// File count: 438
// Total lines: 488
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::EccGenerateServerExchangeValue(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int *a3)
{
  int v3; // r15d
  __int64 v4; // rax
  int v5; // r14d
  CSsl3TlsServerContext *v6; // rbp
  __int16 v7; // r12
  int v8; // ecx
  int v9; // r13d
  struct CEphemKeyData **v10; // rdi
  struct CEphemKeyData *v11; // rax
  unsigned int v12; // esi
  __int64 v13; // rax
  __int64 v14; // rbx
  __int64 v15; // r15
  __int64 *v16; // rax
  struct CEphemKeyData **v17; // rbp
  unsigned int v18; // eax
  unsigned int EphemeralKeyInfo; // ebx
  struct _BCRYPT_ECCKEY_BLOB *v20; // rax
  unsigned int cbKey; // ecx
  int v22; // edi
  int v23; // esi
  __int64 v24; // rax
  __int64 v25; // rax
  unsigned int v26; // esi
  unsigned __int8 v27; // r11
  _DWORD *v28; // rax
  unsigned __int8 v29; // r8
  __int16 v30; // r15
  unsigned __int8 v31; // bl
  __int64 v32; // r10
  int v33; // r9d
  int v34; // ecx
  unsigned __int8 v35; // cl
  void **v36; // rdx
  __int64 v37; // rdx
  __int64 v38; // r8
  DWORD v39; // r9d
  DWORD v40; // ebx
  __int64 *v41; // rcx
  __int64 v42; // rax
  int v43; // eax
  __int64 v44; // rax
  __int64 v45; // rdx
  __int64 *v46; // rax
  __int64 v47; // rcx
  unsigned int v48; // esi
  unsigned __int8 *v50; // r10
  unsigned int v51; // esi
  struct _BCRYPT_ECCKEY_BLOB *v52; // rax
  ULONG v53; // ebx
  unsigned __int8 v54; // bl
  unsigned __int8 v55; // al
  unsigned int v56; // esi
  unsigned __int8 *v57; // rdi
  ULONG v58; // r8d
  __int16 v59; // cx
  int v60; // r13d
  unsigned int v61; // eax
  char *v62; // rax
  __int64 v63; // rcx
  unsigned __int8 v64; // r9
  __int64 v65; // rax
  unsigned __int8 v66[4]; // [rsp+40h] [rbp-C8h] BYREF
  DWORD cbSignature; // [rsp+44h] [rbp-C4h] BYREF
  int v68; // [rsp+48h] [rbp-C0h]
  enum _eTlsHashAlgorithm v69; // [rsp+4Ch] [rbp-BCh]
  CSsl3TlsServerContext *v70; // [rsp+50h] [rbp-B8h]
  unsigned int v71; // [rsp+58h] [rbp-B0h]
  int v72; // [rsp+5Ch] [rbp-ACh] BYREF
  unsigned __int8 *v73; // [rsp+60h] [rbp-A8h]
  unsigned int *v74; // [rsp+68h] [rbp-A0h]
  struct _BCRYPT_ECCKEY_BLOB *v75; // [rsp+70h] [rbp-98h]
  unsigned __int16 *v76; // [rsp+78h] [rbp-90h]
  BYTE pbHashValue[64]; // [rsp+80h] [rbp-88h] BYREF

  v4 = *((_QWORD *)this + 1);
  v5 = 0;
  LOBYTE(v3) = 0;
  v70 = this;
  v6 = this;
  v74 = a3;
  v73 = a2;
  v7 = 0;
  v8 = *(_DWORD *)(v4 + 52);
  v72 = 0;
  v76 = 0i64;
  v68 = v3;
  v66[0] = 0;
  v69 = TlsHashAlgorithm_None;
  v71 = 0;
  if ( v8 == 2 )
  {
    v9 = 1;
  }
  else
  {
    if ( v8 != 4 )
      return 1359;
    v9 = 3;
  }
  v10 = (struct CEphemKeyData **)((char *)v6 + 960);
  v11 = (struct CEphemKeyData *)*((_QWORD *)v6 + 120);
  if ( !v11 )
  {
    v12 = *((_DWORD *)v6 + 4);
    v13 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)v6 + 248i64))(v6);
    v14 = v13;
    if ( !v12 )
    {
      EphemeralKeyInfo = CSslCredential::GetEphemeralKeyInfo(
                           (CSslCredential *)v13,
                           0,
                           (struct CEphemKeyData **)(v13 + 496),
                           (struct CEphemKeyData **)v6 + 120);
      if ( EphemeralKeyInfo == 87 )
      {
        v5 = 1;
        goto LABEL_96;
      }
      goto LABEL_11;
    }
    if ( v12 == *(_DWORD *)(v13 + 140) )
    {
      v17 = (struct CEphemKeyData **)(v13 + 504);
      goto LABEL_10;
    }
    *v10 = 0i64;
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v13 + 552), 1u);
    v15 = v14 + 480;
    v16 = *(__int64 **)(v14 + 480);
    if ( v16 != (__int64 *)(v14 + 480) )
    {
      while ( *((_DWORD *)v16 + 4) != v12 )
      {
        v16 = (__int64 *)*v16;
        if ( v16 == (__int64 *)v15 )
          goto LABEL_89;
      }
      v17 = (struct CEphemKeyData **)(v16 + 3);
      if ( v16 != (__int64 *)-24i64 )
      {
LABEL_9:
        RtlReleaseResource((PRTL_RESOURCE)(v14 + 552));
        LOBYTE(v3) = v68;
LABEL_10:
        v18 = CSslCredential::GetEphemeralKeyInfo((CSslCredential *)v14, v12, v17, v10);
        v6 = v70;
        EphemeralKeyInfo = v18;
LABEL_11:
        if ( !EphemeralKeyInfo )
        {
          *(_DWORD *)(*((_QWORD *)v6 + 11) + 8i64) = *((_DWORD *)*v10 + 10);
          v11 = *v10;
          goto LABEL_13;
        }
LABEL_96:
        v64 = 40;
        if ( !v5 )
          v64 = 80;
        CSslContext::SetErrorAndFatalAlert((__int64)v6, 603, EphemeralKeyInfo, v64);
        CSslContext::SetErrorAndFatalAlert((__int64)v6, 1050, EphemeralKeyInfo, 0x50u);
        return EphemeralKeyInfo;
      }
      v6 = v70;
    }
