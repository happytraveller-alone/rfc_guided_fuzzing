//----- (00000001800439C4) ----------------------------------------------------
__int64 __fastcall SetClientCertPolicy(
        struct CCredentialGroup *a1,
        struct _SecPkgCred_ClientCertPolicy *a2,
        unsigned int a3)
{
  struct CLIENT_CERT_POLICY *v3; // rbx
  __int64 result; // rax
  struct CLIENT_CERT_POLICY *v7; // rax
  struct CLIENT_CERT_POLICY *v8; // rdi
  CCredentialGroup *v9; // rcx
  unsigned int v10; // ebp
  void *v11; // rdx

  v3 = 0i64;
  if ( !a3 || (result = VerifyClientCertPolicyBuffer((char *)a2, a3), !(_DWORD)result) )
  {
    v7 = (struct CLIENT_CERT_POLICY *)SPExternalAlloc(0x38u);
    v8 = v7;
    if ( v7 )
    {
      v10 = InitializeClientCertPolicy(a2, v7);
      if ( v10 )
      {
        SPExternalFree(v8);
      }
      else
      {
        v11 = (void *)*((_QWORD *)a1 + 102);
        if ( v11 )
        {
          if ( *((_QWORD *)a1 + 103) )
            CCredentialGroup::UnsubscribeCertStoreChangeNotification(v9, v11, (void **)a1 + 103);
        }
        *((_QWORD *)a1 + 102) = *((_QWORD *)v8 + 6);
        *((_QWORD *)v8 + 6) = 0i64;
        v3 = v8;
      }
      *((_QWORD *)a1 + 106) = v3;
      return v10;
    }
    else
    {
      return 2148074240i64;
    }
  }
  return result;
}
// 180043A40: variable 'v9' is possibly undefined

