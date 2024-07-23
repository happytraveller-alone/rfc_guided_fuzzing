// File count: 1457
// Total lines: 21
----------------------------------------
__int64 __fastcall DhDssPublicKeyFromCert(const struct _CERT_CONTEXT *a1, unsigned __int64 *a2)
{
  __int64 result; // rax
  PBYTE v4; // rbx
  unsigned int v5; // edi
  DWORD cbData; // [rsp+60h] [rbp+18h] BYREF
  PBYTE pbData; // [rsp+68h] [rbp+20h] BYREF

  pbData = 0i64;
  result = DssGetCertPublicKeyBlob(a1, (HLOCAL *)&pbData, &cbData);
  if ( !(_DWORD)result )
  {
    v4 = pbData;
    v5 = NCryptImportKey(hProvider, 0i64, L"CAPIDSAPUBLICBLOB", 0i64, a2, pbData, cbData, 8u);
    if ( v4 )
      SPExternalFree(v4);
    return v5;
  }
  return result;
}
