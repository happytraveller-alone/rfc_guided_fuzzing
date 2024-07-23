// File count: 95
// Total lines: 159
-----------------------------------------
char __fastcall IsCngAlgorithmBlacklisted(
        unsigned __int64 a1,
        unsigned int a2,
        int a3,
        const wchar_t *a4,
        wchar_t *a5,
        unsigned int a6,
        const UNICODE_STRING *String2,
        char a8)
{
  int v9; // r15d
  unsigned __int64 v10; // rdi
  __int64 v11; // rax
  unsigned __int64 v12; // rbp
  unsigned int v14; // esi
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // r8
  __int64 v17; // rax
  __int64 v18; // rax
  unsigned int v19; // eax
  unsigned int v20; // eax
  const wchar_t **v21; // r15
  unsigned __int64 v22; // r8
  __int64 v23; // rax
  __int64 v24; // rdx
  __int64 v25; // r8

  v9 = a3;
  v10 = a1;
  if ( !a2 )
    return 0;
  if ( !a1 )
    return 0;
  if ( !a4 )
    return 0;
  v11 = -1i64;
  do
    ++v11;
  while ( a4[v11] );
  if ( !v11 )
    return 0;
  v12 = a1 + 40i64 * a2;
  if ( a1 >= v12 )
    return 0;
  while ( 1 )
  {
    if ( *(_DWORD *)(v10 + 20) )
    {
      if ( !*(_DWORD *)v10 )
        goto LABEL_15;
      if ( String2 )
        break;
    }
LABEL_11:
    v10 += 40i64;
    if ( v10 >= v12 )
      return 0;
  }
  v14 = 0;
  while ( RtlCompareUnicodeString((PCUNICODE_STRING)(*(_QWORD *)(v10 + 8) + 16i64 * v14), String2, 1u) )
  {
    if ( ++v14 >= *(_DWORD *)v10 )
      goto LABEL_11;
  }
LABEL_15:
  if ( a8 && (*(_BYTE *)(v10 + 32) & 1) != 0 )
    goto LABEL_11;
  v15 = *(_QWORD *)(v10 + 24);
  if ( v15 >= v15 + 48i64 * *(unsigned int *)(v10 + 20) )
    goto LABEL_11;
  while ( 1 )
  {
    if ( *(_DWORD *)v15 != v9 )
      goto LABEL_19;
    v16 = *(unsigned __int16 *)(v15 + 8);
    v17 = -1i64;
    do
      ++v17;
    while ( a4[v17] );
    if ( 2 * v17 != v16 || wcsncmp(*(const wchar_t **)(v15 + 16), a4, v16 >> 1) )
      goto LABEL_19;
    v18 = *(unsigned int *)(v15 + 24);
    if ( !(_DWORD)v18 && !*(_DWORD *)(v15 + 40) && !*(_DWORD *)(v15 + 44) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_Sd(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xCu,
          (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
          a4,
          v9);
      return 1;
    }
    if ( !a5 )
      goto LABEL_28;
    v21 = *(const wchar_t ***)(v15 + 32);
    if ( v21 < &v21[2 * v18] )
      break;
LABEL_39:
    v9 = a3;
LABEL_28:
    if ( a6 )
    {
      v19 = *(_DWORD *)(v15 + 40);
      if ( !v19 )
      {
        if ( !*(_DWORD *)(v15 + 44) )
          goto LABEL_19;
        v20 = *(_DWORD *)(v15 + 44);
LABEL_49:
        if ( v20 < a6 )
        {
LABEL_50:
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_Sdd(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xEu,
              (__int64)&WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids,
              a4,
              a6,
              v9);
          }
          return 1;
        }
        goto LABEL_19;
      }
      if ( v19 > a6 )
        goto LABEL_50;
      v20 = *(_DWORD *)(v15 + 44);
      if ( v20 )
        goto LABEL_49;
    }
LABEL_19:
    v15 += 48i64;
    if ( v15 >= *(_QWORD *)(v10 + 24) + 48 * (unsigned __int64)*(unsigned int *)(v10 + 20) )
      goto LABEL_11;
  }
  while ( 1 )
  {
    v22 = *(unsigned __int16 *)v21;
    v23 = -1i64;
    do
      ++v23;
    while ( a5[v23] );
    if ( 2 * v23 == v22 && !wcsncmp(v21[1], a5, v22 >> 1) )
      break;
    v21 += 2;
    if ( (unsigned __int64)v21 >= *(_QWORD *)(v15 + 32) + 16 * (unsigned __int64)*(unsigned int *)(v15 + 24) )
      goto LABEL_39;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_SSd(*((_QWORD *)WPP_GLOBAL_Control + 2), v24, v25, a4, a5, a3);
  return 1;
}
// 180033AB9: variable 'v24' is possibly undefined
// 180033AB9: variable 'v25' is possibly undefined
