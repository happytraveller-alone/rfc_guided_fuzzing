// File count: 202
// Total lines: 414
----------------------------------------
__int64 __fastcall SpMapVersion3Certificate(void *a1, int a2, struct _SecBuffer *a3, struct LSA_SCHANNEL_CRED *a4)
{
  unsigned int v7; // ebx
  void *v8; // r12
  void *v9; // r15
  int v10; // r14d
  int v11; // ebx
  __int64 v12; // r15
  __int64 v13; // rax
  unsigned int v14; // r12d
  struct _SecBuffer *v15; // rbx
  unsigned int *pvBuffer; // rsi
  unsigned int cbBuffer; // r14d
  unsigned int *v18; // rbx
  int v19; // r13d
  int v20; // eax
  void *v21; // rcx
  unsigned int v23; // eax
  unsigned int v24; // eax
  _QWORD *v25; // rax
  HLOCAL v26; // rax
  unsigned int v27; // r15d
  __int64 v28; // r8
  __int64 v29; // rcx
  unsigned int *v30; // rdx
  __int64 ppvContext; // r9
  DWORD v32; // r8d
  int v33; // eax
  __int64 v34; // rcx
  int *v35; // r8
  HCERTSTORE v36; // r14
  const CERT_CONTEXT *i; // rdx
  DWORD v38; // eax
  const CERT_CONTEXT *v39; // rax
  const CERT_CONTEXT *v40; // rsi
  DWORD LastError; // eax
  __int64 v42; // rcx
  HCERTSTORE v43; // rax
  unsigned int v44; // ebx
  HLOCAL v45; // rax
  void *pvPara; // [rsp+28h] [rbp-A9h]
  HCERTSTORE hCertStore; // [rsp+48h] [rbp-89h]
  HLOCAL v48; // [rsp+50h] [rbp-81h]
  unsigned int v49; // [rsp+58h] [rbp-79h]
  struct _SecBuffer v50; // [rsp+60h] [rbp-71h] BYREF
  __int64 v51; // [rsp+70h] [rbp-61h]
  unsigned int v52; // [rsp+78h] [rbp-59h] BYREF
  int *v53; // [rsp+80h] [rbp-51h]
  char v54[4]; // [rsp+88h] [rbp-49h] BYREF
  unsigned int v55; // [rsp+8Ch] [rbp-45h]
  __int64 v56; // [rsp+90h] [rbp-41h]
  __int64 v57; // [rsp+98h] [rbp-39h]
  __int64 v58; // [rsp+A0h] [rbp-31h]
  unsigned int v59; // [rsp+B0h] [rbp-21h]
  __int64 v60; // [rsp+B8h] [rbp-19h]
  unsigned int v61; // [rsp+C0h] [rbp-11h]
  int v62; // [rsp+C4h] [rbp-Dh]
  struct _TLS_PARAMETERS *v63; // [rsp+C8h] [rbp-9h]
  __int64 v64; // [rsp+D0h] [rbp-1h]
  __int128 v65; // [rsp+D8h] [rbp+7h] BYREF
  __int64 v66; // [rsp+E8h] [rbp+17h]

  v48 = 0i64;
  hCertStore = 0i64;
  v7 = 80;
  v8 = 0i64;
  v9 = 0i64;
  memset_0(v54, 0, 0x50ui64);
  v65 = 0i64;
  v66 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
  if ( !LsaTable )
    return 2148074333i64;
  if ( !(*(unsigned __int8 (__fastcall **)(__int128 *))(LsaTable + 192))(&v65) )
    return 2148074244i64;
  v10 = BYTE8(v65) & 0x11;
  if ( a2 == 3 )
  {
    v11 = (*(__int64 (__fastcall **)(_QWORD, __int64, char *, void *))(LsaTable + 80))(0i64, 72i64, v54, a1);
    if ( v11 < 0 )
      goto LABEL_26;
    v64 = 0i64;
  }
  else
  {
    if ( a2 != 4 )
      v7 = 72;
    v11 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, char *, void *))(LsaTable + 80))(0i64, v7, v54, a1);
    if ( v11 < 0 )
      goto LABEL_26;
  }
  memset_0((char *)a4 + 4, 0, 0x6Cui64);
  *(_DWORD *)a4 = a2;
  if ( a2 == 4 )
  {
    v12 = v56;
    v13 = v57;
    v14 = v55;
  }
  else
  {
    v12 = v57;
    v13 = v58;
    v14 = v56;
  }
  v51 = v13;
  if ( v14 > 0x64 )
  {
    v9 = 0i64;
    v11 = -2146893056;
    v8 = 0i64;
    goto LABEL_26;
  }
  v15 = a3;
  pvBuffer = (unsigned int *)a3->pvBuffer;
  if ( pvBuffer )
    goto LABEL_64;
  if ( v14 && v12 || (pvBuffer = 0i64, v13) )
  {
    if ( !v10 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
      v9 = 0i64;
      v11 = 590610;
      v8 = 0i64;
      goto LABEL_26;
    }
    v50.cbBuffer = 8;
    v50.BufferType = 1;
    v25 = SPExternalAlloc(8u);
    v50.pvBuffer = v25;
    if ( !v25 )
    {
      v11 = -2146893056;
LABEL_59:
      v9 = 0i64;
      v8 = 0i64;
      goto LABEL_26;
    }
    *v25 = a1;
    v11 = PerformApplicationCallback(10i64, 0i64, 0i64, &v50, a3, 1, 0, 1);
    if ( v50.pvBuffer )
      SPExternalFree(v50.pvBuffer);
    if ( v11 < 0 )
      goto LABEL_59;
    v15 = a3;
    pvBuffer = (unsigned int *)a3->pvBuffer;
    if ( !pvBuffer )
    {
      v11 = -2146893052;
      goto LABEL_59;
    }
LABEL_64:
    cbBuffer = v15->cbBuffer;
    goto LABEL_17;
  }
  cbBuffer = 0;
