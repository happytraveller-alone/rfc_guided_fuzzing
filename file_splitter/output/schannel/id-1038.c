// File count: 1038
// Total lines: 19
----------------------------------------
int __fastcall StringCbCatW(unsigned __int16 *a1, unsigned __int64 a2, const unsigned __int16 *a3)
{
  int result; // eax
  size_t *v6; // r8
  __int64 v7; // r11
  size_t v8; // [rsp+20h] [rbp-18h]
  size_t pcchLength; // [rsp+48h] [rbp+10h] BYREF

  if ( (a2 >> 1) - 1 > 0x7FFFFFFE )
    return -2147024809;
  result = StringLengthWorkerW(a1, a2 >> 1, &pcchLength);
  if ( result >= 0 )
    return StringCopyWorkerW(&a1[pcchLength], v7 - pcchLength, v6, a3, v8);
  return result;
}
// 180056F35: variable 'v7' is possibly undefined
// 180056F3C: variable 'v6' is possibly undefined
// 180056F3C: variable 'v8' is possibly undefined
