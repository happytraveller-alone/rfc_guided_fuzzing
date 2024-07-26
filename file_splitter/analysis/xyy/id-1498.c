//----- (0000000180078520) ----------------------------------------------------
unsigned int __fastcall CTls13ExtClient::ParseStatusRequestExtension(
        CTls13ExtClient *this,
        unsigned __int8 *a2,
        unsigned __int16 a3,
        __int64 a4)
{
  __int64 v4; // rax
  __int64 v6; // rcx

  v4 = *((_QWORD *)this + 1);
  v6 = *(_QWORD *)(v4 + 8);
  if ( !v6 )
    return -2146893052;
  if ( *(_DWORD *)(v6 + 48) == 4 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_5635b40337ae3cd6626e599d778a0aa6_Traceguids);
      v4 = *((_QWORD *)this + 1);
    }
    LOBYTE(a4) = 10;
    CSslContext::SetErrorAndFatalAlert(v4, 200i64, 2148074278i64, a4);
    return -2146893018;
  }
  else
  {
    *(_QWORD *)(v4 + 136) |= 0x20000ui64;
    return CSsl3TlsClientContext::DigestCertificateStatus(*((CSsl3TlsClientContext **)this + 8), a2, a3);
  }
}
// 18007858D: variable 'a4' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 18005B470: using guessed type __int64 __fastcall CSslContext::SetErrorAndFatalAlert(_QWORD, _QWORD, _QWORD, _QWORD);

