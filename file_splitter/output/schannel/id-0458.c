//----- (0000000180021510) ----------------------------------------------------
CTlsExtServer *__fastcall CTlsExtServer::`vector deleting destructor'(CTlsExtServer *this, char a2)
{
  *(_QWORD *)this = &CTlsExt::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
// 18007D038: using guessed type void *CTlsExt::`vftable';

