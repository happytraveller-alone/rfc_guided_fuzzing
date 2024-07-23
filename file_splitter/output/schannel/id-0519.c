// File count: 519
// Total lines: 39
-----------------------------------------
void __fastcall UserMappingsWatchParamKey(HKEY *a1)
{
  BYTE *lpData; // rax
  BYTE *v3; // rax
  DWORD cbData; // [rsp+40h] [rbp+8h] BYREF
  DWORD Type; // [rsp+50h] [rbp+18h] BYREF

  cbData = 0;
  if ( !WatchParamKeyHelper((char *)a1) )
  {
    lpData = g_pszDomainList;
    if ( g_pszDomainList )
    {
      LocalFree(g_pszDomainList);
      lpData = 0i64;
      g_pszDomainList = 0i64;
    }
    if ( !RegQueryValueExW(a1[2], L"UserMappingSafeDomains", 0i64, &Type, lpData, &cbData) )
    {
      if ( cbData )
      {
        if ( Type == 1 )
        {
          v3 = (BYTE *)LocalAlloc(0x40u, cbData);
          g_pszDomainList = v3;
          if ( v3 )
          {
            if ( RegQueryValueExW(a1[2], L"UserMappingSafeDomains", 0i64, &Type, v3, &cbData) )
            {
              LocalFree(g_pszDomainList);
              g_pszDomainList = 0i64;
            }
          }
        }
      }
    }
  }
}
