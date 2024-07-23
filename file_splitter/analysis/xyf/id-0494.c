//----- (00000001800237C0) ----------------------------------------------------
__int64 __fastcall CCipherMill::BuildCipherMill(CCipherMill *this)
{
  CCipherMill *v1; // rcx
  CCipherMill *v2; // rcx
  unsigned int ProviderList; // ebx
  CCipherMill *v5; // [rsp+40h] [rbp+8h] BYREF

  v5 = this;
  if ( !g_cCipherMill[0] )
    return 14i64;
  if ( CSessionCacheManager::m_pSessionCacheManager )
    CSessionCacheManager::PurgeCacheEntries(CSessionCacheManager::m_pSessionCacheManager, 0x30000u, 0i64, 0, 0i64);
  RtlAcquireResourceExclusive(&Resource, 1u);
  CCipherMill::ClearCipherMill(v1, 0);
  ProviderList = CCipherMill::LoadProviderList(v2, (unsigned __int8 *)&v5);
  if ( ProviderList
    || !hProvider
    && (ProviderList = NCryptOpenStorageProvider(&hProvider, L"Microsoft Software Key Storage Provider", 0)) != 0
    || (ProviderList = CCipherMill::LoadCipherTables((CCipherMill *)g_cCipherMill)) != 0 )
  {
    RtlReleaseResource(&Resource);
  }
  else
  {
    RtlReleaseResource(&Resource);
    if ( CSessionCacheManager::m_pSessionCacheManager )
      CSessionCacheManager::PurgeCacheEntries(CSessionCacheManager::m_pSessionCacheManager, 0x30000u, 0i64, 0, 0i64);
    if ( (_BYTE)v5 )
    {
      if ( CSslCredManager::m_pCredManager )
        CSslCredManager::NotifyProviderChange(CSslCredManager::m_pCredManager);
    }
  }
  return ProviderList;
}
// 1800237FE: variable 'v1' is possibly undefined
// 180023808: variable 'v2' is possibly undefined

