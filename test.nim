# import msgpack, tables, sequtils
# proc wraper*[K, V](x: seq[tuple[key: K, val: V]]): Msg =
#   x.map(proc (e: tuple[key: K, val: V]): auto = (wrap(e.key), wrap(e.val))).convM
# proc test() =
#   var 
#     t = @[("a","b"), ("bk","c")]
#     k = % t
#   echo repr t
#   echo repr k
#   # let x =  wraper t
# test()
# proc foo*(x: varargs[stmt, `$`]) =
#   discard
# import macros
# proc bar(x: varargs[stmt]) =
#   discard

# var 
#   a = newSeq[byte](8)
# let
#   b = cast[ptr int64](addr a[2])
#   c: int64 = 257
#   d: int64 = 666666666
# echo a
# b[] = c
# echo a
# b[] = d
# echo a

# {.push checks: off.}
# proc foo*(x: varargs[expr, `$`]) =
#   discard

# type Encoded = object
#   val: int
# proc encode(i: int): Encoded = Encoded(val: i)
type Encodable* = concept x
  encode(x) is Encoded
proc test(x: varargs[Encodable]) =
  for item in x:
    discard encode(item)
# var i = 5
# test(i)
