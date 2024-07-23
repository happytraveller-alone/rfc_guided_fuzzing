// File count: 96
// Total lines: 125
-----------------------------------------
char __fastcall IsEcdheAlgorithmBlacklisted(
        struct _TLS_PARAMETERS *a1,
        unsigned int a2,
        struct CEccCurveInfo *a3,
        struct _UNICODE_STRING *a4,
        unsigned __int8 a5)
{
  unsigned int v9; // r15d
  struct _TLS_PARAMETERS *v10; // rdi
  struct _TLS_PARAMETERS *v11; // rax
  const wchar_t *v12; // r9
  unsigned int v14; // ebx
  unsigned __int64 v15; // rbx
  unsigned __int64 i; // rcx
  struct _TLS_PARAMETERS *v17; // [rsp+40h] [rbp-38h]

  if ( !a2 || !a1 || !a3 )
    return 0;
  v9 = *((_DWORD *)a3 + 192);
  v10 = a1;
  v11 = (struct _TLS_PARAMETERS *)((char *)a1 + 40 * a2);
  v17 = v11;
  if ( a1 < v11 )
  {
    while ( 1 )
    {
      if ( !*((_DWORD *)v10 + 5) )
        goto LABEL_8;
      if ( *(_DWORD *)v10 )
      {
        if ( !a4 )
          goto LABEL_8;
        v14 = 0;
        while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*((_QWORD *)v10 + 1) + 16i64 * v14), a4, 1u) )
        {
          if ( ++v14 >= *(_DWORD *)v10 )
          {
LABEL_35:
            v11 = v17;
            goto LABEL_8;
          }
        }
        v11 = v17;
      }
      if ( !a5 || (*((_BYTE *)v10 + 32) & 1) == 0 )
        break;
LABEL_8:
      v10 = (struct _TLS_PARAMETERS *)((char *)v10 + 40);
      if ( v10 >= v11 )
        goto LABEL_9;
    }
    v15 = *((_QWORD *)v10 + 3);
    for ( i = v15 + 48i64 * *((unsigned int *)v10 + 5); ; i = *((_QWORD *)v10 + 3) + 48i64 * *((unsigned int *)v10 + 5) )
    {
      if ( v15 >= i )
        goto LABEL_35;
      if ( !*(_DWORD *)v15 && *(_WORD *)(v15 + 8) == 8 && !wcsncmp(*(const wchar_t **)(v15 + 16), L"ECDH", 4ui64) )
      {
        if ( !*(_DWORD *)(v15 + 24) && !*(_DWORD *)(v15 + 40) && !*(_DWORD *)(v15 + 44) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_Sd(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xCu,
              (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
              L"ECDH",
              0);
          }
          return 1;
        }
        if ( v9 )
        {
          if ( *(_DWORD *)(v15 + 40) )
          {
            if ( *(_DWORD *)(v15 + 40) > v9 )
              goto LABEL_46;
          }
          else if ( !*(_DWORD *)(v15 + 44) )
          {
            goto LABEL_25;
          }
          if ( *(_DWORD *)(v15 + 44) && *(_DWORD *)(v15 + 44) < v9 )
          {
LABEL_46:
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_Sdd(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xEu,
                (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
                L"ECDH",
                v9,
                0);
            }
            return 1;
          }
        }
      }
LABEL_25:
      v15 += 48i64;
    }
  }
LABEL_9:
  if ( !IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 0, (const wchar_t *)a3, 0i64, 0, a4, a5) )
  {
    switch ( *((_DWORD *)a3 + 193) )
    {
      case 0x17:
        v12 = L"ECDH_P256";
        return IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 0, v12, 0i64, 0, a4, a5);
      case 0x18:
        v12 = L"ECDH_P384";
        return IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 0, v12, 0i64, 0, a4, a5);
      case 0x19:
        v12 = L"ECDH_P521";
        return IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 0, v12, 0i64, 0, a4, a5);
    }
    return 0;
  }
  return 1;
}
