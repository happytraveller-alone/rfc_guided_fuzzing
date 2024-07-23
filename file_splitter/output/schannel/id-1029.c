// File count: 1029
// Total lines: 18
----------------------------------------
__int64 __fastcall CCredentialGroup::GetNameFromFirstCred(CCredentialGroup *this, unsigned __int16 **a2)
{
  struct _RTL_RESOURCE *v5; // rbx
  NTSTATUS NameFromCertificate; // edi
  int v7; // [rsp+30h] [rbp+8h] BYREF

  if ( !*((_DWORD *)this + 7) )
    return 2148074254i64;
  v5 = (struct _RTL_RESOURCE *)((char *)this + 48);
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
  NameFromCertificate = SslGetNameFromCertificate(*(PCCERT_CONTEXT *)(*((_QWORD *)this + 4) + 24i64), a2, &v7);
  RtlReleaseResource(v5);
  if ( NameFromCertificate >= 0 )
    return 0i64;
  else
    return SspNtStatusToSecStatus(NameFromCertificate);
}
