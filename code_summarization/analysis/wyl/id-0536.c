//----- (0000000180027150) ----------------------------------------------------
void CTlsSignatureSuiteList::SetRsaSignatureFlags(void)
{
  int v0; // r11d
  char v1; // cl
  int v2; // r10d
  int v3; // r9d
  _DWORD *v4; // r8
  __int64 v5; // rbx

  LOWORD(v0) = CTlsSignatureSuiteList::RsaSha256Flags;
  v1 = 0;
  LOWORD(v2) = CTlsSignatureSuiteList::RsaSha384Flags;
  LOWORD(v3) = CTlsSignatureSuiteList::RsaSha512Flags;
  if ( !CTlsSignatureSuiteList::RsaSha256Flags
    || !CTlsSignatureSuiteList::RsaSha384Flags
    || !CTlsSignatureSuiteList::RsaSha512Flags )
  {
    v4 = &unk_18007C3B8;
    v5 = 12i64;
    do
    {
      if ( *(v4 - 3) == 1 )
      {
        switch ( *v4 )
        {
          case 4:
            v0 = (unsigned __int16)v0 | (1 << v1);
            CTlsSignatureSuiteList::RsaSha256Flags = v0;
            break;
          case 5:
            v2 = (unsigned __int16)v2 | (1 << v1);
            CTlsSignatureSuiteList::RsaSha384Flags = v2;
            break;
          case 6:
            v3 = (unsigned __int16)v3 | (1 << v1);
            CTlsSignatureSuiteList::RsaSha512Flags = v3;
            break;
        }
      }
      v4 += 18;
      ++v1;
      --v5;
    }
    while ( v5 );
  }
}
// 180092800: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha512Flags;
// 180092804: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha384Flags;
// 180092808: using guessed type unsigned __int16 CTlsSignatureSuiteList::RsaSha256Flags;

