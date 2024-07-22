//----- (000000018000D1CC) ----------------------------------------------------
__int64 __fastcall QueryStreamSizes(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned int *a7)
{
  __int64 v11; // r13
  __int64 result; // rax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  __int128 v15; // [rsp+40h] [rbp-328h] BYREF
  int v16; // [rsp+50h] [rbp-318h]
  char v17[272]; // [rsp+60h] [rbp-308h] BYREF
  unsigned int v18; // [rsp+170h] [rbp-1F8h]
  unsigned int v19; // [rsp+1F4h] [rbp-174h]

  memset_0(v17, 0, 0x2A4ui64);
  v11 = (unsigned __int16)ConvertSchannelProtocolToSsl(a3);
  result = SslLookupCipherSuiteInfo(a1, v11, a2, a4, v17, 0);
  if ( !(_DWORD)result )
  {
    v13 = v18;
    if ( a5 )
      *a5 = v18;
    if ( a6 )
      *a6 = v19 >> 3;
    if ( a7 )
    {
      v14 = 0;
      if ( v13 > 1 )
        v14 = v13;
      *a7 = v14;
    }
    if ( (a3 & 0x3F00) != 0 )
    {
      v16 = 0;
      v15 = 0i64;
      if ( !(unsigned int)SslLookupCipherLengths(a1, (unsigned int)v11, a2, a4, &v15, 20, 0) )
      {
        if ( a6 )
          *a6 = DWORD2(v15);
        if ( a7 )
          *a7 = HIDWORD(v15);
      }
    }
    return 0i64;
  }
  return result;
}
// 1800984F0: using guessed type __int64 __fastcall SslLookupCipherLengths(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
// 180098510: using guessed type __int64 __fastcall SslLookupCipherSuiteInfo(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);

