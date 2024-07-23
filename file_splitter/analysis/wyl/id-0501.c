//----- (0000000180024BEC) ----------------------------------------------------
__int64 __fastcall ReadMultiSzFromRegistry(LPCWSTR lpSubKey, const unsigned __int16 *a2, BYTE **a3)
{
  BYTE *v4; // rbx
  unsigned int v5; // edi
  DWORD cbData; // [rsp+68h] [rbp+38h] BYREF
  int v8; // [rsp+6Ch] [rbp+3Ch]
  DWORD Type; // [rsp+70h] [rbp+40h] BYREF
  HKEY hKey; // [rsp+78h] [rbp+48h] BYREF

  v8 = HIDWORD(a2);
  hKey = 0i64;
  v4 = 0i64;
  cbData = 0;
  if ( !a3 )
    return (unsigned int)-1073741811;
  *a3 = 0i64;
  v5 = RegOpenKeyExW(HKEY_LOCAL_MACHINE, lpSubKey, 0, 0x20119u, &hKey);
  if ( v5 )
    goto LABEL_9;
  v5 = RegQueryValueExW(hKey, L"EccCurves", 0i64, &Type, 0i64, &cbData);
  if ( !v5 && Type == 7 )
  {
    v4 = (BYTE *)SPExternalAlloc(cbData + 4);
    if ( v4 )
    {
      v5 = RegQueryValueExW(hKey, L"EccCurves", 0i64, &Type, v4, &cbData);
      if ( !v5 && Type == 7 )
      {
        *(_WORD *)&v4[2 * ((unsigned __int64)cbData >> 1)] = 0;
        *(_WORD *)&v4[2 * ((unsigned __int64)cbData >> 1) + 2] = 0;
LABEL_9:
        *a3 = v4;
        goto LABEL_10;
      }
      SPExternalFree(v4);
    }
  }
LABEL_10:
  if ( hKey )
    RegCloseKey(hKey);
  return v5;
}

