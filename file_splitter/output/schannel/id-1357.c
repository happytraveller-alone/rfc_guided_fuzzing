// File count: 1357
// Total lines: 13
----------------------------------------
void __fastcall CTls13Context::FreeEarlyKey(CTls13Context *this)
{
  __int64 v2; // rcx

  v2 = *((_QWORD *)this + 13);
  if ( v2 )
  {
    SslFreeObject(v2, 0i64);
    *((_QWORD *)this + 13) = 0i64;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
