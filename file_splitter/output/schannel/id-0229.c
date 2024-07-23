// File count: 229
// Total lines: 106
----------------------------------------
__int64 __fastcall CSsl3TlsContext::QueryRemoteCertificateChain(CSsl3TlsContext *this, PCCERT_CONTEXT *a2)
{
  __int64 v3; // rcx
  __int64 v5; // rcx
  unsigned __int8 *v6; // rbx
  DWORD v7; // edi
  DWORD v8; // edi
  unsigned int v9; // eax
  CCipherMill *v11; // rcx
  __int64 v12; // rdx
  __int64 v13; // r9
  DWORD LastError; // eax
  DWORD v15; // eax
  __int64 v16; // [rsp+20h] [rbp-20h] BYREF
  __int64 v17; // [rsp+28h] [rbp-18h] BYREF
  int pvData; // [rsp+30h] [rbp-10h] BYREF
  __int64 v19; // [rsp+38h] [rbp-8h]
  int v20; // [rsp+70h] [rbp+30h] BYREF
  int v21; // [rsp+80h] [rbp+40h] BYREF
  PCCERT_CONTEXT pCertContext; // [rsp+88h] [rbp+48h] BYREF

  v16 = 0i64;
  v3 = *((_QWORD *)this + 11);
  v17 = 0i64;
  v20 = 0;
  v21 = 0;
  pCertContext = 0i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)(v3 + 72), 1u);
  v5 = *((_QWORD *)this + 11);
  v6 = *(unsigned __int8 **)(v5 + 24);
  v7 = *(_DWORD *)(v5 + 32);
  if ( v6 )
  {
    (*(void (__fastcall **)(CSsl3TlsContext *, __int64 *, int *))(*(_QWORD *)this + 272i64))(this, &v16, &v20);
    v8 = SPLoadCertificate(v6, v7, &pCertContext);
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
    if ( v8 )
    {
      v11 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      {
LABEL_9:
        if ( pCertContext )
          CertFreeCertificateContext(pCertContext);
        return v8;
      }
      v12 = 14i64;
      v13 = v8;
    }
    else
    {
      RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
      if ( v16 )
      {
        v19 = v16;
        pvData = v20;
        if ( !CertSetCertificateContextProperty(pCertContext, 0x46u, 0, &pvData)
          && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        {
          LastError = GetLastError();
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            15i64,
            &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids,
            LastError);
        }
      }
      (*(void (__fastcall **)(CSsl3TlsContext *, __int64 *, int *))(*(_QWORD *)this + 280i64))(this, &v17, &v21);
      if ( v17 )
      {
        if ( v21 )
        {
          v19 = v17;
          pvData = v21;
          if ( !CertSetCertificateContextProperty(pCertContext, 0x77u, 0, &pvData)
            && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
          {
            v15 = GetLastError();
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids, v15);
          }
        }
      }
      RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
      v9 = SslTransferCertChainToClientProcess(a2, pCertContext);
      v8 = v9;
      if ( !v9 )
        goto LABEL_9;
      v11 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_9;
      v12 = 17i64;
      v13 = v9;
    }
    WPP_SF_D(*((_QWORD *)v11 + 2), v12, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids, v13);
    goto LABEL_9;
  }
  RtlReleaseResource((PRTL_RESOURCE)(v5 + 72));
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids);
  return (DWORD)-2146893042;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
