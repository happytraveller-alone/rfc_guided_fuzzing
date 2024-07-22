//----- (000000018001E850) ----------------------------------------------------
__int64 __fastcall CCipherMill::FindAcceptableKeyXCurve(
        CCipherMill *this,
        struct CSsl3TlsServerContext *a2,
        struct CCipherSuiteInfo *a3,
        char a4,
        char a5,
        PCUNICODE_STRING String2,
        unsigned int *a7,
        unsigned __int8 *a8)
{
  struct CSsl3TlsServerContext *v9; // r14
  unsigned int v10; // edi
  bool v11; // zf
  unsigned int v12; // esi
  unsigned int v13; // r13d
  char v14; // al
  __int64 v15; // rdx
  unsigned __int64 v16; // rbp
  __int64 v17; // rax
  __int64 v18; // r15
  unsigned __int64 v19; // r14
  unsigned int v20; // r12d
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rbx
  const UNICODE_STRING *v23; // rax
  const wchar_t *v24; // r9
  unsigned int v25; // ebx
  unsigned int v26; // edx
  __int64 v27; // r8
  char v28; // r12
  unsigned int v29; // ecx
  bool v30; // cc
  CCipherMill *v31; // r10
  int v32; // eax
  unsigned int v33; // edi
  unsigned __int64 v34; // rdi
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // ecx
  __int64 v39; // rax
  unsigned __int16 v40; // dx
  __int64 v41; // [rsp+20h] [rbp-88h]
  __int64 v42; // [rsp+28h] [rbp-80h]
  char v43; // [rsp+40h] [rbp-68h]
  unsigned int v44; // [rsp+44h] [rbp-64h]
  unsigned int v45; // [rsp+48h] [rbp-60h]
  __int64 v46; // [rsp+50h] [rbp-58h] BYREF
  unsigned int v47; // [rsp+58h] [rbp-50h]
  __int64 v48; // [rsp+60h] [rbp-48h]
  char v49; // [rsp+B0h] [rbp+8h]

  v9 = a2;
  if ( !a2 || !a3 || !a7 || !a8 )
    return 2148074244i64;
  v10 = *((_DWORD *)a3 + 5);
  v11 = (*((_DWORD *)a2 + 16) & 0x1000) == 0;
  v12 = 0;
  v13 = 0;
  *a8 = 0;
  *a7 = 0;
  v44 = 0;
  LODWORD(v46) = 0;
  v45 = 0;
  v47 = v10;
  v14 = !v11;
  v43 = v14;
  if ( !a4 || v14 )
  {
    v49 = 0;
  }
  else
  {
    v39 = *(_QWORD *)a2;
    v49 = 1;
    v46 = 0i64;
    (*(void (__fastcall **)(struct CSsl3TlsServerContext *, __int64 *))(v39 + 232))(a2, &v46);
    if ( !v46 )
      return (unsigned int)-2146893052;
    LODWORD(v46) = *(_DWORD *)(v46 + 184);
  }
  v15 = *((_QWORD *)a3 + 106);
  v48 = v15;
  if ( !v15 )
    return (unsigned int)-2146893052;
  v16 = *(_QWORD *)v15;
  if ( *(_QWORD *)v15 >= *(_QWORD *)v15 + 780 * (unsigned __int64)*(unsigned int *)(v15 + 8) )
  {
    v31 = WPP_GLOBAL_Control;
    goto LABEL_132;
  }
  while ( 2 )
  {
    v17 = *((_QWORD *)v9 + 10);
    v18 = *(unsigned int *)(v17 + 196);
    v19 = *(_QWORD *)(v17 + 200);
    if ( !(_DWORD)v18 || !v19 || !v16 )
    {
LABEL_27:
      v9 = a2;
      v25 = *(_DWORD *)(v16 + 772);
      v26 = (*(__int64 (__fastcall **)(struct CSsl3TlsServerContext *, _QWORD))(*(_QWORD *)a2 + 544i64))(a2, v25);
      if ( v26 && v26 != 1168 && v26 != 50 )
        return v26;
      v28 = v49;
      if ( v49 )
      {
        v32 = v46;
        if ( !v26 && v25 == (_DWORD)v46 )
        {
          v31 = WPP_GLOBAL_Control;
          goto LABEL_69;
        }
        v31 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_39;
        LODWORD(v42) = v46;
        LODWORD(v41) = v25;
        WPP_SF_SDD(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x30u, v27, (const wchar_t *)v16, v41, v42);
        goto LABEL_38;
      }
      if ( v26 == 50 )
      {
        v31 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_39;
        v40 = 49;
      }
      else
      {
        v29 = (*(_DWORD *)(v16 + 768) + (*(_DWORD *)(v16 + 768) & 1u)) >> 1;
        if ( v26 != 1168 )
        {
          if ( !v12 )
          {
            v44 = v25;
            v12 = v25;
            v45 = 0;
            v13 = (*(_DWORD *)(v16 + 768) + (*(_DWORD *)(v16 + 768) & 1u)) >> 1;
            if ( v29 == v10 )
            {
LABEL_67:
              v31 = WPP_GLOBAL_Control;
              break;
            }
            goto LABEL_34;
          }
LABEL_32:
          if ( v13 == v10 )
            goto LABEL_38;
          if ( v29 == v10 )
            goto LABEL_75;
LABEL_34:
          v30 = v13 <= v10;
          if ( v13 < v10 )
          {
            if ( v13 < v29 )
            {
LABEL_75:
              v13 = (*(_DWORD *)(v16 + 768) + (*(_DWORD *)(v16 + 768) & 1u)) >> 1;
              if ( v12 )
              {
                v25 = *(_DWORD *)(v16 + 772);
                v44 = v25;
                if ( v29 != v10 )
                {
                  v31 = WPP_GLOBAL_Control;
                  goto LABEL_40;
                }
                goto LABEL_67;
              }
              if ( v45 )
                v45 = *(_DWORD *)(v16 + 772);
LABEL_38:
              v31 = WPP_GLOBAL_Control;
              goto LABEL_39;
            }
            v30 = v13 <= v10;
          }
          if ( v30 || v13 <= v29 || v29 <= v10 )
            goto LABEL_38;
          goto LABEL_75;
        }
        if ( !v12 )
        {
          if ( v45 )
            goto LABEL_32;
          if ( !*((_DWORD *)a2 + 17) && v43 )
          {
            v45 = v25;
            v13 = (*(_DWORD *)(v16 + 768) + (*(_DWORD *)(v16 + 768) & 1u)) >> 1;
            goto LABEL_32;
          }
        }
        v31 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_39;
        v40 = 50;
      }
      WPP_SF_S(
        *((_QWORD *)v31 + 2),
        v40,
        (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
        (const wchar_t *)v16);
      v31 = WPP_GLOBAL_Control;
      goto LABEL_39;
    }
    v20 = *(_DWORD *)(v16 + 768);
    v21 = v19 + 40 * v18;
    v22 = *(_QWORD *)(v17 + 200);
    if ( v19 >= v21 )
    {
LABEL_20:
      if ( !IsCngAlgorithmBlacklisted(v19, v18, 0, (const wchar_t *)v16, 0i64, 0, String2, a5) )
      {
        switch ( *(_DWORD *)(v16 + 772) )
        {
          case 0x17:
            v24 = L"ECDH_P256";
            break;
          case 0x18:
            v24 = L"ECDH_P384";
            break;
          case 0x19:
            v24 = L"ECDH_P521";
            break;
          default:
            goto LABEL_26;
        }
        if ( !IsCngAlgorithmBlacklisted(v19, v18, 0, v24, 0i64, 0, String2, a5) )
        {
LABEL_26:
          v12 = v44;
          goto LABEL_27;
        }
      }
LABEL_99:
      v31 = WPP_GLOBAL_Control;
      goto LABEL_100;
    }
    while ( 1 )
    {
      if ( *(_DWORD *)(v22 + 20) )
      {
        if ( !*(_DWORD *)v22 )
          goto LABEL_51;
        v23 = String2;
        if ( String2 )
          break;
      }
LABEL_18:
      v22 += 40i64;
      if ( v22 >= v21 )
      {
        v10 = v47;
        goto LABEL_20;
      }
    }
    v33 = 0;
    while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*(_QWORD *)(v22 + 8) + 16i64 * v33), v23, 1u) )
    {
      v23 = String2;
      if ( ++v33 >= *(_DWORD *)v22 )
        goto LABEL_18;
    }
