// File count: 452
// Total lines: 54
-----------------------------------------
void __fastcall CSsl3TlsServerContext::CleanupConnectedState(CSsl3TlsServerContext *this)
{
  volatile signed __int32 *v2; // rcx
  void *v3; // rcx
  __int64 v4; // rdx
  _QWORD *v5; // rbx

  if ( *((_QWORD *)this + 120) )
  {
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 248i64))(this);
    v2 = (volatile signed __int32 *)*((_QWORD *)this + 120);
    if ( v2 && _InterlockedExchangeAdd(v2 + 7, 0xFFFFFFFF) == 1 )
      (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v2 + 8i64))(v2, 1i64);
    *((_QWORD *)this + 120) = 0i64;
  }
  if ( *((_QWORD *)this + 121) )
  {
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 121) = 0i64;
  }
  v3 = (void *)*((_QWORD *)this + 112);
  if ( v3 )
  {
    SPExternalFree(v3);
    *((_QWORD *)this + 112) = 0i64;
    *((_DWORD *)this + 222) = 0;
  }
  if ( *((_QWORD *)this + 110) )
  {
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 110) = 0i64;
  }
  v4 = *((_QWORD *)this + 114);
  *((_DWORD *)this + 218) = 0;
  if ( v4 )
  {
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 114) = 0i64;
    *((_WORD *)this + 460) = 0;
  }
  *(_WORD *)((char *)this + 923) = 0;
  *((_BYTE *)this + 472) = 0;
  v5 = (_QWORD *)*((_QWORD *)this + 58);
  if ( v5 && *v5 )
  {
    if ( v5[3] )
    {
      (*(void (__fastcall **)(_QWORD))(*(_QWORD *)*v5 + 16i64))(*v5);
      v5[3] = 0i64;
      *((_DWORD *)v5 + 4) = 0;
    }
  }
}
