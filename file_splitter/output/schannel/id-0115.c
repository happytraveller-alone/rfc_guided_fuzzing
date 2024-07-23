// File count: 115
// Total lines: 75
-----------------------------------------
__int64 __fastcall CheckUserMappingTarget(unsigned __int16 *a1)
{
  const wchar_t *v1; // rbx
  int v4; // edx
  CCipherMill *v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // rax
  unsigned __int16 *v8; // rbp
  unsigned __int16 *v9; // rdi
  wchar_t *v10; // rdx
  __int64 v11; // rax
  const wchar_t *i; // rcx
  wchar_t v13; // ax

  v1 = (const wchar_t *)g_pszDomainList;
  if ( !a1 || !g_pszDomainList )
    return 0i64;
  v4 = *(unsigned __int16 *)g_pszDomainList - 42;
  if ( *(_WORD *)g_pszDomainList == 42 )
    v4 = *((unsigned __int16 *)g_pszDomainList + 1);
  if ( !v4 )
  {
    v5 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      return 1i64;
    v6 = 18i64;
    goto LABEL_33;
  }
  v7 = -1i64;
  do
    ++v7;
  while ( a1[v7] );
  v8 = &a1[v7];
  if ( !*(_WORD *)g_pszDomainList )
    return 0i64;
  while ( 1 )
  {
    v9 = v8 - 1;
    v10 = wcschr(v1, 0x2Cu);
    if ( !v10 )
    {
      v11 = -1i64;
      do
        ++v11;
      while ( v1[v11] );
      v10 = (wchar_t *)&v1[v11];
    }
    for ( i = v10 - 1; i >= v1 && v9 >= a1 && *i == *v9; --i )
      --v9;
    if ( i == v1 - 1 && (v9 == a1 - 1 || *v9 == 46) )
      break;
    v13 = *v10;
    if ( *v10 == 44 )
    {
      v1 = v10 + 1;
      v13 = v10[1];
    }
    else
    {
      v1 = v10;
    }
    if ( !v13 )
      return 0i64;
  }
  v5 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v6 = 19i64;
LABEL_33:
    WPP_SF_(*((_QWORD *)v5 + 2), v6, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
  }
  return 1i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
