// File count: 192
// Total lines: 53
-----------------------------------------
DWORD __fastcall GetCngHashAndSignatureString(
        const struct _CERT_CONTEXT *a1,
        unsigned __int16 *a2,
        unsigned int *a3,
        char *a4,
        DWORD a5)
{
  unsigned int v8; // ebx
  bool v9; // zf
  DWORD v10; // edx
  unsigned __int16 *v11; // rax
  __int64 v13; // rbx

  v8 = 0;
  if ( !a1 || !a2 || !a3 || 2 * (unsigned __int64)*a3 > 0xFFFFFFFF )
    return 87;
  a5 = 2 * *a3;
  if ( CertGetCertificateContextProperty(a1, 0x59u, a2, &a5) )
  {
    v9 = a5 >> 1 == 0;
    v10 = a5 >> 1;
    a2[(a5 >> 1) - 1] = 0;
    if ( v9 )
    {
LABEL_10:
      if ( v8 == v10 )
        return 1359;
    }
    else
    {
      v11 = a2;
      while ( *v11 != 47 )
      {
        ++v8;
        ++v11;
        if ( v8 >= v10 )
          goto LABEL_10;
      }
      *a3 = v8;
      a2[v8] = 0;
    }
    v13 = v8 + 1;
    if ( (_DWORD)v13 != v10
      && (!a4 || v10 - (unsigned int)v13 >= 0x40 || !(unsigned int)StringCchCopyW(a4, 64i64, (char *)&a2[v13])) )
    {
      return 0;
    }
    return 1359;
  }
  *a3 = a5 >> 1;
  return GetLastError();
}
