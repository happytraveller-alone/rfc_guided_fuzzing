// File count: 472
// Total lines: 26
-----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::GetPeerCertValidationResults(
        CSsl3TlsServerContext *this,
        int *a2,
        unsigned int *a3)
{
  __int64 v3; // rcx
  __int64 result; // rax

  if ( !a2 || !a3 )
    return 87i64;
  if ( *(_QWORD *)(*((_QWORD *)this + 10) + 848i64) )
  {
    v3 = *((_QWORD *)this + 124);
    *a2 = *(_DWORD *)(v3 + 216);
    *a3 = *(_DWORD *)(v3 + 220);
    return 0i64;
  }
  else
  {
    result = 0i64;
    *a2 = 0;
    *a3 = 0;
  }
  return result;
}
