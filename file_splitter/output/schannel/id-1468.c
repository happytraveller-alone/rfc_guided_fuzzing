// File count: 1468
// Total lines: 26
----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::GenerateRenegotiateClientHello(
        CSsl3TlsClientContext *this,
        struct SPBuffer *a2)
{
  CSessionCacheClientItem **v3; // rdi
  unsigned int v5; // esi
  __int64 v6; // rcx
  bool v8; // zf

  v3 = (CSessionCacheClientItem **)((char *)this + 1320);
  CSessionCacheManager::AcquireCacheTableLock(
    (__int64)this,
    *(const unsigned __int16 **)(*((_QWORD *)this + 165) + 368i64),
    0i64);
  v5 = CSessionCacheClientItem::CloneCacheElement(*v3, CSessionCacheManager::m_pSessionCacheManager, v3);
  CSessionCacheManager::ReleaseCacheTableLock(v6, *((const unsigned __int16 **)*v3 + 46), 0i64);
  if ( v5 )
    return v5;
  v8 = *((_BYTE *)this + 233) == 0;
  *((_QWORD *)this + 11) = *v3;
  if ( !v8 )
    *((_DWORD *)this + 327) = 0;
  return (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, struct SPBuffer *))(*(_QWORD *)this + 216i64))(this, a2);
}
// 180075F4C: variable 'v6' is possibly undefined
