// File count: 785
// Total lines: 35
-----------------------------------------
bool __fastcall CTlsSignatureSuiteList::Restrict(
        CTlsSignatureSuiteList *this,
        const struct CTlsSignatureSuiteList *a2,
        __int16 a3)
{
  unsigned __int16 *v4; // r11
  unsigned __int16 v5; // ax
  bool v6; // zf
  unsigned __int8 i; // r10
  int v8; // eax

  v4 = (unsigned __int16 *)this;
  if ( !a2 )
    return 0;
  v5 = *((_WORD *)a2 + 17);
  v6 = (v5 & *((_WORD *)this + 17)) == 0;
  *((_WORD *)this + 17) &= v5;
  *(_WORD *)this = 0;
  if ( v6 )
    return 0;
  for ( i = 0; i < 0xCu; ++i )
  {
    v8 = v4[17];
    if ( _bittest(&v8, i) )
    {
      v4[17] = v8 & ~(1 << i);
      if ( (a3 & 0x3000) == 0 || *((_DWORD *)&unk_18007C3AC + 18 * i) != 2 )
        CTlsSignatureSuiteList::AddSignatureSuite((CTlsSignatureSuiteList *)v4, i);
    }
  }
  return *v4 != 0;
}
// 18002A56F: variable 'v4' is possibly undefined
// 18002A5AD: variable 'i' is possibly undefined
