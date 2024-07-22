//----- (0000000180010874) ----------------------------------------------------
__int64 __fastcall SpCommonAcquireCredentialsHandle(
        struct _UNICODE_STRING *a1,
        unsigned int a2,
        struct _LUID *a3,
        struct _SCHANNEL_CRED *a4,
        unsigned __int64 *a5,
        union _LARGE_INTEGER *a6)
{
  int ProcessImageName; // eax
  __int64 v10; // rdx
  __int64 v11; // r8
  __int64 v12; // r9
  CCipherMill *v13; // rcx
  int v14; // r12d
  char v15; // r15
  NTSTATUS v16; // eax
  CCipherMill *v17; // rax
  signed int v18; // eax
  int v19; // ecx
  char v20; // r15
  bool v21; // zf
  unsigned int v22; // ebx
  unsigned int DefaultMachineCred; // ebx
  union _LARGE_INTEGER *v24; // r14
  CCredentialGroup **v25; // rsi
  int v26; // eax
  unsigned int v27; // ecx
  unsigned int v28; // ebx
  char v29; // al
  unsigned int cbBuffer; // edx
  CCredentialGroup *v32; // rcx
  unsigned int updated; // ebx
  NTSTATUS v34; // ecx
  unsigned __int16 v35; // dx
  _DWORD *v36; // rax
  struct _SCHANNEL_CRED **v37; // rax
  signed int v38; // eax
  void *pvBuffer; // rcx
  __int64 DesiredAccess; // [rsp+20h] [rbp-E0h]
  char v41; // [rsp+41h] [rbp-BFh]
  unsigned int v42; // [rsp+50h] [rbp-B0h] BYREF
  struct _SecBuffer v43; // [rsp+58h] [rbp-A8h] BYREF
  void *TargetHandle; // [rsp+68h] [rbp-98h] BYREF
  struct _SecBuffer v45; // [rsp+70h] [rbp-90h] BYREF
  CCredentialGroup *v46; // [rsp+80h] [rbp-80h] BYREF
  unsigned int v47; // [rsp+88h] [rbp-78h] BYREF
  unsigned int v48; // [rsp+8Ch] [rbp-74h]
  struct _LUID v49; // [rsp+90h] [rbp-70h] BYREF
  __int64 v50; // [rsp+98h] [rbp-68h] BYREF
  struct _SECPKG_CALL_INFO v51; // [rsp+A0h] [rbp-60h] BYREF
  struct _LUID v52; // [rsp+B8h] [rbp-48h] BYREF
  char v53; // [rsp+C8h] [rbp-38h]
  int v54; // [rsp+CCh] [rbp-34h]
  HANDLE SourceHandle; // [rsp+D0h] [rbp-30h]
  int v56[18]; // [rsp+E0h] [rbp-20h] BYREF
  int v57; // [rsp+128h] [rbp+28h]
  unsigned __int16 v58[264]; // [rsp+150h] [rbp+50h] BYREF