LABEL_51:
    if ( a5 && (*(_BYTE *)(v22 + 32) & 1) != 0 )
      goto LABEL_18;
    v34 = *(_QWORD *)(v22 + 24);
    if ( v34 >= v34 + 48i64 * *(unsigned int *)(v22 + 20) )
      goto LABEL_18;
    while ( 1 )
    {
      if ( *(_DWORD *)v34 || *(_WORD *)(v34 + 8) != 8 || wcsncmp(*(const wchar_t **)(v34 + 16), L"ECDH", 4ui64) )
        goto LABEL_55;
      if ( !*(_DWORD *)(v34 + 24) && !*(_DWORD *)(v34 + 40) && !*(_DWORD *)(v34 + 44) )
        break;
      if ( !v20 )
        goto LABEL_55;
      v35 = *(_DWORD *)(v34 + 40);
      if ( !v35 )
      {
        if ( !*(_DWORD *)(v34 + 44) )
          goto LABEL_55;
        v36 = *(_DWORD *)(v34 + 44);
LABEL_94:
        if ( v36 < v20 )
        {
LABEL_95:
          v31 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
            goto LABEL_103;
          if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            LODWORD(v42) = 0;
            LODWORD(v41) = v20;
            WPP_SF_Sdd(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xEu,
              (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
              L"ECDH",
              v41,
              v42);
            goto LABEL_99;
          }
          goto LABEL_100;
        }
        goto LABEL_55;
      }
      if ( v35 > v20 )
        goto LABEL_95;
      v36 = *(_DWORD *)(v34 + 44);
      if ( v36 )
        goto LABEL_94;
LABEL_55:
      v34 += 48i64;
      if ( v34 >= *(_QWORD *)(v22 + 24) + 48 * (unsigned __int64)*(unsigned int *)(v22 + 20) )
        goto LABEL_18;
    }
    v31 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
      goto LABEL_103;
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LODWORD(v41) = 0;
      WPP_SF_Sd(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xCu,
        (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
        L"ECDH",
        v41);
      goto LABEL_99;
    }
