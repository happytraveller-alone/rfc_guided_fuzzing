// File count: 102
// Total lines: 67
-----------------------------------------
char __fastcall IsCertificateBlacklisted(
        struct _TLS_PARAMETERS *a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        struct CEccCurveInfo *a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        const unsigned __int16 *a8,
        const unsigned __int16 *a9,
        struct _UNICODE_STRING *String2,
        char a11)
{
  char v14; // si
  char v15; // al
  char v17; // al

  if ( a2 && a1 && a3 && a8 && a9 )
  {
    if ( a3 == 8707 )
    {
      if ( a5 )
      {
        v15 = IsEcdsaAlgorithmBlacklisted(a1, a2, (const unsigned __int16 *)a5, *((_DWORD *)a5 + 193), a4, String2, a11);
        goto LABEL_11;
      }
    }
    else
    {
      if ( a3 == 8704 )
      {
        v15 = IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 1, L"DSA", 0i64, a4, String2, a11);
        goto LABEL_11;
      }
      if ( ((a3 - 9216) & 0xFFFF7FFF) != 0 )
        goto LABEL_12;
      v14 = 0;
      if ( a6 )
      {
        if ( a3 == 41984 )
        {
          v17 = IsRsaAlgorithmBlacklisted((unsigned __int64)a1, a2, 0, a4, String2, a11);
          v14 = v17;
          if ( !a7 )
          {
            if ( v17 )
              return 1;
          }
        }
      }
      v15 = IsRsaAlgorithmBlacklisted((unsigned __int64)a1, a2, 1, a4, String2, a11);
      if ( !a7 || v14 )
      {
LABEL_11:
        if ( !v15 )
          goto LABEL_12;
        return 1;
      }
    }
LABEL_12:
    if ( !IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 4, a8, 0i64, 0, 0i64, 1) )
      return IsCngAlgorithmBlacklisted((unsigned __int64)a1, a2, 4, a9, 0i64, 0, 0i64, 1);
    return 1;
  }
  return 0;
}