  v48 = a2;
  *(_QWORD *)&v43.cbBuffer = a5;
  v46 = 0i64;
  memset_0(v56, 0, 0x70ui64);
  TargetHandle = 0i64;
  v42 = 0;
  v45 = 0i64;
  v50 = 0i64;
  v41 = 0;
  if ( (unsigned int)SchannelInit(0)
    && (*(unsigned __int8 (__fastcall **)(struct _SECPKG_CALL_INFO *))(LsaTable + 192))(&v51) )
  {
    memset_0(v58, 0, 0x208ui64);
    ProcessImageName = GetProcessImageName(v58, &v51);
    v12 = (unsigned int)ProcessImageName;
    if ( ProcessImageName < 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_DD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x32u,
          (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
          ProcessImageName,
          v51.ProcessId);
    }
    else
    {
      v13 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            51i64,
            &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
            v51.ProcessId);
          v13 = WPP_GLOBAL_Control;
        }
        if ( v13 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v13 + 28) & 4) != 0 )
          WPP_SF_S(*((_QWORD *)v13 + 2), 0x34u, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, v58);
      }
    }
    v14 = v51.Attributes & 0x40;
    v15 = v51.Attributes & 1;
    if ( (v51.Attributes & 0x11) == 0 )
    {
      v41 = 1;
      if ( (*(int (__fastcall **)(unsigned int *, _QWORD, _QWORD, struct _SecBuffer *, _QWORD))(LsaTable + 488))(
             &v42,
             0i64,
             0i64,
             &v45,
             0i64) < 0 )
        goto LABEL_61;
      if ( v42 == 4 )
      {
        v25 = *(CCredentialGroup ***)&v43.cbBuffer;
        cbBuffer = v45.cbBuffer;
        v43.BufferType = 1;
        v32 = *(CCredentialGroup **)v45.pvBuffer;
        v43.pvBuffer = (char *)v45.pvBuffer + 8;
        v43.cbBuffer = v45.cbBuffer - 8;
        *v25 = v32;
        v46 = v32;
        if ( v32 )
        {
          if ( cbBuffer != 8 )
          {
            v24 = a6;
            updated = UpdatePrivateKeysForCreds(v32, &v43, v14 != 0);
            CCredentialGroup::GetCredentialExpirationTime(v46, a6);
            v28 = TranslateToSecurityStatus(updated);
LABEL_124:
            v20 = v41;
            goto LABEL_45;
          }
          v28 = -2146893043;
        }
        else
        {
          v28 = -2146893052;
        }
LABEL_123:
        v24 = a6;
        goto LABEL_124;
      }
    }
    if ( (*(int (__fastcall **)(struct _LUID *, __int64, __int64, __int64))(LsaTable + 128))(&v52, v10, v11, v12) >= 0 )
    {
      if ( a3 && (a3->LowPart || a3->HighPart) )
      {
        if ( !v53 )
        {
          v34 = -1073741727;
LABEL_120:
          v18 = RtlNtStatusToDosError(v34);
          goto LABEL_121;
        }
        v49 = *a3;
        v16 = (*(__int64 (__fastcall **)(struct _LUID *, void **))(LsaTable + 368))(a3, &TargetHandle);
        if ( v16 >= 0 )
        {
          v17 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          {
            goto LABEL_21;
          }
          v35 = 53;
          goto LABEL_75;
        }
      }
      else
      {
        if ( (char *)SourceHandle - 1 > (char *)0xFFFFFFFFFFFFFFFDi64 )
        {
          v34 = -1073741670;
          goto LABEL_120;
        }
        v49 = v52;
        v16 = NtDuplicateObject(
                (HANDLE)0xFFFFFFFFFFFFFFFFi64,
                SourceHandle,
                (HANDLE)0xFFFFFFFFFFFFFFFFi64,
                &TargetHandle,
                0,
                0,
                2u);
        if ( v16 >= 0 )
        {
          v17 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          {
            goto LABEL_21;
          }
          v35 = 54;
LABEL_75:
          WPP_SF_q(*((_QWORD *)v17 + 2), v35, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, TargetHandle);
LABEL_21:
          if ( v54 > 1 )
          {
            v56[0] = 4;
            if ( !a4 )
            {
LABEL_34:
              v20 = v41;
LABEL_35:
              if ( (v57 & 0xF0000) != 0 && (v57 & 0xFFF0FFFF) != 0 )
              {
                v28 = -2146893007;
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
                {
                  LODWORD(DesiredAccess) = -2146893007;
                  WPP_SF_Dd(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    0x3Au,
                    (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                    -2146893007,
                    DesiredAccess);
                }
                return v28;
              }
              v21 = a4 == 0i64;
              v22 = v48;
              if ( v21 && (v48 & 0x40051555) != 0 )
              {
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids);
                }
                DefaultMachineCred = FindDefaultMachineCred(&v46, v22, &v49, TargetHandle, v51.ProcessId, v58);
              }
              else
              {
                DefaultMachineCred = CSslCredManager::CreateCredentialGroup(
                                       CSslCredManager::m_pCredManager,
                                       &v46,
                                       v48,
                                       &v49,
                                       TargetHandle,
                                       (struct LSA_SCHANNEL_CRED *)v56,
                                       v58);
                FreeSchannelCred((struct LSA_SCHANNEL_CRED *)v56, 0);
              }
              v24 = a6;
              if ( DefaultMachineCred )
              {
                v25 = *(CCredentialGroup ***)&v43.cbBuffer;
                goto LABEL_43;
              }
              CCredentialGroup::GetCredentialExpirationTime(v46, a6);
              v25 = *(CCredentialGroup ***)&v43.cbBuffer;
              **(_QWORD **)&v43.cbBuffer = v46;
              if ( v20 )
              {
                if ( !LsaTable )
                {
                  v28 = -2146893052;
                  goto LABEL_45;
                }
                v26 = (*(__int64 (__fastcall **)(unsigned int *, __int64 *, _QWORD, struct _SecBuffer *, _QWORD))(LsaTable + 488))(
                        &v42,
                        &v50,
                        0i64,
                        &v45,
                        0i64);
                DefaultMachineCred = v26;
                if ( v26 >= 0 )
                {
                  if ( v42 != 4 )
                    goto LABEL_43;
                  *(_QWORD *)v45.pvBuffer = *v25;
                  LOBYTE(DesiredAccess) = 1;
                  v26 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, struct _SecBuffer *, _DWORD))(LsaTable + 496))(
                          v42,
                          v50,
                          4i64,
                          &v45,
                          DesiredAccess);
                  if ( v26 >= 0 )
                  {
                    v28 = -2146893055;
                    v29 = 1;
                    goto LABEL_46;
                  }
                }
                v27 = v26;
                goto LABEL_44;
              }
LABEL_43:
              v27 = DefaultMachineCred;
LABEL_44:
              v28 = TranslateToSecurityStatus(v27);
LABEL_45:
              v29 = 0;
LABEL_46:
              if ( !TargetHandle || v29 )
              {
                if ( !v28 )
                  goto LABEL_49;
              }
              else
              {
                if ( !v28 )
                {
LABEL_49:
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v28
                     || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
                  {
                    LODWORD(DesiredAccess) = v28;
                    WPP_SF_DD(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      0x3Du,
                      (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                      v28,
                      DesiredAccess);
                  }
                  return v28;
                }
                NtClose(TargetHandle);
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  WPP_SF_q(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    0x3Cu,
                    (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                    TargetHandle);
                }
              }
              if ( v28 != -2146893055 )
              {
                pvBuffer = 0i64;
                if ( !v20 )
                  pvBuffer = v45.pvBuffer;
                CleanupAppModeInfo(pvBuffer);
                if ( v46 )
                  CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, v46);
                if ( v25 )
                  *v25 = 0i64;
                if ( v24 )
                  v24->QuadPart = 0i64;
              }
              goto LABEL_49;
            }
            if ( v15 )
            {
              if ( a4->dwVersion == 4 )
              {
                v18 = MapKernelAuthDataV4(a4, a1, TargetHandle, (struct LSA_SCHANNEL_CRED *)v56);
              }
              else
              {
                if ( a4->dwVersion != 5 )
                  goto LABEL_34;
                v18 = MapKernelAuthDataV5(a4, a1, TargetHandle, (struct LSA_SCHANNEL_CRED *)v56);
              }
              if ( v18 >= 0 )
                goto LABEL_34;
            }
            else
            {
              v18 = (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned int *, struct _SCHANNEL_CRED *))(LsaTable + 80))(
                      0i64,
                      4i64,
                      &v47,
                      a4);
              if ( v18 >= 0 )
              {
                v19 = v47;
                if ( v47 < 3 )
                  goto LABEL_103;
                if ( v47 <= 5 )
                {
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                  {
                    WPP_SF_d(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      0x38u,
                      (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                      v47);
                    v19 = v47;
                  }
                  if ( v14 )
                    v18 = SpWow64MapVersion3Certificate(a4, v19, &v45, (struct LSA_SCHANNEL_CRED *)v56);
                  else
                    v18 = SpMapVersion3Certificate(a4, v19, &v45, (struct LSA_SCHANNEL_CRED *)v56);
                  if ( v18 != 590610 )
                  {
                    if ( v18 >= 0 )
                      goto LABEL_34;
                    goto LABEL_121;
                  }
                  v20 = v41;
                  if ( !v41 )
                    goto LABEL_35;
                  if ( !LsaTable )
                  {
                    v28 = -2146893052;
LABEL_93:
                    v25 = *(CCredentialGroup ***)&v43.cbBuffer;
                    v24 = a6;
                    goto LABEL_45;
                  }
                  v42 = 10;
                  if ( v14 )
                  {
                    v45.cbBuffer = 4;
                    v36 = (_DWORD *)(*(__int64 (__fastcall **)(__int64))(LsaTable + 384))(4i64);
                    v45.pvBuffer = v36;
                    if ( v36 )
                    {
                      *v36 = (_DWORD)a4;
                      goto LABEL_100;
                    }
                  }
                  else
                  {
                    v45.cbBuffer = 8;
                    v37 = (struct _SCHANNEL_CRED **)(*(__int64 (__fastcall **)(__int64))(LsaTable + 384))(8i64);
                    v45.pvBuffer = v37;
                    if ( v37 )
                    {
                      *v37 = a4;
LABEL_100:
                      v45.BufferType = 1;
                      LOBYTE(DesiredAccess) = 1;
                      v38 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, struct _SecBuffer *, _DWORD))(LsaTable + 496))(
                              v42,
                              0i64,
                              8i64,
                              &v45,
                              DesiredAccess);
                      if ( v38 >= 0 )
                        v28 = -2146893055;
                      else
                        v28 = TranslateToSecurityStatus(v38);
                      goto LABEL_93;
                    }
                  }
                  v28 = -2146893056;
                  goto LABEL_93;
                }
                if ( v47 != 512 )
                {
LABEL_103:
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                  {
                    WPP_SF_d(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      0x39u,
                      (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                      v47);
                  }
                  v28 = -2146893043;
                  goto LABEL_122;
                }
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  WPP_SF_d(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    0x37u,
                    (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
                    512);
                }
                v18 = SpMapAuthIdentity(a4, (struct LSA_SCHANNEL_CRED *)v56, (__int64)TargetHandle);
                if ( !v18 )
                  goto LABEL_34;
              }
            }
LABEL_121:
            v28 = TranslateToSecurityStatus(v18);
            goto LABEL_122;
          }
          v28 = -2146893042;
LABEL_122:
          v25 = *(CCredentialGroup ***)&v43.cbBuffer;
          goto LABEL_123;
        }
      }
      v34 = v16;
      goto LABEL_120;
    }
LABEL_61:
    v28 = -2146893052;
    goto LABEL_122;
  }
  return 2148074244i64;
}
// 180010A07: variable 'v10' is possibly undefined
// 180010A07: variable 'v11' is possibly undefined
// 180010A07: variable 'v12' is possibly undefined
// 18003998D: variable 'DesiredAccess' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

