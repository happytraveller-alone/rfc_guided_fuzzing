//----- (00000001800525EC) ----------------------------------------------------
__int64 __fastcall SpQueryLifespan(struct CSslUserContext *a1, struct _SecPkgContext_Lifespan *a2)
{
  unsigned __int8 *v4; // rcx
  PCCERT_CONTEXT v6; // rcx
  PCCERT_CONTEXT pCertContext; // [rsp+30h] [rbp+8h] BYREF

  pCertContext = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
  v4 = (unsigned __int8 *)*((_QWORD *)a1 + 19);
  if ( v4 )
  {
    if ( SPLoadCertificate(v4, *((_DWORD *)a1 + 40), &pCertContext) )
      return 2148074240i64;
    v6 = pCertContext;
    a2->tsStart.QuadPart = (LONGLONG)pCertContext->pCertInfo->NotBefore;
    a2->tsExpiry.QuadPart = (LONGLONG)v6->pCertInfo->NotAfter;
    CertFreeCertificateContext(v6);
  }
  else
  {
    a2->tsStart.QuadPart = 0i64;
    a2->tsExpiry.QuadPart = 0x7FFFFF36D5969FFFi64;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
