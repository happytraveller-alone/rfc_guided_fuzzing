// File count: 443
// Total lines: 755
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::DigestClientHello(
        CSsl3TlsServerContext *this,
        unsigned __int8 *Src,
        SIZE_T uBytes,
        char a4,
        unsigned __int8 *a5)
{
  unsigned __int8 *v5; // r13
  SIZE_T v6; // rdi
  char v9; // r15
  __int64 v10; // r8
  bool v11; // zf
  unsigned int v12; // ebx
  __int64 v13; // r12
  __int64 v14; // rax
  __int64 v15; // rcx
  HLOCAL v16; // rax
  unsigned int v17; // edi
  struct _RTL_RESOURCE *v18; // rsi
  unsigned int v19; // ecx
  __int64 v20; // rax
  unsigned __int64 v21; // r10
  unsigned int v22; // r13d
  const wchar_t **v23; // rsi
  unsigned __int8 v24; // bl
  int v25; // eax
  __int64 v26; // r8
  __int16 v27; // ax
  ULONG v28; // eax
  ULONG v29; // ebx
  __int64 v30; // rax
  unsigned int v31; // r8d
  size_t v32; // rdi
  unsigned int v33; // ecx
  unsigned int v34; // ecx
  unsigned int v35; // ebx
  __int64 v36; // r12
  int v37; // esi
  char v38; // al
  int v39; // ecx
  __int64 v40; // r13
  _QWORD **v41; // rcx
  _QWORD *v42; // r15
  __int64 v43; // rbx
  unsigned int v44; // eax
  unsigned int v45; // edx
  unsigned int v46; // ecx
  signed __int32 v47; // edi
  __int64 v48; // rdx
  _QWORD *v49; // rcx
  char v50; // al
  __int64 v51; // rax
  unsigned int v52; // ecx
  unsigned int v53; // r15d
  __int64 v54; // rdx
  int v55; // r10d
  __int64 v56; // r8
  int v57; // ebx
  __int64 v58; // rcx
  __int64 v59; // r13
  __int64 v60; // rcx
  __int64 v61; // rax
  __int64 *v62; // rsi
  __int64 v63; // rax
  __int64 v64; // rdi
  __int64 v65; // rbx
  __int64 v66; // rcx
  volatile signed __int32 *v67; // rcx
  __int64 v68; // r12
  unsigned int v69; // r9d
  unsigned int v70; // r8d
  __int64 v71; // rax
  int v72; // eax
  int v73; // r9d
  __int64 *v74; // r8
  unsigned int v75; // r10d
  unsigned int v76; // edx
  __int64 v77; // r8
  __int64 v78; // rcx
  __int64 v79; // rax
  __int64 v81; // rax
  int v82; // eax
  __int64 v83; // rcx
  CSessionCacheManager *v84; // rsi
  int v85; // r12d
  unsigned int v86; // r15d
  CSessionCacheItem *v87; // rax
  CSessionCacheItem *v88; // rdi
  unsigned int v89; // ebx
  CSessionCacheTable *v90; // rcx
  _QWORD *v91; // rsi
  __int64 *v92; // r8
  __int64 v93; // rcx
  __int64 **v94; // rax
  _QWORD *v95; // rsi
  _QWORD *v96; // rcx
  _QWORD *v97; // rax
  CSessionCacheManager *v98; // rax
  __int64 v99; // rcx
  unsigned int v100; // ecx
  unsigned int v101; // r9d
  unsigned int *v102; // r8
  int v103; // eax
  __int64 v104; // rax
  unsigned int v105; // ecx
  int v106; // eax
  size_t v107; // [rsp+20h] [rbp-E0h]
  unsigned int v109; // [rsp+44h] [rbp-BCh] BYREF
  DWORD CurrentProcessId; // [rsp+48h] [rbp-B8h]
  unsigned __int64 v111; // [rsp+50h] [rbp-B0h]
  size_t Size; // [rsp+58h] [rbp-A8h] BYREF
  unsigned __int8 *v113; // [rsp+60h] [rbp-A0h]
  unsigned int *v114; // [rsp+68h] [rbp-98h] BYREF
  CSessionCacheManager *v115; // [rsp+70h] [rbp-90h]
  PRTL_RESOURCE Resource; // [rsp+78h] [rbp-88h]
  __int64 v117; // [rsp+80h] [rbp-80h] BYREF
  unsigned __int8 v118[16]; // [rsp+88h] [rbp-78h] BYREF
  __int128 v119; // [rsp+98h] [rbp-68h]
  int v120[6]; // [rsp+A8h] [rbp-58h] BYREF
  _BYTE Source1[20]; // [rsp+C0h] [rbp-40h] BYREF
  __int16 v122; // [rsp+D8h] [rbp-28h] BYREF
  __int128 v123; // [rsp+DAh] [rbp-26h]
  __int128 v124; // [rsp+EAh] [rbp-16h]
  __int16 v125; // [rsp+FAh] [rbp-6h]
  char v126[272]; // [rsp+100h] [rbp+0h] BYREF
  UCHAR pbBuffer[16]; // [rsp+210h] [rbp+110h] BYREF
  __int128 v128; // [rsp+220h] [rbp+120h]
  __int128 Buf1[2]; // [rsp+230h] [rbp+130h] BYREF

  v5 = a5;
  v6 = (unsigned int)uBytes;
  v113 = a5;
  LODWORD(Size) = 0;
  memset(Buf1, 0, sizeof(Buf1));
  v9 = a4;
  memset_0(v126, 0, sizeof(v126));
  v11 = *((_BYTE *)this + 233) == 0;
  v12 = 4;
  v109 = 68;
  v114 = (unsigned int *)v126;
  v13 = 12i64;
  if ( !v11 )
    v12 = 12;
  v115 = CSessionCacheManager::m_pSessionCacheManager;
  *(_OWORD *)pbBuffer = 0i64;
  v128 = 0i64;
  if ( !Src || (unsigned int)v6 < v12 || !a5 )
    return 87i64;
  *a5 = 0;
  if ( *((_QWORD *)this + 110) )
  {
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 110) = 0i64;
  }
  v14 = *((_QWORD *)this + 16);
  *((_DWORD *)this + 218) = v6;
  v15 = *(_QWORD *)(v14 + 24);
  if ( v15 )
  {
    LOBYTE(v10) = 1;
    v16 = (HLOCAL)(*(__int64 (__fastcall **)(__int64, SIZE_T, __int64))(*(_QWORD *)v15 + 48i64))(v15, v6, v10);
  }
  else if ( LsaTable )
  {
    v16 = (HLOCAL)(*(__int64 (__fastcall **)(_QWORD))(LsaTable + 40))((unsigned int)v6);
  }
  else
  {
    v16 = LocalAlloc(0x40u, v6);
  }
  *((_QWORD *)this + 110) = v16;
  if ( !v16 )
  {
    v29 = 14;
    goto LABEL_123;
  }
  memcpy_0(v16, Src, *((unsigned int *)this + 218));
  v17 = v6 - v12;
  v18 = (struct _RTL_RESOURCE *)&Src[v12];
  CurrentProcessId = v17;
  v11 = (*((_DWORD *)this + 16) & 0x40400) == 0;
  Resource = v18;
  if ( !v11 )
  {
    RtlAcquireResourceShared(&::Resource, 1u);
    *((_WORD *)this + 237) = 0;
    *((_WORD *)this + 254) = 0;
    v19 = (unsigned __int16)word_1800925E8;
    if ( (unsigned __int16)word_1800925E8 <= 0x10u )
    {
      *((_WORD *)this + 237) = word_1800925E8;
      *((_WORD *)this + 254) = word_18009260A;
      memcpy_0((char *)this + 476, &xmmword_1800925EA, 2i64 * v19);
    }
    RtlReleaseResource(&::Resource);
    v20 = *((_QWORD *)this + 10);
    v21 = *(_QWORD *)(v20 + 200);
    v111 = v21;
    if ( v21 )
    {
      v22 = *(_DWORD *)(v20 + 196);
      if ( v22 )
      {
        v23 = (const wchar_t **)&off_18007C3B0;
        *((_WORD *)this + 237) = 0;
        v24 = 0;
        do
        {
          if ( v24 < 0xCu )
          {
            v25 = *((unsigned __int16 *)this + 254);
            if ( ((1 << v24) & v25) != 0 )
            {
              *((_WORD *)this + 254) = v25 & ~(1 << v24);
              if ( IsCngAlgorithmBlacklisted(v21, v22, 4, v23[2], 0i64, 0, 0i64, 1)
                || IsCngAlgorithmBlacklisted(v111, v22, 4, *v23, 0i64, 0, 0i64, 1)
                || (*((unsigned __int16 *)this + 254) & (1 << v24)) != 0 )
              {
                v21 = v111;
              }
              else
              {
                v26 = *((unsigned __int16 *)this + 237);
                v21 = v111;
                if ( (unsigned int)v26 < 0x10 )
                {
                  *((_WORD *)this + v26 + 238) = __ROR2__(*((_WORD *)&unk_18007C390 + 36 * v24), 8);
                  v27 = *((_WORD *)this + 254);
                  ++*((_WORD *)this + 237);
                  *((_WORD *)this + 254) = v27 | (1 << v24);
                }
              }
            }
          }
          v23 += 9;
          ++v24;
          --v13;
        }
        while ( v13 );
        if ( !*((_WORD *)this + 237) )
        {
          v29 = -2146893007;
          goto LABEL_123;
        }
        v17 = CurrentProcessId;
        v18 = Resource;
        v9 = a4;
      }
      v5 = v113;
    }
    *((_BYTE *)this + 925) = 0;
  }
  v28 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *, struct _RTL_RESOURCE *, _QWORD, __int128 *, size_t *, unsigned int **, unsigned int *))(*(_QWORD *)this + 528i64))(
          this,
          v18,
          v17,
          Buf1,
          &Size,
          &v114,
          &v109);
  v29 = v28;
  if ( v28 )
  {
    if ( v28 != -2146892986 && v28 != -2146892953 )
    {
      v29 = -2146893048;
      CSslContext::SetErrorAndFatalAlert((__int64)this, 1200, -2146893048, 0xAu);
    }
    goto LABEL_123;
  }
  v30 = *((_QWORD *)this + 17);
  if ( (v30 & 0x8000000) == 0 )
    *((_QWORD *)this + 17) = v30 & 0xFFFFFFFFFFBFFFFFui64;
  if ( (*((_DWORD *)this + 16) & 0x40400) != 0 )
  {
    if ( !*((_BYTE *)this + 925) )
    {
      v122 = 0;
      v123 = 0i64;
      v125 = 0;
      v124 = 0i64;
      CTlsSignatureSuiteList::SetDefaultClientHello((CTlsSignatureSuiteList *)&v122);
      CTlsSignatureSuiteList::SetSignatureSuiteList(
        (CSsl3TlsServerContext *)((char *)this + 510),
        (CSsl3TlsServerContext *)((char *)this + 474));
      CTlsSignatureSuiteList::Restrict(
        (CSsl3TlsServerContext *)((char *)this + 510),
        (const struct CTlsSignatureSuiteList *)&v122,
        *((_DWORD *)this + 16));
    }
    if ( !*((_WORD *)this + 255) )
    {
      v29 = -2146893007;
      CSslContext::SetErrorAndFatalAlert((__int64)this, 1206, -2146893007, 0x28u);
      goto LABEL_123;
    }
  }
  if ( !v9 || (*((_DWORD *)this + 34) & 0x8000000) == 0 )
    goto LABEL_119;
  v31 = *((_DWORD *)this + 246);
  if ( v31 )
  {
    LODWORD(v107) = Size;
    *v5 = CSsl3TlsServerContext::UnprotectAndDeserializeSessionState(
            this,
            *((unsigned __int8 *const *)this + 122),
            v31,
            (unsigned __int8 *const)Buf1,
            v107);
    v104 = *((_QWORD *)this + 15);
    if ( v104 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
    {
      *(_WORD *)(v104 + 64) |= 2u;
      *(_DWORD *)(v104 + 24) = 1;
    }
    goto LABEL_74;
  }
  v32 = (unsigned int)Size;
  if ( !(_DWORD)Size )
    goto LABEL_74;
  if ( (unsigned int)Size < 4 )
  {
    v50 = 0;
    goto LABEL_71;
  }
  if ( LODWORD(Buf1[0]) >= *((_DWORD *)v115 + 4) )
  {
    v50 = 0;
    goto LABEL_71;
  }
  v33 = *((_DWORD *)v115 + 13);
  if ( v33 == 1000 )
  {
    v34 = LODWORD(Buf1[0]) / 0x3E8;
    v35 = LODWORD(Buf1[0]) - 1000 * ((LODWORD(Buf1[0]) / 0x3E8) & 0x3FFFFFF);
  }
  else
  {
    v35 = LODWORD(Buf1[0]) % v33;
    v34 = LODWORD(Buf1[0]) / v33;
  }
  v36 = *((_QWORD *)v115 + 5) + 152i64 * v34;
  v37 = 0;
  LODWORD(v111) = GetTickCount();
  if ( LsaTable )
  {
    v38 = (*(__int64 (__fastcall **)(int *))(LsaTable + 192))(v120);
    v39 = -1;
    if ( v38 )
      v39 = v120[0];
    CurrentProcessId = v39;
  }
  else
  {
    CurrentProcessId = GetCurrentProcessId();
  }
  Resource = (PRTL_RESOURCE)(v36 + 48);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(v36 + 48), 1u);
  v40 = 16i64 * v35;
  v41 = (_QWORD **)(v40 + *(_QWORD *)v36);
  v42 = *v41;
  if ( *v41 == v41 )
  {
LABEL_170:
    v43 = v117;
    goto LABEL_68;
  }
  while ( 1 )
  {
    v43 = (__int64)(v42 - 36);
    v42 = (_QWORD *)*v42;
    RtlAcquireResourceShared((PRTL_RESOURCE)(v43 + 72), 1u);
    if ( !*(_BYTE *)(v43 + 236) )
      goto LABEL_126;
    v44 = *(_DWORD *)(v43 + 276);
    v45 = *(_DWORD *)(v43 + 280);
    v46 = v111 - v44;
    if ( (unsigned int)v111 <= v44 )
      break;
    if ( v46 <= v45 )
      goto LABEL_53;
LABEL_126:
    RtlReleaseResource((PRTL_RESOURCE)(v43 + 72));
    if ( v42 == (_QWORD *)(v40 + *(_QWORD *)v36) )
    {
      RtlReleaseResource(Resource);
      goto LABEL_169;
    }
  }
  if ( (unsigned int)v111 < v44 && v46 - 1 >= v45 )
    goto LABEL_126;
