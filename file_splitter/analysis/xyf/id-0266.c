//----- (00000001800151F0) ----------------------------------------------------
__int64 __fastcall I_GetKeyExchangeDetailsFromAlgorithmName(wchar_t *String1, __int64 a2, _DWORD *a3)
{
  unsigned int v5; // eax
  __int64 v6; // rbx
  const wchar_t **v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // r8
  __int64 v11; // rcx

  if ( a3 )
    *a3 = 0;
  v5 = g_dwKeyExchangeInfoTotalCount;
  v6 = 0i64;
  if ( !g_dwKeyExchangeInfoTotalCount )
    return 1168i64;
  while ( 1 )
  {
    v7 = (const wchar_t **)g_pKeyExchangeInfo[v6];
    if ( !v7 || !*v7 )
      goto LABEL_8;
    if ( !wcsnicmp(String1, *v7, 0x40ui64) )
      break;
    v5 = g_dwKeyExchangeInfoTotalCount;
LABEL_8:
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= v5 )
      return 1168i64;
  }
  v11 = g_pKeyExchangeInfo[v6];
  if ( !v11 )
    return 1168i64;
  return I_GetKeyExchangeDetailsFromKeyExchangeInfo(v11, v8, v9, a3, 0i64);
}
// 180015273: variable 'v8' is possibly undefined
// 180015273: variable 'v9' is possibly undefined
// 1800923B0: using guessed type int g_dwKeyExchangeInfoTotalCount;
// 1800923C0: using guessed type _QWORD g_pKeyExchangeInfo[12];

