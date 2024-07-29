//----- (000000018005AD50) ----------------------------------------------------
void __fastcall CSsl3TlsClientContext::ClearCacheItem(CSsl3TlsClientContext *this)
{
  CSessionCacheTable **v2; // rcx

  v2 = (CSessionCacheTable **)*((_QWORD *)this + 165);
  if ( v2 )
  {
    CSessionCacheTable::DereferenceCacheItemInternal(v2[28], (struct CSessionCacheItem *)v2, 1, 0);
    *((_QWORD *)this + 165) = 0i64;
  }
}

