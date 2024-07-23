// File count: 318
// Total lines: 55
-----------------------------------------
__int64 __fastcall CSslCredManager::RunBalancer(CSslCredManager *this)
{
  char v2; // bp
  void *v3; // rcx
  bool v4; // si
  DWORD LastError; // eax
  _DWORD *i; // rax
  __int64 *j; // rax

  v2 = 0;
  if ( _InterlockedIncrement((volatile signed __int32 *)this + 22) <= 1 )
  {
    v3 = (void *)*((_QWORD *)this + 10);
    if ( v3 && *((_QWORD *)this + 9) && !WaitForSingleObjectEx(v3, 0, 0) )
    {
      v2 = 1;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids);
      if ( !CertControlStore(*((HCERTSTORE *)this + 9), 0, 1u, (char *)this + 80)
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        LastError = GetLastError();
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          25i64,
          &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids,
          LastError);
      }
    }
    v4 = WaitForSingleObjectEx(CSslGlobals::m_hImplicitCertChangeEvent, 0, 0) == 0;
    if ( !WaitForSingleObjectEx(CSslGlobals::m_hImplicitIssersChangeEvent, 0, 0) )
    {
      RtlEnterCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
      for ( i = (_DWORD *)*((_QWORD *)this + 6); i != (_DWORD *)((char *)this + 48); i = *(_DWORD **)i )
        i[37] |= 0x10u;
      RtlLeaveCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
    }
    if ( v2 || v4 )
    {
      RtlEnterCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
      for ( j = (__int64 *)*((_QWORD *)this + 6); j != (__int64 *)((char *)this + 48); j = (__int64 *)*j )
      {
        if ( v4 && j[99] || v2 && !j[99] )
          *((_DWORD *)j + 37) |= 0x40u;
      }
      RtlLeaveCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
    }
  }
  _InterlockedDecrement((volatile signed __int32 *)this + 22);
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