LABEL_100:
    if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
    {
      WPP_SF_S(
        *((_QWORD *)v31 + 2),
        0x2Fu,
        (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids,
        (const wchar_t *)v16);
      v31 = WPP_GLOBAL_Control;
    }
LABEL_103:
    v9 = a2;
    v28 = v49;
LABEL_39:
    v25 = v44;
LABEL_40:
    v16 += 780i64;
    if ( v16 < *(_QWORD *)v48 + 780 * (unsigned __int64)*(unsigned int *)(v48 + 8) )
    {
      v10 = v47;
      v12 = v44;
      continue;
    }
    break;
  }
  v32 = v46;
LABEL_69:
  v37 = v45;
  if ( !v25 && !v45 )
  {
LABEL_132:
    if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)v31 + 2), 51i64, &WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids);
    return (unsigned int)-2146893007;
  }
  if ( v28 && v25 != v32 )
  {
    if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
    {
      LODWORD(v41) = v32;
      WPP_SF_DD(*((_QWORD *)v31 + 2), 0x34u, (__int64)&WPP_bcb3b342e8be3997fa3752f6a9108bb3_Traceguids, v25, v41);
    }
    return (unsigned int)-2146893007;
  }
  if ( v25 || !v45 )
  {
    v37 = v25;
    *a8 = 0;
  }
  else
  {
    *a8 = 1;
  }
  v26 = 0;
  *a7 = v37;
  return v26;
}
// 18003211B: variable 'v27' is possibly undefined
// 18003211B: variable 'v41' is possibly undefined
// 18003211B: variable 'v42' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

