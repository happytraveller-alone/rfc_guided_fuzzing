//----- (0000000180006AAC) ----------------------------------------------------
ULONG __fastcall SslGetClientLogonId(struct _LUID *a1)
{
  NTSTATUS v2; // eax
  struct _LUID v4; // [rsp+20h] [rbp-28h] BYREF

  *a1 = 0i64;
  v2 = (*(__int64 (__fastcall **)(struct _LUID *))(LsaTable + 128))(&v4);
  if ( v2 >= 0 )
    *a1 = v4;
  return RtlNtStatusToDosError(v2);
}
// 180092620: using guessed type __int64 LsaTable;

