// File count: 1344
// Total lines: 11
----------------------------------------
void __fastcall CSslContext::SetEphemeralKey(CSslContext *this, __int64 a2)
{
  __int64 v4; // rcx

  v4 = *((_QWORD *)this + 14);
  if ( v4 )
    SslFreeObject(v4, 0i64);
  *((_QWORD *)this + 14) = a2;
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
