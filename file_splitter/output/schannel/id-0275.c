// File count: 275
// Total lines: 41
-----------------------------------------
unsigned __int8 __fastcall CTlsSignatureSuiteList::IsSupportedSignatureSuiteList(
        CTlsSignatureSuiteList *this,
        struct CTlsSignatureSuiteList *a2)
{
  int v2; // eax
  int v3; // r8d
  unsigned __int16 v4; // cx
  unsigned __int16 v5; // dx
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx

  v2 = 0;
  if ( a2 )
  {
    if ( *(_WORD *)a2 )
    {
      v3 = *((unsigned __int16 *)a2 + 17);
      if ( (_WORD)v3 )
      {
        v4 = *((_WORD *)this + 17);
        v5 = CTlsSignatureSuiteList::RsaSha256Flags;
        if ( (CTlsSignatureSuiteList::RsaSha256Flags & v4) == 0 )
          v5 = 0;
        v6 = v5 | v4;
        v7 = CTlsSignatureSuiteList::RsaSha384Flags;
        if ( (CTlsSignatureSuiteList::RsaSha384Flags & v6) == 0 )
          v7 = 0;
        v8 = v7 | v6;
        if ( (CTlsSignatureSuiteList::RsaSha512Flags & v8) != 0 )
          v2 = CTlsSignatureSuiteList::RsaSha512Flags;
        LOBYTE(v2) = (~(v2 | v8) & v3) == 0;
      }
    }
  }
  return v2;
}
// 180092800: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha512Flags;
// 180092804: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha384Flags;
// 180092808: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha256Flags;
