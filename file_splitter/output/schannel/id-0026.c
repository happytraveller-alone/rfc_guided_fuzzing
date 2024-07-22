//----- (0000000180002A9C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::DigestNewSessionTicket(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  CCipherMill *v6; // rcx
  unsigned int v7; // ebx
  HLOCAL v8; // rsi
  unsigned __int8 v10; // r9
  int v11; // edx
  __int64 v12; // [rsp+20h] [rbp-48h]

  v6 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 61i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    v6 = WPP_GLOBAL_Control;
  }
  if ( (*((_DWORD *)this + 34) & 0x400000) == 0 )
  {
    if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)v6 + 2), 62i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    v10 = 10;
    v11 = 1402;
    goto LABEL_21;
  }
  if ( a3 < 6 )
  {
    if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)v6 + 2), 63i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids, a3);
    CSslContext::SetErrorAndFatalAlert((__int64)this, 1400, -2146893018, 0x32u);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x40u,
        (__int64)&WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
        -2146893018,
        -2146893018);
    return 2148074278i64;
  }
  if ( a3 > 0x10005 )
  {
    if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)v6 + 2), 65i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids, a3);
    v10 = 50;
    v11 = 1400;
    goto LABEL_21;
  }
  v7 = a2[5] | (a2[4] << 8);
  if ( a3 - 6 != v7 )
  {
    v10 = 50;
    v11 = 1401;
LABEL_21:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v11, -2146893018, v10);
    return 2148074278i64;
  }
  v8 = SPExternalAlloc(v7);
  if ( !v8 )
    return 14i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 66i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids, v7);
  memcpy_0(v8, a2 + 6, v7);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64), 1u);
  CSessionCacheClientItem::SetSessionTicket(
    *((CSessionCacheClientItem **)this + 165),
    (unsigned __int8 *)v8,
    v7,
    0i64,
    0,
    0,
    0,
    0,
    0);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 165) + 72i64));
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    LODWORD(v12) = 0;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x43u,
      (__int64)&WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids,
      0,
      v12);
  }
  return 0i64;
}
// 18002C94B: variable 'v12' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

