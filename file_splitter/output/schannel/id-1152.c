// File count: 1152
// Total lines: 20
----------------------------------------
__int64 __fastcall CSessionCacheItem::ComputeSerializedCacheItemLen(
        CSessionCacheItem *this,
        struct CSslContext *a2,
        unsigned int *a3)
{
  __int64 result; // rax
  unsigned int v6; // [rsp+38h] [rbp+10h] BYREF

  v6 = 0;
  if ( !a2 || !a3 )
    return 87i64;
  result = CSessionCacheItem::ComputeSerializedNcryptMasterKeyLen(this, a2, &v6);
  if ( !(_DWORD)result )
  {
    *a3 = v6 + 67 + *((_DWORD *)this + 8) + *((_DWORD *)this + 16) + *((unsigned __int8 *)this + 208);
    return 0i64;
  }
  return result;
}
