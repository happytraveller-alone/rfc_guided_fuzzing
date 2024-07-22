//----- (0000000180057D84) ----------------------------------------------------
__int64 __fastcall FindDefaultMachineCred(
        struct CCredentialGroup **a1,
        unsigned int a2,
        struct _LUID *a3,
        void *a4,
        unsigned int a5,
        unsigned __int16 *SourceString)
{
  int v6; // ebx
  PCCERT_CONTEXT v8; // rsi
  HCERTSTORE v9; // r14
  WCHAR *v10; // rdi
  int v11; // r15d
  DWORD LastError; // eax
  __int64 v13; // rdx
  unsigned int v14; // ebx
  WCHAR *v15; // rax
  int v16; // eax
  __int64 v17; // rax
  const CERT_CONTEXT *i; // rdx
  __int64 v19; // rcx
  __int64 v20; // r8
  __int64 v21; // r9
  __int64 v22; // rcx
  __int64 v23; // r8
  __int64 v24; // r9
  DWORD v25; // eax
  char v26; // al
  __int64 v27; // rcx
  __int64 v28; // r8
  __int64 v29; // r9
  unsigned int v30; // eax
  CCipherMill *v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rdx
  void *pvPara; // [rsp+20h] [rbp-258h]
  DWORD nSize; // [rsp+40h] [rbp-238h] BYREF
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+48h] [rbp-230h] BYREF
  unsigned int v38; // [rsp+50h] [rbp-228h]
  void *v39; // [rsp+58h] [rbp-220h]
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-218h] BYREF
  struct _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+70h] [rbp-208h] BYREF
  int v42[4]; // [rsp+80h] [rbp-1F8h] BYREF
  WCHAR *v43; // [rsp+90h] [rbp-1E8h]
  struct _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+98h] [rbp-1E0h] BYREF
  __int128 v45[3]; // [rsp+B0h] [rbp-1C8h] BYREF
  __int64 v46; // [rsp+E0h] [rbp-198h]
  struct _CERT_CHAIN_PARA pChainPara; // [rsp+F0h] [rbp-188h] BYREF
  int v48[2]; // [rsp+150h] [rbp-128h] BYREF
  __int128 *v49; // [rsp+158h] [rbp-120h]
  char v50[96]; // [rsp+160h] [rbp-118h] BYREF
  __int64 v51[3]; // [rsp+1C0h] [rbp-B8h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v52; // [rsp+1D8h] [rbp-A0h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v53; // [rsp+1E8h] [rbp-90h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v54; // [rsp+1F8h] [rbp-80h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v55; // [rsp+208h] [rbp-70h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v56; // [rsp+218h] [rbp-60h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v57; // [rsp+228h] [rbp-50h] BYREF

  v6 = 0;
  v51[0] = (__int64)"1.3.6.1.5.5.7.3.1";
  v39 = a4;
  v51[1] = (__int64)"1.3.6.1.4.1.311.10.3.3";
  *(_QWORD *)&DestinationString.Length = a3;
  v51[2] = (__int64)"2.16.840.1.113730.4.1";
  v8 = 0i64;
  v38 = a2;
  v9 = 0i64;
  pChainContext = 0i64;
  v10 = 0i64;
  v11 = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
  nSize = 0;
  if ( !GetComputerNameExW(ComputerNameDnsFullyQualified, 0i64, &nSize) && GetLastError() != 234 )
  {
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      goto LABEL_10;
    LastError = GetLastError();
    v13 = 26i64;
LABEL_9:
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), v13, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids, LastError);
LABEL_10:
    v14 = -2146893022;
    goto LABEL_82;
  }
  v15 = (WCHAR *)SPExternalAlloc(2 * nSize);
  v10 = v15;
  if ( !v15 )
  {
    v14 = -2146893056;
    goto LABEL_82;
  }
  if ( !GetComputerNameExW(ComputerNameDnsFullyQualified, v15, &nSize) )
  {
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      goto LABEL_10;
    LastError = GetLastError();
    v13 = 27i64;
    goto LABEL_9;
  }
  v16 = lstrlenW(v10);
  nSize = v16;
  if ( v16 )
  {
    v17 = (unsigned int)(v16 - 1);
    if ( v10[v17] == 46 )
      v10[v17] = 0;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_S(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Cu, (__int64)&WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids, v10);
  v9 = CertOpenStore((LPCSTR)0xA, 1u, 0i64, 0x2C000u, L"MY");
  if ( !v9 )
  {
    GetLastError();
    v14 = GetLastError();
    if ( v14 )
      goto LABEL_82;
    goto LABEL_85;
  }
  while ( 2 )
  {
    for ( i = 0i64; ; i = v8 )
    {
      v8 = CertEnumCertificatesInStore(v9, i);
      if ( !v8 )
        break;
      memset_0(&pChainPara, 0, 0x60ui64);
      pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = (LPSTR *)v51;
      pChainPara.cbSize = 96;
      pChainPara.RequestedUsage.dwType = 1;
      pChainPara.RequestedUsage.Usage.cUsageIdentifier = 3;
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        McGenEventWrite_EventWriteTransfer(v19, &ChainBuildStart, v20, v21, &v52);
      if ( !CertGetCertificateChain(0i64, v8, 0i64, 0i64, &pChainPara, 0x90000004, 0i64, &pChainContext) )
      {
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          McGenEventWrite_EventWriteTransfer(v22, &ChainBuildStop, v23, v24, &v53);
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        {
          v25 = GetLastError();
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids, v25);
        }
        continue;
      }
      v26 = Microsoft_Windows_Schannel_EventsEnableBits;
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      {
        McGenEventWrite_EventWriteTransfer(v22, &ChainBuildStop, v23, v24, &v54);
        v26 = Microsoft_Windows_Schannel_EventsEnableBits;
      }
      v42[3] = 0;
      v42[2] = 0;
      v42[0] = 24;
      pPolicyPara.pvExtraPolicyPara = v42;
      v42[1] = 2;
      memset(&pPolicyStatus, 0, sizeof(pPolicyStatus));
      pPolicyStatus.cbSize = 24;
      v43 = v10;
      pPolicyPara.cbSize = 16;
      pPolicyPara.dwFlags = v6 != 0 ? 7 : 0;
      if ( (v26 & 1) != 0 )
        McGenEventWrite_EventWriteTransfer((unsigned int)-v6, &ChainVerifyStart, v23, v24, &v55);
      if ( !CertVerifyCertificateChainPolicy((LPCSTR)4, pChainContext, &pPolicyPara, &pPolicyStatus) )
      {
        if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          McGenEventWrite_EventWriteTransfer(v27, &ChainVerifyStop, v28, v29, &v56);
        GetLastError();
LABEL_49:
        CertFreeCertificateChain(pChainContext);
        continue;
      }
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        McGenEventWrite_EventWriteTransfer(v27, &ChainVerifyStop, v28, v29, &v57);
      v30 = I_MapWinTrustErrorAndAlert(pPolicyStatus.dwError, 0, 6144, 0i64);
      if ( v30 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids, v30);
        goto LABEL_49;
      }
      CertFreeCertificateChain(pChainContext);
      if ( DoesCertHaveBasicConstraintCA(v8) )
      {
        v31 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
          v31 = WPP_GLOBAL_Control;
        }
        v11 = 1;
        if ( v6 )
        {
          if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
          {
            v33 = 33i64;
            goto LABEL_76;
          }
          goto LABEL_77;
        }
        if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
        {
          v32 = 32i64;
LABEL_72:
          WPP_SF_(*((_QWORD *)v31 + 2), v32, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
          continue;
        }
      }
      else
      {
        v31 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
          v31 = WPP_GLOBAL_Control;
        }
        if ( !v6 )
        {
          if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
          {
            v33 = 35i64;
            goto LABEL_76;
          }
          goto LABEL_77;
        }
        if ( v11 != 1 )
        {
          if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
          {
            v33 = 37i64;
LABEL_76:
            WPP_SF_(*((_QWORD *)v31 + 2), v33, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
          }
LABEL_77:
          memset_0(v50, 0, sizeof(v50));
          v49 = v45;
          v46 = 0i64;
          v48[0] = 4;
          v48[1] = 1;
          memset(&v45[1], 0, 32);
          v45[0] = (unsigned __int64)v8;
          if ( !(unsigned int)CSslCredManager::CreateCredentialGroup(
                                CSslCredManager::m_pCredManager,
                                a1,
                                v38,
                                *(struct _LUID **)&DestinationString.Length,
                                v39,
                                (struct LSA_SCHANNEL_CRED *)v48,
                                SourceString) )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 38i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
            }
            v14 = 0;
            goto LABEL_85;
          }
          continue;
        }
        if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 4) != 0 )
        {
          v32 = 36i64;
          goto LABEL_72;
        }
      }
    }
    if ( (unsigned int)++v6 < 2 )
      continue;
    break;
  }
  v14 = -2146893042;
