// File count: 426
// Total lines: 21
-----------------------------------------
void __fastcall CEphemKeyData::~CEphemKeyData(CEphemKeyData *this)
{
  __int64 v2; // rcx
  void *v3; // rdi

  *(_QWORD *)this = &CEphemKeyData::`vftable';
  v2 = *((_QWORD *)this + 1);
  if ( v2 )
    SslFreeObject(v2, 0i64);
  v3 = (void *)*((_QWORD *)this + 2);
  if ( v3 )
  {
    memset(v3, 0, *((unsigned int *)this + 6));
    SPExternalFree(*((void **)this + 2));
  }
  *(_QWORD *)this = &IAllocate::`vftable';
}
// 18007C270: using guessed type void *CEphemKeyData::`vftable';
// 18007C298: using guessed type void *IAllocate::`vftable';
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
