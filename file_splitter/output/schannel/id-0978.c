// File count: 978
// Total lines: 19
-----------------------------------------
__int64 SslUnsealComputeDecryptErrorDelay(void)
{
  UCHAR v1; // [rsp+40h] [rbp+18h] BYREF
  int v2; // [rsp+48h] [rbp+20h] BYREF
  int pbBuffer; // [rsp+50h] [rbp+28h] BYREF
  int v4; // [rsp+58h] [rbp+30h] BYREF

  pbBuffer = 0;
  BCryptGenRandom(0i64, (PUCHAR)&pbBuffer, 4u, 2u);
  BCryptGenRandom(0i64, (PUCHAR)&v4, 4u, 2u);
  pbBuffer &= 0x3FFFFFu;
  v4 &= 0x3FFFFFu;
  BCryptGenRandom(0i64, (PUCHAR)&v2, 4u, 2u);
  v2 &= 0x1FFFu;
  while ( BCryptGenRandom(0i64, &v1, 1u, 2u) >= 0 && v1 )
    v2 += 0x2000;
  return (unsigned int)(pbBuffer + v4 + v2);
}
