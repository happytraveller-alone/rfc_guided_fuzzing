// File count: 64
// Total lines: 21
------------------------------------------
__int64 __fastcall GetEccBcryptKeyBlobFromKeyExchangeBlob(
        char a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        struct _BCRYPT_ECCKEY_BLOB *a4,
        unsigned int a5)
{
  unsigned int v5; // ebx

  v5 = 0;
  if ( !a2 || !a4 )
    return 87i64;
  if ( (a1 & 8) != 0 )
    return MontgomeryGetEccPublicKeyBlob(a2, a3, a4, a5);
  if ( *a2 == 4 && (unsigned __int64)a3 + 7 <= a5 )
    memcpy_0(&a4[1], a2 + 1, (unsigned int)a3 - 1);
  else
    return (unsigned int)-2146893048;
  return v5;
}
