//----- (000000018000404C) ----------------------------------------------------
void __fastcall CSsl3TlsClientContext::SetDefCredSearched(__int64 a1, int a2)
{
  const CERT_CHAIN_CONTEXT *v3; // rcx

  *(_DWORD *)(a1 + 1048) = a2;
  v3 = *(const CERT_CHAIN_CONTEXT **)(a1 + 1040);
  if ( v3 )
    CertFreeCertificateChain(v3);
  *(_QWORD *)(a1 + 1040) = 0i64;
}

