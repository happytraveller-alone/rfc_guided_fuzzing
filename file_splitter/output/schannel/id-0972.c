// File count: 972
// Total lines: 277
----------------------------------------
__int64 __fastcall GetUserAppCertDataCallback(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  int v4; // ebx
  void *v7; // r13
  unsigned int v8; // esi
  int v9; // edi
  __int64 *v11; // rcx
  __int64 v12; // rcx
  DWORD v13; // eax
  __int64 v14; // rdx
  int v15; // r8d
  void *v16; // r12
  unsigned int v17; // r14d
  const CERT_CONTEXT **v18; // r15
  const CERT_CONTEXT *v19; // rax
  unsigned int v20; // esi
  HCERTSTORE hCertStore; // rcx
  unsigned int v22; // esi
  unsigned int v23; // esi
  DWORD LastError; // eax
  __int64 v25; // rdx
  HLOCAL v26; // rax
  HLOCAL v27; // r12
  _DWORD *v28; // r15
  unsigned int v29; // r14d
  __int64 *v30; // rcx
  int v31; // r14d
  int v32; // eax
  __int64 v33; // rcx
  int v34; // r14d
  __int64 v35; // rax
  CCipherMill *v36; // rcx
  __int64 v37; // rdx
  DWORD pcbElement; // [rsp+38h] [rbp-39h] BYREF
  DWORD v39; // [rsp+3Ch] [rbp-35h]
  int v40; // [rsp+40h] [rbp-31h]
  int v41[2]; // [rsp+48h] [rbp-29h] BYREF
  _DWORD *v42; // [rsp+50h] [rbp-21h]
  __int64 *v43; // [rsp+58h] [rbp-19h]
  int v44[2]; // [rsp+60h] [rbp-11h] BYREF
  __int64 v45; // [rsp+68h] [rbp-9h]
  __int64 v46; // [rsp+70h] [rbp-1h]
  __int128 pvSaveToPara; // [rsp+78h] [rbp+7h] BYREF
  const CERT_CONTEXT *v48; // [rsp+88h] [rbp+17h]

  v4 = 0;
  v44[0] = 0;
  v45 = 0i64;
  v7 = 0i64;
  v41[0] = 0;
  v8 = 0;
  v42 = 0i64;
  v9 = 1;
  v44[1] = 1;
  v41[1] = 1;
  if ( !(unsigned int)SchannelInit(1) )
    return 2148074244i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 64i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  if ( !a4 )
    goto LABEL_64;
  if ( !a3 )
    goto LABEL_64;
  v11 = *(__int64 **)(a3 + 8);
  if ( !v11 )
    goto LABEL_64;
  v12 = *v11;
  if ( (unsigned int)(*(_DWORD *)v12 - 1) > 4 )
    goto LABEL_64;
  if ( *(_DWORD *)v12 == 4 )
  {
    v13 = *(_DWORD *)(v12 + 4);
    v14 = *(_QWORD *)(v12 + 8);
    v15 = *(_DWORD *)(v12 + 72);
    v16 = *(void **)(v12 + 16);
  }
  else
  {
    v13 = *(_DWORD *)(v12 + 8);
    v14 = *(_QWORD *)(v12 + 16);
    v15 = *(_DWORD *)(v12 + 52);
    v16 = *(void **)(v12 + 24);
  }
  v17 = 0;
  v46 = (__int64)v16;
  v40 = v15;
  v43 = (__int64 *)v14;
  v39 = v13;
  if ( v13 )
  {
    v18 = (const CERT_CONTEXT **)v14;
    while ( 1 )
    {
      v19 = *v18;
      pcbElement = 0;
      v48 = v19;
      v20 = v8 + 16;
      if ( !CertSerializeCertificateStoreElement(v19, 0, 0i64, &pcbElement) )
        break;
      v8 = pcbElement + v20;
      if ( (v40 & 0x10000) != 0 )
      {
        hCertStore = v48->hCertStore;
        v22 = v8 + 8;
        pvSaveToPara = 0i64;
        if ( !CertSaveStore(hCertStore, 1u, 1u, 2u, &pvSaveToPara, 0) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            LastError = GetLastError();
            v25 = 66i64;
            goto LABEL_31;
          }
          goto LABEL_32;
        }
        v8 = pvSaveToPara + v22;
      }
      ++v17;
      ++v18;
      if ( v17 >= v39 )
        goto LABEL_20;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      LastError = GetLastError();
      v25 = 65i64;
      goto LABEL_31;
    }
    goto LABEL_32;
  }
