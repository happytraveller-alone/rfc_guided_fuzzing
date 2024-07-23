// File count: 983
// Total lines: 53
-----------------------------------------
DWORD __fastcall SpQueryNames(struct CSslUserContext *a1, struct _SecPkgContext_NamesW *a2)
{
  int v2; // ebx
  unsigned __int8 *v5; // rcx
  DWORD result; // eax
  PCCERT_CONTEXT v7; // rdi
  DWORD v8; // eax
  DWORD csz; // r14d
  SEC_WCHAR *v10; // rax
  PCCERT_CONTEXT pCertContext; // [rsp+40h] [rbp+8h] BYREF

  v2 = 0;
  pCertContext = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
  v5 = (unsigned __int8 *)*((_QWORD *)a1 + 19);
  if ( !v5 )
    return -2146893054;
  result = SPLoadCertificate(v5, *((_DWORD *)a1 + 40), &pCertContext);
  if ( !result )
  {
    v7 = pCertContext;
    v8 = CertNameToStrW(pCertContext->dwCertEncodingType, &pCertContext->pCertInfo->Subject, 0x20000003u, 0i64, 0);
    csz = v8;
    if ( v8 > 1 )
    {
      v10 = (SEC_WCHAR *)LocalAlloc(0x40u, 2 * v8);
      a2->sUserName = v10;
      if ( v10 )
      {
        if ( CertNameToStrW(v7->dwCertEncodingType, &v7->pCertInfo->Subject, 0x20000003u, v10, csz) <= 1 )
        {
          CertFreeCertificateContext(v7);
          LocalFree(a2->sUserName);
          return -2146893054;
        }
      }
      else
      {
        v2 = -2146893056;
      }
    }
    else
    {
      v2 = -2146893054;
    }
    CertFreeCertificateContext(v7);
    return v2;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
