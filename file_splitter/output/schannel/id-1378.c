// File count: 1378
// Total lines: 39
----------------------------------------
__int64 __fastcall CTls13ClientContext::InitHandshakeHash(CTls13ClientContext *this, char a2)
{
  __int64 result; // rax
  __int64 v4; // r9
  unsigned int v5; // edi
  __int64 v6; // rdx
  __int64 v7; // r8

  result = CSsl3TlsContext::InitHandshakeHash(this, a2);
  v5 = result;
  if ( !(_DWORD)result )
  {
    v6 = *((_QWORD *)this + 110);
    if ( v6 )
    {
      v7 = *((unsigned int *)this + 218);
      if ( (_DWORD)v7 )
      {
        LOBYTE(v4) = 1;
        v5 = (*(__int64 (__fastcall **)(CTls13ClientContext *, __int64, __int64, __int64))(*(_QWORD *)this + 504i64))(
               this,
               v6,
               v7,
               v4);
        if ( *((_QWORD *)this + 110) )
        {
          (*(void (__fastcall **)(CTls13ClientContext *))(*(_QWORD *)this + 16i64))(this);
          *((_QWORD *)this + 110) = 0i64;
        }
        *((_DWORD *)this + 218) = 0;
      }
    }
    return v5;
  }
  return result;
}
// 18006D75A: variable 'v4' is possibly undefined
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
