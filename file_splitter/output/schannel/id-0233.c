// File count: 233
// Total lines: 28
-----------------------------------------
int __fastcall CompareEventEntry(unsigned __int8 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rbp
  unsigned int v6; // edi
  int result; // eax
  unsigned int i; // ebx
  __int64 v9; // rcx

  v3 = *(_QWORD *)(a3 + 16);
  v6 = a1;
  result = memcmp_0((const void *)(a2 + 16), (const void *)(v3 + 16), 8ui64);
  if ( !result )
  {
    for ( i = *(unsigned __int8 *)(a3 + 45) + 2; i < v6; ++i )
    {
      v9 = 16i64 * i;
      result = *(_DWORD *)(v9 + a2 + 8) - *(_DWORD *)(v9 + v3 + 8);
      if ( result )
        return result;
      result = memcmp_0(*(const void **)(v9 + a2), *(const void **)(v9 + v3), *(unsigned int *)(v9 + a2 + 8));
      if ( result )
        return result;
    }
    return 0;
  }
  return result;
}
