// File count: 1092
// Total lines: 10
----------------------------------------
CTls13ServerHandshake *__fastcall CTls13ServerHandshake::`scalar deleting destructor'(
        CTls13ServerHandshake *this,
        char a2)
{
  CTls13ServerHandshake::~CTls13ServerHandshake(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
