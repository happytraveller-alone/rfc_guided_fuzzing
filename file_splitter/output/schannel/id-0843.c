//----- (0000000180044D6C) ----------------------------------------------------
void __fastcall LogCredPropertiesEvent(char a1, struct _CRYPT_KEY_PROV_INFO *a2, const struct _CERT_CONTEXT *a3)
{
  const WCHAR *v5; // rbx
  const WCHAR *v6; // rdx
  struct _UNICODE_STRING v7; // [rsp+50h] [rbp-48h] BYREF
  struct _UNICODE_STRING v8; // [rsp+60h] [rbp-38h] BYREF
  struct _UNICODE_STRING v9; // [rsp+70h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+80h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 4) != 0 )
  {
    if ( a2->dwKeySpec == 1 )
    {
      v5 = L"key exchange";
    }
    else if ( a2->dwKeySpec == 2 )
    {
      v5 = L"signature";
    }
    else
    {
      v5 = L"N/A";
      if ( a2->dwProvType )
        v5 = L"unknown";
    }
    v6 = (const WCHAR *)pszClientString;
    if ( a1 )
      v6 = pszServerString;
    RtlInitUnicodeString(&DestinationString, v6);
    RtlInitUnicodeString(&v9, a2->pwszProvName);
    RtlInitUnicodeString(&v8, a2->pwszContainerName);
    RtlInitUnicodeString(&v7, v5);
    SchEventWrite(
      &SSLEVENT_CRED_PROPERTIES,
      L"uuduudb",
      (__int64)&DestinationString,
      &v9,
      a2->dwProvType,
      &v8,
      &v7,
      a2->dwFlags,
      a3->cbCertEncoded,
      a3->pbCertEncoded);
  }
}
// 180084E40: using guessed type wchar_t aKeyExchange[13];
// 180084E60: using guessed type wchar_t aSignature[10];
// 180084E78: using guessed type wchar_t aNA[4];

