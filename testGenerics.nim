import streams
proc unpack(s: Stream, it: int64) =
  discard s.readInt64
proc unpack(s: Stream, it: var bool) =
  it = s.readBool
import streams
proc unpack[T](s: Stream): T =
  s.unpack result
var 
  s = newStringStream()
  i = s.unpack[int64]()

s.write 10
s.write false


