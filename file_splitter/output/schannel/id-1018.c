// File count: 1018
// Total lines: 56
----------------------------------------
__int64 CSslGlobals::InitializeCryptLocatorHandles(void)
{
  DWORD v0; // ebx
  void *v1; // rdi
  DWORD v2; // eax
  void *v3; // rsi
  DWORD LastError; // eax

  v0 = 0;
  RtlAcquireResourceExclusive(&SslGlobalLock, 1u);
  if ( !CSslGlobals::m_hCertLocator )
  {
    v1 = CryptObjectLocatorInitialize(
           "SslObjectLocatorInitializePfx",
           1u,
           0,
           0i64,
           CSslGlobals::m_hImplicitCertChangeEvent);
    if ( v1 )
    {
      v3 = CryptObjectLocatorInitialize(
             "SslObjectLocatorInitializeIssuerList",
             2u,
             0,
             0i64,
             CSslGlobals::m_hImplicitIssersChangeEvent);
      if ( !v3
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        LastError = GetLastError();
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          14i64,
          &WPP_092b895ef39c3c047a28e4103b904d61_Traceguids,
          LastError);
      }
      CSslGlobals::m_hCertLocator = v1;
      CSslGlobals::m_hIssuersLocator = v3;
    }
    else
    {
      v2 = GetLastError();
      v0 = v2;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_092b895ef39c3c047a28e4103b904d61_Traceguids, v2);
    }
  }
  RtlReleaseResource(&SslGlobalLock);
  return v0;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092F60: using guessed type void *CSslGlobals::m_hIssuersLocator;
// 180092F68: using guessed type void *CSslGlobals::m_hCertLocator;
// 180098190: using guessed type void *__stdcall CryptObjectLocatorInitialize(const char *, unsigned int, unsigned int, void *, void *);
