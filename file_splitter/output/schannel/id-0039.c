// File count: 39
// Total lines: 184
-----------------------------------------
CSsl3TlsClientContext *__fastcall CSsl3TlsClientContext::CSsl3TlsClientContext(
        CSsl3TlsClientContext *this,
        struct CSessionCacheClientItem *a2,
        int a3,
        const unsigned __int16 *a4)
{
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  int v10; // eax
  _DWORD *v11; // rdi
  __int16 v12; // ax
  __int16 v13; // cx
  CSsl3TlsClientContext *result; // rax
  char v15[8]; // [rsp+20h] [rbp-28h] BYREF
  char v16; // [rsp+28h] [rbp-20h]

  *(_QWORD *)this = &CSslContext::`vftable';
  *((_QWORD *)this + 1) = 0i64;
  *((_QWORD *)this + 2) = 0i64;
  *((_QWORD *)this + 3) = 0i64;
  *((_WORD *)this + 16) = 0;
  *((_DWORD *)this + 9) = 0;
  *(_OWORD *)((char *)this + 40) = 0i64;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 16) = a3;
  *(_QWORD *)((char *)this + 68) = 0i64;
  *((_QWORD *)this + 10) = 0i64;
  *((_QWORD *)this + 11) = a2;
  *((_WORD *)this + 48) = 0;
  *((_QWORD *)this + 13) = 0i64;
  *((_QWORD *)this + 14) = 0i64;
  *((_QWORD *)this + 15) = 0i64;
  *((_QWORD *)this + 16) = 0i64;
  *((_QWORD *)this + 17) = 0i64;
  *((_QWORD *)this + 18) = 0i64;
  *((_QWORD *)this + 19) = 0i64;
  *((_QWORD *)this + 20) = 0i64;
  *((_QWORD *)this + 21) = 0i64;
  *((_QWORD *)this + 22) = 0i64;
  *((_QWORD *)this + 23) = 0i64;
  *((_DWORD *)this + 48) = 0;
  *((_QWORD *)this + 25) = 0i64;
  *((_QWORD *)this + 26) = 0i64;
  *((_DWORD *)this + 54) = 0;
  *((_WORD *)this + 110) = 0;
  *((_QWORD *)this + 28) = 0i64;
  *((_BYTE *)this + 232) = 0;
  *((_WORD *)this + 117) = 0;
  *((_QWORD *)this + 30) = 0i64;
  *((_QWORD *)this + 31) = 0i64;
  *((_QWORD *)this + 32) = 0i64;
  *((_WORD *)this + 132) = 0;
  *((_BYTE *)this + 266) = 0;
  if ( a2 )
    *((_DWORD *)this + 4) = *((_DWORD *)a2 + 46);
  if ( (*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v15) )
  {
    if ( (v16 & 1) != 0 )
      *((_QWORD *)this + 17) |= 0x20000000ui64;
    *((_BYTE *)this + 266) = (v16 & 0x11) == 0;
  }
  v8 = ConvertSchannelProtocolToSsl(*((_DWORD *)this + 16));
  v9 = v8;
  *((_WORD *)this + 17) = v8;
  if ( HIBYTE(v8) != 0xFE || (v10 = 13, v9 > 0xFEFF) )
    v10 = 5;
  *((_DWORD *)this + 15) = v10;
  *((_BYTE *)this + 233) = (a3 & 0xF0000) != 0;
  if ( dword_180091480
    && (qword_180091490 & 0x400000000000i64) != 0
    && (qword_180091498 & 0x400000000000i64) == qword_180091498
    && (v11 = SPExternalAlloc(0x700u)) != 0i64 )
  {
    v11[2] = 0;
    *(_QWORD *)v11 = &CSchannelTelemetryContext::`vftable';
    *((_BYTE *)v11 + 16) = 0;
    v11[5] = 1;
    memset_0(v11 + 6, 0, 0x6E8ui64);
  }
  else
  {
    v11 = 0i64;
  }
  *((_QWORD *)this + 15) = v11;
  memset_0((char *)this + 272, 0, 0x40ui64);
  *((_DWORD *)this + 84) = 0;
  *((_BYTE *)this + 340) = 0;
  memset_0((char *)this + 341, 0, 0x48ui64);
  *((_DWORD *)this + 104) = 0;
  *(_OWORD *)((char *)this + 420) = 0i64;
  *(_OWORD *)((char *)this + 436) = 0i64;
  *(_QWORD *)((char *)this + 452) = 0i64;
  *((_QWORD *)this + 58) = 0i64;
  *((_DWORD *)this + 118) = 0;
  *(_OWORD *)((char *)this + 476) = 0i64;
  *(_OWORD *)((char *)this + 492) = 0i64;
  *((_DWORD *)this + 127) = 0;
  *((_OWORD *)this + 32) = 0i64;
  *((_OWORD *)this + 33) = 0i64;
  *((_WORD *)this + 272) = 0;
  *(_QWORD *)((char *)this + 548) = 0i64;
  *((_BYTE *)this + 556) = 0;
  *((_OWORD *)this + 35) = 0i64;
  memset_0((char *)this + 592, 0, 0x80ui64);
  *((_DWORD *)this + 180) = 0;
  *(_OWORD *)((char *)this + 724) = 0i64;
  v12 = 0;
  *(_OWORD *)((char *)this + 740) = 0i64;
  *(_OWORD *)((char *)this + 756) = 0i64;
  *(_QWORD *)((char *)this + 772) = 0i64;
  *((_DWORD *)this + 195) = 0;
  *((_QWORD *)this + 98) = 0i64;
  *((_QWORD *)this + 99) = 0i64;
  *((_QWORD *)this + 100) = 0i64;
  *((_QWORD *)this + 101) = 0i64;
  *((_QWORD *)this + 102) = 0i64;
  *((_QWORD *)this + 103) = 0i64;
  *((_QWORD *)this + 104) = 0i64;
  *((_QWORD *)this + 105) = 0i64;
  *((_QWORD *)this + 106) = 0i64;
  *((_QWORD *)this + 107) = 0i64;
  *((_QWORD *)this + 108) = 0i64;
  *((_DWORD *)this + 218) = 0;
  *((_QWORD *)this + 110) = 0i64;
  *((_DWORD *)this + 222) = 0;
  *((_QWORD *)this + 112) = 0i64;
  *((_QWORD *)this + 113) = 0i64;
  *((_QWORD *)this + 114) = 0i64;
  *((_DWORD *)this + 230) = 0;
  *((_WORD *)this + 462) = 0;
  if ( *((_BYTE *)this + 233) )
  {
    v12 = 1083;
    v13 = 1096;
  }
  else
  {
    *((_DWORD *)this + 48) = -1;
    v13 = 0;
    *((_QWORD *)this + 25) = 0i64;
    *((_QWORD *)this + 26) = 0i64;
  }
  *((_WORD *)this + 108) = v13;
  *((_WORD *)this + 109) = v12;
  *((_QWORD *)this + 116) = 0i64;
  *(_QWORD *)this = &CSsl3TlsClientContext::`vftable';
  *((_QWORD *)this + 117) = 0i64;
  *((_DWORD *)this + 236) = 0;
  *((_QWORD *)this + 119) = 0i64;
  *((_DWORD *)this + 240) = 0;
  *((_QWORD *)this + 121) = 0i64;
  *((_DWORD *)this + 244) = 0;
  *((_WORD *)this + 490) = 0;
  *(_OWORD *)((char *)this + 982) = 0i64;
  *(_OWORD *)((char *)this + 998) = 0i64;
  *((_QWORD *)this + 127) = 0i64;
  *((_QWORD *)this + 128) = 0i64;
  *((_BYTE *)this + 1032) = 0;
  *((_QWORD *)this + 130) = 0i64;
  *((_DWORD *)this + 262) = 0;
  memset_0((char *)this + 1052, 0, 0xFFui64);
  *(_QWORD *)((char *)this + 1308) = 0i64;
  *((_QWORD *)this + 165) = a2;
  *((_QWORD *)this + 166) = a4;
  *((_QWORD *)this + 167) = 0i64;
  *((_BYTE *)this + 1344) = 0;
  *((_WORD *)this + 673) = 0;
  *((_DWORD *)this + 337) = 0;
  *((_QWORD *)this + 169) = 0i64;
  *((_DWORD *)this + 340) = 0;
  result = this;
  *((_DWORD *)this + 17) = 40;
  *((_QWORD *)this + 73) = 0i64;
  *((_QWORD *)this + 72) = 0i64;
  return result;
}
// 18007C000: using guessed type void *CSsl3TlsClientContext::`vftable';
// 18007CDB8: using guessed type void *CSslContext::`vftable';
// 18007CF58: using guessed type void *CSchannelTelemetryContext::`vftable';
// 180091490: using guessed type __int64 qword_180091490;
// 180091498: using guessed type __int64 qword_180091498;
// 180092620: using guessed type __int64 LsaTable;
// 180003750: using guessed type char var_28[8];
