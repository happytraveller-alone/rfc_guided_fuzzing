// File count: 225
// Total lines: 137
----------------------------------------
void __fastcall CCredentialGroup::DeleteCredentialGroup(CCredentialGroup *this)
{
  struct _RTL_RESOURCE *v2; // rbp
  void *v3; // rcx
  struct _TLS_PARAMETERS *v4; // rcx
  void *v5; // rcx
  _QWORD *v6; // rdi
  CCredentialGroup *v7; // rcx
  void *v8; // rcx
  void *v9; // rcx
  void *v10; // rcx
  void *v11; // rcx
  CCredentialGroup *v12; // rcx
  CCredentialGroup *v13; // rcx
  void *v14; // rcx
  void *v15; // rcx
  _QWORD *v16; // rsi
  _QWORD *v17; // rdi
  _QWORD *v18; // rcx
  const CTL_CONTEXT *v19; // rcx
  CCredentialGroup *v20; // rcx
  int v21; // [rsp+40h] [rbp+8h] BYREF

  v21 = 0;
  if ( *((_DWORD *)this + 36) )
  {
    v2 = (struct _RTL_RESOURCE *)((char *)this + 48);
    RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
    if ( *((_DWORD *)this + 7) )
    {
      v16 = (_QWORD *)((char *)this + 32);
      v17 = (_QWORD *)*((_QWORD *)this + 4);
      while ( v17 != v16 )
      {
        v18 = v17 - 1;
        v17 = (_QWORD *)*v17;
        if ( v18 )
          (*(void (__fastcall **)(_QWORD *, __int64))(*v18 + 8i64))(v18, 1i64);
      }
      *((_DWORD *)this + 7) = 0;
      *v16 = 0i64;
      *((_QWORD *)this + 5) = 0i64;
    }
    v3 = (void *)*((_QWORD *)this + 23);
    if ( v3 )
      SPExternalFree(v3);
    v4 = (struct _TLS_PARAMETERS *)*((_QWORD *)this + 25);
    if ( v4 )
    {
      FreeTlsParameters(v4, *((_DWORD *)this + 49));
      *((_QWORD *)this + 25) = 0i64;
      *((_DWORD *)this + 49) = 0;
    }
    v5 = (void *)*((_QWORD *)this + 108);
    if ( v5 )
      LocalFree(v5);
    v6 = (_QWORD *)*((_QWORD *)this + 106);
    if ( v6 )
    {
      v19 = (const CTL_CONTEXT *)v6[5];
      if ( v19 )
        CertFreeCTLContext(v19);
      SPExternalFree(v6);
    }
    v7 = (CCredentialGroup *)*((_QWORD *)this + 96);
    if ( v7 )
    {
      if ( *((_QWORD *)this + 97) )
      {
        CCredentialGroup::UnsubscribeCertStoreChangeNotification(v7, *((void **)this + 96), (void **)this + 97);
        v7 = (CCredentialGroup *)*((_QWORD *)this + 96);
      }
      CertCloseStore(v7, 0);
    }
    v8 = (void *)*((_QWORD *)this + 109);
    if ( v8 )
      SPExternalFree(v8);
    v9 = (void *)*((_QWORD *)this + 110);
    if ( v9 )
      SPExternalFree(v9);
    if ( *((_QWORD *)this + 98) )
    {
      if ( !SslImpersonateClient(*((_QWORD *)this + 94), &v21) && *((_QWORD *)this + 99) )
        CCredentialGroup::UnsubscribeCertStoreChangeNotification(v20, *((void **)this + 98), (void **)this + 99);
      CertCloseStore(*((HCERTSTORE *)this + 98), 0);
      if ( v21 )
        RevertToSelf();
    }
    v10 = (void *)*((_QWORD *)this + 100);
    if ( v10 )
      CryptObjectLocatorFree(v10);
    v11 = (void *)*((_QWORD *)this + 101);
    if ( v11 )
      CryptObjectLocatorFree(v11);
    v12 = (CCredentialGroup *)*((_QWORD *)this + 102);
    if ( v12 )
    {
      if ( *((_QWORD *)this + 103) )
      {
        CCredentialGroup::UnsubscribeCertStoreChangeNotification(v12, *((void **)this + 102), (void **)this + 103);
        v12 = (CCredentialGroup *)*((_QWORD *)this + 102);
      }
      CertCloseStore(v12, 0);
    }
    v13 = (CCredentialGroup *)*((_QWORD *)this + 104);
    if ( v13 )
    {
      if ( *((_QWORD *)this + 105) )
      {
        CCredentialGroup::UnsubscribeCertStoreChangeNotification(v13, *((void **)this + 104), (void **)this + 105);
        v13 = (CCredentialGroup *)*((_QWORD *)this + 104);
      }
      CertCloseStore(v13, 0);
    }
    v14 = (void *)*((_QWORD *)this + 94);
    if ( v14 )
    {
      NtClose(v14);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_q(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x18u,
          (__int64)&WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids,
          *((_QWORD *)this + 94));
      *((_QWORD *)this + 94) = 0i64;
    }
    v15 = (void *)*((_QWORD *)this + 111);
    if ( v15 )
      LocalFree(v15);
    RtlReleaseResource(v2);
    RtlDeleteResource(v2);
  }
}
// 18003C915: variable 'v20' is possibly undefined
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
// 180098018: using guessed type void __stdcall CryptObjectLocatorFree(void *);
