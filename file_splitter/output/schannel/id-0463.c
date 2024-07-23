// File count: 463
// Total lines: 24
-----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::LookupEccCurveType(CSsl3TlsServerContext *this, int a2)
{
  unsigned __int16 *v2; // rax
  __int64 v3; // r9
  unsigned __int16 *v4; // r8

  v2 = (unsigned __int16 *)*((_QWORD *)this + 114);
  v3 = *((unsigned __int16 *)this + 460);
  v4 = &v2[v3];
  if ( v2 < v4 )
  {
    while ( *v2 != a2 )
    {
      if ( ++v2 >= v4 )
        goto LABEL_6;
    }
    return 0i64;
  }
LABEL_6:
  if ( !(_WORD)v3 )
    return 0i64;
  return 50i64;
}
