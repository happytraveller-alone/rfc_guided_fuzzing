//----- (00000001800276A4) ----------------------------------------------------
ULONG SslInitSystemMapper(void)
{
  int v0; // ebx
  int v1; // eax
  ULONG v2; // edi
  struct _TOKEN_GROUPS *v3; // rax
  enum _NT_PRODUCT_TYPE ProductType; // [rsp+20h] [rbp-29h] BYREF
  ULONG SecurityMode; // [rsp+24h] [rbp-25h] BYREF
  struct _STRING DestinationString; // [rsp+28h] [rbp-21h] BYREF
  struct _SID_IDENTIFIER_AUTHORITY IdentifierAuthority; // [rsp+38h] [rbp-11h] BYREF
  char Sid[80]; // [rsp+40h] [rbp-9h] BYREF

  v0 = 0;
  if ( !SslLogonHandle )
  {
    v1 = LsaRegisterLogonProcess((PLSA_STRING)&SslPackageNameA, &SslLogonHandle, &SecurityMode);
    if ( v1 < 0 )
      return RtlNtStatusToDosError(v1);
  }
  RtlInitString(&DestinationString, "Kerberos");
  v1 = LsaLookupAuthenticationPackage(SslLogonHandle, (PLSA_STRING)&DestinationString, &SslKerberosPackageId);
  if ( v1 < 0 )
    return RtlNtStatusToDosError(v1);
  RtlInitString(&DestinationString, "MICROSOFT_AUTHENTICATION_PACKAGE_V1_0");
  v1 = LsaLookupAuthenticationPackage(SslLogonHandle, (PLSA_STRING)&DestinationString, &SslMsvPackageId);
  if ( v1 < 0 )
    return RtlNtStatusToDosError(v1);
  if ( !SslPackageSid )
  {
    *(_DWORD *)IdentifierAuthority.Value = 0;
    *(_WORD *)&IdentifierAuthority.Value[4] = 1280;
    RtlInitializeSid(Sid, &IdentifierAuthority, 2u);
    *RtlSubAuthoritySid(Sid, 0) = 64;
    *RtlSubAuthoritySid(Sid, 1u) = 14;
    v2 = RtlLengthSid(Sid);
    v3 = (struct _TOKEN_GROUPS *)LocalAlloc(0x40u, v2 + 24i64);
    SslPackageSid = v3;
    if ( !v3 )
      return 14;
    v3->GroupCount = 1;
    v3->Groups[0].Sid = &v3[1];
    v3->Groups[0].Attributes = 7;
    RtlCopySid(v2, &v3[1], Sid);
  }
  g_SslS4U2SelfInitialized = 1;
  if ( RtlGetNtProductType(&ProductType) )
    LOBYTE(v0) = ProductType == NtProductLanManNt;
  else
    v0 = 1;
  fUseLocalMapping = v0;
  return 0;
}
// 1800919A0: using guessed type int fUseLocalMapping;
// 180092784: using guessed type int g_SslS4U2SelfInitialized;

