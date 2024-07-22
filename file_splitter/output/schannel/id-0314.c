//----- (0000000180017348) ----------------------------------------------------
void __fastcall DestroyCachedSslProv(struct CACHED_SSL_PROVIDER *a1)
{
  __int64 v2; // rcx
  void *v3; // rcx

  v2 = *(_QWORD *)a1;
  if ( v2 )
  {
    SslFreeObject(v2, 0i64);
    *(_QWORD *)a1 = 0i64;
  }
  v3 = (void *)*((_QWORD *)a1 + 1);
  if ( v3 )
  {
    LocalFree(v3);
    *((_QWORD *)a1 + 1) = 0i64;
  }
}
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

