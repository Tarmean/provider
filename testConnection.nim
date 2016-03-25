import net, msgpack, osproc
var s = newSocket()
s.connect("127.0.0.1", Port(7777))
s.pack((0, 0, "vim_get_api_info"))
# echo repr s.toAny
# echo stringify execProcess("nvim --api-info")
# s.send(msg)
# let b = toAny(s)
# var
  # a: int = s.recv()
# echo stringify
#
