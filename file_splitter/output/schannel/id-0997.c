//----- (00000001800534DC) ----------------------------------------------------
__int64 __fastcall GetTokenUserSid(void *a1, unsigned __int8 *const a2)
{
  unsigned int v3; // ebx
  DWORD LengthSid; // eax
  DWORD ReturnLength[4]; // [rsp+30h] [rbp-88h] BYREF
  void *TokenInformation; // [rsp+40h] [rbp-78h] BYREF

  if ( a1 )
  {
    v3 = GetTokenInformation(a1, TokenUser, &TokenInformation, 0x54u, ReturnLength);
    if ( !v3 )
      return v3;
    LengthSid = GetLengthSid(TokenInformation);
    ReturnLength[0] = LengthSid;
    if ( LengthSid <= 0x44 )
    {
      memcpy_0(a2, TokenInformation, LengthSid);
      return v3;
    }
  }
  return 0i64;
}
// 1800534DC: using guessed type DWORD var_88[4];

