// File count: 13
// Total lines: 156
-----------------------------------------
__int64 __fastcall VerifyEcdsaParams(
        struct CSsl3TlsClientContext *a1,
        unsigned __int8 *a2,
        unsigned int a3,
        enum _eTlsHashAlgorithm a4,
        unsigned __int8 *pbEncoded,
        DWORD cbEncoded)
{
  struct _RTL_RESOURCE *v7; // rcx
  char *v9; // r14
  const void **v10; // rdi
  BOOL v11; // eax
  struct _RTL_RESOURCE *v12; // rcx
  DWORD LastError; // eax
  DWORD v14; // ebx
  unsigned int v15; // ebx
  enum _eTlsHashAlgorithm v16; // ecx
  NTSTATUS v17; // eax
  NTSTATUS v18; // eax
  unsigned __int8 v20; // r9
  int v21; // r8d
  int v22; // edx
  BCRYPT_KEY_HANDLE *phKey; // [rsp+20h] [rbp-89h]
  __int64 dwFlags; // [rsp+28h] [rbp-81h]
  DWORD cbSignature; // [rsp+40h] [rbp-69h] BYREF
  UCHAR pbOutput[4]; // [rsp+44h] [rbp-65h] BYREF
  ULONG cbHash; // [rsp+48h] [rbp-61h] BYREF
  BCRYPT_KEY_HANDLE hObject; // [rsp+50h] [rbp-59h] BYREF
  ULONG pcbResult; // [rsp+58h] [rbp-51h] BYREF
  unsigned int v30; // [rsp+5Ch] [rbp-4Dh]
  unsigned __int8 *v31; // [rsp+60h] [rbp-49h]
  UCHAR pbHash[64]; // [rsp+70h] [rbp-39h] BYREF

  v31 = a2;
  v7 = (struct _RTL_RESOURCE *)(*((_QWORD *)a1 + 11) + 72i64);
  v30 = a3;
  cbHash = 0;
  hObject = 0i64;
  v9 = 0i64;
  pcbResult = 0;
  v10 = 0i64;
  *(_DWORD *)pbOutput = 0;
  cbSignature = 0;
  RtlAcquireResourceShared(v7, 1u);
  v11 = CryptImportPublicKeyInfoEx2(
          **(_DWORD **)(*((_QWORD *)a1 + 11) + 48i64),
          (PCERT_PUBLIC_KEY_INFO)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)a1 + 11) + 48i64) + 24i64) + 96i64),
          0x80000000,
          0i64,
          &hObject);
  v12 = (struct _RTL_RESOURCE *)(*((_QWORD *)a1 + 11) + 72i64);
  if ( !v11 )
  {
    RtlReleaseResource(v12);
    LastError = GetLastError();
    v14 = LastError;
    v20 = 43;
LABEL_22:
    v21 = LastError;
    v22 = 1107;
    goto LABEL_34;
  }
  RtlReleaseResource(v12);
  LastError = BCryptGetProperty(hObject, L"KeyLength", pbOutput, 4u, &pcbResult, 0);
  v14 = LastError;
  if ( LastError )
  {
    v20 = 80;
    goto LABEL_22;
  }
  v15 = (*(_DWORD *)pbOutput >> 3) + ((pbOutput[0] & 7) != 0);
  v9 = (char *)SPExternalAlloc(2 * v15);
  if ( !v9 )
  {
    v14 = 14;
    goto LABEL_13;
  }
  if ( CryptDecodeObject(1u, (LPCSTR)0x2F, pbEncoded, cbEncoded, 0, 0i64, &cbSignature) )
  {
    v10 = (const void **)SPExternalAlloc(cbSignature);
    if ( !v10 )
    {
      v14 = -2146893056;
      goto LABEL_13;
    }
    if ( !CryptDecodeObject(1u, (LPCSTR)0x2F, pbEncoded, cbEncoded, 0, v10, &cbSignature) )
    {
      v14 = GetLastError();
      goto LABEL_13;
    }
    if ( *(_DWORD *)v10 <= v15 && *((_DWORD *)v10 + 4) <= v15 )
    {
      memcpy_0(v9, v10[1], *(unsigned int *)v10);
      memcpy_0(&v9[v15], v10[3], *((unsigned int *)v10 + 4));
      cbSignature = 2 * v15;
      ReverseInPlace((unsigned __int8 *)v9, v15);
      ReverseInPlace((unsigned __int8 *)&v9[(unsigned __int64)cbSignature >> 1], cbSignature >> 1);
      v16 = TlsHashAlgorithm_Sha1;
      if ( a4 )
        v16 = a4;
      v17 = GenerateTlsHash(v16, (UCHAR *)a1, v31, v30, pbHash, &cbHash);
      v14 = v17;
      if ( v17 )
      {
        v20 = 80;
        v21 = v17;
        v22 = 1109;
      }
      else
      {
        v18 = BCryptVerifySignature(hObject, 0i64, pbHash, cbHash, (PUCHAR)v9, cbSignature, 0);
        v14 = v18;
        if ( !v18 )
          goto LABEL_13;
        v20 = 51;
        v21 = v18;
        v22 = 1110;
      }
      goto LABEL_34;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      LODWORD(dwFlags) = v15;
      LODWORD(phKey) = *((_DWORD *)v10 + 4);
      WPP_SF_DDD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xAu,
        (__int64)&WPP_3e0ca11e9b65363ec3903422d835754d_Traceguids,
        *(_DWORD *)v10,
        phKey,
        dwFlags);
    }
    v14 = 13;
    v21 = 13;
  }
  else
  {
    v14 = GetLastError();
    v21 = v14;
  }
  v22 = 1108;
  v20 = 50;
LABEL_34:
  CSslContext::SetErrorAndFatalAlert((__int64)a1, v22, v21, v20);
LABEL_13:
  if ( hObject )
    BCryptDestroyKey(hObject);
  if ( v9 )
    SPExternalFree(v9);
  if ( v10 )
    SPExternalFree(v10);
  return v14;
}
// 18002BF6A: variable 'phKey' is possibly undefined
// 18002BF6A: variable 'dwFlags' is possibly undefined
