// File count: 99
// Total lines: 13
------------------------------------------
__int64 __fastcall I_GetHashDetailsFromHashInfo(__int64 a1, _QWORD *a2, _DWORD *a3, __int64 a4, _DWORD *a5, _DWORD *a6)
{
  if ( a3 )
    *a3 = *(_DWORD *)(a1 + 8);
  if ( a5 )
    *a5 = *(_DWORD *)(a1 + 16);
  if ( a2 )
    *a2 = *(_QWORD *)a1;
  if ( a6 )
    *a6 = *(_DWORD *)(a1 + 20);
  return 0i64;
}
