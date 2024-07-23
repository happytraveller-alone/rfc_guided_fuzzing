//----- (000000018000EB9C) ----------------------------------------------------
ULONG __fastcall GenerateRandomBits(PUCHAR pbBuffer, ULONG cbBuffer)
{
  int v2; // ecx
  ULONG result; // eax

  v2 = BCryptGenRandom(0i64, pbBuffer, cbBuffer, 2u);
  result = 0;
  if ( v2 < 0 )
    return RtlNtStatusToDosError(v2);
  return result;
}

