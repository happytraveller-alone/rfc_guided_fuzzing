//----- (0000000180078D14) ----------------------------------------------------
__int64 __fastcall GetCipherDetailsFromRegistry(HANDLE KeyHandle, char *a2)
{
  int SslStringFromRegistry; // ebx

  SslStringFromRegistry = GetSslStringFromRegistry(KeyHandle, L"CngAlgorithm", a2);
  if ( SslStringFromRegistry >= 0 )
    GetSslStringFromRegistry(KeyHandle, L"CipherMode", a2 + 128);
  return (unsigned int)SslStringFromRegistry;
}

