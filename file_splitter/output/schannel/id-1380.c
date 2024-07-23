// File count: 1380
// Total lines: 14
----------------------------------------
__int64 __fastcall CTls13ServerContext::LookupEccCurveType(CTls13ServerContext *this, unsigned int a2)
{
  __int16 v2; // di
  __int64 result; // rax

  v2 = a2;
  if ( a2 > 0xFFFF )
    return 87i64;
  result = CSsl3TlsServerContext::LookupEccCurveType(this, a2);
  if ( !(_DWORD)result && *((_DWORD *)this + 16) == 4096 )
    return CTls13ServerContext::FindClientShare(this, v2, 0i64, 0i64);
  return result;
}
