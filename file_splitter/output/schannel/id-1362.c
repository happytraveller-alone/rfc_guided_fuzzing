// File count: 1362
// Total lines: 13
----------------------------------------
ULONG __fastcall CTls13ServerContext::GenerateCertificateRequestContext(CTls13ServerContext *this)
{
  UCHAR *v2; // rax

  CTls13Context::FreeCertificateRequestContext((CTls13ServerContext *)((char *)this + 1000));
  v2 = (UCHAR *)SPExternalAlloc(0x20u);
  *((_QWORD *)this + 153) = v2;
  if ( !v2 )
    return -2146893056;
  *((_BYTE *)this + 1232) = 32;
  return GenerateRandomBits(v2, 0x20u);
}
