// File count: 97
// Total lines: 139
-----------------------------------------
char __fastcall IsEcdsaAlgorithmBlacklisted(
        struct _TLS_PARAMETERS *a1,
        unsigned int a2,
        const unsigned __int16 *a3,
        int a4,
        unsigned int a5,
        PCUNICODE_STRING String2,
        char a7)
{
  struct _TLS_PARAMETERS *v10; // rax
  struct _TLS_PARAMETERS *v11; // rdi
  int v12; // esi
  int v13; // esi
  const wchar_t *v15; // r9
  unsigned int v16; // ebx
  unsigned __int64 v17; // rbx
  unsigned __int64 i; // rcx
  struct _TLS_PARAMETERS *v19; // [rsp+40h] [rbp-38h]
  const unsigned __int16 *v20; // [rsp+90h] [rbp+18h]

  v20 = a3;
  if ( !a2 || !a1 )
    return 0;
  v10 = (struct _TLS_PARAMETERS *)((char *)a1 + 40 * a2);
  v19 = v10;
  v11 = a1;
  if ( a1 < v10 )
  {
    while ( 1 )
    {
      if ( !*((_DWORD *)v11 + 5) )
        goto LABEL_7;
      if ( *(_DWORD *)v11 )
      {
        if ( !String2 )
          goto LABEL_7;
        v16 = 0;
        while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*((_QWORD *)v11 + 1) + 16i64 * v16), String2, 1u) )
        {
          if ( ++v16 >= *(_DWORD *)v11 )
          {
LABEL_36:
            v10 = v19;
            goto LABEL_7;
          }
        }
        v10 = v19;
      }
      if ( !a7 || (*((_BYTE *)v11 + 32) & 1) == 0 )
        break;
LABEL_7:
      v11 = (struct _TLS_PARAMETERS *)((char *)v11 + 40);
      if ( v11 >= v10 )
      {
        a3 = v20;
        goto LABEL_9;
      }
    }
    v17 = *((_QWORD *)v11 + 3);
    for ( i = v17 + 48i64 * *((unsigned int *)v11 + 5); ; i = *((_QWORD *)v11 + 3) + 48i64 * *((unsigned int *)v11 + 5) )
    {
      if ( v17 >= i )
        goto LABEL_36;
      if ( *(_DWORD *)v17 == 1 && *(_WORD *)(v17 + 8) == 10 && !wcsncmp(*(const wchar_t **)(v17 + 16), L"ECDSA", 5ui64) )
      {
        if ( !*(_DWORD *)(v17 + 24) && !*(_DWORD *)(v17 + 40) && !*(_DWORD *)(v17 + 44) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_Sd(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xCu,
              (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
              L"ECDSA",
              1);
          }
          return 1;
        }
        if ( a5 )
        {
          if ( *(_DWORD *)(v17 + 40) )
          {
            if ( *(_DWORD *)(v17 + 40) > a5 )
              goto LABEL_47;
          }
          else if ( !*(_DWORD *)(v17 + 44) )
          {
            goto LABEL_26;
          }
          if ( *(_DWORD *)(v17 + 44) && *(_DWORD *)(v17 + 44) < a5 )
          {
LABEL_47:
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_Sdd(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xEu,
                (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
                L"ECDSA",
                a5,
                1);
            }
            return 1;
          }
        }
      }
LABEL_26:
      v17 += 48i64;
    }
  }
LABEL_9:
  if ( a3 && IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 1, a3, 0i64, 0, String2, a7) )
    return 1;
  v12 = a4 - 23;
  if ( v12 )
  {
    v13 = v12 - 1;
    if ( v13 )
    {
      if ( v13 != 1 )
        return 0;
      v15 = L"ECDSA_P521";
    }
    else
    {
      v15 = L"ECDSA_P384";
    }
  }
  else
  {
    v15 = L"ECDSA_P256";
  }
  return IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 1, v15, 0i64, 0, String2, a7);
}
// 1800821D8: using guessed type wchar_t aEcdsaP384[11];
// 180082E10: using guessed type wchar_t aEcdsaP521[11];
