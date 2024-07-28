//----- (000000018005E558) ----------------------------------------------------
__int64 __fastcall CTlsSignatureSuiteList::ParseSupportedSignatureAlgorithmsAndSet(
        CTlsSignatureSuiteList *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned int *a4)
{
  unsigned __int8 *v6; // r11
  unsigned int v7; // r10d
  unsigned int v8; // ecx
  __int64 v9; // rdi
  unsigned __int8 SignatureSuiteInfoRowByCodePoint; // al
  int v11; // r10d
  __int64 v12; // r11

  if ( !a2 )
    return 2148074278i64;
  if ( a3 < 2 )
    return 2148074278i64;
  *(_WORD *)this = 0;
  v6 = a2 + 2;
  *((_WORD *)this + 17) = 0;
  v7 = a2[1] | (*a2 << 8);
  v8 = v7 >> 1;
  if ( v7 > a3 - 2 || (v7 & 1) != 0 || v8 - 1 > 0x4F )
    return 2148074278i64;
  if ( !v8 )
    return 2148074289i64;
  v9 = v8;
  do
  {
    SignatureSuiteInfoRowByCodePoint = GetSignatureSuiteInfoRowByCodePoint(*v6 | (v6[1] << 8));
    CTlsSignatureSuiteList::AddSignatureSuite(this, SignatureSuiteInfoRowByCodePoint);
    v6 = (unsigned __int8 *)(v12 + 2);
    --v9;
  }
  while ( v9 );
  if ( !*(_WORD *)this )
    return 2148074289i64;
  *a4 = v11 + 2;
  return 0i64;
}
// 18005E5E1: variable 'v12' is possibly undefined
// 18005E5F0: variable 'v11' is possibly undefined
