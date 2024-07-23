// File count: 824
// Total lines: 33
-----------------------------------------
__int64 __fastcall SpSetCredentialsAttributes(
        struct CCredentialGroup *a1,
        int a2,
        struct _SecPkgCred_ClientCertPolicy *a3,
        unsigned int a4)
{
  __int64 v9; // [rsp+20h] [rbp-28h] BYREF
  int v10; // [rsp+28h] [rbp-20h]

  if ( !(*(unsigned __int8 (__fastcall **)(__int64 *))(LsaTable + 192))(&v9) )
    return 2148074244i64;
  if ( (v10 & 1) == 0 )
    return 2148074242i64;
  if ( !a3 || !a1 )
    return 2148074333i64;
  if ( (v10 & 0x10000) == 0 )
  {
    if ( a4 )
      goto LABEL_10;
    return 2148074333i64;
  }
  a4 = 0;
LABEL_10:
  if ( a2 != 96 )
    return 2148074242i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
  return SetClientCertPolicy(a1, a3, a4);
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
