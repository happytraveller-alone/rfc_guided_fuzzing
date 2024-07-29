//----- (0000000180065AF8) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateCertVerifySignature(__int64 a1)
{
  BYTE *pbSignature; // r14
  BYTE *v3; // rbx
  ULONG LastError; // edi
  __int64 v5; // r15
  __int64 v6; // rax
  unsigned int v7; // eax
  const void *v8; // r15
  BYTE *v9; // rax
  DWORD v10; // r15d
  bool v11; // zf
  int v12; // eax
  const wchar_t *v13; // r9
  __int64 v14; // rax
  __int64 v15; // rcx
  int v16; // edx
  __int64 v17; // r10
  _QWORD *v18; // rcx
  __int64 v19; // rcx
  SECURITY_STATUS v20; // eax
  int v21; // ecx
  __int128 *p_pPaddingInfo; // rdx
  BYTE *v23; // rdx
  unsigned int v24; // r15d
  unsigned int v25; // edx
  unsigned int v26; // ecx
  DWORD v27; // edx
  __int16 v28; // cx
  __int64 v29; // rax
  __int64 v30; // rbx
  void *v31; // rcx
  DWORD cbHashValue; // [rsp+40h] [rbp-C0h] BYREF
  DWORD pcbResult; // [rsp+44h] [rbp-BCh] BYREF
  int v35; // [rsp+48h] [rbp-B8h] BYREF
  __int128 pPaddingInfo; // [rsp+50h] [rbp-B0h] BYREF
  unsigned int v37; // [rsp+60h] [rbp-A0h]
  BYTE *v38; // [rsp+68h] [rbp-98h]
  BYTE pbHashValue[192]; // [rsp+70h] [rbp-90h] BYREF

  pbSignature = 0i64;
  v35 = 0;
  v3 = 0i64;
  LastError = 0;
  if ( !*(_WORD *)(a1 + 140) )
    goto LABEL_44;
  if ( !*(_WORD *)(a1 + 142) )
    goto LABEL_44;
  v5 = *(_QWORD *)(a1 + 8);
  if ( !v5 )
    goto LABEL_44;
  v6 = *(_QWORD *)(a1 + 72);
  if ( !v6 )
    goto LABEL_44;
  pcbResult = 0;
  if ( *(_BYTE *)(v6 + 78) && !*(_BYTE *)(v6 + 79) )
  {
    v7 = *(unsigned __int16 *)(v5 + 944);
    *(_WORD *)(a1 + 140) = v7;
    if ( !(_WORD)v7 || (v8 = *(const void **)(v5 + 936)) == 0i64 )
    {
      LastError = 1359;
      goto LABEL_51;
    }
    v9 = (BYTE *)SPExternalAlloc(v7);
    pbSignature = v9;
    if ( v9 )
    {
      memcpy_0(v9, v8, *(unsigned __int16 *)(a1 + 140));
      v10 = *(unsigned __int16 *)(a1 + 140);
      pcbResult = v10;
      goto LABEL_33;
    }
LABEL_18:
    LastError = 14;
    goto LABEL_51;
  }
  memset_0(pbHashValue, 0, sizeof(pbHashValue));
  v11 = *(_DWORD *)(a1 + 104) == 1;
  cbHashValue = 0;
  if ( v11 && (v12 = *(_DWORD *)(v5 + 64), (v12 & 0x40051555) != 0) )
  {
    v13 = *(const wchar_t **)(a1 + 112);
  }
  else
  {
    v12 = *(_DWORD *)(v5 + 64);
    v13 = 0i64;
  }
  LastError = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertVerifyContentHash(
                a1,
                (v12 & 0x40051555) != 0,
                *(enum _eTlsHashAlgorithm *)(a1 + 100),
                v13,
                pbHashValue,
                0xC0u,
                &cbHashValue);
  if ( LastError )
    goto LABEL_51;
  pbSignature = (BYTE *)SPExternalAlloc(*(unsigned __int16 *)(a1 + 140));
  if ( !pbSignature )
    goto LABEL_18;
  LastError = SslImpersonateClient(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 80i64) + 752i64), &v35);
  if ( !LastError )
  {
    v14 = *(_QWORD *)(a1 + 8);
    if ( (*(_DWORD *)(v14 + 64) & 0x40051555) != 0 )
    {
      v15 = *(_QWORD *)(v14 + 24);
      if ( !v15 )
        goto LABEL_44;
      v16 = 2;
      v17 = *(_QWORD *)(v15 + 8);
      v18 = *(_QWORD **)(v14 + 8);
      if ( *(_DWORD *)(a1 + 104) != 1 )
        v16 = 0;
      v19 = v18 ? *v18 : 0i64;
      v20 = SslSignHash(
              v19,
              v17,
              pbHashValue,
              cbHashValue,
              pbSignature,
              *(unsigned __int16 *)(a1 + 140),
              &pcbResult,
              v16);
    }
    else
    {
      v11 = *(_DWORD *)(a1 + 104) == 1;
      v21 = 0;
      pPaddingInfo = 0i64;
      p_pPaddingInfo = 0i64;
      if ( v11 )
      {
        p_pPaddingInfo = &pPaddingInfo;
        *(_QWORD *)&pPaddingInfo = *(_QWORD *)(a1 + 112);
        v21 = 8;
        DWORD2(pPaddingInfo) = cbHashValue;
      }
      v20 = NCryptSignHash(
              *(_QWORD *)(*(_QWORD *)(a1 + 72) + 104i64),
              p_pPaddingInfo,
              pbHashValue,
              cbHashValue,
              pbSignature,
              *(unsigned __int16 *)(a1 + 140),
              &pcbResult,
              v21 | 0x40);
    }
    LastError = v20;
    if ( !v20 )
    {
      v10 = pcbResult;
LABEL_33:
      v23 = pbSignature;
      if ( *(_DWORD *)(a1 + 104) == 1 )
      {
        if ( v10 <= 0xFFFF )
        {
          *(_WORD *)(a1 + 142) = v10;
          pbSignature = 0i64;
          v3 = v23;
          goto LABEL_43;
        }
      }
      else if ( *(_DWORD *)(a1 + 104) == 3 )
      {
        v24 = v10 >> 1;
        ReverseInPlace(pbSignature, v24);
        ReverseInPlace(&pbSignature[v24], v25);
        v26 = *(unsigned __int16 *)(a1 + 142);
        LODWORD(pPaddingInfo) = v24;
        *((_QWORD *)&pPaddingInfo + 1) = pbSignature;
        v37 = v24;
        v38 = &pbSignature[v24];
        v3 = (BYTE *)SPExternalAlloc(v26);
        if ( !v3 )
        {
          LastError = 14;
          goto LABEL_45;
        }
        cbHashValue = *(unsigned __int16 *)(a1 + 142);
        if ( !CryptEncodeObject(1u, (LPCSTR)0x2F, &pPaddingInfo, v3, &cbHashValue) )
        {
          LastError = GetLastError();
          goto LABEL_45;
        }
        v27 = *(unsigned __int16 *)(a1 + 142);
        v28 = cbHashValue;
        if ( cbHashValue <= v27 )
        {
          *(_WORD *)(a1 + 142) = cbHashValue;
          *(_WORD *)(a1 + 138) += v28 - v27;
LABEL_43:
          *(_QWORD *)(a1 + 144) = v3;
          v3 = 0i64;
          goto LABEL_45;
        }
      }
LABEL_44:
      LastError = 1359;
    }
  }
LABEL_45:
  if ( v35 )
    RevertToSelf();
  if ( v3 )
    SPExternalFree(v3);
  if ( pbSignature )
    SPExternalFree(pbSignature);
LABEL_51:
  v29 = *(_QWORD *)(a1 + 72);
  if ( *(_BYTE *)(v29 + 78) && !*(_BYTE *)(v29 + 79) )
  {
    v30 = *(_QWORD *)(a1 + 8);
    v31 = *(void **)(v30 + 936);
    if ( v31 )
    {
      SPExternalFree(v31);
      *(_QWORD *)(v30 + 936) = 0i64;
    }
    *(_DWORD *)(v30 + 944) = 0;
  }
  return LastError;
}
// 180065DAF: variable 'v25' is possibly undefined
// 180098540: using guessed type __int64 __fastcall SslSignHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);

