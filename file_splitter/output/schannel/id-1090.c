//----- (000000018005AB10) ----------------------------------------------------
CTls13ClientHandshake *__fastcall CTls13ClientHandshake::`vector deleting destructor'(
        CTls13ClientHandshake *this,
        char a2)
{
  *(_QWORD *)this = &CTls13ClientHandshake::`vftable';
  CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::~CTls13Handshake<CTls13ClientContext,CTls13ExtClient>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
// 18007D550: using guessed type void *CTls13ClientHandshake::`vftable';

