type Test = int

proc initTest(x: Test): Test  = x+1
proc initTest2(x: var Test) = x += 1
proc initTest3(x: ptr Test) = x[] += 1
template initTest4(v: typed): typed = v.x[0] = 1
import benchmark

# suite "increment", 0.0:
#   var
#     ts: TestStats
#     loops = 0
  
#   test "inc", 0.5, ts:
#     inc(loops)
  
#   test "atomicInc", 0.5, ts:
#     atomicInc(loops)

suite "creation", 0.0:
    var ts: TestStats
    var t: Test
    test "norm", 0.5, ts:
        t += 1
    test "inc", 0.5, ts:
        inc t
    test "default", 0.5, ts:
        t = t.Test()
    test "long", 0.5, ts:
        t = t + 1
    test "var", 0.5, ts:
        initTest2(t)
    test "ptr", 0.5, ts:
        initTest3(addr(t))
