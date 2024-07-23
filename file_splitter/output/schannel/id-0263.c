// File count: 263
// Total lines: 32
-----------------------------------------
__int64 __fastcall MapOidToKeyExch(char *a1)
{
  const struct _OIDPROVMAP near *const *v2; // r8
  __int64 v3; // rax
  char *v4; // rdx
  int v5; // r10d
  int v6; // ecx

  v2 = &g_CertTypes;
  v3 = 0i64;
  do
  {
    v4 = a1;
    do
    {
      v5 = (unsigned __int8)v4[(unsigned __int64)(*v2 - (const struct _OIDPROVMAP near *const)a1)];
      v6 = (unsigned __int8)*v4 - v5;
      if ( v6 )
        break;
      ++v4;
    }
    while ( v5 );
    if ( !v6 )
      return *((unsigned int *)&g_CertTypes + 4 * v3 + 2);
    v3 = (unsigned int)(v3 + 1);
    v2 += 2;
  }
  while ( (unsigned int)v3 < 8 );
  return 0i64;
}
// 18007D750: using guessed type const struct _OIDPROVMAP near *const g_CertTypes;
