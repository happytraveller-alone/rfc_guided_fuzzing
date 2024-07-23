// File count: 1037
// Total lines: 49
----------------------------------------
__int64 __fastcall CCredentialGroup::RenewLocalStoreCertificates(CCredentialGroup *this)
{
  char *v1; // rdi
  char *v2; // rbx
  char *v4; // rsi
  const CERT_CONTEXT *v5; // rsi
  unsigned int RenewedCredential; // eax
  __int128 v8[3]; // [rsp+20h] [rbp-48h] BYREF
  __int64 v9; // [rsp+50h] [rbp-18h]
  PCCERT_CONTEXT pCertContext; // [rsp+70h] [rbp+8h] BYREF

  pCertContext = 0i64;
  v1 = (char *)this + 32;
  v2 = (char *)*((_QWORD *)this + 4);
  while ( v2 != v1 )
  {
    v4 = v2;
    v2 = *(char **)v2;
    if ( (*((_DWORD *)v4 + 4) & 0x21) == 32
      && (unsigned int)CheckForLocalStoreCertificateRenewal(
                         *((HCERTSTORE *)CSslCredManager::m_pCredManager + 9),
                         *((PCCERT_CONTEXT *)v4 + 3),
                         1,
                         &pCertContext) )
    {
      *((_DWORD *)v4 + 4) |= 1u;
      v5 = pCertContext;
      v8[0] = (unsigned __int64)pCertContext;
      v9 = 1i64;
      memset(&v8[1], 0, 32);
      RenewedCredential = CCredentialGroup::CreateRenewedCredential(this, (struct LSA_SCHANNEL_SUB_CRED *)v8);
      if ( RenewedCredential
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          28i64,
          &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids,
          RenewedCredential);
      }
      CertFreeCertificateContext(v5);
    }
  }
  return 0i64;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
