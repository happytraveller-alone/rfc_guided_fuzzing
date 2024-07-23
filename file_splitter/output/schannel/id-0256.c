// File count: 256
// Total lines: 226
----------------------------------------
__int64 __fastcall CSsl3TlsContext::ProcessRecord(__int64 a1, int a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v4; // ebp
  unsigned __int8 *v5; // rsi
  __int64 v8; // rax
  bool v9; // cl
  int v10; // ebx
  __int64 v11; // r14
  unsigned int v12; // ebx
  __int64 result; // rax
  __int64 v14; // r10
  unsigned int v15; // r9d
  unsigned int v16; // ecx
  CTlsMessageFragment *v17; // rcx
  unsigned int v18; // eax
  bool v19; // zf
  _QWORD *Memory; // rax
  CCipherMill *v21; // rcx
  bool v22; // zf
  CCipherMill *v23; // rcx
  bool v24; // zf
  unsigned int v25; // eax
  bool v26; // zf
  int v27; // eax
  unsigned int v28[4]; // [rsp+30h] [rbp-38h] BYREF
  unsigned __int8 v29; // [rsp+70h] [rbp+8h] BYREF

  v4 = a4;
  v5 = a3;
  if ( *(_BYTE *)(a1 + 233) )
    return CSsl3TlsContext::DtlsProcessRecord(a1, a2, a3, a4);
  v8 = *(_QWORD *)(a1 + 464);
  v28[0] = 0;
  v9 = 1;
  if ( !v8 || !*(_DWORD *)(v8 + 36) )
  {
LABEL_3:
    v10 = a2 - 21;
    if ( !v10 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 57i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
      v27 = TlsParseAlertMessage(v5, v4, (unsigned __int8 *)(a1 + 473), &v29);
      v12 = v27;
      if ( v27 )
      {
        if ( v27 == -2146892953 || *(_DWORD *)(a1 + 36) < 0x302u || (*(_DWORD *)(a1 + 64) & 0x800A00AA) == 0 )
        {
          if ( v4 == 2 )
            LogReceiveAlertEvent(
              *(_DWORD *)(*(_QWORD *)(a1 + 80) + 212i64),
              (const unsigned __int16 *)(*(_QWORD *)(a1 + 80) + 216i64),
              *v5,
              v5[1]);
        }
        else
        {
          CSslContext::SetError(a1, 14, v27);
          return (unsigned int)-2146893018;
        }
      }
      else if ( v29 )
      {
        *(_BYTE *)(a1 + 552) = 1;
        *(_DWORD *)(a1 + 68) = 75;
      }
      return v12;
    }
    if ( v10 != 1 )
      return 0;
    while ( v4 >= 4 )
    {
      v11 = v5[3] + (v5[1] << 16) + (v5[2] << 8);
      if ( v11 + 4 > (unsigned __int64)v4 )
      {
        v17 = *(CTlsMessageFragment **)(a1 + 464);
        if ( v17 )
          goto LABEL_52;
        if ( (*(_DWORD *)(a1 + 64) & 0x40051555) != 0 )
        {
          if ( (*(_DWORD *)(a1 + 136) & 0x100i64) == 0 )
            goto LABEL_36;
          v18 = CSslGlobals::m_dwTlsMessageLimitSrvClientAuth;
          if ( CSslGlobals::m_dwTlsMessageLimitSrv > CSslGlobals::m_dwTlsMessageLimitSrvClientAuth )
            v18 = CSslGlobals::m_dwTlsMessageLimitSrv;
          if ( v18 )
          {
LABEL_36:
            v19 = CSslGlobals::m_dwTlsMessageLimitSrv == 0;
            goto LABEL_38;
          }
          goto LABEL_41;
        }
        v19 = CSslGlobals::m_dwTlsMessageLimitClient == 0;
LABEL_38:
        if ( !v19 )
        {
          Memory = CSslContext::GetMemory((CSslContext *)a1, 0x30u);
          if ( !Memory )
          {
            v21 = WPP_GLOBAL_Control;
            v22 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
LABEL_47:
            if ( !v22 && (*((_BYTE *)v21 + 28) & 1) != 0 )
              WPP_SF_(*((_QWORD *)v21 + 2), 68i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
            return 14;
          }
LABEL_51:
          *Memory = 0i64;
          *(_QWORD *)((char *)Memory + 12) = 256i64;
          Memory[3] = 0i64;
          Memory[4] = 0i64;
          *(_QWORD *)(a1 + 464) = Memory;
          CTlsMessageFragment::Initialize((CTlsMessageFragment *)Memory, (struct CSsl3TlsContext *)a1);
          v17 = *(CTlsMessageFragment **)(a1 + 464);
LABEL_52:
          v28[0] = 0;
          return (unsigned int)CTlsMessageFragment::SaveFragment(v17, v5, v4, 1, v28);
        }
LABEL_41:
        v23 = WPP_GLOBAL_Control;
        v24 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
LABEL_43:
        if ( !v24 && (*((_BYTE *)v23 + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)v23 + 2), 67i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        v12 = -2146893018;
        CSslContext::SetErrorAndFatalAlert(a1, 12, -2146893018, 0xAu);
        return v12;
      }
      v12 = CSsl3TlsContext::ProcessHandshakeCommon((CSsl3TlsContext *)a1, v5, (int)v11 + 4);
      if ( !v12 )
      {
        v5 += v11 + 4;
        v4 += -4 - v11;
        if ( v4 )
          continue;
      }
      return v12;
    }
    v17 = *(CTlsMessageFragment **)(a1 + 464);
    if ( v17 )
      goto LABEL_52;
    if ( (*(_DWORD *)(a1 + 64) & 0x40051555) != 0 )
    {
      if ( (*(_DWORD *)(a1 + 136) & 0x100i64) != 0 )
      {
        v25 = CSslGlobals::m_dwTlsMessageLimitSrvClientAuth;
        if ( CSslGlobals::m_dwTlsMessageLimitSrv > CSslGlobals::m_dwTlsMessageLimitSrvClientAuth )
          v25 = CSslGlobals::m_dwTlsMessageLimitSrv;
        if ( !v25 )
        {
LABEL_42:
          v23 = WPP_GLOBAL_Control;
          v24 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
          goto LABEL_43;
        }
      }
      v26 = CSslGlobals::m_dwTlsMessageLimitSrv == 0;
    }
    else
    {
      v26 = CSslGlobals::m_dwTlsMessageLimitClient == 0;
    }
    if ( !v26 )
    {
      Memory = CSslContext::GetMemory((CSslContext *)a1, 0x30u);
      if ( !Memory )
      {
        v21 = WPP_GLOBAL_Control;
        v22 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
        goto LABEL_47;
      }
      goto LABEL_51;
    }
    goto LABEL_42;
  }
  if ( a2 != 22 )
  {
    if ( a2 == 21 )
      *(_QWORD *)(v8 + 32) = 0i64;
LABEL_12:
    result = 0i64;
    if ( !v9 )
      return result;
    goto LABEL_3;
  }
  result = CTlsMessageFragment::SaveFragment((CTlsMessageFragment *)v8, a3, a4, 0, v28);
  if ( !(_DWORD)result )
  {
    v14 = *(_QWORD *)(a1 + 464);
    v15 = *(_DWORD *)(v14 + 32);
    v16 = *(_DWORD *)(v14 + 40) != 0 ? 12 : 4;
    if ( (v15 <= v16 || *(_DWORD *)(v14 + 36) < v15)
      && (*(_DWORD *)(v14 + 36) < v16
       || *(unsigned __int8 *)(*(_QWORD *)(v14 + 24) + 3i64)
        + (*(unsigned __int8 *)(*(_QWORD *)(v14 + 24) + 1i64) << 16)
        + (*(unsigned __int8 *)(*(_QWORD *)(v14 + 24) + 2i64) << 8)) )
    {
      return 0i64;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_d(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x45u,
        (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
        v15);
      v14 = *(_QWORD *)(a1 + 464);
    }
    result = CSsl3TlsContext::ProcessHandshakeCommon(
               (CSsl3TlsContext *)a1,
               *(unsigned __int8 **)(v14 + 24),
               *(_DWORD *)(v14 + 32));
    if ( !(_DWORD)result )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 464) + 32i64) = 0i64;
      v5 += v28[0];
      v4 -= v28[0];
      v9 = v4 != 0;
      goto LABEL_12;
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
