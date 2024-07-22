//----- (000000018001A100) ----------------------------------------------------
__int64 __fastcall CTlsExtServer::BuildServerHelloExtension(
        CTlsExtServer *this,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned int *a4)
{
  unsigned __int8 *v5; // rbp
  unsigned int v6; // eax
  unsigned __int8 *v7; // rdi
  unsigned __int8 *v8; // rdx
  unsigned __int8 v9; // al
  _DWORD *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rsi
  _BOOL8 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rax
  unsigned __int16 *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rsi
  unsigned int *v20; // rax
  __int64 v21; // r9
  const void *v22; // r12
  __int64 v23; // r10
  const void *v24; // r15
  size_t v25; // rsi
  size_t v26; // r14
  __int16 v27; // ax
  unsigned __int8 v28; // r9
  char *v29; // rdi
  char *v30; // rdi
  __int64 v31; // rcx
  __int64 result; // rax
  __int16 v33; // dx
  unsigned __int16 v34; // dx
  __int64 v35; // rax
  __int64 v36; // rcx
  __int64 v37; // rcx
  __int64 v38; // rcx
  size_t v39; // r14
  int v40; // esi
  const void *v41; // r15
  unsigned __int8 *v42; // rsi
  __int64 v43; // rcx
  CTlsExt *v44; // rcx
  __int64 v45; // [rsp+20h] [rbp-48h]
  unsigned __int8 *v46; // [rsp+80h] [rbp+18h] BYREF

  v5 = &a3[a2];
  if ( !a3 || !a4 )
    return 87i64;
  v6 = *((_DWORD *)this + 5);
  *a4 = v6;
  if ( !v6 )
    return 0i64;
  if ( a2 < v6 )
    return 234i64;
  v7 = a3 + 2;
  v8 = a3 + 2;
  *a3 = (unsigned __int16)(v6 - 2) >> 8;
  v9 = *((_BYTE *)this + 20) - 2;
  v46 = a3 + 2;
  a3[1] = v9;
  if ( *((_BYTE *)this + 24) )
  {
    *(_WORD *)v7 = 1280;
    v37 = *((_QWORD *)this + 1);
    v7 = a3 + 6;
    v46 = a3 + 6;
    CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v37 + 120), 0, 5);
    v8 = v7;
  }
  if ( *((_BYTE *)this + 25) )
  {
    *v7 = 0;
    v7 = v8 + 6;
    *(_DWORD *)(v8 + 1) = 16908294;
    v8[5] = 64;
    v38 = *((_QWORD *)this + 1);
    v46 = v8 + 6;
    CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v38 + 120), 0, 6);
    v8 = v7;
  }
  v10 = (_DWORD *)*((_QWORD *)this + 1);
  if ( (v10[34] & 0x400000) != 0 )
  {
    *v7 = 0;
    v7 = v8 + 4;
    v46 = v8 + 4;
    v8[1] = 35;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
    CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 35);
    v10 = (_DWORD *)*((_QWORD *)this + 1);
  }
  v11 = (*(__int64 (__fastcall **)(_DWORD *, unsigned __int8 *))(*(_QWORD *)v10 + 88i64))(v10, v8);
  v12 = v11;
  if ( !v11 || *(_DWORD *)v11 != 1 || *(_DWORD *)(v11 + 4) != 2 )
    goto LABEL_11;
  v33 = *(unsigned __int8 *)(v11 + 8);
  *(_WORD *)v7 = 4096;
  v34 = v33 + 1;
  v7[2] = (unsigned __int16)(v34 + 2) >> 8;
  v7[3] = v34 + 2;
  v7[4] = HIBYTE(v34);
  v7[5] = v34;
  v7[6] = *(_BYTE *)(v11 + 8);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids, v34);
  memcpy_0(v7 + 7, (const void *)(v12 + 9), *(unsigned __int8 *)(v12 + 8));
  v35 = *((_QWORD *)this + 1);
  v7 += *(unsigned __int8 *)(v12 + 8) + 7;
  v46 = v7;
  v36 = *(_QWORD *)(v35 + 120);
  if ( v36 )
  {
    v13 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
    if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
      *(_DWORD *)(v36 + 68) |= 0x800u;
  }
  else
  {
LABEL_11:
    v13 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
  }
  v14 = *((_QWORD *)this + 1);
  if ( (*(_DWORD *)(v14 + 136) & 0x8000000) != 0 )
  {
    *(_WORD *)v7 = 5888;
    v7 += 4;
    v46 = v7;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
      v13 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
    }
    v14 = *((_QWORD *)this + 1);
    v15 = *(_QWORD *)(v14 + 120);
    if ( v15 && v13 )
    {
      *(_WORD *)(v15 + 66) |= 2u;
      v14 = *((_QWORD *)this + 1);
    }
    v16 = *(_QWORD *)(v14 + 120);
    if ( v16 && v13 )
    {
      *(_DWORD *)(v16 + 68) |= 0x1000u;
      v14 = *((_QWORD *)this + 1);
    }
  }
  v17 = (unsigned __int16 *)(*(__int64 (__fastcall **)(__int64, _BOOL8))(*(_QWORD *)v14 + 96i64))(v14, v13);
  if ( v17 )
  {
    v39 = *((unsigned __int8 *)v17 + 2);
    v40 = *v17;
    v41 = (const void *)*((_QWORD *)v17 + 1);
    *(_WORD *)v7 = 3584;
    v7[2] = (unsigned __int16)(v39 + 5) >> 8;
    v7[3] = v39 + 5;
    *((_WORD *)v7 + 2) = 512;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x14u,
        (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
        v40,
        v39);
    *((_WORD *)v7 + 3) = v40;
    v42 = v7 + 9;
    v7[8] = v39;
    if ( v41 )
      memcpy_0(v7 + 9, v41, v39);
    v43 = *((_QWORD *)this + 1);
    v7 = &v42[v39];
    v46 = &v42[v39];
    CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(v43 + 120), 0, 14);
  }
  v18 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 1) + 104i64))(*((_QWORD *)this + 1));
  v19 = v18;
  if ( v18 )
  {
    v44 = (CTlsExt *)*((_QWORD *)this + 4);
    if ( (*((_DWORD *)v44 + 16) & 0x1000) != 0
      || *((_BYTE *)this + 26) && (v44 = (CTlsExt *)*((_QWORD *)this + 1), (*((_DWORD *)v44 + 34) & 0x8000000) != 0) )
    {
      result = CTlsExt::BuildTBExtension(
                 v44,
                 *(_BYTE *)v18,
                 *(_BYTE *)(v18 + 1),
                 *(unsigned __int8 *const *)(v18 + 8),
                 *(_BYTE *)(v18 + 2),
                 v5,
                 &v46);
      if ( (_DWORD)result )
        return result;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          22i64,
          &WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
          *(unsigned __int16 *)(v19 + 2));
      CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 24);
      v7 = v46;
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 21i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
      CSsl3TlsContext::FreeSelectedTBParameters(*((CSsl3TlsContext **)this + 1));
    }
  }
  if ( !*((_BYTE *)this + 26) )
    goto LABEL_36;
  v20 = (unsigned int *)*((_QWORD *)this + 1);
  v21 = v20[104];
  v22 = (char *)v20 + 377;
  v23 = v20[114];
  v24 = v20 + 105;
  if ( (_DWORD)v21 == (_DWORD)v23 )
  {
    v25 = (unsigned int)v23;
    v26 = (unsigned int)v21;
    if ( &v7[v23 + 5 + v21] <= v5 )
    {
      *(_WORD *)v7 = 511;
      v27 = v23 + v21 + 1;
      v28 = v23 + v21;
      v7[2] = HIBYTE(v27);
      v7[3] = v28 + 1;
      v7[4] = v28;
      v29 = (char *)(v7 + 5);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
      }
      memcpy_0(v29, v22, v26);
      v30 = &v29[v26];
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 26i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
      }
      memcpy_0(v30, v24, v25);
      v7 = (unsigned __int8 *)&v30[v25];
      v31 = *(_QWORD *)(*((_QWORD *)this + 1) + 120i64);
      if ( v31 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        *(_DWORD *)(v31 + 68) |= 0x10000u;
LABEL_36:
      if ( (*(_DWORD *)(*((_QWORD *)this + 1) + 136i64) & 0x200000) != 0 )
      {
        *(_DWORD *)v7 = 0;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(*(_QWORD *)(*((_QWORD *)this + 1) + 120i64), 0, 0);
      }
      return 0i64;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
    return 234i64;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    LODWORD(v45) = v20[114];
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x17u,
      (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
      v21,
      v45);
  }
  return 1359i64;
}
// 18001A1B0: variable 'v8' is possibly undefined
// 18002EF8B: variable 'v45' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

