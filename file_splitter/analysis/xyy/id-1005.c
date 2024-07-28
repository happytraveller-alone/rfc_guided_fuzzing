//----- (0000000180054118) ----------------------------------------------------
__int64 __fastcall GetEndpointCerts(HCERTSTORE hCertStore, struct LSA_SCHANNEL_SUB_CRED *a2, unsigned int *a3)
{
  unsigned int v3; // ebx
  const CERT_CONTEXT *i; // rax
  const CERT_CONTEXT *pPrevCertContext; // rdi

  v3 = 0;
  for ( i = CertFindCertificateInStore(hCertStore, 1u, 0, 0x150000u, 0i64, 0i64);
        ;
        i = CertFindCertificateInStore(hCertStore, 1u, 0, 0x150000u, 0i64, pPrevCertContext) )
  {
    pPrevCertContext = i;
    if ( !i )
      break;
    if ( (unsigned int)CertHasServerAuthEku(i) )
    {
      if ( a2 )
        *((_QWORD *)a2 + 7 * v3) = CertDuplicateCertificateContext(pPrevCertContext);
      ++v3;
    }
    else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids);
    }
  }
  if ( a3 )
    *a3 = v3;
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
