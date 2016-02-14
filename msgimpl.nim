type
  b16 = uint16
  b32 = uint32
  b64 = uint64

  Ext* = tuple[typ:int, data: seq[byte]]

  MsgKind* = enum
    kArray16
    kArray32
    kBin16
    kBin32
    kBin8
    kExt16
    kExt32
    kExt8
    kFalse
    kFixArray
    kFixExt1
    kFixExt16
    kFixExt2
    kFixExt4
    kFixExt8
    kFixMap
    kFixStr
    kFloat32
    kFloat64
    kInt16
    kInt32
    kInt64
    kInt8
    kMap16
    kMap32
    kNFixNum
    kNil
    kPFixNum
    kStr16
    kStr32
    kStr8
    kTrue
    kUInt16
    kUInt32
    kUInt64
    kUInt8
  Msg* = ref MsgObj
  MsgObj* {.acyclic.} = object
    case kind*: MsgKind
    of kArray16: vArray16*: seq[Msg]
    of kArray32: vArray32*: seq[Msg]
    of kBin16: vBin16*: seq[byte]
    of kBin32: vBin32*: seq[byte]
    of kBin8: vBin8*: seq[byte]
    of kExt16: vExt16: Ext
    of kExt32: vExt32: Ext
    of kExt8: vExt8: Ext
    of kFalse: nil
    of kFixArray: vFixArray*: seq[Msg]
    of kFixExt16: vFixExt16: Ext
    of kFixExt1: vFixExt1: Ext
    of kFixExt2: vFixExt2: Ext
    of kFixExt4: vFixExt4: Ext
    of kFixExt8: vFixExt8: Ext
    of kFixMap: vFixMap*: seq[tuple[key:Msg, val:Msg]]
    of kFixStr: vFixStr*: string
    of kFloat32: vFloat32*: float32
    of kFloat64: vFloat64*: float64
    of kInt16: vInt16*: int16
    of kInt32: vInt32*: int32
    of kInt64: vInt64*: int64
    of kInt8: vInt8*: int8
    of kMap16: vMap16*: seq[tuple[key:Msg, val:Msg]]
    of kMap32: vMap32*: seq[tuple[key:Msg, val:Msg]]
    of kNFixNum: vNFixNum*: int8
    of kNil: nil
    of kPFixNum: vPFixNum*: uint8
    of kStr16: vStr16*: string
    of kStr32: vStr32*: string
    of kStr8: vStr8*: string
    of kTrue: nil
    of kUInt16: vUInt16*: uint16
    of kUInt32: vUInt32*: uint32
    of kUInt64: vUInt64*: uint64
    of kUInt8: vUInt8*: uint8

{.push inline.}

proc FixArray*(v: seq[Msg]): Msg =
  assert(len(v) < 16)
  Msg(kind: kFixArray, vFixArray: v)

proc Array16*(v: seq[Msg]): Msg =
  assert(len(v) < (1 shl 16))
  Msg(kind: kArray16, vArray16: v)

proc Array32*(v: seq[Msg]): Msg =
  assert(len(v) < (1 shl 32))
  Msg(kind: kArray32, vArray32: v)

proc FixMap*(v: seq[tuple[key: Msg, val: Msg]]): Msg =
  assert(len(v) < 16)
  Msg(kind: kFixMap, vFixMap: v)

proc Map16*(v: seq[tuple[key: Msg, val: Msg]]): Msg =
  assert(len(v) < (1 shl 16))
  Msg(kind: kMap16, vMap16: v)

proc Map32*(v: seq[tuple[key: Msg, val: Msg]]): Msg =
  assert(len(v) < (1 shl 32))
  Msg(kind: kMap32, vMap32: v)

let
  Nil* = Msg(kind: kNil)
  True* = Msg(kind: kTrue)
  False* = Msg(kind: kFalse)

# Compile type check that v is 7 bit?
proc PFixNum*(v: uint8): Msg =
  assert(v < 128)
  Msg(kind: kPFixNum, vPFixNum: v)

proc NFixNum*(v: int8): Msg =
  assert(-32 <= v and v < 0)
  Msg(kind: kNFixNum, vNFixNum: v)

proc UInt8*(v: uint8): Msg =
  Msg(kind: kUInt8, vUInt8: v)

proc UInt16*(v: uint16): Msg =
  Msg(kind: kUInt16, vUInt16: v)

proc UInt32*(v: uint32): Msg =
  Msg(kind: kUInt32, vUInt32: v)

proc UInt64*(v: uint64): Msg =
  Msg(kind: kUInt64, vUInt64: v)

proc Int8*(v: int8): Msg =
  Msg(kind: kInt8, vInt8: v)

proc Int16*(v: int16): Msg =
  Msg(kind: kInt16, vInt16: v)

proc Int32*(v: int32): Msg =
  Msg(kind: kInt32, vInt32: v)

