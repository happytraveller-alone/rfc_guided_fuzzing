//----- (0000000180026560) ----------------------------------------------------
void __fastcall FipsWatchParamKey(char *a1, char a2)
{
  CCipherMill *v3; // rcx
  BOOLEAN pfEnabled; // [rsp+40h] [rbp+18h] BYREF

  pfEnabled = 0;
  if ( !WatchParamKeyHelper(a1) )
  {
    if ( BCryptGetFipsAlgorithmMode(&pfEnabled) < 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
    }
    else if ( pfEnabled != CSslGlobals::m_bFipsMode )
    {
      CSslGlobals::m_bFipsMode = pfEnabled;
      if ( !a2 )
        CCipherMill::BuildCipherMill(v3);
    }
  }
}
// 18002B67A: variable 'v3' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092F18: using guessed type int CSslGlobals::m_bFipsMode;
