// File count: 1165
// Total lines: 25
----------------------------------------
__int64 __fastcall CSessionCacheItem::SerializeAppData(
        CSessionCacheItem *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned int *a4)
{
  const void *v8; // rdx

  if ( !a2 && a3 || !a4 )
    return 87i64;
  v8 = (const void *)*((_QWORD *)this + 7);
  if ( v8 )
  {
    if ( a3 < *((_DWORD *)this + 16) )
      return 122i64;
    memcpy_0(a2, v8, *((unsigned int *)this + 16));
    *a4 = *((_DWORD *)this + 16);
  }
  else
  {
    *a4 = 0;
  }
  return 0i64;
}
