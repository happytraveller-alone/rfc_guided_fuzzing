//----- (000000018004CF24) ----------------------------------------------------
void UnloadSslRegOptions(void)
{
  __int64 v0; // rsi
  void ***v1; // rdi
  void **v2; // rbx
  void *v3; // rcx
  HKEY v4; // rcx
  void *v5; // rcx
  _QWORD v6[3]; // [rsp+20h] [rbp-28h] BYREF

  v0 = 3i64;
  v6[0] = &g_BaseSslRegOptions;
  v1 = (void ***)v6;
  v6[1] = &g_FipsRegOptions;
  v6[2] = &g_UserMappingRegOptions;
  do
  {
    v2 = *v1;
    v3 = **v1;
    if ( v3 )
    {
      RtlDeregisterWait(v3);
      *v2 = 0i64;
    }
    v4 = (HKEY)v2[2];
    if ( v4 )
    {
      RegCloseKey(v4);
      v2[2] = 0i64;
    }
    v5 = v2[1];
    if ( v5 )
    {
      CloseHandle(v5);
      v2[1] = 0i64;
    }
    ++v1;
    --v0;
  }
  while ( v0 );
  if ( g_hBcryptWait )
  {
    RtlDeregisterWait(g_hBcryptWait);
    g_hBcryptWait = 0i64;
  }
  if ( g_hBcryptEvent )
  {
    BCryptUnregisterConfigChangeNotify(g_hBcryptEvent);
    g_hBcryptEvent = 0i64;
  }
  if ( g_pszDomainList )
  {
    LocalFree(g_pszDomainList);
    g_pszDomainList = 0i64;
  }
  if ( g_pszOcspReadDirectory )
  {
    LocalFree(g_pszOcspReadDirectory);
    g_pszOcspReadDirectory = 0i64;
  }
}

