//----- (0000000180062998) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::InitUpdateClientHash(CSsl3TlsServerContext *this)
{
  __int64 result; // rax
  unsigned int v3; // edi

  result = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 496i64))(this);
  if ( !(_DWORD)result )
  {
    *((_BYTE *)this + 340) = 0;
    v3 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, _QWORD, _QWORD, _QWORD))(*(_QWORD *)this + 504i64))(
           this,
           *((_QWORD *)this + 110),
           *((unsigned int *)this + 218),
           0i64);
    if ( *((_QWORD *)this + 110) )
    {
      (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
      *((_QWORD *)this + 110) = 0i64;
    }
    *((_DWORD *)this + 218) = 0;
    if ( v3 )
      CSslContext::SetErrorAndFatalAlert((__int64)this, 1007, v3, 0x50u);
    return v3;
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

