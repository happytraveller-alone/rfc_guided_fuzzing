// File count: 904
// Total lines: 79
-----------------------------------------
__int64 __fastcall SpCallPackage(
        __int64 a1,
        _DWORD *a2,
        unsigned __int64 a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  int v11; // esi
  int v12; // ebp
  void *v13; // rdx
  void **v14; // rcx
  void *v15; // r8
  __int64 v16; // r9
  CCipherMill *v17; // rcx
  __int64 v18; // rdx
  __int64 v19; // [rsp+40h] [rbp-28h] BYREF
  int v20; // [rsp+48h] [rbp-20h]

  if ( (*(unsigned __int8 (__fastcall **)(__int64 *))(LsaTable + 192))(&v19) )
  {
    v11 = v20 & 0x10;
    v12 = v20 & 0x200;
    if ( !a2 || a4 < 4 )
      return 3221225485i64;
    if ( (unsigned int)SchannelInit(0) )
    {
      switch ( *a2 )
      {
        case 2:
          return SslDoClientRequest(v14, a2, (size_t)v15, a4, a5, a6, a7);
        case 6:
          if ( v11 )
            return SslMapExternalCredential(v14, a2, v15, a4, a5, a6, a7);
          break;
        case 7:
          if ( !v11 )
          {
            if ( v12 )
              return SslMapEncodedCredential(v14, a2, v15, a4, a5, a6, a7);
            else
              return 3221225569i64;
          }
          break;
        case 4:
          return SslSessionCacheInfo(v14, (char *)a2, a3, a4, a5, a6, a7);
        case 3:
          return SslPurgeSessionCache(v14, (char *)a2, a3, a4, a5, a6, a7);
        case 8:
          return SslGetStreamSizes(v14, v13, v15, v16, a5, a6, a7);
      }
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074242i64;
      v18 = 14i64;
    }
    else
    {
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074242i64;
      v18 = 13i64;
    }
    WPP_SF_(*((_QWORD *)v17 + 2), v18, &WPP_6672ee5dd6af34547aa752f96a369f0c_Traceguids);
    return 2148074242i64;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_6672ee5dd6af34547aa752f96a369f0c_Traceguids);
  return 3221225701i64;
}
// 18004C7B6: variable 'v14' is possibly undefined
// 18004C7B6: variable 'v15' is possibly undefined
// 18004C8FD: variable 'v13' is possibly undefined
// 18004C8FD: variable 'v16' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
