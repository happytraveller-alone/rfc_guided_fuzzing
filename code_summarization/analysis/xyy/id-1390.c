//----- (000000018006EC64) ----------------------------------------------------
__int64 __fastcall CTls13ClientContext::SetCertificateRequestContext(
        CTls13ClientContext *this,
        unsigned __int8 *a2,
        unsigned __int8 a3)
{
  size_t v4; // rbx
  HLOCAL v6; // rax

  v4 = a3;
  CTls13Context::FreeCertificateRequestContext((CTls13ClientContext *)((char *)this + 1368));
  if ( a2 && (_BYTE)v4 )
  {
    v6 = SPExternalAlloc(v4);
    *((_QWORD *)this + 199) = v6;
    if ( !v6 )
      return 2148074240i64;
    *((_BYTE *)this + 1600) = v4;
    memcpy_0(v6, a2, v4);
  }
  return 0i64;
}
