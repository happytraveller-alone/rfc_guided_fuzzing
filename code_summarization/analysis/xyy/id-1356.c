//----- (000000018006AFC8) ----------------------------------------------------
void __fastcall CTls13Context::FreeCertificateRequestContext(CTls13Context *this)
{
  void *v2; // rcx

  v2 = (void *)*((_QWORD *)this + 28);
  if ( v2 )
  {
    SPExternalFree(v2);
    *((_QWORD *)this + 28) = 0i64;
  }
  *((_BYTE *)this + 232) = 0;
}
