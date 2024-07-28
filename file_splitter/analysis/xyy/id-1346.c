//----- (000000018006A4E0) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::VerifySignature(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3)
{
  const void **v3; // rsi
  __int64 v5; // rcx
  int v6; // r8d
  unsigned int LastError; // ebx
  unsigned __int8 v8; // r9
  int v9; // edx
  UCHAR *v10; // r15
  ULONG v11; // r14d
  __int64 v12; // rax
  __int64 v13; // r13
  __int64 v14; // rax
  struct _CERT_PUBLIC_KEY_INFO *v15; // rcx
  NTSTATUS Property; // eax
  unsigned int v17; // r14d
  unsigned __int8 *v18; // rax
  unsigned __int8 *v19; // r15
  unsigned int v20; // edx
  NTSTATUS v21; // eax
  BCRYPT_KEY_HANDLE *phKey; // [rsp+20h] [rbp-79h]
  void *pvStructInfo; // [rsp+28h] [rbp-71h]
  DWORD pcbStructInfo; // [rsp+40h] [rbp-59h] BYREF
  ULONG cbHash; // [rsp+44h] [rbp-55h] BYREF
  UCHAR pbOutput[4]; // [rsp+48h] [rbp-51h] BYREF
  BCRYPT_KEY_HANDLE hObject; // [rsp+50h] [rbp-49h] BYREF
  ULONG pcbResult; // [rsp+58h] [rbp-41h] BYREF
  __int64 pPaddingInfo; // [rsp+60h] [rbp-39h] BYREF
  ULONG v31; // [rsp+68h] [rbp-31h]
  UCHAR pbHash[64]; // [rsp+70h] [rbp-29h] BYREF

  hObject = 0i64;
  v3 = 0i64;
  if ( a2 && a3 )
  {
    if ( a3 < 2 )
    {
      v5 = *(_QWORD *)(a1 + 8);
      v6 = -2146893048;
      LastError = -2146893048;
      v8 = 50;
      v9 = 1305;
LABEL_5:
      CSslContext::SetErrorAndFatalAlert(v5, v9, v6, v8);
      goto LABEL_42;
    }
    v10 = a2 + 2;
    v11 = a3 - 2;
    if ( a3 - 2 != (a2[1] | (*a2 << 8)) )
    {
      v6 = -2146893048;
      v9 = 1305;
      LastError = -2146893048;
LABEL_8:
      v8 = 50;
LABEL_9:
      v5 = *(_QWORD *)(a1 + 8);
      goto LABEL_5;
    }
    memset_0(pbHash, 0, sizeof(pbHash));
    v12 = *(_QWORD *)(a1 + 8);
    cbHash = 0;
    LastError = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertVerifyContentHash(
                  a1,
                  (*(_DWORD *)(v12 + 64) & 0x40051555) == 0,
                  *(enum _eTlsHashAlgorithm *)(a1 + 100),
                  0i64,
                  pbHash,
                  0x40u,
                  &cbHash);
    if ( !LastError )
    {
      v13 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 88i64);
      if ( !v13 )
      {
LABEL_12:
        LastError = 1359;
        goto LABEL_42;
      }
      RtlAcquireResourceShared((PRTL_RESOURCE)(v13 + 72), 1u);
      v14 = *(_QWORD *)(v13 + 48);
      if ( !v14
        || (v15 = *(struct _CERT_PUBLIC_KEY_INFO **)(v14 + 24)) == 0i64
        || v15 == (struct _CERT_PUBLIC_KEY_INFO *)-96i64 )
      {
        LastError = 1359;
        goto LABEL_40;
      }
      if ( !CryptImportPublicKeyInfoEx2(*(_DWORD *)v14, v15 + 2, 0x80000000, 0i64, &hObject) )
      {
        LastError = GetLastError();
        CSslContext::SetErrorAndFatalAlert(*(_QWORD *)(a1 + 8), 1306, LastError, 0x2Bu);
LABEL_40:
        RtlReleaseResource((PRTL_RESOURCE)(v13 + 72));
        goto LABEL_42;
      }
      RtlReleaseResource((PRTL_RESOURCE)(v13 + 72));
      if ( *(_DWORD *)(a1 + 104) == 1 )
      {
        pPaddingInfo = *(_QWORD *)(a1 + 112);
        v31 = cbHash;
        v21 = BCryptVerifySignature(hObject, &pPaddingInfo, pbHash, cbHash, v10, v11, 8u);
      }
      else
      {
        if ( *(_DWORD *)(a1 + 104) != 3 )
          goto LABEL_12;
        pcbStructInfo = 0;
        if ( !CryptDecodeObject(1u, (LPCSTR)0x2F, v10, v11, 0, 0i64, &pcbStructInfo) )
          goto LABEL_21;
        v3 = (const void **)SPExternalAlloc(pcbStructInfo);
        if ( !v3 )
          goto LABEL_24;
        if ( !CryptDecodeObject(1u, (LPCSTR)0x2F, v10, v11, 0, v3, &pcbStructInfo) )
        {
LABEL_21:
          LastError = GetLastError();
          v6 = LastError;
LABEL_22:
          v9 = 1108;
          goto LABEL_8;
        }
        *(_DWORD *)pbOutput = 0;
        pcbResult = 0;
        Property = BCryptGetProperty(hObject, L"KeyLength", pbOutput, 4u, &pcbResult, 0);
        LastError = Property;
        if ( Property )
        {
          v6 = Property;
          v9 = 1107;
          goto LABEL_8;
        }
        v17 = (*(_DWORD *)pbOutput >> 3) + ((pbOutput[0] & 7) != 0);
        pcbStructInfo = 2 * v17;
        v18 = (unsigned __int8 *)SPExternalAlloc(2 * v17);
        v19 = v18;
        if ( !v18 )
        {
LABEL_24:
          LastError = 14;
          goto LABEL_42;
        }
        if ( *(_DWORD *)v3 > v17 || *((_DWORD *)v3 + 4) > v17 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            LODWORD(pvStructInfo) = v17;
            LODWORD(phKey) = *((_DWORD *)v3 + 4);
            WPP_SF_DDD(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xEu,
              (__int64)WPP_922678f99ae534148d3bb024010f1556_Traceguids,
              *(_DWORD *)v3,
              phKey,
              pvStructInfo);
          }
          LastError = 13;
          v6 = 13;
          goto LABEL_22;
        }
        memcpy_0(v18, v3[1], *(unsigned int *)v3);
        memcpy_0(&v19[v17], v3[3], *((unsigned int *)v3 + 4));
        ReverseInPlace(v19, v17);
        ReverseInPlace(&v19[v17], v20);
        v21 = BCryptVerifySignature(hObject, 0i64, pbHash, cbHash, v19, pcbStructInfo, 0);
      }
      LastError = v21;
      if ( v21 )
      {
        v8 = 51;
        v6 = v21;
        v9 = 1306;
        goto LABEL_9;
      }
    }
  }
  else
  {
    LastError = 87;
  }
LABEL_42:
  if ( hObject )
    BCryptDestroyKey(hObject);
  if ( v3 )
    SPExternalFree(v3);
  return LastError;
}
// 18006A7DF: variable 'v20' is possibly undefined
// 18006A830: variable 'phKey' is possibly undefined
// 18006A830: variable 'pvStructInfo' is possibly undefined
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
