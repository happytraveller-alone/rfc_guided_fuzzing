//----- (0000000180005298) ----------------------------------------------------
bool __fastcall CTlsSignatureSuiteList::IsSupportedCodePoint(CTlsSignatureSuiteList *this, __int16 a2)
{
  unsigned __int8 SignatureSuiteInfoRowByCodePoint; // al
  int v3; // r9d
  int v4; // r10d
  __int64 v5; // r11
  int v6; // ecx
  bool result; // al

  SignatureSuiteInfoRowByCodePoint = GetSignatureSuiteInfoRowByCodePoint(a2);
  result = SignatureSuiteInfoRowByCodePoint < 0xCu
        && (v6 = *(unsigned __int16 *)(v5 + 34), _bittest(&v6, SignatureSuiteInfoRowByCodePoint))
        && ((v4 & 0x3000) == 0
         || *((_DWORD *)&unk_18007C390 + 18 * SignatureSuiteInfoRowByCodePoint + 7) != 3
         || *((_DWORD *)&unk_18007C390 + 18 * SignatureSuiteInfoRowByCodePoint + 16) == v3)
        && (v4 & *((_DWORD *)&unk_18007C390 + 18 * SignatureSuiteInfoRowByCodePoint + 6)) != 0;
  return result;
}
// 1800052AE: variable 'v5' is possibly undefined
// 1800052C9: variable 'v4' is possibly undefined
// 18002D6BE: variable 'v3' is possibly undefined

