//----- (0000000180002F90) ----------------------------------------------------
void __fastcall CSessionCacheManager::PurgeCacheForCredentialGroup(
        CSessionCacheManager *this,
        struct CCredentialGroup *a2)
{
  unsigned int v2; // edi

  v2 = 0;
  if ( *((_DWORD *)this + 8) )
  {
    if ( *((_DWORD *)this + 12) )
    {
      do
        CSessionCacheTable::ExpireItemsBoundToCred((CSessionCacheTable *)(*((_QWORD *)this + 5) + 152i64 * v2++), a2);
      while ( v2 < *((_DWORD *)this + 12) );
    }
    CSessionCacheManager::CacheExpireElements(this, 0, 0);
  }
}

