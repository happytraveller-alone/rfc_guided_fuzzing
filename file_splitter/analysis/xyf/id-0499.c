//----- (000000018002492C) ----------------------------------------------------
CMasterEccCurveInfo *__fastcall CMasterEccCurveInfo::CMasterEccCurveInfo(
        CMasterEccCurveInfo *this,
        struct ProviderEccCurves *a2,
        struct CEccCurveInfo *a3,
        struct PROVIDER_TO_ECC_CURVES *a4,
        unsigned int a5)
{
  __int64 v6; // rbx
  unsigned int *v7; // r11
  __int64 v8; // rsi
  unsigned int v9; // ebp
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // r8
  __int64 v13; // r9

  *((_DWORD *)this + 3) = 1;
  *((_DWORD *)this + 2) = a5;
  *(_QWORD *)this = a2;
  if ( a5 )
  {
    v6 = 0i64;
    v7 = (unsigned int *)((char *)a4 + 8);
    v8 = a5;
    do
    {
      *(_DWORD *)(v6 + *(_QWORD *)this + 8) = *v7;
      *(_BYTE *)(v6 + *(_QWORD *)this + 24) = *((_BYTE *)v7 + 8);
      *(_QWORD *)(v6 + *(_QWORD *)this + 16) = this;
      if ( *v7 )
      {
        v9 = 0;
        *(_QWORD *)(v6 + *(_QWORD *)this) = a3;
        v10 = *v7;
        if ( (_DWORD)v10 )
        {
          do
          {
            v11 = 780i64 * v9;
            v12 = v11 + *((_QWORD *)v7 - 1);
            v13 = v11 + *(_QWORD *)(v6 + *(_QWORD *)this);
            *(_OWORD *)v13 = *(_OWORD *)v12;
            *(_OWORD *)(v13 + 16) = *(_OWORD *)(v12 + 16);
            *(_OWORD *)(v13 + 32) = *(_OWORD *)(v12 + 32);
            *(_OWORD *)(v13 + 48) = *(_OWORD *)(v12 + 48);
            *(_OWORD *)(v13 + 64) = *(_OWORD *)(v12 + 64);
            *(_OWORD *)(v13 + 80) = *(_OWORD *)(v12 + 80);
            *(_OWORD *)(v13 + 96) = *(_OWORD *)(v12 + 96);
            *(_OWORD *)(v13 + 112) = *(_OWORD *)(v12 + 112);
            *(_OWORD *)(v13 + 128) = *(_OWORD *)(v12 + 128);
            *(_OWORD *)(v13 + 144) = *(_OWORD *)(v12 + 144);
            *(_OWORD *)(v13 + 160) = *(_OWORD *)(v12 + 160);
            *(_OWORD *)(v13 + 176) = *(_OWORD *)(v12 + 176);
            *(_OWORD *)(v13 + 192) = *(_OWORD *)(v12 + 192);
            *(_OWORD *)(v13 + 208) = *(_OWORD *)(v12 + 208);
            *(_OWORD *)(v13 + 224) = *(_OWORD *)(v12 + 224);
            *(_QWORD *)(v13 + 240) = *(_QWORD *)(v12 + 240);
            *(_DWORD *)(v13 + 248) = *(_DWORD *)(v12 + 248);
            *(_WORD *)(v13 + 252) = *(_WORD *)(v12 + 252);
            *(_BYTE *)(v13 + 254) = *(_BYTE *)(v12 + 254);
            *(_OWORD *)(v13 + 510) = *(_OWORD *)(v12 + 510);
            *(_OWORD *)(v13 + 526) = *(_OWORD *)(v12 + 526);
            *(_OWORD *)(v13 + 542) = *(_OWORD *)(v12 + 542);
            *(_OWORD *)(v13 + 558) = *(_OWORD *)(v12 + 558);
            *(_OWORD *)(v13 + 574) = *(_OWORD *)(v12 + 574);
            *(_OWORD *)(v13 + 590) = *(_OWORD *)(v12 + 590);
            *(_OWORD *)(v13 + 606) = *(_OWORD *)(v12 + 606);
            *(_OWORD *)(v13 + 622) = *(_OWORD *)(v12 + 622);
            *(_OWORD *)(v13 + 638) = *(_OWORD *)(v12 + 638);
            *(_OWORD *)(v13 + 654) = *(_OWORD *)(v12 + 654);
            *(_OWORD *)(v13 + 670) = *(_OWORD *)(v12 + 670);
            *(_OWORD *)(v13 + 686) = *(_OWORD *)(v12 + 686);
            *(_OWORD *)(v13 + 702) = *(_OWORD *)(v12 + 702);
            *(_OWORD *)(v13 + 718) = *(_OWORD *)(v12 + 718);
            *(_OWORD *)(v13 + 734) = *(_OWORD *)(v12 + 734);
            ++v9;
            *(_QWORD *)(v13 + 750) = *(_QWORD *)(v12 + 750);
            *(_DWORD *)(v13 + 758) = *(_DWORD *)(v12 + 758);
            *(_WORD *)(v13 + 762) = *(_WORD *)(v12 + 762);
            *(_BYTE *)(v13 + 764) = *(_BYTE *)(v12 + 764);
            *(_DWORD *)(v13 + 772) = *(_DWORD *)(v12 + 772);
            *(_DWORD *)(v13 + 768) = *(_DWORD *)(v12 + 768);
            *(_DWORD *)(v13 + 776) = *(_DWORD *)(v12 + 776);
            v10 = *v7;
          }
          while ( v9 < (unsigned int)v10 );
        }
        a3 = (struct CEccCurveInfo *)((char *)a3 + 780 * v10);
      }
      v7 += 6;
      v6 += 32i64;
      --v8;
    }
    while ( v8 );
  }
  return this;
}

