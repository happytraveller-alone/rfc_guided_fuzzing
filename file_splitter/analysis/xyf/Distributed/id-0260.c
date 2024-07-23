//----- (0000000180014D38) ----------------------------------------------------
__int64 __fastcall I_GetHashInfoFromAlgorithmName(wchar_t *String1)
{
  unsigned int v1; // eax
  __int64 v2; // rbx
  const wchar_t **v4; // rdx
  const wchar_t *v5; // rdx

  v1 = g_dwHashInfoTotalCount;
  v2 = 0i64;
  if ( !g_dwHashInfoTotalCount )
    return 0i64;
  while ( 1 )
  {
    v4 = (const wchar_t **)g_pHashInfo[v2];
    if ( !v4 )
      goto LABEL_6;
    v5 = *v4;
    if ( !v5 )
      goto LABEL_6;
    if ( !wcsnicmp(String1, v5, 0x40ui64) )
      return g_pHashInfo[v2];
    v1 = g_dwHashInfoTotalCount;
LABEL_6:
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= v1 )
      return 0i64;
  }
}
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];

