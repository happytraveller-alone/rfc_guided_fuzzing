//----- (00000001800149C0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::ProcessRecord(__int64 a1, int a2, unsigned __int8 *a3, unsigned int a4)
{
  int v4; // r10d
  __int64 result; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rcx
  unsigned int SessionKeys; // esi

  v4 = *(_DWORD *)(a1 + 68);
  if ( v4 != 51 )
  {
LABEL_2:
    if ( a2 != 20 )
      return CSsl3TlsContext::ProcessRecord(a1, a2, a3, a4);
    if ( v4 == 46 )
    {
LABEL_6:
      if ( !(unsigned int)CSsl3TlsContext::DigestCcs((CSsl3TlsContext *)a1, a3, a4) )
      {
        if ( *(_DWORD *)(a1 + 68) == 47 || *(_DWORD *)(a1 + 68) == 52 )
          *(_DWORD *)(a1 + 68) = 48;
        else
          *(_DWORD *)(a1 + 68) = 45;
      }
      return CSsl3TlsContext::ProcessRecord(a1, a2, a3, a4);
    }
    if ( v4 != 47 )
    {
      if ( v4 == 50 )
        goto LABEL_6;
      if ( v4 != 52 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_Sd(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0xDu,
            (__int64)&WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
            *(const wchar_t **)(*(_QWORD *)(a1 + 1320) + 368i64),
            v4);
        return CSsl3TlsContext::ProcessRecord(a1, a2, a3, a4);
      }
    }
    v10 = *(_QWORD *)(a1 + 136);
    if ( (v10 & 0x1000000) != 0 )
    {
      if ( (v10 & 0x8000000) == 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        CSslContext::SetErrorAndFatalAlert(a1, 106, -2146893018, 0x28u);
        return CSsl3TlsContext::ProcessRecord(a1, a2, a3, a4);
      }
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xBu,
          (__int64)&WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
          *(const wchar_t **)(*(_QWORD *)(a1 + 1320) + 368i64));
      v11 = *(_QWORD *)(a1 + 120);
      if ( v11 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
      {
        *(_DWORD *)(v11 + 24) = 1;
        *(_WORD *)(v11 + 64) |= 0xAu;
      }
      v12 = *(_QWORD *)(a1 + 1320);
      *(_QWORD *)(a1 + 136) &= ~0x1000000ui64;
      RtlAcquireResourceShared((PRTL_RESOURCE)(v12 + 72), 1u);
      SessionKeys = CSslContext::MakeSessionKeys((CSslContext *)a1, *(_QWORD *)(*(_QWORD *)(a1 + 1320) + 16i64));
      RtlReleaseResource((PRTL_RESOURCE)(*(_QWORD *)(a1 + 1320) + 72i64));
      if ( SessionKeys )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            12i64,
            &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
            SessionKeys);
        return CSsl3TlsContext::ProcessRecord(a1, a2, a3, a4);
      }
    }
    goto LABEL_6;
  }
  if ( (*(_DWORD *)(a1 + 136) & 0x40000000) == 0 || *(_BYTE *)(a1 + 266) )
  {
LABEL_14:
    *(_DWORD *)(a1 + 68) = 46;
    v4 = 46;
    goto LABEL_2;
  }
  result = RemotelyGetUserKeys((struct CSslContext *)a1, 2u);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 136) &= ~0x40000000ui64;
    goto LABEL_14;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

