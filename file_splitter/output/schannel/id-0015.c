// File count: 15
// Total lines: 98
------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::GenerateResponse(CSsl3TlsClientContext *this, struct SPBuffer *a2)
{
  unsigned int CcsAndFinish; // edi
  int v5; // ecx
  int v6; // ecx
  unsigned int ServerHelloResponse; // eax
  int v9; // ecx
  CCipherMill *v10; // rcx
  __int64 v11; // rdx
  unsigned __int8 v12; // [rsp+30h] [rbp+8h] BYREF

  CcsAndFinish = 0;
  v5 = *((_DWORD *)this + 17) - 4;
  if ( v5 )
  {
    v6 = v5 - 87;
    if ( !v6 )
    {
      v12 = 0;
      CcsAndFinish = CSsl3TlsClientContext::CheckForClientCertificatePrivateKeys(this, &v12);
      if ( !v12 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        ServerHelloResponse = CSsl3TlsClientContext::GenerateServerHelloResponse(this, a2);
        CcsAndFinish = ServerHelloResponse;
        if ( ServerHelloResponse )
        {
          if ( ServerHelloResponse == 590684 )
            *((_DWORD *)this + 17) = 49;
        }
        else
        {
          *((_DWORD *)this + 17) = CSsl3TlsClientContext::IsFalseStartAllowed(this) ? 51 : 46;
        }
      }
      return CcsAndFinish;
    }
    v9 = v6 - 1;
    if ( !v9 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 35i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      CcsAndFinish = CSsl3TlsContext::AllocateAndGenerateCcsAndFinish(this, a2);
      if ( !CcsAndFinish )
        (*(void (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)this + 448i64))(this);
      return CcsAndFinish;
    }
    if ( v9 != 5 )
      return CcsAndFinish;
    v10 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 38i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      v10 = WPP_GLOBAL_Control;
    }
    if ( !*((_BYTE *)this + 233) )
    {
      if ( v10 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v10 + 28) & 4) == 0 )
        return (unsigned int)-2146893018;
      v11 = 39i64;
LABEL_32:
      WPP_SF_(*((_QWORD *)v10 + 2), v11, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      return (unsigned int)-2146893018;
    }
    CcsAndFinish = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, struct SPBuffer *))(*(_QWORD *)this + 216i64))(
                     this,
                     a2);
    if ( !CcsAndFinish )
      *((_DWORD *)this + 17) = 40;
  }
  else
  {
    if ( CSslGlobals::m_fDisableRenegoOnClient )
    {
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        return (unsigned int)-2146893018;
      v11 = 36i64;
      goto LABEL_32;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    CSchannelTelemetryContext::LogRenegoStart(*((_QWORD *)this + 15), 0, *((_QWORD *)this + 17));
    CcsAndFinish = CSsl3TlsClientContext::GenerateRenegotiateClientHello(this, a2);
    if ( !CcsAndFinish )
    {
      *((_DWORD *)this + 17) = 40;
      if ( *((_BYTE *)this + 233) )
        *(_DWORD *)(*((_QWORD *)this + 73) + 36i64) = *(__int16 *)(*(_QWORD *)(*((_QWORD *)this + 73) + 40i64) + 192i64);
    }
    *((_QWORD *)this + 17) &= ~0x40000000ui64;
  }
  return CcsAndFinish;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800927C4: using guessed type int CSslGlobals::m_fDisableRenegoOnClient;
