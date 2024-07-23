// File count: 1128
// Total lines: 17
----------------------------------------
void __fastcall DTLSCookieManager::~DTLSCookieManager(DTLSCookieManager *this)
{
  void *v2; // rcx
  void *v3; // rcx

  v2 = (void *)*((_QWORD *)this + 3);
  if ( v2 )
  {
    BCryptCloseAlgorithmProvider(v2, 0);
    *((_QWORD *)this + 3) = 0i64;
  }
  v3 = (void *)*((_QWORD *)this + 1);
  if ( v3 )
    SPExternalFree(v3);
  *((_DWORD *)this + 4) = 0;
}
