#fix
proc write(c: char) = discard
proc store8(val: uint8) = discard
proc write8(val: uint8, fix: bool, bytes: int, prefix: byte) =
    if val < uint8(1 shl bytes):
        if not fix:
            write(chr(prefix))
        store8(val)


import math, macros

type
  Entry = object
      range: Slice[int]
      fix: bool
# proc newProc*(name = newEmptyNode(); params: openArray[NimNode] = [newEmptyNode()];
#     body: NimNode = newStmtList(), procType = nnkProcDef): NimNode {.compileTime.} =
macro genInt(): untyped =
  result = newStmtList()
  for bytes in 1..4:
    discard
    # var function = newProc

for i in countdown(4,2):
    echo -(pow(2, (pow(2, 1+i.float)-1)))
echo int32.high - (2^31 - 1)
