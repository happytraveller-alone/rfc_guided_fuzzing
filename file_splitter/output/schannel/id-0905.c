// File count: 905
// Total lines: 16
-----------------------------------------
__int64 __fastcall SpCallPackagePassthrough(
        __int64 a1,
        _DWORD *a2,
        unsigned __int64 a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  if ( !a2 || a4 < 4 )
    return 3221225485i64;
  if ( *a2 == 2 )
    return SpCallPackage(a1, a2, a3, a4, a5, a6, a7);
  return 2148074242i64;
}
