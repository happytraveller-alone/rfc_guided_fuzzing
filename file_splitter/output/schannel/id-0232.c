// File count: 232
// Total lines: 18
-----------------------------------------
__int64 __fastcall CBufferGetNextOffset(__int64 *a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // r9
  __int64 result; // rax

  if ( !a1 )
    return 0i64;
  if ( !a2 )
    return 0i64;
  v2 = a1[1];
  if ( v2 < a2 )
    return 0i64;
  result = *a1;
  a1[1] = v2 - a2;
  *a1 = result + a2;
  return result;
}
