// File count: 1054
// Total lines: 34
----------------------------------------
void __fastcall CSslCredManager::FreeCredentialManager(CSslCredManager *this)
{
  CSslCredManager *v1; // rbx
  void *v2; // rcx
  void *v3; // rcx
  __int64 v4; // rax

  v1 = CSslCredManager::m_pCredManager;
  if ( CSslCredManager::m_pCredManager )
  {
    v2 = (void *)*((_QWORD *)CSslCredManager::m_pCredManager + 8);
    if ( v2 )
    {
      UnregisterGPNotification(v2);
      CloseHandle(*((HANDLE *)v1 + 8));
    }
    v3 = (void *)*((_QWORD *)v1 + 9);
    if ( v3 )
    {
      if ( *((_QWORD *)v1 + 10) )
      {
        CertControlStore(v3, 0, 5u, (char *)v1 + 80);
        CloseHandle(*((HANDLE *)v1 + 10));
        v3 = (void *)*((_QWORD *)v1 + 9);
      }
      CertCloseStore(v3, 0);
    }
    RtlDeleteCriticalSection((PRTL_CRITICAL_SECTION)((char *)v1 + 8));
    v4 = *(_QWORD *)v1;
    CSslCredManager::m_pCredManager = 0i64;
    (*(void (__fastcall **)(CSslCredManager *, __int64))(v4 + 8))(v1, 1i64);
  }
}
