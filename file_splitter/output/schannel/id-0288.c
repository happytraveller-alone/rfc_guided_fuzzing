// File count: 288
// Total lines: 76
-----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::Initialize(CSsl3TlsClientContext *this)
{
  __int64 v2; // rax
  __int64 v3; // r8
  _QWORD *v5; // rax
  _QWORD *v6; // rdx
  _QWORD *v7; // rcx
  _QWORD *v8; // rax
  _QWORD *v9; // rax
  DTlsMsgMgr *v10; // rcx

  if ( !*((_BYTE *)this + 233) )
    goto LABEL_2;
  v5 = operator new(0x60ui64);
  v6 = v5;
  if ( v5 )
  {
    *v5 = 0i64;
    v5[4] = v5 + 3;
    v5[3] = v5 + 3;
    v5[6] = v5 + 5;
    v5[5] = v5 + 5;
    v7 = v5 + 7;
    *((_DWORD *)v5 + 2) = 10;
    v8 = v5 + 9;
    v7[1] = v7;
    *v7 = v7;
    v6[11] = this;
    v8[1] = v8;
    *v8 = v8;
  }
  else
  {
    v6 = 0i64;
  }
  *((_QWORD *)this + 72) = v6;
  if ( !v6 )
    return 14i64;
  v9 = operator new(0x30ui64);
  if ( v9 )
  {
    *v9 = *((_QWORD *)this + 72);
    v9[1] = 0i64;
    v9[2] = 0i64;
    v9[3] = 0i64;
    *((_DWORD *)v9 + 8) = 0;
    v9[5] = this;
    *((_DWORD *)v9 + 9) = *((__int16 *)this + 96);
  }
  else
  {
    v9 = 0i64;
  }
  v10 = (DTlsMsgMgr *)*((_QWORD *)this + 72);
  *((_QWORD *)this + 73) = v9;
  if ( !v9 )
  {
    if ( v10 )
      DTlsMsgMgr::`scalar deleting destructor'(v10);
    return 14i64;
  }
  *((_QWORD *)this + 28) = v10;
LABEL_2:
  v2 = *((_QWORD *)this + 15);
  v3 = *((_QWORD *)this + 166);
  if ( v2 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
  {
    *(_WORD *)(v2 + 152) = 0;
    if ( v3 )
      o_wcsncpy_s_0(v2 + 152, 256i64, v3, -1i64);
  }
  return 0i64;
}
// 180028D84: using guessed type __int64 __fastcall o_wcsncpy_s_0(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
