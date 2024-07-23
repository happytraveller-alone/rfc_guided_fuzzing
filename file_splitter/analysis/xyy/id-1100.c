//----- (000000018005AFCC) ----------------------------------------------------
void __fastcall CTls13Context::FreeApplicationTrafficKeys(CTls13Context *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx

  v2 = *((_QWORD *)this + 10);
  if ( v2 )
  {
    SslFreeObject(v2, 0i64);
    *((_QWORD *)this + 10) = 0i64;
  }
  v3 = *((_QWORD *)this + 11);
  if ( v3 )
  {
    SslFreeObject(v3, 0i64);
    *((_QWORD *)this + 11) = 0i64;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

