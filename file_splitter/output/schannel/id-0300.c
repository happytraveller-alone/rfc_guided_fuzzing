// File count: 300
// Total lines: 108
----------------------------------------
char __fastcall IsRsaAlgorithmBlacklisted(
        unsigned __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        const UNICODE_STRING *String2,
        char a6)
{
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r15
  char v10; // si
  unsigned int v12; // edi
  unsigned __int64 v13; // rdi
  unsigned __int64 i; // rcx
  int v15; // [rsp+20h] [rbp-28h]
  int v16; // [rsp+20h] [rbp-28h]
  int v17; // [rsp+28h] [rbp-20h]

  v8 = a1;
  if ( !a2 || !a1 )
    return 0;
  v9 = a1 + 40i64 * a2;
  if ( a1 < v9 )
  {
    v10 = 1;
    while ( 1 )
    {
      if ( *(_DWORD *)(v8 + 20) )
      {
        if ( !*(_DWORD *)v8 )
          goto LABEL_13;
        if ( String2 )
          break;
      }
LABEL_8:
      v8 += 40i64;
      if ( v8 >= v9 )
        return 0;
    }
    v12 = 0;
    while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*(_QWORD *)(v8 + 8) + 16i64 * v12), String2, 1u) )
    {
      if ( ++v12 >= *(_DWORD *)v8 )
        goto LABEL_8;
    }
LABEL_13:
    if ( a6 && (*(_BYTE *)(v8 + 32) & 1) != 0 )
      goto LABEL_8;
    v13 = *(_QWORD *)(v8 + 24);
    for ( i = v13 + 48i64 * *(unsigned int *)(v8 + 20); ; i = *(_QWORD *)(v8 + 24) + 48i64 * *(unsigned int *)(v8 + 20) )
    {
      if ( v13 >= i )
        goto LABEL_8;
      if ( *(_DWORD *)v13 == a3 && *(_WORD *)(v13 + 8) == 6 && !wcsncmp(*(const wchar_t **)(v13 + 16), L"RSA", 3ui64) )
      {
        if ( !*(_DWORD *)(v13 + 24) && !*(_DWORD *)(v13 + 40) && !*(_DWORD *)(v13 + 44) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            v16 = a3;
            WPP_SF_Sd(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xCu,
              (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
              L"RSA",
              v16);
          }
          return v10;
        }
        if ( a4 )
        {
          if ( *(_DWORD *)(v13 + 40) )
          {
            if ( *(_DWORD *)(v13 + 40) > a4 )
              goto LABEL_37;
          }
          else if ( !*(_DWORD *)(v13 + 44) )
          {
            goto LABEL_18;
          }
          if ( *(_DWORD *)(v13 + 44) && *(_DWORD *)(v13 + 44) < a4 )
          {
LABEL_37:
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              v17 = a3;
              v15 = a4;
              WPP_SF_Sdd(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xEu,
                (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
                L"RSA",
                v15,
                v17);
            }
            return v10;
          }
        }
      }
LABEL_18:
      v13 += 48i64;
    }
  }
  return 0;
}
