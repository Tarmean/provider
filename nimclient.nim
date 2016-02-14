import os

type Session = object
  discard
proc initTcpSession(address: string, port: int): Session = nil
proc initSocketSession(path: string): Session = nil
proc initStdioSession(): Session = nil
proc initChildSession(argv: string): Session = nil

proc startHost(session: Session) =
  var plugins: seq[string] = @[]
  for idx in 1..<paramCount():
    let 
      arg = paramStr(idx)
      (_, _, ext) = splitFile(arg)
    if ext == ".nim":
      plugins.add arg
  if plugins.len == 0:
    quit "must specify at least one plugin as argument"
  # TODO: add loging

  # host = session.fromSession.initHost()
  # host.start(plugins)
proc startHost() = startHost(initStdioSession())

type SessionType = enum
  kTcp, kSocket, kChild, kStdio
proc attach(sessionType: SessionType, address: string = nil, port: int = 0, path: string = nil, argv: string = nil): Session =
  result = case sessionType
           of kTcp: initTcpSession(address, port)
           of kSocket: initSocketSession(path)
           of kStdio: initStdioSession()
           of kChild: initChildSession(argv)
