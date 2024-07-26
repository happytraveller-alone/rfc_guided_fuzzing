//----- (00000001800617E0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::SetSrtpMasterKeyIdentifier(
        CSsl3TlsClientContext *this,
        struct _SEC_SRTP_MASTER_KEY_IDENTIFIER *const a2)
{
  void *v2; // rdi
  __int64 MasterKeyIdentifierSize; // rbp
  void *v6; // rax

  v2 = 0i64;
  if ( a2 )
  {
    MasterKeyIdentifierSize = a2->MasterKeyIdentifierSize;
    v6 = (void *)(*(__int64 (__fastcall **)(CSsl3TlsClientContext *, __int64))(*(_QWORD *)this + 8i64))(
                   this,
                   MasterKeyIdentifierSize + 1);
    v2 = v6;
    if ( !v6 )
      return 14i64;
    memcpy_0(v6, a2, MasterKeyIdentifierSize + 1);
  }
  if ( *((_QWORD *)this + 167) )
    (*(void (__fastcall **)(CSsl3TlsClientContext *))(*(_QWORD *)this + 16i64))(this);
  *((_QWORD *)this + 167) = v2;
  return 0i64;
}

