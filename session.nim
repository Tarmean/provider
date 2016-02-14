type Session* = object
  isRunning: bool
  asyncSession: bool


proc initSession(asyncSession: bool): Session =
  result = Session(asyncSession: asyncSession)

