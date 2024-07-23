// File count: 269
// Total lines: 48
-----------------------------------------
unsigned __int8 *__fastcall CSsl3TlsContext::FindMatchingApplicationProtocol(
        unsigned __int8 *const a1,
        unsigned __int16 a2,
        unsigned __int8 *const a3,
        unsigned __int16 a4)
{
  unsigned __int8 *v5; // rbx
  unsigned __int8 *v6; // r14
  unsigned __int8 *v7; // rbp
  unsigned __int8 *v8; // rdi
  __int64 v9; // rcx
  SIZE_T v10; // rax

  v5 = a1;
  if ( !a1 )
    return 0i64;
  if ( !a3 )
    return 0i64;
  v6 = &a1[a2];
  if ( a1 >= v6 )
    return 0i64;
  v7 = &a3[a4];
  while ( 1 )
  {
    v8 = a3;
    if ( a3 < v7 )
      break;
LABEL_11:
    v5 += *v5 + 1;
    if ( v5 >= v6 )
      return 0i64;
  }
  LOBYTE(v9) = *v5;
  while ( 1 )
  {
    if ( (_BYTE)v9 == *v8 )
    {
      v10 = RtlCompareMemory(v5 + 1, v8 + 1, (unsigned __int8)v9);
      v9 = *v5;
      if ( v10 == v9 )
        return v5;
    }
    v8 += *v8 + 1;
    if ( v8 >= v7 )
      goto LABEL_11;
  }
}
