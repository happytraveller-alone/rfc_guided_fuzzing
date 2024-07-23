//----- (000000018001B930) ----------------------------------------------------
__int64 __fastcall CSslCredential::IsServerCredApplicable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        struct _TLS_PARAMETERS *a6,
        unsigned int a7,
        PCUNICODE_STRING String2,
        char a9)
{
  int v9; // esi
  int v12; // ebx
  _DWORD *v13; // rax
  int v14; // r14d
  unsigned int v15; // r12d
  CCipherMill *v16; // r10
  __int64 v17; // r12
  const wchar_t *v18; // rbx
  int v19; // eax
  unsigned int v20; // r9d
  struct _TLS_PARAMETERS *v21; // r15
  const UNICODE_STRING *v22; // r13
  struct _TLS_PARAMETERS *v23; // rbx
  struct _TLS_PARAMETERS *v24; // r14
  int v25; // eax
  unsigned int v26; // r11d
  int v27; // eax
  _DWORD *v28; // rdx
  unsigned __int8 i; // r9
  int v30; // ebx
  int v31; // ecx
  int v32; // edx
  unsigned __int16 v33; // r8
  unsigned __int16 v34; // cx
  unsigned __int16 v35; // r8
  unsigned __int16 v36; // cx
  int v37; // r8d
  __int64 v38; // rdx
  int v39; // ebx
  struct _CERT_INFO *v40; // rdx
  unsigned int v42; // ebp
  unsigned __int64 v43; // rbp
  unsigned int v44; // eax
  unsigned int v45; // eax
  int v46; // r9d
  bool v47; // zf
  int v48; // eax
  int v49; // eax
  __int64 v50; // [rsp+20h] [rbp-68h]
  PCUNICODE_STRING v51; // [rsp+28h] [rbp-60h]
  unsigned int v52; // [rsp+40h] [rbp-48h]
  int v53; // [rsp+48h] [rbp-40h]
  unsigned int pbKeyUsage; // [rsp+90h] [rbp+8h] BYREF
  int v55; // [rsp+A0h] [rbp+18h]
  int v56; // [rsp+A8h] [rbp+20h]

  v56 = a4;
  v9 = 0;
  v12 = 0;
  if ( a3 )
    v12 = *(_DWORD *)(a3 + 772);
  v13 = *(_DWORD **)(a1 + 32);
  if ( !v13 )
    return 0i64;
  if ( *v13 != 1 )
    return 0i64;
  if ( !a2 )
    return 0i64;
  v14 = *(_DWORD *)(a2 + 32);
  v15 = *(_DWORD *)(a2 + 36);
  v55 = v14;
  v52 = v15;
  if ( !*(_QWORD *)(a1 + 432) && !*(_DWORD *)(a1 + 132) )
    return 0i64;
  if ( v14 == 41984 && *(_DWORD *)(a1 + 124) == 1 )
  {
    v46 = *(_DWORD *)(a1 + 128);
    if ( v46 != 1 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x2Au,
          (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
          v46);
      return 0i64;
    }
  }
  v16 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x2Bu,
      (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids,
      v15,
      *(_DWORD *)(a1 + 132));
    v16 = WPP_GLOBAL_Control;
  }
  if ( v15 == 9216 )
  {
    if ( ((*(_DWORD *)(a1 + 132) - 9216) & 0xFFFF7FFF) != 0 )
      return 0i64;
    goto LABEL_13;
  }
  if ( v15 == 8704 )
  {
    v47 = *(_DWORD *)(a1 + 132) == 8704;
LABEL_113:
    if ( !v47 )
      return 0i64;
    goto LABEL_13;
  }
  if ( v15 != 8707 )
  {
    if ( v15 != 41984 )
    {
      if ( !v15 || *(_DWORD *)(a1 + 132) == v15 )
        goto LABEL_13;
      if ( v16 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v16 + 28) & 2) != 0 )
        WPP_SF_D(*((_QWORD *)v16 + 2), 45i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v15);
      return 0i64;
    }
    v47 = *(_DWORD *)(a1 + 132) == 41984;
    goto LABEL_113;
  }
  if ( *(_DWORD *)(a1 + 132) != 8707 )
    return 0i64;
  if ( v12 != *(_DWORD *)(a1 + 140) )
  {
    if ( v16 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v16 + 28) & 2) != 0 )
    {
      LODWORD(v50) = *(_DWORD *)(a1 + 140);
      WPP_SF_DD(*((_QWORD *)v16 + 2), 0x2Cu, (__int64)&WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v12, v50);
    }
    return 0i64;
  }