LABEL_20:
  if ( !v16 )
  {
LABEL_34:
    if ( v8 )
    {
      if ( (a2 & 8) != 0 )
        v26 = SPExternalAlloc(v8);
      else
        v26 = PvExtVirtualAlloc(v8);
      v7 = v26;
      v27 = v26;
      if ( !v26 )
        goto LABEL_39;
      pcbElement = 0;
      v28 = v26;
      v29 = v8;
      if ( v39 )
      {
        v30 = v43;
        while ( 1 )
        {
          v45 = *v30;
          v44[0] = 40;
          v31 = v29 - 4;
          v42 = v28 + 1;
          v41[0] = v31;
          v32 = UploadCertContextCallback(0i64, 0i64, (__int64)v44, (__int64)v41);
          v4 = v32;
          if ( v32 < 0 )
            break;
          v33 = (unsigned int)v41[0];
          v29 = v31 - v41[0];
          *v28 = v41[0];
          v28 = (_DWORD *)((char *)v28 + v33 + 4);
          if ( (v40 & 0x10000) != 0 )
          {
            if ( v29 < 4 )
              goto LABEL_39;
            v34 = v29 - 4;
            v42 = v28 + 1;
            v41[0] = v34;
            v32 = UploadCertStoreCallback(1i64, 0i64, (__int64)v44, v41);
            v4 = v32;
            if ( v32 < 0 )
            {
              v36 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                v37 = 69i64;
                goto LABEL_60;
              }
              goto LABEL_65;
            }
            v35 = (unsigned int)v41[0];
            v29 = v34 - v41[0];
            *v28 = v41[0];
            v28 = (_DWORD *)((char *)v28 + v35 + 4);
          }
          v30 = v43 + 1;
          ++pcbElement;
          ++v43;
          if ( pcbElement >= v39 )
            goto LABEL_48;
        }
        v36 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          v37 = 68i64;
          goto LABEL_60;
        }
        goto LABEL_65;
      }
LABEL_48:
      if ( v46 )
      {
        v45 = v46;
        v44[0] = 8;
        if ( v29 < 4 )
        {
LABEL_39:
          v4 = -2146893056;
          goto LABEL_65;
        }
        v42 = v28 + 1;
        v41[0] = v29 - 4;
        v32 = UploadCertStoreCallback(0i64, 0i64, (__int64)v44, v41);
        v4 = v32;
        if ( v32 < 0 )
        {
          v36 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            v37 = 70i64;
LABEL_60:
            WPP_SF_D(*((_QWORD *)v36 + 2), v37, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, (unsigned int)v32);
          }
          goto LABEL_65;
        }
        *v28 = v41[0];
      }
      if ( v4 >= 0 )
        goto LABEL_69;
      goto LABEL_65;
    }
LABEL_64:
    v4 = -2146893052;
    goto LABEL_65;
  }
  pvSaveToPara = 0i64;
  v23 = v8 + 8;
  if ( CertSaveStore(v16, 1u, 1u, 2u, &pvSaveToPara, 0) )
  {
    v8 = pvSaveToPara + v23;
    goto LABEL_34;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    LastError = GetLastError();
    v25 = 67i64;
LABEL_31:
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), v25, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, LastError);
  }
LABEL_32:
  v4 = -2146893043;
LABEL_65:
  if ( (a2 & 8) != 0 )
    SPExternalFree(v7);
  else
    FreeExtVirtualAlloc(v7);
  v8 = 0;
  v27 = 0i64;
  v9 = 0;
LABEL_69:
  *(_DWORD *)(a4 + 4) = v9;
  *(_QWORD *)(a4 + 8) = v27;
  *(_DWORD *)a4 = v8;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 71i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  return (unsigned int)v4;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
