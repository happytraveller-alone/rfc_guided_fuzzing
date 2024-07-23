// File count: 1074
// Total lines: 15
----------------------------------------
struct sigsel *__fastcall GetSigInfo(int a1)
{
  __int64 v1; // rax
  _DWORD *i; // rdx

  v1 = 0i64;
  for ( i = &unk_1800913EC; *i != a1; i += 8 )
  {
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= 5 )
      return 0i64;
  }
  return (struct sigsel *)((char *)&g_AvailableSigs + 32 * v1);
}
