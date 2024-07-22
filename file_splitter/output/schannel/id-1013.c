//----- (0000000180054DE4) ----------------------------------------------------
__int64 __fastcall VerifyClientCertificate(
        PCCERT_CHAIN_CONTEXT pChainContext,
        LPCSTR pszPolicyOID,
        __int64 a3,
        __int64 a4)
{
  __int16 v5; // r14
  __int64 v7; // rcx
  __int64 v8; // r8
  __int64 v9; // r9
  unsigned int v10; // edi
  struct _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+30h] [rbp-19h] BYREF
  int v13[3]; // [rsp+40h] [rbp-9h] BYREF
  __int64 v14; // [rsp+4Ch] [rbp+3h]
  int v15; // [rsp+54h] [rbp+Bh]
  struct _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+58h] [rbp+Fh] BYREF
  struct _EVENT_DATA_DESCRIPTOR v17; // [rsp+70h] [rbp+27h] BYREF

  pPolicyPara.cbSize = 16;
  v5 = a3;
  if ( pszPolicyOID == (LPCSTR)6 )
  {
    pPolicyPara.pvExtraPolicyPara = 0i64;
    pPolicyPara.dwFlags = 0x40000000;
  }
  else
  {
    v14 = 0i64;
    v15 = 0;
    v13[2] = 0;
    pPolicyPara.dwFlags = 0;
    pPolicyPara.pvExtraPolicyPara = v13;
    v13[0] = 24;
    v13[1] = 1;
  }
  memset(&pPolicyStatus, 0, sizeof(pPolicyStatus));
  pPolicyStatus.cbSize = 24;
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(24i64, &ChainVerifyStart, a3, a4, &v17);
  if ( CertVerifyCertificateChainPolicy(pszPolicyOID, pChainContext, &pPolicyPara, &pPolicyStatus) )
  {
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v7, &ChainVerifyStop, v8, v9, &v17);
    v10 = I_MapWinTrustErrorAndAlert(pPolicyStatus.dwError, 0, v5, 0i64);
    if ( v10 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v10);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v7, &ChainVerifyStop, v8, v9, &v17);
    return GetLastError();
  }
  return v10;
}
// 180054EB8: variable 'v7' is possibly undefined
// 180054EB8: variable 'v8' is possibly undefined
// 180054EB8: variable 'v9' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C60: using guessed type EVENT_DESCRIPTOR ChainVerifyStop;
// 180084C70: using guessed type EVENT_DESCRIPTOR ChainVerifyStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;

