//----- (000000018000A498) ----------------------------------------------------
_BOOL8 __fastcall IsIpAddress(PCWSTR AddressString)
{
  USHORT Port[2]; // [rsp+20h] [rbp-A8h] BYREF
  ULONG ScopeId[3]; // [rsp+24h] [rbp-A4h] BYREF
  char v5[4]; // [rsp+30h] [rbp-98h] BYREF
  struct in_addr Address; // [rsp+34h] [rbp-94h] BYREF
  struct in6_addr v7; // [rsp+38h] [rbp-90h] BYREF

  memset_0(v5, 0, 0x80ui64);
  return RtlIpv4StringToAddressExW(AddressString, 1u, &Address, Port) >= 0
      || RtlIpv6StringToAddressExW(AddressString, &v7, ScopeId, Port) >= 0;
}
// 18000A498: using guessed type char var_98[4];
// 18000A498: using guessed type ULONG ScopeId[3];

