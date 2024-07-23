//----- (000000018005D304) ----------------------------------------------------
__int64 __fastcall CSessionCacheItem::DeserializeNcryptMasterKey(CSessionCacheItem *this, unsigned __int8 *a2, int a3)
{
  char *v3; // r10
  __int64 *v5; // rax
  __int64 v6; // rcx

  v3 = (char *)this + 16;
  if ( *((_QWORD *)this + 2) )
    return 1359i64;
  if ( !a3 )
    return 0i64;
  if ( !a2 )
    return 87i64;
  v5 = (__int64 *)*((_QWORD *)this + 22);
  if ( v5 )
    v6 = *v5;
  else
    v6 = 0i64;
  return SslImportKey(v6, v3, L"OpaqueKeyBlob", a2, a3, 0);
}
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);

