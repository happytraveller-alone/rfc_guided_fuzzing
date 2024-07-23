// File count: 72
// Total lines: 452
-----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::ProcessHandshake(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *a4)
{
  unsigned int SessionKeys; // ebx
  bool v5; // cf
  int v8; // ecx
  unsigned int v9; // r15d
  int v10; // eax
  unsigned int v11; // r12d
  unsigned int v12; // ecx
  unsigned __int8 *v13; // r14
  unsigned int v14; // ebp
  CCipherMill *v15; // rcx
  __int64 v16; // r8
  int v17; // r9d
  HLOCAL v18; // rax
  struct _RTL_RESOURCE *v19; // rcx
  int v20; // edx
  __int64 v22; // rax
  CCipherMill *v23; // rcx
  __int64 v24; // rdx
  struct CSessionCacheManager *v25; // rdx
  __int64 v26; // rcx
  struct CSessionCacheClientItem *v27; // rbx
  int v28; // eax
  __int64 v29; // rcx
  __int64 v30; // rcx
  CCipherMill *v31; // rcx
  void *v32; // rcx
  CCipherMill *v33; // rcx
  __int64 v34; // rax
  __int64 v35; // rax
  unsigned __int8 v36; // r9
  int v37; // edx
  __int64 v38; // rdx
  CCipherMill *v39; // rcx
  unsigned int v40; // eax
  struct CSessionCacheClientItem *v41; // [rsp+50h] [rbp-88h] BYREF
  unsigned __int8 *v42; // [rsp+58h] [rbp-80h]
  __int128 Src[2]; // [rsp+60h] [rbp-78h] BYREF

  SessionKeys = 0;
  v5 = *((_BYTE *)this + 233) != 0;
  v42 = a4;
  *(_DWORD *)a4 = 0;
  v8 = *a2;
  v9 = 32;
  v10 = *((unsigned __int16 *)this + 34);
  v41 = 0i64;
  v11 = v5 ? 12 : 4;
  v12 = v10 | (v8 << 16);
  v13 = &a2[v11];
  v14 = a3 - v11;
  memset(Src, 0, sizeof(Src));
  if ( v12 > 0xC0046 )
  {
    if ( v12 < 0xD0029 )
      goto LABEL_151;
    if ( v12 > 0xD002B )
    {
      if ( v12 <= 0xE0028 )
        goto LABEL_151;
      if ( v12 > 0xE002C )
      {
        if ( v12 == 1310765 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
          }
          SessionKeys = CSsl3TlsContext::DigestFinish(this, v13, v14);
          v19 = (struct _RTL_RESOURCE *)(*((_QWORD *)this + 165) + 72i64);
          if ( !SessionKeys )
          {
            RtlAcquireResourceExclusive(v19, 1u);
            UpdateServerCertificateSerialChainProperty(this, 0);
            RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
            *(_DWORD *)v42 = 1;
            (*(void (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)this + 448i64))(this);
            if ( (*((_DWORD *)this + 34) & 0x8000000) != 0 )
              CSessionCacheManager::FinishCacheAddItem(CSessionCacheManager::m_pSessionCacheManager, this);
            return SessionKeys;
          }
LABEL_130:
          RtlAcquireResourceExclusive(v19, 1u);
          CSessionCacheClientItem::SetSessionTicket(
            *((CSessionCacheClientItem **)this + 165),
            0i64,
            0,
            0i64,
            0,
            0,
            0,
            0,
            0);
          RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
          return SessionKeys;
        }
        if ( v12 == 1310768 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
          }
          SessionKeys = CSsl3TlsContext::DigestFinish(this, v13, v14);
          v19 = (struct _RTL_RESOURCE *)(*((_QWORD *)this + 165) + 72i64);
          if ( !SessionKeys )
          {
            RtlAcquireResourceExclusive(v19, 1u);
            UpdateServerCertificateSerialChainProperty(this, 1u);
            RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
            *((_DWORD *)this + 17) = 92;
            return SessionKeys;
          }
          goto LABEL_130;
        }
        if ( v12 != 917574 )
        {
          if ( v12 != 1441833 )
            goto LABEL_151;
          v33 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
            v33 = WPP_GLOBAL_Control;
          }
          if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4 )
          {
            if ( v33 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v33 + 28) & 1) != 0 )
              WPP_SF_(*((_QWORD *)v33 + 2), 21i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
            v36 = 10;
            v37 = 200;
            goto LABEL_116;
          }
          SessionKeys = CSsl3TlsClientContext::DigestCertificateStatus(this, v13, v14);
          if ( !SessionKeys )
            *((_DWORD *)this + 17) = 42;
          return SessionKeys;
        }
      }
      v15 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        v15 = WPP_GLOBAL_Control;
      }
      if ( a3 > v11 )
        return (unsigned int)-2146893048;
      if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) != 4 )
      {
        if ( *((_WORD *)this + 34) == 70 )
        {
          if ( v15 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v15 + 28) & 1) == 0 )
            goto LABEL_155;
          v38 = 28i64;
          goto LABEL_154;
        }
        CreateServerCertificateSerialChainProperty(this);
        SessionKeys = AutoVerifyServerCertificate(this);
        if ( SessionKeys )
          return SessionKeys;
      }
      SessionKeys = CSsl3TlsClientContext::DigestServerKeyX(
                      this,
                      *((unsigned __int8 **)this + 121),
                      *((_DWORD *)this + 244),
                      a4);
      if ( !SessionKeys )
      {
        v32 = (void *)*((_QWORD *)this + 121);
        if ( v32 )
        {
          SPExternalFree(v32);
          *((_QWORD *)this + 121) = 0i64;
        }
        *((_DWORD *)this + 17) = 91;
        *((_BYTE *)this + 924) = 0;
        if ( *((_BYTE *)this + 1314) )
        {
          SessionKeys = CSsl3TlsClientContext::CheckForClientCred(this);
          *((_BYTE *)this + 1314) = 0;
        }
        if ( *((_BYTE *)this + 1313) )
          return 590624;
      }
      return SessionKeys;
    }
    v39 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      v39 = WPP_GLOBAL_Control;
    }
    if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4 )
    {
      if ( v39 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v39 + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)v39 + 2), 26i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      v36 = 10;
      v37 = 400;
      goto LABEL_116;
    }
    SessionKeys = CSsl3TlsClientContext::DigestCertificateRequest(this, v13, v14);
    if ( SessionKeys )
      return SessionKeys;
    v40 = CSsl3TlsClientContext::CheckForClientCred(this);
    SessionKeys = v40;
    if ( v40 == -2146893024 )
    {
      *((_BYTE *)this + 1313) = 1;
    }
    else if ( v40 != 590624 )
    {
      if ( v40 )
        return SessionKeys;
      goto LABEL_147;
    }
    SessionKeys = 0;
