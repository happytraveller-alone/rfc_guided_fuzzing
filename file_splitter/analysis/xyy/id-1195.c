//----- (000000018005E7C0) ----------------------------------------------------
void __fastcall CSslServerKey::~CSslServerKey(CSslServerKey *this)
{
  CCipherMill *v2; // rcx

  *(_QWORD *)this = &CSslServerKey::`vftable';
  v2 = (CCipherMill *)*((_QWORD *)this + 1);
  if ( v2 )
  {
    SslFreeObject(v2, 0i64);
    *((_QWORD *)this + 1) = 0i64;
  }
  if ( *((_QWORD *)this + 2) )
  {
    CCipherMill::DeferenceProvider(v2, (unsigned __int64 *)this + 2);
    *((_QWORD *)this + 2) = 0i64;
  }
  *(_QWORD *)this = &IAllocate::`vftable';
}
// 18005E800: variable 'v2' is possibly undefined
// 18007C298: using guessed type void *IAllocate::`vftable';
// 18007D568: using guessed type void *CSslServerKey::`vftable';
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

