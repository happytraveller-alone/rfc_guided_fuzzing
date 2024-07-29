//----- (0000000180077CF0) ----------------------------------------------------
__int64 __fastcall CTls13ExtClient::ParseCertRequestSigAlgExtension(
        CTls13ExtClient *this,
        unsigned __int8 *a2,
        unsigned __int16 a3)
{
  unsigned int v4; // eax
  __int64 v5; // rcx
  unsigned int v6; // ebx
  unsigned __int8 v7; // r9
  int v8; // r8d
  unsigned int v10; // [rsp+20h] [rbp-58h] BYREF
  __int16 v11; // [rsp+28h] [rbp-50h] BYREF
  __int128 v12; // [rsp+2Ah] [rbp-4Eh]
  __int128 v13; // [rsp+3Ah] [rbp-3Eh]
  __int16 v14; // [rsp+4Ah] [rbp-2Eh]

  v11 = 0;
  v14 = 0;
  v10 = 0;
  v12 = 0i64;
  v13 = 0i64;
  v4 = CTlsSignatureSuiteList::ParseSupportedSignatureAlgorithmsAndSet((CTlsSignatureSuiteList *)&v11, a2, a3, &v10);
  v5 = *((_QWORD *)this + 1);
  v6 = v4;
  if ( v4 )
  {
    v7 = 47;
    v8 = v4;
LABEL_7:
    CSslContext::SetErrorAndFatalAlert(v5, 402, v8, v7);
    return v6;
  }
  if ( v5 != -474 )
  {
    CTlsSignatureSuiteList::SetSignatureSuiteList(
      (CTlsSignatureSuiteList *)(v5 + 510),
      (const struct CTlsSignatureSuiteList *)(v5 + 474));
    if ( CTlsSignatureSuiteList::Restrict(
           (CTlsSignatureSuiteList *)(*((_QWORD *)this + 1) + 510i64),
           (const struct CTlsSignatureSuiteList *)&v11,
           *(_DWORD *)(*((_QWORD *)this + 1) + 64i64)) )
    {
      return 0;
    }
    v5 = *((_QWORD *)this + 1);
    v6 = -2146893007;
    v8 = -2146893007;
    v7 = 40;
    goto LABEL_7;
  }
  return (unsigned int)-2146893052;
}

