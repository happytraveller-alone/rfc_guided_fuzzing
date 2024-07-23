// File count: 98
// Total lines: 24
------------------------------------------
__int64 __fastcall I_GetHashDetailsFromIndex(
        unsigned int a1,
        _QWORD *a2,
        _DWORD *a3,
        __int64 a4,
        __int64 a5,
        _DWORD *a6)
{
  __int64 v6; // rcx

  if ( a3 )
    *a3 = 0;
  if ( a2 )
    *a2 = 0i64;
  if ( a6 )
    *a6 = 0;
  if ( a1 < g_dwHashInfoTotalCount && (v6 = g_pHashInfo[a1]) != 0 )
    return I_GetHashDetailsFromHashInfo(v6, a2, a3, (__int64)a2, 0i64, a6);
  else
    return 1168i64;
}
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];
