// File count: 1211
// Total lines: 35
----------------------------------------
__int64 __fastcall CbLenOfEncode(unsigned int a1, unsigned __int8 *a2)
{
  __int64 v2; // r9
  int v3; // ebx
  __int64 v4; // rax
  __int64 v6; // [rsp+20h] [rbp-18h] BYREF

  v6 = 0i64;
  LODWORD(v2) = 7;
  if ( a1 >= 0x80 )
  {
    do
    {
      v4 = (unsigned int)v2;
      v2 = (unsigned int)(v2 - 1);
      *((_BYTE *)&v6 + v4) = a1;
      a1 >>= 8;
    }
    while ( a1 );
    v3 = 8 - v2;
    *((_BYTE *)&v6 + v2) = (8 - v2 - 1) | 0x80;
  }
  else
  {
    HIBYTE(v6) = a1;
    v3 = 1;
  }
  if ( a2 )
  {
    *a2 = 48;
    memcpy_0(a2 + 1, (char *)&v6 + (unsigned int)v2, v3);
  }
  return (unsigned int)(v3 + 1);
}
