//----- (00000001800595E0) ----------------------------------------------------
__int64 __fastcall CSessionCacheManager::PurgeCacheEntries(
        CSessionCacheManager *this,
        unsigned int a2,
        struct _LUID *a3,
        int a4,
        unsigned __int16 *a5)
{
  int *v5; // rsi
  unsigned int v6; // ebx

  v5 = (int *)((char *)this + 32);
  v6 = 0;
  if ( *((_DWORD *)this + 8) && *((_DWORD *)this + 12) )
  {
    do
      CSessionCacheTable::PurgeCacheEntries(
        (CSessionCacheTable *)(*((_QWORD *)this + 5) + 152i64 * v6++),
        a2,
        a3,
        a4,
        v5,
        a5);
    while ( v6 < *((_DWORD *)this + 12) );
  }
  return 0i64;
}

