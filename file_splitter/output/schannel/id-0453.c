//----- (0000000180020B60) ----------------------------------------------------
void __fastcall CTls13Context::~CTls13Context(CTls13Context *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx
  void *v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx
  void (__fastcall ***v7)(_QWORD, _QWORD); // rcx

  *(_QWORD *)this = &CTls13Context::`vftable';
  v2 = *((_QWORD *)this + 9);
  if ( v2 )
    SslFreeObject(v2, 0i64);
  v3 = *((_QWORD *)this + 12);
  if ( v3 )
    SslFreeObject(v3, 0i64);
  v4 = (void *)*((_QWORD *)this + 20);
  if ( v4 )
    SPExternalFree(v4);
  v5 = *((_QWORD *)this + 10);
  if ( v5 )
  {
    SslFreeObject(v5, 0i64);
    *((_QWORD *)this + 10) = 0i64;
  }
  v6 = *((_QWORD *)this + 11);
  if ( v6 )
  {
    SslFreeObject(v6, 0i64);
    *((_QWORD *)this + 11) = 0i64;
  }
  *((_QWORD *)this + 18) = 0i64;
  *((_QWORD *)this + 16) = 0i64;
  memset((char *)this + 112, 0, 8ui64);
  *((_BYTE *)this + 120) = 0;
  memset((char *)this + 168, 0, 0x20ui64);
  v7 = (void (__fastcall ***)(_QWORD, _QWORD))*((_QWORD *)this + 26);
  *((_BYTE *)this + 200) = 0;
  (**v7)(v7, 0i64);
  *((_QWORD *)this + 2) = &CTls13ChangeCipherSpec::`vftable';
}
// 18007CB58: using guessed type void *CTls13ChangeCipherSpec::`vftable';
// 18007CB60: using guessed type void *CTls13Context::`vftable';
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