LABEL_17:
  v18 = pvBuffer;
  if ( v14 && v12 )
  {
    v48 = SPExternalAlloc(8 * v14);
    if ( !v48 )
    {
      v9 = 0i64;
      v11 = -2146893056;
      v8 = 0i64;
      goto LABEL_26;
    }
    v11 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, HLOCAL, __int64))(LsaTable + 80))(0i64, 8 * v14, v48, v12);
    if ( v11 < 0 )
      goto LABEL_72;
    *((_DWORD *)a4 + 1) = v14;
    v26 = SPExternalAlloc(56 * v14);
    *((_QWORD *)a4 + 1) = v26;
    if ( !v26 )
    {
      v11 = -2146893056;
LABEL_72:
      v9 = hCertStore;
LABEL_74:
      v8 = v48;
      goto LABEL_26;
    }
    hCertStore = CertOpenStore((LPCSTR)2, 0, 0i64, 4u, 0i64);
    v9 = hCertStore;
    if ( !hCertStore )
    {
      GetLastError();
      v11 = -2146893056;
      goto LABEL_74;
    }
    v27 = 0;
    v28 = 0i64;
    *(_QWORD *)&v50.cbBuffer = 0i64;
    v18 = pvBuffer;
    while ( 1 )
    {
      v29 = *v18;
      v30 = v18 + 1;
      cbBuffer += -4 - v29;
      v18 = (unsigned int *)((char *)v18 + v29 + 4);
      if ( !v30 )
        break;
      if ( (unsigned int)v29 < 0xC )
        break;
      ppvContext = v28 + *((_QWORD *)a4 + 1);
      *(_QWORD *)(ppvContext + 16) = *(_QWORD *)v30;
      v32 = v30[2];
      if ( (int)v29 - 12 < v32 )
        break;
      if ( !CertAddSerializedElementToStore(
              hCertStore,
              (const BYTE *)v30 + 12,
              v32,
              4u,
              0,
              2u,
              0i64,
              (const void **)ppvContext) )
        goto LABEL_99;
      v33 = HIDWORD(v60);
      if ( a2 == 4 )
        v33 = v64;
      if ( (v33 & 0x10000) != 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
        v34 = *v18;
        v35 = (int *)(v18 + 1);
        v18 = (unsigned int *)((char *)v18 + v34 + 4);
        v49 = -4 - v34 + cbBuffer;
        if ( v35 )
        {
          if ( (unsigned int)v34 >= 4 )
          {
            v52 = *v35;
            v53 = v35 + 1;
            if ( v34 - 4 >= (unsigned __int64)v52 )
            {
              v36 = CertOpenStore((LPCSTR)6, 1u, 0i64, 0, &v52);
              if ( !v36 )
                goto LABEL_109;
              for ( i = 0i64; ; i = v40 )
              {
                v39 = CertEnumCertificatesInStore(v36, i);
                v40 = v39;
                if ( !v39 )
                {
                  if ( !CertCloseStore(v36, 2u)
                    && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
                  {
                    LastError = GetLastError();
                    WPP_SF_D(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      15i64,
                      &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                      LastError);
                  }
                  cbBuffer = v49;
                  goto LABEL_107;
                }
                if ( !CertAddCertificateContextToStore(hCertStore, v39, 1u, 0i64) && GetLastError() != -2146885627 )
                  break;
              }
              if ( !CertCloseStore(v36, 2u)
                && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
              {
                v38 = GetLastError();
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  14i64,
                  &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                  v38);
              }
              CertFreeCertificateContext(v40);
LABEL_99:
              v11 = -2146893043;
              goto LABEL_72;
            }
          }
        }
        goto LABEL_110;
      }
LABEL_107:
      ++v27;
      v28 = *(_QWORD *)&v50.cbBuffer + 56i64;
      *(_QWORD *)&v50.cbBuffer += 56i64;
      if ( v27 >= v14 )
        goto LABEL_18;
    }
LABEL_71:
    v11 = -2146893052;
    goto LABEL_72;
  }
