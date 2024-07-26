//----- (0000000180045FDC) ----------------------------------------------------
__int64 __fastcall CSslContext::QueryAppData(CSslContext *this, void *a2)
{
  __int64 v5; // rcx
  int v6; // edi
  unsigned int CacheAppData; // ebx
  unsigned __int8 *v8; // rsi
  unsigned int v9; // ebx
  NTSTATUS v10; // eax
  __int64 *v11; // r9
  __int64 v12; // [rsp+30h] [rbp-19h] BYREF
  unsigned int v13; // [rsp+38h] [rbp-11h] BYREF
  unsigned __int8 *v14; // [rsp+40h] [rbp-9h] BYREF
  __int128 v15; // [rsp+48h] [rbp-1h] BYREF
  char v16[24]; // [rsp+58h] [rbp+Fh] BYREF
  __int64 v17; // [rsp+70h] [rbp+27h] BYREF
  int v18; // [rsp+78h] [rbp+2Fh]

  v14 = 0i64;
  v12 = 0i64;
  v13 = 0;
  v17 = 0i64;
  v18 = 0;
  v15 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v16) )
    return 1359i64;
  v5 = *((_QWORD *)this + 11);
  v6 = v16[8] & 0x40;
  if ( !v5 )
    return 2148074241i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)(v5 + 72), 1u);
  CacheAppData = CSessionCacheItem::GetCacheAppData(*((CSessionCacheItem **)this + 11), &v14, &v13);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
  v8 = v14;
  if ( !CacheAppData )
  {
    v9 = v13;
    if ( v14 )
    {
      v10 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(0i64, v13, &v12);
      if ( v10 < 0 )
        goto LABEL_8;
      v10 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, unsigned __int8 *))(LsaTable + 72))(0i64, v9, v12, v8);
      if ( v10 < 0 )
        goto LABEL_8;
    }
    if ( v6 )
    {
      v18 = v12;
      HIDWORD(v17) = v9;
    }
    else
    {
      *((_QWORD *)&v15 + 1) = v12;
      DWORD1(v15) = v9;
    }
    v11 = &v17;
    if ( !v6 )
      v11 = (__int64 *)&v15;
    v10 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, void *, __int64 *))(LsaTable + 72))(
            0i64,
            v6 != 0 ? 12 : 16,
            a2,
            v11);
    CacheAppData = v10;
    if ( v10 < 0 )
LABEL_8:
      CacheAppData = RtlNtStatusToDosError(v10);
    else
      v12 = 0i64;
  }
  if ( v12 )
    (*(void (__fastcall **)(_QWORD))(LsaTable + 64))(0i64);
  if ( v8 )
    SPExternalFree(v8);
  return CacheAppData;
}
// 180092620: using guessed type __int64 LsaTable;

