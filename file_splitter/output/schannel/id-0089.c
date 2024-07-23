// File count: 89
// Total lines: 51
------------------------------------------
char __fastcall CTlsSignatureSuiteList::AddBCryptSignatureSuites(
        CTlsSignatureSuiteList *this,
        const unsigned __int16 **const a2,
        unsigned int a3,
        char a4)
{
  char v4; // di
  __int64 i; // r15
  unsigned __int8 v9; // bl
  wchar_t **v10; // rsi
  int v11; // eax
  const wchar_t **v12; // rcx

  v4 = 0;
  if ( a3 )
  {
    for ( i = a3; i; --i )
    {
      v9 = 0;
      v10 = &off_18007C3A0;
      while ( v9 < 0xCu )
      {
        v11 = *((unsigned __int16 *)this + 17);
        if ( !_bittest(&v11, v9) )
          break;
        v4 = 1;
LABEL_9:
        v10 += 9;
        ++v9;
        if ( v10 - 2 >= (wchar_t **)&CSsl3TlsServerContext::`vftable' )
          goto LABEL_10;
      }
      v12 = (const wchar_t **)(v10 - 1);
      if ( !a4 )
        v12 = (const wchar_t **)v10;
      if ( wcsicmp(*v12, *a2) )
        goto LABEL_9;
      v4 |= CTlsSignatureSuiteList::AddSignatureSuite(this, v9);
      if ( !a4 )
        goto LABEL_9;
LABEL_10:
      ++a2;
    }
  }
  if ( a4 )
    CTlsSignatureSuiteList::SetRsaSignatureFlags();
  return v4;
}
// 18007C3A0: using guessed type wchar_t *off_18007C3A0;
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
