//----- (0000000180054FC4) ----------------------------------------------------
void CSslGlobals::CleanupCryptLocatorEvents(void)
{
  if ( CSslGlobals::m_hImplicitCertChangeEvent )
  {
    CloseHandle(CSslGlobals::m_hImplicitCertChangeEvent);
    CSslGlobals::m_hImplicitCertChangeEvent = 0i64;
  }
  if ( CSslGlobals::m_hImplicitIssersChangeEvent )
  {
    CloseHandle(CSslGlobals::m_hImplicitIssersChangeEvent);
    CSslGlobals::m_hImplicitIssersChangeEvent = 0i64;
  }
}

