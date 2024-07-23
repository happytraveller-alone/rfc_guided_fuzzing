// File count: 1278
// Total lines: 37
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::ComputePskExtensionSize(CTls13ClientHandshake *this)
{
  __int64 v2; // rcx
  unsigned int v4; // ebx
  int PrfHashDetails; // esi
  unsigned int v6; // ecx
  unsigned __int8 v7; // [rsp+40h] [rbp+8h] BYREF
  CSessionCacheItem *v8; // [rsp+48h] [rbp+10h] BYREF

  *((_WORD *)this + 78) = 0;
  v2 = *((_QWORD *)this + 1);
  v8 = 0i64;
  v7 = 0;
  (*(void (__fastcall **)(__int64, CSessionCacheItem **))(*(_QWORD *)v2 + 224i64))(v2, &v8);
  if ( !v8 )
    return 2148074244i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)v8 + 72), 1u);
  v4 = *((_DWORD *)v8 + 108);
  PrfHashDetails = CSessionCacheItem::GetPrfHashDetails(v8, &v7, 0i64);
  RtlReleaseResource((PRTL_RESOURCE)((char *)v8 + 72));
  if ( !v4 )
    return 0i64;
  if ( !PrfHashDetails && (unsigned __int8)(v7 - 1) <= 0x3Fu )
  {
    if ( v4 > 0xFFFF )
      return 2148074248i64;
    v6 = v4 + v7 + 11;
    if ( v6 <= 0xFFFB )
    {
      *((_WORD *)this + 78) = v6;
      return 0i64;
    }
  }
  return 1359i64;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
