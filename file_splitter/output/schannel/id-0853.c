// File count: 853
// Total lines: 68
-----------------------------------------
void __fastcall MapProtocolToString(unsigned int a1, struct _UNICODE_STRING *a2)
{
  unsigned int v3; // ecx
  unsigned int v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  const WCHAR *v9; // rdx

  if ( a1 > 0x200 )
  {
    switch ( a1 )
    {
      case 0x400u:
      case 0x800u:
        v9 = L"TLS 1.2";
        goto LABEL_24;
      case 0x10000u:
      case 0x20000u:
        v9 = L"DTLS 1.0";
        goto LABEL_24;
      case 0x40000u:
      case 0x80000u:
        v9 = L"DTLS 1.2";
        goto LABEL_24;
    }
    goto LABEL_20;
  }
  if ( a1 != 512 )
  {
    v3 = a1 - 4;
    if ( !v3 || (v4 = v3 - 4) == 0 )
    {
      v9 = L"SSL 2.0";
      goto LABEL_24;
    }
    v5 = v4 - 8;
    if ( !v5 || (v6 = v5 - 16) == 0 )
    {
      v9 = L"SSL 3.0";
      goto LABEL_24;
    }
    v7 = v6 - 32;
    if ( !v7 || (v8 = v7 - 64) == 0 )
    {
      v9 = L"TLS 1.0";
      goto LABEL_24;
    }
    if ( v8 != 128 )
    {
LABEL_20:
      v9 = L"unknown";
      goto LABEL_24;
    }
  }
  v9 = L"TLS 1.1";
LABEL_24:
  RtlInitUnicodeString(a2, v9);
}
// 180084DA0: using guessed type wchar_t aSsl20[8];
// 180084DB0: using guessed type wchar_t aSsl30[8];
// 180084DC0: using guessed type wchar_t aTls10[8];
// 180084DD0: using guessed type wchar_t aTls11[8];
// 180084DE0: using guessed type wchar_t aTls12[8];
// 180084DF0: using guessed type wchar_t aDtls10[9];
// 180084E08: using guessed type wchar_t aDtls12[9];
