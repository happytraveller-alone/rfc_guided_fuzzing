//----- (0000000180017E30) ----------------------------------------------------
BOOLEAN RemoveExternalSchannelAlgorithms()
{
  BOOLEAN result; // al

  if ( dword_1800921B0 )
  {
    FreeExternalHashAlgorithms();
    FreeExternalSignatureAlgorithms();
    FreeExternalKeyExchangeAlgorithms();
    return FreeExternalCipherAlgorithms();
  }
  return result;
}
// 1800921B0: using guessed type int dword_1800921B0;

