//----- (00000001800745B4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::DhGenerateClientExchangeValue(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        int a3,
        unsigned __int8 *a4,
        unsigned int *a5)
{
  char *v7; // rsi
  __int64 v8; // rax
  enum _eTlsHashAlgorithm v9; // r10d
  bool v10; // zf
  int v11; // r14d
  unsigned __int8 *v12; // r15
  int v13; // r12d
  unsigned int v14; // edx
  unsigned __int8 *v15; // r8
  unsigned __int8 *v16; // r9
  unsigned int v17; // r8d
  unsigned __int8 *v18; // r13
  unsigned int v20; // r8d
  int v21; // edx
  __int16 v22; // dx
  __int16 v23; // ax
  unsigned int *v24; // r9
  unsigned __int8 v25; // r9
  unsigned int cbEncoded; // edx
  int v27; // r14d
  unsigned int EphemKey; // edi
  __int64 v29; // rax
  unsigned int v30; // edx
  __int64 v31; // rcx
  unsigned __int8 v32; // r9
  __int64 v33; // r14
  __int64 v34; // rcx
  unsigned int v35; // edi
  unsigned int v36; // edx
  __int64 *v37; // rax
  __int64 v38; // rcx
  int EphemBlobFromKey; // eax
  unsigned int *v40; // r15
  int v41; // edx
  unsigned int v42; // edx
  unsigned __int64 v43; // rcx
  unsigned __int64 v44; // rax
  void *v45; // rsp
  size_t v46; // r13
  unsigned int v47; // ecx
  char *v48; // rax
  __int64 v49; // rdi
  unsigned int v50; // r12d
  _QWORD *v51; // rcx
  size_t v52; // rdx
  unsigned int v53; // eax
  unsigned __int8 *v54; // rcx
  unsigned int EccDhPskSessionKeysHelper; // eax
  __int64 v56; // [rsp+0h] [rbp-50h] BYREF
  unsigned int v57; // [rsp+50h] [rbp+0h] BYREF
  __int16 v58; // [rsp+54h] [rbp+4h]
  enum _eTlsSignatureAlgorithm v59; // [rsp+58h] [rbp+8h] BYREF
  enum _eTlsHashAlgorithm v60; // [rsp+5Ch] [rbp+Ch] BYREF
  unsigned int v61; // [rsp+60h] [rbp+10h]
  ULONG v62; // [rsp+64h] [rbp+14h] BYREF
  unsigned int v63; // [rsp+68h] [rbp+18h] BYREF
  unsigned __int64 v64; // [rsp+70h] [rbp+20h] BYREF
  unsigned __int64 v65; // [rsp+78h] [rbp+28h] BYREF
  unsigned int v66; // [rsp+80h] [rbp+30h]
  _DWORD Size[3]; // [rsp+84h] [rbp+34h] BYREF
  void *Src; // [rsp+90h] [rbp+40h] BYREF
  unsigned __int8 *v69; // [rsp+98h] [rbp+48h]
  unsigned __int8 *v70; // [rsp+A0h] [rbp+50h]
  unsigned __int8 *v71; // [rsp+A8h] [rbp+58h]
  void *v72; // [rsp+B0h] [rbp+60h]

  v69 = a4;
  v64 = 0i64;
  v63 = 0;
  v7 = 0i64;
  v8 = *((_QWORD *)this + 1);
  v9 = TlsHashAlgorithm_None;
  v65 = 0i64;
  Src = 0i64;
  *(_QWORD *)&Size[1] = 0i64;
  v10 = *(_DWORD *)(v8 + 52) == 2;
  v60 = TlsHashAlgorithm_None;
  v62 = 0;
  if ( v10 )
  {
    v11 = 1;
  }
  else
  {
    if ( *(_DWORD *)(v8 + 52) != 3 )
      return 2148074248i64;
    v11 = 2;
  }
  if ( a2 )
  {
    v12 = &a2[a3];
    v71 = a2 + 2;
    if ( a2 + 2 > v12 )
      goto LABEL_91;
    v13 = a2[1] | (*a2 << 8);
    v14 = v13 + 2;
    v15 = &a2[v13 + 2];
    v70 = v15 + 2;
    if ( v15 + 2 > v12 )
      goto LABEL_91;
    v66 = v15[1] | (*v15 << 8);
    v16 = &v15[v66 + 2];
    if ( v16 + 2 > v12 )
      goto LABEL_91;
    v17 = v16[1] | (*v16 << 8);
    Size[0] = v17;
    v72 = v16 + 2;
    v18 = &v16[v17 + 2];
    if ( v18 + 2 > v12 || v17 + 2 < v17 )
      goto LABEL_91;
    if ( !v69 )
    {
      *a5 = v14;
      return 0i64;
    }
    if ( *a5 < v14 )
      return 122i64;
    v20 = (_DWORD)v18 - (_DWORD)a2;
    v10 = (*((_DWORD *)this + 16) & 0x80800) == 0;
    v61 = (_DWORD)v18 - (_DWORD)a2;
    if ( !v10 )
    {
      if ( v18 + 4 > v12 )
      {
        v21 = 822;
LABEL_92:
        v25 = 50;
        goto LABEL_93;
      }
      v22 = v18[1];
      v23 = *v18;
      v18 += 2;
      v58 = v23 | (v22 << 8);
      if ( !CTlsSignatureSuiteList::IsSupportedCodePoint((CSsl3TlsClientContext *)((char *)this + 474), v58) )
      {
        v25 = 47;
LABEL_20:
        v21 = 822;
LABEL_93:
        EphemKey = -2146893048;
        goto LABEL_94;
      }
      v59 = TlsSignatureAlgorithm_Anonymous;
      GetSignatureSuiteInfoByCodePoint(v58, &v59, &v60, v24, (const unsigned __int16 **)&Size[1], 0i64, &v62);
      if ( v59 != v11 || (v9 = v60, v59 == TlsSignatureAlgorithm_Dsa) && v60 != TlsHashAlgorithm_Sha1 )
      {
        v25 = 40;
        goto LABEL_20;
      }
      v20 = v61;
    }
    cbEncoded = v18[1] | (*v18 << 8);
    if ( &v18[cbEncoded + 2] != v12 )
    {
LABEL_91:
      v21 = 807;
      goto LABEL_92;
    }
    v27 = v11 - 1;
    if ( !v27 )
    {
      EphemKey = VerifyRsaParams(
                   (UCHAR *)this,
                   a2,
                   v20,
                   *(const unsigned __int16 **)&Size[1],
                   v9,
                   v62,
                   v18 + 2,
                   cbEncoded);
      if ( EphemKey )
      {
        v25 = 51;
        v21 = 802;
        goto LABEL_94;
      }
LABEL_33:
      if ( (*((_BYTE *)this + 32) & 1) != 0 && (v29 = *((_QWORD *)this + 1)) != 0 )
      {
        v30 = *(_DWORD *)(v29 + 28);
      }
      else
      {
        v29 = *((_QWORD *)this + 1);
        v30 = 0;
        if ( !v29 )
        {
          v31 = 0i64;
LABEL_39:
          EphemKey = DhGetEphemKey(v31, v30, *((unsigned __int16 *)this + 17), v13, v71, v66, v70, &v65, &v63);
          if ( EphemKey )
          {
            v32 = 51;
            if ( EphemKey == 87 )
              v32 = 40;
            CSslContext::SetErrorAndFatalAlert((__int64)this, 808, EphemKey, v32);
            goto LABEL_43;
          }
          v34 = *((_QWORD *)this + 10);
          v35 = v63;
          v36 = *(_DWORD *)(v34 + 196);
          if ( v36 && IsDheAlgorithmBlacklisted(*(struct _TLS_PARAMETERS **)(v34 + 200), v36, v63, 0i64, 1u) )
          {
            CSslContext::SetErrorAndFatalAlert((__int64)this, 808, 0, 0x28u);
            EphemKey = 87;
LABEL_43:
            v33 = v65;
LABEL_87:
            if ( v33 )
              SslFreeObject(v33, 0i64);
            if ( v64 )
              SslFreeObject(v64, 0i64);
            return EphemKey;
          }
          *(_DWORD *)(*((_QWORD *)this + 165) + 8i64) = v35;
          v37 = (__int64 *)*((_QWORD *)this + 1);
          if ( v37 )
            v38 = *v37;
          else
            v38 = 0i64;
          v33 = v65;
          EphemBlobFromKey = GetEphemBlobFromKey(v38, v65, L"DHPUBLICBLOB", &v57, (unsigned __int8 **)&Src);
          v40 = (unsigned int *)Src;
          EphemKey = EphemBlobFromKey;
          if ( EphemBlobFromKey )
          {
            v41 = 809;
            goto LABEL_52;
          }
          v42 = v57;
          if ( v57 )
          {
            if ( v57 <= (unsigned __int64)g_ulMaxStackAllocSize )
            {
              v43 = v57 + g_ulAdditionalProbeSize + 8;
              if ( v43 >= v57 )
              {
                if ( !(unsigned int)VerifyStackAvailable(v43) )
                {
LABEL_64:
                  v42 = v57;
                  goto LABEL_65;
                }
                v42 = v57;
                v44 = v57 + 8 + 15i64;
                if ( v44 <= v57 + 8 )
                  v44 = 0xFFFFFFFFFFFFFF0i64;
                v45 = alloca(v44 & 0xFFFFFFFFFFFFFFF0ui64);
                v7 = (char *)&v57;
                if ( &v56 != (__int64 *)-80i64 )
                {
                  v57 = 1801679955;
                  v7 = (char *)&v59;
                  if ( &v59 )
                  {
                    v42 = v57;
LABEL_62:
                    v46 = Size[0];
                    v47 = 2 * v13 + 8;
                    if ( v47 + Size[0] > v42 )
                    {
                      EphemKey = 1359;
                      goto LABEL_82;
                    }
                    v49 = v47;
                    memcpy_0(v7, v40, v47);
                    v50 = v13 - v46;
                    if ( v50 )
                      memset_0(&v7[v49], 0, v50);
                    memcpy_0(&v7[v49 + v50], v72, v46);
                    v51 = (_QWORD *)*((_QWORD *)this + 1);
                    if ( v51 )
                      v51 = (_QWORD *)*v51;
                    EphemBlobFromKey = SslImportKey(v51, &v64, L"DHPUBLICBLOB", v7, v57, 0);
                    EphemKey = EphemBlobFromKey;
                    if ( !EphemBlobFromKey )
                    {
                      v52 = v40[1];
                      v53 = *a5;
                      *a5 = v52 + 2;
                      if ( v53 >= (int)v52 + 2 )
                      {
                        v54 = v69;
                        v69[1] = v52;
                        *v54 = BYTE1(v52);
                        memcpy_0(v54 + 2, (char *)v40 + 2 * v52 + 8, v52);
                        if ( (*((_DWORD *)this + 34) & 0x8000000) != 0 )
                        {
                          (*(void (__fastcall **)(CSsl3TlsClientContext *, unsigned __int64))(*(_QWORD *)this + 152i64))(
                            this,
                            v64);
                          EccDhPskSessionKeysHelper = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, __int64))(*(_QWORD *)this + 168i64))(
                                                        this,
                                                        v33);
                          v64 = 0i64;
                          v33 = 0i64;
                        }
                        else
                        {
                          EccDhPskSessionKeysHelper = MakeEccDhPskSessionKeysHelper(this, v33, v64, 0);
                        }
                        EphemKey = EccDhPskSessionKeysHelper;
                      }
                      else
                      {
                        EphemKey = -2146893023;
                      }
                      goto LABEL_82;
                    }
                    v41 = 810;
LABEL_52:
                    CSslContext::SetErrorAndFatalAlert((__int64)this, v41, EphemBlobFromKey, 0x33u);
LABEL_82:
                    if ( v40 )
                      SPExternalFree(v40);
                    if ( v7 && *((_DWORD *)v7 - 2) == 1885431112 )
                      ((void (*)(void))g_pfnFree)();
                    goto LABEL_87;
                  }
                  goto LABEL_64;
                }
              }
            }
          }
LABEL_65:
          if ( v42 + 8 >= v42 )
          {
            v48 = (char *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)(v42 + 8);
            v7 = v48;
            if ( !v48 )
              goto LABEL_69;
            *(_DWORD *)v48 = 1885431112;
            v7 = v48 + 8;
            v42 = v57;
          }
          if ( v7 )
            goto LABEL_62;
LABEL_69:
          EphemKey = 14;
          goto LABEL_82;
        }
      }
      v31 = *(_QWORD *)v29;
      goto LABEL_39;
    }
    if ( v27 == 1 )
    {
      EphemKey = VerifyDssParams((UCHAR *)this, a2, v20, v18 + 2, cbEncoded);
      if ( EphemKey )
      {
        v25 = 51;
        v21 = 823;
LABEL_94:
        CSslContext::SetErrorAndFatalAlert((__int64)this, v21, EphemKey, v25);
        return EphemKey;
      }
      goto LABEL_33;
    }
  }
  return 2148074248i64;
}
// 180074795: variable 'v24' is possibly undefined
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);

