// File count: 272
// Total lines: 17
-----------------------------------------
__int64 __fastcall I_GetSignatureDetailsFromSignatureInfo(
        _DWORD *a1,
        __int64 a2,
        __int64 a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6)
{
  if ( a4 )
    *a4 = a1[3];
  if ( a5 )
    *a5 = a1[4];
  if ( a6 )
    *a6 = a1[5];
  return 0i64;
}
