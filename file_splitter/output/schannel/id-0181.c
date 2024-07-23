// File count: 181
// Total lines: 62
-----------------------------------------
DWORD __fastcall SPLoadCertificate(unsigned __int8 *a1, DWORD LastError, const struct _CERT_CONTEXT **a3)
{
  HCERTSTORE v6; // r14
  int v7; // r15d
  __int64 v8; // rbp
  unsigned int v9; // ebx
  const BYTE *v10; // rsi
  PCCERT_CONTEXT pCertContext; // [rsp+60h] [rbp+18h] BYREF

  pCertContext = 0i64;
  if ( !a3 )
    return -2146893052;
  if ( *a3 )
    CertFreeCertificateContext(*a3);
  *a3 = 0i64;
  v6 = CertOpenStore((LPCSTR)2, 0, 0i64, 4u, 0i64);
  if ( !v6 )
    return GetLastError();
  v7 = 1;
  while ( LastError >= 4 )
  {
    v8 = *(unsigned int *)a1;
    v9 = LastError - 4;
    v10 = a1 + 4;
    if ( (unsigned int)v8 > v9 )
      break;
    if ( !CertAddEncodedCertificateToStore(v6, 1u, v10, v8, 2u, &pCertContext) )
    {
      LastError = GetLastError();
      goto LABEL_12;
    }
    a1 = (unsigned __int8 *)&v10[v8];
    LastError = v9 - v8;
    if ( v7 )
    {
      v7 = 0;
      *a3 = pCertContext;
    }
    else
    {
      CertFreeCertificateContext(pCertContext);
    }
    pCertContext = 0i64;
    if ( !LastError )
      goto LABEL_12;
  }
  LastError = -2146893052;
LABEL_12:
  CertCloseStore(v6, 0);
  if ( LastError )
  {
    if ( pCertContext )
      CertFreeCertificateContext(pCertContext);
    if ( *a3 )
    {
      CertFreeCertificateContext(*a3);
      *a3 = 0i64;
    }
  }
  return LastError;
}
