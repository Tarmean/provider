import threadpool
proc test() =
  echo "bla"
spawn test()
sync()
