// File count: 1016
// Total lines: 17
----------------------------------------
void CSslGlobals::CleanupCryptLocatorHandles(void)
{
  if ( CSslGlobals::m_hCertLocator )
  {
    CryptObjectLocatorRelease(1u, CSslGlobals::m_hCertLocator);
    CSslGlobals::m_hCertLocator = 0i64;
  }
  if ( CSslGlobals::m_hIssuersLocator )
  {
    CryptObjectLocatorRelease(1u, CSslGlobals::m_hIssuersLocator);
    CSslGlobals::m_hIssuersLocator = 0i64;
  }
}
// 180092F60: using guessed type void *CSslGlobals::m_hIssuersLocator;
// 180092F68: using guessed type void *CSslGlobals::m_hCertLocator;
// 180098198: using guessed type void __stdcall CryptObjectLocatorRelease(unsigned int, void *);
