// File count: 1125
// Total lines: 21
----------------------------------------
unsigned __int64 __fastcall CSsl3TlsContext::FindTlsClientAuthHandshakeHash(
        CSsl3TlsContext *this,
        enum _eTlsHashAlgorithm a2)
{
  unsigned int v2; // r9d
  __int64 v3; // rax
  _DWORD *i; // r8

  v2 = *((_DWORD *)this + 137);
  v3 = 0i64;
  if ( !v2 )
    return 0i64;
  for ( i = (_DWORD *)((char *)this + 720); *i != a2; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= v2 )
      return 0i64;
  }
  return *((_QWORD *)this + v3 + 74);
}
