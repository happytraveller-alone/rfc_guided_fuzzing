//----- (0000000180042244) ----------------------------------------------------
__int64 __fastcall LoadImplicitCredentials(struct _UNICODE_STRING *a1, __int64 a2, struct LSA_SCHANNEL_CRED *a3)
{
  void *v5; // r12
  void *v6; // r13
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned int CertificatesFromLocator; // eax
  __int64 v11; // rcx
  __int64 v12; // r8
  CCipherMill *v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // r8
  __int64 v17; // r9
  __int64 v18; // r8
  void *v19; // rcx
  void *v20; // rax
  __int64 v21; // r8
  __int64 v22; // rcx
  DWORD LastError; // eax
  void *Content; // rax
  __int64 v25; // rcx
  __int64 v26; // r8
  struct LSA_SCHANNEL_CRED *v27; // r15
  __int64 v28; // [rsp+20h] [rbp-78h]
  int v29; // [rsp+30h] [rbp-68h] BYREF
  struct _CRYPTOAPI_BLOB v30; // [rsp+38h] [rbp-60h] BYREF
  struct LSA_SCHANNEL_CRED *v31; // [rsp+48h] [rbp-50h]
  char v32[16]; // [rsp+50h] [rbp-48h] BYREF

  v31 = a3;
  v5 = 0i64;
  v6 = 0i64;
  v29 = 0;
  v30 = 0i64;
  if ( a1->Length )
  {
    if ( !CSslGlobals::m_hCertLocator )
    {
      v8 = CSslGlobals::InitializeCryptLocatorHandles();
      v9 = v8;
      if ( v8 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 38i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, v8);
        return v9;
      }
    }
    CertificatesFromLocator = SslImpersonateClient(a2, &v29);
    v9 = CertificatesFromLocator;
    if ( CertificatesFromLocator )
    {
      v13 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_47;
      v14 = 39i64;
    }
    else
    {
      v30.cbData = a1->Length;
      v30.pbData = (BYTE *)a1->Buffer;
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        McGenEventWrite_EtwEventWriteTransfer(v11, (__int64)&LocatorGetStart, v12, 1, (__int64)v32);
      v5 = CryptObjectLocatorGet(CSslGlobals::m_hCertLocator, 1u, &v30);
      if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
        McGenEventWrite_EtwEventWriteTransfer(v15, (__int64)&LocatorGetStop, v16, 1, (__int64)v32);
      if ( v5 )
      {
        CertificatesFromLocator = LoadCertificatesFromLocator(v5, v31, v16, v17);
        v9 = CertificatesFromLocator;
        if ( CertificatesFromLocator )
        {
          v13 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_47;
          }
          v14 = 41i64;
        }
        else
        {
          v19 = CSslGlobals::m_hIssuersLocator;
          v5 = 0i64;
          if ( !CSslGlobals::m_hIssuersLocator )
            goto LABEL_46;
          v30.cbData = a1->Length;
          v30.pbData = (BYTE *)a1->Buffer;
          if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          {
            McGenEventWrite_EtwEventWriteTransfer(
              (__int64)CSslGlobals::m_hIssuersLocator,
              (__int64)&LocatorGetStart,
              v18,
              1,
              (__int64)v32);
            v19 = CSslGlobals::m_hIssuersLocator;
          }
          v20 = CryptObjectLocatorGet(v19, 1u, &v30);
          v22 = (unsigned int)Microsoft_Windows_Schannel_EventsEnableBits;
          v6 = v20;
          if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
          {
            McGenEventWrite_EtwEventWriteTransfer(
              (unsigned int)Microsoft_Windows_Schannel_EventsEnableBits,
              (__int64)&LocatorGetStop,
              v21,
              1,
              (__int64)v32);
            v22 = (unsigned int)Microsoft_Windows_Schannel_EventsEnableBits;
          }
          if ( !v6 )
          {
            LastError = GetLastError();
            v13 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                42i64,
                &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                LastError);
              v13 = WPP_GLOBAL_Control;
            }
            v9 = 0;
            goto LABEL_47;
          }
          if ( (v22 & 1) != 0 )
            McGenEventWrite_EtwEventWriteTransfer(v22, (__int64)&LocatorGetContentStart, v21, 1, (__int64)v32);
          Content = CryptObjectLocatorGetContent(v6);
          v27 = v31;
          *((_QWORD *)v31 + 6) = Content;
          if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
            McGenEventWrite_EtwEventWriteTransfer(v25, (__int64)&LocatorGetContentStop, v26, 1, (__int64)v32);
          if ( *((_QWORD *)v27 + 6) )
            goto LABEL_46;
          CertificatesFromLocator = GetLastError();
          v9 = CertificatesFromLocator;
          v13 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_47;
          }
          v14 = 43i64;
        }
      }
      else
      {
        CertificatesFromLocator = GetLastError();
        v9 = CertificatesFromLocator;
        v13 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_47;
        v14 = 40i64;
      }
    }
    WPP_SF_D(*((_QWORD *)v13 + 2), v14, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, CertificatesFromLocator);
LABEL_46:
    v13 = WPP_GLOBAL_Control;
LABEL_47:
    if ( v29 )
    {
      RevertToSelf();
      v13 = WPP_GLOBAL_Control;
    }
    if ( v5 )
    {
      CryptObjectLocatorFree(v5);
      v13 = WPP_GLOBAL_Control;
    }
    if ( v6 )
    {
      CryptObjectLocatorFree(v6);
      v13 = WPP_GLOBAL_Control;
    }
    if ( v13 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v13 + 28) & 0x20) != 0 )
    {
      LODWORD(v28) = v9;
      WPP_SF_DD(*((_QWORD *)v13 + 2), 0x2Cu, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, v9, v28);
    }
    return v9;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
  return 2148074253i64;
}
// 180042387: variable 'v11' is possibly undefined
// 180042387: variable 'v12' is possibly undefined
// 1800423C5: variable 'v15' is possibly undefined
// 1800423C5: variable 'v16' is possibly undefined
// 180042408: variable 'v17' is possibly undefined
// 180042476: variable 'v18' is possibly undefined
// 1800424B6: variable 'v21' is possibly undefined
// 18004255A: variable 'v25' is possibly undefined
// 18004255A: variable 'v26' is possibly undefined
// 180042615: variable 'v28' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180084C20: using guessed type EVENT_DESCRIPTOR LocatorGetContentStop;
// 180084C30: using guessed type EVENT_DESCRIPTOR LocatorGetContentStart;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 180092F60: using guessed type void *CSslGlobals::m_hIssuersLocator;
// 180092F68: using guessed type void *CSslGlobals::m_hCertLocator;
// 180098018: using guessed type void __stdcall CryptObjectLocatorFree(void *);
// 1800980D8: using guessed type void *__stdcall CryptObjectLocatorGet(void *, unsigned int, struct _CRYPTOAPI_BLOB *);
// 180098168: using guessed type void *__stdcall CryptObjectLocatorGetContent(void *);
