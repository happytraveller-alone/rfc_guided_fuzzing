// File count: 1187
// Total lines: 17
----------------------------------------
__int64 __fastcall CTlsSignatureSuiteList::GetMinimumCodePointToSign(
        CTlsSignatureSuiteList *this,
        enum _eTlsSignatureAlgorithm a2,
        unsigned int a3,
        int a4,
        unsigned int a5)
{
  unsigned __int16 v5; // bx
  unsigned __int8 MinimumHashToSignRow; // al

  v5 = 0;
  MinimumHashToSignRow = CTlsSignatureSuiteList::FindMinimumHashToSignRow(this, a2, a3, a4, a5);
  if ( MinimumHashToSignRow < 0xCu )
    return *((unsigned __int16 *)&unk_18007C390 + 36 * MinimumHashToSignRow);
  return v5;
}
