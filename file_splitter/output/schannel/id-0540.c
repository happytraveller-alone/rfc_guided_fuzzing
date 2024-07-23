// File count: 540
// Total lines: 54
-----------------------------------------
__int64 __fastcall SpInitialize(unsigned __int64 *a1, __int64 a2, __int64 a3)
{
  int v5; // eax
  const unsigned __int16 *v6; // rdx
  const unsigned __int16 *v7; // rcx
  struct _GUID *v8; // r8
  const unsigned __int16 *v9; // r9

  if ( SpInitialized )
  {
    qword_180092630 = (__int64)a1;
  }
  else
  {
    LsaTable = a3;
    *(_QWORD *)SslTokenSource.SourceName = 0x6C656E6E61686353i64;
    AllocateLocallyUniqueId(&SslTokenSource.SourceIdentifier);
    SslDuplicateString(&SslDomainName, (struct _UNICODE_STRING *)(a2 + 24));
    SslDuplicateString(&SslGlobalDnsDomainName, (struct _UNICODE_STRING *)(a2 + 40));
    RtlInitUnicodeString(&SslPackageName, L"Schannel");
    RtlInitUnicodeString(&SslLegacyPackageName, L"Microsoft Unified Security Protocol Provider");
    bDomainJoined = (*(_DWORD *)(a2 + 4) & 0x10) == 0;
    RtlInitString(&SslPackageNameA, "Schannel");
    RtlInitializeResource(&SslGlobalLock);
    v5 = LsaIRegisterPolicyChangeNotificationCallback(SslDomainChangeCallback, 4i64);
    if ( v5 < 0 )
    {
      v6 = (const unsigned __int16 *)&WPP_GLOBAL_Control;
      v7 = (const unsigned __int16 *)WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          92i64,
          &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
          (unsigned int)v5);
    }
    InitDebugTracingEx(v7, v6, v8, v9);
    SpInitialized = 1;
    g_dwPackageId = a1;
  }
  return 0i64;
}
// 180027464: variable 'v7' is possibly undefined
// 180027464: variable 'v6' is possibly undefined
// 180027464: variable 'v8' is possibly undefined
// 180027464: variable 'v9' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
// 180092628: using guessed type unsigned __int64 near *g_dwPackageId;
// 180092630: using guessed type __int64 qword_180092630;
// 180092648: using guessed type int bDomainJoined;
// 180092780: using guessed type int SpInitialized;
// 180098218: using guessed type __int64 __fastcall LsaIRegisterPolicyChangeNotificationCallback(_QWORD, _QWORD);
