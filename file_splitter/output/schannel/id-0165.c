// File count: 165
// Total lines: 17
-----------------------------------------
void __fastcall CTlsSignatureSuiteList::SetSignatureSuiteList(
        CTlsSignatureSuiteList *this,
        const struct CTlsSignatureSuiteList *a2)
{
  __int64 v2; // r8

  *(_WORD *)this = 0;
  *((_WORD *)this + 17) = 0;
  v2 = *(unsigned __int16 *)a2;
  if ( (unsigned int)v2 <= 0x10 )
  {
    *(_WORD *)this = v2;
    *((_WORD *)this + 17) = *((_WORD *)a2 + 17);
    memcpy_0((char *)this + 2, (char *)a2 + 2, 2 * v2);
  }
}
