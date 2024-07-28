//----- (000000018005E464) ----------------------------------------------------
unsigned __int8 __fastcall CTlsSignatureSuiteList::IsSupportedSignatureKey(
        CTlsSignatureSuiteList *this,
        int a2,
        unsigned int a3,
        int a4,
        unsigned int a5)
{
  int v8; // edx
  int v9; // edx
  int v10; // edx
  enum _eTlsSignatureAlgorithm v11; // r11d
  _DWORD *v12; // r10
  unsigned __int8 i; // bl
  int v14; // eax

  v8 = a2 - 8704;
  if ( v8 )
  {
    v9 = v8 - 3;
    if ( v9 )
    {
      v10 = v9 - 509;
      if ( v10 && v10 != 0x8000 )
        return 0;
      v11 = TlsSignatureAlgorithm_Rsa;
    }
    else
    {
      v11 = TlsSignatureAlgorithm_Ecdsa;
    }
  }
  else
  {
    v11 = TlsSignatureAlgorithm_Dsa;
  }
  v12 = &unk_18007C3A8;
  for ( i = 0; ; ++i )
  {
    if ( v12[1] == v11
      && (a4 & *v12) != 0
      && (!a3 || IsSignatureKeySizeSufficient(v11, a3, *((unsigned __int8 *)v12 + 32), v12[9]))
      && ((a4 & 0x3000) == 0 || v12[1] != 3 || v12[10] == a5)
      && i < 0xCu )
    {
      v14 = *((unsigned __int16 *)this + 17);
      if ( _bittest(&v14, i) )
        break;
    }
    v12 += 18;
    if ( v12 - 6 >= (_DWORD *)&CSsl3TlsServerContext::`vftable' )
      return 0;
  }
  return 1;
}
// 18005E4CE: variable 'v11' is possibly undefined
// 18005E4F8: variable 'v12' is possibly undefined
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
