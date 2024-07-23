// File count: 888
// Total lines: 223
----------------------------------------
__int64 __fastcall SslMapCertToUserPac(
        struct _SSL_CERT_LOGON_REQ *a1,
        unsigned int a2,
        unsigned __int8 **a3,
        unsigned int *a4,
        unsigned __int16 **a5)
{
  unsigned __int64 v7; // rbp
  unsigned int v9; // ebx
  int v10; // r12d
  __int64 v11; // rcx
  DWORD v12; // r8d
  PCCERT_CONTEXT CertificateContext; // r15
  int v14; // eax
  CCipherMill *v15; // rcx
  __int64 v16; // rdx
  CCipherMill *v17; // r10
  int v18; // edx
  int v19; // eax
  __int16 v20; // cx
  int v21; // eax
  __int64 v22; // rsi
  __int64 v23; // rcx
  unsigned int v24; // edx
  int v25; // eax
  int v26; // eax

  v7 = a2;
  v9 = -1073741715;
  v10 = -1073741275;
  *a5 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
  if ( (unsigned int)(v7 - 32) > 0xFFE0 )
    return 3221225485i64;
  if ( *((_DWORD *)a1 + 1) > (unsigned int)v7 )
    return 3221225485i64;
  v11 = *((unsigned int *)a1 + 2);
  if ( (unsigned int)v11 > (unsigned int)v7 )
    return 3221225485i64;
  v12 = *((_DWORD *)a1 + 3);
  if ( v12 > 0x10000 || v12 + (unsigned int)v11 > (unsigned int)v7 )
    return 3221225485i64;
  CertificateContext = CertCreateCertificateContext(1u, (const BYTE *)a1 + v11, v12);
  if ( CertificateContext )
  {
    if ( (*((_BYTE *)a1 + 16) & 0x10) != 0 && (g_dwCertMappingMethods & 4) != 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
      }
      v14 = SslTryUpn(CertificateContext, a3, a4, a5);
      v9 = v14;
      if ( v14 >= 0 || *a5 )
      {
        v20 = 16;
        goto LABEL_37;
      }
      if ( v14 == -1073740943 )
      {
        v15 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
          || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
        {
          goto LABEL_77;
        }
        v16 = 21i64;
        goto LABEL_21;
      }
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
        || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
      {
LABEL_26:
        v18 = *((_DWORD *)a1 + 4);
        if ( (v18 & 0x20) != 0 && (g_dwCertMappingMethods & 1) != 0 )
        {
          if ( v17 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v17 + 7) & 0x100) != 0 )
            WPP_SF_(*((_QWORD *)v17 + 2), 23i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
          v19 = SslTryCompoundName(CertificateContext, a3, a4, a5);
          v9 = v19;
          if ( v19 >= 0 || *a5 )
          {
            v20 = 8;
            goto LABEL_37;
          }
          if ( v19 == -1073740943 )
          {
            v15 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
            {
              goto LABEL_77;
            }
            v16 = 24i64;
            goto LABEL_21;
          }
          v17 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
          {
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              25i64,
              &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
              (unsigned int)v19);
            v17 = WPP_GLOBAL_Control;
          }
          v18 = *((_DWORD *)a1 + 4);
          v10 = v9;
        }
        if ( (v18 & 0x40) == 0 || (g_dwCertMappingMethods & 2) == 0 )
          goto LABEL_62;
        if ( v17 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v17 + 7) & 0x100) != 0 )
        {
          WPP_SF_(*((_QWORD *)v17 + 2), 26i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
          v18 = *((_DWORD *)a1 + 4);
        }
        if ( (v18 & 0x80u) != 0 )
        {
          v21 = *((_DWORD *)a1 + 5);
          if ( v21 )
          {
            if ( 8 * (unsigned __int64)(unsigned int)(v21 - 1) + 32 > v7 )
            {
              v9 = -1073741811;
              goto LABEL_77;
            }
            v22 = 0i64;
            while ( 1 )
            {
              v23 = *((unsigned int *)a1 + 2 * v22 + 6);
              v24 = *((_DWORD *)a1 + 2 * v22 + 7);
              if ( (unsigned int)v23 > (unsigned int)v7 || v24 > 0x10000 || v24 + (unsigned int)v23 > (unsigned int)v7 )
                return 3221225485i64;
              v25 = SslTryIssuer((unsigned __int8 *)a1 + v23, v24, a3, a4, a5);
              v9 = v25;
              if ( v25 >= 0 || *a5 )
                goto LABEL_69;
              if ( v25 == -1073740943 )
              {
                v15 = WPP_GLOBAL_Control;
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
                {
                  v16 = 27i64;
                  goto LABEL_21;
                }
                goto LABEL_77;
              }
              v22 = (unsigned int)(v22 + 1);
              if ( (unsigned int)v22 >= *((_DWORD *)a1 + 5) )
                goto LABEL_59;
            }
          }
        }
        v26 = SslTryIssuer(
                CertificateContext->pCertInfo->Issuer.pbData,
                CertificateContext->pCertInfo->Issuer.cbData,
                a3,
                a4,
                a5);
        v9 = v26;
        if ( v26 < 0 && !*a5 )
        {
          if ( v26 == -1073740943 )
          {
            v15 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
            {
              goto LABEL_77;
            }
            v16 = 28i64;
LABEL_21:
            WPP_SF_D(*((_QWORD *)v15 + 2), v16, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, 3221226353i64);
LABEL_77:
            CertFreeCertificateContext(CertificateContext);
            goto LABEL_78;
          }
LABEL_59:
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v9);
          }
LABEL_62:
          if ( v9 == -1073741771 || v10 == -1073741771 )
          {
            v9 = -2146892985;
          }
          else if ( v9 != -1073741801 )
          {
            v9 = -1073741715;
          }
          goto LABEL_77;
        }
LABEL_69:
        v20 = 4;
LABEL_37:
        CSchannelTelemetryContext::LogRCMPUsage(v20);
        goto LABEL_77;
      }
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        22i64,
        &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
        (unsigned int)v14);
    }
    v17 = WPP_GLOBAL_Control;
    goto LABEL_26;
  }
  v9 = -1073741801;
LABEL_78:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v9);
  return v9;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
