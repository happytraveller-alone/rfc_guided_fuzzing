//----- (0000000180018FC0) ----------------------------------------------------
CSessionCacheServerItem *__fastcall CSessionCacheServerItem::`vector deleting destructor'(
        CSessionCacheServerItem *this,
        char a2)
{
  void *v4; // rcx

  *(_QWORD *)this = &CSessionCacheServerItem::`vftable';
  v4 = (void *)*((_QWORD *)this + 43);
  if ( v4 )
    NtClose(v4);
  *(_QWORD *)this = &CSessionCacheItem::`vftable';
  CSessionCacheItem::ClearState(this);
  if ( !*((_DWORD *)this + 17) )
    RtlDeleteResource((PRTL_RESOURCE)((char *)this + 72));
  *(_QWORD *)this = &IAllocate::`vftable';
  if ( (a2 & 1) != 0 )
    (*(void (__fastcall **)(struct IAllocate *, CSessionCacheServerItem *))(*(_QWORD *)CSessionCacheServerItem::m_pServerCacheLookaside
                                                                          + 32i64))(
      CSessionCacheServerItem::m_pServerCacheLookaside,
      this);
  return this;
}
// 18007C298: using guessed type void *IAllocate::`vftable';
// 18007C2C0: using guessed type void *CSessionCacheItem::`vftable';
// 18007C330: using guessed type void *CSessionCacheServerItem::`vftable';
// 1800927F8: using guessed type struct IAllocate *CSessionCacheServerItem::m_pServerCacheLookaside;

