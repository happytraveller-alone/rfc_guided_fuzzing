//----- (0000000180015FC8) ----------------------------------------------------
char GetExternalSchannelAlgorithms()
{
  BOOL v0; // ebx
  char result; // al
  int v2; // [rsp+30h] [rbp+8h] BYREF
  HANDLE KeyHandle; // [rsp+38h] [rbp+10h] BYREF

  v0 = 0;
  KeyHandle = 0i64;
  v2 = 0;
  if ( TlsOpenRegKey(
         L"\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\Cryptography\\Providers\\Microsoft SSL Protocol Provider",
         0i64,
         &KeyHandle) >= 0
    && GetSslDWordFromRegistry(KeyHandle, L"EnableTlsExternalAlgorithms", &v2) >= 0 )
  {
    v0 = v2 == 1;
  }
  result = TlsCloseRegKey(&KeyHandle);
  dword_1800921B0 = v0;
  if ( v0 )
  {
    GetExternalHashAlgorithms();
    GetExternalSignatureAlgorithms();
    GetExternalKeyExchangeAlgorithms();
    return GetExternalCipherAlgorithms();
  }
  return result;
}
// 180082408: using guessed type wchar_t aEnabletlsexter[28];
// 1800921B0: using guessed type int dword_1800921B0;