LABEL_13:
  v17 = a7;
  v53 = 3;
  if ( !a7 )
    goto LABEL_33;
  v18 = (const wchar_t *)(a1 + 272);
  v19 = *(_DWORD *)(a1 + 132);
  v20 = v19 == 8707 ? *(_DWORD *)(a1 + 136) : *(_DWORD *)(a1 + 428);
  v21 = a6;
  pbKeyUsage = v20;
  if ( !a6 || !v19 || a1 == -144 || a1 == -272 )
    goto LABEL_33;
  if ( v19 == 8707 )
  {
    if ( a3
      && IsEcdsaAlgorithmBlacklisted(a6, a7, (const unsigned __int16 *)a3, *(_DWORD *)(a3 + 772), v20, String2, a9) )
    {
      return 0i64;
    }
  }
  else if ( v19 == 8704 )
  {
    if ( IsCngAlgorithmBlacklisted((unsigned __int64)a6, a7, 1, L"DSA", 0i64, v20, String2, a9) )
      return 0i64;
  }
  else
  {
    v22 = String2;
    if ( v19 == 41984 )
    {
      if ( v14 == 41984 && IsRsaAlgorithmBlacklisted((unsigned __int64)a6, a7, 0, v20, String2, a9) )
        return 0i64;
      goto LABEL_24;
    }
    if ( v19 == 9216 )
    {
LABEL_24:
      v23 = v21;
      v24 = (struct _TLS_PARAMETERS *)((char *)v21 + 40 * v17);
      if ( v21 < v24 )
      {
        while ( 1 )
        {
          if ( *((_DWORD *)v23 + 5) )
          {
            if ( !*(_DWORD *)v23 )
              goto LABEL_75;
            if ( v22 )
              break;
          }
LABEL_28:
          v23 = (struct _TLS_PARAMETERS *)((char *)v23 + 40);
          if ( v23 >= v24 )
            goto LABEL_29;
        }
        v42 = 0;
        while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*((_QWORD *)v23 + 1) + 16i64 * v42), v22, 1u) )
        {
          if ( ++v42 >= *(_DWORD *)v23 )
            goto LABEL_28;
        }
LABEL_75:
        if ( a9 && (*((_BYTE *)v23 + 32) & 1) != 0 )
          goto LABEL_28;
        v43 = *((_QWORD *)v23 + 3);
        if ( v43 >= v43 + 48i64 * *((unsigned int *)v23 + 5) )
          goto LABEL_28;
        while ( 1 )
        {
          if ( *(_DWORD *)v43 != 1 || *(_WORD *)(v43 + 8) != 6 || wcsncmp(*(const wchar_t **)(v43 + 16), L"RSA", 3ui64) )
            goto LABEL_79;
          if ( !*(_DWORD *)(v43 + 24) && !*(_DWORD *)(v43 + 40) && !*(_DWORD *)(v43 + 44) )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              LODWORD(v50) = 1;
              WPP_SF_Sd(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xCu,
                (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
                L"RSA",
                v50);
            }
            return 0i64;
          }
          if ( !pbKeyUsage )
            goto LABEL_79;
          v44 = *(_DWORD *)(v43 + 40);
          if ( v44 )
          {
            if ( v44 > pbKeyUsage )
              goto LABEL_134;
            v45 = *(_DWORD *)(v43 + 44);
            if ( !v45 )
              goto LABEL_79;
          }
          else
          {
            if ( !*(_DWORD *)(v43 + 44) )
              goto LABEL_79;
            v45 = *(_DWORD *)(v43 + 44);
          }
          if ( v45 < pbKeyUsage )
          {
LABEL_134:
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              LODWORD(v51) = 1;
              LODWORD(v50) = pbKeyUsage;
              WPP_SF_Sdd(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xEu,
                (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
                L"RSA",
                v50,
                v51);
            }
            return 0i64;
          }
LABEL_79:
          v43 += 48i64;
          if ( v43 >= *((_QWORD *)v23 + 3) + 48 * (unsigned __int64)*((unsigned int *)v23 + 5) )
            goto LABEL_28;
        }
      }
