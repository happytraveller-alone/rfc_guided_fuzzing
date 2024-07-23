// File count: 1033
// Total lines: 38
----------------------------------------
__int64 __fastcall CCredentialGroup::PickClientCredential(
        CCredentialGroup *this,
        int a2,
        int a3,
        struct CTlsSignatureSuiteList *a4,
        struct CSslCredential **a5)
{
  unsigned int v8; // ebx
  CCredentialGroup *v9; // rsi
  struct CSslCredential *v10; // r15

  v8 = -2146893007;
  if ( *((_DWORD *)this + 7) )
  {
    RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
    v9 = (CCredentialGroup *)*((_QWORD *)this + 4);
    while ( v9 != (CCredentialGroup *)((char *)this + 32) )
    {
      v10 = (CCredentialGroup *)((char *)v9 - 8);
      v9 = *(CCredentialGroup **)v9;
      if ( CSslCredential::IsClientCredApplicable(
             v10,
             a2,
             a3,
             a4,
             *((struct _TLS_PARAMETERS **)this + 25),
             *((_DWORD *)this + 49)) )
      {
        v8 = 0;
        *a5 = v10;
        break;
      }
    }
    RtlReleaseResource((PRTL_RESOURCE)((char *)this + 48));
  }
  return v8;
}
