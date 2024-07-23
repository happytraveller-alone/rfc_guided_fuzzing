// File count: 1141
// Total lines: 96
----------------------------------------
__int64 __fastcall ImportNcryptExportBcrypt(struct CSslContext *a1, const unsigned __int16 *a2, void **a3)
{
  BYTE *v6; // rdi
  PBYTE v7; // rsi
  BCRYPT_ALG_HANDLE v8; // r13
  const WCHAR *v9; // r15
  struct _RTL_RESOURCE *v10; // rcx
  int CertPublicKeyBlob; // ebx
  DWORD cbData; // ecx
  BYTE *pbData; // rax
  struct _RTL_RESOURCE *v14; // rcx
  __int64 v15; // rcx
  NCRYPT_KEY_HANDLE hKey; // [rsp+40h] [rbp-20h] BYREF
  PBYTE v18; // [rsp+48h] [rbp-18h] BYREF
  LPCWSTR pszBlobType; // [rsp+50h] [rbp-10h]
  DWORD pcbResult; // [rsp+B0h] [rbp+50h] BYREF
  DWORD v21; // [rsp+B8h] [rbp+58h] BYREF

  *a3 = 0i64;
  hKey = 0i64;
  pcbResult = 0;
  v18 = 0i64;
  v21 = 0;
  v6 = 0i64;
  v7 = 0i64;
  if ( !wcsncmp(a2, L"DSA", 3ui64) )
  {
    v8 = g_hDSAProvider;
    v9 = L"DSAPUBLICBLOB";
    v10 = (struct _RTL_RESOURCE *)(*((_QWORD *)a1 + 11) + 72i64);
    pszBlobType = L"CAPIDSAPUBLICBLOB";
    RtlAcquireResourceShared(v10, 1u);
    CertPublicKeyBlob = DssGetCertPublicKeyBlob(
                          *(const struct _CERT_CONTEXT **)(*((_QWORD *)a1 + 11) + 48i64),
                          (HLOCAL *)&v18,
                          &v21);
    if ( CertPublicKeyBlob )
    {
      RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64));
      v7 = v18;
      goto LABEL_15;
    }
    v7 = v18;
    cbData = v21;
    pbData = v18;
  }
  else
  {
    if ( wcsncmp(a2, L"RSA", 3ui64) )
    {
      CertPublicKeyBlob = -2146893052;
      goto LABEL_15;
    }
    v8 = g_hRSAProvider;
    v9 = L"RSAPUBLICBLOB";
    v14 = (struct _RTL_RESOURCE *)(*((_QWORD *)a1 + 11) + 72i64);
    pszBlobType = L"CAPIPUBLICBLOB";
    RtlAcquireResourceShared(v14, 1u);
    v15 = *(_QWORD *)(*((_QWORD *)a1 + 11) + 40i64);
    pbData = *(BYTE **)v15;
    cbData = *(_DWORD *)(v15 + 8);
  }
  CertPublicKeyBlob = NCryptImportKey(hProvider, 0i64, pszBlobType, 0i64, &hKey, pbData, cbData, 8u);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64));
  if ( !CertPublicKeyBlob )
  {
    CertPublicKeyBlob = NCryptExportKey(hKey, 0i64, v9, 0i64, 0i64, 0, &pcbResult, 0);
    if ( CertPublicKeyBlob >= 0 )
    {
      v6 = (BYTE *)SPExternalAlloc(pcbResult);
      if ( v6 )
      {
        CertPublicKeyBlob = NCryptExportKey(hKey, 0i64, v9, 0i64, v6, pcbResult, &pcbResult, 0);
        if ( !CertPublicKeyBlob )
        {
          CertPublicKeyBlob = BCryptImportKeyPair(v8, 0i64, v9, a3, v6, pcbResult, 0);
          if ( CertPublicKeyBlob )
            CertPublicKeyBlob = -2146893043;
        }
      }
      else
      {
        CertPublicKeyBlob = -2146893056;
      }
    }
  }
LABEL_15:
  if ( v7 )
    LocalFree(v7);
  if ( v6 )
    SPExternalFree(v6);
  if ( hKey )
    NCryptFreeObject(hKey);
  return (unsigned int)CertPublicKeyBlob;
}
