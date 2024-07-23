// File count: 131
// Total lines: 19
-----------------------------------------
void __fastcall CTlsSignatureSuiteList::BuildSupportedSignatureAlgorithms(
        CTlsSignatureSuiteList *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  size_t v4; // rdx

  if ( a2 )
  {
    v4 = 2 * (unsigned int)*(unsigned __int16 *)this;
    if ( a3 >= v4 + 2 )
    {
      *a2 = BYTE1(v4);
      a2[1] = v4;
      memcpy_0(a2 + 2, (char *)this + 2, v4);
    }
  }
}
