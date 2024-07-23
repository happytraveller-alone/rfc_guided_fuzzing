// File count: 1492
// Total lines: 40
----------------------------------------
unsigned int __fastcall CTls13ExtClient::ParseExtension(__int64 a1, unsigned int a2, unsigned __int8 *a3, __int64 a4)
{
  unsigned __int16 v5; // di
  int v8; // eax
  __int16 v9; // dx
  int v10; // r8d
  unsigned int result; // eax

  v5 = a4;
  v8 = (unsigned __int8)*(_DWORD *)(a1 + 16) | (a2 << 8);
  switch ( v8 )
  {
    case 1291:
      return CTls13ExtClient::ParseStatusRequestExtension((CTls13ExtClient *)a1, a3, a4, a4);
    case 3341:
      return CTls13ExtClient::ParseCertRequestSigAlgExtension((CTls13ExtClient *)a1, a3, a4);
    case 10498:
      return CTls13ExtClient::ParsePreSharedKeyExtension((CTls13ExtClient *)a1, a3, a4, a4);
    case 11010:
      return CTls13ExtClient::ParseSupportedVersionsExtension((CTls13ExtClient *)a1, a3, a4);
    case 11266:
      return CTls13ExtClient::ParseCookieExtension((CTls13ExtClient *)a1, a3, a4);
    case 12045:
      return CSsl3TlsClientContext::ParseDistinguishedNameList(
               *(CSsl3TlsClientContext **)(a1 + 64),
               a3,
               (unsigned __int16)a4);
    case 13058:
      return CTls13ExtClient::ParseKeyShareExtension((CTls13ExtClient *)a1, a3, a4);
  }
  if ( !CTls13Context::IsValidGenericExtensionType(a2) )
    return CTlsExtClient::ParseExtension(a1, a2, a3, v5);
  result = CTls13Context::RetrieveGenericExtension(*(_QWORD *)(a1 + 64) + 1368i64, v9, v10, (__int64)a3, v5);
  if ( !result )
    return CTlsExtClient::ParseExtension(a1, a2, a3, v5);
  return result;
}
// 180077ECC: variable 'v9' is possibly undefined
// 180077ECC: variable 'v10' is possibly undefined
