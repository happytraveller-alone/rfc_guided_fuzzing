//----- (0000000180053738) ----------------------------------------------------
__int64 __fastcall CertHasServerAuthEku(PCCERT_CONTEXT pCertContext)
{
  unsigned int EnhancedKeyUsage; // ebx
  struct _CTL_USAGE *v3; // rax
  struct _CTL_USAGE *v4; // rdi
  __int64 v5; // rsi
  LPSTR *rgpszUsageIdentifier; // r14
  DWORD pcbUsage; // [rsp+38h] [rbp+10h] BYREF

  pcbUsage = 0;
  EnhancedKeyUsage = CertGetEnhancedKeyUsage(pCertContext, 2u, 0i64, &pcbUsage);
  if ( EnhancedKeyUsage )
  {
    v3 = (struct _CTL_USAGE *)SPExternalAlloc(pcbUsage);
    v4 = v3;
    if ( v3 )
    {
      EnhancedKeyUsage = CertGetEnhancedKeyUsage(pCertContext, 2u, v3, &pcbUsage);
      if ( EnhancedKeyUsage )
      {
        v5 = 0i64;
        if ( v4->cUsageIdentifier )
        {
          rgpszUsageIdentifier = v4->rgpszUsageIdentifier;
          EnhancedKeyUsage = 1;
          while ( strcmp_0(rgpszUsageIdentifier[v5], "1.3.6.1.5.5.7.3.1") )
          {
            v5 = (unsigned int)(v5 + 1);
            if ( (unsigned int)v5 >= v4->cUsageIdentifier )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          EnhancedKeyUsage = 0;
        }
      }
      else
      {
        GetLastError();
      }
      SPExternalFree(v4);
    }
  }
  else
  {
    GetLastError();
  }
  return EnhancedKeyUsage;
}

