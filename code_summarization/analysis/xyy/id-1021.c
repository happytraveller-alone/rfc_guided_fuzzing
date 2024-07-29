//----- (0000000180055510) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::CheckForCredentialRenewal(CCredentialGroup *this)
{
  unsigned int v3; // edi
  unsigned int v4; // eax

  if ( (*((_DWORD *)this + 38) & 0x40051555) == 0 )
    return 0i64;
  RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
  v3 = 0;
  if ( (*((_BYTE *)this + 156) & 0x40) != 0 )
  {
    if ( *((_QWORD *)this + 100) )
      v4 = CCredentialGroup::RenewImplicitCertificates((void **)this);
    else
      v4 = CCredentialGroup::RenewLocalStoreCertificates(this);
    if ( !v4 )
      *((_DWORD *)this + 39) &= ~0x40u;
    v3 = v4;
  }
  RtlReleaseResource((PRTL_RESOURCE)((char *)this + 48));
  return v3;
}