LABEL_89:
    v62 = (char *)LocalAlloc(0x40u, 0x20ui64);
    if ( !v62 )
    {
      RtlReleaseResource((PRTL_RESOURCE)(v14 + 552));
      EphemeralKeyInfo = 14;
      goto LABEL_96;
    }
    *((_DWORD *)v62 + 4) = v12;
    *((_QWORD *)v62 + 1) = v62;
    *(_QWORD *)v62 = v62;
    v63 = *(_QWORD *)v15;
    if ( *(_QWORD *)(*(_QWORD *)v15 + 8i64) != v15 )
      __fastfail(3u);
    *(_QWORD *)v62 = v63;
    v17 = (struct CEphemKeyData **)(v62 + 24);
    *((_QWORD *)v62 + 1) = v15;
    *(_QWORD *)(v63 + 8) = v62;
    *(_QWORD *)v15 = v62;
    goto LABEL_9;
  }
LABEL_13:
  v20 = (struct _BCRYPT_ECCKEY_BLOB *)*((_QWORD *)v11 + 2);
  v75 = v20;
  if ( !v20 )
    return 87;
  cbKey = v20->cbKey;
  if ( (*((_BYTE *)v6 + 20) & 8) != 0 )
  {
    v3 = (unsigned __int8)v3;
    if ( cbKey <= 0xFF )
      v3 = (unsigned __int8)cbKey;
    EphemeralKeyInfo = 87;
    if ( cbKey <= 0xFF )
      EphemeralKeyInfo = 0;
    goto LABEL_17;
  }
  if ( cbKey <= 0x7F )
  {
    v3 = 2 * cbKey + 1;
    EphemeralKeyInfo = 0;
LABEL_17:
    v66[0] = v3;
    v68 = v3;
    goto LABEL_18;
  }
  EphemeralKeyInfo = 1359;