LABEL_82:
  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, SourceString);
    SchEventWrite(&SSLEVENT_NO_DEFAULT_SERVER_CRED, L"du", a5, &DestinationString);
  }
  if ( v10 )
LABEL_85:
    SPExternalFree(v10);
  if ( v8 )
    CertFreeCertificateContext(v8);
  if ( v9 )
    CertCloseStore(v9, 0);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v14 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(pvPara) = v14;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x27u,
      (__int64)&WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
      v14,
      pvPara);
  }
  return v14;
}
// 180058028: variable 'v19' is possibly undefined
// 180058028: variable 'v20' is possibly undefined
// 180058028: variable 'v21' is possibly undefined
// 18005808A: variable 'v22' is possibly undefined
// 18005808A: variable 'v23' is possibly undefined
// 18005808A: variable 'v24' is possibly undefined
// 1800581D7: variable 'v27' is possibly undefined
// 1800581D7: variable 'v28' is possibly undefined
// 1800581D7: variable 'v29' is possibly undefined
// 180058531: variable 'pvPara' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18008275C: using guessed type wchar_t aMy[3];
// 180084C60: using guessed type EVENT_DESCRIPTOR ChainVerifyStop;
// 180084C70: using guessed type EVENT_DESCRIPTOR ChainVerifyStart;
// 180084C80: using guessed type EVENT_DESCRIPTOR ChainBuildStop;
// 180084C90: using guessed type EVENT_DESCRIPTOR ChainBuildStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180057D84: using guessed type char var_118[96];

