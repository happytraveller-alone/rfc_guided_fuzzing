//----- (000000018005BA0C) ----------------------------------------------------
__int64 __fastcall DTLSCookieManager::ResetSecret(PUCHAR *this)
{
  signed int RandomBits; // ebx

  if ( DTLSCookieManager::m_pCookieMgr )
  {
    RandomBits = GenerateRandomBits(this[1], *(_DWORD *)this);
    if ( RandomBits >= 0 )
      this[7] = (PUCHAR)GetTickCount64();
  }
  else
  {
    return 12;
  }
  return (unsigned int)RandomBits;
}