LABEL_18:
  if ( EphemeralKeyInfo )
    return EphemeralKeyInfo;
  v22 = *((_DWORD *)v6 + 16);
  v23 = (unsigned __int8)v3 + 6;
  if ( (v22 & 0x40400) == 0 )
  {
LABEL_38:
    memset_0(pbHashValue, 0, sizeof(pbHashValue));
    cbSignature = 0;
    v39 = 0;
    if ( (v22 & 0x43C00) != 0 )
    {
      v38 = (unsigned int)g_dwHashInfoTotalCount;
      v40 = 0;
      v37 = 0i64;
      if ( g_dwHashInfoTotalCount )
      {
        v41 = g_pHashInfo;
        while ( 1 )
        {
          v42 = *v41;
          if ( *v41 )
          {
            if ( *(_DWORD *)(v42 + 20) == v69 )
              break;
          }
          v37 = (unsigned int)(v37 + 1);
          ++v41;
          if ( (unsigned int)v37 >= g_dwHashInfoTotalCount )
            goto LABEL_112;
        }
        v40 = *(_DWORD *)(v42 + 8);
        v43 = 0;
      }
      else
      {
LABEL_112:
        v43 = 1168;
      }
      if ( v43 )
      {
LABEL_58:
        EphemeralKeyInfo = v43;
        if ( v43 >= 0 )
        {
          if ( v39 <= 0x8C )
            v39 = 140;
          v48 = v39 + v23;
          if ( !v73 )
          {
            *v74 = v48;
            return 0;
          }
          if ( *v74 < v48 )
          {
            *v74 = v48;
            return (unsigned int)-2146893023;
          }
          EphemeralKeyInfo = SslImpersonateClient(*(_QWORD *)(*((_QWORD *)v6 + 10) + 752i64), &v72);
          if ( EphemeralKeyInfo )
            goto LABEL_81;
          v50 = v73;
          v51 = v48 - 3;
          *v73 = 3;
          v50[1] = BYTE1(*((_DWORD *)v6 + 4));
          v50[2] = *((_BYTE *)v6 + 16);
          if ( (*((_BYTE *)v6 + 20) & 8) != 0 )
          {
            EphemeralKeyInfo = MontgomeryGetKeyExchangeBlob(v75, v50 + 4, v66);
            v55 = v66[0];
          }
          else
          {
            v52 = v75;
            v53 = v75->cbKey;
            if ( v53 > 0x7F )
            {
              v55 = v68;
              EphemeralKeyInfo = 1359;
              goto LABEL_72;
            }
            v54 = 2 * v53 + 1;
            if ( v50 == (unsigned __int8 *)-4i64 )
            {
              v55 = v54;
              EphemeralKeyInfo = 0;
              goto LABEL_72;
            }
            if ( (unsigned __int8)v3 < v54 )
            {
              v55 = v54;
              EphemeralKeyInfo = -2146893023;
              goto LABEL_72;
            }
            v50[4] = 4;
            memcpy_0(v50 + 5, &v52[1], v54 - 1i64);
            v55 = v54;
            EphemeralKeyInfo = 0;
          }
          v50 = v73;
LABEL_72:
          if ( EphemeralKeyInfo )
            goto LABEL_81;
          v50[3] = v55;
          v56 = -1 - v55 + v51;
          v57 = &v50[v55 + 4];
          v58 = v55 + 4;
          if ( (*((_DWORD *)v6 + 16) & 0x40400) == 0 )
          {
LABEL_76:
            v59 = v56 - 2;
            cbSignature = v56 - 2;
            v60 = v9 - 1;
            if ( v60 )
            {
              if ( v60 != 2 )
              {
LABEL_80:
                *v57 = HIBYTE(v59);
                v57[1] = cbSignature;
                *v74 = (_DWORD)v57 - (_DWORD)v50 + cbSignature + 2;
                goto LABEL_81;
              }
              v61 = SignEcdsaParams(v6, v50, v58, v69, v57 + 2, &cbSignature);
            }
            else
            {
              v61 = SignRsaParams(v6, v50, v58, v76, v69, v71, v57 + 2, &cbSignature);
            }
            EphemeralKeyInfo = v61;
            if ( v61 )
              goto LABEL_81;
            HIBYTE(v59) = BYTE1(cbSignature);
            LODWORD(v50) = (_DWORD)v73;
            goto LABEL_80;
          }
          if ( v56 >= 2 )
          {
            *(_WORD *)v57 = v7;
            v57 += 2;
            v56 -= 2;
            goto LABEL_76;
          }
          EphemeralKeyInfo = 1359;
LABEL_81:
          if ( v72 )
            RevertToSelf();
          return EphemeralKeyInfo;
        }
LABEL_117:
        CSslContext::SetErrorAndFatalAlert((__int64)v6, 1051, v43, 0x50u);
        return EphemeralKeyInfo;
      }
    }
    else
    {
      if ( v9 == 1 )
      {
        v40 = 36;
LABEL_52:
        if ( (v22 & 0x40051555) != 0 )
        {
          v44 = *((_QWORD *)v6 + 3);
          if ( v44 )
          {
            v45 = *(_QWORD *)(v44 + 8);
            v46 = (__int64 *)*((_QWORD *)v6 + 1);
            if ( v46 )
              v47 = *v46;
            else
              v47 = 0i64;
            v43 = SslSignHash(v47, v45, pbHashValue, v40, 0i64, 0, &cbSignature, 0);
            goto LABEL_57;
          }
        }
        else
        {
          v65 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, __int64, __int64, _QWORD))(*(_QWORD *)v6 + 248i64))(
                  v6,
                  v37,
                  v38,
                  0i64);
          if ( v65 )
          {
            v43 = NCryptSignHash(*(_QWORD *)(v65 + 104), 0i64, pbHashValue, v40, 0i64, cbSignature, &cbSignature, 0x40u);
LABEL_57:
            v39 = cbSignature;
            goto LABEL_58;
          }
        }
