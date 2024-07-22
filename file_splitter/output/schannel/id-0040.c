//----- (0000000180003C24) ----------------------------------------------------
void __fastcall CSessionCacheItem::ClearState(CSessionCacheItem *this)
{
  __int64 v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  const CERT_CONTEXT *v5; // rcx
  void *v6; // rcx
  __int64 v7; // rdi
  __int64 v8; // rcx
  void *v9; // rcx

  v2 = *((_QWORD *)this + 2);
  if ( v2 )
    SslFreeObject(v2, 0i64);
  v3 = (void *)*((_QWORD *)this + 3);
  if ( v3 )
    SPExternalFree(v3);
  v4 = (void *)*((_QWORD *)this + 5);
  if ( v4 )
    SPExternalFree(v4);
  v5 = (const CERT_CONTEXT *)*((_QWORD *)this + 6);
  if ( v5 )
    CertFreeCertificateContext(v5);
  v6 = (void *)*((_QWORD *)this + 7);
  if ( v6 )
    SPExternalFree(v6);
  v7 = *((_QWORD *)this + 22);
  if ( v7 )
  {
    v8 = *(_QWORD *)(v7 + 848);
    if ( v8 )
      CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v8 + 16));
    CMasterCipherInfo::Dereference(*(CMasterCipherInfo **)(v7 + 856));
  }
  v9 = (void *)*((_QWORD *)this + 25);
  if ( v9 )
    SPExternalFree(v9);
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

