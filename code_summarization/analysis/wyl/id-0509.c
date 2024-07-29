//----- (000000018002518C) ----------------------------------------------------
__int64 __fastcall SslReadRegOptions(int a1)
{
  LSTATUS v2; // eax
  HKEY v3; // rdx
  BOOL v4; // ebx
  __int64 v5; // r15
  __int64 v6; // r12
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // edi
  LPCWSTR *v15; // r14
  LSTATUS v16; // eax
  HKEY v17; // rcx
  char *v18; // rdi
  int v19; // esi
  int v20; // eax
  const CHAR *v21; // rdx
  LSTATUS v22; // eax
  HKEY v23; // rcx
  char *v24; // rdi
  __int64 v25; // rsi
  int v26; // r14d
  int v27; // eax
  const CHAR *v28; // rdx
  LSTATUS v29; // eax
  HKEY v30; // rcx
  char *v31; // rdi
  int *v32; // rsi
  int v33; // r13d
  int v34; // edx
  char v36; // al
  CCipherMill *v37; // rcx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  DWORD Type; // [rsp+30h] [rbp-28h] BYREF
  HKEY phkResult; // [rsp+38h] [rbp-20h] BYREF
  HKEY v43; // [rsp+40h] [rbp-18h] BYREF
  HKEY hKey; // [rsp+48h] [rbp-10h] BYREF
  unsigned int v46; // [rsp+A8h] [rbp+50h] BYREF
  int Data; // [rsp+B0h] [rbp+58h] BYREF
  DWORD cbData; // [rsp+B8h] [rbp+60h] BYREF

  phkResult = 0i64;
  v46 = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
  v2 = RegOpenKeyExW(
         HKEY_LOCAL_MACHINE,
         L"System\\CurrentControlSet\\Control\\SecurityProviders\\Schannel",
         0,
         0x2001Bu,
         &hKey);
  v3 = hKey;
  if ( v2 )
    v3 = 0i64;
  hKey = v3;
  v4 = ReadRegistrySetting(::hKey, v3, L"EventLogging", (BYTE *)&g_dwEventLogging, 1u) != 0;
  if ( (unsigned int)ReadRegistrySetting(::hKey, 0i64, L"LogLevel", (BYTE *)&SchannelInfoLevel, 0) )
    v4 = 1;
  ReadRegistrySetting(::hKey, 0i64, L"ManualCredValidation", (BYTE *)&v46, 0);
  if ( (v46 != 0) != g_fManualCredValidation )
  {
    v4 = 1;
    g_fManualCredValidation = v46 != 0;
  }
  if ( (unsigned int)ReadRegistrySetting(
                       ::hKey,
                       0i64,
                       L"ClientCacheTime",
                       (BYTE *)&CSslGlobals::m_dwClientLifespan,
                       0x2255100u) )
    v4 = 1;
  if ( (unsigned int)ReadRegistrySetting(
                       ::hKey,
                       0i64,
                       L"ServerCacheTime",
                       (BYTE *)&CSslGlobals::m_dwServerLifespan,
                       0x2255100u) )
    v4 = 1;
  if ( (unsigned int)ReadRegistrySetting(
                       ::hKey,
                       0i64,
                       L"SessionTicketTime",
                       (BYTE *)&CSslGlobals::m_dwSessionTicketLifespan,
                       0x2255100u) )
    v4 = 1;
  if ( (unsigned int)ReadRegistrySetting(
                       ::hKey,
                       0i64,
                       L"SessionTicketTimeSkew",
                       (BYTE *)&CSslGlobals::m_dwSessionTicketTimeSkew,
                       0x493E0u) )
    v4 = 1;
  ReadRegistrySetting(::hKey, 0i64, L"DisableRenegoOnClient", (BYTE *)&v46, 0);
  CSslGlobals::m_fDisableRenegoOnClient = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"DisableRenegoOnServer", (BYTE *)&v46, 0);
  CSslGlobals::m_fDisableRenegoOnServer = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"MaximumCacheSize", (BYTE *)&CSslGlobals::m_dwMaximumEntries, 0x4E20u);
  ReadRegistrySetting(::hKey, 0i64, L"IgnoreExponentOfOne", (BYTE *)&v46, 0);
  if ( (v46 != 0) != g_fIgnoreExponentOfOne )
  {
    v4 = 1;
    g_fIgnoreExponentOfOne = v46 != 0;
  }
  ReadRegistrySetting(::hKey, 0i64, L"SendTrustedIssuerList", (BYTE *)&v46, 0);
  if ( (v46 != 0) != g_fSendIssuerList )
  {
    v4 = 1;
    g_fSendIssuerList = v46 != 0;
  }
  v5 = 14i64;
  v6 = 8i64;
  if ( (unsigned int)ReadRegistrySetting(
                       ::hKey,
                       0i64,
                       L"CertificateMappingMethods",
                       (BYTE *)&g_dwCertMappingMethods,
                       0x1Fu) )
  {
    v36 = g_dwCertMappingMethods;
    v4 = 1;
    if ( (g_dwCertMappingMethods & 1) == 0 )
    {
      v37 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        goto LABEL_90;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
      v36 = g_dwCertMappingMethods;
    }
    v37 = WPP_GLOBAL_Control;
LABEL_90:
    if ( (v36 & 2) == 0 && v37 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v37 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v37 + 2), 14i64, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
      v37 = WPP_GLOBAL_Control;
      v36 = g_dwCertMappingMethods;
    }
    if ( (v36 & 4) == 0 && v37 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v37 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v37 + 2), 15i64, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
      v37 = WPP_GLOBAL_Control;
      v36 = g_dwCertMappingMethods;
    }
    if ( (v36 & 8) == 0 && v37 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v37 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v37 + 2), 16i64, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
      v37 = WPP_GLOBAL_Control;
      v36 = g_dwCertMappingMethods;
    }
    if ( (v36 & 0x10) == 0 && v37 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v37 + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)v37 + 2), 17i64, &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids);
  }
  if ( hKey )
  {
    RegCloseKey(hKey);
    hKey = 0i64;
  }
  ReadRegistrySetting(::hKey, 0i64, L"IssuerCacheTime", (BYTE *)&dword_1800926F8, 0x927C0u);
  ReadRegistrySetting(::hKey, 0i64, L"IssuerCacheSize", (BYTE *)&dword_180092700, 0x64u);
  v7 = dword_1800926FC;
  if ( a1 )
    v7 = dword_180092700;
  dword_1800926FC = v7;
  ReadRegistrySetting(
    ::hKey,
    0i64,
    L"MaxEncryptedRecordsBeforeKeyUpdate",
    (BYTE *)&CSslGlobals::m_dwMaxEncryptedRecords,
    0x16A09E6u);
  v8 = CSslGlobals::m_dwMaxEncryptedRecords;
  if ( CSslGlobals::m_dwMaxEncryptedRecords > 0x16A09E6 )
    v8 = 23726566;
  CSslGlobals::m_dwMaxEncryptedRecords = v8;
  ReadRegistrySetting(::hKey, 0i64, L"AllowInsecureRenegoClients", (BYTE *)&v46, 1u);
  g_fAllowInsecureRenegoClients = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"AllowInsecureRenegoServers", (BYTE *)&v46, 1u);
  g_fAllowInsecureRenegoServers = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"EnableOcspStaplingForSni", (BYTE *)&v46, 0);
  g_fEnableOcspForSni = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"DisableOcspStapling", (BYTE *)&v46, 0);
  g_fDisableOcsp = v46 != 0;
  if ( a1 )
    ReadOcspReadDirectoryRegistrySetting(::hKey);
  ReadRegistrySetting(::hKey, 0i64, L"ClientAuthTrustMode", (BYTE *)&v46, 0);
  v9 = g_eClientAuthMode;
  if ( v46 < 3 )
    v9 = v46;
  g_eClientAuthMode = v9;
  if ( (unsigned int)ReadRegistrySetting(
                       ::hKey,
                       0i64,
                       L"CleanupPeriod",
                       (BYTE *)&CSslGlobals::m_dwCleanupIntervalInSeconds,
                       0x12Cu) )
  {
    CSslGlobals::CleanupPeriodicCleanupHandler();
    CSslGlobals::InitializePeriodicCleanupHandler();
  }
  ReadRegistrySetting(::hKey, 0i64, L"SendExtraRecord", (BYTE *)&v46, 0);
  v10 = v46;
  if ( v46 - 1 > 1 )
    v10 = 0;
  CSslGlobals::m_bSendAuxRecord = v10;
  ReadRegistrySetting(::hKey, 0i64, L"EnableConfigChangeNotification", (BYTE *)&v46, 0);
  g_fEnableConfigChangeNtf = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"HelloVerifyRequestEnabled", (BYTE *)&v46, 1u);
  g_fEnableHelloVerifyRequest = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"HelloRetryRequestEnabled", (BYTE *)&v46, 0);
  g_fEnableHelloRetryRequest = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"EnableSessionTicket", (BYTE *)&v46, 0);
  v11 = v46;
  if ( v46 - 1 > 1 )
    v11 = 0;
  CSslGlobals::m_dwEnableSessionTicket = v11;
  WinSqmSetDWORD(0i64, 12709i64);
  ReadRegistrySetting(::hKey, 0i64, L"DisableClientExtendedMasterSecret", (BYTE *)&v46, 0);
  CSslGlobals::m_fDisableClientExtendedMS = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"DisableServerExtendedMasterSecret", (BYTE *)&v46, 0);
  CSslGlobals::m_fDisableServerExtendedMS = v46 != 0;
  ReadRegistrySetting(::hKey, 0i64, L"MachineID", (BYTE *)&v46, 0xFFFFFFFF);
  v12 = _byteswap_ulong(v46);
  v46 = v12;
  if ( v12 != g_SslMachineID )
  {
    g_SslMachineID = v12;
    v4 = 1;
  }
  v13 = 1074741184;
  v14 = 48;
  if ( RegOpenKeyExW(::hKey, L"Protocols", 0, 0x20019u, &phkResult) )
  {
    CSslGlobals::m_ProtEnabled = 1074741184;
  }
  else
  {
    v15 = (LPCWSTR *)&unk_18007F098;
    do
    {
      if ( !RegOpenKeyExW(phkResult, *(v15 - 1), 0, 0x20019u, &v43) )
      {
        cbData = 4;
        if ( !RegQueryValueExW(v43, L"Enabled", 0i64, &Type, (LPBYTE)&Data, &cbData) )
        {
          v38 = *(_DWORD *)v15;
          if ( Data )
            v13 |= v38;
          else
            v13 &= ~v38;
        }
        cbData = 4;
        if ( !RegQueryValueExW(v43, L"DisabledByDefault", 0i64, &Type, (LPBYTE)&Data, &cbData) )
        {
          v39 = *(_DWORD *)v15;
          if ( Data )
            v14 |= v39;
          else
            v14 &= ~v39;
        }
        RegCloseKey(v43);
      }
      v15 += 2;
      --v5;
    }
    while ( v5 );
    RegCloseKey(phkResult);
    if ( CSslGlobals::m_ProtEnabled != v13 )
    {
      CSslGlobals::m_ProtEnabled = v13;
      v4 = 1;
    }
    if ( CSslGlobals::m_ProtDisabledByDefault == v14 )
      goto LABEL_48;
    v4 = 1;
  }
  CSslGlobals::m_ProtDisabledByDefault = v14;
