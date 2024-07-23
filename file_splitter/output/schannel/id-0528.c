// File count: 528
// Total lines: 30
-----------------------------------------
__int64 __fastcall I_GetSignatureDetailsFromAlgId(int a1, __int64 a2, __int64 a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v6; // rdx
  _QWORD *i; // r8
  _DWORD *v8; // rcx

  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  v6 = 0i64;
  if ( !g_dwSignatureInfoTotalCount )
    return 1168i64;
  for ( i = g_pSignatureInfo; ; ++i )
  {
    v8 = (_DWORD *)*i;
    if ( *i )
    {
      if ( v8[3] == a1 )
        break;
    }
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= g_dwSignatureInfoTotalCount )
      return 1168i64;
  }
  return I_GetSignatureDetailsFromSignatureInfo(v8, v6, (__int64)i, 0i64, a4, a5);
}
// 180092218: using guessed type int g_dwSignatureInfoTotalCount;
// 180092220: using guessed type _QWORD g_pSignatureInfo[16];
