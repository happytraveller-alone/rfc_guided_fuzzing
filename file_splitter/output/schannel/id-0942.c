// File count: 942
// Total lines: 12
-----------------------------------------
__int64 __fastcall CSslUserContext::GetProviderInfo(char **this, char *a2, unsigned __int64 *a3)
{
  __int64 v4; // r11
  __int64 result; // rax

  StringCchCopyW(a2, 256i64, this[10]);
  result = 0i64;
  *a3 = *(_QWORD *)(v4 + 88);
  return result;
}
// 18004E210: variable 'v4' is possibly undefined
