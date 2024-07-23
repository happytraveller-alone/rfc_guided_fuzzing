// File count: 25
// Total lines: 34
------------------------------------------
__int64 __fastcall MontgomeryGetKeyExchangeBlob(
        struct _BCRYPT_ECCKEY_BLOB *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3)
{
  unsigned int cbKey_low; // ecx
  unsigned int v6; // ebx
  unsigned __int8 v7; // al

  if ( a1->cbKey > 0xFF )
  {
    return 87;
  }
  else
  {
    cbKey_low = LOBYTE(a1->cbKey);
    v6 = 0;
    if ( a2 )
    {
      v7 = *a3;
      *a3 = cbKey_low;
      if ( v7 < (unsigned __int8)cbKey_low )
        return (unsigned int)-2146893023;
      else
        memcpy_0(a2, &a1[1], cbKey_low);
    }
    else
    {
      *a3 = cbKey_low;
    }
  }
  return v6;
}
