//----- (00000001800790C4) ----------------------------------------------------
__int64 __fastcall I_GetCipherDetailsFromAlgorithmName(wchar_t *String1, __int64 a2, __int64 a3, _DWORD *a4)
{
  unsigned int v4; // ebx
  unsigned int v7; // eax
  int v8; // esi
  const wchar_t **v9; // rcx
  __int64 v11; // rax

  v4 = 0;
  if ( a4 )
    *a4 = 0;
  v7 = g_dwCipherInfoTotalCount;
  v8 = 0;
  if ( !g_dwCipherInfoTotalCount )
    return 1168;
  while ( 1 )
  {
    v9 = (const wchar_t **)g_pCipherInfo[v8];
    if ( !v9 || !*v9 )
      goto LABEL_8;
    if ( !wcsnicmp(String1, *v9, 0x40ui64) )
      break;
    v7 = g_dwCipherInfoTotalCount;
LABEL_8:
    if ( ++v8 >= v7 )
      return 1168;
  }
  v11 = g_pCipherInfo[v8];
  if ( !v11 )
    return 1168;
  if ( a4 )
    *a4 = *(_DWORD *)(v11 + 16);
  return v4;
}
// 1800922A0: using guessed type _QWORD g_pCipherInfo[16];
// 180092320: using guessed type int g_dwCipherInfoTotalCount;
