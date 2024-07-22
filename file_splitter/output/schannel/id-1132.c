//----- (000000018005BA60) ----------------------------------------------------
__int64 __fastcall DTLSCookieManager::ValidateCookie(
        DTLSCookieManager *this,
        unsigned __int8 *const a2,
        ULONG a3,
        unsigned __int8 *const a4,
        unsigned int a5,
        unsigned __int8 *const a6,
        unsigned int a7)
{
  unsigned int v8; // ebx
  __int128 Buf2[2]; // [rsp+40h] [rbp-48h] BYREF

  memset(Buf2, 0, sizeof(Buf2));
  v8 = 0;
  if ( (int)DTLSCookieManager::ComputeCookie(this, a2, a3, a4, a5, a6, a7, (unsigned __int8 *)Buf2) < 0 )
    return 0i64;
  LOBYTE(v8) = memcmp_0(a4 - 32, Buf2, 0x20ui64) == 0;
  return v8;
}

