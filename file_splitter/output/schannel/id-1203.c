// File count: 1203
// Total lines: 31
----------------------------------------
ULONG __fastcall CSslCredential::GetLocalClientKeyFromProvider(
        NCRYPT_KEY_HANDLE *this,
        struct _CRYPT_KEY_PROV_INFO *a2,
        __int64 a3)
{
  ULONG result; // eax
  unsigned int v6; // ebx
  int v7[6]; // [rsp+40h] [rbp-18h] BYREF
  int v8; // [rsp+78h] [rbp+20h] BYREF

  v8 = 0;
  v7[0] = 0;
  result = SslImpersonateClient(a3, &v8);
  if ( !result )
  {
    v6 = OpenKeyUsingCng(this + 13, a2->pwszContainerName, a2->pwszProvName, a2->dwKeySpec, a2->dwFlags, 0, v7);
    if ( v6 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_221bc911720835f3baa7a86739b227e3_Traceguids, v6);
      *((_DWORD *)this + 18) = 10002;
    }
    if ( v8 )
      RevertToSelf();
    return v6;
  }
  return result;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18005F780: using guessed type int var_18[6];
