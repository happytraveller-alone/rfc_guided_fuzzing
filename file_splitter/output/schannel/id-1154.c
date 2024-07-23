// File count: 1154
// Total lines: 32
----------------------------------------
__int64 __fastcall CSessionCacheItem::ComputeSerializedNcryptMasterKeyLen(
        CSessionCacheItem *this,
        struct CSslContext *a2,
        unsigned int *a3)
{
  __int64 result; // rax
  __int64 *v5; // rax
  __int64 v6; // rcx

  if ( !a2 || !a3 )
    return 87i64;
  if ( *((_QWORD *)this + 2) )
  {
    v5 = (__int64 *)*((_QWORD *)a2 + 1);
    if ( v5 )
      v6 = *v5;
    else
      v6 = 0i64;
    result = SslExportKey(v6, *((_QWORD *)this + 2), L"OpaqueKeyBlob");
    if ( (_DWORD)result == -2146893784 )
      return 0i64;
  }
  else
  {
    *a3 = 0;
    return 0i64;
  }
  return result;
}
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180098528: using guessed type __int64 __fastcall SslExportKey(_QWORD, _QWORD, _QWORD);
