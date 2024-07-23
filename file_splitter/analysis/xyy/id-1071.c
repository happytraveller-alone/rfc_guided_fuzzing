//----- (0000000180059CD0) ----------------------------------------------------
struct csel *__fastcall GetCipherInfo(int a1)
{
  __int64 v1; // rax
  _DWORD *i; // rdx

  v1 = 0i64;
  for ( i = &unk_180091100; *i != a1; i += 14 )
  {
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= 8 )
      return 0i64;
  }
  return (struct csel *)((char *)&g_AvailableCiphers + 56 * v1);
}

