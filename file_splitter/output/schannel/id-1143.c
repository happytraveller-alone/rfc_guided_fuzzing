// File count: 1143
// Total lines: 29
----------------------------------------
char __fastcall IsSignatureTypeBlacklisted(unsigned __int64 a1, unsigned int a2, int a3, const UNICODE_STRING *a4)
{
  int v5; // r8d
  int v6; // r8d
  const wchar_t *v7; // r9

  if ( a2 && a1 )
  {
    v5 = a3 - 1;
    if ( !v5 )
    {
      v7 = L"RSA";
      return IsCngAlgorithmBlacklisted(a1, a2, 1, v7, 0i64, 0, a4, 1);
    }
    v6 = v5 - 1;
    if ( !v6 )
    {
      v7 = L"DSA";
      return IsCngAlgorithmBlacklisted(a1, a2, 1, v7, 0i64, 0, a4, 1);
    }
    if ( v6 == 62 )
    {
      v7 = L"ECDSA";
      return IsCngAlgorithmBlacklisted(a1, a2, 1, v7, 0i64, 0, a4, 1);
    }
  }
  return 0;
}
