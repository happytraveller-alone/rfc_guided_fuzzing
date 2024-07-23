// File count: 480
// Total lines: 12
-----------------------------------------
void __fastcall CSsl3TlsServerContext::ClearCacheItem(CSsl3TlsServerContext *this)
{
  CSessionCacheTable **v2; // rcx

  v2 = (CSessionCacheTable **)*((_QWORD *)this + 124);
  if ( v2 )
  {
    CSessionCacheTable::DereferenceCacheItemInternal(v2[28], (struct CSessionCacheItem *)v2, 1, 0);
    *((_QWORD *)this + 124) = 0i64;
  }
}
