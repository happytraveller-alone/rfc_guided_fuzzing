//----- (000000018005E43C) ----------------------------------------------------
bool __fastcall IsSignatureKeySizeSufficient(enum _eTlsSignatureAlgorithm a1, unsigned int a2, int a3, int a4)
{
  return a1 != TlsSignatureAlgorithm_Rsa || a4 != 8 || a2 >> 3 >= 2 * a3 + 2;
}
