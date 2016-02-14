import session
type Buffer = object
  session: Session

proc len(self: Buffer): int =
  return self.session.request('buffer_get_line', self)
