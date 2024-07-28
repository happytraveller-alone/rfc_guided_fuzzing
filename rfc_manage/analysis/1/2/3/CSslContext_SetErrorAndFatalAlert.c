void __fastcall CSslContext::SetErrorAndFatalAlert(__int64 a1, int a2, int a3,
                                                   unsigned __int8 a4) {
  int v5;                                   // ebp
  __int64 v8;                               // rax
  __int64 v9;                               // rcx
  __int64 v10;                              // rdx
  const WCHAR *v11;                         // rdi
  unsigned int v12;                         // r14d
  __int64 v13;                              // r8
  __int64 v14;                              // rcx
  int v15;                                  // edi
  int v16;                                  // r14d
  __int64 v17;                              // r15
  __int64 v18;                              // rax
  __int64 v19;                              // rcx
  CSchannelTelemetryContext *v20;           // rax
  struct _UNICODE_STRING v21;               // [rsp+40h] [rbp-738h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+50h] [rbp-728h] BYREF
  char v23[8];                              // [rsp+60h] [rbp-718h] BYREF
  int v24;                                  // [rsp+68h] [rbp-710h]
  int v25;                                  // [rsp+6Ch] [rbp-70Ch]

  v5 = a4;
  v8 = (*(__int64(__fastcall **)(__int64))(*(_QWORD *)a1 + 320i64))(a1);
  v9 = *(_QWORD *)(a1 + 128);
  if (!*(_WORD *)(v9 + 34)) {
    *(_WORD *)(v9 + 34) = a2;
    *(_DWORD *)(v9 + 36) = a3;
  }
  v10 = *(_QWORD *)(a1 + 80);
  v11 = &Class;
  *(_BYTE *)(a1 + 96) = 2;
  *(_BYTE *)(a1 + 97) = v5;
  if (v8)
    v11 = (const WCHAR *)v8;
  v12 = *(_DWORD *)(v10 + 212);
  if ((g_dwEventLogging & 4) != 0) {
    RtlInitUnicodeString(&DestinationString, (PCWSTR)(v10 + 216));
    RtlInitUnicodeString(&v21, v11);
    SchEventWrite(&SSLEVENT_GENERATE_FATAL_ALERT, L"duddu", v12,
                  &DestinationString, v5, a2, &v21);
  }
  memset_0(v23, 0, 0x6E8ui64);
  v14 = *(_QWORD *)(a1 + 8);
  if (v14) {
    v15 = *(_DWORD *)(v14 + 28);
    v24 = v15;
  } else {
    v15 = 0;
    v24 = 0;
  }
  v16 = *(unsigned __int16 *)(a1 + 34);
  v17 = *(_QWORD *)(a1 + 136);
  v25 = *(_DWORD *)(a1 + 16);
  if (v14) {
    v18 = *(_QWORD *)(a1 + 88);
    if (v18)
      CSchannelTelemetryContext::LogKeyExchange(
          *(CSchannelTelemetryContext **)(a1 + 120), *(_DWORD *)(v14 + 32),
          *(_DWORD *)(v18 + 8));
  }
  v19 = *(_QWORD *)(a1 + 120);
  v20 = (CSchannelTelemetryContext *)v19;
  if (v19 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized) {
    *(_DWORD *)(v19 + 36) = v25;
    *(_BYTE *)(v19 + 108) = v5;
    *(_DWORD *)(v19 + 104) = a3;
    *(_DWORD *)(v19 + 112) = a2;
    *(_DWORD *)(v19 + 32) = v15;
    *(_DWORD *)(v19 + 40) = v16;
    *(_QWORD *)(v19 + 128) = v17;
    CSchannelTelemetryContext::WriteEvent((CSchannelTelemetryContext *)v19, 1,
                                          v13);
    v20 = *(CSchannelTelemetryContext **)(a1 + 120);
  }
  CSchannelTelemetryContext::LogDebugTraceHandshakeInfo(v20, L"Fatal Error");
}