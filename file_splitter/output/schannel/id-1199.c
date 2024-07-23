// File count: 1199
// Total lines: 76
----------------------------------------
void __fastcall CSslCredential::DeleteCredential(CSslCredential *this)
{
  void *v2; // rcx
  void *v3; // rcx
  const CERT_CHAIN_CONTEXT *v4; // rcx
  CERT_CONTEXT *v5; // rcx
  CSslCredential *v6; // rcx
  CSslCredential *v7; // rcx
  void **v8; // rsi
  void *v9; // rdi
  void **v10; // rax
  __int64 v11; // rdx
  int v12; // r8d
  NCRYPT_HANDLE v13; // rcx
  void *v14; // rcx
  void *v15; // rcx
  void *v16; // rcx
  void *v17; // rcx

  v2 = (void *)*((_QWORD *)this + 54);
  if ( v2 )
    SPExternalFree(v2);
  v3 = (void *)*((_QWORD *)this + 57);
  if ( v3 )
    CertCloseServerOcspResponse(v3, 0);
  v4 = (const CERT_CHAIN_CONTEXT *)*((_QWORD *)this + 8);
  if ( v4 )
    CertFreeCertificateChain(v4);
  v5 = (CERT_CONTEXT *)*((_QWORD *)this + 4);
  if ( v5 )
    CertFreeCertificateContext(v5);
  CSslCredential::ReleaseEphemeralKeyData((CSslCredential *)v5, *((struct CEphemKeyData **)this + 62));
  CSslCredential::ReleaseEphemeralKeyData(v6, *((struct CEphemKeyData **)this + 63));
  v8 = (void **)((char *)this + 480);
  while ( 1 )
  {
    v9 = *v8;
    if ( *v8 == v8 )
      break;
    if ( *((void ***)v9 + 1) != v8 || (v10 = *(void ***)v9, *(void **)(*(_QWORD *)v9 + 8i64) != v9) )
      __fastfail(3u);
    *v8 = v10;
    v10[1] = v8;
    CSslCredential::ReleaseEphemeralKeyData(v7, *((struct CEphemKeyData **)v9 + 3));
    LocalFree(v9);
  }
  CSslCredential::DeleteLocalServerKeys(this);
  if ( !*((_BYTE *)this + 120) )
    CSslCredential::RemoteCloseKeyHandle(this, v11, v12);
  if ( !*((_BYTE *)this + 78) )
  {
    v13 = *((_QWORD *)this + 13);
    if ( v13 )
      NCryptFreeObject(v13);
  }
  v14 = (void *)*((_QWORD *)this + 55);
  if ( v14 )
    SPExternalFree(v14);
  v15 = (void *)*((_QWORD *)this + 52);
  if ( v15 )
    SPExternalFree(v15);
  v16 = (void *)*((_QWORD *)this + 50);
  if ( v16 )
    SPExternalFree(v16);
  v17 = (void *)*((_QWORD *)this + 58);
  if ( v17 )
    SPExternalFree(v17);
  if ( *((_BYTE *)this + 648) )
    RtlDeleteResource((PRTL_RESOURCE)((char *)this + 552));
}
// 18005F356: variable 'v5' is possibly undefined
// 18005F362: variable 'v6' is possibly undefined
// 18005F390: variable 'v7' is possibly undefined
// 18005F3BE: variable 'v11' is possibly undefined
// 18005F3BE: variable 'v12' is possibly undefined
