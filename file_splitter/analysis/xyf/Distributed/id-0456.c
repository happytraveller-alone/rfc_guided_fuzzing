//----- (0000000180020DF0) ----------------------------------------------------
CSsl3TlsContext *__fastcall CSsl3TlsContext::CSsl3TlsContext(CSsl3TlsContext *this, __int64 a2)
{
  __int64 v4; // rdx
  void *v5; // rsi
  void *v6; // rdx
  CSsl3TlsContext *result; // rax

  CSslContext::CSslContext((__int64)this, a2);
  *(_QWORD *)this = &CSsl3TlsContext::`vftable';
  *((_DWORD *)this + 84) = *(_DWORD *)(v4 + 336);
  *((_BYTE *)this + 340) = *(_BYTE *)(v4 + 340);
  *((_DWORD *)this + 104) = *(_DWORD *)(v4 + 416);
  *((_DWORD *)this + 114) = *(_DWORD *)(v4 + 456);
  *((_QWORD *)this + 58) = *(_QWORD *)(v4 + 464);
  *((_BYTE *)this + 472) = *(_BYTE *)(v4 + 472);
  *((_BYTE *)this + 473) = *(_BYTE *)(v4 + 473);
  *(_OWORD *)((char *)this + 474) = *(_OWORD *)(v4 + 474);
  *(_OWORD *)((char *)this + 490) = *(_OWORD *)(v4 + 490);
  *(_DWORD *)((char *)this + 506) = *(_DWORD *)(v4 + 506);
  *(_OWORD *)((char *)this + 510) = *(_OWORD *)(v4 + 510);
  *(_OWORD *)((char *)this + 526) = *(_OWORD *)(v4 + 526);
  *(_DWORD *)((char *)this + 542) = *(_DWORD *)(v4 + 542);
  *((_DWORD *)this + 137) = *(_DWORD *)(v4 + 548);
  *((_BYTE *)this + 552) = *(_BYTE *)(v4 + 552);
  *((_BYTE *)this + 553) = *(_BYTE *)(v4 + 553);
  *((_BYTE *)this + 554) = *(_BYTE *)(v4 + 554);
  *((_BYTE *)this + 555) = *(_BYTE *)(v4 + 555);
  *((_BYTE *)this + 556) = *(_BYTE *)(v4 + 556);
  *((_DWORD *)this + 140) = *(_DWORD *)(v4 + 560);
  *((_DWORD *)this + 141) = *(_DWORD *)(v4 + 564);
  *((_QWORD *)this + 71) = *(_QWORD *)(v4 + 568);
  *((_QWORD *)this + 72) = *(_QWORD *)(v4 + 576);
  *((_QWORD *)this + 73) = *(_QWORD *)(v4 + 584);
  *((_QWORD *)this + 98) = *(_QWORD *)(v4 + 784);
  *((_QWORD *)this + 100) = *(_QWORD *)(v4 + 800);
  *((_QWORD *)this + 101) = *(_QWORD *)(v4 + 808);
  *((_QWORD *)this + 102) = *(_QWORD *)(v4 + 816);
  *((_QWORD *)this + 103) = *(_QWORD *)(v4 + 824);
  *((_QWORD *)this + 104) = *(_QWORD *)(v4 + 832);
  *((_QWORD *)this + 105) = *(_QWORD *)(v4 + 840);
  *((_QWORD *)this + 106) = *(_QWORD *)(v4 + 848);
  *((_QWORD *)this + 107) = *(_QWORD *)(v4 + 856);
  *((_QWORD *)this + 108) = *(_QWORD *)(v4 + 864);
  *((_DWORD *)this + 218) = *(_DWORD *)(v4 + 872);
  *((_QWORD *)this + 110) = *(_QWORD *)(v4 + 880);
  *((_DWORD *)this + 222) = *(_DWORD *)(v4 + 888);
  *((_QWORD *)this + 112) = *(_QWORD *)(v4 + 896);
  v5 = (void *)(v4 + 592);
  *((_QWORD *)this + 113) = *(_QWORD *)(v4 + 904);
  *((_QWORD *)this + 114) = *(_QWORD *)(v4 + 912);
  *((_WORD *)this + 460) = *(_WORD *)(v4 + 920);
  *((_BYTE *)this + 922) = *(_BYTE *)(v4 + 922);
  *((_BYTE *)this + 923) = *(_BYTE *)(v4 + 923);
  *((_BYTE *)this + 924) = *(_BYTE *)(v4 + 924);
  *((_BYTE *)this + 925) = *(_BYTE *)(v4 + 925);
  *((_OWORD *)this + 45) = *(_OWORD *)(v4 + 720);
  *((_OWORD *)this + 46) = *(_OWORD *)(v4 + 736);
  *((_OWORD *)this + 47) = *(_OWORD *)(v4 + 752);
  *((_OWORD *)this + 48) = *(_OWORD *)(v4 + 768);
  *((_OWORD *)this + 37) = *(_OWORD *)(v4 + 592);
  *((_OWORD *)this + 38) = *(_OWORD *)(v4 + 608);
  *((_OWORD *)this + 39) = *(_OWORD *)(v4 + 624);
  *((_OWORD *)this + 40) = *(_OWORD *)(v4 + 640);
  *((_OWORD *)this + 41) = *(_OWORD *)(v4 + 656);
  *((_OWORD *)this + 42) = *(_OWORD *)(v4 + 672);
  *((_OWORD *)this + 43) = *(_OWORD *)(v4 + 688);
  *((_OWORD *)this + 44) = *(_OWORD *)(v4 + 704);
  *(_OWORD *)((char *)this + 420) = *(_OWORD *)(v4 + 420);
  *(_OWORD *)((char *)this + 436) = *(_OWORD *)(v4 + 436);
  *((_DWORD *)this + 113) = *(_DWORD *)(v4 + 452);
  *(_OWORD *)((char *)this + 377) = *(_OWORD *)(v4 + 377);
  *(_OWORD *)((char *)this + 393) = *(_OWORD *)(v4 + 393);
  *(_DWORD *)((char *)this + 409) = *(_DWORD *)(v4 + 409);
  *(_OWORD *)((char *)this + 341) = *(_OWORD *)(v4 + 341);
  *(_OWORD *)((char *)this + 357) = *(_OWORD *)(v4 + 357);
  *(_DWORD *)((char *)this + 373) = *(_DWORD *)(v4 + 373);
  *((_OWORD *)this + 17) = *(_OWORD *)(v4 + 272);
  *((_OWORD *)this + 18) = *(_OWORD *)(v4 + 288);
  *((_OWORD *)this + 19) = *(_OWORD *)(v4 + 304);
  *((_OWORD *)this + 20) = *(_OWORD *)(v4 + 320);
  *(_QWORD *)(v4 + 896) = 0i64;
  *(_DWORD *)(v4 + 888) = 0;
  *(_QWORD *)(v4 + 880) = 0i64;
  *(_DWORD *)(v4 + 872) = 0;
  *(_QWORD *)(v4 + 912) = 0i64;
  *(_WORD *)(v4 + 920) = 0;
  *(_QWORD *)(v4 + 464) = 0i64;
  *(_QWORD *)(v4 + 560) = 0i64;
  *(_QWORD *)(v4 + 568) = 0i64;
  *(_QWORD *)(v4 + 584) = 0i64;
  *(_QWORD *)(v4 + 576) = 0i64;
  *(_QWORD *)(v4 + 784) = 0i64;
  *(_QWORD *)(v4 + 800) = 0i64;
  *(_QWORD *)(v4 + 808) = 0i64;
  v6 = *(void **)(v4 + 792);
  if ( v6 )
  {
    CSslContext::FreeMemory(this, v6);
    *(_QWORD *)(a2 + 792) = 0i64;
  }
  *(_QWORD *)(a2 + 816) = 0i64;
  *(_QWORD *)(a2 + 824) = 0i64;
  *(_QWORD *)(a2 + 832) = 0i64;
  *(_QWORD *)(a2 + 840) = 0i64;
  *(_QWORD *)(a2 + 848) = 0i64;
  *(_QWORD *)(a2 + 856) = 0i64;
  *(_QWORD *)(a2 + 864) = 0i64;
  memset_0(v5, 0, 0x80ui64);
  memset_0((void *)(a2 + 720), 0, 0x40ui64);
  result = this;
  *(_DWORD *)(a2 + 548) = 0;
  *(_WORD *)(a2 + 474) = 0;
  *(_DWORD *)(a2 + 508) = 0;
  *(_WORD *)(a2 + 544) = 0;
  *(_BYTE *)(a2 + 473) = 0;
  return result;
}
// 180020E1F: variable 'v4' is possibly undefined
// 18007CBA8: using guessed type void *CSsl3TlsContext::`vftable';

