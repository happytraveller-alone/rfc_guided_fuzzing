// File count: 475
// Total lines: 9
------------------------------------------
CTls13Record *__fastcall CTls13Record::`vector deleting destructor'(CTls13Record *this, char a2)
{
  *(_QWORD *)this = &CTlsRecord::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
// 18007D3F0: using guessed type void *CTlsRecord::`vftable';
