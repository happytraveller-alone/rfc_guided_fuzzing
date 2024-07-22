//----- (0000000180001268) ----------------------------------------------------
__int64 __fastcall VerifyServerCertificate(struct CSsl3TlsContext *a1, DWORD a2, int a3)
{
  __int64 v5; // r13
  __int64 v6; // r15
  unsigned __int16 *v7; // r14
  const CERT_CONTEXT *Ptr; // rsi
  __int64 v9; // r13
  DWORD v10; // eax
  unsigned int v11; // ebx
  __int64 v12; // rdx
  int v13; // eax
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // r8
  __int64 v17; // r9
  __int64 v18; // rcx
  __int64 v19; // r8
  __int64 v20; // r9
  __int64 v21; // rcx
  __int64 v22; // r8
  __int64 v23; // r9
  __int64 v24; // rcx
  DWORD dwErrorStatus; // edx
  unsigned __int8 v27; // r9
  int v28; // edx
  int v29; // r8d
  DWORD LastError; // eax
  DWORD v31; // eax
  unsigned __int8 v32; // r9
  char v33[8]; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v34; // [rsp+48h] [rbp-B8h] BYREF
  int v35; // [rsp+50h] [rbp-B0h] BYREF
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+58h] [rbp-A8h] BYREF
  int v37; // [rsp+60h] [rbp-A0h]
  __int128 pvData; // [rsp+68h] [rbp-98h] BYREF
  __int128 v39; // [rsp+78h] [rbp-88h] BYREF
  unsigned __int16 *v40; // [rsp+88h] [rbp-78h]
  struct _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+90h] [rbp-70h] BYREF
  struct _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+A0h] [rbp-60h] BYREF
  struct _CERT_CHAIN_PARA pChainPara; // [rsp+C0h] [rbp-40h] BYREF
  struct _EVENT_DATA_DESCRIPTOR pCertContext; // [rsp+120h] [rbp+20h] BYREF
  __int64 v45[3]; // [rsp+130h] [rbp+30h] BYREF

  v37 = a3;
  v40 = 0i64;
  v39 = 0i64;
  pPolicyPara = 0i64;
  memset(&pPolicyStatus, 0, sizeof(pPolicyStatus));
  memset_0(&pChainPara, 0, 0x60ui64);
  v5 = *((_QWORD *)a1 + 17);
  v6 = *((_QWORD *)a1 + 10);
  v45[0] = (__int64)"1.3.6.1.5.5.7.3.1";
  pChainContext = 0i64;
  v45[1] = (__int64)"1.3.6.1.4.1.311.10.3.3";
  v7 = 0i64;
  v34 = 0i64;
  v45[2] = (__int64)"2.16.840.1.113730.4.1";
  Ptr = 0i64;
  pCertContext.Ptr = 0i64;
  v9 = v5 & 0x200000000i64;
  v35 = 0;
  v33[0] = 0;
  pvData = 0i64;
  if ( !v6 )
    return (unsigned int)-2146893052;
  (*(void (__fastcall **)(struct CSsl3TlsContext *, __int64 *))(*(_QWORD *)a1 + 224i64))(a1, &v34);
  if ( v34 )
  {
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v34 + 72), 1u);
    v10 = SPLoadCertificate(
            *(unsigned __int8 **)(v34 + 24),
            *(_DWORD *)(v34 + 32),
            (const struct _CERT_CONTEXT **)&pCertContext);
    Ptr = (const CERT_CONTEXT *)pCertContext.Ptr;
    v11 = v10;
    if ( v10 )
    {
      v27 = 42;
      v28 = 550;
    }
    else
    {
      v12 = v34;
      LODWORD(pvData) = *(_DWORD *)(v34 + 344);
      *((_QWORD *)&pvData + 1) = *(_QWORD *)(v34 + 336);
      if ( (_DWORD)pvData )
      {
        if ( !CertSetCertificateContextProperty((PCCERT_CONTEXT)pCertContext.Ptr, 0x46u, 0, &pvData)
          && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        {
          LastError = GetLastError();
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            21i64,
            &WPP_145b996ecad4340088f3534b93eceddb_Traceguids,
            LastError);
        }
        v12 = v34;
      }
      v13 = *(_DWORD *)(v12 + 360);
      v14 = *(_QWORD *)(v12 + 352);
      *((_QWORD *)&pvData + 1) = v14;
      LODWORD(pvData) = v13;
      if ( v13
        && v14
        && !CertSetCertificateContextProperty(Ptr, 0x77u, 0, &pvData)
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      {
        v31 = GetLastError();
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids, v31);
      }
      if ( SslImpersonateClient(*(_QWORD *)(*((_QWORD *)a1 + 10) + 752i64), &v35) )
      {
        v11 = -2146893052;
LABEL_25:
        if ( v34 )
          RtlReleaseResource((PRTL_RESOURCE)(v34 + 72));
        goto LABEL_27;
      }
      pChainPara.cbSize = 96;
      pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = (LPSTR *)v45;
      pChainPara.RequestedUsage.dwType = 1;
      pChainPara.RequestedUsage.Usage.cUsageIdentifier = 3;
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        McGenEventWrite_EventWriteTransfer(v15, &ChainBuildStart, v16, v17, &pCertContext);
      if ( CertGetCertificateChain(0i64, Ptr, 0i64, Ptr->hCertStore, &pChainPara, a2, 0i64, &pChainContext) )
      {
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          McGenEventWrite_EventWriteTransfer(v18, &ChainBuildStop, v19, v20, &pCertContext);
        if ( (*(_BYTE *)(v6 + 156) & 2) == 0 )
        {
          v7 = *(unsigned __int16 **)(v34 + 368);
          if ( !v7 || !lstrlenW(*(LPCWSTR *)(v34 + 368)) )
          {
            v11 = -2146893022;
            v28 = 553;
            v27 = 80;
            v29 = -2146893022;
            goto LABEL_40;
          }
        }
        pPolicyPara.dwFlags = 0;
        v39 = 0x200000018ui64;
        v40 = v7;
        pPolicyPara.cbSize = 16;
        pPolicyPara.pvExtraPolicyPara = &v39;
        pPolicyStatus.cbSize = 24;
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          McGenEventWrite_EventWriteTransfer(v18, &ChainVerifyStart, v19, v20, &pCertContext);
        if ( CertVerifyCertificateChainPolicy((LPCSTR)4, pChainContext, &pPolicyPara, &pPolicyStatus) )
        {
          if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
            McGenEventWrite_EventWriteTransfer(v21, &ChainVerifyStop, v22, v23, &pCertContext);
          v24 = v34;
          dwErrorStatus = pChainContext->TrustStatus.dwErrorStatus;
          *(_DWORD *)(v34 + 216) = pPolicyStatus.dwError;
          *(_DWORD *)(v24 + 220) = dwErrorStatus;
          if ( !v9 && (v11 = I_MapWinTrustErrorAndAlert(pPolicyStatus.dwError, 0, v37, v33)) != 0 )
          {
            v32 = v33[0];
            if ( !v33[0] )
              v32 = 80;
            CSslContext::SetErrorAndFatalAlert((__int64)a1, 552, v11, v32);
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                24i64,
                &WPP_145b996ecad4340088f3534b93eceddb_Traceguids,
                v11);
            }
            LogBogusServerCertEvent(*(_DWORD *)(v6 + 212), (const unsigned __int16 *)(v6 + 216), Ptr, v7, v11);
          }
          else
          {
            v11 = 0;
          }
          goto LABEL_25;
        }
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          McGenEventWrite_EventWriteTransfer(v21, &ChainVerifyStop, v22, v23, &pCertContext);
        v10 = GetLastError();
        v27 = 80;
        v28 = 552;
        v11 = v10;
      }
      else
      {
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          McGenEventWrite_EventWriteTransfer(v18, &ChainBuildStop, v19, v20, &pCertContext);
        v10 = GetLastError();
        v27 = 80;
        v28 = 551;
        v11 = v10;
      }
    }
    v29 = v10;
