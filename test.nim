import msgpack, os, streams, tables, macros

proc fwrite(formatstr: cstring, size: int, length: int, file: File) {.importc: "fwrite", varargs, header: "<stdio.h>".}
proc fecho(s: string) = fwrite(s, sizeof(char), s.len, stdout)


proc skipString(s: Stream) =
  let i = s.unpackString()
  s.setPosition(s.getPosition + i)

proc unpackTypePartial[T](s: Stream, val: var T) =
  macro createCase(stream: typed, selector: typed, obj: typed): stmt =
    result = newNimNode(nnkStmtList)
    var caseStatement = newNimNode(nnkCaseStmt).add selector
    for field in getType(obj)[1].children:
      let fieldname = $field
      caseStatement.add newNimNode(nnkOfBranch).add(
         newStrLitNode(fieldname),
         newStmtList(
           newNimNode(nnkCommand).add(
             newDotExpr(stream, ident"unpack_type"),
             newDotExpr(obj, field)
           ),
         )
      )
    result.add caseStatement

  var
    length =  s.unpackMap()
    selector: string
  for i in 0..<length:
    s.unpackType selector
    createCase(s, selector, val)

type
    Function = object
        name: string
        async: bool
        can_fail: bool
        receives_channel_id: bool
        parameters: seq[seq[string]]
        return_type: string
    IdTable = Table[string, int]
    ApiInfo = object
      functions: seq[Function]
      types: IdTable
      error_types: IdTable
proc initIdTable(): IdTable = initTable[string, int]()
proc unpackIdTable(s: Stream): IdTable =
  result = initIdTable()
  var 
    length = s.unpackMap()
    selector: string
    current: int
  for i in 0..<length:
    s.unpackType selector

    discard s.unpackMap
    s.skipString

    s.unpackType current
    result[selector] = current

proc parseApi(s: Stream): ApiInfo =
  var 
    length = s.unpackMap()
    functions = newSeq[Function]()
    errors, types: IdTable
  for i in 0..<length:
    var selector: string
    s.unpackType selector
    case selector
    of "functions":
      let lenArray = s.unpackArray()
      for j in 0..<lenArray:
        var current = Function()
        s.unpackTypePartial(current)
        functions.add current
    of "error_types":
      errors = s.unpackIdTable()
    of "types":
      types = s.unpackIdTable()
    else:
      raise
  return ApiInfo(errorTypes: errors, types: types, functions: functions)

type Request = object
  callback: int
  id: int
  meth: string
  params: seq[(string, string)]
import os

import asyncnet, asyncdispatch, asyncfile
var f = openAsync(stdin)
# proc testConnect() {.async.}=
#   var 
#     sock = newAsyncSocket()
#     # target =  string(getEnv("NVIM_LISTEN_ADDRESS"))
#   await sock.connect("127.0.0.1", Port(7777))
#   echo "bla"
#   var 
#     message = Request(callback: 0, id: 1, meth: "vim_get_api_info", params: @[])
#     packed = message.pack
#     answer = ""
#   fecho (packed & "\n")
#   await sock.send packed
#   while true:
#         var 
#           received = await sock.recv(4096)
#         echo "received"
#         answer.add received
#         fecho received & "\n"
#         echo received.len
#         if received.len < 4096:
#           break
#   echo answer.len
#   echo stringify answer
#   sock.close()
# echo "before"
# asyncCheck testConnect()
# runForever()
echo "after"
when false:
  var 
    s = newFileStream "nvim.log"
    res = s.parseApi()
  echo res.types
  echo res.errorTypes
  for fun in res.functions:
    echo fun.name

#   read = s.readAll()

# echo stringify read

# var s = newStringStream()
# var f = Function(name: "foo", async: true, parameters: @[@["foo", "string"], @["bar", "int"]])

# s.pack f
# var g = Function()
# s.setPosition(0)
# unpackTypePartial(s, g)


# echo f
# echo g
