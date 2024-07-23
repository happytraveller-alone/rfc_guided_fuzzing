// File count: 73
// Total lines: 312
-----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::DigestServerHello(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        int *a4)
{
  CSsl3TlsClientContext *v4; // rdi
  int v5; // r15d
  unsigned int v6; // esi
  int v7; // r8d
  size_t v8; // r14
  unsigned __int8 *v9; // r12
  unsigned __int8 *v10; // rbx
  unsigned int v11; // esi
  int v12; // eax
  __int64 v13; // rdx
  int v14; // eax
  __int64 v15; // rcx
  unsigned int v16; // r8d
  __int64 v17; // r9
  unsigned int v18; // r10d
  unsigned int v19; // eax
  int v20; // r8d
  unsigned int v21; // r8d
  int v22; // eax
  unsigned int v23; // ebx
  struct CSessionCacheClientItem *v24; // rbx
  __int64 v25; // rcx
  int v26; // esi
  __int64 v27; // rcx
  CCipherMill *v28; // rcx
  __int64 v29; // rdx
  __int64 result; // rax
  __int64 v31; // r9
  int *v32; // rax
  __int64 v33; // rdx
  __int64 v34; // rax
  __int64 v35; // rax
  struct CSessionCacheManager *v36; // rdx
  __int64 v37; // rcx
  int v38; // edx
  unsigned __int8 v39; // r9
  unsigned __int8 IsMaliciousDowngrade; // al
  CCipherMill *v41; // rcx
  __int64 v42; // rdx
  unsigned int v43; // [rsp+34h] [rbp-45h]
  struct CSessionCacheClientItem *v44; // [rsp+38h] [rbp-41h] BYREF
  int *v45; // [rsp+40h] [rbp-39h]
  __int64 Buf1[3]; // [rsp+50h] [rbp-29h] BYREF
  int v47; // [rsp+68h] [rbp-11h]
  char v48; // [rsp+70h] [rbp-9h]
  __int64 v49; // [rsp+78h] [rbp-1h]
  int v50; // [rsp+80h] [rbp+7h]
  char v51; // [rsp+84h] [rbp+Bh]
  CSsl3TlsClientContext *v52; // [rsp+88h] [rbp+Fh]

  v45 = a4;
  v4 = this;
  v44 = 0i64;
  v5 = 32;
  *((_BYTE *)this + 554) = 0;
  if ( a3 < 0x23 )
    goto LABEL_78;
  v6 = a3 - 35;
  v7 = a2[1] | (*a2 << 8);
  *((_OWORD *)this + 19) = *(_OWORD *)(a2 + 2);
  *((_OWORD *)this + 20) = *(_OWORD *)(a2 + 18);
  v8 = a2[34];
  if ( (unsigned int)v8 > 0x20 )
  {
    v38 = 103;
LABEL_79:
    v39 = 50;
    goto LABEL_80;
  }
  if ( v6 < (int)v8 + 3 )
  {
LABEL_78:
    v38 = 100;
    goto LABEL_79;
  }
  v9 = a2 + 35;
  v10 = &a2[v8 + 35];
  v43 = v10[1] | (*v10 << 8);
  if ( v10[2] )
  {
    v39 = 30;
    v38 = 104;
LABEL_80:
    v23 = -2146893018;
    goto LABEL_81;
  }
  v11 = -3 - v8 + v6;
  if ( !*((_QWORD *)this + 10) )
    return 2148074244i64;
  v12 = ConvertSslVersionToSchannelProtocol(v7);
  v14 = *(_DWORD *)(v13 + 152) & v12 & 0xA2AA0;
  if ( !v14 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)v4, 105, -2146893007, 0x46u);
    return 2148074289i64;
  }
  *((_DWORD *)v4 + 16) = v14;
  *((_WORD *)v4 + 17) = ConvertSchannelProtocolToSsl(v14);
  v19 = *((_DWORD *)v4 + 9);
  if ( *((_BYTE *)v4 + 233) == (_BYTE)v17 )
  {
    if ( v19 <= v16 || v19 < 0x303 )
      goto LABEL_9;
  }
  else if ( v19 > 0xFEFD || v19 >= v16 )
  {
    goto LABEL_9;
  }
  IsMaliciousDowngrade = CSsl3TlsClientContext::IsMaliciousDowngrade(v4, v16);
  v17 = 0i64;
  if ( IsMaliciousDowngrade )
    return 2148074248i64;
  v18 = 2;
