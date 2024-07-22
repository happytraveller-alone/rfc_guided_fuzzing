//----- (0000000180052374) ----------------------------------------------------
void SslUnsealHideDecryptErrorDelay(void)
{
  int v0; // ebx
  unsigned int v1; // eax
  __int64 v2; // rcx
  int v3; // eax
  int v4; // [rsp+30h] [rbp+8h] BYREF
  int pbBuffer; // [rsp+38h] [rbp+10h] BYREF

  BCryptGenRandom(0i64, (PUCHAR)&pbBuffer, 4u, 2u);
  v0 = pbBuffer;
  BCryptGenRandom(0i64, (PUCHAR)&v4, 4u, 2u);
  v4 |= 1u;
  v1 = (unsigned int)SslUnsealComputeDecryptErrorDelay() >> 1;
  if ( v1 )
  {
    v2 = v1;
    v3 = v4;
    do
    {
      v0 += v3;
      v3 ^= v0;
      --v2;
    }
    while ( v2 );
  }
}

