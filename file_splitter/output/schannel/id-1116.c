// File count: 1116
// Total lines: 8
-----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::SetSrtpMasterKeyIdentifier(
        CSsl3TlsServerContext *this,
        struct _SEC_SRTP_MASTER_KEY_IDENTIFIER *const a2)
{
  *((_BYTE *)this + 988) = a2 != 0i64;
  return 0i64;
}
