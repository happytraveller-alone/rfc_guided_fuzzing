// File count: 258
// Total lines: 40
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::DigestCcs(CSsl3TlsContext *this, unsigned __int8 *a2, int a3)
{
  __int64 v4; // rcx
  __int64 v5; // rax
  char v6; // al

  if ( a3 == 1 && *a2 == 1 )
  {
    *((_WORD *)this + 16) |= 0xAu;
    v4 = *((_QWORD *)this + 18);
    if ( v4 )
      SslFreeObject(v4, 0i64);
    v5 = *((_QWORD *)this + 20);
    *((_QWORD *)this + 20) = 0i64;
    *((_QWORD *)this + 18) = v5;
    v6 = *((_BYTE *)this + 233);
    if ( !v6 )
      *((_QWORD *)this + 22) = 0i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
      v6 = *((_BYTE *)this + 233);
    }
    if ( v6 )
    {
      ++*((_DWORD *)this + 48);
      *((_QWORD *)this + 26) = 0i64;
      *((_QWORD *)this + 25) = 0i64;
    }
    return 0i64;
  }
  else
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 904, -2146893018, 0xAu);
    return 2148074278i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
