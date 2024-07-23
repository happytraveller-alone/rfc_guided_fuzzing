// File count: 931
// Total lines: 72
-----------------------------------------
SECURITY_STATUS __stdcall SslGetServerIdentity(
        PBYTE ClientHello,
        DWORD ClientHelloSize,
        PBYTE *ServerIdentity,
        PDWORD ServerIdentitySize,
        DWORD Flags)
{
  int v6; // r13d
  SECURITY_STATUS v7; // edx
  PBYTE v10; // rbp
  SECURITY_STATUS result; // eax
  int v12; // ecx
  int v13; // edi
  SECURITY_STATUS v14; // eax
  _OWORD v15[3]; // [rsp+20h] [rbp-38h] BYREF

  v6 = 0;
  v7 = 0;
  v10 = ClientHello;
  v15[0] = 0i64;
  if ( !ClientHello || !ServerIdentity || !ServerIdentitySize )
    return -2146892963;
  if ( ClientHelloSize < 5 )
  {
    *ServerIdentitySize = 5 - ClientHelloSize;
    return -2146893032;
  }
  if ( *ClientHello == 22 )
  {
    while ( ClientHelloSize >= 5 )
    {
      v12 = *v10;
      if ( (unsigned int)(v12 - 20) > 3 )
        return -2146893048;
      v13 = v10[4] | (v10[3] << 8);
      if ( v13 + 5 > ClientHelloSize )
      {
        *ServerIdentitySize = v13 - ClientHelloSize + 5;
        return -2146893032;
      }
      v6 += v13 + 5;
      v14 = ProcessRecord(v12, v10 + 5, v13, (__int64)v15);
      v7 = v14;
      if ( v14 )
      {
        if ( v14 == -2146893032 )
LABEL_16:
          *ServerIdentitySize = v15[0];
        return v7;
      }
      v10 += (unsigned int)(v13 + 5);
      ClientHelloSize += -5 - v13;
      if ( !ClientHelloSize )
        goto LABEL_15;
    }
    if ( v6 )
    {
LABEL_15:
      *ServerIdentity = (PBYTE)*((_QWORD *)&v15[0] + 1);
      goto LABEL_16;
    }
    *ServerIdentitySize = 5 - ClientHelloSize;
    return -2146893032;
  }
  *((_QWORD *)&v15[0] + 1) = ClientHello;
  LODWORD(v15[0]) = ClientHelloSize;
  result = ParseSsl2Hello((struct SPBuffer *)v15);
  if ( !result )
    *ServerIdentitySize = 0;
  return result;
}
