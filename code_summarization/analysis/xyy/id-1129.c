//----- (000000018005B8B4) ----------------------------------------------------
DTLSCookieManager *__fastcall DTLSCookieManager::`scalar deleting destructor'(DTLSCookieManager *this)
{
  DTLSCookieManager::~DTLSCookieManager(this);
  operator delete(this);
  return this;
}