LABEL_53:
  if ( (_DWORD)v32 != *(unsigned __int16 *)(v43 + 238) )
    goto LABEL_126;
  if ( memcmp_0(Buf1, (const void *)(v43 + 240), v32) )
    goto LABEL_126;
  if ( *(_DWORD *)(v43 + 272) != CurrentProcessId )
    goto LABEL_126;
  v117 = *(_QWORD *)(*((_QWORD *)this + 10) + 760i64);
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, _QWORD, _QWORD, __int64 *, _DWORD))(*(_QWORD *)v43 + 80i64))(
          v43,
          0i64,
          0i64,
          &v117,
          *((_DWORD *)this + 16)) )
    goto LABEL_126;
  v47 = _InterlockedIncrement((volatile signed __int32 *)(v43 + 232));
  v37 = v47;
  if ( v47 != 2 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(v43 + 72));
    if ( v47 )
      goto LABEL_60;
    goto LABEL_170;
  }
  LsaIModifyPerformanceCounter(5i64);
  RtlReleaseResource((PRTL_RESOURCE)(v43 + 72));
LABEL_60:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, (__int64)&WPP_54aae497645f38b3b161e68e12f6f932_Traceguids, v43);
  if ( v47 == 2 )
  {
    v48 = *(_QWORD *)(v43 + 320);
    if ( *(_QWORD *)(v48 + 8) == v43 + 320 )
    {
      v49 = *(_QWORD **)(v43 + 328);
      if ( *v49 == v43 + 320 )
      {
        *v49 = v48;
        *(_QWORD *)(v48 + 8) = v49;
        goto LABEL_67;
      }
    }
LABEL_140:
    __fastfail(3u);
  }