LABEL_48:
  v16 = RegOpenKeyExW(::hKey, L"Ciphers", 0, 0x20019u, &phkResult);
  v17 = phkResult;
  v18 = (char *)&unk_1800910E4;
  if ( v16 )
    v17 = 0i64;
  phkResult = v17;
  do
  {
    v19 = *((_DWORD *)v18 - 1);
    v20 = *(_DWORD *)v18;
    *((_DWORD *)v18 - 1) = *(_DWORD *)v18;
    if ( v17 )
    {
      v21 = *(const CHAR **)(v18 + 12);
      Data = v20;
      if ( !RegOpenKeyExA(v17, v21, 0, 0x20019u, &v43) )
      {
        cbData = 4;
        if ( RegQueryValueExW(v43, L"Enabled", 0i64, &Type, (LPBYTE)&Data, &cbData) )
          Data = *(_DWORD *)v18;
        RegCloseKey(v43);
      }
      v20 = Data & *((_DWORD *)v18 + 1);
      v17 = phkResult;
      *((_DWORD *)v18 - 1) = v20;
    }
    if ( v20 != v19 )
      v4 = 1;
    v18 += 56;
    --v6;
  }
  while ( v6 );
  if ( v17 )
    RegCloseKey(v17);
  v22 = RegOpenKeyExW(::hKey, L"Hashes", 0, 0x20019u, &phkResult);
  v23 = phkResult;
  v24 = (char *)&g_AvailableHashes;
  v25 = 5i64;
  if ( v22 )
    v23 = 0i64;
  phkResult = v23;
  do
  {
    v26 = *(_DWORD *)v24;
    v27 = *((_DWORD *)v24 + 1);
    *(_DWORD *)v24 = v27;
    if ( v23 )
    {
      v28 = (const CHAR *)*((_QWORD *)v24 + 1);
      Data = v27;
      if ( !RegOpenKeyExA(v23, v28, 0, 0x20019u, &v43) )
      {
        cbData = 4;
        if ( RegQueryValueExW(v43, L"Enabled", 0i64, &Type, (LPBYTE)&Data, &cbData) )
          Data = *((_DWORD *)v24 + 1);
        RegCloseKey(v43);
      }
      v27 = Data & *(_DWORD *)v24;
      v23 = phkResult;
      *(_DWORD *)v24 = v27;
    }
    if ( v26 != v27 )
      v4 = 1;
    v24 += 40;
    --v25;
  }
  while ( v25 );
  if ( v23 )
    RegCloseKey(v23);
  v29 = RegOpenKeyExW(::hKey, L"KeyExchangeAlgorithms", 0, 0x20019u, &phkResult);
  v30 = phkResult;
  v31 = (char *)&unk_1800914C8;
  if ( v29 )
    v30 = 0i64;
  phkResult = v30;
  do
  {
    v32 = (int *)(v31 + 40);
    v33 = *((_DWORD *)v31 - 1);
    v34 = *(_DWORD *)v31;
    *((_DWORD *)v31 + 6) = *((_DWORD *)v31 + 7);
    *((_DWORD *)v31 + 8) = *((_DWORD *)v31 + 9);
    *((_DWORD *)v31 + 10) = *((_DWORD *)v31 + 11);
    *((_DWORD *)v31 + 12) = *((_DWORD *)v31 + 13);
    *((_DWORD *)v31 - 1) = v34;
    if ( !v30 )
      goto LABEL_76;
    Data = v34;
    if ( !RegOpenKeyExA(v30, *((LPCSTR *)v31 + 1), 0, 0x20019u, &v43) )
    {
      ReadRegistrySetting(v43, 0i64, L"Enabled", (BYTE *)&Data, *(_DWORD *)v31);
      ReadRegistrySetting(v43, 0i64, L"ClientMinKeyBitLength", (BYTE *)v31 + 24, *((_DWORD *)v31 + 7));
      ReadRegistrySetting(v43, 0i64, L"ClientMaxKeyBitLength", (BYTE *)v31 + 32, *((_DWORD *)v31 + 9));
      ReadRegistrySetting(v43, 0i64, L"ServerMinKeyBitLength", (BYTE *)v31 + 40, *((_DWORD *)v31 + 11));
      if ( *((_DWORD *)v31 - 2) == 43522 )
      {
        v40 = 1024;
        if ( (unsigned int)*v32 > 0x400 )
        {
          v40 = 2048;
          if ( (unsigned int)*v32 > 0x800 )
          {
            v40 = 4096;
            if ( (unsigned int)*v32 <= 0xC00 )
              v40 = 3072;
          }
        }
        *v32 = v40;
      }
      else if ( *((_DWORD *)v31 - 2) != 44550 )
      {
LABEL_132:
        RegCloseKey(v43);
        goto LABEL_75;
      }
      ReadRegistrySetting(v43, 0i64, L"EphemKeyReuseTime", (BYTE *)v31 + 48, *((_DWORD *)v31 + 13));
      goto LABEL_132;
    }
LABEL_75:
    *((_DWORD *)v31 - 1) &= Data;
    v34 = *((_DWORD *)v31 - 1);
    v30 = phkResult;
LABEL_76:
    if ( v33 != v34 )
      v4 = 1;
    v31 += 64;
  }
  while ( v31 - 8 < SpTable );
  if ( v30 )
    RegCloseKey(v30);
  if ( !RegOpenKeyExW(::hKey, L"Messaging", 0, 0x20019u, &phkResult) )
  {
    ReadRegistrySetting(
      phkResult,
      0i64,
      L"MessageLimitClient",
      (BYTE *)&CSslGlobals::m_dwTlsMessageLimitClient,
      0x8000u);
    ReadRegistrySetting(phkResult, 0i64, L"MessageLimitServer", (BYTE *)&CSslGlobals::m_dwTlsMessageLimitSrv, 0x4000u);
    ReadRegistrySetting(
      phkResult,
      0i64,
      L"MessageLimitServerClientAuth",
      (BYTE *)&CSslGlobals::m_dwTlsMessageLimitSrvClientAuth,
      0x8000u);
    RegCloseKey(phkResult);
  }
  if ( !a1 && v4 && CSessionCacheManager::m_pSessionCacheManager )
    CSessionCacheManager::PurgeCacheEntries(CSessionCacheManager::m_pSessionCacheManager, 0x30000u, 0i64, 0, 0i64);
  return 1i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080E38: using guessed type __int64 __fastcall WinSqmSetDWORD(_QWORD, _QWORD);
