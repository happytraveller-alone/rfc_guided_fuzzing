// File count: 125
// Total lines: 14
-----------------------------------------
signed __int64 __fastcall InternalVerifyStackAvailable(unsigned __int64 a1)
{
  __int64 v1; // rax
  signed __int64 result; // rax
  void *v3; // rsp

  v1 = a1 + 15;
  if ( a1 + 15 <= a1 )
    v1 = 0xFFFFFFFFFFFFFF0i64;
  result = v1 & 0xFFFFFFFFFFFFFFF0ui64;
  v3 = alloca(result);
  return result;
}