LABEL_40:
    CSslContext::SetErrorAndFatalAlert((__int64)a1, v28, v29, v27);
    goto LABEL_25;
  }
  v11 = -2146893052;
LABEL_27:
  if ( pChainContext )
    CertFreeCertificateChain(pChainContext);
  if ( Ptr )
    CertFreeCertificateContext(Ptr);
  if ( v35 )
    RevertToSelf();
  return v11;
}
// 18002B828: variable 'v15' is possibly undefined
// 18002B828: variable 'v16' is possibly undefined
// 18002B828: variable 'v17' is possibly undefined
// 18002B87E: variable 'v18' is possibly undefined
// 18002B87E: variable 'v19' is possibly undefined
// 18002B87E: variable 'v20' is possibly undefined
// 18002B8C5: variable 'v21' is possibly undefined
// 18002B8C5: variable 'v22' is possibly undefined
// 18002B8C5: variable 'v23' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C60: using guessed type EVENT_DESCRIPTOR ChainVerifyStop;
// 180084C70: using guessed type EVENT_DESCRIPTOR ChainVerifyStart;
// 180084C80: using guessed type EVENT_DESCRIPTOR ChainBuildStop;
// 180084C90: using guessed type EVENT_DESCRIPTOR ChainBuildStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180001268: using guessed type char var_140[8];

