//----- (0000000180048DD8) ----------------------------------------------------
__int64 __fastcall SslLocalMapCredential(
        struct CCredentialGroup *a1,
        __int64 a2,
        int a3,
        __int64 a4,
        unsigned int a5,
        struct _CERT_CONTEXT *a6,
        struct _LUID a7,
        unsigned __int16 *a8,
        unsigned __int16 *a9,
        unsigned __int64 *a10)
{
  struct _MSV1_0_PASSTHROUGH_RESPONSE *v10; // r13
  unsigned __int8 *v11; // r14
  unsigned __int8 *v12; // r12
  __int64 result; // rax
  int v14; // esi
  PCCERT_CHAIN_CONTEXT v15; // rdi
  int v16; // ebx
  CCipherMill *v17; // rcx
  __int64 v18; // rdx
  CCipherMill *v19; // rcx
  __int64 v20; // rdx
  unsigned int *v21; // r15
  int v22; // eax
  CCipherMill *v23; // rcx
  const WCHAR *v24; // rsi
  int v25; // edi
  int v26; // eax
  PUCHAR ValidationData; // rcx
  int v28; // esi
  unsigned __int8 *v29; // [rsp+48h] [rbp-59h] BYREF
  void *v30; // [rsp+50h] [rbp-51h] BYREF
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+58h] [rbp-49h] BYREF
  unsigned int v32; // [rsp+60h] [rbp-41h] BYREF
  unsigned __int8 *v33; // [rsp+68h] [rbp-39h] BYREF
  struct _UNICODE_STRING v34; // [rsp+70h] [rbp-31h] BYREF
  HLOCAL hMem; // [rsp+80h] [rbp-21h] BYREF
  struct _MSV1_0_PASSTHROUGH_RESPONSE *v36; // [rsp+88h] [rbp-19h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+90h] [rbp-11h] BYREF
  __int64 v39; // [rsp+F0h] [rbp+4Fh] BYREF
  int v40; // [rsp+F8h] [rbp+57h] BYREF

  v39 = a2;
  v36 = 0i64;
  hMem = 0i64;
  v10 = 0i64;
  a7.LowPart = 0;
  v11 = 0i64;
  v29 = 0i64;
  v12 = 0i64;
  v33 = 0i64;
  v40 = 0;
  pChainContext = 0i64;
  v34 = 0i64;
  if ( a3 != 1 )
    return 2148074253i64;
  result = MapperVerifyClientChain(a1, a6, a4, a5, &v32, &v40, &pChainContext);
  if ( !(_DWORD)result )
  {
    v14 = v32;
    v15 = pChainContext;
    if ( (v32 & 0x10) != 0 )
    {
      if ( (g_dwCertMappingMethods & 8) != 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
        }
        v16 = SslTryS4U2Self(v15, &v30, 0, a8, a9);
        if ( v16 >= 0 )
        {
          v17 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
          {
            goto LABEL_14;
          }
          v18 = 38i64;
LABEL_13:
          WPP_SF_(*((_QWORD *)v17 + 2), v18, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
LABEL_14:
          CertFreeCertificateChain(v15);
          *a10 = (unsigned __int64)v30;
          return (unsigned int)v16;
        }
        v19 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          v20 = 39i64;
LABEL_29:
          WPP_SF_D(*((_QWORD *)v19 + 2), v20, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, (unsigned int)v16);
          goto LABEL_30;
        }
        goto LABEL_31;
      }
    }
    else if ( (v32 & 0x60) != 0 && (g_dwCertMappingMethods & 0x10) != 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
      }
      v16 = SslTryS4U2Self(v15, &v30, 4, a8, a9);
      if ( v16 >= 0 )
      {
        v17 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
          || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
        {
          goto LABEL_14;
        }
        v18 = 41i64;
        goto LABEL_13;
      }
      v19 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        v20 = 42i64;
        goto LABEL_29;
      }
