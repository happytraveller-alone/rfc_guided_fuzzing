//----- (0000000180003328) ----------------------------------------------------
void __fastcall CSessionCacheClientItem::~CSessionCacheClientItem(CSessionCacheClientItem *this)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  __int64 v6; // rcx
  void *v7; // rcx

  *(_QWORD *)this = &CSessionCacheClientItem::`vftable';
  v2 = (void *)*((_QWORD *)this + 42);
  if ( v2 )
    SPExternalFree(v2);
  v3 = (void *)*((_QWORD *)this + 44);
  if ( v3 )
    CryptMemFree(v3);
  v4 = (void *)*((_QWORD *)this + 50);
  if ( v4 )
    SPExternalFree(v4);
  v5 = (void *)*((_QWORD *)this + 46);
  if ( v5 )
    SPExternalFree(v5);
  v6 = *((_QWORD *)this + 48);
  if ( v6 )
    CSessionCacheTable::DereferenceCacheItemInternal(
      *(CSessionCacheTable **)(v6 + 224),
      *((struct CSessionCacheItem **)this + 48),
      1,
      0);
  v7 = (void *)*((_QWORD *)this + 53);
  if ( v7 )
    SPExternalFree(v7);
  CSessionCacheItem::~CSessionCacheItem(this);
}
// 18007C210: using guessed type void *CSessionCacheClientItem::`vftable';