LABEL_116:
        EphemeralKeyInfo = -2146893052;
        v43 = -2146893052;
        goto LABEL_117;
      }
      v40 = 20;
    }
    if ( v40 > 0x40 )
      goto LABEL_116;
    goto LABEL_52;
  }
  v24 = *(_QWORD *)v6;
  LODWORD(v70) = (unsigned __int8)v3 + 8;
  v25 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(v24 + 248))(v6);
  if ( !v25 )
    return (unsigned int)-2146893052;
  v26 = *(_DWORD *)(v25 + 428);
  v27 = 0;
  v22 = *((_DWORD *)v6 + 16);
  v28 = &unk_18007C3A8;
  v29 = 0;
  v30 = 0;
  v31 = -1;
  v32 = 12i64;
  do
  {
    v33 = v28[1];
    if ( v33 == v9 && (v22 & *v28) != 0 && v29 < 0xCu )
    {
      v34 = *((unsigned __int16 *)v6 + 272);
      if ( _bittest(&v34, v29) )
      {
        if ( (v9 != 1 || v28[9] != 8 || v26 >> 3 >= 2 * (unsigned int)*((unsigned __int8 *)v28 + 32) + 2)
          && ((v22 & 0x3000) == 0 || v33 != 3 || !v28[10]) )
        {
          if ( (v35 = *((_BYTE *)v28 + 32), v35 < v27) && v35 > 0x14u || v27 <= 0x14u )
          {
            v31 = v29;
            v27 = *((_BYTE *)v28 + 32);
          }
        }
      }
    }
    v28 += 18;
    ++v29;
    --v32;
  }
  while ( v32 );
  v36 = (void **)&unk_18007C390;
  if ( v31 < 0xCu )
    v30 = *((_WORD *)&unk_18007C390 + 36 * v31);
  v7 = __ROR2__(v30, 8);
  if ( v7 )
  {
    while ( v30 != *(_WORD *)v36 )
    {
      v36 += 9;
      if ( v36 >= &CSsl3TlsServerContext::`vftable' )
        goto LABEL_37;
    }
    v69 = *((_DWORD *)v36 + 10);
    v76 = (unsigned __int16 *)v36[6];
    v71 = *((_DWORD *)v36 + 15);
LABEL_37:
    LOBYTE(v3) = v68;
    v23 = (int)v70;
    goto LABEL_38;
  }
  return 2148074289i64;
}
// 18003088E: conditional instruction was optimized away because r13d.4==3
// 18001BEC6: variable 'v3' is possibly undefined
// 1800308DD: variable 'v37' is possibly undefined
// 1800308DD: variable 'v38' is possibly undefined
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];
// 180098540: using guessed type __int64 __fastcall SslSignHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 18001BE70: using guessed type unsigned __int8 var_C8[4];
