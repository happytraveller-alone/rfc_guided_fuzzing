// File count: 496
// Total lines: 78
-----------------------------------------
__int64 __fastcall CCipherMill::FindSupportedProvider(
        CCipherMill *this,
        struct _CRYPT_CONTEXT_FUNCTION_PROVIDERS *a2,
        ULONG a3,
        struct CCipherMill::CIPHER_SUITE_TO_PROVIDER *a4,
        unsigned int a5,
        unsigned __int8 *a6,
        unsigned __int16 *a7,
        int a8)
{
  unsigned int v11; // esi
  unsigned int v12; // ebx
  PWSTR *rgpszProviders; // rcx
  wchar_t *v14; // r14
  unsigned int v15; // edi
  struct ProviderEccCurves *v16; // rbx
  __int64 v18; // rax
  ULONG pcbBuffer; // [rsp+80h] [rbp+8h] BYREF
  int v20; // [rsp+84h] [rbp+Ch]
  PCRYPT_PROVIDER_REG ppBuffer; // [rsp+88h] [rbp+10h] BYREF

  v20 = HIDWORD(this);
  pcbBuffer = 0;
  v11 = -1;
  v12 = 0;
  if ( !a2->cProviders )
    return 1168i64;
  while ( v11 == -1 )
  {
    rgpszProviders = a2->rgpszProviders;
    ppBuffer = 0i64;
    if ( BCryptQueryProviderRegistration(rgpszProviders[v12], a3, 0x10002u, &pcbBuffer, &ppBuffer) >= 0
      && (a3 == 1 && ppBuffer->pUM || a3 == 2 && ppBuffer->pKM) )
    {
      v11 = v12;
    }
    if ( ppBuffer )
      BCryptFreeBuffer(ppBuffer);
    if ( ++v12 >= a2->cProviders )
    {
      if ( v11 == -1 )
        return 1168i64;
      break;
    }
  }
  v14 = a7;
  if ( a8 && !wcsnicmp(a2->rgpszProviders[v11], L"Microsoft SSL Protocol Provider", 0x40ui64) )
  {
    v18 = -1i64;
    do
      ++v18;
    while ( v14[v18] );
    v14[(unsigned int)(v18 - 5)] = 0;
  }
  v15 = 0;
  if ( !qword_180092498 )
    goto LABEL_20;
  while ( wcsnicmp(*(const wchar_t **)(qword_180092490 + 16i64 * v15), a2->rgpszProviders[v11], 0x40ui64) )
  {
    if ( ++v15 >= qword_180092498 )
      goto LABEL_20;
  }
  if ( v15 == -1 )
LABEL_20:
    v16 = 0i64;
  else
    v16 = (struct ProviderEccCurves *)(*(_QWORD *)qword_1800925C8 + 32i64 * v15);
  return CCipherMill::InitializeCipherSuite(
           (CCipherMill *)v11,
           a4,
           a5,
           (CCipherSuiteInfo *)a6,
           (char *)a2->rgpszProviders[v11],
           v14,
           v16);
}
// 180092490: using guessed type __int64 qword_180092490;
