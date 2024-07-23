//----- (0000000180001604) ----------------------------------------------------
ULONG __fastcall SslImpersonateClient(__int64 a1, int *a2)
{
  ULONG result; // eax
  int v4; // eax
  __int64 ThreadInformation; // [rsp+30h] [rbp+8h] BYREF

  ThreadInformation = a1;
  *a2 = 0;
  result = LsaTable;
  if ( LsaTable )
  {
    if ( a1 )
      v4 = NtSetInformationThread((HANDLE)0xFFFFFFFFFFFFFFFEi64, ThreadImpersonationToken, &ThreadInformation, 8u);
    else
      v4 = (*(__int64 (**)(void))(LsaTable + 88))();
    if ( v4 >= 0 )
      *a2 = 1;
    return RtlNtStatusToDosError(v4);
  }
  return result;
}
// 180092620: using guessed type __int64 LsaTable;

