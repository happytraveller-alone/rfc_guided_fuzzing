// File count: 464
// Total lines: 143
----------------------------------------
void __fastcall CSsl3TlsServerContext::SetStateConnected(CSsl3TlsServerContext *this)
{
  __int64 v1; // rax
  __int64 v3; // rcx
  DWORD v4; // edi
  DWORD v5; // ebp
  LARGE_INTEGER v6; // r14
  bool v7; // r9
  __int64 v8; // rax
  __int64 v9; // r11
  int v10; // r10d
  LARGE_INTEGER *v11; // rbx
  LARGE_INTEGER *v12; // r11
  __int64 v13; // r8
  __int64 v14; // rdx
  bool v15; // zf
  unsigned __int16 v16; // ax
  DTlsHandshakeQueue *v17; // rcx
  struct kexch *KeyExchangeInfo; // rax
  int v19; // r10d
  _DWORD *v20; // r11
  char v21[8]; // [rsp+A0h] [rbp-708h] BYREF
  DWORD v22; // [rsp+A8h] [rbp-700h]
  LONG v23; // [rsp+ACh] [rbp-6FCh]

  v1 = *(_QWORD *)this;
  *((_DWORD *)this + 17) = 4;
  (*(void (**)(void))(v1 + 456))();
  if ( *((_BYTE *)this + 233) )
  {
    v16 = CSslContext::computeMaxPayload(this, *((unsigned __int16 *)this + 108));
    v17 = (DTlsHandshakeQueue *)*((_QWORD *)this + 73);
    *((_WORD *)this + 109) = v16;
    DTlsHandshakeQueue::DtlsHandshakeDone(v17);
    **((_DWORD **)this + 72) = 0;
    *((_WORD *)this + 110) = 0;
  }
  memset_0(v21, 0, 0x6E8ui64);
  v3 = *((_QWORD *)this + 1);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 28);
    v22 = v4;
  }
  else
  {
    v4 = 0;
    v22 = 0;
  }
  v5 = *((unsigned __int16 *)this + 17);
  v6 = *(LARGE_INTEGER *)((char *)this + 136);
  v7 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
  v23 = *((_DWORD *)this + 4);
  if ( v3 )
  {
    v8 = *((_QWORD *)this + 11);
    if ( v8 )
    {
      v9 = *((_QWORD *)this + 15);
      v10 = *(_DWORD *)(v3 + 32);
      if ( v9 )
      {
        if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        {
          *(_DWORD *)(v9 + 48) = *(_DWORD *)(v8 + 8);
          if ( v10 == 43522 || v10 == 41984 )
          {
            KeyExchangeInfo = GetKeyExchangeInfo(v10);
            if ( KeyExchangeInfo )
            {
              v20[13] = *((_DWORD *)KeyExchangeInfo + 8);
              v20[14] = *((_DWORD *)KeyExchangeInfo + 10);
              if ( v19 == 43522 )
                v20[15] = *((_DWORD *)KeyExchangeInfo + 12);
            }
          }
        }
      }
    }
  }
  v11 = (LARGE_INTEGER *)*((_QWORD *)this + 15);
  v12 = v11;
  if ( v11 )
  {
    if ( !v7 )
      return;
    v11[4].HighPart = v23;
    v11[4].LowPart = v4;
    v11[5].LowPart = v5;
    v11[16] = v6;
    QueryPerformanceCounter(v11 + 11);
    v13 = 1000 * (v11[11].QuadPart - v11[10].QuadPart);
    v11[12].QuadPart = v13;
    if ( CSchannelTelemetryContext::m_liPerfCtrFreq.QuadPart == 10000000 )
      v14 = v13 / 10000000;
    else
      v14 = v13 / CSchannelTelemetryContext::m_liPerfCtrFreq.QuadPart;
    v15 = v11[13].LowPart == -2146893032;
    v11[12].QuadPart = v14;
    if ( v15 )
    {
      v11[13].LowPart = 0;
      v11[14].LowPart = 0;
    }
    CSchannelTelemetryContext::WriteEvent((CSchannelTelemetryContext *)v11, 0, v13);
    v12 = (LARGE_INTEGER *)*((_QWORD *)this + 15);
    v7 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
  }
  if ( v12
    && v7
    && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_SSSdiiDDDDDddiDDd(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      HIWORD(v12[8].u.LowPart),
      LOWORD(v12[8].LowPart),
      L"Server",
      (const wchar_t *)&v12[19],
      (const wchar_t *)&v12[83],
      v12[3].LowPart,
      v12[15].QuadPart,
      v12[16].QuadPart,
      v12[4].LowPart,
      v12[4].HighPart,
      v12[5].LowPart,
      v12[5].HighPart,
      v12[6].LowPart,
      v12[8].LowPart,
      HIWORD(v12[8].u.LowPart),
      v12[12].QuadPart,
      v12[13].LowPart,
      BYTE4(v12[13].QuadPart),
      v12[14].LowPart);
  }
}
// 1800229FF: variable 'v7' is possibly undefined
// 18003FBD5: variable 'v20' is possibly undefined
// 18003FBE7: variable 'v19' is possibly undefined
// 180082BC8: using guessed type wchar_t aServer_0[7];
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 180022910: using guessed type char var_708[8];
