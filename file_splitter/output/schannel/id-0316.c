// File count: 316
// Total lines: 25
-----------------------------------------
void __fastcall CSchannelTelemetryContext::LogUnknownTlsExtension(CSchannelTelemetryContext *this, int a2)
{
  __int64 v2; // rax

  if ( this && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
  {
    if ( a2 > 16 )
    {
      if ( a2 < 23 || a2 > 24 && a2 != 35 && a2 != 65281 )
        goto LABEL_17;
    }
    else if ( a2 != 16 && (a2 < 0 || a2 > 6 && (a2 <= 9 || a2 > 11 && (a2 <= 12 || a2 > 14))) )
    {
LABEL_17:
      v2 = *((unsigned __int16 *)this + 892);
      if ( (unsigned int)v2 < 0x32 )
      {
        *((_DWORD *)this + v2 + 396) = a2;
        ++*((_WORD *)this + 892);
      }
    }
  }
}
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
