//----- (0000000180042D24) ----------------------------------------------------
const struct _CERT_CONTEXT *__fastcall SslGetCertificateByHash(
        unsigned __int8 *a1,
        int a2,
        int a3,
        unsigned __int16 *a4,
        void *a5)
{
  struct _CERT_CONTEXT *v5; // rbx
  CCipherMill *v10; // rcx
  __int64 v11; // rcx
  const char *v12; // r9
  DWORD v13; // edi
  ULONG v14; // eax
  HCERTSTORE v15; // rdi
  DWORD v16; // eax
  const CERT_CONTEXT *CertificateInStore; // rax
  DWORD LastError; // eax
  struct _CERT_CONTEXT *v20; // [rsp+30h] [rbp-48h] BYREF
  int pvFindPara; // [rsp+38h] [rbp-40h] BYREF
  unsigned __int8 *v22; // [rsp+40h] [rbp-38h]
  int v23; // [rsp+90h] [rbp+18h] BYREF

  v23 = 0;
  v5 = 0i64;
  v20 = 0i64;
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
      v10 = WPP_GLOBAL_Control;
    }
    if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v10 + 28) & 4) != 0 )
      {
        WPP_SF_qd(*((_QWORD *)v10 + 2), 0x19u, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, a1, a2);
        v10 = WPP_GLOBAL_Control;
      }
      if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v10 + 28) & 4) != 0 )
        {
          v11 = *((_QWORD *)v10 + 2);
          v12 = "LOCAL_MACHINE";
          if ( !a3 )
            v12 = "CURRENT_USER";
          WPP_SF_s(v11, 0x1Au, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, v12);
          v10 = WPP_GLOBAL_Control;
        }
        if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
        {
          WPP_SF_S(*((_QWORD *)v10 + 2), 0x1Bu, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, a4);
          v10 = WPP_GLOBAL_Control;
        }
      }
    }
  }
  if ( a3 )
  {
    v13 = 537002496;
  }
  else
  {
    v13 = 536936960;
    if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)v10 + 2), 28i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
    v14 = SslImpersonateClient((__int64)a5, &v23);
    v10 = WPP_GLOBAL_Control;
    if ( v14 )
      goto LABEL_39;
  }
  if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)v10 + 2), 29i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
  v15 = CertOpenStore((LPCSTR)0xA, 1u, 0i64, v13, a4);
  if ( v15 )
  {
    pvFindPara = a2;
    v22 = a1;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
    CertificateInStore = CertFindCertificateInStore(v15, 1u, 0, 0x10000u, &pvFindPara, 0i64);
    v5 = (struct _CERT_CONTEXT *)CertificateInStore;
    if ( CertificateInStore )
    {
      if ( (unsigned int)CheckForLocalStoreCertificateRenewal(
                           v15,
                           CertificateInStore,
                           0,
                           (const struct _CERT_CONTEXT **)&v20) )
      {
        CertFreeCertificateContext(v5);
        v5 = v20;
      }
    }
    else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      LastError = GetLastError();
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, LastError);
    }
    CertCloseStore(v15, 0);
    goto LABEL_38;
  }
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    v16 = GetLastError();
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, v16);
LABEL_38:
    v10 = WPP_GLOBAL_Control;
  }
LABEL_39:
  if ( v23 )
  {
    RevertToSelf();
    v10 = WPP_GLOBAL_Control;
  }
  if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
    WPP_SF_q(*((_QWORD *)v10 + 2), 0x21u, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, v5);
  return v5;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

