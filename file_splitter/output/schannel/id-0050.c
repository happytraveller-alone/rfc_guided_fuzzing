// File count: 50
// Total lines: 11
------------------------------------------
void __fastcall CSessionCacheItem::~CSessionCacheItem(CSessionCacheItem *this)
{
  *(_QWORD *)this = &CSessionCacheItem::`vftable';
  CSessionCacheItem::ClearState(this);
  if ( !*((_DWORD *)this + 17) )
    RtlDeleteResource((PRTL_RESOURCE)((char *)this + 72));
  *(_QWORD *)this = &IAllocate::`vftable';
}
// 18007C298: using guessed type void *IAllocate::`vftable';
// 18007C2C0: using guessed type void *CSessionCacheItem::`vftable';
