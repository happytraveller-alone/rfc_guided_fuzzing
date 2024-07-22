//----- (0000000180070804) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::TlsNulRecordHandlerWorker(
        CSsl3TlsContext *this,
        struct SPBuffer *a2,
        struct SPBuffer *a3)
{
  __int64 result; // rax
  unsigned __int8 *v7; // r14
  unsigned int v8; // esi
  __int64 v9; // rax
  char v10; // r13
  CTlsMessageFragment *v11; // rcx
  unsigned int v12; // eax
  __int64 v13; // r9
  __int64 v14; // r15
  unsigned int v15; // r8d
  unsigned int v16; // ecx
  __int64 v17; // rcx
  unsigned int v18; // edx
  unsigned int v19; // ebp
  int v20; // ecx
  __int64 v21; // rax
  CTlsMessageFragment *v22; // rcx
  unsigned int v23; // eax
  bool v24; // zf
  CCipherMill *v25; // rcx
  bool v26; // zf
  _QWORD *Memory; // rax
  CCipherMill *v28; // rcx
  bool v29; // zf
  unsigned int v30; // eax
  bool v31; // zf
  unsigned int v32; // edi
  unsigned int v33; // [rsp+60h] [rbp+8h] BYREF

  if ( (*(unsigned __int8 (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 384i64))(this) || !a2 || !a3 )
    return 2148074333i64;
  result = (*(__int64 (__fastcall **)(CSsl3TlsContext *, struct SPBuffer *))(*(_QWORD *)this + 432i64))(this, a2);
  if ( (_DWORD)result )
    return result;
  if ( !CSsl3TlsContext::CanParseInput(this) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 44i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    return CSsl3TlsContext::GenerateResponseCommon(this, a3);
  }
  v7 = (unsigned __int8 *)*((_QWORD *)a2 + 1);
  if ( !v7 )
    return 2148074248i64;
  v8 = *((_DWORD *)a2 + 1);
  if ( !v8 )
    return 2148074248i64;
  *((_DWORD *)a2 + 1) = 0;
  if ( (*((_BYTE *)this + 32) & 2) == 0 || (v9 = *((_QWORD *)this + 1)) == 0 || (v10 = 1, !*(_DWORD *)(v9 + 28)) )
    v10 = 0;
  while ( 1 )
  {
    v11 = (CTlsMessageFragment *)*((_QWORD *)this + 58);
    if ( !v11 || !*((_DWORD *)v11 + 9) )
      break;
    v33 = 0;
    result = CTlsMessageFragment::SaveFragment(v11, v7, v8, 0, &v33);
    if ( (_DWORD)result )
      return result;
    v12 = v33;
    if ( v33 > v8 )
      return 2148074244i64;
    *((_DWORD *)a2 + 1) += v33;
    v8 -= v12;
    v13 = *((_QWORD *)this + 58);
    v14 = v12;
    v15 = *(_DWORD *)(v13 + 32);
    v16 = *(_DWORD *)(v13 + 40) != 0 ? 12 : 4;
    if ( (v15 <= v16 || *(_DWORD *)(v13 + 36) < v15)
      && (*(_DWORD *)(v13 + 36) < v16
       || *(unsigned __int8 *)(*(_QWORD *)(v13 + 24) + 3i64)
        + (*(unsigned __int8 *)(*(_QWORD *)(v13 + 24) + 1i64) << 16)
        + (*(unsigned __int8 *)(*(_QWORD *)(v13 + 24) + 2i64) << 8)) )
    {
      return 0i64;
    }
    result = CSsl3TlsContext::ProcessHandshakeCommon(this, *(unsigned __int8 **)(v13 + 24), v15);
    v17 = *((_QWORD *)this + 58);
    v18 = result;
    *(_DWORD *)(v17 + 36) = 0;
    *(_DWORD *)(v17 + 32) = 0;
    if ( (_DWORD)result )
      return result;
LABEL_30:
    v20 = *((_DWORD *)this + 17);
    v7 += v14;
    if ( (unsigned int)(v20 - 91) <= 0xB )
      return CSsl3TlsContext::GenerateResponseCommon(this, a3);
    if ( v20 == 4 )
      return v18;
    if ( !v10 && (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v21 = *((_QWORD *)this + 1);
      if ( v21 )
      {
        if ( *(_DWORD *)(v21 + 28) )
          return v18;
      }
    }
    if ( !v8 )
      return v18;
  }
  if ( v8 < 4 )
  {
    *((_DWORD *)a2 + 1) += v8;
    v22 = (CTlsMessageFragment *)*((_QWORD *)this + 58);
    if ( v22 )
      goto LABEL_73;
    if ( (*((_DWORD *)this + 16) & 0x40051555) != 0 )
    {
      if ( (*((_DWORD *)this + 34) & 0x100i64) != 0 )
      {
        v30 = CSslGlobals::m_dwTlsMessageLimitSrvClientAuth;
        if ( CSslGlobals::m_dwTlsMessageLimitSrv > CSslGlobals::m_dwTlsMessageLimitSrvClientAuth )
          v30 = CSslGlobals::m_dwTlsMessageLimitSrv;
        if ( !v30 )
          goto LABEL_61;
      }
      v31 = CSslGlobals::m_dwTlsMessageLimitSrv == 0;
    }
    else
    {
      v31 = CSslGlobals::m_dwTlsMessageLimitClient == 0;
    }
    if ( !v31 )
    {
      Memory = CSslContext::GetMemory(this, 0x30u);
      if ( !Memory )
      {
        v28 = WPP_GLOBAL_Control;
        v29 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
LABEL_68:
        if ( !v29 && (*((_BYTE *)v28 + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)v28 + 2), 68i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        return 14;
      }
      goto LABEL_72;
    }
LABEL_61:
    v25 = WPP_GLOBAL_Control;
    v26 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
    goto LABEL_62;
  }
  if ( (unsigned __int64)(v7[3] + (v7[1] << 16) + (v7[2] << 8)) + 4 <= v8 )
  {
    v19 = v7[3] + (v7[1] << 16) + (v7[2] << 8) + 4;
    v18 = CSsl3TlsContext::ProcessHandshakeCommon(this, v7, v19);
    if ( v18 )
      return v18;
    v8 -= v19;
    v14 = v19;
    *((_DWORD *)a2 + 1) += v19;
    goto LABEL_30;
  }
  *((_DWORD *)a2 + 1) += v8;
  v22 = (CTlsMessageFragment *)*((_QWORD *)this + 58);
  if ( v22 )
  {
LABEL_73:
    v33 = 0;
    return (unsigned int)CTlsMessageFragment::SaveFragment(v22, v7, v8, 1, &v33);
  }
  if ( (*((_DWORD *)this + 16) & 0x40051555) != 0 )
  {
    if ( (*((_DWORD *)this + 34) & 0x100i64) == 0 )
      goto LABEL_46;
    v23 = CSslGlobals::m_dwTlsMessageLimitSrvClientAuth;
    if ( CSslGlobals::m_dwTlsMessageLimitSrv > CSslGlobals::m_dwTlsMessageLimitSrvClientAuth )
      v23 = CSslGlobals::m_dwTlsMessageLimitSrv;
    if ( v23 )
    {
LABEL_46:
      v24 = CSslGlobals::m_dwTlsMessageLimitSrv == 0;
      goto LABEL_48;
    }
    goto LABEL_49;
  }
  v24 = CSslGlobals::m_dwTlsMessageLimitClient == 0;
LABEL_48:
  if ( !v24 )
  {
    Memory = CSslContext::GetMemory(this, 0x30u);
    if ( !Memory )
    {
      v28 = WPP_GLOBAL_Control;
      v29 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
      goto LABEL_68;
    }
LABEL_72:
    *Memory = 0i64;
    *(_QWORD *)((char *)Memory + 12) = 256i64;
    Memory[3] = 0i64;
    Memory[4] = 0i64;
    *((_QWORD *)this + 58) = Memory;
    CTlsMessageFragment::Initialize((CTlsMessageFragment *)Memory, this);
    v22 = (CTlsMessageFragment *)*((_QWORD *)this + 58);
    goto LABEL_73;
  }
LABEL_49:
  v25 = WPP_GLOBAL_Control;
  v26 = WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control;
LABEL_62:
  if ( !v26 && (*((_BYTE *)v25 + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)v25 + 2), 67i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  v32 = -2146893018;
  CSslContext::SetErrorAndFatalAlert((__int64)this, 12, -2146893018, 0xAu);
  return v32;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

