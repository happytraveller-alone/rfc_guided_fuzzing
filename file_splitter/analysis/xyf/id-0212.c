//----- (0000000180012368) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::LogDebugTraceHandshakeInfo(
        CSchannelTelemetryContext *this,
        unsigned __int16 *const a2)
{
  int v2; // [rsp+88h] [rbp-20h]
  int v3; // [rsp+90h] [rbp-18h]
  int v4; // [rsp+98h] [rbp-10h]

  if ( this
    && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized
    && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v4 = *((_DWORD *)this + 28);
    v3 = *((unsigned __int8 *)this + 108);
    v2 = *((_DWORD *)this + 26);
    WPP_SF_SSSdiiDDDDDddiDDd(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      *((unsigned __int16 *)this + 33),
      *((unsigned __int16 *)this + 32),
      a2,
      (const wchar_t *)this + 76,
      (const wchar_t *)this + 332,
      *((_DWORD *)this + 6),
      *((_QWORD *)this + 15),
      *((_QWORD *)this + 16),
      *((_DWORD *)this + 8),
      *((_DWORD *)this + 9),
      *((_DWORD *)this + 10),
      *((_DWORD *)this + 11),
      *((_DWORD *)this + 12),
      *((_WORD *)this + 32),
      *((_WORD *)this + 33),
      *((_QWORD *)this + 12),
      v2,
      v3,
      v4);
  }
}
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

