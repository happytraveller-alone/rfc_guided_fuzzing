//----- (0000000180053000) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::LogCertKeyUsageError(__int64 a1, int a2, const unsigned __int16 *a3)
{
  int v3; // [rsp+30h] [rbp-18h] BYREF
  const WCHAR *v4; // [rsp+38h] [rbp-10h] BYREF
  int v5; // [rsp+68h] [rbp+20h] BYREF

  if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized
    && (unsigned int)dword_180091480 > 5
    && (qword_180091490 & 0x400000000000i64) != 0
    && (qword_180091498 & 0x400000000000i64) == qword_180091498 )
  {
    v5 = a2;
    v4 = a3;
    v3 = a1;
    _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteAgg(_tlgProvider_t const *,void const *,void const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),void const *>::Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned short>>(
      a1,
      byte_180084988,
      (__int64)a3,
      (__int64)&v3,
      (__int64)&v5,
      &v4);
  }
}
// 180084988: using guessed type unsigned __int8 byte_180084988[80];
// 180091490: using guessed type __int64 qword_180091490;
// 180091498: using guessed type __int64 qword_180091498;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

