// File count: 291
// Total lines: 59
-----------------------------------------
__int64 __fastcall DownloadCertContextCallback(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // ebp
  CCipherMill *v8; // rcx
  unsigned __int16 v9; // dx
  int v10; // [rsp+20h] [rbp-28h]
  struct _CERT_CONTEXT *ppvContext; // [rsp+30h] [rbp-18h] BYREF

  if ( !(unsigned int)SchannelInit(1) )
  {
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return 2148074244i64;
    v9 = 50;
    goto LABEL_22;
  }
  if ( !a3 || !a4 )
  {
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) == 0 )
      return 2148074244i64;
    v9 = 51;
LABEL_22:
    v10 = -2146893052;
    WPP_SF_DD(*((_QWORD *)v8 + 2), v9, (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, -2146893052, v10);
    return 2148074244i64;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 52i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  v6 = DeserializeCertContext((const struct _CERT_CONTEXT **)&ppvContext, *(unsigned __int8 **)(a3 + 8), *(_DWORD *)a3);
  *(_DWORD *)a4 = *(_DWORD *)a3;
  SPExternalFree(*(void **)(a3 + 8));
  *(_QWORD *)(a3 + 8) = 0i64;
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  if ( v6 < 0 )
  {
    *(_DWORD *)(a4 + 4) = 0;
    *(_DWORD *)a4 = 0;
    *(_QWORD *)(a4 + 8) = 0i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        53i64,
        &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids,
        (unsigned int)v6);
    return (unsigned int)v6;
  }
  else
  {
    **(_QWORD **)(a4 + 8) = ppvContext;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 54i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
    return 0i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
