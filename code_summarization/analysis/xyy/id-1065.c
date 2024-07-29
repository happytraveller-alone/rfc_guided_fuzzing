//----- (0000000180059568) ----------------------------------------------------
unsigned __int8 __fastcall CSessionCacheManager::LookupCacheForServerItem(
        CSessionCacheManager *this,
        struct CSslContext *a2,
        unsigned __int8 *a3,
        unsigned int a4,
        struct CSessionCacheServerItem **a5)
{
  size_t Size; // [rsp+20h] [rbp-28h]
  struct CSessionCacheItem *v7; // [rsp+30h] [rbp-18h] BYREF

  if ( a4 >= 4 && *(_DWORD *)a3 < *((_DWORD *)this + 4) )
  {
    LODWORD(Size) = a4;
    if ( CSessionCacheTable::LookupCacheBySessionId(
           (CSessionCacheTable *)(*((_QWORD *)this + 5) + 152i64
                                                        * (unsigned int)(*(_DWORD *)a3 / *((_DWORD *)this + 13))),
           *(_DWORD *)a3 % *((_DWORD *)this + 13),
           a2,
           a3,
           Size,
           &v7) )
    {
      *a5 = v7;
      return 1;
    }
    *a5 = 0i64;
  }
  return 0;
}
// 1800595AD: variable 'Size' is possibly undefined
