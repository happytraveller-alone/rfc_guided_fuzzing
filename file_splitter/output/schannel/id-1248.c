// File count: 1248
// Total lines: 61
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::CTls13Handshake<CTls13ClientContext,CTls13ExtClient>(
        __int64 a1,
        __int64 a2,
        __int64 a3)
{
  _QWORD *v6; // rax
  _QWORD *v7; // r9
  __int64 result; // rax

  *(_QWORD *)(a1 + 8) = a2;
  *(_QWORD *)a1 = &CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::`vftable';
  v6 = operator new(0x48ui64);
  v7 = v6;
  if ( v6 )
  {
    v6[1] = a2;
    v6[2] = 0i64;
    *((_DWORD *)v6 + 6) = 0;
    *v6 = &CTlsExtClient::`vftable';
    *((_BYTE *)v6 + 32) = 0;
    v6[5] = 0i64;
    *((_DWORD *)v6 + 12) = 0;
    v6[7] = a2;
    *((_BYTE *)v6 + 52) = *(_BYTE *)(a2 + 922);
    *v6 = &CTls13ExtClient::`vftable';
    v6[8] = a2;
  }
  else
  {
    v7 = 0i64;
  }
  *(_QWORD *)(a1 + 32) = a3;
  result = a1;
  *(_QWORD *)(a1 + 16) = v7;
  *(_QWORD *)(a1 + 24) = 0i64;
  *(_DWORD *)(a1 + 40) = 0;
  *(_WORD *)(a1 + 44) = 0;
  *(_BYTE *)(a1 + 46) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  *(_WORD *)(a1 + 52) = 0;
  *(_BYTE *)(a1 + 54) = 0;
  *(_QWORD *)(a1 + 56) = 0i64;
  *(_WORD *)(a1 + 64) = 0;
  *(_QWORD *)(a1 + 72) = 0i64;
  *(_DWORD *)(a1 + 80) = 0;
  *(_QWORD *)(a1 + 88) = 0i64;
  *(_QWORD *)(a1 + 96) = 0i64;
  *(_DWORD *)(a1 + 104) = 0;
  *(_QWORD *)(a1 + 112) = 0i64;
  *(_QWORD *)(a1 + 120) = 0i64;
  *(_QWORD *)(a1 + 128) = 0i64;
  *(_QWORD *)(a1 + 136) = 0i64;
  *(_QWORD *)(a1 + 144) = 0i64;
  *(_DWORD *)(a1 + 152) = 0;
  *(_WORD *)(a1 + 156) = 0;
  return result;
}
// 18007D048: using guessed type void *CTlsExtClient::`vftable';
// 18007D5C8: using guessed type void *CTls13ExtClient::`vftable';
// 18007FD48: using guessed type void *CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::`vftable';
