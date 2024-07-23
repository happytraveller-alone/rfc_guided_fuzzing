// File count: 1153
// Total lines: 20
----------------------------------------
__int64 __fastcall CSessionCacheServerItem::ComputeSerializedCacheItemLen(
        CSessionCacheServerItem *this,
        struct CSslContext *a2,
        unsigned int *a3)
{
  __int64 result; // rax
  unsigned int v6; // [rsp+38h] [rbp+10h] BYREF

  v6 = 0;
  if ( !a2 || !a3 )
    return 87i64;
  result = CSessionCacheItem::ComputeSerializedCacheItemLen(this, a2, &v6);
  if ( !(_DWORD)result )
  {
    *a3 = (*((_QWORD *)this + 42) != 0i64 ? 0x14 : 0) + v6 + 39;
    return 0i64;
  }
  return result;
}
