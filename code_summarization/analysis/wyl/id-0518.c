//----- (00000001800263AC) ----------------------------------------------------
void __fastcall ReadOcspReadDirectoryRegistrySetting(HKEY hKey)
{
  HLOCAL lpData; // rbx
  SIZE_T uBytes; // [rsp+48h] [rbp+10h] BYREF
  DWORD Type; // [rsp+50h] [rbp+18h] BYREF

  LODWORD(uBytes) = 0;
  Type = 0;
  if ( !RegQueryValueExW(hKey, L"OcspReadDirectory", 0i64, &Type, 0i64, (LPDWORD)&uBytes) )
  {
    if ( (_DWORD)uBytes )
    {
      if ( Type == 1 )
      {
        lpData = LocalAlloc(0x40u, (unsigned int)uBytes);
        if ( lpData )
        {
          if ( RegQueryValueExW(hKey, L"OcspReadDirectory", 0i64, &Type, (LPBYTE)lpData, (LPDWORD)&uBytes) )
            LocalFree(lpData);
          else
            g_pszOcspReadDirectory = lpData;
        }
      }
    }
  }
}