proc Int64*(v: int64): Msg =
  Msg(kind: kInt64, vInt64: v)

proc Float32*(v: float32): Msg =
  Msg(kind: kFloat32, vFloat32: v)

proc Float64*(v: float64): Msg =
  Msg(kind: kFloat64, vFloat64: v)

proc FixStr*(v: string): Msg =
  assert(len(v) < 32)
  Msg(kind: kFixStr, vFixStr: v)

proc Str8*(s: string): Msg =
  Msg(kind: kStr8, vStr8: s)

proc Str16*(s: string): Msg =
  Msg(kind: kStr16, vStr16: s)

proc Str32*(s: string): Msg =
  Msg(kind: kStr32, vStr32: s)

proc Bin8*(v: seq[byte]): Msg =
  assert(len(v) < (1 shl 8))
  Msg(kind: kBin8, vBin8: v)

proc Bin16*(v: seq[byte]): Msg =
  assert(len(v) < (1 shl 16))
  Msg(kind: kBin16, vBin16: v)

proc Bin32*(v: seq[byte]): Msg =
  assert(len(v) < (1 shl 32))
  Msg(kind: kBin32, vBin32: v)

proc FixExt1*(v: Ext): Msg =
  assert(len(v.data) == 1)
  Msg(kind: kFixExt1, vFixExt1: v)

proc FixExt2*(v: Ext): Msg =
  assert(len(v.data) == 2)
  Msg(kind: kFixExt2, vFixExt2: v)

proc FixExt4*(v: Ext): Msg =
  assert(len(v.data) == 4)
  Msg(kind: kFixExt4, vFixExt4: v)

proc FixExt8*(v: Ext): Msg =
  assert(len(v.data) == 8)
  Msg(kind: kFixExt8, vFixExt8: v)

proc FixExt16*(v: Ext): Msg =
  assert(len(v.data) == 16)
  Msg(kind: kFixExt16, vFixExt16: v)

proc Ext8*(v: Ext): Msg =
  assert(len(v.data) < (1 shl 8))
  Msg(kind: kExt8, vExt8: v)

proc Ext16*(v: Ext): Msg =
  assert(len(v.data) < (1 shl 16))
  Msg(kind: kExt16, vExt16: v)

proc Ext32*(v: Ext): Msg =
  assert(len(v.data) < (1 shl 32))
  Msg(kind: kExt32, vExt32: v)

{.pop.}


type Wrappable* = concept x
  wrap(x) is Msg

proc wrap*(x: int): Msg =
  if 0 <= x:
    if x < 0b10000000:
      PFixNum(cast[uint8](x.toU8))
    elif x < 0x100:
      UInt8(cast[uint8](x.toU8))
    elif x < 0x10000:
      UInt16(cast[uint16](x.toU16))
    elif x < 0x100000000:
      UInt32(cast[uint32](x.toU32))
    else:
      UInt64(x.uint64)
  else:
    if x >= -32:
      NFixNum(cast[int8](x.toU8))
    elif x >= -128:
      Int8(cast[int8](x.toU8))
    elif x >= -(1 shl 15):
      Int16(cast[int16](x.toU16))
    elif x >= -(1 shl 31):
      Int32(cast[int32](x.toU32))
    else:
      Int64(x.int64)

proc wrap(x: string): Msg =
  let sz = len(x)
  if sz < 32:
    FixStr(x)
  elif sz < 0x100:
    Str8(x)
  elif sz < 0x10000:
    Str16(x)
  elif sz < 0x100000000:
    Str32(x)
  else:
    assert(false)
    nil

proc wrap(x: seq[byte]): Msg =
  let sz = len(x)
  if sz < 0x100:
    Bin8(x)
  elif sz < 0x10000:
    Bin16(x)
  elif sz < 0x100000000:
    Bin32(x)
  else:
    assert(false)
    nil

proc wrap(x: seq[Msg]): Msg =
  let sz = len(x)
  if sz < 16:
    FixArray(x)
  elif sz < 0x10000:
    Array16(x)
  elif sz < 0x100000000:
    Array32(x)
  else:
    assert(false)
    nil

proc wrap(x: Ext): Msg =
  let sz = len(x.data)
  if sz == 1:
    FixExt1(x)
  elif sz == 2:
    FixExt2(x)
  elif sz == 4:
    FixExt4(x)
  elif sz == 8:
    FixExt8(x)
  elif sz == 16:
    FixExt16(x)
  elif sz < 0x100:
    Ext8(x)
  elif sz < 0x10000:
    Ext16(x)
  else: # FIXME
    Ext32(x)

proc wrap*[T:Wrappable](x: seq[T]): Msg =
  var sequence = newSeq[T](x.len)
  for item in x:
    sequence.add wrap item
  let sz = len(x)
  result = if sz < 16:
            FixArray(sequence)
          elif sz < 0x10000:
            Array16(sequence)
          elif sz < 0x100000000:
            Array32(sequence)
          else:
            assert(false)

