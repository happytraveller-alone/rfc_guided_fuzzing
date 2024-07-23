// File count: 63
// Total lines: 13
------------------------------------------
__int64 __fastcall GetEccKeyExchangeBlobFromBcryptKeyBlob(
        char a1,
        struct _BCRYPT_ECCKEY_BLOB *a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4)
{
  if ( !a2 || !a4 )
    return 87i64;
  if ( (a1 & 8) != 0 )
    return MontgomeryGetKeyExchangeBlob(a2, a3, a4);
  return NonMontgomeryGetKeyExchangeBlob(a2, a3, a4);
}
