//----- (0000000180003DF0) ----------------------------------------------------
void __fastcall CSsl3TlsContext::FreeHandshakeHash(CSsl3TlsContext *this)
{
  unsigned int v2; // edi
  char *v3; // rsi
  __int64 v4; // rcx

  v2 = 0;
  if ( *((_DWORD *)this + 137) )
  {
    do
    {
      v3 = (char *)this + 8 * v2;
      v4 = *((_QWORD *)v3 + 74);
      if ( v4 )
      {
        SslFreeObject(v4, 0i64);
        *((_QWORD *)v3 + 74) = 0i64;
      }
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 137) );
    *((_DWORD *)this + 180) = 0;
    *((_DWORD *)this + 137) = 0;
  }
  else
  {
    *((_DWORD *)this + 180) = 0;
    *((_DWORD *)this + 137) = 0;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

