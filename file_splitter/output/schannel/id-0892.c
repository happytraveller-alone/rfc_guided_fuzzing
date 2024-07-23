// File count: 892
// Total lines: 242
----------------------------------------
__int64 __fastcall SslRemoteMapCredential(
        struct CCredentialGroup *a1,
        void *a2,
        int a3,
        __int64 a4,
        unsigned int a5,
        struct _CERT_CONTEXT *a6,
        void *a7,
        unsigned __int16 *a8,
        unsigned __int16 *a9,
        unsigned __int64 *a10)
{
  __int64 result; // rax
  PCCERT_CHAIN_CONTEXT v14; // rdi
  CCipherMill *v15; // rcx
  const wchar_t *v16; // rbx
  int v17; // ebx
  CCipherMill *v18; // rcx
  __int64 v19; // rdx
  CCipherMill *v20; // rcx
  __int64 v21; // rdx
  int v22; // edi
  PCCERT_CHAIN_CONTEXT v23; // rdi
  PCERT_SIMPLE_CHAIN *rgpChain; // rcx
  int v25; // eax
  HLOCAL hMem; // [rsp+50h] [rbp-30h] BYREF
  unsigned __int8 *v27; // [rsp+58h] [rbp-28h] BYREF
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+60h] [rbp-20h] BYREF
  struct _LUID v29; // [rsp+68h] [rbp-18h] BYREF
  struct _UNICODE_STRING v30; // [rsp+70h] [rbp-10h] BYREF
  int v31; // [rsp+B8h] [rbp+38h] BYREF
  int v32; // [rsp+BCh] [rbp+3Ch]
  unsigned int v33; // [rsp+C0h] [rbp+40h] BYREF

  v32 = HIDWORD(a2);
  v31 = 0;
  v29 = 0i64;
  pChainContext = 0i64;
  hMem = 0i64;
  v27 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_q(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x4Bu,
      (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
      0i64);
  if ( a3 != 1 )
    return 2148074253i64;
  result = MapperVerifyClientChain(a1, a6, a4, a5, &v33, &v31, &pChainContext);
  if ( !(_DWORD)result )
  {
    v14 = pChainContext;
    if ( (v33 & 0x10) != 0 )
    {
      if ( (g_dwCertMappingMethods & 8) != 0 )
      {
        v15 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 76i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
          v15 = WPP_GLOBAL_Control;
        }
        v16 = a9;
        if ( a1 && v15 != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)v15 + 28) & 4) != 0 )
          {
            WPP_SF_S(*((_QWORD *)v15 + 2), 0x4Du, (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, a8);
            v15 = WPP_GLOBAL_Control;
          }
          if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
            WPP_SF_S(*((_QWORD *)v15 + 2), 0x4Eu, (__int64)&WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v16);
        }
        v17 = SslTryS4U2Self(v14, &a7, 0, a8, v16);
        if ( v17 >= 0 )
        {
          v18 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
          {
            goto LABEL_24;
          }
          v19 = 79i64;
LABEL_23:
          WPP_SF_(*((_QWORD *)v18 + 2), v19, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
LABEL_24:
          CertFreeCertificateChain(v14);
          *a10 = (unsigned __int64)a7;
          return (unsigned int)v17;
        }
        v20 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          v21 = 80i64;
LABEL_39:
          WPP_SF_D(*((_QWORD *)v20 + 2), v21, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, (unsigned int)v17);
          goto LABEL_40;
        }
        goto LABEL_41;
      }
    }
    else if ( (v33 & 0x60) != 0 && (g_dwCertMappingMethods & 0x10) != 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 81i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
      }
      v17 = SslTryS4U2Self(v14, &a7, 4, a8, a9);
      if ( v17 >= 0 )
      {
        v18 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
          || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
        {
          goto LABEL_24;
        }
        v19 = 82i64;
        goto LABEL_23;
      }
      v20 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        v21 = 83i64;
        goto LABEL_39;
      }
LABEL_41:
      if ( v33 )
      {
        CSchannelTelemetryContext::LogRCMPUsage(2);
        v17 = SslBuildCertLogonRequest(v14, v33, (struct _SSL_CERT_LOGON_REQ **)&hMem, (unsigned int *)&a6);
        CertFreeCertificateChain(v14);
        if ( v17 >= 0 )
        {
          v17 = SslMapCertAtDC(
                  &SslDomainName,
                  hMem,
                  (unsigned int)a6,
                  0,
                  0,
                  &v27,
                  &v33,
                  (struct _MSV1_0_PASSTHROUGH_RESPONSE **)&pChainContext);
          LocalFree(hMem);
          if ( v17 >= 0 )
          {
            v23 = pChainContext;
            rgpChain = pChainContext->rgpChain;
            if ( (unsigned int)(*((_DWORD *)rgpChain + 1) - *((_DWORD *)rgpChain + 3)) <= 0x20
              || *((_DWORD *)rgpChain + 6) >= 0x10000u )
            {
              v30 = SslDomainName;
            }
            else
            {
              v30.Length = *((_WORD *)rgpChain + 12);
              v30.MaximumLength = v30.Length;
              v30.Buffer = (PWSTR)((char *)rgpChain + *((unsigned int *)rgpChain + 5));
            }
            v25 = SslCreateTokenFromPac(v27, v33, &v30, &v29, &a7);
            v17 = v25;
            if ( v25 < 0 )
            {
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
              {
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  87i64,
                  &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                  (unsigned int)v25);
              }
              LogCertMappingFailureEvent(*((_DWORD *)a1 + 53), (const unsigned __int16 *)a1 + 108, v17);
            }
            else
            {
              *a10 = (unsigned __int64)a7;
            }
            (*(void (__fastcall **)(PCCERT_CHAIN_CONTEXT))(LsaTable + 184))(v23);
            (*(void (__fastcall **)(unsigned __int8 *))(LsaTable + 48))(v27);
          }
          else
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                86i64,
                &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                (unsigned int)v17);
            }
            v22 = v31;
            (*(void (__fastcall **)(_QWORD, _QWORD, void *, void *, _QWORD, _QWORD, int, struct _TOKEN_SOURCE *, struct _LUID *))(LsaTable + 168))(
              (unsigned int)v17,
              (unsigned int)v31,
              &SslNullString,
              &SslNullString,
              0i64,
              0i64,
              3,
              &SslTokenSource,
              &v29);
            LogCertMappingFailureEvent(*((_DWORD *)a1 + 53), (const unsigned __int16 *)a1 + 108, v17);
            if ( v22 < 0 && (v17 & 0x1FFF0000) != 589824 )
              return (unsigned int)v22;
          }
        }
        else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
               && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            85i64,
            &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
            (unsigned int)v17);
        }
      }
      else
      {
        if ( v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v20 + 7) & 0x100) != 0 )
          WPP_SF_(*((_QWORD *)v20 + 2), 84i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
        v17 = -2146893017;
        if ( v31 < 0 )
          v17 = v31;
        CertFreeCertificateChain(v14);
      }
      return (unsigned int)v17;
    }
LABEL_40:
    v20 = WPP_GLOBAL_Control;
    goto LABEL_41;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
