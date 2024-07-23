// File count: 1096
// Total lines: 27
----------------------------------------
void __fastcall CTls13ServerContext::CleanupLsaModeKeys(CTls13ServerContext *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx

  if ( *((_BYTE *)this + 1201) )
    CTls13Context::FreeApplicationTrafficKeys((CTls13ServerContext *)((char *)this + 1000));
  v2 = *((_QWORD *)this + 19);
  if ( v2 )
  {
    SslFreeObject(v2, 0i64);
    *((_QWORD *)this + 19) = 0i64;
  }
  v3 = *((_QWORD *)this + 18);
  if ( v3 )
  {
    SslFreeObject(v3, 0i64);
    *((_QWORD *)this + 18) = 0i64;
  }
  if ( *((_BYTE *)this + 233) )
  {
    if ( *((_BYTE *)this + 264) )
      *((_QWORD *)this + 31) = 0i64;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
