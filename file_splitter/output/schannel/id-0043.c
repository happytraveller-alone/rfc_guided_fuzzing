// File count: 43
// Total lines: 24
------------------------------------------
void __fastcall CSslCredManager::DereferenceCredentialGroup(CSslCredManager *this, struct CCredentialGroup *a2)
{
  struct _RTL_CRITICAL_SECTION *v3; // rdi
  struct CCredentialGroup **v4; // r8
  struct CCredentialGroup **v5; // rdx

  if ( _InterlockedExchangeAdd((volatile signed __int32 *)a2 + 6, 0xFFFFFFFF) == 1 )
  {
    v3 = (struct _RTL_CRITICAL_SECTION *)((char *)this + 8);
    RtlEnterCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
    v4 = (struct CCredentialGroup **)*((_QWORD *)a2 + 1);
    if ( v4[1] != (struct CCredentialGroup *)((char *)a2 + 8)
      || (v5 = (struct CCredentialGroup **)*((_QWORD *)a2 + 2), *v5 != (struct CCredentialGroup *)((char *)a2 + 8)) )
    {
      __fastfail(3u);
    }
    *v5 = (struct CCredentialGroup *)v4;
    v4[1] = (struct CCredentialGroup *)v5;
    RtlLeaveCriticalSection(v3);
    if ( a2 )
      (*(void (__fastcall **)(struct CCredentialGroup *, __int64))(*(_QWORD *)a2 + 8i64))(a2, 1i64);
  }
}
