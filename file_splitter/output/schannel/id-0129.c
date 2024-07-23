// File count: 129
// Total lines: 354
----------------------------------------
__int64 __fastcall CTlsExtClient::BuildClientHelloExtension(
        CTlsExtClient *this,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned int *a4)
{
  unsigned int v4; // eax
  unsigned __int16 *v5; // r12
  unsigned __int8 *v7; // r13
  unsigned __int8 *v8; // rsi
  int v9; // r11d
  unsigned __int8 v10; // al
  __int64 v11; // rax
  unsigned __int8 *v12; // rbx
  unsigned __int8 *v13; // rbx
  __int64 v14; // rcx
  int v15; // edx
  __int64 v16; // rcx
  unsigned int v17; // r9d
  __int16 v18; // cx
  _BYTE *v19; // rbx
  bool i; // cf
  __int64 v21; // r8
  __int64 v22; // rcx
  int v23; // edx
  _BYTE *v24; // rcx
  CTlsSignatureSuiteList *v25; // rcx
  int v26; // eax
  unsigned int v27; // edi
  unsigned __int8 *v28; // rbx
  __int64 v29; // rcx
  CTlsExt *v30; // rcx
  size_t v31; // rdi
  const void *v32; // r15
  unsigned int v33; // eax
  __int64 v34; // r15
  size_t v35; // rdi
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rcx
  __int64 v39; // rax
  __int16 v40; // r11
  __int64 v41; // rbx
  __int64 v42; // rbx
  __int64 result; // rax
  __int64 v44; // rax
  size_t v45; // rbx
  const void *v46; // rdi
  __int64 v47; // rcx
  __int64 v48; // rax
  size_t v49; // rbx
  unsigned __int8 *v50; // r15
  unsigned __int8 v51; // di
  __int16 v52; // ax
  __int16 v53; // cx
  char *v54; // rsi
  char *v55; // rbx
  __int64 v56; // rax
  __int64 v57; // [rsp+80h] [rbp+40h] BYREF
  unsigned __int8 *v58; // [rsp+90h] [rbp+50h] BYREF

  v4 = *((_DWORD *)this + 5);
  LOBYTE(v5) = 0;
  v7 = &a3[a2];
  v57 = 0i64;
  if ( v4 )
  {
    if ( a2 < v4 )
      return 234i64;
    *a4 = a2;
    v8 = a3 + 2;
    *a3 = (unsigned __int16)(v4 - 2) >> 8;
    v9 = 1;
    v10 = *((_BYTE *)this + 20) - 2;
    v58 = a3 + 2;
    a3[1] = v10;
    v11 = *((_QWORD *)this + 1);
    if ( (*(_DWORD *)(v11 + 64) & 0x2A88) != 0 || (*(_BYTE *)(v11 + 64) & 0x20) == 0 )
    {
      v12 = a3 + 2;
      if ( *((_QWORD *)this + 5) )
      {
        *(_WORD *)v8 = 0;
        v13 = a3 + 11;
        a3[4] = (unsigned __int16)(*((_WORD *)this + 24) + 5) >> 8;
        a3[5] = *((_BYTE *)this + 48) + 5;
        a3[6] = (unsigned __int16)(*((_WORD *)this + 24) + 3) >> 8;
        a3[7] = *((_BYTE *)this + 48) + 3;
        a3[8] = 0;
        a3[9] = *((_BYTE *)this + 49);
        a3[10] = *((_BYTE *)this + 48);
        memcpy_0(a3 + 11, *((const void **)this + 5), *((unsigned int *)this + 12));
        v14 = *((_QWORD *)this + 1);
        v58 = &v13[*((unsigned int *)this + 12)];
        v8 = v58;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v14 + 120), 0, 0);
        v12 = v8;
        v9 = v15 + 1;
      }
      if ( *((_BYTE *)this + 24) )
      {
        *v8 = 0;
        *(_QWORD *)(v12 + 1) = 17104901i64;
        v8 = v12 + 9;
        v16 = *((_QWORD *)this + 1);
        v58 = v12 + 9;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v16 + 120), 0, 5);
        v12 += 9;
      }
      if ( *((_BYTE *)this + 25) )
      {
        *v8 = 0;
        *(_DWORD *)(v12 + 1) = 16908294;
        v8 = v12 + 6;
        v12[5] = 64;
        v48 = *((_QWORD *)this + 1);
        v58 = v12 + 6;
        *(_BYTE *)(v48 + 922) = v9;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 6);
        v12 += 6;
      }
      if ( *((_BYTE *)this + 32) )
      {
        v17 = 0;
        v18 = *(_WORD *)(*((_QWORD *)this + 7) + 920i64);
        *v8 = 0;
        v18 *= 2;
        v12[1] = 10;
        v12[2] = (unsigned __int16)(v18 + 2) >> 8;
        v12[3] = v18 + 2;
        v12[4] = HIBYTE(v18);
        v12[5] = v18;
        v19 = v12 + 6;
        for ( i = *(_WORD *)(*((_QWORD *)this + 7) + 920i64) != 0;
              i;
              i = v17 < *(unsigned __int16 *)(*((_QWORD *)this + 7) + 920i64) )
        {
          v21 = v17;
          v17 += v9;
          *v19 = *(_BYTE *)(*(_QWORD *)(*((_QWORD *)this + 7) + 912i64) + 2 * v21 + 1);
          v19[1] = *(_BYTE *)(*(_QWORD *)(*((_QWORD *)this + 7) + 912i64) + 2 * v21);
          v19 += 2;
        }
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 10);
        *v19 = 0;
        *(_DWORD *)(v19 + 1) = 16908299;
        v8 = v19 + 6;
        v19[5] = 0;
        v22 = *((_QWORD *)this + 1);
        v58 = v19 + 6;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v22 + 120), v23, v23 + 11);
        v12 = v19 + 6;
      }
      v24 = (_BYTE *)*((_QWORD *)this + 7);
      if ( v24[925] )
      {
        v25 = (CTlsSignatureSuiteList *)(v24 + 474);
        v26 = *(unsigned __int16 *)v25;
        *v8 = 0;
        v12[1] = 13;
        v27 = 2 * v26 + 2;
        v12[2] = BYTE1(v27);
        v12[3] = 2 * v26 + 2;
        v28 = v12 + 4;
        CTlsSignatureSuiteList::BuildSupportedSignatureAlgorithms(v25, v28, v27);
        v29 = *((_QWORD *)this + 1);
        v8 = &v28[v27];
        v58 = v8;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v29 + 120), 0, 13);
        v24 = (_BYTE *)*((_QWORD *)this + 7);
        v12 = v8;
      }
      (*(void (__fastcall **)(_BYTE *, __int64 *))(*(_QWORD *)v24 + 224i64))(v24, &v57);
      if ( v57 )
      {
        v32 = *(const void **)(v57 + 424);
        v33 = *(_DWORD *)(v57 + 432);
        v31 = v33;
        *v8 = 0;
        v8 = v12 + 4;
        v12[1] = 35;
        v12[2] = BYTE1(v33);
        v12[3] = v33;
        v58 = v12 + 4;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids, v33);
        v12 += 4;
        if ( (_DWORD)v31 )
        {
          *(_QWORD *)(*((_QWORD *)this + 1) + 136i64) |= 0x800000ui64;
          v47 = *(_QWORD *)(*((_QWORD *)this + 1) + 120i64);
          if ( v47 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
          {
            *(_WORD *)(v47 + 64) |= 2u;
            *(_DWORD *)(v47 + 24) = 1;
          }
          memcpy_0(v8, v32, v31);
          v12 = &v8[v31];
          v8 = v12;
          v58 = v12;
        }
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 35);
      }
      v34 = *(_QWORD *)(*((_QWORD *)this + 1) + 784i64);
      if ( v34 )
      {
        v35 = *(unsigned __int16 *)(v34 + 4);
        *v8 = 0;
        v12[1] = 16;
        v12[2] = (unsigned __int16)(v35 + 2) >> 8;
        v12[3] = v35 + 2;
        v12[4] = BYTE1(v35);
        v12[5] = v35;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            11i64,
            &WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
            (unsigned int)v35);
        memcpy_0(v12 + 6, (const void *)(v34 + 6), v35);
        v36 = *((_QWORD *)this + 1);
        v8 = &v12[v35 + 6];
        v58 = v8;
        *(_QWORD *)(v36 + 136) |= 0x4000000ui64;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 16);
        v12 = v8;
      }
      v37 = *((_QWORD *)this + 7);
      if ( *(_BYTE *)(v37 + 1344) )
      {
        *v8 = 0;
        v8 = v12 + 4;
        v58 = v12 + 4;
        v12[1] = 23;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
        v38 = *((_QWORD *)this + 1);
        v39 = *(_QWORD *)(v38 + 120);
        if ( v39 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        {
          *(_WORD *)(v39 + 66) |= 1u;
          v38 = *((_QWORD *)this + 1);
        }
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v38 + 120), 0, 23);
        v37 = *((_QWORD *)this + 7);
      }
      else
      {
        v40 = 1;
      }
      v41 = v37;
      if ( *(_BYTE *)(v37 + 233) )
      {
        v5 = *(unsigned __int16 **)(v37 + 800);
        if ( v5 )
        {
          v49 = *v5;
          v50 = *(unsigned __int8 **)(v37 + 1336);
          if ( v50 )
          {
            v51 = *v50;
            v52 = v40 + *v50;
          }
          else
          {
            v52 = 1;
            v51 = 0;
          }
          v53 = v52 + v49 + 2;
          *(_WORD *)v8 = 3584;
          v8[2] = HIBYTE(v53);
          v8[3] = v53;
          v8[4] = BYTE1(v49);
          v8[5] = v49;
          v54 = (char *)(v8 + 6);
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_DD(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xDu,
              (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
              v49,
              v51);
          }
          memcpy_0(v54, v5 + 1, v49);
          v54[v49] = v51;
          LOBYTE(v5) = 0;
          v55 = &v54[v49 + 1];
          if ( v50 )
            memcpy_0(v55, v50 + 1, v51);
          v56 = *((_QWORD *)this + 7);
          v8 = (unsigned __int8 *)&v55[v51];
          v58 = v8;
          *(_QWORD *)(v56 + 136) |= 0x2000ui64;
          CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 14);
          v41 = *((_QWORD *)this + 7);
        }
      }
      v42 = *(_QWORD *)(v41 + 816);
      if ( v42 )
      {
        result = CTlsExt::BuildTBExtension(
                   v30,
                   *(_BYTE *)v42,
                   *(_BYTE *)(v42 + 1),
                   (unsigned __int8 *const)(v42 + 4),
                   *(_BYTE *)(v42 + 2),
                   v7,
                   &v58);
        if ( (_DWORD)result )
          return result;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            14i64,
            &WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
            *(unsigned __int16 *)(v42 + 2));
        *(_QWORD *)(*((_QWORD *)this + 7) + 136i64) |= 0x80000000ui64;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 24);
        v8 = v58;
      }
      LOBYTE(v9) = 1;
    }
    if ( *((_BYTE *)this + 26) != (_BYTE)v5 )
    {
      v44 = *((_QWORD *)this + 7);
      v45 = *(unsigned int *)(v44 + 416);
      v46 = (const void *)(v44 + 377);
      *(_WORD *)v8 = 511;
      v8[2] = (unsigned __int16)(v45 + 1) >> 8;
      v8[3] = v9 + v45;
      v8[4] = v45;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
      }
      if ( (_DWORD)v45 )
        memcpy_0(v8 + 5, v46, v45);
      CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 65281);
    }
  }
  return 0i64;
}
// 18000A8C1: variable 'v15' is possibly undefined
// 18003564D: variable 'v9' is possibly undefined
// 18000A9C1: variable 'v23' is possibly undefined
// 18000ABFE: variable 'v30' is possibly undefined
// 1800356F6: variable 'v40' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
