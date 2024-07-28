//----- (00000001800478D4) ----------------------------------------------------
__int64 __fastcall MapperVerifyClientChain(
        struct CCredentialGroup *a1,
        const struct _CERT_CONTEXT *a2,
        __int64 a3,
        unsigned int a4,
        unsigned int *a5,
        int *a6,
        const struct _CERT_CHAIN_CONTEXT **a7)
{
  int v11; // edx
  int v12; // r8d
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // edx
  unsigned int LastError; // ebx
  _DWORD *v17; // rcx
  __int64 v18; // r8
  __int64 v19; // rcx
  __int64 v20; // r8
  __int64 v21; // r9
  const CERT_CHAIN_CONTEXT *v22; // rcx
  unsigned int v24; // r12d
  __int64 v25; // r9
  const CERT_CHAIN_CONTEXT *v26; // rcx
  DWORD dwFlags; // [rsp+40h] [rbp-91h]
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+48h] [rbp-89h] BYREF
  int v29; // [rsp+50h] [rbp-81h] BYREF
  unsigned int v30; // [rsp+54h] [rbp-7Dh]
  const char *v31; // [rsp+58h] [rbp-79h] BYREF
  struct _CERT_CHAIN_PARA pChainPara; // [rsp+60h] [rbp-71h] BYREF
  int v33; // [rsp+98h] [rbp-39h]
  int v34; // [rsp+9Ch] [rbp-35h]
  int v35; // [rsp+A0h] [rbp-31h]
  char v36[16]; // [rsp+C0h] [rbp-11h] BYREF

  pChainContext = 0i64;
  v29 = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
  *a5 = 0;
  *a6 = 0;
  if ( a7 )
    *a7 = 0i64;
  v11 = (16 * (a4 & 0x1000000)) | 0x20000000;
  if ( (a4 & 0x2000000) == 0 )
    v11 = 16 * (a4 & 0x1000000);
  v12 = v11 | 0x40000000;
  if ( (a4 & 0x4000000) == 0 )
    v12 = v11;
  v13 = HIWORD(a4) & 0x800 | 0x1000;
  if ( (a4 & 0x10000000) == 0 )
    v13 = HIWORD(a4) & 0x800;
  v14 = v12 | 4;
  v30 = v13;
  if ( (a4 & 0x200000) == 0 )
    v14 = v12;
  v15 = v14 | 0x80000000;
  if ( (a4 & 0x400000) == 0 )
    v15 = v14;
  dwFlags = v15;
  LastError = SslImpersonateClient(a3, &v29);
  if ( LastError )
    goto LABEL_30;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x20u,
      (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
      dwFlags,
      a4);
  v31 = "1.3.6.1.5.5.7.3.2";
  memset_0(&pChainPara, 0, 0x60ui64);
  pChainPara.cbSize = 96;
  pChainPara.RequestedUsage.dwType = 1;
  pChainPara.RequestedUsage.Usage.cUsageIdentifier = 1;
  pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = (LPSTR *)&v31;
  if ( a1 )
  {
    v17 = (_DWORD *)*((_QWORD *)a1 + 106);
    if ( v17 )
    {
      v33 = v17[5];
      v34 = v17[6];
      v35 = v17[7];
      if ( v17[8] == 1 )
      {
        pChainPara.RequestedUsage.dwType = 0;
        pChainPara.RequestedUsage.Usage.cUsageIdentifier = 0;
        pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = 0i64;
      }
    }
  }
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EtwEventWriteTransfer((__int64)v17, (__int64)&ChainBuildStart, v18, 1, (__int64)v36);
  if ( CertGetCertificateChain(0i64, a2, 0i64, a2->hCertStore, &pChainPara, dwFlags, 0i64, &pChainContext) )
  {
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EtwEventWriteTransfer(v19, (__int64)&ChainBuildStop, v20, 1, (__int64)v36);
    if ( (a4 & 0x800000) != 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 33i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
      *a5 |= 0x70u;
    }
    else
    {
      v24 = v30;
      LastError = VerifyClientCertificate(pChainContext, (LPCSTR)4, v30, v21);
      if ( LastError )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            34i64,
            &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
            LastError);
        LogBogusClientCertEvent(*((_DWORD *)a1 + 53), (const unsigned __int16 *)a1 + 108, a2, LastError);
      }
      else
      {
        v26 = pChainContext;
        *a5 |= 0x60u;
        LastError = VerifyClientCertificate(v26, (LPCSTR)6, v24, v25);
        if ( !LastError )
        {
          *a5 |= 0x10u;
          goto LABEL_56;
        }
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            35i64,
            &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
            LastError);
        LogFastMappingFailureEvent(*((_DWORD *)a1 + 53), (const unsigned __int16 *)a1 + 108, a2, LastError);
      }
      *a6 = LastError;
    }
    LastError = 0;
    goto LABEL_56;
  }
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EtwEventWriteTransfer(v19, (__int64)&ChainBuildStop, v20, 1, (__int64)v36);
  LastError = GetLastError();
  if ( LastError )
    goto LABEL_30;
LABEL_56:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, *a5);
  if ( !a7 )
  {
LABEL_30:
    v22 = pChainContext;
    goto LABEL_31;
  }
  v22 = 0i64;
  *a7 = pChainContext;
  pChainContext = 0i64;
LABEL_31:
  if ( v22 )
    CertFreeCertificateChain(v22);
  if ( v29 )
    RevertToSelf();
  return LastError;
}
// 180047AB5: variable 'v17' is possibly undefined
// 180047AB5: variable 'v18' is possibly undefined
// 180047B16: variable 'v19' is possibly undefined
// 180047B16: variable 'v20' is possibly undefined
// 180047BF6: variable 'v21' is possibly undefined
// 180047C0F: variable 'v25' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C80: using guessed type EVENT_DESCRIPTOR ChainBuildStop;
// 180084C90: using guessed type EVENT_DESCRIPTOR ChainBuildStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
