// File count: 1244
// Total lines: 9
-----------------------------------------
CTlsRecord *__fastcall CTlsRecord::`scalar deleting destructor'(CTlsRecord *this, char a2)
{
  *(_QWORD *)this = &CTlsRecord::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
// 18007D3F0: using guessed type void *CTlsRecord::`vftable';
