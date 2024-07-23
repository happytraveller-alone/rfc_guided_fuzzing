// File count: 85
// Total lines: 25
------------------------------------------
CSessionCacheClientItem *__fastcall CSessionCacheClientItem::CSessionCacheClientItem(
        CSessionCacheClientItem *this,
        struct CSessionCacheManager *a2,
        int a3,
        unsigned __int16 *a4)
{
  CSessionCacheItem::CSessionCacheItem(this, a3, 0i64);
  *((_QWORD *)this + 46) = a4;
  *(_QWORD *)this = &CSessionCacheClientItem::`vftable';
  *((_QWORD *)this + 49) = a2;
  *((_QWORD *)this + 42) = 0i64;
  *((_DWORD *)this + 86) = 0;
  *((_QWORD *)this + 44) = 0i64;
  *((_DWORD *)this + 90) = 0;
  *((_QWORD *)this + 48) = 0i64;
  *((_QWORD *)this + 50) = 0i64;
  *((_QWORD *)this + 51) = 0i64;
  *((_DWORD *)this + 104) = 0;
  *((_QWORD *)this + 53) = 0i64;
  *((_DWORD *)this + 108) = 0;
  SslGetClientLogonId((struct _LUID *)this + 47);
  return this;
}
// 18007C210: using guessed type void *CSessionCacheClientItem::`vftable';
