//----- (0000000180057640) ----------------------------------------------------
__int64 __fastcall AssignNewClientCredential(struct CSsl3TlsClientContext *this, const struct _CERT_CONTEXT *a2)
{
  int v3; // r14d
  __int64 v5; // r15
  unsigned int v6; // ecx
  const char **v7; // rdx
  int v8; // r8d
  unsigned int v9; // ecx
  _DWORD *v10; // rax
  unsigned int Credential; // ebx
  __int64 v13; // rbp
  CSslCredential *v14; // rax
  CSslCredential *v15; // rax
  int *v16; // rsi
  struct _TLS_PARAMETERS *v17; // [rsp+20h] [rbp-98h]
  void *v18[2]; // [rsp+50h] [rbp-68h] BYREF
  __int128 v19[3]; // [rsp+60h] [rbp-58h] BYREF
  __int64 v20; // [rsp+90h] [rbp-28h]

  v3 = *((_DWORD *)this + 16);
  v5 = *(_QWORD *)(*((_QWORD *)this + 10) + 752i64);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids);
  v6 = 0;
  v7 = (const char **)&g_CertTypes;
  while ( strcmp(a2->pCertInfo->SubjectPublicKeyInfo.Algorithm.pszObjId, *v7) )
  {
    ++v6;
    v7 += 2;
    if ( v6 >= 8 )
    {
      v8 = 0;
      goto LABEL_9;
    }
  }
  v8 = *((_DWORD *)&g_CertTypes + 4 * v6 + 3);
LABEL_9:
  v9 = 0;
  if ( *((_WORD *)this + 673) )
  {
    v10 = (_DWORD *)((char *)this + 1348);
    while ( *v10 != v8 )
    {
      ++v9;
      ++v10;
      if ( v9 >= *((unsigned __int16 *)this + 673) )
        goto LABEL_13;
    }
    v13 = *((_QWORD *)this + 10);
    if ( v13 )
    {
      v14 = (CSslCredential *)SPExternalAlloc(0x498u);
      if ( v14 && (v15 = CSslCredential::CSslCredential(v14), (v16 = (int *)v15) != 0i64) )
      {
        v20 = 0i64;
        v19[0] = (unsigned __int64)a2;
        memset(&v19[1], 0, 32);
        Credential = CSslCredential::CreateCredential(
                       v15,
                       *(_DWORD *)(v13 + 212),
                       (char *)(v13 + 216),
                       v5,
                       (struct LSA_SCHANNEL_SUB_CRED *)v19,
                       (*(_DWORD *)(v13 + 156) >> 4) & 8,
                       1u,
                       0,
                       0i64,
                       0);
        if ( !Credential )
        {
          if ( CSslCredential::IsClientCredApplicable(
                 (CSslCredential *)v16,
                 v16[33],
                 *((_DWORD *)this + 16),
                 (const struct CTlsSignatureSuiteList *)(((unsigned __int64)this + 510) & -(__int64)((v3 & 0x82800) != 0)),
                 *(struct _TLS_PARAMETERS **)(v13 + 200),
                 *(_DWORD *)(v13 + 196)) )
          {
            CSsl3TlsClientContext::SetActiveClientCred(this, (struct CSslCredential *)v16, 1);
            Credential = 0;
            goto LABEL_18;
          }
          Credential = -2146893043;
        }
        (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)v16 + 8i64))(v16, 1i64);
      }
      else
      {
        Credential = 14;
      }
    }
    else
    {
      Credential = -2146893052;
    }
  }
  else
  {
LABEL_13:
    Credential = -2146893043;
  }
  if ( *((_BYTE *)this + 266) )
  {
    *(_OWORD *)v18 = 0i64;
    if ( LsaTable )
    {
      if ( !(*(unsigned int (__fastcall **)(_QWORD, _QWORD, _QWORD, void **, _QWORD))(LsaTable + 488))(
              0i64,
              0i64,
              0i64,
              v18,
              0i64) )
        CleanupAppModeInfo(v18[1]);
    }
  }
LABEL_18:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && Credential || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(v17) = Credential;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0xBu,
      (__int64)&WPP_d5302f0819dd3315699237cebd9fbb35_Traceguids,
      Credential,
      v17);
  }
  return Credential;
}
// 1800577AF: variable 'v17' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18007D750: using guessed type const struct _OIDPROVMAP near *const g_CertTypes;
// 180092620: using guessed type __int64 LsaTable;