// 1800919A4: using guessed type int g_fEnableHelloVerifyRequest;
// 1800919A8: using guessed type int g_fAllowInsecureRenegoServers;
// 1800919AC: using guessed type int g_fAllowInsecureRenegoClients;
// 1800919F4: using guessed type unsigned int g_SslMachineID;
// 1800919F8: using guessed type unsigned int CSslGlobals::m_ProtEnabled;
// 1800919FC: using guessed type unsigned int CSslGlobals::m_ProtDisabledByDefault;
// 1800926FC: using guessed type int dword_1800926FC;
// 18009278C: using guessed type int g_fEnableConfigChangeNtf;
// 1800927A0: using guessed type int g_fEnableHelloRetryRequest;
// 1800927A4: using guessed type int g_fDisableOcsp;
// 1800927A8: using guessed type int g_fEnableOcspForSni;
// 1800927B0: using guessed type unsigned int CSslGlobals::m_dwEnableSessionTicket;
// 1800927B4: using guessed type int CSslGlobals::m_fDisableServerExtendedMS;
// 1800927B8: using guessed type int CSslGlobals::m_fDisableClientExtendedMS;
// 1800927BC: using guessed type unsigned int CSslGlobals::m_bSendAuxRecord;
// 1800927C0: using guessed type int CSslGlobals::m_fDisableRenegoOnServer;
// 1800927C4: using guessed type int CSslGlobals::m_fDisableRenegoOnClient;
// 180092F04: using guessed type int g_fManualCredValidation;
// 180092F08: using guessed type int g_fSendIssuerList;
// 180092F1C: using guessed type int g_fIgnoreExponentOfOne;
