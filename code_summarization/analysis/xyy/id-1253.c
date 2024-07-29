//----- (00000001800638E0) ----------------------------------------------------
CTls13ExtClient *__fastcall CTls13ExtClient::`scalar deleting destructor'(CTls13ExtClient *this, char a2)
{
  *(_QWORD *)this = &CTls13ExtClient::`vftable';
  CTlsExtClient::~CTlsExtClient(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
// 18007D5C8: using guessed type void *CTls13ExtClient::`vftable';

