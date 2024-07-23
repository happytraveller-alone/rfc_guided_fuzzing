// File count: 1043
// Total lines: 25
----------------------------------------
__int64 __fastcall CCredentialGroup::UpdateIssuerList(CCredentialGroup *this)
{
  struct _RTL_RESOURCE *v2; // rdi
  unsigned int v3; // ebx

  CSslCredManager::CheckForGpEventAndUpdateIssuersList(CSslCredManager::m_pCredManager);
  CCredentialGroup::CheckForCertificateStoreChange(this);
  if ( !*((_QWORD *)this + 108) || (*((_BYTE *)this + 156) & 0x10) != 0 )
  {
    v2 = (struct _RTL_RESOURCE *)((char *)this + 48);
    RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
    if ( !*((_QWORD *)this + 108) || (*((_BYTE *)this + 156) & 0x10) != 0 )
    {
      v3 = CCredentialGroup::ConstructIssuersList(this);
      if ( v3 )
      {
        RtlReleaseResource(v2);
        return v3;
      }
    }
    RtlReleaseResource(v2);
  }
  return 0i64;
}
