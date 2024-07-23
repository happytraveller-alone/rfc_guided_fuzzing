// File count: 185
// Total lines: 275
----------------------------------------
__int64 __fastcall CCredentialGroup::InitializeCredentialGroup(
        CCredentialGroup *this,
        unsigned int a2,
        struct _LUID *a3,
        __int64 a4,
        struct LSA_SCHANNEL_CRED *a5,
        unsigned __int16 *a6)
{
  int v9; // r15d
  unsigned int v10; // esi
  int v11; // eax
  unsigned int RandomBits; // esi
  unsigned int v13; // edx
  int v14; // eax
  __int64 v15; // rax
  __int64 v16; // rax
  const WCHAR *v18; // rdx
  CSslCredential *v19; // rax
  CSslCredential *v20; // r13
  CCredentialGroup *v21; // rdx
  CCredentialGroup **v22; // rcx
  unsigned int v23; // r8d
  int v24; // edx
  char v25; // si
  char v26; // r10
  unsigned int v27; // r15d
  PCCERT_CONTEXT *v28; // rcx
  void *v29; // rcx
  HCERTSTORE v30; // rax
  DWORD LastError; // eax
  void *v32; // rcx
  __int64 v33; // rax
  char pvData[4]; // [rsp+50h] [rbp-88h] BYREF
  unsigned int i; // [rsp+54h] [rbp-84h]
  DWORD pcbData; // [rsp+58h] [rbp-80h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-78h] BYREF
  struct _UNICODE_STRING v38; // [rsp+70h] [rbp-68h] BYREF
  int v39; // [rsp+80h] [rbp-58h] BYREF
  char v40; // [rsp+88h] [rbp-50h]

  pcbData = 0;
  v9 = 0;
  RtlInitializeResource((PRTL_RESOURCE)((char *)this + 48));
  *((_DWORD *)this + 36) = 1;
  if ( (*(unsigned __int8 (__fastcall **)(int *))(LsaTable + 192))(&v39) )
  {
    *((_DWORD *)this + 53) = v39;
    *((_BYTE *)this + 172) = v40 & 1;
    *((_BYTE *)this + 173) = (v40 & 0x11) == 0;
  }
  StringCchCopyW((char *)this + 216, 260i64, (char *)a6);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_qD(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x15u, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, this, a2);
  v10 = *((_DWORD *)this + 53);
  if ( (g_dwEventLogging & 4) != 0 )
  {
    v18 = (const WCHAR *)pszClientString;
    if ( (a2 & 0x40051555) != 0 )
      v18 = pszServerString;
    RtlInitUnicodeString(&DestinationString, v18);
    RtlInitUnicodeString(&v38, (PCWSTR)this + 108);
    SchEventWrite(&SSLEVENT_CREATE_CRED, L"duub", v10, &v38, &DestinationString, 80i64, a5);
  }
  v11 = CopyTlsParameters(
          *((struct _TLS_PARAMETERS **)a5 + 13),
          *((_DWORD *)a5 + 24),
          0,
          0,
          (struct _TLS_PARAMETERS **)this + 25,
          (unsigned int *)this + 49);
  if ( v11 )
  {
    RandomBits = 87;
    if ( v11 == -2146893056 )
      RandomBits = 14;
    v9 = 10017;
    goto LABEL_35;
  }
  RandomBits = CCredentialGroup::InitializeEnabledProtocols(
                 this,
                 *(_DWORD *)a5,
                 *((_DWORD *)a5 + 18),
                 *((_DWORD *)a5 + 22),
                 a2);
  if ( RandomBits )
  {
    v9 = 10013;
    goto LABEL_35;
  }
  *(struct _LUID *)((char *)this + 740) = *a3;
  *((_QWORD *)this + 94) = a4;
  if ( (a2 & 0x800A2AAA) != 0 )
  {
    if ( bDomainJoined )
    {
      RandomBits = CCredentialGroup::InitializeClientNameInfo(this, a4);
      if ( RandomBits )
        goto LABEL_35;
    }
  }
  RandomBits = GenerateRandomBits((PUCHAR)this + 760, 8u);
  if ( RandomBits )
    goto LABEL_35;
  for ( i = 0; i < *((_DWORD *)a5 + 1); ++i )
  {
    v19 = (CSslCredential *)SPExternalAlloc(0x498u);
    if ( v19 )
      v20 = CSslCredential::CSslCredential(v19);
    else
      v20 = 0i64;
    if ( !v20 )
    {
      RandomBits = 14;
      goto LABEL_35;
    }
    v21 = (CSslCredential *)((char *)v20 + 8);
    v22 = (CCredentialGroup **)*((_QWORD *)this + 5);
    if ( *v22 != (CCredentialGroup *)((char *)this + 32) )
      __fastfail(3u);
    *(_QWORD *)v21 = (char *)this + 32;
    *((_QWORD *)v20 + 2) = v22;
    *v22 = v21;
    *((_QWORD *)this + 5) = v21;
    ++*((_DWORD *)this + 7);
    v23 = *((_DWORD *)a5 + 22);
    v24 = HIWORD(v23) & 1 | 4;
    if ( (v23 & 0x20000) == 0 )
      v24 = HIWORD(*((_DWORD *)a5 + 22)) & 1;
    v25 = v24 | 8;
    if ( (v23 & 0x40000) == 0 )
      v25 = v24;
    if ( g_fDisableOcsp )
    {
      v26 = v25 | 0x10;
    }
    else
    {
      v26 = v25;
      if ( (v23 & 0x180000) == 0x80000 && !g_fEnableOcspForSni )
      {
        v27 = i;
        v28 = (PCCERT_CONTEXT *)(*((_QWORD *)a5 + 1) + 56i64 * i);
        pvData[0] = 0;
        pcbData = 1;
        if ( !CertGetCertificateContextProperty(*v28, 0x79u, pvData, &pcbData) || (v26 = v25, !pvData[0]) )
          v26 = v25 | 0x10;
        goto LABEL_53;
      }
    }
    v27 = i;
LABEL_53:
    RandomBits = CSslCredential::CreateCredential(
                   v20,
                   *((_DWORD *)this + 53),
                   (char *)this + 216,
                   a4,
                   (struct LSA_SCHANNEL_SUB_CRED *)(*((_QWORD *)a5 + 1) + 56i64 * v27),
                   v26,
                   1u,
                   *((_QWORD *)a5 + 3) != 0i64,
                   *((struct _TLS_PARAMETERS **)this + 25),
                   *((_DWORD *)this + 49));
    pcbData = *((unsigned __int8 *)v20 + 76);
    v9 = *((_DWORD *)v20 + 18);
    if ( RandomBits )
      goto LABEL_35;
    if ( *((_DWORD *)v20 + 35) )
      *((_BYTE *)this + 900) = 1;
  }
  CCredentialGroup::InitializeFlags(this, *((_DWORD *)a5 + 22));
  if ( (a2 & 0x40051555) != 0 && (*((_DWORD *)this + 39) & 0x4000) != 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids);
    RandomBits = 87;
    v9 = 10019;
    goto LABEL_35;
  }
  if ( (*((_DWORD *)this + 39) & 0x2000) != 0 )
  {
    *((_DWORD *)a5 + 19) = -1;
    v13 = -1;
  }
  else
  {
    v13 = *((_DWORD *)a5 + 19);
  }
  RandomBits = CCredentialGroup::InitializeMinMaxStrengths(this, v13, *((_DWORD *)a5 + 20));
  if ( RandomBits )
  {
    v9 = 10010;
LABEL_35:
    if ( !pcbData )
      LogCreateCredFailedEvent(*((_DWORD *)this + 53), (const WCHAR *)this + 108, (a2 & 0x40051555) != 0, v9);
    *((_QWORD *)this + 94) = 0i64;
    return RandomBits;
  }
  if ( !BuildUserRequestedAlgList(
          this,
          *((_BYTE *)this + 172),
          *((unsigned int **)a5 + 8),
          *((_DWORD *)a5 + 14),
          (unsigned int **)this + 23,
          (unsigned int *)this + 44,
          (CCredentialGroup *)((char *)this + 192)) )
  {
    RandomBits = -2146893007;
    v9 = 10011;
    goto LABEL_35;
  }
  if ( *((_DWORD *)a5 + 21) )
  {
    v14 = 0;
    if ( *((_DWORD *)a5 + 21) != -1 )
      v14 = *((_DWORD *)a5 + 21);
  }
  else if ( (*((_DWORD *)this + 38) & 0x800A2AAA) != 0 )
  {
    v14 = *((_DWORD *)CSessionCacheManager::m_pSessionCacheManager + 5);
  }
  else
  {
    v14 = *((_DWORD *)CSessionCacheManager::m_pSessionCacheManager + 6);
  }
  *((_DWORD *)this + 52) = v14;
  if ( (a2 & 0x40051555) != 0 )
  {
    v29 = (void *)*((_QWORD *)a5 + 2);
    if ( v29 )
    {
      v30 = CertDuplicateStore(v29);
      *((_QWORD *)this + 96) = v30;
      if ( !v30
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        LastError = GetLastError();
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          23i64,
          &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids,
          LastError);
      }
    }
  }
  v15 = *((_QWORD *)a5 + 3);
  if ( v15 )
    *((_QWORD *)this + 100) = v15;
  else
    v15 = *((_QWORD *)this + 100);
  if ( v15 )
  {
    v32 = (void *)*((_QWORD *)a5 + 4);
    if ( v32 )
      CertCloseStore(v32, 0);
  }
  v16 = *((_QWORD *)a5 + 5);
  if ( v16 )
  {
    *((_QWORD *)this + 101) = v16;
    v33 = *((_QWORD *)a5 + 6);
    if ( v33 )
      *((_QWORD *)this + 102) = v33;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082B38: using guessed type GUID WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids;
// 180092620: using guessed type __int64 LsaTable;
// 180092648: using guessed type int bDomainJoined;
// 1800927A4: using guessed type int g_fDisableOcsp;
// 1800927A8: using guessed type int g_fEnableOcspForSni;
// 18000FB04: using guessed type char pvData[4];