LABEL_18:
  if ( v51 )
  {
    v42 = *v18;
    if ( v18 == (unsigned int *)-4i64 || (unsigned int)v42 < 4 )
      goto LABEL_71;
    v52 = v18[1];
    v53 = (int *)(v18 + 2);
    if ( v42 - 4 < (unsigned __int64)v52 )
    {
LABEL_110:
      v11 = -2146893052;
      goto LABEL_25;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
    v43 = CertOpenStore((LPCSTR)6, 1u, 0i64, 0, &v52);
    *((_QWORD *)a4 + 2) = v43;
    if ( !v43 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
LABEL_109:
      v11 = -2146893043;
      goto LABEL_25;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_q(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x12u,
        (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
        v43);
  }
  v19 = a2 - 4;
  if ( v19 )
  {
    if ( v19 != 1 )
    {
LABEL_24:
      v11 = 0;
      goto LABEL_25;
    }
    v11 = CopyTlsParameters(v63, v61, 0, 1, (struct _TLS_PARAMETERS **)a4 + 13, (unsigned int *)a4 + 24);
    if ( !v11 )
    {
      *(_QWORD *)((char *)a4 + 84) = v60;
      v20 = v55;
LABEL_23:
      *((_DWORD *)a4 + 23) = v20;
      goto LABEL_24;
    }
  }
  else
  {
    v23 = v59;
    if ( !v59 || !v60 )
      goto LABEL_41;
    if ( v59 > 0x100
      || (v44 = 4 * v59, *((_DWORD *)a4 + 14) = v59, v45 = SPExternalAlloc(4 * v23), (*((_QWORD *)a4 + 8) = v45) == 0i64) )
    {
      v11 = -2146893056;
      goto LABEL_25;
    }
    v11 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, HLOCAL, __int64))(LsaTable + 80))(0i64, v44, v45, v60);
    if ( v11 >= 0 )
    {
LABEL_41:
      v24 = v61;
      if ( v61 == -1 )
        v24 = 0;
      *((_DWORD *)a4 + 18) = v24 & 0x3FFFFFFF;
      *((_DWORD *)a4 + 19) = v62;
      *((_QWORD *)a4 + 10) = v63;
      *((_DWORD *)a4 + 22) = v64;
      v20 = HIDWORD(v64);
      goto LABEL_23;
    }
  }
LABEL_25:
  v9 = hCertStore;
  v8 = v48;
LABEL_26:
  if ( a3 )
  {
    v21 = a3->pvBuffer;
    if ( v21 && (BYTE8(v65) & 0x10) != 0 )
      SPExternalFree(v21);
    a3->pvBuffer = 0i64;
    *(_QWORD *)&a3->cbBuffer = 0i64;
    CleanupAppModeInfo(0i64);
  }
  if ( v8 )
    SPExternalFree(v8);
  if ( v9 )
    CertCloseStore(v9, 0);
  if ( v11 < 0 )
    FreeSchannelCred(a4, 1);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v11 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(pvPara) = v11;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x13u,
      (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
      v11,
      pvPara);
  }
  return (unsigned int)v11;
}
// 18003A716: variable 'pvPara' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
