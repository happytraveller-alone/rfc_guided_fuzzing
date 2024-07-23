// File count: 24
// Total lines: 16
------------------------------------------
__int64 __fastcall MontgomeryGetEccPublicKeyBlob(
        unsigned __int8 *Src,
        size_t Size,
        struct _BCRYPT_ECCKEY_BLOB *a3,
        unsigned int a4)
{
  unsigned int v4; // ebx

  v4 = 0;
  if ( a3 && Src && (unsigned __int64)(unsigned int)(2 * Size) + 8 <= a4 )
    memcpy_0(&a3[1], Src, (unsigned int)Size);
  else
    return (unsigned int)-2146893048;
  return v4;
}
