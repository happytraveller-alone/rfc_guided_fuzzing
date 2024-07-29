//----- (0000000180059D04) ----------------------------------------------------
struct hsel *__fastcall GetHashInfo(int a1)
{
  __int64 v1; // rax
  _DWORD *i; // rdx

  v1 = 0i64;
  for ( i = &unk_180091028; *i != a1; i += 10 )
  {
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= 5 )
      return 0i64;
  }
  return (struct hsel *)((char *)&g_AvailableHashes + 40 * v1);
}

