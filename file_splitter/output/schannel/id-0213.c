// File count: 213
// Total lines: 28
-----------------------------------------
void __fastcall CSchannelTelemetryContext::LogHandshakeEnd(LARGE_INTEGER *a1, LARGE_INTEGER *a2)
{
  __int64 v3; // r8
  __int64 v4; // rax
  bool v5; // zf

  if ( a1 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
  {
    a1[4].LowPart = a2[1].LowPart;
    a1[4].HighPart = a2[1].HighPart;
    a1[5].LowPart = a2[2].LowPart;
    a1[16] = a2[13];
    QueryPerformanceCounter(a1 + 11);
    v4 = 1000 * (a1[11].QuadPart - a1[10].QuadPart);
    a1[12].QuadPart = v4;
    v5 = a1[13].LowPart == -2146893032;
    a1[12].QuadPart = v4 / CSchannelTelemetryContext::m_liPerfCtrFreq.QuadPart;
    if ( v5 )
    {
      a1[13].LowPart = 0;
      a1[14].LowPart = 0;
    }
    CSchannelTelemetryContext::WriteEvent((CSchannelTelemetryContext *)a1, 0, v3);
  }
}
// 180012440: variable 'v3' is possibly undefined
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
