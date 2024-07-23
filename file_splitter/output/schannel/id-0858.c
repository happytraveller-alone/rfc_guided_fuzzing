// File count: 858
// Total lines: 9
------------------------------------------
void __stdcall SslFreeCertificate(PX509Certificate pCertificate)
{
  if ( pCertificate )
  {
    SPExternalFree(pCertificate->pPublicKey);
    SPExternalFree(pCertificate);
  }
}
