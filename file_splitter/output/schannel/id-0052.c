// File count: 52
// Total lines: 39
------------------------------------------
__int64 __fastcall NonMontgomeryGetKeyExchangeBlob(
        struct _BCRYPT_ECCKEY_BLOB *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3)
{
  unsigned int v5; // ebx
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // al

  if ( a1->cbKey > 0x7F )
  {
    return 1359;
  }
  else
  {
    v5 = 0;
    v6 = 2 * LOBYTE(a1->cbKey) + 1;
    if ( a2 )
    {
      v7 = *a3;
      *a3 = v6;
      if ( v7 < v6 )
      {
        return (unsigned int)-2146893023;
      }
      else
      {
        *a2 = 4;
        memcpy_0(a2 + 1, &a1[1], v6 - 1i64);
      }
    }
    else
    {
      *a3 = v6;
    }
  }
  return v5;
}
