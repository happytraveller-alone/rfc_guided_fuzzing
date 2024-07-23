// File count: 551
// Total lines: 15
-----------------------------------------
__int64 __fastcall SpLsaModeInitialize(
        __int64 a1,
        unsigned int *a2,
        struct _SECPKG_FUNCTION_TABLE **a3,
        unsigned int *a4)
{
  __int64 result; // rax

  *a2 = 0x40000;
  *a3 = (struct _SECPKG_FUNCTION_TABLE *)&SpTable;
  result = 0i64;
  *a4 = 2;
  return result;
}
