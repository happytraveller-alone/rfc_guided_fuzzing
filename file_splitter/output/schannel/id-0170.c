//----- (000000018000EC9C) ----------------------------------------------------
void __fastcall CSslUserContext::CleanupUserContext(CSslUserContext *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx
  void *v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // rcx

  if ( *((_QWORD *)this + 11) )
    SslDecrementProviderReferenceCount();
  v2 = *((_QWORD *)this + 5);
  if ( v2 )
    SslFreeObject(v2, 0i64);
  v3 = *((_QWORD *)this + 6);
  if ( v3 )
    SslFreeObject(v3, 0i64);
  v4 = (void *)*((_QWORD *)this + 33);
  if ( v4 )
    NtClose(v4);
  v5 = *((_QWORD *)this + 54);
  if ( v5 )
    SslFreeObject(v5, 0i64);
  v6 = *((_QWORD *)this + 55);
  if ( v6 )
    SslFreeObject(v6, 0i64);
  v7 = *((_QWORD *)this + 56);
  if ( v7 )
    SslFreeObject(v7, 0i64);
}
// 180098518: using guessed type __int64 SslDecrementProviderReferenceCount(void);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

