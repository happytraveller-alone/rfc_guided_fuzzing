// File count: 54
// Total lines: 98
------------------------------------------
__int64 __fastcall VerifyRsaParams(
        UCHAR *a1,
        unsigned __int8 *a2,
        ULONG a3,
        const unsigned __int16 *a4,
        enum _eTlsHashAlgorithm a5,
        ULONG a6,
        PUCHAR pbSignature,
        ULONG cbSignature)
{
  unsigned int v12; // eax
  ULONG v14; // r14d
  unsigned int v15; // ebx
  BOOL v16; // eax
  struct _RTL_RESOURCE *v17; // rcx
  const unsigned __int16 **p_pPaddingInfo; // rdx
  DWORD LastError; // eax
  unsigned __int8 v21; // r9
  int v22; // r8d
  int v23; // edx
  ULONG cbHash; // [rsp+40h] [rbp-79h] BYREF
  BCRYPT_KEY_HANDLE hKey; // [rsp+48h] [rbp-71h] BYREF
  const unsigned __int16 *pPaddingInfo; // [rsp+50h] [rbp-69h] BYREF
  __int128 v27; // [rsp+58h] [rbp-61h] BYREF
  UCHAR pbHash[64]; // [rsp+70h] [rbp-49h] BYREF

  hKey = 0i64;
  memset_0(pbHash, 0, sizeof(pbHash));
  cbHash = 0;
  pPaddingInfo = 0i64;
  v27 = 0i64;
  if ( a5 )
  {
    v12 = GenerateTlsHash(a5, a1, a2, a3, pbHash, &cbHash);
    v14 = cbHash;
  }
  else
  {
    v14 = 36;
    v12 = CSsl3TlsContext::ComputeRsaServerExchangeHashes(a1, a2, a3, pbHash);
    a6 = 2;
  }
  v15 = v12;
  if ( v12 )
  {
    v21 = 80;
    v22 = v12;
    v23 = 1105;
LABEL_18:
    CSslContext::SetErrorAndFatalAlert((__int64)a1, v23, v22, v21);
    goto LABEL_9;
  }
  RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)a1 + 11) + 72i64), 1u);
  v16 = CryptImportPublicKeyInfoEx2(
          **(_DWORD **)(*((_QWORD *)a1 + 11) + 48i64),
          (PCERT_PUBLIC_KEY_INFO)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)a1 + 11) + 48i64) + 24i64) + 96i64),
          0x80000000,
          0i64,
          &hKey);
  v17 = (struct _RTL_RESOURCE *)(*((_QWORD *)a1 + 11) + 72i64);
  if ( !v16 )
  {
    RtlReleaseResource(v17);
    LastError = GetLastError();
    v15 = LastError;
    v21 = 43;
LABEL_17:
    v22 = LastError;
    v23 = 1106;
    goto LABEL_18;
  }
  RtlReleaseResource(v17);
  if ( a6 == 8 )
  {
    p_pPaddingInfo = (const unsigned __int16 **)&v27;
    *(_QWORD *)&v27 = a4;
    DWORD2(v27) = v14;
    goto LABEL_8;
  }
  if ( a6 == 2 )
  {
    p_pPaddingInfo = &pPaddingInfo;
    pPaddingInfo = a4;
LABEL_8:
    LastError = BCryptVerifySignature(hKey, p_pPaddingInfo, pbHash, v14, pbSignature, cbSignature, a6);
    v15 = LastError;
    if ( !LastError )
      goto LABEL_9;
    v21 = 51;
    goto LABEL_17;
  }
  v15 = -2146893052;
LABEL_9:
  if ( hKey )
    BCryptDestroyKey(hKey);
  return v15;
}
