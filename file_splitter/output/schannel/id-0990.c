//----- (0000000180053078) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::LogRCMPUsage(__int16 a1)
{
  __int16 v1; // [rsp+30h] [rbp-48h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v2; // [rsp+38h] [rbp-40h] BYREF
  __int16 *v3; // [rsp+58h] [rbp-20h]
  int v4; // [rsp+60h] [rbp-18h]
  int v5; // [rsp+64h] [rbp-14h]

  if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized
    && (unsigned int)dword_180091480 > 5
    && (qword_180091490 & 0x400000000000i64) != 0
    && (qword_180091498 & 0x400000000000i64) == qword_180091498 )
  {
    v1 = a1;
    v3 = &v1;
    v5 = 0;
    v4 = 2;
    tlgWriteTransfer_EventWriteTransfer(
      (__int64)&dword_180091480,
      (unsigned __int8 *)dword_18008495B,
      0i64,
      0i64,
      3u,
      &v2);
  }
}
// 18008495B: using guessed type int dword_18008495B[11];
// 180091490: using guessed type __int64 qword_180091490;
// 180091498: using guessed type __int64 qword_180091498;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

