//----- (000000018007075C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetSrtpProtectionProfiles(
        CSsl3TlsContext *this,
        struct _SEC_SRTP_PROTECTION_PROFILES *const a2)
{
  void *v2; // rdi
  __int64 ProfilesSize; // rbp
  void *v6; // rax

  v2 = 0i64;
  if ( a2 )
  {
    ProfilesSize = a2->ProfilesSize;
    v6 = (void *)(*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(
                   this,
                   ProfilesSize + 2);
    v2 = v6;
    if ( !v6 )
      return 14i64;
    memcpy_0(v6, a2, ProfilesSize + 2);
  }
  if ( *((_QWORD *)this + 100) )
    (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
  *((_QWORD *)this + 100) = v2;
  return 0i64;
}

