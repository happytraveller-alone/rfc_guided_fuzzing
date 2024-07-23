// File count: 1047
// Total lines: 199
---------------------------------------
__int64 __fastcall FindClientCertificate(
        struct CSsl3TlsClientContext *this,
        void *a2,
        const struct _CERT_CHAIN_CONTEXT **a3,
        struct _CERT_CHAIN_FIND_BY_ISSUER_PARA *a4,
        int *a5,
        int a6,
        int a7)
{
  const struct _CERT_CHAIN_CONTEXT *pPrevChainContext; // rdi
  signed int v12; // eax
  int v13; // ebx
  PCCERT_CHAIN_CONTEXT i; // rax
  char *v15; // rdx
  PCERT_SIMPLE_CHAIN *rgpChain; // rcx
  __int64 v17; // rbx
  PCERT_SIMPLE_CHAIN v18; // rsi
  __int64 v19; // r8
  __int64 v20; // r9
  int v21; // eax
  DWORD v22; // eax
  __int64 v23; // rcx
  __int64 v24; // r8
  __int64 v25; // r9
  unsigned int LastError; // eax
  CCipherMill *v27; // rcx
  __int64 v28; // rdx
  PCERT_SIMPLE_CHAIN v29; // rcx
  PCERT_CHAIN_ELEMENT *rgpElement; // rax
  PCERT_CHAIN_ELEMENT v31; // rax
  const struct _CERT_CONTEXT *pCertContext; // rbx
  void *pvFindPara; // [rsp+20h] [rbp-A1h]
  int v35; // [rsp+30h] [rbp-91h] BYREF
  unsigned int v36; // [rsp+34h] [rbp-8Dh] BYREF
  HCERTSTORE hCertStore; // [rsp+38h] [rbp-89h]
  struct _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+40h] [rbp-81h] BYREF
  int v39[4]; // [rsp+50h] [rbp-71h] BYREF
  __int64 v40; // [rsp+60h] [rbp-61h]
  struct _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+68h] [rbp-59h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v42; // [rsp+80h] [rbp-41h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v43; // [rsp+90h] [rbp-31h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v44; // [rsp+A0h] [rbp-21h] BYREF

  hCertStore = a2;
  pPrevChainContext = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
  if ( !a3 || !a5 || !this || !a4 )
  {
    v13 = 1359;
    goto LABEL_53;
  }
  if ( !*a5 )
  {
    v12 = SslImpersonateClient(*(_QWORD *)(*((_QWORD *)this + 10) + 752i64), a5);
    v13 = v12;
    if ( v12 )
    {
      if ( v12 < 0 )
        goto LABEL_50;
      goto LABEL_53;
    }
  }
  for ( i = CertFindChainInStore(a2, 1u, 0, 1u, a4, *a3);
        ;
        i = CertFindChainInStore(hCertStore, 1u, 0, 1u, a4, pPrevChainContext) )
  {
    pPrevChainContext = i;
    if ( !i )
    {
      v13 = -2146893024;
      goto LABEL_53;
    }
    rgpChain = i->rgpChain;
    v17 = 0i64;
    v35 = 0;
    v18 = *rgpChain;
    if ( !(*rgpChain)->cElement )
      continue;
    while ( !(unsigned int)SPCheckKeyUsage(v18->rgpElement[v17]->pCertContext, v15, 1, &v35) )
    {
      v21 = v35;
      if ( !v35 )
        break;
      v17 = (unsigned int)(v17 + 1);
      if ( (unsigned int)v17 >= v18->cElement )
        goto LABEL_19;
    }
    v21 = 0;
LABEL_19:
    if ( !v21 )
      continue;
    v39[3] = 0;
    v39[2] = 0;
    v40 = 0i64;
    pPolicyPara.pvExtraPolicyPara = v39;
    v22 = 48;
    memset(&pPolicyStatus, 0, sizeof(pPolicyStatus));
    v39[0] = 24;
    pPolicyStatus.cbSize = 24;
    if ( !a6 )
      v22 = 55;
    v39[1] = 1;
    pPolicyPara.dwFlags = v22;
    pPolicyPara.cbSize = 16;
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(55i64, &ChainVerifyStart, v19, v20, &v42);
    if ( !CertVerifyCertificateChainPolicy((LPCSTR)4, pPrevChainContext, &pPolicyPara, &pPolicyStatus) )
    {
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        McGenEventWrite_EventWriteTransfer(v23, &ChainVerifyStop, v24, v25, &v43);
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
      {
        LastError = GetLastError();
        v27 = WPP_GLOBAL_Control;
        v28 = 17i64;
LABEL_36:
        WPP_SF_D(*((_QWORD *)v27 + 2), v28, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids, LastError);
        continue;
      }
      continue;
    }
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EventWriteTransfer(v23, &ChainVerifyStop, v24, v25, &v44);
    LastError = I_MapWinTrustErrorAndAlert(pPolicyStatus.dwError, 0, 0, 0i64);
    if ( !LastError )
      break;
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    {
      v28 = 18i64;
      goto LABEL_36;
    }
LABEL_46:
    ;
  }
  if ( pPrevChainContext->cChain )
  {
    v29 = *pPrevChainContext->rgpChain;
    if ( v29 )
    {
      if ( v29->cElement )
      {
        rgpElement = v29->rgpElement;
        if ( rgpElement )
        {
          v31 = *rgpElement;
          pCertContext = v31->pCertContext;
          if ( !a7 || (GetImplementationType(v31->pCertContext, &v36), v36 == 2) )
          {
            if ( *a5 == 1 )
            {
              RevertToSelf();
              *a5 = 0;
            }
            v13 = AssignNewClientCredential(this, pCertContext);
            if ( v13 >= 0 )
              goto LABEL_53;
          }
          goto LABEL_46;
        }
      }
    }
  }
  v13 = -2146893052;
LABEL_50:
  if ( pPrevChainContext )
  {
    CertFreeCertificateChain(pPrevChainContext);
    pPrevChainContext = 0i64;
  }
LABEL_53:
  *a3 = pPrevChainContext;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v13 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(pvFindPara) = v13;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x13u,
      (__int64)&WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
      v13,
      pvFindPara);
  }
  return (unsigned int)v13;
}
// 180057ACD: variable 'v15' is possibly undefined
// 180057B56: variable 'v19' is possibly undefined
// 180057B56: variable 'v20' is possibly undefined
// 180057B95: variable 'v23' is possibly undefined
// 180057B95: variable 'v24' is possibly undefined
// 180057B95: variable 'v25' is possibly undefined
// 180057D54: variable 'pvFindPara' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C60: using guessed type EVENT_DESCRIPTOR ChainVerifyStop;
// 180084C70: using guessed type EVENT_DESCRIPTOR ChainVerifyStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
