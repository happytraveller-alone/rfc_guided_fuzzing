//----- (000000018000F3F4) ----------------------------------------------------
__int64 __fastcall GenerateRemoteEndpointBindingsHash(__int64 a1, unsigned __int8 **a2, unsigned int *a3)
{
  DWORD CertEndpointBindings; // ebx
  PCCERT_CONTEXT pCertContext; // [rsp+30h] [rbp+8h] BYREF

  *a2 = 0i64;
  *a3 = 0;
  pCertContext = 0i64;
  if ( (*(_DWORD *)(a1 + 24) & 0x40051555) != 0 || !*(_QWORD *)(a1 + 152) )
    return 0i64;
  CertEndpointBindings = SPLoadCertificate(*(unsigned __int8 **)(a1 + 152), *(_DWORD *)(a1 + 160), &pCertContext);
  if ( !CertEndpointBindings )
  {
    CertEndpointBindings = GetCertEndpointBindings(pCertContext, a2, a3);
    CertFreeCertificateContext(pCertContext);
  }
  return CertEndpointBindings;
}

