// File count: 1349
// Total lines: 43
----------------------------------------
void __fastcall CTls13Context::CleanupTls13SharedConnectedState(CTls13Context *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx
  __int64 v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx

  CTls13Context::FreeEarlyKey(this);
  CTls13Context::FreeCertificateRequestContext(this);
  v2 = *((_QWORD *)this + 5);
  if ( v2 )
  {
    SslFreeObject(v2, 0i64);
    *((_QWORD *)this + 5) = 0i64;
  }
  v3 = *((_QWORD *)this + 6);
  if ( v3 )
  {
    SslFreeObject(v3, 0i64);
    *((_QWORD *)this + 6) = 0i64;
  }
  v4 = *((_QWORD *)this + 7);
  if ( v4 )
  {
    SslFreeObject(v4, 0i64);
    *((_QWORD *)this + 7) = 0i64;
  }
  v5 = *((_QWORD *)this + 8);
  if ( v5 )
  {
    SslFreeObject(v5, 0i64);
    *((_QWORD *)this + 8) = 0i64;
  }
  v6 = *((_QWORD *)this + 30);
  if ( v6 )
  {
    SslFreeObject(v6, 0i64);
    *((_QWORD *)this + 30) = 0i64;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
