// File count: 991
// Total lines: 23
-----------------------------------------
bool __fastcall CSchannelTelemetryContext::LogRenegoStart(__int64 a1, int a2, __int64 a3)
{
  bool v5; // zf
  bool result; // al

  if ( a1 )
  {
    if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
    {
      *(_BYTE *)(a1 + 16) = 1;
      *(_DWORD *)(a1 + 12) = a2;
      QueryPerformanceCounter((LARGE_INTEGER *)(a1 + 80));
      v5 = *(_DWORD *)(a1 + 12) == 1;
      *(_DWORD *)(a1 + 24) = 2;
      result = v5;
      *(_QWORD *)(a1 + 120) = a3;
      *(_BYTE *)(a1 + 28) = v5;
    }
  }
  return result;
}
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
