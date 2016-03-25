import macros, os, strutils

type
  Sized {.pure.} = enum
    fixed, size
  MsgSize = object
    fixType: Sized
    constant: byte
    area: Slice[int]
    size: int
proc initSize(size: int, constant: byte): MsgSize = MsgSize(fixType: Sized.size, constant: constant, size: size)
proc initFix(size: int, area: Slice[int]): MsgSize = MsgSize(fixType: Sized.fixed, area: area, size: size)
proc createFormat(baseConst: byte, sizeLow = 1, steps = 4, stepSize = 1): seq[MsgSize] =
  result = newSeq[MsgSize]()
  for i in 0..<steps:
    result.add initSize(sizeLow + i * stepSize, baseConst + i.byte)
const
    posFixInt = initFix(7, 0x00..0x7f)
    negFixInt = initFix(5, 0xe0..0xff)
    fixInts = @[posFixInt, negFixInt]
    uintFormats = fixInts & createFormat(0xcc)
    intFormats = fixInts & createFormat(0xd0)

    floatFormats = createFormat(0xca, 2, 2, 2)

    fixMap = initFix(4, 0x80..0x8f)
    fixArray = initFix(4, 0x90..0x9f)
    fixStr = initFix(5, 0xa0..0xbf)


    binFormats = createFormat(0xc4, steps = 3)
    extFormats = createFormat(0xc7, steps = 3)



macro readFormat(formats: seq[MsgSize]): untyped =
  result = newStmtList()

  # var ifBlock = newNimNode(nnkIfStmt)
  # let formats = callsite()[1]
  for format in formats:
    echo repr format
    # let format = formats[i]
    # if format.fixType == Sized.fixed:
    #   discard
    # # case format.kind
    # # of Sized.fixed:
    # #   discard
    # #     # result.add 
    # # of Sized.size:
    # #     discard
    # result.add(newNimNode(nnkElifBranch).add(i.cond, i.body))


# for format in uintFormats:
#   echo format

readFormat(uintFormats)

