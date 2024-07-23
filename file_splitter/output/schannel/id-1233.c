// File count: 1233
// Total lines: 61
----------------------------------------
__int64 __fastcall GenerateCertificateRequest(
        unsigned __int8 *Src,
        size_t Size,
        struct CTlsSignatureSuiteList *this,
        enum eTlsCertificateType *a4,
        unsigned __int8 a5,
        unsigned __int8 *a6,
        unsigned int *a7)
{
  size_t v7; // rdi
  unsigned int v8; // esi
  unsigned int v10; // r10d
  int v11; // eax
  unsigned __int8 *v13; // rbx
  __int64 v14; // rcx
  unsigned __int8 v15; // al

  v7 = (unsigned int)Size;
  v8 = 0;
  v10 = Size + a5 + 3;
  if ( this )
  {
    v11 = *(unsigned __int16 *)this;
    v10 += 2 * v11 + 2;
    v8 = 2 * v11 + 2;
  }
  if ( a6 )
  {
    if ( *a7 < v10 )
      return 1359i64;
    *a6 = a5;
    v13 = a6 + 1;
    if ( a5 )
    {
      v14 = a5;
      do
      {
        v15 = *(_BYTE *)a4;
        a4 = (enum eTlsCertificateType *)((char *)a4 + 4);
        *v13++ = v15;
        --v14;
      }
      while ( v14 );
    }
    if ( this )
    {
      CTlsSignatureSuiteList::BuildSupportedSignatureAlgorithms(this, v13, v8);
      v13 += v8;
    }
    v13[1] = v7;
    *v13 = BYTE1(v7);
    if ( Src )
      memcpy_0(v13 + 2, Src, v7);
  }
  else
  {
    *a7 = v10;
  }
  return 0i64;
}
