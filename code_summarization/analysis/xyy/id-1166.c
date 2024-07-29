//----- (000000018005D968) ----------------------------------------------------
__int64 __fastcall CSessionCacheItem::SerializeNcryptMasterKey(
        CSessionCacheItem *this,
        struct CSslContext *a2,
        unsigned __int8 *a3,
        int a4,
        unsigned int *a5)
{
  __int64 v6; // rdx
  _QWORD *v8; // rcx

  if ( !a2 || !a3 && a4 || !a5 )
    return 87i64;
  v6 = *((_QWORD *)this + 2);
  if ( v6 )
  {
    v8 = (_QWORD *)*((_QWORD *)a2 + 1);
    if ( v8 )
      v8 = (_QWORD *)*v8;
    return SslExportKey(v8, v6, L"OpaqueKeyBlob");
  }
  else
  {
    *a5 = 0;
    return 0i64;
  }
}
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180098528: using guessed type __int64 __fastcall SslExportKey(_QWORD, _QWORD, _QWORD);