LABEL_147:
    *((_BYTE *)this + 1315) = 1;
    *((_DWORD *)this + 17) = 44;
    return SessionKeys;
  }
  switch ( v12 )
  {
    case 0xC0046u:
LABEL_11:
      v15 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        v15 = WPP_GLOBAL_Control;
      }
      v16 = *((_QWORD *)this + 1);
      v17 = *(_DWORD *)(v16 + 48);
      if ( v17 == 4 )
      {
LABEL_17:
        *((_DWORD *)this + 244) = v14;
        v18 = SPExternalAlloc(v14);
        *((_QWORD *)this + 121) = v18;
        if ( v18 )
        {
          memcpy_0(v18, v13, *((unsigned int *)this + 244));
          *((_DWORD *)this + 17) = 43;
        }
        else
        {
          return 14;
        }
        return SessionKeys;
      }
      if ( *((_WORD *)this + 34) != 70 )
      {
        if ( (unsigned int)(v17 - 2) > 1 && !*(_BYTE *)(v16 + 72) )
        {
          if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 1) != 0 )
            WPP_SF_(*((_QWORD *)v15 + 2), 24i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
          v36 = 10;
          v37 = 824;
LABEL_116:
          SessionKeys = -2146893018;
          CSslContext::SetErrorAndFatalAlert((__int64)this, v37, -2146893018, v36);
          return SessionKeys;
        }
        goto LABEL_17;
      }
      if ( v15 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v15 + 28) & 1) == 0 )
        goto LABEL_155;
      v38 = 23i64;
      goto LABEL_154;
    case 0x20028u:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      SessionKeys = CSsl3TlsClientContext::DigestServerHello(this, v13, v14, (int *)&v41);
      if ( SessionKeys )
        return SessionKeys;
      if ( (_DWORD)v41 )
      {
        v34 = *((_QWORD *)this + 17);
        if ( (v34 & 0x1000000) == 0 )
        {
          if ( (v34 & 0x8000000) == 0 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
            }
            v36 = 40;
            v37 = 106;
            goto LABEL_116;
          }
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
          }
          v35 = *((_QWORD *)this + 15);
          if ( v35 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
          {
            *(_WORD *)(v35 + 64) |= 4u;
            *(_DWORD *)(v35 + 24) = 1;
          }
          RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u);
          SessionKeys = CSslContext::MakeSessionKeys(this, *(_QWORD *)(*((_QWORD *)this + 165) + 16i64));
          RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
          if ( SessionKeys )
            return SessionKeys;
        }
        v20 = 47;
      }
      else
      {
        v20 = 70;
      }
      *((_DWORD *)this + 17) = v20;
      *((_BYTE *)this + 1315) = 0;
      return SessionKeys;
    case 0x30028u:
      SessionKeys = CSsl3TlsClientContext::DigestServerHelloVerifyRequest(this, v13, v14);
      if ( !SessionKeys )
        *((_DWORD *)this + 17) = 97;
      return SessionKeys;
    case 0xB0046u:
      goto LABEL_47;
    case 0x4002Eu:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      SessionKeys = CSsl3TlsClientContext::DigestNewSessionTicket(this, v13, v14);
      if ( !SessionKeys )
        *((_DWORD *)this + 17) = 50;
      return SessionKeys;
    case 0xB002Fu:
      v22 = *((_QWORD *)this + 17);
      if ( (v22 & 0x1000000) != 0 )
      {
        v23 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_S(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x11u,
            (__int64)&WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
            *(const wchar_t **)(*((_QWORD *)this + 165) + 368i64));
          v22 = *((_QWORD *)this + 17);
        }
        v24 = *((_QWORD *)this + 165);
        *((_QWORD *)this + 17) = v22 & 0xFFFFFFFFFEFFFFFFui64;
        CSessionCacheManager::AcquireCacheTableLock((__int64)v23, *(const unsigned __int16 **)(v24 + 368), 0i64);
        RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u);
        v25 = CSessionCacheManager::m_pSessionCacheManager;
        *(_BYTE *)(*((_QWORD *)this + 165) + 236i64) = 0;
        SessionKeys = CSessionCacheClientItem::CloneCacheElement(*((CSessionCacheClientItem **)this + 165), v25, &v41);
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
        if ( SessionKeys )
        {
          CSessionCacheManager::ReleaseCacheTableLock(
            v26,
            *(const unsigned __int16 **)(*((_QWORD *)this + 165) + 368i64),
            0i64);
          return SessionKeys;
        }
        v27 = v41;
        RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)v41 + 72), 1u);
        v28 = *((_DWORD *)this + 16);
        *((_QWORD *)this + 165) = v27;
        *((_QWORD *)this + 11) = v27;
        *((_DWORD *)v27 + 42) = v28;
        if ( *((unsigned __int16 *)this + 490) > 0x20u
          || (v9 = *((unsigned __int16 *)this + 490),
              memcpy_0(Src, (char *)this + 982, *((unsigned __int16 *)this + 490)),
              v9) )
        {
          v29 = *((_QWORD *)this + 165);
          *(_WORD *)(v29 + 238) = v9;
          memcpy_0((void *)(v29 + 240), Src, v9);
        }
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
        CSessionCacheManager::ReleaseCacheTableLock(
          v30,
          *(const unsigned __int16 **)(*((_QWORD *)this + 165) + 368i64),
          0i64);
      }