LABEL_67:
  LsaIModifyPerformanceCounter(9i64);
LABEL_68:
  RtlReleaseResource(Resource);
  if ( v37 <= 0 )
  {
LABEL_169:
    v50 = 0;
    *((_QWORD *)this + 124) = 0i64;
  }
  else
  {
    *((_QWORD *)this + 124) = v43;
    v50 = 1;
  }
  v5 = v113;
LABEL_71:
  *v5 = v50;
  v51 = *((_QWORD *)this + 15);
  if ( v51 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
  {
    *(_WORD *)(v51 + 64) |= 1u;
    *(_DWORD *)(v51 + 24) = 1;
  }
LABEL_74:
  if ( *v5 )
  {
    v52 = v109;
    v53 = 0;
    if ( !v109 )
      goto LABEL_118;
    v54 = *(_QWORD *)(*((_QWORD *)this + 124) + 176i64);
    while ( 1 )
    {
      v55 = v54 ? *(_DWORD *)(v54 + 28) : 0;
      v56 = v53;
      if ( v114[v56] == v55 )
        break;
      if ( ++v53 >= v109 )
        goto LABEL_118;
    }
    v57 = *((_DWORD *)this + 17);
    if ( (unsigned int)CCipherMill::ChooseServerCipher(
                         (CCipherMill *)g_cCipherMill,
                         this,
                         &v114[v56],
                         1u,
                         *((_DWORD *)this + 16),
                         *v5) )
    {
      *((_WORD *)this + 48) = 0;
      *((_DWORD *)this + 17) = v57;
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 48i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      v58 = *((_QWORD *)this + 124);
      *((_QWORD *)this + 11) = v58;
      RtlAcquireResourceExclusive((PRTL_RESOURCE)(v58 + 72), 1u);
      v59 = *((_QWORD *)this + 11);
      v60 = *(_QWORD *)(v59 + 176);
      v61 = *(_QWORD *)(v60 + 848);
      if ( v61 )
        _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v61 + 16) + 12i64));
      _InterlockedIncrement((volatile signed __int32 *)(*(_QWORD *)(v60 + 856) + 12i64));
      v62 = *(__int64 **)(v59 + 176);
      v63 = (*(__int64 (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 248i64))(this);
      v64 = *((_QWORD *)this + 1);
      v65 = v63;
      if ( v64 )
      {
        v66 = *(_QWORD *)(v64 + 848);
        if ( v66 )
          CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v66 + 16));
        CMasterCipherInfo::Dereference(*(CMasterCipherInfo **)(v64 + 856));
      }
      v67 = (volatile signed __int32 *)*((_QWORD *)this + 3);
      if ( v67 )
      {
        if ( _InterlockedExchangeAdd(v67 + 6, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v67 + 8i64))(v67, 1i64);
        *((_QWORD *)this + 3) = 0i64;
      }
      if ( v65 )
      {
        v68 = *v62;
        RtlAcquireResourceShared((PRTL_RESOURCE)(v65 + 552), 1u);
        v69 = *(_DWORD *)(v65 + 96);
        v70 = 0;
        if ( v69 )
        {
          while ( 1 )
          {
            v71 = *(_QWORD *)(*(_QWORD *)(v65 + 88) + 8i64 * v70);
            if ( *(_QWORD *)(v71 + 16) == v68 )
              break;
            if ( ++v70 >= v69 )
              goto LABEL_100;
          }
          _InterlockedIncrement((volatile signed __int32 *)(v71 + 24));
          *((_QWORD *)this + 3) = *(_QWORD *)(*(_QWORD *)(v65 + 88) + 8i64 * v70);
        }
LABEL_100:
        RtlReleaseResource((PRTL_RESOURCE)(v65 + 552));
      }
      if ( (*((_DWORD *)this + 16) & 0xF3F00) != 0 )
      {
        if ( !(unsigned int)SslLookupCipherLengths(
                              *v62,
                              *((unsigned __int16 *)this + 17),
                              *((unsigned int *)v62 + 7),
                              *((unsigned int *)this + 4),
                              Source1,
                              20,
                              0) )
          goto LABEL_103;
      }
      else
      {
        v105 = *((_DWORD *)v62 + 3);
        v106 = *((_DWORD *)v62 + 4);
        *(_QWORD *)Source1 = 20i64;
        *(_QWORD *)&Source1[12] = 0i64;
        *(_DWORD *)&Source1[8] = v106;
        if ( v105 > 1 )
        {
          *(_DWORD *)&Source1[16] |= 1u;
          *(_DWORD *)&Source1[12] = v105;
        }
LABEL_103:
        if ( (*((_BYTE *)this + 32) & 1) == 0 || RtlCompareMemory(Source1, (char *)this + 40, 0x14ui64) == 20 )
        {
          v72 = *(_DWORD *)&Source1[16];
          *(_OWORD *)((char *)this + 40) = *(_OWORD *)Source1;
          *((_DWORD *)this + 14) = v72;
        }
      }
      *((_WORD *)this + 16) |= 1u;
      *((_QWORD *)this + 1) = v62;
      v73 = *(_DWORD *)(v59 + 184);
      *((_DWORD *)this + 4) = v73;
      v74 = (__int64 *)v62[106];
      if ( v74 )
      {
        v75 = *((_DWORD *)v74 + 2);
        v76 = 0;
        if ( v75 )
        {
          v77 = *v74;
          while ( 1 )
          {
            v78 = 780i64 * v76;
            if ( *(_DWORD *)(v77 + v78 + 772) == v73 )
              break;
            if ( ++v76 >= v75 )
              goto LABEL_114;
          }
          if ( v77 + v78 )
            *((_DWORD *)this + 5) = *(_DWORD *)(v77 + v78 + 776);
        }
      }
