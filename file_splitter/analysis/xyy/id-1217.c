//----- (0000000180061134) ----------------------------------------------------
unsigned __int8 __fastcall CSsl3TlsClientContext::IsMaliciousDowngrade(CSsl3TlsClientContext *this, int a2)
{
  const unsigned __int8 near *const *v4; // rdx
  int v6; // [rsp+20h] [rbp-18h]

  if ( (*((_DWORD *)this + 16) & 0x2000) != 0 )
    return 0;
  v4 = &CSsl3TlsContext::m_rgbTls12Downgrade;
  if ( (*((_DWORD *)this + 16) & 0x80800) == 0 )
    v4 = &CSsl3TlsContext::m_rgbTls11OrBelowDowngrade;
  if ( RtlCompareMemory((char *)this + 328, v4, 8ui64) != 8 )
    return 0;
  CSslContext::SetErrorAndFatalAlert((__int64)this, 105, -2146893048, 0x2Fu);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    v6 = a2;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x4Du,
      (__int64)&WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
      *((_DWORD *)this + 9),
      v6);
  }
  return 1;
}
// 180082BB8: using guessed type const unsigned __int8 near *const CSsl3TlsContext::m_rgbTls11OrBelowDowngrade;
// 180082BC0: using guessed type const unsigned __int8 near *const CSsl3TlsContext::m_rgbTls12Downgrade;
