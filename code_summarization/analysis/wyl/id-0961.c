//----- (000000018004FE10) ----------------------------------------------------
__int64 __fastcall SpGetContextToken(__int64 a1, _QWORD *a2)
{
  struct CSslUserContext *UserContext; // rax
  struct CSslUserContext *v5; // rcx
  __int64 result; // rax
  __int64 v7; // rax
  unsigned int v8; // ecx

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  UserContext = SslFindUserContext(a1);
  v5 = UserContext;
  if ( !UserContext )
    return 2148074241i64;
  v7 = *((_QWORD *)UserContext + 33);
  if ( v7 )
  {
    *a2 = v7;
    return 0i64;
  }
  else
  {
    v8 = *((_DWORD *)v5 + 68);
    result = 2148074251i64;
    if ( v8 )
      return v8;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

