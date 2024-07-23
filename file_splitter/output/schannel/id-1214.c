// File count: 1214
// Total lines: 30
----------------------------------------
__int64 __fastcall CSsl3TlsClientContext::DigestServerHelloVerifyRequest(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  unsigned __int8 v4; // r9
  unsigned int v5; // ecx

  if ( (*(_DWORD *)(*((_QWORD *)this + 10) + 152i64) & 0xA0000) == 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 50i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    v4 = 10;
    goto LABEL_14;
  }
  if ( a3 < 3 || *a2 != 0xFE || (a2[1] | (*a2 << 8)) > 0xFEFFu || (v5 = a2[2], a3 < v5 + 3) )
  {
    v4 = 50;
LABEL_14:
    CSslContext::SetErrorAndFatalAlert((__int64)this, 90, -2146893018, v4);
    return 2148074278i64;
  }
  *((_BYTE *)this + 1312) = v5;
  *((_DWORD *)this + 327) = 1;
  if ( (_BYTE)v5 )
    memcpy_0((char *)this + 1052, a2 + 3, v5);
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
