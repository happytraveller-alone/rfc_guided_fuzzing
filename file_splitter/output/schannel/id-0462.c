// File count: 462
// Total lines: 320
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::ProcessRecord(__int64 a1, int a2, unsigned __int8 *a3, unsigned int a4)
{
  char v4; // al
  unsigned int v5; // ebp
  unsigned __int8 *v6; // r14
  __int64 v8; // rbx
  unsigned int v9; // esi
  __int64 v10; // rax
  bool v11; // cl
  int v12; // edi
  __int64 v13; // rdi
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v17; // eax
  __int64 v18; // rcx
  char v19; // al
  int v20; // eax
  __int64 v21; // r10
  unsigned int v22; // eax
  unsigned int v23; // r9d
  CTlsMessageFragment *v24; // rcx
  unsigned int v25; // eax
  _QWORD *Memory; // rax
  CCipherMill *v27; // rcx
  bool v28; // zf
  CCipherMill *v29; // rcx
  bool v30; // zf
  int v31; // edx
  unsigned int v32; // eax
  int v33; // eax
  unsigned int *v34; // [rsp+20h] [rbp-48h]
  __int64 v35; // [rsp+28h] [rbp-40h]
  unsigned int v36; // [rsp+70h] [rbp+8h] BYREF
  unsigned __int8 v37; // [rsp+78h] [rbp+10h] BYREF

  v4 = *(_BYTE *)(a1 + 233);
  v5 = a4;
  v6 = a3;
  v8 = a1;
  v9 = -2146893018;
  if ( v4 )
    v9 = 590610;
  if ( a2 == 20 )
  {
    v17 = *(_DWORD *)(a1 + 68);
    if ( v17 == 61 )
    {
      if ( (*(_DWORD *)(a1 + 136) & 0x100i64) != 0 && !*(_BYTE *)(a1 + 552) )
        return (unsigned int)-2146893018;
    }
    else if ( ((v17 - 62) & 0xFFFFFFFD) != 0 )
    {
      return v9;
    }
    if ( a4 == 1 && *a3 == 1 )
    {
      *(_WORD *)(a1 + 32) |= 0xAu;
      v18 = *(_QWORD *)(a1 + 144);
      if ( v18 )
        SslFreeObject(v18, 0i64);
      *(_QWORD *)(v8 + 144) = *(_QWORD *)(v8 + 160);
      v19 = *(_BYTE *)(v8 + 233);
      *(_QWORD *)(v8 + 160) = 0i64;
      if ( !v19 )
        *(_QWORD *)(v8 + 176) = 0i64;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        v19 = *(_BYTE *)(v8 + 233);
      }
      if ( v19 )
      {
        ++*(_DWORD *)(v8 + 192);
        *(_QWORD *)(v8 + 208) = 0i64;
        *(_QWORD *)(v8 + 200) = 0i64;
      }
      v20 = 63;
      v9 = 0;
      if ( *(_DWORD *)(v8 + 68) == 64 )
        v20 = 65;
      *(_DWORD *)(v8 + 68) = v20;
      return v9;
    }
    v31 = 904;
    goto LABEL_112;
  }
  if ( v4 )
    return (unsigned int)CSsl3TlsContext::DtlsProcessRecord(a1, a2, a3, a4);
  v10 = *(_QWORD *)(a1 + 464);
  v11 = 1;
  v36 = 0;
  if ( v10 && *(_DWORD *)(v10 + 36) )
  {
    if ( a2 == 22 )
    {
      v9 = CTlsMessageFragment::SaveFragment((CTlsMessageFragment *)v10, a3, a4, 0, &v36);
      if ( v9 )
        return v9;
      v21 = *(_QWORD *)(v8 + 464);
      v22 = 12;
      v23 = *(_DWORD *)(v21 + 32);
      if ( !*(_DWORD *)(v21 + 40) )
        v22 = 4;
      if ( (v23 <= v22 || *(_DWORD *)(v21 + 36) < v23)
        && (*(_DWORD *)(v21 + 36) < v22
         || *(unsigned __int8 *)(*(_QWORD *)(v21 + 24) + 3i64)
          + (*(unsigned __int8 *)(*(_QWORD *)(v21 + 24) + 1i64) << 16)
          + (*(unsigned __int8 *)(*(_QWORD *)(v21 + 24) + 2i64) << 8)) )
      {
        return 0;
      }
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x45u,
          (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
          v23);
        v21 = *(_QWORD *)(v8 + 464);
      }
      v9 = CSsl3TlsContext::ProcessHandshakeCommon(
             (CSsl3TlsContext *)v8,
             *(unsigned __int8 **)(v21 + 24),
             *(_DWORD *)(v21 + 32));
      if ( v9 )
        return v9;
      *(_QWORD *)(*(_QWORD *)(v8 + 464) + 32i64) = 0i64;
      v6 += v36;
      v5 -= v36;
      v11 = v5 != 0;
    }
    else if ( a2 == 21 )
    {
      *(_QWORD *)(v10 + 32) = 0i64;
    }
    v9 = 0;
    if ( !v11 )
      return v9;
  }
  v12 = a2 - 21;
  if ( !v12 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 57i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    v33 = TlsParseAlertMessage(v6, v5, (unsigned __int8 *)(v8 + 473), &v37);
    v9 = v33;
    if ( !v33 )
    {
      if ( v37 )
      {
        *(_BYTE *)(v8 + 552) = 1;
        *(_DWORD *)(v8 + 68) = 75;
      }
      return v9;
    }
    if ( v33 == -2146892953 || *(_DWORD *)(v8 + 36) < 0x302u || (*(_DWORD *)(v8 + 64) & 0x800A00AA) == 0 )
    {
      if ( v5 == 2 )
        LogReceiveAlertEvent(
          *(_DWORD *)(*(_QWORD *)(v8 + 80) + 212i64),
          (const unsigned __int16 *)(*(_QWORD *)(v8 + 80) + 216i64),
          *v6,
          v6[1]);
      return v9;
    }
    CSslContext::SetError(v8, 14, v33);
    return (unsigned int)-2146893018;
  }
  if ( v12 != 1 )
    return 0;
  while ( 1 )
  {
    if ( v5 < 4 )
    {
      v24 = *(CTlsMessageFragment **)(v8 + 464);
      if ( v24 )
        goto LABEL_96;
      if ( (*(_DWORD *)(v8 + 64) & 0x40051555) != 0 )
      {
        if ( (*(_DWORD *)(v8 + 136) & 0x100i64) != 0 )
        {
          v32 = CSslGlobals::m_dwTlsMessageLimitSrvClientAuth;
          if ( CSslGlobals::m_dwTlsMessageLimitSrv > CSslGlobals::m_dwTlsMessageLimitSrvClientAuth )
            v32 = CSslGlobals::m_dwTlsMessageLimitSrv;
          if ( !v32 )
            goto LABEL_75;
        }
        if ( !CSslGlobals::m_dwTlsMessageLimitSrv )
          goto LABEL_75;
      }
      else if ( !CSslGlobals::m_dwTlsMessageLimitClient )
      {
LABEL_75:
        v29 = WPP_GLOBAL_Control;
        v30 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
LABEL_76:
        if ( !v30 && (*((_BYTE *)v29 + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)v29 + 2), 67i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        v31 = 12;
        a1 = v8;
LABEL_112:
        CSslContext::SetErrorAndFatalAlert(a1, v31, -2146893018, 0xAu);
        return (unsigned int)-2146893018;
      }
      Memory = CSslContext::GetMemory((CSslContext *)v8, 0x30u);
      if ( !Memory )
      {
        v27 = WPP_GLOBAL_Control;
        v28 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
        goto LABEL_81;
      }
      goto LABEL_95;
    }
    v13 = v6[3] + (v6[1] << 16) + (v6[2] << 8);
    if ( v13 + 4 > (unsigned __int64)v5 )
      break;
    v36 = 0;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LODWORD(v35) = *(_DWORD *)(v8 + 68);
      LODWORD(v34) = *v6;
      WPP_SF_DDD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x3Au,
        (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
        *(_DWORD *)(v8 + 64),
        v34,
        v35);
    }
    v14 = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *, _QWORD, unsigned int *))(*(_QWORD *)v8 + 416i64))(
            v8,
            v6,
            (unsigned int)(v13 + 4),
            &v36);
    v9 = v14;
    if ( (!v14 || v14 == 590624) && !*(_DWORD *)(v8 + 872) && !v36 )
    {
      v15 = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *, _QWORD, _QWORD))(*(_QWORD *)v8 + 504i64))(
              v8,
              v6,
              (unsigned int)(v13 + 4),
              0i64);
      if ( v15 )
        v9 = v15;
    }
    if ( *(_BYTE *)(v8 + 923) )
    {
      v9 = 590610;
      *(_DWORD *)(v8 + 72) = *(_DWORD *)(v8 + 68);
      *(_DWORD *)(v8 + 68) = 77;
      return v9;
    }
    if ( v9 == 590624 )
    {
      *(_BYTE *)(v8 + 924) = 1;
      return v9;
    }
    if ( !v9 )
    {
      v6 += v13 + 4;
      v5 += -4 - v13;
      if ( v5 )
        continue;
    }
    return v9;
  }
  v24 = *(CTlsMessageFragment **)(v8 + 464);
  if ( v24 )
  {
LABEL_96:
    v36 = 0;
    return (unsigned int)CTlsMessageFragment::SaveFragment(v24, v6, v5, 1, &v36);
  }
  if ( (*(_DWORD *)(v8 + 64) & 0x40051555) == 0 )
  {
    if ( CSslGlobals::m_dwTlsMessageLimitClient )
      goto LABEL_71;
    goto LABEL_74;
  }
  if ( (*(_DWORD *)(v8 + 136) & 0x100i64) != 0 )
  {
    v25 = CSslGlobals::m_dwTlsMessageLimitSrvClientAuth;
    if ( CSslGlobals::m_dwTlsMessageLimitSrv > CSslGlobals::m_dwTlsMessageLimitSrvClientAuth )
      v25 = CSslGlobals::m_dwTlsMessageLimitSrv;
    if ( !v25 )
      goto LABEL_74;
  }
  if ( !CSslGlobals::m_dwTlsMessageLimitSrv )
  {
LABEL_74:
    v29 = WPP_GLOBAL_Control;
    v30 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
    goto LABEL_76;
  }
LABEL_71:
  Memory = CSslContext::GetMemory((CSslContext *)v8, 0x30u);
  if ( Memory )
  {
LABEL_95:
    *Memory = 0i64;
    *(_QWORD *)((char *)Memory + 12) = 256i64;
    Memory[3] = 0i64;
    Memory[4] = 0i64;
    *(_QWORD *)(v8 + 464) = Memory;
    CTlsMessageFragment::Initialize((CTlsMessageFragment *)Memory, (struct CSsl3TlsContext *)v8);
    v24 = *(CTlsMessageFragment **)(v8 + 464);
    goto LABEL_96;
  }
  v27 = WPP_GLOBAL_Control;
  v28 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
LABEL_81:
  if ( !v28 && (*((_BYTE *)v27 + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)v27 + 2), 68i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  return 14;
}
// 18003F865: variable 'v34' is possibly undefined
// 18003F865: variable 'v35' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
