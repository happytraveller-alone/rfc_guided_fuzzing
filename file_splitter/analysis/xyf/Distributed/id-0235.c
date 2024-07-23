//----- (00000001800139F0) ----------------------------------------------------
__int64 __fastcall SpWow64MapVersion3Certificate(void *a1, int a2, struct _SecBuffer *a3, struct LSA_SCHANNEL_CRED *a4)
{
  void *v4; // rsi
  void *v5; // r13
  unsigned int *pvBuffer; // r15
  __int64 v11; // rdx
  int v12; // ebx
  unsigned int v13; // ebx
  int v14; // r13d
  unsigned int v15; // esi
  int v16; // r14d
  int v17; // eax
  HLOCAL v19; // rax
  void *v20; // r10
  unsigned int v21; // ebx
  __int64 v22; // r12
  __int64 v23; // rcx
  const BYTE *v24; // rdx
  __int64 ppvContext; // r9
  DWORD v26; // r8d
  __int64 v27; // rcx
  HCERTSTORE v28; // rax
  int v29; // eax
  unsigned int v30; // ebx
  HLOCAL v31; // rax
  unsigned int v32; // eax
  HCERTSTORE v33; // [rsp+40h] [rbp-49h]
  HLOCAL v34; // [rsp+48h] [rbp-41h]
  unsigned int pvPara; // [rsp+58h] [rbp-31h] BYREF
  unsigned int *v37; // [rsp+60h] [rbp-29h]
  __int128 v38; // [rsp+68h] [rbp-21h] BYREF
  __int128 v39; // [rsp+78h] [rbp-11h]
  unsigned int v40[4]; // [rsp+88h] [rbp-1h]
  __int64 v41; // [rsp+98h] [rbp+Fh]

  v4 = 0i64;
  v5 = 0i64;
  v34 = 0i64;
  v33 = 0i64;
  pvBuffer = 0i64;
  v38 = 0i64;
  v41 = 0i64;
  v39 = 0i64;
  *(_OWORD *)v40 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
  if ( a2 == 3 )
  {
    v12 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, void *))(LsaTable + 80))(0i64, 48i64, &v38, a1);
    if ( v12 < 0 )
      goto LABEL_24;
    v41 = 0i64;
  }
  else
  {
    v11 = 56i64;
    if ( a2 != 4 )
      v11 = 44i64;
    v12 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, void *))(LsaTable + 80))(0i64, v11, &v38, a1);
    if ( v12 < 0 )
      goto LABEL_24;
  }
  memset_0((char *)a4 + 4, 0, 0x6Cui64);
  *(_DWORD *)a4 = a2;
  if ( a2 == 4 )
  {
    v13 = DWORD2(v38);
    v14 = HIDWORD(v38);
    v15 = DWORD1(v38);
  }
  else
  {
    v13 = HIDWORD(v38);
    v14 = v39;
    v15 = DWORD2(v38);
  }
  if ( v15 > 0x64 )
  {
    v12 = -2146893056;
  }
  else
  {
    if ( a3->pvBuffer )
    {
      pvBuffer = (unsigned int *)a3->pvBuffer;
      goto LABEL_14;
    }
    if ( (!v15 || !v13) && !v14 )
    {
LABEL_14:
      if ( v15 && v13 )
      {
        v34 = SPExternalAlloc(4 * v15);
        if ( !v34 )
        {
          v12 = -2146893056;
          v4 = 0i64;
          goto LABEL_23;
        }
        v12 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, HLOCAL, _QWORD))(LsaTable + 80))(0i64, 4 * v15, v34, v13);
        if ( v12 >= 0 )
        {
          *((_DWORD *)a4 + 1) = v15;
          v19 = SPExternalAlloc(56 * v15);
          *((_QWORD *)a4 + 1) = v19;
          if ( !v19 )
          {
LABEL_51:
            v12 = -2146893056;
            goto LABEL_22;
          }
          v33 = CertOpenStore((LPCSTR)2, 0, 0i64, 4u, 0i64);
          v20 = v33;
          if ( !v33 )
          {
            GetLastError();
            goto LABEL_51;
          }
          v21 = 0;
          v22 = 0i64;
          while ( 1 )
          {
            v23 = *pvBuffer;
            v24 = (const BYTE *)(pvBuffer + 1);
            pvBuffer = (unsigned int *)((char *)pvBuffer + v23 + 4);
            if ( !v24 )
              break;
            if ( (unsigned int)v23 < 0xC )
              break;
            ppvContext = v22 + *((_QWORD *)a4 + 1);
            *(_QWORD *)(ppvContext + 16) = *(unsigned int *)v24;
            v26 = *((_DWORD *)v24 + 1);
            if ( (int)v23 - 8 < v26 )
              break;
            if ( !CertAddSerializedElementToStore(v20, v24 + 8, v26, 4u, 0, 2u, 0i64, (const void **)ppvContext) )
            {
              GetLastError();
              goto LABEL_60;
            }
            v20 = v33;
            ++v21;
            v22 += 56i64;
            if ( v21 >= v15 )
              goto LABEL_15;
          }
LABEL_61:
          v12 = -2146893052;
        }
