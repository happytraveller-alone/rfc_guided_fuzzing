// File count: 230
// Total lines: 22
-----------------------------------------
signed int __fastcall CSsl3TlsContext::QueryContextAttributesA(CSsl3TlsContext *this, int a2, void *a3)
{
  switch ( a2 )
  {
    case '"':
      return CSsl3TlsContext::QuerySupportedMTU(this, a3);
    case 'Y':
      return CSsl3TlsContext::QueryIssuerList(this, a3);
    case '[':
      return CSsl3TlsContext::QueryEapKeyBlock(this, a3);
    case 'f':
      return CSsl3TlsContext::QuerySupportedSignatures(this, a3);
    case 'g':
      return CSsl3TlsContext::QueryRemoteCertificateChain(this, (PCCERT_CONTEXT *)a3);
    case 'k':
      return (*(__int64 (__fastcall **)(CSsl3TlsContext *, void *))(*(_QWORD *)this + 480i64))(this, a3);
    case 'q':
      return CSsl3TlsContext::QueryCertificateValidationResult(this, a3);
  }
  return CSslContext::QueryContextAttributesA(this, a2, a3);
}
