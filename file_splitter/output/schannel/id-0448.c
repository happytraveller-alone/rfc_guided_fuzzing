// File count: 448
// Total lines: 705
----------------------------------------
__int64 __fastcall CSslContextManager::InstantiateServerContext(
        CSslContextManager *this,
        struct SPBuffer *a2,
        struct SPBuffer *a3,
        struct _SecBuffer *a4,
        struct _SecBuffer *a5,
        struct CCredentialGroup *a6,
        unsigned __int64 a7,
        struct CSslParentContext **a8)
{
  char v8; // r12
  unsigned __int64 v11; // rsi
  CCipherMill *v12; // r11
  unsigned int v13; // ebx
  __int64 v14; // rdx
  int v15; // edi
  unsigned int v16; // ecx
  int v17; // r8d
  unsigned int v18; // ebp
  int v19; // eax
  unsigned int v20; // r9d
  unsigned int v21; // eax
  unsigned int v22; // ebp
  int v23; // r15d
  __int64 v24; // rax
  __int64 v25; // rdi
  __int64 v26; // rbx
  void ***v27; // r14
  __int64 v28; // r12
  void **v29; // rax
  __int64 v30; // rax
  char v31; // al
  unsigned __int16 v32; // ax
  unsigned int v33; // ecx
  int v34; // eax
  _DWORD *v35; // rsi
  __int16 v36; // ax
  __int16 v37; // cx
  __int64 v38; // rsi
  _QWORD *v39; // rax
  __int64 v40; // rcx
  __int64 v41; // rsi
  _DWORD *v42; // rbx
  __int64 result; // rax
  int v44; // r9d
  int v45; // eax
  ULONG v46; // edx
  __int64 v47; // rax
  char v48; // al
  unsigned __int16 v49; // ax
  unsigned int v50; // ecx
  int v51; // eax
  _DWORD *v52; // rsi
  __int16 v53; // ax
  __int16 v54; // cx
  _WORD *v55; // rax
  int v56; // r14d
  char v57[8]; // [rsp+30h] [rbp-58h] BYREF
  int v58; // [rsp+38h] [rbp-50h]
  int v59; // [rsp+98h] [rbp+10h]

