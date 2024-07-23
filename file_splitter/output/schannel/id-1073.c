// File count: 1073
// Total lines: 15
----------------------------------------
struct kexch *__fastcall GetKeyExchangeInfo(int a1)
{
  __int64 v1; // rax
  _DWORD *i; // rdx

  v1 = 0i64;
  for ( i = &g_AvailableExch; *i != a1; i += 16 )
  {
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= 4 )
      return 0i64;
  }
  return (struct kexch *)((char *)&g_AvailableExch + 64 * v1);
}
