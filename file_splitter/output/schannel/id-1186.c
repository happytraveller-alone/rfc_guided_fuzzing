// File count: 1186
// Total lines: 47
----------------------------------------
char __fastcall CTlsSignatureSuiteList::FindMinimumHashToSignRow(
        CTlsSignatureSuiteList *this,
        enum _eTlsSignatureAlgorithm a2,
        unsigned int a3,
        int a4,
        unsigned int a5)
{
  _DWORD *v5; // r10
  unsigned __int8 v6; // bl
  unsigned __int8 v8; // r11
  char v12; // di
  __int64 v13; // rsi
  int v14; // eax
  unsigned __int8 v15; // r8

  v5 = &unk_18007C3A8;
  v6 = 0;
  v8 = 0;
  v12 = -1;
  v13 = 12i64;
  do
  {
    if ( v5[1] == a2 && (a4 & *v5) != 0 && v8 < 0xCu )
    {
      v14 = *((unsigned __int16 *)this + 17);
      if ( _bittest(&v14, v8) )
      {
        if ( IsSignatureKeySizeSufficient(a2, a3, *((unsigned __int8 *)v5 + 32), v5[9])
          && ((a4 & 0x3000) == 0 || v5[1] != 3 || v5[10] == a5)
          && (v15 < v6 && v15 > 0x14u || v6 <= 0x14u) )
        {
          v12 = v8;
          v6 = v15;
        }
      }
    }
    v5 += 18;
    ++v8;
    --v13;
  }
  while ( v13 );
  return v12;
}
// 18005E3A9: variable 'v5' is possibly undefined
// 18005E3B9: variable 'v15' is possibly undefined
// 18005E3C6: variable 'v8' is possibly undefined
