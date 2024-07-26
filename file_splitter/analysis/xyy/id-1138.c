//----- (000000018005C184) ----------------------------------------------------
__int64 __fastcall DecodeSigAndReverse(
        BYTE *pbEncoded,
        DWORD cbEncoded,
        unsigned __int8 *a3,
        unsigned int *a4,
        const char *lpszStructType)
{
  unsigned int v5; // ebx
  const void **pvStructInfo; // rdi
  unsigned int v11; // esi
  DWORD pcbStructInfo[4]; // [rsp+40h] [rbp-28h] BYREF

  v5 = 0;
  pcbStructInfo[0] = 0;
  if ( CryptDecodeObject(1u, lpszStructType, pbEncoded, cbEncoded, 0, 0i64, pcbStructInfo) )
  {
    pvStructInfo = (const void **)SPExternalAlloc(pcbStructInfo[0]);
    if ( !pvStructInfo )
      return (unsigned int)-2146893056;
    if ( CryptDecodeObject(1u, lpszStructType, pbEncoded, cbEncoded, 0, pvStructInfo, pcbStructInfo) )
    {
      if ( lpszStructType == (const char *)47 )
      {
        v11 = *a4 >> 1;
        if ( *(_DWORD *)pvStructInfo <= v11 && *((_DWORD *)pvStructInfo + 4) <= v11 )
        {
          memcpy_0(a3, pvStructInfo[1], *(unsigned int *)pvStructInfo);
          memcpy_0(&a3[(unsigned __int64)*a4 >> 1], pvStructInfo[3], *((unsigned int *)pvStructInfo + 4));
          ReverseInPlace(a3, v11);
          ReverseInPlace(&a3[(unsigned __int64)*a4 >> 1], *a4 >> 1);
LABEL_15:
          SPExternalFree(pvStructInfo);
          return v5;
        }
LABEL_10:
        v5 = -2146893018;
        goto LABEL_15;
      }
      if ( lpszStructType == (const char *)40 )
      {
        if ( pcbStructInfo[0] <= *a4 )
        {
          ReverseMemCopy(a3, (unsigned __int8 *)pvStructInfo, pcbStructInfo[0] >> 1);
          ReverseMemCopy(
            &a3[(unsigned __int64)pcbStructInfo[0] >> 1],
            (unsigned __int8 *)pvStructInfo + ((unsigned __int64)pcbStructInfo[0] >> 1),
            pcbStructInfo[0] >> 1);
          *a4 = pcbStructInfo[0];
          goto LABEL_15;
        }
        goto LABEL_10;
      }
    }
    v5 = -2146893052;
    goto LABEL_15;
  }
  return (unsigned int)-2146893052;
}

