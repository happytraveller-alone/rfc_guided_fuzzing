// File count: 906
// Total lines: 35
-----------------------------------------
__int64 __fastcall SpCallPackageUntrusted(
        __int64 a1,
        char *a2,
        unsigned __int64 a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  int v10; // ebx
  void *v11; // r8
  __int64 v12; // r9
  int v14; // ebx
  int v15; // ebx

  if ( !a2 || a4 < 4 )
    return 3221225485i64;
  v10 = *(_DWORD *)a2;
  if ( !(unsigned int)SchannelInit(0) )
    return 2148074242i64;
  *a5 = 0i64;
  *a6 = 0;
  v14 = v10 - 3;
  if ( !v14 )
    return SslPurgeSessionCache(a5, a2, a3, a4, a5, a6, a7);
  v15 = v14 - 1;
  if ( !v15 )
    return SslSessionCacheInfo(a5, a2, a3, a4, a5, a6, a7);
  if ( v15 != 4 )
    return 2148074242i64;
  return SslGetStreamSizes(a5, a6, v11, v12, a5, a6, a7);
}
// 18004CA0E: variable 'v11' is possibly undefined
// 18004CA0E: variable 'v12' is possibly undefined
