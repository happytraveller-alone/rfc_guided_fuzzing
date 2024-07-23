// File count: 267
// Total lines: 14
-----------------------------------------
__int64 __fastcall I_GetKeyExchangeDetailsFromKeyExchangeInfo(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _DWORD *a4,
        _DWORD *a5)
{
  if ( a4 )
    *a4 = *(_DWORD *)(a1 + 12);
  if ( a5 )
    *a5 = *(_DWORD *)(a1 + 16);
  return 0i64;
}
