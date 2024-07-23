//----- (0000000180011144) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::LogAppName(CSchannelTelemetryContext *this)
{
  __int64 v1; // r8

  if ( this && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
  {
    v1 = *((_QWORD *)this + 17);
    if ( v1 )
      o_wcsncpy_s_0((char *)this + 664, 256i64, v1 + 216, -1i64);
  }
}
// 180028D84: using guessed type __int64 __fastcall o_wcsncpy_s_0(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

