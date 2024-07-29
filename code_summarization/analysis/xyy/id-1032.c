//----- (0000000180056618) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::NotifyProviderChange(CCredentialGroup *this)
{
  CCredentialGroup *v2; // r14
  __int64 v3; // rbx
  char *v4; // rsi

  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
  v2 = (CCredentialGroup *)*((_QWORD *)this + 4);
  while ( v2 != (CCredentialGroup *)((char *)this + 32) )
  {
    v3 = *((_QWORD *)this + 94);
    v4 = (char *)v2 - 8;
    v2 = *(CCredentialGroup **)v2;
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v4 + 552), 1u);
    CSslCredential::DeleteLocalServerKeys((CSslCredential *)v4);
    CSslCredential::GetLocalServerKeyFromProvider((const struct _CERT_CONTEXT **)v4, v3);
    RtlReleaseResource((PRTL_RESOURCE)(v4 + 552));
  }
  RtlReleaseResource((PRTL_RESOURCE)((char *)this + 48));
  return 0i64;
}
