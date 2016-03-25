import Tables, msgpack
import macros, threadpool, msgpack, streams, logger, os
addLogger "nivmlog.log".open(fmWrite)
log "started"

type
  StreamInterface* = object
    s: Stream
  Vim* = ref object
    i: StreamInterface
  CallType  = enum
    ctRequest      = 0,
    ctResponse     = 1,
    ctNotification = 2,

  MessageKind = enum
    kWrite, kStop
  Message = object
    case kind: MessageKind
    of kWrite: s: string
    of kStop: discard

  RpcTable = Table[string, proc(s: Vim)]
var outChannel = Channel[Message]()

proc initRpcTable: RpcTable = initTable[string, proc(s: Vim)]()
var rpcTable = initRpcTable()

proc fread(handle: File, buffer: ptr, nbyte: int) {.importc: "read", header:  "fcntl.h"}
proc fwrite(formatstr: cstring, size: int, length: int, file: File) {.importc: "fwrite", varargs, header: "<stdio.h>".}
proc fecho(s: string) =
  let s = s & "\n"
  fwrite(s, sizeof(char), s.len, stdout)
proc unpack[T](s: Vim, it: var T) = s.i.s.unPack it

proc write(s: string) {.gcsafe.}=
  outChannel.send Message(kind: kWrite, s: s)

proc write(vim: Vim, s: string) =
  fecho s
proc writerThread(vim: Vim) =
  while true:
    let msg = outChannel.recv()
    case msg.kind
    of kWrite:
      vim.write msg.s
    of kStop:
      break

proc readerThread(vim: Vim, rpcTable: RpcTable) {.gcsafe.}=
    try:
      while true:
        assert vim.i.s.unpackArray == 4
        var
          callType: int
          msgid: int
          methodName: string
        vim.unpack callType
        log "in", callType
        case CallType(callType)
        of ctRequest:
          vim.unpack msgid
          vim.unpack methodName
          rpcTable[methodName](vim)
        of ctResponse:
          discard
        of ctNotification:
          vim.unpack methodName
          rpcTable[methodName](vim)
    except:
      log getCurrentExceptionMsg()

proc stop() =
  outChannel.send Message(kind: kStop)
  sync()
  close outChannel

proc init(vim: Vim) =
  outChannel.open()
  spawn writerThread(vim)
  spawn readerThread(vim, rpcTable)



# proc pack[T](s: var Stream, it:  T) = s.

macro VimExport(p: untyped): untyped =
  result = newStmtList().add p
  var
    params = p.params
  var
    parLen = genSym(nskVar, "parLen")
    varSection = newNimNode(nnkVarSection).add(
      newNimNode(nnkIdentDefs).add(parLen, ident"int", newEmptyNode())
    )
    parseSection = newStmtList()
    call = newNimNode(nnkCall).add(p.name)
  parseSection.add quote do:
    discard s.i.s.unpackArray() # XXX: Check that parameters have the right length
    # assert x == `p.params`
  for i in 1..<params.len:
    let
      curPar = params[i]
      curVar = newNimNode(nnkIdentDefs)
    for j in 0..<curPar.len-2:
      var sym = genSym(nskVar, $curPar[j])
      curVar.add sym
      parseSection.add(
        newCall(ident"unpack", @[ident"s", sym]),
      )

      call.add sym

    curVar.add curPar[^2] # type
    curVar.add curPar[^1] # default

    varSection.add curVar

  var
    proxy: NimNode
  if params[0].kind != nnkEmpty:
    var
      proxyBody =
        quote do:
          var
            res = `call`
            packStream = newStringStream()
          packStream.pack res
          write packStream.data
      proxyDef= newProc(genSym(nskProc, "proxy"), [newEmptyNode()], proxyBody)
      proxyCall = newCall(ident"spawn", newCall(proxyDef.name))
    proxy = newStmtList().add(proxyDef, proxyCall)
  else:
    proxy = newCall(ident"spawn", call)

  var
    lambdaParam = newNimNode(nnkFormalParams).add(
      newEmptyNode(),
      newIdentDefs(ident"s", ident"Vim")
    )
    body = newStmtList().add(
      varSection, parseSection, proxy
    )

    lam = newNimNode(nnkLambda).add(
      newEmptyNode(), #name
      newEmptyNode(),
      newEmptyNode(),
      lambdaParam, ##params
      newEmptyNode(),  ## pragmas
      newEmptyNode(),
      body
    )

    assignment = newAssignment(
      newNimNode(nnkBracketExpr).add(ident"rpcTable", newStrLitNode($p.name)),
      lam
    )

  result.add assignment


proc abc(a, b, c: int = 2): string {.VimExport.} =
    return $a & $(b + c)
var
  # d = (0, 1, "abc", @[5, 2, 3])
  # d = @[5, 2, 3]
  inStream = newFileStream(stdin)
  outStream = newFileStream(stdout)
# g.pack d
# g.setPosition 0
for i in 1..paramCount():
  log paramStr(i)
var i = Vim(i:StreamInterface(s:inStream))
i.init()
sync()
# rpcTable["abc"] i

