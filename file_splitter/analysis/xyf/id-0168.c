//----- (000000018000EBEC) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::LogHandshakeStart(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v8; // zf

  if ( a1 )
  {
    if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
    {
      *(_DWORD *)(a1 + 12) = a2;
      QueryPerformanceCounter((LARGE_INTEGER *)(a1 + 80));
      *(_DWORD *)(a1 + 24) = 0;
      v8 = *(_DWORD *)(a1 + 12) == 1;
      *(_QWORD *)(a1 + 120) = a3;
      *(_QWORD *)(a1 + 136) = a4;
      *(_BYTE *)(a1 + 28) = v8;
      *(_QWORD *)(a1 + 144) = a5;
      CSchannelTelemetryContext::LogAppName((CSchannelTelemetryContext *)a1);
    }
  }
}
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