LABEL_9:
  if ( v11 <= v18 )
  {
    *((_BYTE *)v4 + 922) = v17;
  }
  else
  {
    Buf1[2] = 0i64;
    v47 = 0;
    v20 = v10[3];
    Buf1[0] = (__int64)&CTlsExtClient::`vftable';
    Buf1[1] = (__int64)v4;
    v48 = v17;
    v49 = v17;
    v50 = v17;
    v52 = v4;
    v51 = *((_BYTE *)v4 + 922);
    v21 = v10[4] | (v20 << 8);
    if ( v11 - 2 < v21 )
    {
      *((_BYTE *)v4 + 922) = v17;
    }
    else
    {
      v22 = CTlsExt::ParseTlsExtensions((__int64)Buf1, v10 + 5, v21, v18);
      v23 = v22;
      if ( v22 )
      {
        if ( v22 != -2146892986 )
          CSslContext::SetErrorAndFatalAlert((__int64)v4, 106, v22, 0xAu);
        CTlsExtClient::~CTlsExtClient((CTlsExtClient *)Buf1);
        return v23;
      }
    }
    CTlsExtClient::~CTlsExtClient((CTlsExtClient *)Buf1);
    LODWORD(v17) = 0;
  }
  if ( *((_BYTE *)v4 + 554) == (_BYTE)v17 )
  {
    if ( *((_BYTE *)v4 + 553) == (_BYTE)v17 )
    {
      if ( g_fAllowInsecureRenegoServers != (_DWORD)v17 )
        goto LABEL_14;
      v41 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      {
LABEL_73:
        CSslContext::SetErrorAndFatalAlert((__int64)v4, 1207, -2146892986, 0x28u);
        result = 2148074310i64;
        *((_DWORD *)v4 + 17) = 96;
        *((_WORD *)v4 + 48) = 10242;
        return result;
      }
      v42 = 52i64;
    }
    else
    {
      v41 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_73;
      v42 = 51i64;
    }
    WPP_SF_(*((_QWORD *)v41 + 2), v42, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    goto LABEL_73;
  }
LABEL_14:
  CSessionCacheManager::AcquireCacheTableLock(v15, *(const unsigned __int16 **)(*((_QWORD *)v4 + 165) + 368i64), 0i64);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)v4 + 165) + 72i64), 1u);
  v24 = (struct CSessionCacheClientItem *)*((_QWORD *)v4 + 165);
  if ( *((unsigned __int16 *)v24 + 119) <= 0x20u )
  {
    v5 = *((unsigned __int16 *)v24 + 119);
    memcpy_0(Buf1, (char *)v24 + 240, *((unsigned __int16 *)v24 + 119));
  }
  if ( !*((_QWORD *)v24 + 2) )
  {
LABEL_17:
    *((_DWORD *)v24 + 42) = *((_DWORD *)v4 + 16);
    if ( (_DWORD)v8 )
    {
      v25 = *((_QWORD *)v4 + 165);
      *(_WORD *)(v25 + 238) = v8;
      if ( v9 )
        memcpy_0((void *)(v25 + 240), v9, v8);
    }
    v26 = 0;
    goto LABEL_21;
  }
  if ( v5 && v5 == (_DWORD)v8 && !memcmp_0(Buf1, v9, v8) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 53i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    v35 = *((_QWORD *)v4 + 15);
    v26 = 1;
    if ( v35 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
    {
      *(_WORD *)(v35 + 64) |= 1u;
      *(_DWORD *)(v35 + 24) = 1;
    }
  }
  else
  {
    v33 = *((_QWORD *)v4 + 17);
    if ( (v33 & 0xC00000) == 0 )
    {
      v36 = CSessionCacheManager::m_pSessionCacheManager;
      *((_BYTE *)v24 + 236) = 0;
      v23 = CSessionCacheClientItem::CloneCacheElement(*((CSessionCacheClientItem **)v4 + 165), v36, &v44);
      RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 165) + 72i64));
      if ( v23 )
      {
        CSessionCacheManager::ReleaseCacheTableLock(
          v37,
          *(const unsigned __int16 **)(*((_QWORD *)v4 + 165) + 368i64),
          0i64);
        return v23;
      }
      v24 = v44;
      RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)v44 + 72), 1u);
      *((_QWORD *)v4 + 165) = v24;
      *((_QWORD *)v4 + 11) = v24;
      goto LABEL_17;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 54i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
      v33 = *((_QWORD *)v4 + 17);
    }
    *((_QWORD *)v4 + 17) = v33 | 0x1000000;
    v26 = 1;
    if ( (_DWORD)v8 )
    {
      *((_WORD *)v4 + 490) = v8;
      if ( v9 )
        memcpy_0((char *)v4 + 982, v9, v8);
    }
    v34 = *((_QWORD *)v4 + 15);
    if ( v34 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
    {
      *(_DWORD *)(v34 + 24) = 1;
      *(_WORD *)(v34 + 64) |= 2u;
    }
  }
LABEL_21:
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)v4 + 165) + 72i64));
  CSessionCacheManager::ReleaseCacheTableLock(v27, *(const unsigned __int16 **)(*((_QWORD *)v4 + 165) + 368i64), 0i64);
  v23 = CCipherMill::SetServerHelloCipher(v28, v4, v43);
  if ( v23 )
  {
    v39 = 40;
    v38 = 107;
    this = v4;
LABEL_81:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v38, v23, v39);
    return v23;
  }
  LOBYTE(v29) = (*((_DWORD *)v4 + 16) & 0x80800) != 0;
  result = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, __int64))(*(_QWORD *)v4 + 496i64))(v4, v29);
  if ( (_DWORD)result )
    return result;
  *((_BYTE *)v4 + 340) = 0;
  LOBYTE(v31) = 1;
  v23 = (*(__int64 (__fastcall **)(CSsl3TlsClientContext *, _QWORD, _QWORD, __int64))(*(_QWORD *)v4 + 504i64))(
          v4,
          *((_QWORD *)v4 + 110),
          *((unsigned int *)v4 + 218),
          v31);
  if ( *((_QWORD *)v4 + 110) )
  {
    (*(void (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)v4 + 16i64))(v4);
    *((_QWORD *)v4 + 110) = 0i64;
  }
  v32 = v45;
  *((_DWORD *)v4 + 218) = 0;
  *v32 = v26;
  return v23;
}
// 180005F4A: conditional instruction was optimized away because rsi.8!=0
// 180005BF4: variable 'v13' is possibly undefined
// 180005C1D: variable 'v17' is possibly undefined
// 180005C26: variable 'v16' is possibly undefined
// 180005C2F: variable 'v18' is possibly undefined
// 180005CC6: variable 'v15' is possibly undefined
// 180005D7F: variable 'v27' is possibly undefined
// 180005D8B: variable 'v28' is possibly undefined
// 180005DBB: variable 'v29' is possibly undefined
// 180005DF3: variable 'v31' is possibly undefined
// 18002DD70: variable 'v37' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18007D048: using guessed type void *CTlsExtClient::`vftable';
// 1800919A8: using guessed type int g_fAllowInsecureRenegoServers;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