LABEL_31:
      if ( !v14 )
      {
        if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v19 + 7) & 0x100) != 0 )
          WPP_SF_(*((_QWORD *)v19 + 2), 43i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
        v16 = -2146893017;
        if ( v40 < 0 )
          v16 = v40;
        CertFreeCertificateChain(v15);
        return (unsigned int)v16;
      }
      v16 = SslBuildCertLogonRequest(v15, v14, (struct _SSL_CERT_LOGON_REQ **)&hMem, (unsigned int *)&a7);
      CertFreeCertificateChain(v15);
      if ( v16 < 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            44i64,
            &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
            (unsigned int)v16);
        }
        return (unsigned int)v16;
      }
      CSchannelTelemetryContext::LogRCMPUsage(1);
      v21 = (unsigned int *)hMem;
      v22 = SslMapCertToUserPac(
              (struct _SSL_CERT_LOGON_REQ *)hMem,
              a7.LowPart,
              &v29,
              (unsigned int *)&v39,
              (unsigned __int16 **)&pChainContext);
      v23 = WPP_GLOBAL_Control;
      v16 = v22;
      if ( v22 < 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            45i64,
            &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
            (unsigned int)v22);
          v23 = WPP_GLOBAL_Control;
        }
        v24 = (const WCHAR *)pChainContext;
        if ( pChainContext || v16 == -1073740943 )
        {
          v25 = 0;
          if ( v23 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v23 + 7) & 0x100) != 0 )
            WPP_SF_(*((_QWORD *)v23 + 2), 46i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
          if ( v16 == -1073740943 )
          {
            v25 = 1;
            DestinationString = SslDomainName;
          }
          else
          {
            RtlInitUnicodeString(&DestinationString, v24);
          }
          v26 = SslMapCertAtDC(&DestinationString, v21, v21[1], 1, v25, &v29, (unsigned int *)&v39, &v36);
          v10 = v36;
          v16 = v26;
          if ( v26 < 0 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                47i64,
                &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                (unsigned int)v26);
            }
          }
          else
          {
            ValidationData = v36->ValidationData;
            v12 = v29;
            if ( (unsigned int)(*((_DWORD *)ValidationData + 1) - *((_DWORD *)ValidationData + 3)) <= 0x20
              || *((_DWORD *)ValidationData + 6) >= 0x10000u )
            {
              v34 = SslDomainName;
            }
            else
            {
              v34.Length = *((_WORD *)ValidationData + 12);
              v34.MaximumLength = v34.Length;
              v34.Buffer = (PWSTR)&ValidationData[*((unsigned int *)ValidationData + 5)];
            }
          }
          (*(void (__fastcall **)(const WCHAR *))(LsaTable + 48))(v24);
          v23 = WPP_GLOBAL_Control;
LABEL_65:
          if ( v16 >= 0 )
          {
            v16 = (*(__int64 (__fastcall **)(unsigned __int8 *, _QWORD, _QWORD, unsigned __int8 **, struct _CERT_CONTEXT **))(LsaTable + 376))(
                    v29,
                    (unsigned int)v39,
                    0i64,
                    &v33,
                    &a6);
            if ( v16 >= 0 )
            {
              v29 = v33;
              v28 = 0;
              LODWORD(v39) = (_DWORD)a6;
              v16 = SslCreateTokenFromPac(v33, (unsigned int)a6, &v34, &a7, &v30);
              if ( v16 < 0 )
              {
                v23 = WPP_GLOBAL_Control;
                if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
                  || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
                {
                  goto LABEL_77;
                }
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  49i64,
                  &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                  (unsigned int)v16);
              }
              else
              {
                *a10 = (unsigned __int64)v30;
              }
              v23 = WPP_GLOBAL_Control;
LABEL_77:
              if ( v21 )
              {
                LocalFree(v21);
                v23 = WPP_GLOBAL_Control;
              }
              if ( v10 )
              {
                (*(void (__fastcall **)(struct _MSV1_0_PASSTHROUGH_RESPONSE *))(LsaTable + 184))(v10);
                v23 = WPP_GLOBAL_Control;
              }
              if ( v11 )
              {
                (*(void (__fastcall **)(unsigned __int8 *))(LsaTable + 48))(v11);
                v23 = WPP_GLOBAL_Control;
              }
              if ( v12 )
              {
                (*(void (__fastcall **)(unsigned __int8 *))(LsaTable + 48))(v12);
                v23 = WPP_GLOBAL_Control;
              }
              if ( v33 )
              {
                (*(void (__fastcall **)(unsigned __int8 *))(LsaTable + 48))(v33);
                v23 = WPP_GLOBAL_Control;
              }
              if ( v16 < 0 )
              {
                if ( v23 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v23 + 28) & 2) != 0 )
                  WPP_SF_D(
                    *((_QWORD *)v23 + 2),
                    50i64,
                    &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                    (unsigned int)v16);
                LogCertMappingFailureEvent(*((_DWORD *)a1 + 53), (const unsigned __int16 *)a1 + 108, v16);
                if ( v28 < 0 && (v16 & 0x1FFF0000) != 589824 )
                  return (unsigned int)v28;
              }
              return (unsigned int)v16;
            }
            v23 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                48i64,
                &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
                (unsigned int)v16);
              v23 = WPP_GLOBAL_Control;
            }
          }
          v28 = v40;
          goto LABEL_77;
        }
      }
      else
      {
        v11 = v29;
      }
      v34 = SslDomainName;
      goto LABEL_65;
    }
LABEL_30:
    v19 = WPP_GLOBAL_Control;
    goto LABEL_31;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
