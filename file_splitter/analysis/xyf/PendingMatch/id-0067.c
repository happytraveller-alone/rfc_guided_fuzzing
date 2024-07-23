//----- (00000001800051C0) ----------------------------------------------------
void __fastcall GetSignatureSuiteInfoByCodePoint(
        __int16 a1,
        enum _eTlsSignatureAlgorithm *a2,
        enum _eTlsHashAlgorithm *a3,
        unsigned int *a4,
        const unsigned __int16 **a5,
        unsigned int *a6,
        unsigned int *a7)
{
  enum _eTlsSignatureAlgorithm *v8; // rcx
  __int16 v9; // ax

  if ( a2 )
    *a2 = TlsSignatureAlgorithm_Anonymous;
  if ( a3 )
    *a3 = TlsHashAlgorithm_None;
  if ( a5 )
    *a5 = 0i64;
  if ( a7 )
    *a7 = 0;
  if ( a6 )
    *a6 = 0;
  if ( a4 )
    *a4 = 0;
  v8 = (enum _eTlsSignatureAlgorithm *)&unk_18007C390;
  v9 = __ROR2__(a1, 8);
  while ( v9 != *(_WORD *)v8 )
  {
    v8 += 18;
    if ( v8 >= (enum _eTlsSignatureAlgorithm *)&CSsl3TlsServerContext::`vftable' )
      return;
  }
  if ( a2 )
    *a2 = v8[7];
  if ( a3 )
    *a3 = *((enum _eTlsHashAlgorithm *)v8 + 10);
  if ( a5 )
    *a5 = (const unsigned __int16 *)*((_QWORD *)v8 + 6);
  if ( a6 )
    *a6 = *((unsigned __int8 *)v8 + 56);
  if ( a7 )
    *a7 = *((_DWORD *)v8 + 15);
  if ( a4 )
    *a4 = *((_DWORD *)v8 + 11);
}
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';

