// File count: 69
// Total lines: 20
------------------------------------------
unsigned __int8 __fastcall GetSignatureSuiteInfoRowByCodePoint(__int16 a1)
{
  char v1; // dl
  void **v2; // rax
  __int16 v3; // cx

  v1 = 0;
  v2 = (void **)&unk_18007C390;
  v3 = __ROR2__(a1, 8);
  while ( v3 != *(_WORD *)v2 )
  {
    v2 += 9;
    ++v1;
    if ( v2 >= &CSsl3TlsServerContext::`vftable' )
      return -1;
  }
  return v1;
}
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
