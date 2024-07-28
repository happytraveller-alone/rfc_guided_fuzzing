//----- (0000000180062074) ----------------------------------------------------
__int64 IsEccCurveGroupPolicyEnabled()
{
  unsigned int v0; // ebx
  DWORD Type; // [rsp+40h] [rbp+8h] BYREF
  DWORD cbData; // [rsp+48h] [rbp+10h] BYREF
  HKEY hKey; // [rsp+50h] [rbp+18h] BYREF

  hKey = 0i64;
  v0 = 0;
  if ( RegOpenKeyExW(
         HKEY_LOCAL_MACHINE,
         L"Software\\Policies\\Microsoft\\Cryptography\\Configuration\\SSL\\00010002",
         0,
         0x20119u,
         &hKey)
    || !RegQueryValueExW(hKey, L"EccCurves", 0i64, &Type, 0i64, &cbData) && Type == 7 )
  {
    v0 = 1;
  }
  if ( hKey )
    RegCloseKey(hKey);
  return v0;
}