LABEL_114:
      RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
      v79 = *((_QWORD *)this + 15);
      if ( v79 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
      {
        *(_WORD *)(v79 + 64) |= 4u;
        *(_DWORD *)(v79 + 24) = 1;
      }
      v5 = v113;
      v52 = v109;
LABEL_118:
      if ( v53 != v52 )
      {
LABEL_119:
        if ( *v5 )
          goto LABEL_120;
        goto LABEL_129;
      }
    }
    *(_BYTE *)(*((_QWORD *)this + 124) + 236i64) = 0;
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 240i64))(this);
    *v5 = 0;
  }
LABEL_129:
  v81 = *((_QWORD *)this + 17);
  if ( (v81 & 0x800) != 0 && *((_DWORD *)this + 246) )
    *((_QWORD *)this + 17) = v81 | 0x400000;
  v82 = BCryptGenRandom(0i64, pbBuffer, 0x20u, 2u);
  if ( v82 >= 0 || (v29 = RtlNtStatusToDosError(v82)) == 0 )
  {
    if ( CSessionCacheManager::m_pSessionCacheManager )
    {
      v83 = *((_QWORD *)CSessionCacheManager::m_pSessionCacheManager + 5)
          + 152i64
          * ((unsigned int)(*(_DWORD *)pbBuffer % *((_DWORD *)CSessionCacheManager::m_pSessionCacheManager + 4))
           / *((_DWORD *)CSessionCacheManager::m_pSessionCacheManager + 13));
      if ( v83 )
        RtlAcquireResourceExclusive((PRTL_RESOURCE)(v83 + 48), 1u);
    }
    v84 = v115;
    v85 = *((_DWORD *)this + 16);
    v86 = *(_DWORD *)pbBuffer % *((_DWORD *)v115 + 4);
    *(_OWORD *)v118 = *(_OWORD *)pbBuffer;
    *(_DWORD *)v118 = v86;
    v119 = v128;
    if ( g_SslMachineID != -1 )
      *(_DWORD *)&v118[4] = g_SslMachineID;
    v87 = (CSessionCacheItem *)(*(__int64 (__fastcall **)(struct IAllocate *, __int64))(*(_QWORD *)CSessionCacheServerItem::m_pServerCacheLookaside
                                                                                      + 24i64))(
                                 CSessionCacheServerItem::m_pServerCacheLookaside,
                                 360i64);
    v88 = v87;
    if ( v87 )
    {
      CSessionCacheItem::CSessionCacheItem(v87, *((_DWORD *)v84 + 6), v118);
      *((_DWORD *)v88 + 54) = -2146893019;
      *(_QWORD *)v88 = &CSessionCacheServerItem::`vftable';
      *((_QWORD *)v88 + 42) = 0i64;
      *((_QWORD *)v88 + 43) = 0i64;
      *((_DWORD *)v88 + 88) = 0;
      v29 = *((_DWORD *)v88 + 17);
      if ( v29 )
      {
        CSessionCacheServerItem::`vector deleting destructor'(v88, 1);
      }
      else
      {
        v89 = *((_DWORD *)v84 + 13);
        v90 = (CSessionCacheTable *)(v86 / v89);
        v91 = (_QWORD *)(*((_QWORD *)v115 + 5) + 152i64 * (_QWORD)v90);
        CSessionCacheTable::ReferenceCacheItemInternal(v90, v88);
        *((_QWORD *)v88 + 28) = v91;
        v92 = (__int64 *)((char *)v88 + 288);
        v93 = *v91 + 16i64 * (v86 % v89);
        v94 = *(__int64 ***)(v93 + 8);
        if ( *v94 != (__int64 *)v93 )
          goto LABEL_140;
        *v92 = v93;
        v95 = v91 + 2;
        *((_QWORD *)v88 + 37) = v94;
        *v94 = v92;
        *(_QWORD *)(v93 + 8) = v92;
        v96 = (_QWORD *)((char *)v88 + 304);
        v97 = (_QWORD *)v95[1];
        if ( (_QWORD *)*v97 != v95 )
          goto LABEL_140;
        *((_QWORD *)v88 + 39) = v97;
        *v96 = v95;
        *v97 = v96;
        v98 = v115;
        v95[1] = v96;
        _InterlockedIncrement((volatile signed __int32 *)v98 + 8);
        LsaIModifyPerformanceCounter(4i64);
        *((_QWORD *)this + 124) = v88;
        v29 = 0;
        *((_DWORD *)v88 + 42) = v85;
      }
    }
    else
    {
      v29 = 14;
    }
    if ( CSessionCacheManager::m_pSessionCacheManager )
    {
      v99 = *((_QWORD *)CSessionCacheManager::m_pSessionCacheManager + 5)
          + 152i64
          * ((unsigned int)(*(_DWORD *)pbBuffer % *((_DWORD *)CSessionCacheManager::m_pSessionCacheManager + 4))
           / *((_DWORD *)CSessionCacheManager::m_pSessionCacheManager + 13));
      if ( v99 )
        RtlReleaseResource((PRTL_RESOURCE)(v99 + 48));
    }
    if ( !v29 )
    {
      v100 = *((_DWORD *)this + 16);
      v101 = v109;
      v102 = v114;
      *((_QWORD *)this + 11) = *((_QWORD *)this + 124);
      v103 = CCipherMill::ChooseServerCipher((CCipherMill *)g_cCipherMill, this, v102, v101, v100, *v5);
      v29 = v103;
      if ( v103 )
      {
        CSslContext::SetErrorAndFatalAlert((__int64)this, 1205, v103, 0x28u);
      }
      else
      {
LABEL_120:
        v11 = *((_BYTE *)this + 233) == 0;
        *((_BYTE *)this + 555) = 0;
        if ( !v11 )
          CSsl3TlsContext::FreeSavedWriteCipherState(this);
        v29 = 0;
      }
    }
  }
LABEL_123:
  *((_QWORD *)this + 122) = 0i64;
  *((_DWORD *)this + 246) = 0;
  if ( v114 != (unsigned int *)v126 )
    (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
  return v29;
}
// 1800311E3: variable 'v10' is possibly undefined
// 1800312EA: variable 'v107' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18007C330: using guessed type void *CSessionCacheServerItem::`vftable';
// 18007C3B0: using guessed type wchar_t *off_18007C3B0;
// 1800919F4: using guessed type unsigned int g_SslMachineID;
// 1800925E8: using guessed type __int16 word_1800925E8;
// 1800925EA: using guessed type __int128 xmmword_1800925EA;
// 18009260A: using guessed type __int16 word_18009260A;
// 180092620: using guessed type __int64 LsaTable;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 1800927F8: using guessed type struct IAllocate *CSessionCacheServerItem::m_pServerCacheLookaside;
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 1800984F0: using guessed type __int64 __fastcall SslLookupCipherLengths(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
// 18001CE80: using guessed type int var_1E8[6];