proc wrap*[K: Wrappable, V: Wrappable](x: openarray[tuple[key: K, val: V]]): Msg =
  var sequence = newSeq[Msg](x.len)
  for item in x:
    let key, value = item
    sequence.add((wrap key, wrap value))
  let sz = len(x)
  result = if sz < 16:
             FixMap(sequence)
           elif sz < 0x10000:
             Map16(sequence)
           elif sz < 0x100000000:
             Map32(sequence)
           else:
             assert(false)

proc wrap*(x: bool): Msg =
  assert false
proc wrap*(x: float): Msg =
  assert false

proc `%`*(x: Wrappable): Msg = wrap(x)

converter toMsg*(x: Msg): Msg =
  x

converter toMsg*(x: bool): Msg =
  wrap(x)

converter toMsg*(x: int): Msg =
  wrap(x)

converter toMsg*(x: float): Msg =
  wrap(x)

converter toMsg*(x: string): Msg =
  wrap(x)

converter toMsg*(x: seq[byte]): Msg =
  wrap(x)

converter toMsg*(x: Ext): Msg =
  wrap(x)

converter toMsg*[T:Wrappable](x: seq[T]): Msg =
  wrap(x)

converter toMsg*[K: Wrappable, V: Wrappable](x: seq[tuple[key: K, val: V]]): Msg =
  wrap(x)

# proc convM(x: Ext): Msg =
#   let sz = len(x.data)
#   if sz == 1:
#     FixExt1(x)
#   elif sz == 2:
#     FixExt2(x)
#   elif sz == 4:
#     FixExt4(x)
#   elif sz == 8:
#     FixExt8(x)
#   elif sz == 16:
#     FixExt16(x)
#   elif sz < 0x100:
#     Ext8(x)
#   elif sz < 0x10000:
#     Ext16(x)
#   else: # FIXME
#     Ext32(x)

















proc unwrapBool*(x: Msg): bool =
  case x.kind:
  of kTrue:
    true
  of kFalse:
    false
  else:
    assert(false)
    false

proc unwrapInt*(x: Msg): int =
  case x.kind:
  of kPFixNum:
    x.vPFixNum.int
  of kNFixNum:
    x.vNFixNum.int
  of kUInt8:
    x.vUInt8.int
  of kUInt16:
    x.vUInt16.int
  of kUInt32:
    x.vUInt32.int
  of kUInt64:
    x.vUInt64.int # FIXME
  of kInt8:
    x.vInt8.int
  of kInt16:
    x.vInt16.int
  of kInt32:
    x.vInt32.int
  else:
    x.vInt64.int

proc unwrapFloat*(x: Msg): float =
  case x.kind:
  of kFloat32:
    x.vFloat32.float
  else:
    x.vFloat64.float

proc unwrapStr*(x: Msg): string =
  case x.kind:
  of kFixStr:
    x.vFixStr
  of kStr8:
    x.vStr8
  of kStr16:
    x.vStr16
  of kStr32:
    x.vStr32
  else:
    assert(false)
    nil

proc unwrapBin*(x: Msg): seq[byte] =
  case x.kind:
  of kBin8:
    x.vBin8
  of kBin16:
    x.vBin16
  of kBin32:
    x.vBin32
  else:
    assert(false)
    nil

proc unwrapArray*(x: Msg): seq[Msg] =
  case x.kind:
  of kFixArray:
    x.vFixArray
  of kArray16:
    x.vArray16
  of kArray32:
    x.vArray32
  else:
    assert(false)
    nil
 
proc unwrapMap*(x: Msg): seq[tuple[key:Msg, val:Msg]] =
  case x.kind:
  of kFixMap:
    x.vFixMap
  of kMap16:
    x.vMap16
  of kMap32:
    x.vMap32
  else:
    assert(false)
    nil

proc unwrapExt*(x: Msg): Ext =
  case x.kind:
  of kFixExt1:
    x.vFixExt1
  of kFixExt2:
    x.vFixExt2
  of kFixExt4:
    x.vFixExt4
  of kFixExt8:
    x.vFixExt8
  of kFixExt16:
    x.vFixExt16
  of kExt8:
    x.vExt8
  of kExt16:
    x.vExt16
  else:
    x.vExt32 # FIXME

  # uint8 | uint16 | uint32 | uint64 | int8 | int16 | int32 | int64 | float32 | float64 |
  # bool| Msg
 # | openarray[byte] 
# type Native = int | bool
# proc foo*(x: varargs[stmt, `$`]) =
#   discard
# proc bar*(x: varargs[untyped, `$`]) =
#   discard
  # echo x
  # for item in inputs:
  #   echo repr item
var 
  i = 5
  # j = encode(i)
# proc translate()
##
type Encodable* = concept x
  encode(x) is Msg
proc test(x: varargs[Encodable]) =
  for i in x:
    echo encode(x)
