// File count: 18
// Total lines: 25
------------------------------------------
void __fastcall CSsl3TlsContext::FreeTlsClientAuthHandshakeHashes(CSsl3TlsContext *this)
{
  unsigned int v2; // edi
  __int64 v3; // rcx

  *((_DWORD *)this + 180) = 0;
  if ( *((_DWORD *)this + 137) > 1u )
  {
    v2 = 1;
    do
    {
      v3 = *((_QWORD *)this + v2 + 74);
      if ( v3 )
      {
        SslFreeObject(v3, 0i64);
        *((_QWORD *)this + v2 + 74) = 0i64;
      }
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 137) );
    *((_DWORD *)this + 137) = 1;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