LABEL_47:
      v31 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        v31 = WPP_GLOBAL_Control;
      }
      if ( *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4 )
      {
        if ( v31 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v31 + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)v31 + 2), 19i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        v36 = 10;
        v37 = 250;
        goto LABEL_116;
      }
      SessionKeys = CSsl3TlsContext::DigestRemoteCertificate(this, v13, v14);
      if ( !SessionKeys )
      {
        if ( (*((_DWORD *)this + 34) & 0x20000000) == 0
          || (RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u),
              SessionKeys = CSessionCacheClientItem::UpdateRemoteEndpointBindings(*((CSessionCacheClientItem **)this
                                                                                  + 165)),
              RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64)),
              !SessionKeys) )
        {
          *((_DWORD *)this + 17) = 41;
        }
      }
      return SessionKeys;
  }
  if ( v12 != 262191 )
  {
    if ( v12 > 0xC0028 && v12 <= 0xC002A )
      goto LABEL_11;
LABEL_151:
    v15 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      goto LABEL_155;
    v38 = 33i64;
LABEL_154:
    WPP_SF_(*((_QWORD *)v15 + 2), v38, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
LABEL_155:
    if ( (*((_DWORD *)this + 16) & 0xF3FC0) != 0 )
    {
      *((_DWORD *)this + 17) = 96;
      *((_WORD *)this + 48) = 2562;
    }
    return (unsigned int)-2146893018;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
  SessionKeys = CSsl3TlsClientContext::DigestNewSessionTicket(this, v13, v14);
  if ( !SessionKeys )
    *((_DWORD *)this + 17) = 52;
  return SessionKeys;
}
// 1800056F2: variable 'v23' is possibly undefined
// 1800057F4: variable 'v30' is possibly undefined
// 1800058D0: variable 'a4' is possibly undefined
// 18002D70A: variable 'v26' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
