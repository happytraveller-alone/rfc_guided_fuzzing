//----- (00000001800049B0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::EccGenerateClientExchangeValue(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned int *a5)
{
  __int64 v5; // rax
  CSsl3TlsClientContext *v7; // rdi
  struct _BCRYPT_ECCKEY_BLOB *p_Size_4; // rsi
  bool v9; // zf
  __int64 v10; // r13
  int v11; // r15d
  int v12; // r12d
  unsigned int v13; // eax
  __int64 v14; // r14
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // edx
  CCipherMill *v18; // rcx
  unsigned __int8 *v19; // r14
  unsigned int v20; // r8d
  __int16 v21; // ax
  __int16 v22; // r12
  __int16 v23; // r12
  unsigned int *v24; // r9
  unsigned int v25; // edx
  int v26; // r15d
  unsigned int v27; // eax
  unsigned int EccBcryptKeyBlobFromKeyExchangeBlob; // ebx
  __int64 v29; // rax
  unsigned int v30; // edx
  __int64 v31; // rcx
  unsigned int EphemKey; // eax
  __int64 *v33; // rax
  __int64 v34; // rcx
  unsigned int EphemBlobFromKey; // eax
  struct _BCRYPT_ECCKEY_BLOB *v36; // r14
  unsigned int v37; // edx
  unsigned __int64 v38; // rcx
  unsigned __int64 v39; // rax
  void *v40; // rsp
  unsigned __int8 v41; // r8
  unsigned __int8 *v42; // rdx
  __int64 *v43; // rax
  __int64 v44; // rcx
  ULONG dwMagic; // ebx
  __int64 *v46; // rax
  __int64 v47; // rcx
  unsigned __int8 *v48; // r15
  int v49; // ecx
  int v50; // eax
  unsigned int EccDhPskSessionKeysHelper; // eax
  unsigned int v53; // eax
  unsigned __int8 v54; // r9
  int v55; // edx
  unsigned __int8 v56; // r9
  int v57; // r8d
  int v58; // edx
  int v59; // r8d
  int v60; // edx
  struct _BCRYPT_ECCKEY_BLOB *v61; // rax
  __int64 v62; // rcx
  __int64 v63; // [rsp+0h] [rbp-40h] BYREF
  int v64; // [rsp+40h] [rbp+0h] BYREF
  unsigned int Size; // [rsp+44h] [rbp+4h] BYREF
  enum _eTlsHashAlgorithm Size_4; // [rsp+48h] [rbp+8h] BYREF
  unsigned __int64 v67; // [rsp+50h] [rbp+10h] BYREF
  unsigned __int64 v68; // [rsp+58h] [rbp+18h] BYREF
  enum _eTlsSignatureAlgorithm v69; // [rsp+60h] [rbp+20h] BYREF
  ULONG v70; // [rsp+64h] [rbp+24h] BYREF
  unsigned int v71; // [rsp+68h] [rbp+28h] BYREF
  struct CEccCurveInfo *v72; // [rsp+70h] [rbp+30h] BYREF
  int v73; // [rsp+78h] [rbp+38h]
  unsigned __int8 v74[4]; // [rsp+7Ch] [rbp+3Ch]
  unsigned __int16 *v75; // [rsp+80h] [rbp+40h] BYREF
  struct _BCRYPT_ECCKEY_BLOB *v76; // [rsp+88h] [rbp+48h] BYREF
  unsigned __int8 *v77; // [rsp+90h] [rbp+50h]
  unsigned __int8 *v78; // [rsp+98h] [rbp+58h]

  v5 = *((_QWORD *)this + 1);
  v67 = 0i64;
  v68 = 0i64;
  v7 = this;
  v78 = a4;
  p_Size_4 = 0i64;
  v9 = *(_DWORD *)(v5 + 52) == 2;
  v10 = a3;
  v71 = 0;
  v76 = 0i64;
  v75 = 0i64;
  Size_4 = TlsHashAlgorithm_None;
  v70 = 0;
  if ( v9 )
  {
    v11 = 1;
  }
  else
  {
    if ( *(_DWORD *)(v5 + 52) != 4 )
      return 2148074248i64;
    v11 = 3;
  }
  if ( !a2 )
    return 2148074248i64;
  if ( a3 < 4 )
    goto LABEL_75;
  if ( *a2 != 3 )
  {
    v54 = 47;
    v55 = 800;
LABEL_77:
    EccBcryptKeyBlobFromKeyExchangeBlob = -2146893048;
    CSslContext::SetErrorAndFatalAlert((__int64)this, v55, -2146893048, v54);
    return EccBcryptKeyBlobFromKeyExchangeBlob;
  }
  v12 = a2[2] | (a2[1] << 8);
  v13 = a2[3];
  v73 = v12;
  *(_DWORD *)v74 = v13;
  if ( v13 < 2 )
    goto LABEL_75;
  v14 = v13 + 4;
  if ( (unsigned int)v14 > a3 )
    goto LABEL_75;
  v77 = a2 + 4;
  v15 = v13 + 6;
  if ( a4 )
  {
    if ( *a5 >= v15 )
    {
      v16 = *((unsigned __int16 *)v7 + 460);
      if ( (_WORD)v16 )
      {
        v17 = 0;
        while ( *(unsigned __int16 *)(*((_QWORD *)v7 + 114) + 2i64 * v17) != v12 )
        {
          if ( ++v17 >= v16 )
            goto LABEL_79;
        }
      }
      CSslContext::SetEccCurveInfo(v7, v12);
      if ( !*(_DWORD *)(*((_QWORD *)v7 + 10) + 196i64) )
        goto LABEL_18;
      v72 = 0i64;
      if ( (unsigned int)CCipherMill::GetCurveInfo(v18, v12, &v72) )
      {
        v56 = 80;
        EccBcryptKeyBlobFromKeyExchangeBlob = -2146893052;
        v58 = 800;
        goto LABEL_83;
      }
      if ( IsEcdheAlgorithmBlacklisted(
             *(struct _TLS_PARAMETERS **)(*((_QWORD *)v7 + 10) + 200i64),
             *(_DWORD *)(*((_QWORD *)v7 + 10) + 196i64),
             v72,
             0i64,
             1u) )
      {
LABEL_79:
        v56 = 40;
        EccBcryptKeyBlobFromKeyExchangeBlob = -2146893048;
        v58 = 801;
      }
      else
      {
LABEL_18:
        v19 = &a2[v14];
        v20 = (_DWORD)v19 - (_DWORD)a2;
        v9 = (*((_DWORD *)v7 + 16) & 0x80800) == 0;
        LODWORD(v72) = (_DWORD)v19 - (_DWORD)a2;
        if ( v9 )
        {
LABEL_23:
          if ( v19 + 2 <= &a2[v10] )
          {
            v25 = (*v19 << 8) | v19[1];
            if ( &v19[v25 + 2] <= &a2[v10] )
            {
              v26 = v11 - 1;
              if ( v26 )
              {
                if ( v26 == 2 )
                {
                  v53 = VerifyEcdsaParams(v7, a2, v20, Size_4, v19 + 2, v25);
                  EccBcryptKeyBlobFromKeyExchangeBlob = v53;
                  if ( v53 )
                  {
                    v56 = 51;
                    v57 = v53;
                    v58 = 803;
                    goto LABEL_85;
                  }
                }
              }
              else
              {
                v27 = VerifyRsaParams((UCHAR *)v7, a2, v20, v75, Size_4, v70, v19 + 2, v25);
                EccBcryptKeyBlobFromKeyExchangeBlob = v27;
                if ( v27 )
                {
                  v56 = 51;
                  v57 = v27;
                  v58 = 802;
                  goto LABEL_85;
                }
              }
              if ( (*((_BYTE *)v7 + 32) & 1) != 0 && (v29 = *((_QWORD *)v7 + 1)) != 0 )
              {
                v30 = *(_DWORD *)(v29 + 28);
              }
              else
              {
                v29 = *((_QWORD *)v7 + 1);
                v30 = 0;
                if ( !v29 )
                {
                  v31 = 0i64;
                  goto LABEL_31;
                }
              }
              v31 = *(_QWORD *)v29;
LABEL_31:
              EphemKey = EccGetEphemKey(v31, v30, *((unsigned __int16 *)v7 + 17), v12, &v68, &v71);
              EccBcryptKeyBlobFromKeyExchangeBlob = EphemKey;
              if ( !EphemKey )
              {
                *(_DWORD *)(*((_QWORD *)v7 + 165) + 8i64) = v71;
                v33 = (__int64 *)*((_QWORD *)v7 + 1);
                if ( v33 )
                  v34 = *v33;
                else
                  v34 = 0i64;
                EphemBlobFromKey = GetEphemBlobFromKey(v34, v68, L"ECCPUBLICBLOB", &Size, (unsigned __int8 **)&v76);
                v36 = v76;
                EccBcryptKeyBlobFromKeyExchangeBlob = EphemBlobFromKey;
                if ( EphemBlobFromKey )
                {
                  v59 = EphemBlobFromKey;
                  v60 = 806;
                  goto LABEL_91;
                }
                v37 = Size;
                p_Size_4 = 0i64;
                if ( Size )
                {
                  if ( Size <= (unsigned __int64)g_ulMaxStackAllocSize )
                  {
                    v38 = Size + g_ulAdditionalProbeSize + 8;
                    if ( v38 >= Size )
                    {
                      if ( !(unsigned int)VerifyStackAvailable(v38) )
                      {
LABEL_92:
                        v37 = Size;
                        goto LABEL_93;
                      }
                      v37 = Size;
                      v39 = Size + 8 + 15i64;
                      if ( v39 <= Size + 8 )
                        v39 = 0xFFFFFFFFFFFFFF0i64;
                      v40 = alloca(v39 & 0xFFFFFFFFFFFFFFF0ui64);
                      p_Size_4 = (struct _BCRYPT_ECCKEY_BLOB *)&v64;
                      if ( &v63 != (__int64 *)-64i64 )
                      {
                        v64 = 1801679955;
                        p_Size_4 = (struct _BCRYPT_ECCKEY_BLOB *)&Size_4;
                        if ( &Size_4 )
                        {
                          v37 = Size;
LABEL_44:
                          memset_0(p_Size_4, 0, v37);
                          v41 = v74[0];
                          v42 = v77;
                          *p_Size_4 = *v36;
                          EccBcryptKeyBlobFromKeyExchangeBlob = GetEccBcryptKeyBlobFromKeyExchangeBlob(
                                                                  *((_DWORD *)v7 + 5),
                                                                  v42,
                                                                  v41,
                                                                  p_Size_4,
                                                                  Size);
                          if ( EccBcryptKeyBlobFromKeyExchangeBlob )
                          {
LABEL_54:
                            if ( v36 )
                              SPExternalFree(v36);
                            if ( p_Size_4 && p_Size_4[-1].dwMagic == 1885431112 )
                              ((void (*)(void))g_pfnFree)();
                            goto LABEL_59;
                          }
                          v43 = (__int64 *)*((_QWORD *)v7 + 1);
                          v44 = v43[106];
                          if ( v44 && *(_BYTE *)(v44 + 24) )
                          {
                            dwMagic = p_Size_4->dwMagic;
                            p_Size_4->dwMagic = v12;
                            v46 = (__int64 *)*((_QWORD *)v7 + 1);
                            if ( v46 )
                              v47 = *v46;
                            else
                              v47 = 0i64;
                            if ( !(unsigned int)SslImportKey(v47, &v67, L"SSLECCPUBLICBLOB", p_Size_4, Size, 0) )
                              goto LABEL_50;
                            p_Size_4->dwMagic = dwMagic;
                            v43 = (__int64 *)*((_QWORD *)v7 + 1);
                          }
                          if ( v43 )
                            v62 = *v43;
                          else
                            v62 = 0i64;
                          EccBcryptKeyBlobFromKeyExchangeBlob = SslImportKey(
                                                                  v62,
                                                                  &v67,
                                                                  L"ECCPUBLICBLOB",
                                                                  p_Size_4,
                                                                  Size,
                                                                  0);
                          if ( !EccBcryptKeyBlobFromKeyExchangeBlob )
                          {
LABEL_50:
                            v48 = v78;
                            v49 = *((_DWORD *)v7 + 5);
                            LOBYTE(v64) = *(_BYTE *)a5 - 1;
                            if ( (unsigned int)GetEccKeyExchangeBlobFromBcryptKeyBlob(
                                                 v49,
                                                 v36,
                                                 v78 + 1,
                                                 (unsigned __int8 *)&v64) )
                            {
                              EccBcryptKeyBlobFromKeyExchangeBlob = -2146893048;
                            }
                            else
                            {
                              v50 = (unsigned __int8)v64;
                              *v48 = v64;
                              *a5 = v50 + 1;
                              if ( (*((_DWORD *)v7 + 34) & 0x8000000) != 0 )
                              {
                                (*(void (__fastcall **)(CSsl3TlsClientContext *, unsigned __int64))(*(_QWORD *)v7
                                                                                                  + 152i64))(
                                  v7,
                                  v67);
                                EccDhPskSessionKeysHelper = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, unsigned __int64))(*(_QWORD *)v7 + 168i64))(
                                                              v7,
                                                              v68);
                                v67 = 0i64;
                                v68 = 0i64;
                              }
                              else
                              {
                                EccDhPskSessionKeysHelper = MakeEccDhPskSessionKeysHelper(v7, v68, v67, 0);
                              }
                              EccBcryptKeyBlobFromKeyExchangeBlob = EccDhPskSessionKeysHelper;
                            }
                            goto LABEL_54;
                          }
                          v59 = EccBcryptKeyBlobFromKeyExchangeBlob;
                          v60 = 804;
LABEL_91:
                          CSslContext::SetErrorAndFatalAlert((__int64)v7, v60, v59, 0x33u);
                          goto LABEL_54;
                        }
                        goto LABEL_92;
                      }
                    }
                  }
                }
LABEL_93:
                if ( v37 + 8 >= v37 )
                {
                  v61 = (struct _BCRYPT_ECCKEY_BLOB *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)(v37 + 8);
                  p_Size_4 = v61;
                  if ( !v61 )
                    goto LABEL_97;
                  v61->dwMagic = 1885431112;
                  p_Size_4 = v61 + 1;
                  v37 = Size;
                }
                if ( p_Size_4 )
                  goto LABEL_44;
LABEL_97:
                EccBcryptKeyBlobFromKeyExchangeBlob = 14;
                goto LABEL_54;
              }
              v56 = 51;
              v57 = EphemKey;
              v58 = 805;
LABEL_85:
              CSslContext::SetErrorAndFatalAlert((__int64)v7, v58, v57, v56);
LABEL_59:
              if ( v68 )
                SslFreeObject(v68, 0i64);
              if ( v67 )
                SslFreeObject(v67, 0i64);
              return EccBcryptKeyBlobFromKeyExchangeBlob;
            }
          }
LABEL_75:
          v54 = 50;
          v55 = 800;
LABEL_76:
          this = v7;
          goto LABEL_77;
        }
        if ( v19 + 2 > &a2[v10] )
        {
          v56 = 50;
        }
        else
        {
          v21 = *v19;
          v22 = v19[1];
          v19 += 2;
          v23 = v21 | (v22 << 8);
          if ( !CTlsSignatureSuiteList::IsSupportedCodePoint((CSsl3TlsClientContext *)((char *)v7 + 474), v23) )
          {
            v54 = 47;
            v55 = 821;
            goto LABEL_76;
          }
          v69 = TlsSignatureAlgorithm_Anonymous;
          GetSignatureSuiteInfoByCodePoint(v23, &v69, &Size_4, v24, (const unsigned __int16 **)&v75, 0i64, &v70);
          if ( v69 == v11 )
          {
            v20 = (unsigned int)v72;
            v12 = v73;
            goto LABEL_23;
          }
          v56 = 40;
        }
        EccBcryptKeyBlobFromKeyExchangeBlob = -2146893048;
        v58 = 821;
      }
LABEL_83:
      v57 = EccBcryptKeyBlobFromKeyExchangeBlob;
      goto LABEL_85;
    }
    return 2148074273i64;
  }
  else
  {
    *a5 = v15;
    return 0i64;
  }
}
// 180004AAE: conditional instruction was optimized away because eax.4 is in (1..FFFF)
// 180004AF5: variable 'v18' is possibly undefined
// 180004BB1: variable 'v24' is possibly undefined
// 180082258: using guessed type wchar_t aSsleccpublicbl[17];
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);

