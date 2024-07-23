// File count: 1010
// Total lines: 164
---------------------------------------
__int64 __fastcall SchGetTrustedRoots(void **a1, __int64 a2)
{
  HCERTSTORE v4; // r15
  DWORD LastError; // ebx
  HCERTSTORE v6; // rax
  void *v7; // r14
  DWORD v8; // eax
  PCCERT_CONTEXT i; // rsi
  __int64 v10; // r8
  __int64 v11; // r9
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9
  DWORD v15; // eax
  __int64 v16; // rdx
  char v17; // al
  __int64 v18; // rcx
  __int64 v19; // r8
  __int64 v20; // r9
  DWORD v21; // eax
  const CERT_CHAIN_CONTEXT *v22; // rcx
  int v24; // [rsp+40h] [rbp-158h] BYREF
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+48h] [rbp-150h] BYREF
  const char *v26; // [rsp+50h] [rbp-148h] BYREF
  struct _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+58h] [rbp-140h] BYREF
  int v28[4]; // [rsp+68h] [rbp-130h] BYREF
  __int64 v29; // [rsp+78h] [rbp-120h]
  struct _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+80h] [rbp-118h] BYREF
  struct _CERT_CHAIN_PARA pChainPara; // [rsp+A0h] [rbp-F8h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v32; // [rsp+100h] [rbp-98h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v33; // [rsp+110h] [rbp-88h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v34; // [rsp+120h] [rbp-78h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v35; // [rsp+130h] [rbp-68h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v36; // [rsp+140h] [rbp-58h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v37; // [rsp+150h] [rbp-48h] BYREF

  pChainContext = 0i64;
  v24 = 0;
  v4 = CertOpenStore((LPCSTR)2, 0, 0i64, 4u, 0i64);
  if ( !v4 )
  {
    LastError = GetLastError();
    goto LABEL_42;
  }
  LastError = SslImpersonateClient(a2, &v24);
  if ( !LastError )
  {
    v6 = CertOpenStore((LPCSTR)0xA, 0, 0i64, 0x18001u, L"ROOT");
    v7 = v6;
    if ( !v6 )
    {
      v8 = GetLastError();
      LastError = v8;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v8);
      goto LABEL_40;
    }
    for ( i = CertEnumCertificatesInStore(v6, 0i64); i; i = CertEnumCertificatesInStore(v7, i) )
    {
      if ( IsCertSelfSigned(i) )
      {
        v26 = "1.3.6.1.5.5.7.3.2";
        memset_0(&pChainPara, 0, 0x60ui64);
        pChainPara.cbSize = 96;
        pChainPara.RequestedUsage.dwType = 1;
        pChainPara.RequestedUsage.Usage.cUsageIdentifier = 1;
        pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = (LPSTR *)&v26;
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          McGenEventWrite_EventWriteTransfer(1i64, &ChainBuildStart, v10, v11, &v32);
        if ( !CertGetCertificateChain(0i64, i, 0i64, 0i64, &pChainPara, 0, 0i64, &pChainContext) )
        {
          if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
            McGenEventWrite_EventWriteTransfer(v12, &ChainBuildStop, v13, v14, &v33);
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            continue;
          }
          v15 = GetLastError();
          v16 = 14i64;
LABEL_37:
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), v16, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v15);
          continue;
        }
        v17 = Microsoft_Windows_Schannel_EventsEnableBits;
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        {
          McGenEventWrite_EventWriteTransfer(v12, &ChainBuildStop, v13, v14, &v34);
          v17 = Microsoft_Windows_Schannel_EventsEnableBits;
        }
        v28[3] = 0;
        v28[2] = 0;
        v29 = 0i64;
        pPolicyPara.pvExtraPolicyPara = v28;
        v28[0] = 24;
        v28[1] = 1;
        pPolicyPara.cbSize = 16;
        pPolicyPara.dwFlags = 7;
        memset(&pPolicyStatus, 0, sizeof(pPolicyStatus));
        pPolicyStatus.cbSize = 24;
        if ( (v17 & 1) != 0 )
          McGenEventWrite_EventWriteTransfer((__int64)v28, &ChainVerifyStart, v13, v14, &v35);
        if ( CertVerifyCertificateChainPolicy((LPCSTR)4, pChainContext, &pPolicyPara, &pPolicyStatus) )
        {
          if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
            McGenEventWrite_EventWriteTransfer(v18, &ChainVerifyStop, v19, v20, &v37);
          v22 = pChainContext;
          if ( !pPolicyStatus.dwError )
          {
            CertFreeCertificateChain(pChainContext);
            if ( CertAddCertificateContextToStore(v4, i, 2u, 0i64)
              || WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
            {
              continue;
            }
            v15 = GetLastError();
            v16 = 16i64;
            goto LABEL_37;
          }
        }
        else
        {
          if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
            McGenEventWrite_EventWriteTransfer(v18, &ChainVerifyStop, v19, v20, &v36);
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            v21 = GetLastError();
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v21);
          }
          v22 = pChainContext;
        }
        CertFreeCertificateChain(v22);
      }
    }
    CertCloseStore(v7, 0);
  }
LABEL_40:
  if ( v24 )
    RevertToSelf();
LABEL_42:
  if ( LastError )
    CertCloseStore(v4, 0);
  else
    *a1 = v4;
  return LastError;
}
// 180054840: variable 'v10' is possibly undefined
// 180054840: variable 'v11' is possibly undefined
// 18005489F: variable 'v12' is possibly undefined
// 18005489F: variable 'v13' is possibly undefined
// 18005489F: variable 'v14' is possibly undefined
// 1800549B5: variable 'v18' is possibly undefined
// 1800549B5: variable 'v19' is possibly undefined
// 1800549B5: variable 'v20' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C60: using guessed type EVENT_DESCRIPTOR ChainVerifyStop;
// 180084C70: using guessed type EVENT_DESCRIPTOR ChainVerifyStart;
// 180084C80: using guessed type EVENT_DESCRIPTOR ChainBuildStop;
// 180084C90: using guessed type EVENT_DESCRIPTOR ChainBuildStart;
// 1800854C0: using guessed type wchar_t aRoot[5];
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
