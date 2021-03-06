import streams, endians, strutils, sequtils, algorithm, math, hashes
import tables, intsets, lists, queues, sets, strtabs, critbits, macros

const
  pack_value_nil = chr(0xc0)

proc conversionError(msg: string): ref ObjectConversionError =
  new(result)
  result.msg = msg

#this macro convert any distinct types to it's base type
macro undistinct(x:typed): untyped =
  var ty = getType(x)
  var isDistinct = ty.typekind == ntyDistinct
  if isDistinct:
    let parent = ty[1]
    let T = newIdentNode($parent)
    result = quote do: `T`(`x`)
  else:
    result = x
when system.cpuEndian == littleEndian:
  proc take8_8(val: uint8): uint8 {.inline.} = val
  proc take8_16(val: uint16): uint8 {.inline.} = val and 0xFF
  proc take8_32(val: uint32): uint8 {.inline.} = val and 0xFF
  proc take8_64(val: uint64): uint8 {.inline.} = uint8(val and 0xFF)

  proc store16(s: Stream, val: uint16) =
    var res: uint16
    swapEndian16(addr(res), unsafeAddr(val))
    s.write(res)
  proc store32(s: Stream, val: uint32) =
    var res: uint32
    swapEndian32(addr(res), unsafeAddr(val))
    s.write(res)
  proc store64(s: Stream, val: uint64) =
    var res: uint64
    swapEndian64(addr(res), unsafeAddr(val))
    s.write(res)
  proc unstore16(s: Stream): uint16 =
    var tmp: uint16 = cast[uint16](s.readInt16)
    swapEndian16(addr(result), addr(tmp))
  proc unstore32(s: Stream): uint32 =
    var tmp: uint32 = cast[uint32](s.readInt32)
    swapEndian32(addr(result), addr(tmp))
  proc unstore64(s: Stream): uint64 =
    var tmp: uint64 = cast[uint64](s.readInt64)
    swapEndian64(addr(result), addr(tmp))
else:
  proc take8_8(val: uint8): uint8 {.inline.} = val
  proc take8_16(val: uint16): uint8 {.inline.} = (val shr 8) and 0xFF
  proc take8_32(val: uint32): uint8 {.inline.} = (val shr 24) and 0xFF
  proc take8_64(val: uint64): uint8 {.inline.} = uint8((val shr 56) and 0xFF)
  
  proc store16(s: Stream, val: uint16) = s.write(val)
  proc store32(s: Stream, val: uint32) = s.write(val)
  proc store64(s: Stream, val: uint64) = s.write(val)
  proc unstore16(s: Stream): uint16 = cast[uint16](s.readInt16)
  proc unstore32(s: Stream): uint32 = cast[uint32](s.readInt32)
  proc unstore64(s: Stream): uint64 = cast[uint64](s.readInt64)

proc take8_8[T:uint8|char|int8](val: T): uint8 {.inline.} = uint8(val)
proc take16_8[T:uint8|char|int8](val: T): uint16 {.inline.} = uint16(val)
proc take32_8[T:uint8|char|int8](val: T): uint32 {.inline.} = uint32(val)
proc take64_8[T:uint8|char|int8](val: T): uint64 {.inline.} = uint64(val)
