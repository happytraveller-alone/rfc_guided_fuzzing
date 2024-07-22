//----- (00000001800555A0) ----------------------------------------------------
char __fastcall CCredentialGroup::CheckForValidIssuer(CCredentialGroup *this, const struct _CERT_CHAIN_CONTEXT *a2)
{
  struct _RTL_RESOURCE *v2; // r12
  unsigned __int8 *v5; // rdi
  char v6; // bl
  __int64 v7; // rbp
  unsigned __int64 v8; // r13
  PCERT_SIMPLE_CHAIN v9; // r15
  int v10; // r14d
  PCCERT_CONTEXT pCertContext; // rax
  _BYTE *v12; // rsi
  struct _CRYPTOAPI_BLOB pCertName2; // [rsp+20h] [rbp-38h] BYREF

  v2 = (struct _RTL_RESOURCE *)((char *)this + 48);
  pCertName2 = 0i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
  v5 = (unsigned __int8 *)*((_QWORD *)this + 108);
  v6 = 0;
  if ( v5 )
  {
    v7 = *((unsigned int *)this + 214);
    if ( (unsigned int)v7 >= 2 )
    {
      v8 = (unsigned __int64)&v5[v7];
      v9 = *a2->rgpChain;
      while ( 1 )
      {
        v12 = v5 + 1;
        if ( (unsigned __int64)(v5 + 1) >= v8 )
          break;
        pCertName2.pbData = v5 + 2;
        LOBYTE(pCertName2.cbData) = *v12;
        BYTE1(pCertName2.cbData) = *v5;
        if ( pCertName2.cbData > (unsigned int)v7 )
          break;
        v10 = 0;
        if ( v9->cElement )
        {
          while ( 1 )
          {
            pCertContext = v9->rgpElement[v10]->pCertContext;
            if ( CertCompareCertificateName(
                   pCertContext->dwCertEncodingType,
                   &pCertContext->pCertInfo->Issuer,
                   &pCertName2) )
            {
              break;
            }
            if ( ++v10 >= v9->cElement )
              goto LABEL_14;
          }
          v6 = 1;
          break;
        }
LABEL_14:
        v5 += ((unsigned __int8)*v12 | ((unsigned __int64)*v5 << 8)) + 2;
      }
    }
    else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    {
      WPP_SF_d(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x27u,
        (__int64)&WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids,
        v7);
    }
  }
  else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 38i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids);
  }
  RtlReleaseResource(v2);
  return v6;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;