LABEL_22:
        v4 = v34;
LABEL_23:
        v5 = v33;
        goto LABEL_24;
      }
LABEL_15:
      if ( v14 )
      {
        v27 = *pvBuffer;
        if ( pvBuffer == (unsigned int *)-4i64 )
          goto LABEL_61;
        if ( (unsigned int)v27 < 4 )
          goto LABEL_61;
        pvPara = pvBuffer[1];
        v37 = pvBuffer + 2;
        if ( v27 - 4 < (unsigned __int64)pvPara )
          goto LABEL_61;
        v28 = CertOpenStore((LPCSTR)6, 1u, 0i64, 0, &pvPara);
        *((_QWORD *)a4 + 2) = v28;
        if ( !v28 )
        {
LABEL_60:
          v12 = -2146893043;
          goto LABEL_22;
        }
      }
      v16 = a2 - 4;
      if ( v16 )
      {
        if ( v16 != 1 )
        {
LABEL_21:
          v12 = 0;
          goto LABEL_22;
        }
        v12 = CopyTlsParameters(0i64, v40[1], v40[2], 1, (struct _TLS_PARAMETERS **)a4 + 13, (unsigned int *)a4 + 24);
        if ( v12 )
          goto LABEL_22;
        *((_DWORD *)a4 + 21) = HIDWORD(v39);
        *((_DWORD *)a4 + 22) = v40[0];
        v17 = DWORD1(v38);
      }
      else
      {
        v29 = DWORD2(v39);
        if ( DWORD2(v39) && HIDWORD(v39) )
        {
          if ( DWORD2(v39) > 0x100 )
            goto LABEL_51;
          v30 = 4 * DWORD2(v39);
          *((_DWORD *)a4 + 14) = DWORD2(v39);
          v31 = SPExternalAlloc(4 * v29);
          *((_QWORD *)a4 + 8) = v31;
          if ( !v31 )
            goto LABEL_51;
          v12 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, HLOCAL, _QWORD))(LsaTable + 80))(
                  0i64,
                  v30,
                  v31,
                  HIDWORD(v39));
          if ( v12 < 0 )
            goto LABEL_22;
        }
        v32 = v40[0];
        if ( v40[0] == -1 )
          v32 = 0;
        else
          *((_DWORD *)a4 + 18) = v40[0];
        *((_DWORD *)a4 + 18) = v32 & 0x3FFFFFFF;
        *((_DWORD *)a4 + 19) = v40[1];
        *((_DWORD *)a4 + 20) = v40[2];
        *((_DWORD *)a4 + 21) = v40[3];
        *((_DWORD *)a4 + 22) = v41;
        v17 = HIDWORD(v41);
      }
      *((_DWORD *)a4 + 23) = v17;
      goto LABEL_21;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 23i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
    v12 = 590610;
  }
  v4 = 0i64;
  v5 = 0i64;
LABEL_24:
  if ( a3 )
  {
    a3->pvBuffer = 0i64;
    *(_QWORD *)&a3->cbBuffer = 0i64;
    CleanupAppModeInfo(0i64);
  }
  if ( v4 )
    SPExternalFree(v4);
  if ( v5 )
    CertCloseStore(v5, 0);
  if ( v12 < 0 )
    FreeSchannelCred(a4, 1);
  return (unsigned int)v12;
}
// 18003CE25: conditional instruction was optimized away because esi.4 is in (1..64)
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

