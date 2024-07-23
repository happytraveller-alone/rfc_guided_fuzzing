// File count: 492
// Total lines: 56
-----------------------------------------
__int64 LoadSslRegistryOptions(void)
{
  NTSTATUS v0; // eax
  CCipherMill *v1; // rcx

  qword_180092680 = (__int64)CreateEventW(0i64, 0, 0, 0i64);
  qword_180092698 = (__int64)SslWatchParamKey;
  qword_180092690 = (__int64)L"System\\CurrentControlSet\\Control\\SecurityProviders\\Schannel";
  qword_1800926A8 = (__int64)CreateEventW(0i64, 0, 0, 0i64);
  qword_1800926C0 = (__int64)FipsWatchParamKey;
  qword_1800926B8 = (__int64)L"System\\CurrentControlSet\\Control\\Lsa";
  qword_1800926D0 = (__int64)CreateEventW(0i64, 0, 0, 0i64);
  qword_1800926E8 = (__int64)UserMappingsWatchParamKey;
  qword_1800926E0 = (__int64)L"Software\\Policies\\Microsoft\\Cryptography\\Configuration\\SSL\\00010002";
  qword_180092658 = (__int64)CreateEventW(0i64, 0, 0, 0i64);
  qword_180092670 = (__int64)DefaultEccCurveWatchParamKey;
  qword_180092668 = (__int64)L"System\\CurrentControlSet\\Control\\Cryptography\\Configuration\\Local\\SSL\\00010002";
  SslWatchParamKey(g_BaseSslRegOptions);
  FipsWatchParamKey(g_FipsRegOptions, 1);
  UserMappingsWatchParamKey(&g_UserMappingRegOptions);
  DefaultEccCurveWatchParamKey(&g_DefaultEccCurveRegOptions, 1);
  v0 = BCryptRegisterConfigChangeNotify(&g_hBcryptEvent);
  if ( v0 < 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        10i64,
        &WPP_652d1bd98c7033c24f7b4105215d66be_Traceguids,
        (unsigned int)v0);
    return 0i64;
  }
  else
  {
    RtlRegisterWait(&g_hBcryptWait, g_hBcryptEvent, (WAITORTIMERCALLBACKFUNC)WatchBcryptEvent, 0i64, 0xFFFFFFFF, 0);
    CCipherMill::BuildCipherMill(v1);
    return 1i64;
  }
}
// 180023689: variable 'v1' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800817E0: using guessed type wchar_t aSystemCurrentc_1[37];
// 180092658: using guessed type __int64 qword_180092658;
// 180092668: using guessed type __int64 qword_180092668;
// 180092670: using guessed type __int64 qword_180092670;
// 180092680: using guessed type __int64 qword_180092680;
// 180092690: using guessed type __int64 qword_180092690;
// 180092698: using guessed type __int64 qword_180092698;
// 1800926A8: using guessed type __int64 qword_1800926A8;
// 1800926B8: using guessed type __int64 qword_1800926B8;
// 1800926C0: using guessed type __int64 qword_1800926C0;
// 1800926C8: using guessed type HKEY g_UserMappingRegOptions;
// 1800926D0: using guessed type __int64 qword_1800926D0;
// 1800926E0: using guessed type __int64 qword_1800926E0;
// 1800926E8: using guessed type __int64 qword_1800926E8;
