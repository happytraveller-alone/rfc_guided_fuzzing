//----- (0000000180073FE8) ----------------------------------------------------
void __fastcall RunClientCertPolicy(struct CCredentialGroup *a1, PCCERT_CONTEXT pCertContext, _DWORD *a3)
{
  _DWORD *v3; // rdi
  bool v7; // zf
  DWORD v8; // ebx
  __int64 v9; // rcx
  __int64 v10; // r8
  __int64 v11; // r9
  void *ChainEngine; // r15
  __int64 v13; // rcx
  __int64 v14; // r8
  __int64 v15; // r9
  DWORD LastError; // eax
  char v17; // al
  __int64 v18; // rcx
  __int64 v19; // r8
  __int64 v20; // r9
  __int64 dwError; // rdx
  const char *v22; // r9
  __int64 dwFlags; // [rsp+28h] [rbp-120h]
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+40h] [rbp-108h] BYREF
  struct _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+48h] [rbp-100h] BYREF
  const char *v26; // [rsp+60h] [rbp-E8h] BYREF
  struct _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+68h] [rbp-E0h] BYREF
  int v28[2]; // [rsp+78h] [rbp-D0h] BYREF
  __int64 v29; // [rsp+80h] [rbp-C8h]
  __int64 v30; // [rsp+88h] [rbp-C0h]
  struct _CERT_CHAIN_PARA pChainPara; // [rsp+90h] [rbp-B8h] BYREF
  int v32; // [rsp+C8h] [rbp-80h]
  int v33; // [rsp+CCh] [rbp-7Ch]
  int v34; // [rsp+D0h] [rbp-78h]
  struct _EVENT_DATA_DESCRIPTOR v35; // [rsp+F0h] [rbp-58h] BYREF

  v3 = (_DWORD *)*((_QWORD *)a1 + 106);
  v26 = "1.3.6.1.5.5.7.3.2";
  pChainContext = 0i64;
  if ( !v3 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids);
    return;
  }
  memset_0(&pChainPara, 0, 0x60ui64);
  pChainPara.cbSize = 96;
  v32 = v3[5];
  v33 = v3[6];
  v34 = v3[7];
  v7 = v3[8] == 1;
  pChainPara.RequestedUsage.dwType = 0;
  if ( v7 )
  {
    pChainPara.RequestedUsage.Usage.cUsageIdentifier = 0;
    pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = 0i64;
  }
  else
  {
    pChainPara.RequestedUsage.Usage.cUsageIdentifier = 1;
    pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = (LPSTR *)&v26;
  }
  v8 = v3[4];
  ChainEngine = (void *)CreateChainEngine(a1);
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v9, &ChainBuildStart, v10, v11, &v35);
  if ( CertGetCertificateChain(
         ChainEngine,
         pCertContext,
         0i64,
         pCertContext->hCertStore,
         &pChainPara,
         v8,
         0i64,
         &pChainContext) )
  {
    v17 = Microsoft_Windows_Schannel_EventsEnableBits;
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    {
      McGenEventWrite_EventWriteTransfer(v13, &ChainBuildStop, v14, v15, &v35);
      v17 = Microsoft_Windows_Schannel_EventsEnableBits;
    }
    v29 = 0i64;
    pPolicyPara.pvExtraPolicyPara = v28;
    v28[0] = 24;
    v28[1] = 1;
    v30 = 0i64;
    *(_QWORD *)&pPolicyPara.cbSize = 16i64;
    memset(&pPolicyStatus, 0, sizeof(pPolicyStatus));
    pPolicyStatus.cbSize = 24;
    if ( (v17 & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(0i64, &ChainVerifyStart, v14, v15, &v35);
    if ( !CertVerifyCertificateChainPolicy((LPCSTR)4, pChainContext, &pPolicyPara, &pPolicyStatus) )
    {
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        McGenEventWrite_EventWriteTransfer(v18, &ChainVerifyStop, v19, v20, &v35);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          13i64,
          &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids,
          pPolicyStatus.dwError);
      goto LABEL_46;
    }
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v18, &ChainVerifyStop, v19, v20, &v35);
    dwError = pPolicyStatus.dwError;
    if ( pPolicyStatus.dwError == -2146885614 )
      dwError = 0i64;
    pPolicyStatus.dwError = dwError;
    if ( (_DWORD)dwError )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        LODWORD(dwFlags) = v3[8];
        WPP_SF_Dqd(*((_QWORD *)WPP_GLOBAL_Control + 2), dwError, v19, dwError, a1, dwFlags);
        LODWORD(dwError) = pPolicyStatus.dwError;
      }
      *a3 = dwError;
      goto LABEL_46;
    }
    if ( !pChainContext->cChain )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids);
      goto LABEL_46;
    }
    if ( g_eClientAuthMode >= 0 )
    {
      if ( g_eClientAuthMode <= 1 )
      {
        if ( !CCredentialGroup::CheckForValidIssuer(a1, pChainContext) )
          goto LABEL_46;
      }
      else if ( g_eClientAuthMode != 2 )
      {
        goto LABEL_46;
      }
      *a3 = 0;
    }
LABEL_46:
    if ( pChainContext )
      CertFreeCertificateChain(pChainContext);
    goto LABEL_48;
  }
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EventWriteTransfer(v13, &ChainBuildStop, v14, v15, &v35);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    LastError = GetLastError();
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids, LastError);
  }
  pChainContext = 0i64;
LABEL_48:
  if ( ChainEngine != (void *)1 )
    CertFreeCertificateChainEngine(ChainEngine);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v22 = "FOUND";
    if ( *a3 )
      v22 = "DID NOT FIND";
    WPP_SF_s(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x10u, (__int64)&WPP_ee3ada077a243a8835f858b78da5bb63_Traceguids, v22);
  }
}
// 18007410E: variable 'v9' is possibly undefined
// 18007410E: variable 'v10' is possibly undefined
// 18007410E: variable 'v11' is possibly undefined
// 180074173: variable 'v13' is possibly undefined
// 180074173: variable 'v14' is possibly undefined
// 180074173: variable 'v15' is possibly undefined
// 180074297: variable 'v18' is possibly undefined
// 180074297: variable 'v19' is possibly undefined
// 180074297: variable 'v20' is possibly undefined
// 180074332: variable 'dwFlags' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C60: using guessed type EVENT_DESCRIPTOR ChainVerifyStop;
// 180084C70: using guessed type EVENT_DESCRIPTOR ChainVerifyStart;
// 180084C80: using guessed type EVENT_DESCRIPTOR ChainBuildStop;
// 180084C90: using guessed type EVENT_DESCRIPTOR ChainBuildStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
