// File count: 1341
// Total lines: 48
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseKeyUpdate(__int64 a1, _BYTE *a2, int a3)
{
  _DWORD *v4; // rcx
  unsigned __int8 v5; // r9
  int v6; // edx

  if ( !a2 || !a3 )
    return 87i64;
  if ( a3 != 1 )
  {
    v4 = *(_DWORD **)(a1 + 8);
    v5 = 50;
    v6 = 1602;
LABEL_5:
    CSslContext::SetErrorAndFatalAlert((__int64)v4, v6, -2146893048, v5);
    return 2148074248i64;
  }
  if ( *a2 )
  {
    v4 = *(_DWORD **)(a1 + 8);
    if ( *a2 != 1 )
    {
      v5 = 47;
      v6 = 1603;
      goto LABEL_5;
    }
    if ( (v4[34] & 0x1000i64) != 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
        v4 = *(_DWORD **)(a1 + 8);
      }
      LOBYTE(a2) = 1;
      (*(void (__fastcall **)(_DWORD *, _BYTE *))(*(_QWORD *)v4 + 408i64))(v4, a2);
    }
  }
  return 0i64;
}
// 180069B04: variable 'a2' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
