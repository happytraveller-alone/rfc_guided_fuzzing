//----- (0000000180042800) ----------------------------------------------------
__int64 __fastcall MapKernelAuthDataV5(
        struct _SCHANNEL_CRED *a1,
        struct _UNICODE_STRING *a2,
        void *a3,
        struct LSA_SCHANNEL_CRED *a4)
{
  unsigned int ImplicitCredentials; // ebx
  unsigned int paCred; // ecx
  int v8; // eax
  struct _TLS_PARAMETERS **v10; // [rsp+20h] [rbp-18h]

  *(_DWORD *)a4 = 5;
  if ( a2 && a2->Buffer )
  {
    ImplicitCredentials = LoadImplicitCredentials(a2, (__int64)a3, a4);
    if ( ImplicitCredentials )
      goto LABEL_11;
  }
  else
  {
    paCred = (unsigned int)a1->paCred;
    if ( paCred )
    {
      ImplicitCredentials = LoadCredentialsFromLocalStore(
                              paCred,
                              (const struct _CERT_CONTEXT **)a1->hRootStore,
                              a1->cCreds,
                              a3,
                              a4);
      if ( ImplicitCredentials )
        goto LABEL_11;
      *((_DWORD *)a4 + 1) = a1->paCred;
    }
  }
  v8 = CopyTlsParameters(
         *(struct _TLS_PARAMETERS **)&a1->dwMaximumCipherStrength,
         a1->grbitEnabledProtocols,
         0,
         0,
         (struct _TLS_PARAMETERS **)a4 + 13,
         (unsigned int *)a4 + 24);
  if ( !v8 )
  {
    ImplicitCredentials = 0;
    *((_DWORD *)a4 + 21) = a1->palgSupportedAlgs;
    *((_DWORD *)a4 + 22) = HIDWORD(a1->palgSupportedAlgs);
    *((_DWORD *)a4 + 23) = a1->cCreds;
    goto LABEL_13;
  }
  ImplicitCredentials = 14;
  if ( v8 == -2146892963 )
    ImplicitCredentials = 87;
LABEL_11:
  FreeSchannelCred(a4, 1);
LABEL_13:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && ImplicitCredentials
     || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(v10) = ImplicitCredentials;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x31u,
      (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
      ImplicitCredentials,
      v10);
  }
  return ImplicitCredentials;
}
// 1800428FA: variable 'v10' is possibly undefined