  v8 = 0;
  v59 = 0;
  v11 = a7 & 0x100000000i64;
  v12 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids);
    v12 = WPP_GLOBAL_Control;
  }
  v13 = *((_DWORD *)a2 + 1);
  if ( v13 < 5 && (a7 & 0x100000000i64) == 0 )
  {
    *((_DWORD *)a2 + 1) = 5;
    return 2148074264i64;
  }
  v14 = *((_QWORD *)a2 + 1);
  v15 = *((_DWORD *)a6 + 38);
  if ( (a7 & 0x100000000i64) != 0 )
  {
    if ( (v15 & 0xFFFFEFFF) != 0 )
      return 2148074333i64;
    v22 = 771;
    v23 = 1024;
    v8 = 1;
LABEL_18:
    v24 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 6) + 16i64))(*((_QWORD *)this + 6));
    v25 = v24;
    if ( v24 )
    {
      v26 = v24 + 40;
      *(_QWORD *)(v24 + 8) = 0i64;
      if ( !v8 )
      {
        *(_QWORD *)(v24 + 48) = 0i64;
        *(_QWORD *)v26 = &CSslContext::`vftable';
        *(_QWORD *)(v24 + 56) = 0i64;
        *(_QWORD *)(v24 + 64) = 0i64;
        *(_WORD *)(v24 + 72) = 0;
        *(_DWORD *)(v24 + 76) = 0;
        *(_OWORD *)(v24 + 80) = 0i64;
        *(_DWORD *)(v24 + 96) = 0;
        *(_WORD *)(v24 + 136) = 0;
        *(_BYTE *)(v24 + 272) = 0;
        *(_WORD *)(v24 + 304) = 0;
        *(_BYTE *)(v24 + 306) = 0;
        v47 = LsaTable;
        *(_DWORD *)(v26 + 64) = v23;
        *(_QWORD *)(v26 + 68) = 0i64;
        *(_QWORD *)(v26 + 80) = 0i64;
        *(_QWORD *)(v26 + 88) = 0i64;
        *(_QWORD *)(v26 + 104) = 0i64;
        *(_QWORD *)(v26 + 112) = 0i64;
        *(_QWORD *)(v26 + 120) = 0i64;
        *(_QWORD *)(v26 + 128) = 0i64;
        *(_QWORD *)(v26 + 136) = 0i64;
        *(_QWORD *)(v26 + 144) = 0i64;
        *(_QWORD *)(v26 + 152) = 0i64;
        *(_QWORD *)(v26 + 160) = 0i64;
        *(_QWORD *)(v26 + 168) = 0i64;
        *(_QWORD *)(v26 + 176) = 0i64;
        *(_QWORD *)(v26 + 184) = 0i64;
        *(_DWORD *)(v26 + 192) = 0;
        *(_QWORD *)(v26 + 200) = 0i64;
        *(_QWORD *)(v26 + 208) = 0i64;
        *(_DWORD *)(v26 + 216) = 0;
        *(_WORD *)(v26 + 220) = 0;
        *(_QWORD *)(v26 + 224) = 0i64;
        *(_WORD *)(v26 + 234) = 0;
        *(_QWORD *)(v26 + 240) = 0i64;
        *(_QWORD *)(v26 + 248) = 0i64;
        *(_QWORD *)(v26 + 256) = 0i64;
        if ( (*(unsigned __int8 (__fastcall **)(char *))(v47 + 192))(v57) )
        {
          v48 = v58;
          if ( (v58 & 1) != 0 )
            *(_QWORD *)(v26 + 136) |= 0x20000000ui64;
          *(_BYTE *)(v26 + 266) = (v48 & 0x11) == 0;
        }
        v49 = ConvertSchannelProtocolToSsl(*(_DWORD *)(v26 + 64));
        v50 = v49;
        *(_WORD *)(v26 + 34) = v49;
        if ( HIBYTE(v49) != 0xFE || (v51 = 13, v50 > 0xFEFF) )
          v51 = 5;
        *(_DWORD *)(v26 + 60) = v51;
        *(_BYTE *)(v26 + 233) = (v23 & 0xF0000) != 0;
        if ( dword_180091480
          && (qword_180091490 & 0x400000000000i64) != 0
          && (qword_180091498 & 0x400000000000i64) == qword_180091498
          && (v52 = SPExternalAlloc(0x700u)) != 0i64 )
        {
          v52[2] = 0;
          *(_QWORD *)v52 = &CSchannelTelemetryContext::`vftable';
          *((_BYTE *)v52 + 16) = 0;
          v52[5] = 1;
          memset_0(v52 + 6, 0, 0x6E8ui64);
        }
        else
        {
          v52 = 0i64;
        }
        *(_QWORD *)(v26 + 120) = v52;
        memset_0((void *)(v26 + 272), 0, 0x40ui64);
        *(_DWORD *)(v26 + 336) = 0;
        *(_BYTE *)(v26 + 340) = 0;
        memset_0((void *)(v26 + 341), 0, 0x48ui64);
        *(_DWORD *)(v26 + 416) = 0;
        *(_OWORD *)(v26 + 420) = 0i64;
        *(_OWORD *)(v26 + 436) = 0i64;
        *(_QWORD *)(v26 + 452) = 0i64;
        *(_QWORD *)(v26 + 464) = 0i64;
        *(_DWORD *)(v26 + 472) = 0;
        *(_OWORD *)(v26 + 476) = 0i64;
        *(_OWORD *)(v26 + 492) = 0i64;
        *(_DWORD *)(v26 + 508) = 0;
        *(_OWORD *)(v26 + 512) = 0i64;
        *(_OWORD *)(v26 + 528) = 0i64;
        *(_WORD *)(v26 + 544) = 0;
        *(_QWORD *)(v26 + 548) = 0i64;
        *(_BYTE *)(v26 + 556) = 0;
        *(_OWORD *)(v26 + 560) = 0i64;
        *(_QWORD *)(v26 + 576) = 0i64;
        *(_QWORD *)(v26 + 584) = 0i64;
        memset_0((void *)(v26 + 592), 0, 0x80ui64);
        *(_DWORD *)(v26 + 720) = 0;
        *(_OWORD *)(v26 + 724) = 0i64;
        *(_OWORD *)(v26 + 740) = 0i64;
        *(_OWORD *)(v26 + 756) = 0i64;
        *(_QWORD *)(v26 + 772) = 0i64;
        *(_DWORD *)(v26 + 780) = 0;
        *(_QWORD *)(v26 + 784) = 0i64;
        *(_QWORD *)(v26 + 792) = 0i64;
        *(_QWORD *)(v26 + 800) = 0i64;
        *(_QWORD *)(v26 + 808) = 0i64;
        *(_QWORD *)(v26 + 816) = 0i64;
        *(_QWORD *)(v26 + 824) = 0i64;
        *(_QWORD *)(v26 + 832) = 0i64;
        *(_QWORD *)(v26 + 840) = 0i64;
        *(_QWORD *)(v26 + 848) = 0i64;
        *(_QWORD *)(v26 + 856) = 0i64;
        *(_QWORD *)(v26 + 864) = 0i64;
        *(_DWORD *)(v26 + 872) = 0;
        *(_QWORD *)(v26 + 880) = 0i64;
        *(_DWORD *)(v26 + 888) = 0;
        *(_QWORD *)(v26 + 896) = 0i64;
        *(_QWORD *)(v26 + 904) = 0i64;
        *(_QWORD *)(v26 + 912) = 0i64;
        *(_DWORD *)(v26 + 920) = 0;
        *(_WORD *)(v26 + 924) = 0;
        if ( *(_BYTE *)(v26 + 233) )
        {
          v53 = 1083;
          v54 = 1096;
        }
        else
        {
          *(_DWORD *)(v26 + 192) = -1;
          v53 = 0;
          *(_QWORD *)(v26 + 200) = 0i64;
          v54 = 0;
          *(_QWORD *)(v26 + 208) = 0i64;
        }
        *(_WORD *)(v26 + 216) = v54;
        v28 = 1000i64;
        *(_WORD *)(v26 + 218) = v53;
        *(_QWORD *)v26 = &CSsl3TlsServerContext::`vftable';
        *(_QWORD *)(v26 + 928) = 0i64;
        *(_QWORD *)(v26 + 936) = 0i64;
        *(_QWORD *)(v26 + 944) = 0i64;
        *(_WORD *)(v26 + 952) = 0;
        *(_QWORD *)(v26 + 960) = 0i64;
        *(_QWORD *)(v26 + 968) = 0i64;
        *(_QWORD *)(v26 + 976) = 0i64;
        *(_DWORD *)(v26 + 984) = 0;
        *(_BYTE *)(v26 + 988) = 0;
        *(_QWORD *)(v26 + 992) = 0i64;
LABEL_41:
        v40 = *((_QWORD *)this + 7);
        v41 = v28 + v26;
        if ( v40 )
        {
          v55 = (_WORD *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v40 + 16i64))(v40);
          v56 = *((_DWORD *)this + 8);
        }
        else
        {
          if ( !*((_BYTE *)this + 68) )
          {
LABEL_43:
            *(_QWORD *)(v25 + 8) = v26;
            *(_QWORD *)(v26 + 128) = v25;
            v42 = *(_DWORD **)(v25 + 8);
            if ( !v42 )
              return 1359i64;
            result = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v42 + 184i64))(*(_QWORD *)(v25 + 8));
            if ( !(_DWORD)result )
            {
              v42[17] = v59;
              v42[9] = v22;
              *a8 = (struct CSslParentContext *)v25;
              return 0i64;
            }
            return result;
          }
          v56 = 2048;
          v55 = SPExternalAlloc(0x800u);
          *(_BYTE *)(v25 + 32) = 1;
        }
        if ( v55 && v56 )
        {
          *(_QWORD *)(v41 + 8) = 0i64;
          *(_QWORD *)v41 = &CSslScratchAllocator::`vftable';
          *(_WORD *)(v41 + 16) = v56;
          *(_DWORD *)(v41 + 18) = 0;
          if ( (unsigned __int16)v56 > 4u )
          {
            *(_QWORD *)(v41 + 8) = v55;
            *v55 = 0;
            *(_WORD *)(*(_QWORD *)(v41 + 8) + 2i64) = v56 - 4;
          }
          *(_QWORD *)(v25 + 24) = v41;
        }
        goto LABEL_43;
      }
      v27 = (void ***)(v24 + 1560);
      v28 = 1600i64;
      if ( !v11 )
        v28 = 1616i64;
      if ( v24 != -1560 && v24 != -40 )
      {
        if ( v11 )
        {
          v29 = &CNulRecord::`vftable';
        }
        else
        {
          *(_DWORD *)(v24 + 1644) = 20;
          *(_WORD *)(v24 + 1640) = 0x4000;
          *(_WORD *)(v24 + 1650) = 0x4000;
          v29 = &CTls13Record::`vftable';
          *(_BYTE *)(v26 + 1608) = 0;
        }
        *(_QWORD *)(v26 + 1528) = v26;
        *(_WORD *)(v26 + 1536) = 0;
        *(_QWORD *)(v26 + 1544) = 0i64;
        *(_QWORD *)(v26 + 1552) = 0i64;
        *(_DWORD *)(v26 + 1560) = 0;
        *(_QWORD *)(v26 + 1568) = 0i64;
        *(_QWORD *)(v26 + 1576) = 0i64;
        *(_QWORD *)(v26 + 1584) = 0i64;
        *(_DWORD *)(v26 + 1592) = 0;
        *v27 = v29;
        *(_QWORD *)v26 = &CSslContext::`vftable';
        *(_QWORD *)(v26 + 8) = 0i64;
        *(_QWORD *)(v26 + 16) = 0i64;
        *(_QWORD *)(v26 + 24) = 0i64;
        *(_WORD *)(v26 + 32) = 0;
        *(_DWORD *)(v26 + 36) = 0;
        *(_OWORD *)(v26 + 40) = 0i64;
        *(_DWORD *)(v26 + 56) = 0;
        *(_WORD *)(v26 + 96) = 0;
        *(_BYTE *)(v26 + 232) = 0;
        *(_WORD *)(v26 + 264) = 0;
        *(_BYTE *)(v26 + 266) = 0;
        v30 = LsaTable;
        *(_DWORD *)(v26 + 64) = v23;
        *(_QWORD *)(v26 + 68) = 0i64;
        *(_QWORD *)(v26 + 80) = 0i64;
        *(_QWORD *)(v26 + 88) = 0i64;
        *(_QWORD *)(v26 + 104) = 0i64;
        *(_QWORD *)(v26 + 112) = 0i64;
        *(_QWORD *)(v26 + 120) = 0i64;
        *(_QWORD *)(v26 + 128) = 0i64;
        *(_QWORD *)(v26 + 136) = 0i64;
        *(_QWORD *)(v26 + 144) = 0i64;
        *(_QWORD *)(v26 + 152) = 0i64;
        *(_QWORD *)(v26 + 160) = 0i64;
        *(_QWORD *)(v26 + 168) = 0i64;
        *(_QWORD *)(v26 + 176) = 0i64;
        *(_QWORD *)(v26 + 184) = 0i64;
        *(_DWORD *)(v26 + 192) = 0;
        *(_QWORD *)(v26 + 200) = 0i64;
        *(_QWORD *)(v26 + 208) = 0i64;
        *(_DWORD *)(v26 + 216) = 0;
        *(_WORD *)(v26 + 220) = 0;
        *(_QWORD *)(v26 + 224) = 0i64;
        *(_WORD *)(v26 + 234) = 0;
        *(_QWORD *)(v26 + 240) = 0i64;
        *(_QWORD *)(v26 + 248) = 0i64;
        *(_QWORD *)(v26 + 256) = 0i64;
        if ( (*(unsigned __int8 (__fastcall **)(char *))(v30 + 192))(v57) )
        {
          v31 = v58;
          if ( (v58 & 1) != 0 )
            *(_QWORD *)(v26 + 136) |= 0x20000000ui64;
          *(_BYTE *)(v26 + 266) = (v31 & 0x11) == 0;
        }
        v32 = ConvertSchannelProtocolToSsl(*(_DWORD *)(v26 + 64));
        v33 = v32;
        *(_WORD *)(v26 + 34) = v32;
        if ( HIBYTE(v32) != 0xFE || (v34 = 13, v33 > 0xFEFF) )
          v34 = 5;
        *(_DWORD *)(v26 + 60) = v34;
        *(_BYTE *)(v26 + 233) = (v23 & 0xF0000) != 0;
        if ( dword_180091480
          && (qword_180091490 & 0x400000000000i64) != 0
          && (qword_180091498 & 0x400000000000i64) == qword_180091498
          && (v35 = SPExternalAlloc(0x700u)) != 0i64 )
        {
          v35[2] = 0;
          *(_QWORD *)v35 = &CSchannelTelemetryContext::`vftable';
          *((_BYTE *)v35 + 16) = 0;
          v35[5] = 1;
          memset_0(v35 + 6, 0, 0x6E8ui64);
        }
        else
        {
          v35 = 0i64;
        }
        *(_QWORD *)(v26 + 120) = v35;
        memset_0((void *)(v26 + 272), 0, 0x40ui64);
        *(_DWORD *)(v26 + 336) = 0;
        *(_BYTE *)(v26 + 340) = 0;
        memset_0((void *)(v26 + 341), 0, 0x48ui64);
        *(_DWORD *)(v26 + 416) = 0;
        *(_OWORD *)(v26 + 420) = 0i64;
        *(_OWORD *)(v26 + 436) = 0i64;
        *(_QWORD *)(v26 + 452) = 0i64;
        *(_QWORD *)(v26 + 464) = 0i64;
        *(_DWORD *)(v26 + 472) = 0;
        *(_OWORD *)(v26 + 476) = 0i64;
        *(_OWORD *)(v26 + 492) = 0i64;
        *(_DWORD *)(v26 + 508) = 0;
        *(_OWORD *)(v26 + 512) = 0i64;
        *(_OWORD *)(v26 + 528) = 0i64;
        *(_WORD *)(v26 + 544) = 0;
        *(_QWORD *)(v26 + 548) = 0i64;
        *(_BYTE *)(v26 + 556) = 0;
        *(_OWORD *)(v26 + 560) = 0i64;
        *(_QWORD *)(v26 + 576) = 0i64;
        *(_QWORD *)(v26 + 584) = 0i64;
        memset_0((void *)(v26 + 592), 0, 0x80ui64);
        *(_DWORD *)(v26 + 720) = 0;
        *(_OWORD *)(v26 + 724) = 0i64;
        *(_OWORD *)(v26 + 740) = 0i64;
        *(_OWORD *)(v26 + 756) = 0i64;
        *(_QWORD *)(v26 + 772) = 0i64;
        *(_DWORD *)(v26 + 780) = 0;
        *(_QWORD *)(v26 + 784) = 0i64;
        *(_QWORD *)(v26 + 792) = 0i64;
        *(_QWORD *)(v26 + 800) = 0i64;
        *(_QWORD *)(v26 + 808) = 0i64;
        *(_QWORD *)(v26 + 816) = 0i64;
        *(_QWORD *)(v26 + 824) = 0i64;
        *(_QWORD *)(v26 + 832) = 0i64;
        *(_QWORD *)(v26 + 840) = 0i64;
        *(_QWORD *)(v26 + 848) = 0i64;
        *(_QWORD *)(v26 + 856) = 0i64;
        *(_QWORD *)(v26 + 864) = 0i64;
        *(_DWORD *)(v26 + 872) = 0;
        *(_QWORD *)(v26 + 880) = 0i64;
        *(_DWORD *)(v26 + 888) = 0;
        *(_QWORD *)(v26 + 896) = 0i64;
        *(_QWORD *)(v26 + 904) = 0i64;
        *(_QWORD *)(v26 + 912) = 0i64;
        *(_DWORD *)(v26 + 920) = 0;
        *(_WORD *)(v26 + 924) = 0;
        if ( *(_BYTE *)(v26 + 233) )
        {
          v36 = 1083;
          v37 = 1096;
        }
        else
        {
          *(_DWORD *)(v26 + 192) = -1;
          v36 = 0;
          *(_QWORD *)(v26 + 200) = 0i64;
          v37 = 0;
          *(_QWORD *)(v26 + 208) = 0i64;
        }
        *(_WORD *)(v26 + 216) = v37;
        *(_WORD *)(v26 + 218) = v36;
        *(_QWORD *)(v26 + 928) = 0i64;
        *(_QWORD *)(v26 + 936) = 0i64;
        *(_QWORD *)(v26 + 944) = 0i64;
        *(_WORD *)(v26 + 952) = 0;
        *(_QWORD *)(v26 + 960) = 0i64;
        *(_QWORD *)(v26 + 968) = 0i64;
        *(_QWORD *)(v26 + 976) = 0i64;
        *(_DWORD *)(v26 + 984) = 0;
        *(_BYTE *)(v26 + 988) = 0;
        *(_QWORD *)(v26 + 992) = 0i64;
        *(_QWORD *)(v26 + 1016) = &CTls13ChangeCipherSpec::`vftable';
        *(_QWORD *)(v26 + 1024) = v27;
        *(_BYTE *)(v26 + 1008) = 0;
        *(_BYTE *)(v26 + 1032) = 0;
        *(_QWORD *)(v26 + 1040) = 0i64;
        *(_QWORD *)(v26 + 1048) = 0i64;
        *(_QWORD *)(v26 + 1056) = 0i64;
        *(_QWORD *)(v26 + 1064) = 0i64;
        *(_QWORD *)(v26 + 1072) = 0i64;
        *(_QWORD *)(v26 + 1080) = 0i64;
        *(_QWORD *)(v26 + 1088) = 0i64;
        *(_QWORD *)(v26 + 1096) = 0i64;
        *(_QWORD *)(v26 + 1104) = 0i64;
        *(_QWORD *)(v26 + 1112) = 0i64;
        *(_BYTE *)(v26 + 1120) = 0;
        *(_BYTE *)(v26 + 1136) = 0;
        *(_QWORD *)(v26 + 1128) = 0i64;
        *(_QWORD *)(v26 + 1144) = 0i64;
        *(_OWORD *)(v26 + 1152) = 0i64;
        *(_OWORD *)(v26 + 1168) = 0i64;
        *(_OWORD *)(v26 + 1184) = 0i64;
        *(_BYTE *)(v26 + 1216) = 0;
        *(_WORD *)(v26 + 1232) = 0;
        *(_BYTE *)(v26 + 1248) = 0;
        *(_WORD *)(v26 + 1200) = 256;
        *(_QWORD *)(v26 + 1208) = v27;
        *(_QWORD *)(v26 + 1224) = 0i64;
        *(_QWORD *)(v26 + 1240) = 0i64;
        *(_OWORD *)(v26 + 1249) = 0i64;
        *(_OWORD *)(v26 + 1265) = 0i64;
        *(_WORD *)(v26 + 1281) = 0;
        v38 = *(_QWORD *)(v26 + 1208);
        *(_QWORD *)v26 = &CTls13ServerContext::`vftable'{for `CSsl3TlsServerContext'};
        *(_QWORD *)(v26 + 1000) = &CTls13ServerContext::`vftable'{for `CTls13Context'};
        *(_QWORD *)(v26 + 1288) = &CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::`vftable';
        *(_QWORD *)(v26 + 1296) = v26;
        v39 = operator new(0x30ui64);
        if ( v39 )
        {
          v39[1] = v26;
          *v39 = &CTls13ExtServer::`vftable';
          v39[2] = 0i64;
          *((_DWORD *)v39 + 6) = 0;
          v39[4] = v26;
          v39[5] = v26;
        }
        else
        {
          v39 = 0i64;
        }
        *(_QWORD *)(v26 + 1304) = v39;
        *(_QWORD *)(v26 + 1288) = &CTls13ServerHandshake::`vftable';
        *(_QWORD *)(v26 + 1312) = 0i64;
        *(_QWORD *)(v26 + 1320) = v38;
        *(_DWORD *)(v26 + 1328) = 0;
        *(_WORD *)(v26 + 1332) = 0;
        *(_BYTE *)(v26 + 1334) = 0;
        *(_DWORD *)(v26 + 1336) = 0;
        *(_WORD *)(v26 + 1340) = 0;
        *(_BYTE *)(v26 + 1342) = 0;
        *(_QWORD *)(v26 + 1344) = 0i64;
        *(_WORD *)(v26 + 1352) = 0;
        *(_QWORD *)(v26 + 1360) = 0i64;
        *(_DWORD *)(v26 + 1368) = 0;
        *(_QWORD *)(v26 + 1376) = 0i64;
        *(_QWORD *)(v26 + 1384) = 0i64;
        *(_DWORD *)(v26 + 1392) = 0;
        *(_QWORD *)(v26 + 1400) = 0i64;
        *(_QWORD *)(v26 + 1408) = 0i64;
        *(_QWORD *)(v26 + 1416) = 0i64;
        *(_QWORD *)(v26 + 1424) = 0i64;
        *(_QWORD *)(v26 + 1432) = 0i64;
        *(_DWORD *)(v26 + 1440) = 0;
        *(_WORD *)(v26 + 1444) = 0;
        *(_QWORD *)(v26 + 1448) = 0i64;
        *(_DWORD *)(v26 + 1456) = 0;
        *(_WORD *)(v26 + 1460) = 0;
        *(_QWORD *)(v26 + 1464) = 0i64;
        *(_DWORD *)(v26 + 1472) = 0;
        *(_WORD *)(v26 + 1476) = 0;
        *(_QWORD *)(v26 + 1480) = 0i64;
        *(_WORD *)(v26 + 1488) = 0;
        *(_QWORD *)(v26 + 1496) = 0i64;
        *(_WORD *)(v26 + 1504) = 0;
        *(_BYTE *)(v26 + 1506) = 0;
        *(_QWORD *)(v26 + 1512) = 0i64;
        goto LABEL_41;
      }
      (*(void (__fastcall **)(_QWORD, __int64))(**((_QWORD **)this + 6) + 32i64))(*((_QWORD *)this + 6), v26);
    }
    return 14i64;
  }
  if ( *(_BYTE *)v14 != 22 )
  {
    v22 = *(unsigned __int8 *)(v14 + 4) | (*(unsigned __int8 *)(v14 + 3) << 8);
    if ( v22 < 0x300 )
      goto LABEL_70;
    if ( v13 < 0xE )
    {
      *((_DWORD *)a2 + 1) = 14;
      return 2148074264i64;
    }
    if ( !(*(unsigned __int8 *)(v14 + 6) | (*(unsigned __int8 *)(v14 + 5) << 8)) )
      return 2148074289i64;
    if ( BYTE1(v22) == 0xFE && v22 <= 0xFEFF )
    {
      if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)v12 + 2), 13i64, &WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids);
      return 2148074278i64;
    }
    if ( v22 < 0x302 )
    {
      if ( v22 < 0x301 )
        goto LABEL_102;
    }
    else
    {
      v23 = 256;
      if ( (v15 & 0x100) != 0 )
      {
        v59 = 20;
        goto LABEL_18;
      }
    }
    if ( (v15 & 0x40) != 0 )
    {
      v59 = 20;
      v23 = 64;
      goto LABEL_18;
    }
LABEL_102:
    if ( (v15 & 0x10) != 0 )
    {
      v59 = 20;
      goto LABEL_104;
    }
LABEL_70:
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)v12 + 2), 14i64, &WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids);
    return 2148074289i64;
  }
  v16 = *(unsigned __int8 *)(v14 + 2) | (*(unsigned __int8 *)(v14 + 1) << 8);
  if ( _byteswap_ushort(*(_WORD *)(v14 + 1)) >> 8 == 0xFE && v16 <= 0xFEFF )
  {
    v17 = *(unsigned __int8 *)(v14 + 11);
    v18 = 13;
    v19 = *(unsigned __int8 *)(v14 + 12);
    v20 = 12;
  }
  else
  {
    v17 = *(unsigned __int8 *)(v14 + 3);
    v18 = 5;
    v19 = *(unsigned __int8 *)(v14 + 4);
    v20 = 4;
  }
  if ( (v19 | (unsigned int)(v17 << 8)) < v20 + 2 )
  {
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 1) != 0 )
    {
      if ( BYTE1(v16) == 0xFE && v16 <= 0xFEFF )
      {
        v44 = *(unsigned __int8 *)(v14 + 11);
        v45 = *(unsigned __int8 *)(v14 + 12);
      }
      else
      {
        v44 = *(unsigned __int8 *)(v14 + 3);
        v45 = *(unsigned __int8 *)(v14 + 4);
      }
      WPP_SF_d(*((_QWORD *)v12 + 2), 0xCu, (__int64)&WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids, v45 | (v44 << 8));
    }
    return 2148074278i64;
  }
  v21 = v20 + v18 + 2;
  if ( v13 < v21 )
  {
    *((_DWORD *)a2 + 1) = v21;
    return 2148074264i64;
  }
  v22 = *(unsigned __int8 *)(v18 + v14 + v20 + 1) | (*(unsigned __int8 *)(v18 + v14 + v20) << 8);
  if ( BYTE1(v22) != 0xFE || v22 > 0xFEFF )
  {
    if ( v22 < 0x303 )
    {
      if ( v22 < 0x302 )
      {
        if ( v22 < 0x301 )
          goto LABEL_83;
        goto LABEL_86;
      }
    }
    else if ( (v15 & 0x1400) != 0 )
    {
      if ( (v15 & 0x1000) != 0 )
        v8 = 1;
      v23 = 1024;
      goto LABEL_18;
    }
    v23 = 256;
    if ( (v15 & 0x100) != 0 )
      goto LABEL_18;
LABEL_86:
    if ( (v15 & 0x40) != 0 )
    {
      v23 = 64;
      goto LABEL_18;
    }
LABEL_83:
    if ( (v15 & 0x10) == 0 )
      return 2148074289i64;
LABEL_104:
    v23 = 16;
    goto LABEL_18;
  }
  if ( v22 > 0xFEFD || (v23 = 0x40000, (v15 & 0x40000) == 0) )
  {
    v23 = 0x10000;
    if ( (v15 & 0x10000) == 0 )
      goto LABEL_70;
  }
  v46 = CheckInitialDTLSHelloCookie(*((_DWORD *)a6 + 53), (const unsigned __int16 *)a6 + 108, a5, a2, a3);
  if ( !v46 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids);
    goto LABEL_18;
  }
  if ( v46 == 590610 )
  {
    a4->pvBuffer = (void *)*((_QWORD *)a3 + 1);
    a4->cbBuffer = *((_DWORD *)a3 + 1);
  }
  return v46;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18007C6F0: using guessed type void *CSsl3TlsServerContext::`vftable';
// 18007C920: using guessed type void *CTls13ServerContext::`vftable'{for `CTls13Context'};
// 18007C928: using guessed type void *CTls13ServerContext::`vftable'{for `CSsl3TlsServerContext'};
// 18007CB58: using guessed type void *CTls13ChangeCipherSpec::`vftable';
// 18007CB68: using guessed type void *CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::`vftable';
// 18007CB80: using guessed type void *CTls13ServerHandshake::`vftable';
// 18007CB98: using guessed type void *CTls13ExtServer::`vftable';
// 18007CDB8: using guessed type void *CSslContext::`vftable';
// 18007CF58: using guessed type void *CSchannelTelemetryContext::`vftable';
// 18007CF80: using guessed type void *CTls13Record::`vftable';
// 18007D508: using guessed type void *CSslScratchAllocator::`vftable';
// 18007D590: using guessed type void *CNulRecord::`vftable';
// 180091490: using guessed type __int64 qword_180091490;
// 180091498: using guessed type __int64 qword_180091498;
// 180092620: using guessed type __int64 LsaTable;
// 18001F810: using guessed type char var_58[8];