LABEL_29:
      v14 = v55;
      v18 = (const wchar_t *)(a1 + 272);
    }
  }
  if ( IsCngAlgorithmBlacklisted((unsigned __int64)v21, v17, 4, (const wchar_t *)(a1 + 144), 0i64, 0, 0i64, 1)
    || IsCngAlgorithmBlacklisted((unsigned __int64)v21, v17, 4, v18, 0i64, 0, 0i64, 1) )
  {
    return 0i64;
  }
  v16 = WPP_GLOBAL_Control;
LABEL_33:
  if ( !a5 )
    goto LABEL_57;
  v25 = *(_DWORD *)(a1 + 132);
  v26 = *(_DWORD *)(a1 + 428);
  if ( v25 != 41984 )
  {
    v48 = v25 - 8704;
    if ( !v48 )
    {
      v27 = 2;
      goto LABEL_36;
    }
    v49 = v48 - 3;
    if ( !v49 )
    {
      v27 = 3;
      goto LABEL_37;
    }
    if ( v49 != 509 )
      return 0i64;
  }
  v27 = 1;
LABEL_36:
  v53 = v27;
LABEL_37:
  v28 = &unk_18007C3A8;
  for ( i = 0; ; ++i )
  {
    v30 = v28[1];
    if ( v30 == v27
      && (v56 & *v28) != 0
      && (!v26 || v27 != 1 || v28[9] != 8 || v26 >> 3 >= 2 * (unsigned int)*((unsigned __int8 *)v28 + 32) + 2)
      && ((v56 & 0x3000) == 0 || v30 != 3 || v28[10] == *(_DWORD *)(a1 + 140))
      && i < 0xCu )
    {
      v31 = *(unsigned __int16 *)(a5 + 34);
      if ( _bittest(&v31, i) )
        break;
    }
    v28 += 18;
    if ( v28 - 6 >= (_DWORD *)&CSsl3TlsServerContext::`vftable' )
      return 0i64;
    v27 = v53;
  }
  if ( a1 == -512 )
    return 2i64;
  if ( !*(_WORD *)(a1 + 512) )
    return 2i64;
  v32 = *(unsigned __int16 *)(a1 + 546);
  if ( !(_WORD)v32 )
    return 2i64;
  v33 = (CTlsSignatureSuiteList::RsaSha256Flags & (unsigned __int16)v31) != 0
      ? CTlsSignatureSuiteList::RsaSha256Flags
      : 0;
  v34 = v33 | v31;
  v35 = (CTlsSignatureSuiteList::RsaSha384Flags & v34) != 0 ? CTlsSignatureSuiteList::RsaSha384Flags : 0;
  v36 = v35 | v34;
  v37 = (CTlsSignatureSuiteList::RsaSha512Flags & v36) != 0 ? CTlsSignatureSuiteList::RsaSha512Flags : 0;
  if ( (~(v37 | v36) & v32) != 0 )
    return 2i64;
LABEL_57:
  v38 = *(_QWORD *)(a1 + 32);
  if ( !v38 )
    return 2i64;
  if ( v52 != 9216 )
    goto LABEL_68;
  if ( v14 != 44550 )
  {
    if ( v14 == 41984 )
    {
      v39 = 32;
      goto LABEL_61;
    }
    if ( v14 != 43522 )
      goto LABEL_68;
  }
  v39 = 128;
LABEL_61:
  v40 = *(struct _CERT_INFO **)(v38 + 24);
  pbKeyUsage = 0;
  if ( CertGetIntendedKeyUsage(0x10001u, v40, (BYTE *)&pbKeyUsage, 4u) )
  {
    if ( (pbKeyUsage & v39) != 0 )
      v9 = 1;
    v16 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    {
      LODWORD(v50) = v39;
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x14u,
        (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
        pbKeyUsage,
        v50);
      v16 = WPP_GLOBAL_Control;
    }
    if ( v9 )
      goto LABEL_68;
    return 2i64;
  }
  v16 = WPP_GLOBAL_Control;
LABEL_68:
  if ( v16 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v16 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v16 + 2), 46i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v52);
  return 1i64;
}
// 1800306CF: variable 'v50' is possibly undefined
// 1800305E3: variable 'v51' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
// 180092800: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha512Flags;
// 180092804: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha384Flags;
// 180092808: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha256Flags;

