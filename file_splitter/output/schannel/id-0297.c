// File count: 297
// Total lines: 12
-----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::SetClientEphemeralKey(CSsl3TlsClientContext *this, __int64 a2)
{
  __int64 v4; // rcx

  v4 = *((_QWORD *)this + 128);
  if ( v4 )
    SslFreeObject(v4, 0i64);
  *((_QWORD *)this + 128) = a2;
  return 0i64;
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
