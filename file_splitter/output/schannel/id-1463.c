// File count: 1463
// Total lines: 64
----------------------------------------
__int64 __fastcall VerifyDssParams(UCHAR *a1, unsigned __int8 *a2, ULONG a3, BYTE *pbEncoded, DWORD cbEncoded)
{
  DWORD LastError; // eax
  unsigned __int8 v9; // r9
  int v10; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  ULONG v13; // edx
  int v14; // r8d
  DWORD cbSignature; // [rsp+40h] [rbp-31h] BYREF
  NCRYPT_KEY_HANDLE hKey; // [rsp+48h] [rbp-29h] BYREF
  BYTE pbHashValue[24]; // [rsp+50h] [rbp-21h] BYREF
  BYTE pvStructInfo[20]; // [rsp+68h] [rbp-9h] BYREF
  unsigned __int8 v20[20]; // [rsp+7Ch] [rbp+Bh] BYREF

  hKey = 0i64;
  cbSignature = 40;
  if ( !CryptDecodeObject(1u, (LPCSTR)0x28, pbEncoded, cbEncoded, 0, pvStructInfo, &cbSignature) )
  {
    LastError = GetLastError();
    v9 = 50;
    v10 = 1114;
    v11 = LastError;
LABEL_9:
    v14 = LastError;
    goto LABEL_10;
  }
  ReverseInPlace(pvStructInfo, 0x14u);
  ReverseInPlace(v20, v12);
  LastError = GenerateHash(g_hSHAProvider, a1, a2, a3, pbHashValue, v13);
  v11 = LastError;
  if ( LastError )
  {
    v9 = 80;
    v10 = 1115;
    goto LABEL_9;
  }
  RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64), 1u);
  v11 = DhDssPublicKeyFromCert(*(const struct _CERT_CONTEXT **)(*((_QWORD *)a1 + 11) + 48i64), &hKey);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64));
  if ( !v11 )
  {
    LastError = NCryptVerifySignature(hKey, 0i64, pbHashValue, 0x14u, pvStructInfo, cbSignature, 0);
    v11 = LastError;
    if ( !LastError )
      goto LABEL_11;
    v9 = 51;
    v10 = 1116;
    goto LABEL_9;
  }
  v9 = 43;
  v14 = v11;
  v10 = 1117;
LABEL_10:
  CSslContext::SetErrorAndFatalAlert((__int64)a1, v10, v14, v9);
LABEL_11:
  if ( hKey )
    NCryptFreeObject(hKey);
  return v11;
}
// 1800756F6: variable 'v12' is possibly undefined
// 180075718: variable 'v13' is possibly undefined
// 180075660: using guessed type unsigned __int8 var_44[20];
