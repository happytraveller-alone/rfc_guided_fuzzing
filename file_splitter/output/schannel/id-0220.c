//----- (0000000180012D94) ----------------------------------------------------
__int64 __fastcall RunningHash(_DWORD *a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 i; // r10
  int v4; // eax
  __int64 result; // rax

  for ( i = 0i64; i < a3; *a1 = result )
  {
    v4 = *(unsigned __int8 *)(i + a2);
    ++i;
    result = (1025 * (*a1 + v4)) ^ ((unsigned int)(1025 * (*a1 + v4)) >> 6);
  }
  return result;
}

