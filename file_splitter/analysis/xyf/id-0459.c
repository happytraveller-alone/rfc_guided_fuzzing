//----- (0000000180021540) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::WriteServerEvent(CSchannelTelemetryContext *this)
{
  unsigned int v1; // r10d
  char v2; // al
  int v3; // r10d
  __int16 v4; // r8
  int v5; // r11d
  int v6; // edi
  const WCHAR *v7; // r9
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // rax
  int v26; // ecx
  unsigned __int8 v27; // bl
  char *v28; // rax
  char v29; // cl
  char v32; // cl
  char v33; // r8
  char v34; // dl
  __int64 v35; // rcx
  signed __int64 v36; // r13
  __int64 v37; // rdi
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned __int8 v41; // cl
  unsigned int v42; // edx
  struct _EVENT_DATA_DESCRIPTOR *v43; // r10
  __int64 v44; // r11
  unsigned __int64 i; // rcx
  int v46; // eax
  RTL_SRWLOCK *v47; // r12
  int v48; // r15d
  volatile signed __int64 *j; // rsi
  volatile signed __int64 v50; // rsi
  int v51; // ecx
  __int64 v52; // r14
  int v53; // eax
  unsigned int v54; // edi
  unsigned __int8 v55; // dl
  signed __int64 v56; // r8
  __int64 v57; // rax
  int v58; // r10d
  volatile signed __int64 *v59; // r9
  int v60; // eax
  unsigned int v61; // eax
  signed __int64 v62; // rax
  volatile signed __int64 v63; // rtt
  char v64; // [rsp+38h] [rbp-D0h] BYREF
  char v65; // [rsp+39h] [rbp-CFh] BYREF
  __int64 v66; // [rsp+40h] [rbp-C8h] BYREF
  __int16 v67; // [rsp+48h] [rbp-C0h] BYREF
  __int16 v68; // [rsp+4Ah] [rbp-BEh] BYREF
  int v69; // [rsp+4Ch] [rbp-BCh] BYREF
  int v70; // [rsp+50h] [rbp-B8h] BYREF
  int v71; // [rsp+54h] [rbp-B4h] BYREF
  int v72; // [rsp+58h] [rbp-B0h] BYREF
  int v73; // [rsp+5Ch] [rbp-ACh] BYREF
  int v74; // [rsp+60h] [rbp-A8h] BYREF
  int v75; // [rsp+64h] [rbp-A4h] BYREF
  int v76; // [rsp+68h] [rbp-A0h] BYREF
  int v77; // [rsp+6Ch] [rbp-9Ch] BYREF
  int v78; // [rsp+70h] [rbp-98h] BYREF
  int v79; // [rsp+74h] [rbp-94h] BYREF
  int v80; // [rsp+78h] [rbp-90h] BYREF
  int v81; // [rsp+7Ch] [rbp-8Ch] BYREF
  int v82; // [rsp+80h] [rbp-88h] BYREF
  __int64 v83; // [rsp+88h] [rbp-80h]
  EVENT_DESCRIPTOR EventDescriptor; // [rsp+90h] [rbp-78h] BYREF
  __int64 v85; // [rsp+A0h] [rbp-68h] BYREF
  __int64 v86; // [rsp+A8h] [rbp-60h] BYREF
  __int64 v87; // [rsp+B0h] [rbp-58h] BYREF
  __int64 v88; // [rsp+B8h] [rbp-50h] BYREF
  __int64 v89; // [rsp+C0h] [rbp-48h] BYREF
  __int64 v90; // [rsp+C8h] [rbp-40h] BYREF
  __int64 v91; // [rsp+D0h] [rbp-38h] BYREF
  __int64 v92; // [rsp+D8h] [rbp-30h] BYREF
  __int64 v93; // [rsp+E0h] [rbp-28h] BYREF
  __int64 v94; // [rsp+E8h] [rbp-20h] BYREF
  __int64 v95; // [rsp+F0h] [rbp-18h] BYREF
  __int64 v96; // [rsp+F8h] [rbp-10h] BYREF
  __int64 v97; // [rsp+100h] [rbp-8h] BYREF
  __int64 v98; // [rsp+108h] [rbp+0h] BYREF
  __int64 v99; // [rsp+110h] [rbp+8h] BYREF
  __int64 v100; // [rsp+118h] [rbp+10h] BYREF
  __int64 v101; // [rsp+120h] [rbp+18h] BYREF
  __int64 v102; // [rsp+128h] [rbp+20h] BYREF
  __int64 v103; // [rsp+130h] [rbp+28h] BYREF
  __int64 v104; // [rsp+138h] [rbp+30h] BYREF
  __int64 v105; // [rsp+140h] [rbp+38h] BYREF
  __int64 v106; // [rsp+148h] [rbp+40h] BYREF
  __int64 v107; // [rsp+150h] [rbp+48h] BYREF
  __int64 v108; // [rsp+158h] [rbp+50h] BYREF
  __int64 v109; // [rsp+160h] [rbp+58h] BYREF
  __int64 v110; // [rsp+168h] [rbp+60h] BYREF
  __int64 v111; // [rsp+170h] [rbp+68h] BYREF
  __int64 v112; // [rsp+178h] [rbp+70h] BYREF
  __int64 v113; // [rsp+180h] [rbp+78h] BYREF
  __int64 v114; // [rsp+188h] [rbp+80h] BYREF
  __int64 v115; // [rsp+190h] [rbp+88h] BYREF
  __int64 v116; // [rsp+198h] [rbp+90h] BYREF
  __int64 v117; // [rsp+1A0h] [rbp+98h] BYREF
  __int64 v118; // [rsp+1A8h] [rbp+A0h] BYREF
  __int64 v119[2]; // [rsp+1B0h] [rbp+A8h] BYREF
  __int16 v120; // [rsp+1C0h] [rbp+B8h] BYREF
  __int64 v121; // [rsp+1C8h] [rbp+C0h]
  __int16 v122; // [rsp+1D0h] [rbp+C8h] BYREF
  __int64 v123; // [rsp+1D8h] [rbp+D0h]
  struct _EVENT_DATA_DESCRIPTOR UserData; // [rsp+1E8h] [rbp+E0h] BYREF
  void *Buf1; // [rsp+1F8h] [rbp+F0h] BYREF
  int v126; // [rsp+200h] [rbp+F8h]
  int v127; // [rsp+204h] [rbp+FCh]
  __int64 *v128; // [rsp+208h] [rbp+100h]
  __int64 v129[68]; // [rsp+210h] [rbp+108h]
  int v130; // [rsp+430h] [rbp+328h]
  int v131; // [rsp+434h] [rbp+32Ch]
  char *v132; // [rsp+438h] [rbp+330h]
  __int64 v133; // [rsp+440h] [rbp+338h]
  __int64 *v134; // [rsp+448h] [rbp+340h]
  __int64 v135; // [rsp+450h] [rbp+348h]
  __int64 *v136; // [rsp+458h] [rbp+350h]
  __int64 v137; // [rsp+460h] [rbp+358h]
  int *v138; // [rsp+468h] [rbp+360h]
  __int64 v139; // [rsp+470h] [rbp+368h]
  __int16 *v140; // [rsp+478h] [rbp+370h]
  __int64 v141; // [rsp+480h] [rbp+378h]
  int *v142; // [rsp+488h] [rbp+380h]
  __int64 v143; // [rsp+490h] [rbp+388h]
  int *v144; // [rsp+498h] [rbp+390h]
  __int64 v145; // [rsp+4A0h] [rbp+398h]
  __int16 *v146; // [rsp+4A8h] [rbp+3A0h]
  __int64 v147; // [rsp+4B0h] [rbp+3A8h]
  __int64 v148; // [rsp+4B8h] [rbp+3B0h]
  int v149; // [rsp+4C0h] [rbp+3B8h]
  int v150; // [rsp+4C4h] [rbp+3BCh]
  __int16 *v151; // [rsp+4C8h] [rbp+3C0h]
  __int64 v152; // [rsp+4D0h] [rbp+3C8h]
  int *v153; // [rsp+4D8h] [rbp+3D0h]
  __int64 v154; // [rsp+4E0h] [rbp+3D8h]
  int *v155; // [rsp+4E8h] [rbp+3E0h]
  __int64 v156; // [rsp+4F0h] [rbp+3E8h]
  int *v157; // [rsp+4F8h] [rbp+3F0h]
  __int64 v158; // [rsp+500h] [rbp+3F8h]
  int *v159; // [rsp+508h] [rbp+400h]
  __int64 v160; // [rsp+510h] [rbp+408h]
  int *v161; // [rsp+518h] [rbp+410h]
  __int64 v162; // [rsp+520h] [rbp+418h]
  int *v163; // [rsp+528h] [rbp+420h]
  __int64 v164; // [rsp+530h] [rbp+428h]
  int *v165; // [rsp+538h] [rbp+430h]
  __int64 v166; // [rsp+540h] [rbp+438h]
  char *v167; // [rsp+548h] [rbp+440h]
  __int64 v168; // [rsp+550h] [rbp+448h]
  int *v169; // [rsp+558h] [rbp+450h]
  __int64 v170; // [rsp+560h] [rbp+458h]
  int *v171; // [rsp+568h] [rbp+460h]
  __int64 v172; // [rsp+570h] [rbp+468h]
  __int16 *v173; // [rsp+578h] [rbp+470h]
  __int64 v174; // [rsp+580h] [rbp+478h]
  __int64 v175; // [rsp+588h] [rbp+480h]
  int v176; // [rsp+590h] [rbp+488h]
  int v177; // [rsp+594h] [rbp+48Ch]
  int *v178; // [rsp+598h] [rbp+490h]
  __int64 v179; // [rsp+5A0h] [rbp+498h]

  v1 = *((_DWORD *)this + 8);
  v2 = v1 & 0xF;
  v3 = v1 >> 4;
  v4 = 1 << v2;
  if ( (unsigned int)dword_180091480 <= 5
    || (qword_180091490 & 0x400000000000i64) == 0
    || (qword_180091498 & 0x400000000000i64) != qword_180091498 )
  {
    return;
  }
  v5 = *((unsigned __int16 *)this + 892);
  v6 = *((unsigned __int16 *)this + 788);
  v7 = (const WCHAR *)((char *)this + 664);
  v70 = *((_DWORD *)this + 395);
  v71 = *((_DWORD *)this + 11);
  v72 = *((_DWORD *)this + 28);
  v64 = *((_BYTE *)this + 108);
  v73 = *((_DWORD *)this + 26);
  v74 = *((_DWORD *)this + 15);
  v75 = *((_DWORD *)this + 14);
  v76 = *((_DWORD *)this + 13);
  v77 = *((_DWORD *)this + 12);
  v78 = *((_DWORD *)this + 10);
  v79 = *((_DWORD *)this + 9);
  v80 = *((_DWORD *)this + 18);
  v81 = *((_DWORD *)this + 17);
  v68 = *((_WORD *)this + 33);
  LOWORD(v69) = *((_WORD *)this + 32);
  v119[0] = *((_QWORD *)this + 16);
  v85 = *((_QWORD *)this + 15);
  v65 = *((_BYTE *)this + 24);
  v119[1] = (__int64)this + 1176;
  v120 = v6;
  v67 = v5;
  v121 = (__int64)this + 1584;
  v122 = v5;
  v123 = (__int64)this + 664;
  v82 = v3;
  v8 = v4 < 0 ? *((_QWORD *)this + 12) : 0i64;
  v86 = v8;
  v9 = (v4 & 0x4000) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v87 = v9;
  v10 = (v4 & 0x2000) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v88 = v10;
  v11 = (v4 & 0x1000) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v89 = v11;
  v12 = (v4 & 0x800) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v90 = v12;
  v13 = (v4 & 0x400) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v91 = v13;
  v14 = (v4 & 0x200) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v92 = v14;
  v15 = (v4 & 0x100) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v93 = v15;
  v16 = (v4 & 0x80u) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v94 = v16;
  v17 = (v4 & 0x40) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v95 = v17;
  v18 = (v4 & 0x20) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v96 = v18;
  v19 = (v4 & 0x10) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v97 = v19;
  v20 = (v4 & 8) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v98 = v20;
  v21 = (v4 & 4) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v99 = v21;
  v22 = (v4 & 2) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v100 = v22;
  v23 = (v4 & 1) != 0 ? *((_QWORD *)this + 12) : 0i64;
  v101 = v23;
  v118 = 1i64;
  v179 = 4i64;
  v102 = (unsigned __int16)v4 & 0x8000;
  v174 = 2i64;
  v103 = v4 & 0x4000;
  v175 = (__int64)this + 1176;
  v104 = v4 & 0x2000;
  v177 = 0;
  v105 = v4 & 0x1000;
  v172 = 4i64;
  v106 = v4 & 0x800;
  v170 = 4i64;
  v107 = v4 & 0x400;
  v168 = 1i64;
  v108 = v4 & 0x200;
  v166 = 4i64;
  v109 = v4 & 0x100;
  v164 = 4i64;
  v110 = (unsigned __int8)v4 & 0x80;
  v162 = 4i64;
  v111 = v4 & 0x40;
  v112 = v4 & 0x20;
  v113 = v4 & 0x10;
  v114 = v4 & 8;
  v115 = v4 & 4;
  v116 = v4 & 2;
  v178 = &v70;
  v173 = &v120;
  v176 = 4 * v6;
  v171 = &v71;
  v169 = &v72;
  v167 = &v64;
  v165 = &v73;
  v163 = &v74;
  v161 = &v75;
  v159 = &v76;
  v117 = v4 & 1;
  v160 = 4i64;
  v157 = &v77;
  v155 = &v78;
  v153 = &v79;
  v151 = &v67;
  v146 = &v122;
  v149 = 4 * v5;
  v144 = &v80;
  v142 = &v81;
  v140 = &v68;
  v138 = &v69;
  v136 = v119;
  v134 = &v85;
  v132 = &v65;
  v158 = 4i64;
  v156 = 4i64;
  v154 = 4i64;
  v152 = 2i64;
  v147 = 2i64;
  v148 = (__int64)this + 1584;
  v150 = 0;
  v145 = 4i64;
  v143 = 4i64;
  v141 = 2i64;
  v139 = 2i64;
  v137 = 8i64;
  v135 = 8i64;
  v133 = 1i64;
  if ( this == (CSchannelTelemetryContext *)-664i64 )
  {
    v7 = &Class;
    v26 = 2;
  }
  else
  {
    v24 = -1i64;
    while ( v7[++v24] != 0 )
      ;
    v26 = 2 * v24 + 2;
  }
  v129[67] = (__int64)v7;
  v129[65] = (__int64)&v82;
  v129[63] = (__int64)&v86;
  v129[61] = (__int64)&v87;
  v129[59] = (__int64)&v88;
  v129[57] = (__int64)&v89;
  v129[55] = (__int64)&v90;
  v129[53] = (__int64)&v91;
  v129[51] = (__int64)&v92;
  v129[49] = (__int64)&v93;
  v129[47] = (__int64)&v94;
  v129[45] = (__int64)&v95;
  v129[43] = (__int64)&v96;
  v129[41] = (__int64)&v97;
  v129[39] = (__int64)&v98;
  v129[37] = (__int64)&v99;
  v129[35] = (__int64)&v100;
  v129[33] = (__int64)&v101;
  v129[31] = (__int64)&v102;
  v129[29] = (__int64)&v103;
  v129[27] = (__int64)&v104;
  v129[25] = (__int64)&v105;
  v129[23] = (__int64)&v106;
  v129[21] = (__int64)&v107;
  v129[19] = (__int64)&v108;
  v129[17] = (__int64)&v109;
  v129[15] = (__int64)&v110;
  v130 = v26;
  v131 = 0;
  v129[66] = 4i64;
  v129[64] = 8i64;
  v129[62] = 8i64;
  v129[60] = 8i64;
  v129[58] = 8i64;
  v129[56] = 8i64;
  v129[54] = 8i64;
  v129[52] = 8i64;
  v129[50] = 8i64;
  v129[48] = 8i64;
  v129[46] = 8i64;
  v129[44] = 8i64;
  v129[42] = 8i64;
  v129[40] = 8i64;
  v129[38] = 8i64;
  v129[36] = 8i64;
  v129[34] = 8i64;
  v129[32] = 8i64;
  v129[30] = 8i64;
  v129[28] = 8i64;
  v129[26] = 8i64;
  v129[24] = 8i64;
  v129[22] = 8i64;
  v129[20] = 8i64;
  v129[18] = 8i64;
  v129[16] = 8i64;
  v129[14] = 8i64;
  v129[13] = (__int64)&v111;
  v129[12] = 8i64;
  v129[11] = (__int64)&v112;
  v129[9] = (__int64)&v113;
  v129[7] = (__int64)&v114;
  v129[5] = (__int64)&v115;
  v129[3] = (__int64)&v116;
  v129[1] = (__int64)&v117;
  v128 = &v118;
  *(_DWORD *)&EventDescriptor.Level = 5;
  UserData.Ptr = (ULONGLONG)off_180091488;
  v129[10] = 8i64;
  v129[8] = 8i64;
  v129[6] = 8i64;
  v129[4] = 8i64;
  v129[2] = 8i64;
  v129[0] = 8i64;
  *(_DWORD *)&EventDescriptor.Id = 184549376;
  EventDescriptor.Keyword = 0x400000000000i64;
  UserData.Size = *(unsigned __int16 *)off_180091488;
  Buf1 = &unk_180083F6C;
  UserData.Reserved = 2;
  v126 = 1137;
  v127 = 1;
  LODWORD(v66) = (unsigned int)&TraceLoggingMetadataEnd - (unsigned int)&TraceLoggingMetadata;
  if ( (void (__fastcall *)(const struct _GUID *, unsigned int, __int64, __int64, unsigned __int64, struct _EVENT_FILTER_DESCRIPTOR *, _QWORD *))qword_1800914A8 != TlgAggregateInternalRegisteredProviderEtwCallback )
    return;
  v27 = 0;
  v28 = (char *)&unk_180083F6E;
  do
    v29 = *v28++;
  while ( v29 < 0 );
  while ( *v28++ )
    ;
  if ( v28 >= (char *)&unk_1800843DD )
    goto LABEL_117;
  while ( 1 )
  {
    while ( *v28++ )
      ;
    if ( *v28 >= 0 )
      break;
    v32 = v28[1];
    v33 = *v28 & 0x7F;
    v28 += 2;
    if ( v32 >= 0 )
      break;
    v34 = *v28;
    if ( *v28 < 0 )
    {
      while ( v34 == (char)0x80 )
      {
        v34 = *++v28;
        if ( v34 >= 0 )
          goto LABEL_51;
      }
      break;
    }
LABEL_51:
    if ( v33 == 9 && (unsigned __int8)(v34 - 113) <= 2u )
    {
      v35 = v27++;
      BYTE5(v129[2 * v35]) = v34;
      if ( v28 < (char *)&unk_1800843DD )
        continue;
    }
    break;
  }
  if ( !v27 )
  {
LABEL_117:
    EventWriteTransfer_0(RegHandle, &EventDescriptor, 0i64, 0i64, 0x3Cu, &UserData);
    return;
  }
  v36 = 0i64;
  v37 = qword_1800914B0;
  v66 = 0i64;
  v83 = qword_1800914B0;
  v38 = 1025
      * (BYTE4(Buf1)
       + ((1025
         * (BYTE3(Buf1)
          + ((1025
            * (BYTE2(Buf1)
             + ((1025
               * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) ^ ((1025 * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) >> 6)))) ^ ((1025 * (BYTE2(Buf1) + ((1025 * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) ^ ((1025 * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) >> 6)))) >> 6)))) ^ ((1025 * (BYTE3(Buf1) + ((1025 * (BYTE2(Buf1) + ((1025 * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) ^ ((1025 * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) >> 6)))) ^ ((1025 * (BYTE2(Buf1) + ((1025 * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) ^ ((1025 * (BYTE1(Buf1) + ((1025 * (unsigned __int8)Buf1) ^ ((1025 * (unsigned int)(unsigned __int8)Buf1) >> 6)))) >> 6)))) >> 6)))) >> 6)));
  v39 = 1025 * (BYTE5(Buf1) + (v38 ^ (v38 >> 6)));
  v40 = 1025 * (BYTE6(Buf1) + (v39 ^ (v39 >> 6)));
  v41 = v27 + 2;
  v42 = ((1025 * (HIBYTE(Buf1) + (v40 ^ (v40 >> 6)))) >> 6) ^ (1025 * (HIBYTE(Buf1) + (v40 ^ (v40 >> 6))));
  if ( (unsigned __int8)(v27 + 2) < 0x3Cu )
  {
    v43 = &UserData + v41;
    v44 = (unsigned __int8)(60 - v41);
    do
    {
      for ( i = 0i64; i < v43->Size; v42 = ((1025 * (v42 + v46)) >> 6) ^ (1025 * (v42 + v46)) )
      {
        v46 = *(unsigned __int8 *)(i + v43->Ptr);
        ++i;
      }
      ++v43;
      --v44;
    }
    while ( v44 );
  }
  v47 = (RTL_SRWLOCK *)(qword_1800914B0 + 264);
  v48 = 32769 * ((9 * v42) ^ ((9 * v42) >> 11));
  AcquireSRWLockShared((PSRWLOCK)(qword_1800914B0 + 264));
  for ( j = (volatile signed __int64 *)(v37 + 8i64 * (v48 & 0x1F));
        ;
        j = (volatile signed __int64 *)((((__int64)v53 >> 63) & 0xFFFFFFFFFFFFFFF8ui64) + v50 + 32) )
  {
    if ( !*j )
    {
      if ( *(_DWORD *)(v37 + 256) >= 0x400u )
      {
        ++*(_DWORD *)(v37 + 300);
        goto LABEL_74;
      }
      if ( !v36 )
      {
        v60 = CreateNewEventEntry((__int128 *)&EventDescriptor, 0x3Cu, (__int64)&UserData, v27, v48, &v66);
        v36 = v66;
        if ( !v66 )
        {
          if ( v60 == 8 )
            ++*(_DWORD *)(v37 + 304);
          else
            ++*(_DWORD *)(v37 + 308);
          goto LABEL_74;
        }
      }
      if ( !_InterlockedCompareExchange64(j, v36, 0i64) )
      {
        v66 = 0i64;
        if ( _InterlockedIncrement((volatile signed __int32 *)(v37 + 256)) == 1 )
          EnableFlushTimer(*(struct _TP_TIMER **)(v37 + 344), *(_DWORD *)(v37 + 352));
        v61 = *(_DWORD *)(v37 + 256);
        v36 = v66;
        if ( *(_DWORD *)(v37 + 288) < v61 )
          *(_DWORD *)(v37 + 288) = v61;
        goto LABEL_74;
      }
      v36 = v66;
    }
    v50 = *j;
    v51 = *(_DWORD *)(v50 + 40);
    if ( v48 != v51 )
    {
      v53 = v48 - v51;
      continue;
    }
    v52 = *(_QWORD *)(v50 + 16);
    v53 = memcmp_0(&Buf1, (const void *)(v52 + 16), 8ui64);
    if ( v53 )
      continue;
    v54 = *(unsigned __int8 *)(v50 + 45) + 2;
    if ( v54 >= 0x3C )
      break;
    while ( 1 )
    {
      v53 = *(&UserData.Size + 4 * v54) - *(_DWORD *)(v52 + 16i64 * v54 + 8);
      if ( v53 )
        break;
      v53 = memcmp_0(
              *((const void **)&UserData.Ptr + 2 * v54),
              *(const void **)(v52 + 16i64 * v54),
              *(&UserData.Size + 4 * v54));
      if ( v53 )
        break;
      if ( ++v54 >= 0x3C )
        goto LABEL_68;
    }
    v37 = v83;
  }
LABEL_68:
  if ( v50 )
  {
    v55 = 2;
    do
    {
      v56 = **((_QWORD **)&UserData.Ptr + 2 * v55);
      v57 = *(_QWORD *)(v50 + 16);
      v58 = *(unsigned __int8 *)(v57 + 16i64 * v55 + 13);
      v59 = *(volatile signed __int64 **)(v57 + 16i64 * v55);
      if ( v58 == 113 )
      {
        _InterlockedExchangeAdd64(v59, v56);
      }
      else if ( (unsigned int)(v58 - 114) <= 1 )
      {
        do
        {
          v62 = *v59;
          if ( (_BYTE)v58 == 114 )
          {
            if ( v56 >= v62 )
              break;
          }
          else if ( v56 <= v62 )
          {
            break;
          }
          v63 = *v59;
        }
        while ( v63 != _InterlockedCompareExchange64(v59, v56, v62) );
      }
      ++v55;
    }
    while ( v55 < (unsigned int)v27 + 2 );
    v36 = v66;
  }
LABEL_74:
  ReleaseSRWLockShared(v47);
  if ( v36 )
    DestroyEventEntry(v36);
}
// 1800220DF: conditional instruction was optimized away because bl.1!=0
// 180091488: using guessed type void *off_180091488;
// 180091490: using guessed type __int64 qword_180091490;
// 180091498: using guessed type __int64 qword_180091498;
// 1800914A8: using guessed type __int64 qword_1800914A8;
// 1800914B0: using guessed type __int64 qword_1800914B0;

