//----- (000000018005CA1C) ----------------------------------------------------
__int64 __fastcall OpenKeyUsingCng(
        NCRYPT_KEY_HANDLE *phKey,
        LPCWSTR pszKeyName,
        LPCWSTR pszProviderName,
        DWORD dwLegacyKeySpec,
        unsigned int a5,
        int a6,
        int *a7)
{
  unsigned int v10; // esi
  unsigned int dwFlags; // esi
  unsigned int v12; // ebx
  CCipherMill *v13; // rcx
  __int64 v14; // rdx
  NCRYPT_PROV_HANDLE phProvider[5]; // [rsp+30h] [rbp-28h] BYREF

  phProvider[0] = 0i64;
  if ( a7 )
    *a7 = 0;
  v10 = a5 | 0x40;
  if ( a6 )
    v10 = a5;
  dwFlags = v10 & 0xFFFFFFFE;
  v12 = NCryptOpenStorageProvider(phProvider, pszProviderName, 0);
  if ( v12 )
  {
    v13 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v14 = 10i64;
LABEL_15:
      WPP_SF_D(*((_QWORD *)v13 + 2), v14, &WPP_8df7ab8bd71935acb34f6c4601d37485_Traceguids, v12);
    }
  }
  else
  {
    if ( a7 )
      *a7 = 1;
    v12 = NCryptOpenKey(phProvider[0], phKey, pszKeyName, dwLegacyKeySpec, dwFlags);
    if ( v12 )
    {
      v13 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        v14 = 11i64;
        goto LABEL_15;
      }
    }
  }
  if ( phProvider[0] )
    NCryptFreeObject(phProvider[0]);
  return v12;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18005CA1C: using guessed type NCRYPT_PROV_HANDLE phProvider[5];
