// File count: 278
// Total lines: 15
-----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::GetPeerCertValidationResults(
        CSsl3TlsClientContext *this,
        int *a2,
        unsigned int *a3)
{
  __int64 v3; // rcx

  if ( !a2 || !a3 )
    return 87i64;
  v3 = *((_QWORD *)this + 11);
  *a2 = *(_DWORD *)(v3 + 216);
  *a3 = *(_DWORD *)(v3 + 220);
  return 0i64;
}
