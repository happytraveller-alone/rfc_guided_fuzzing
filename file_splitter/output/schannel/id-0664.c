// File count: 664
// Total lines: 13
-----------------------------------------
__int64 __fastcall _tailMerge_userenv_dll(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rax
  __int64 (__fastcall *Helper2)(__int64, __int64, __int64, __int64); // rax

  Helper2 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64))_delayLoadHelper2(
                                                                          (__int64)&_DELAY_IMPORT_DESCRIPTOR_userenv_dll,
                                                                          v4);
  return Helper2(a1, a2, a3, a4);
}
// 1800295B0: variable 'v4' is possibly undefined
// 18008BF10: using guessed type int _DELAY_IMPORT_DESCRIPTOR_userenv_dll;
