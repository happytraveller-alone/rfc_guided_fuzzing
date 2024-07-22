void __fastcall CSslContext::SetError(__int64 a1, int a2, int a3) {
  __int64 v3;           // rax
  __int64 v7;           // r8
  __int64 v8;           // rcx
  int v9;               // edi
  int v10;              // r14d
  __int64 v11;          // r15
  __int64 v12;          // rcx
  unsigned __int64 v13; // rax
  __int64 v14;          // rax
  char v15[8];          // [rsp+20h] [rbp-708h] BYREF
  unsigned __int64 v16; // [rsp+28h] [rbp-700h]

  v3 = *(_QWORD *)(a1 + 128);
  if (!*(_WORD *)(v3 + 34)) {
    *(_WORD *)(v3 + 34) = a2;
    *(_DWORD *)(v3 + 36) = a3;
  }
  memset_0(v15, 0, 0x6E8ui64);
  v8 = *(_QWORD *)(a1 + 8);
  if (v8) {
    v9 = *(_DWORD *)(v8 + 28);
    LODWORD(v16) = v9;
  } else {
    v9 = 0;
    LODWORD(v16) = 0;
  }
  v10 = *(unsigned __int16 *)(a1 + 34);
  v11 = *(_QWORD *)(a1 + 136);
  HIDWORD(v16) = *(_DWORD *)(a1 + 16);
  if (v8) {
    v14 = *(_QWORD *)(a1 + 88);
    if (v14)
      CSchannelTelemetryContext::LogKeyExchange(
          *(CSchannelTelemetryContext **)(a1 + 120), *(_DWORD *)(v8 + 32),
          *(_DWORD *)(v14 + 8));
  }
  v12 = *(_QWORD *)(a1 + 120);
  if (v12) {
    if (CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized) {
      v13 = HIDWORD(v16);
      *(_DWORD *)(v12 + 104) = a3;
      *(_DWORD *)(v12 + 112) = a2;
      *(_DWORD *)(v12 + 32) = v9;
      *(_DWORD *)(v12 + 36) = v13;
      *(_DWORD *)(v12 + 40) = v10;
      *(_QWORD *)(v12 + 128) = v11;
      if (a3 != -2146893032)
        CSchannelTelemetryContext::WriteEvent((CSchannelTelemetryContext *)v12,
                                              1, v7);
    }
  }
  CSchannelTelemetryContext::LogDebugTraceHandshakeInfo(
      *(CSchannelTelemetryContext **)(a1 + 120), L"Error");
}