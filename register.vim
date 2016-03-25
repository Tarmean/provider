func! RequireNimHost(name)
  return rpcstart('/home/cyril/Projects/provider/session')
endfunc
call remote#host#Register('nim', '*.nim', function('RequireNimHost'))
