//----- (0000000180010CF8) ----------------------------------------------------
void __fastcall FreeSchannelCred(struct LSA_SCHANNEL_CRED *a1, char a2)
{
  void *v4; // rcx
  void *v5; // rcx
  struct _TLS_PARAMETERS *v6; // rcx
  unsigned int i; // ebp
  __int64 v8; // rsi
  _WORD *v9; // rdi
  __int64 v10; // rcx
  void *v11; // rcx
  void *v12; // rcx
  void *v13; // rcx
  void *v14; // rcx

  if ( *((_QWORD *)a1 + 1) )
  {
    for ( i = 0; i < *((_DWORD *)a1 + 1); *(_QWORD *)(v8 + 48) = 0i64 )
    {
      v8 = *((_QWORD *)a1 + 1) + 56i64 * i;
      if ( *(_QWORD *)v8 )
        CertFreeCertificateContext(*(PCCERT_CONTEXT *)v8);
      v9 = *(_WORD **)(v8 + 8);
      if ( v9 )
      {
        v10 = -1i64;
        do
          ++v10;
        while ( v9[v10] );
        memset(v9, 0, 2 * v10);
        SPExternalFree(*(void **)(v8 + 8));
      }
      *(_OWORD *)v8 = 0i64;
      ++i;
      *(_OWORD *)(v8 + 16) = 0i64;
      *(_OWORD *)(v8 + 32) = 0i64;
    }
    SPExternalFree(*((void **)a1 + 1));
    *((_QWORD *)a1 + 1) = 0i64;
  }
  v4 = (void *)*((_QWORD *)a1 + 2);
  if ( v4 )
  {
    CertCloseStore(v4, 0);
    *((_QWORD *)a1 + 2) = 0i64;
  }
  v5 = (void *)*((_QWORD *)a1 + 8);
  if ( v5 )
  {
    SPExternalFree(v5);
    *((_QWORD *)a1 + 8) = 0i64;
  }
  v6 = (struct _TLS_PARAMETERS *)*((_QWORD *)a1 + 13);
  if ( v6 )
  {
    FreeTlsParameters(v6, *((_DWORD *)a1 + 24));
    *((_QWORD *)a1 + 13) = 0i64;
    *((_DWORD *)a1 + 24) = 0;
  }
  if ( a2 )
  {
    v11 = (void *)*((_QWORD *)a1 + 3);
    if ( v11 )
      CryptObjectLocatorFree(v11);
    v12 = (void *)*((_QWORD *)a1 + 4);
    if ( v12 )
      CertCloseStore(v12, 0);
    v13 = (void *)*((_QWORD *)a1 + 5);
    if ( v13 )
      CryptObjectLocatorFree(v13);
    v14 = (void *)*((_QWORD *)a1 + 6);
    if ( v14 )
      CertCloseStore(v14, 0);
  }
  memset(a1, 0, 0x70ui64);
}
// 180098018: using guessed type void __stdcall CryptObjectLocatorFree(void *);

