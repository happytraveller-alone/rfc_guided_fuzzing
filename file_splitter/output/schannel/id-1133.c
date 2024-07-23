// File count: 1133
// Total lines: 46
----------------------------------------
__int64 __fastcall DTLSCookieManager::getDTlsCookieManager(struct DTLSCookieManager **a1)
{
  struct DTLSCookieManager *v1; // rax
  int v2; // edi
  DTLSCookieManager *v4; // rax
  const unsigned __int16 *v5; // rdx
  DTLSCookieManager *v6; // rbx

  v1 = DTLSCookieManager::m_pCookieMgr;
  v2 = 0;
  if ( !DTLSCookieManager::m_pCookieMgr )
  {
    RtlEnterCriticalSection(&CSslGlobals::m_DTLSInitCriticalSection);
    if ( !DTLSCookieManager::m_pCookieMgr )
    {
      v4 = (DTLSCookieManager *)operator new(0x40ui64);
      v6 = v4;
      if ( v4 )
      {
        *((_QWORD *)v4 + 1) = 0i64;
        *((_DWORD *)v4 + 4) = 0;
        *((_QWORD *)v4 + 3) = 0i64;
        *((_DWORD *)v4 + 8) = 0;
        *((_DWORD *)v4 + 9) = 0;
        *((_DWORD *)v4 + 10) = 0;
        *(_DWORD *)v4 = 32;
        *((_QWORD *)v4 + 6) = 600000i64;
        v2 = DTLSCookieManager::init(v4, v5);
        if ( v2 >= 0 )
          DTLSCookieManager::m_pCookieMgr = v6;
        else
          DTLSCookieManager::`scalar deleting destructor'(v6);
      }
      else
      {
        v2 = -1073741801;
      }
    }
    RtlLeaveCriticalSection(&CSslGlobals::m_DTLSInitCriticalSection);
    v1 = DTLSCookieManager::m_pCookieMgr;
  }
  *a1 = v1;
  return (unsigned int)v2;
}
// 18005BB6D: variable 'v5' is possibly undefined
