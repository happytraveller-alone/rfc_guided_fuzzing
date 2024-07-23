// File count: 1140
// Total lines: 49
----------------------------------------
__int64 __fastcall DssGetCertPublicKeyBlob(const struct _CERT_CONTEXT *a1, HLOCAL *a2, unsigned int *a3)
{
  unsigned int v5; // ebx
  unsigned __int8 *pbData; // rax
  BOOL v7; // eax
  int v8; // ecx
  HCRYPTKEY hKey; // [rsp+50h] [rbp+8h] BYREF

  *a2 = 0i64;
  hKey = 0i64;
  if ( CryptImportPublicKeyInfoEx(
         g_hDhSchannelProv,
         a1->dwCertEncodingType,
         &a1->pCertInfo->SubjectPublicKeyInfo,
         0x2200u,
         0,
         0i64,
         &hKey)
    && CryptExportKey(hKey, 0i64, 6u, 0x80u, 0i64, a3) )
  {
    pbData = (unsigned __int8 *)SPExternalAlloc(*a3);
    *a2 = pbData;
    if ( pbData )
    {
      v7 = CryptExportKey(hKey, 0i64, 6u, 0x80u, pbData, a3);
      v8 = 0;
      if ( !v7 )
        v8 = -2146893052;
      v5 = v8;
    }
    else
    {
      v5 = -2146893056;
    }
  }
  else
  {
    v5 = -2146893052;
  }
  if ( hKey )
    CryptDestroyKey(hKey);
  if ( v5 )
  {
    LocalFree(*a2);
    *a2 = 0i64;
  }
  return v5;
}
