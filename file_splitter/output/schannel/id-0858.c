//----- (0000000180045F80) ----------------------------------------------------
void __stdcall SslFreeCertificate(PX509Certificate pCertificate)
{
  if ( pCertificate )
  {
    SPExternalFree(pCertificate->pPublicKey);
    SPExternalFree(pCertificate);
  }
}

