//----- (0000000180027298) ----------------------------------------------------
__int64 __fastcall CSessionCacheServerItem::InitializeServerCacheLookAside(char a1)
{
  struct IAllocate *v2; // rbx
  void *v3; // rax

  v2 = 0i64;
  if ( CSessionCacheServerItem::m_pServerCacheLookaside )
    (*(void (__fastcall **)(struct IAllocate *, __int64))(*(_QWORD *)CSessionCacheServerItem::m_pServerCacheLookaside
                                                        + 8i64))(
      CSessionCacheServerItem::m_pServerCacheLookaside,
      1i64);
  v3 = operator new(0x50ui64);
  if ( v3 )
    v2 = (struct IAllocate *)CSslLookaside::CSslLookaside((__int64)v3, 360, a1);
  CSessionCacheServerItem::m_pServerCacheLookaside = v2;
  return v2 == 0i64 ? 0xE : 0;
}
// 1800927F8: using guessed type struct IAllocate *CSessionCacheServerItem::m_pServerCacheLookaside;

