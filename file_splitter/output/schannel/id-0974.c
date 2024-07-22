//----- (0000000180051690) ----------------------------------------------------
__int64 __fastcall SetAppMtuCallback(__int64 a1, char a2, struct _SecBuffer *a3)
{
  struct CSslUserContext *UserContext; // rax
  unsigned int v8; // ebx

  if ( !(unsigned int)SchannelInit(1) || !a3 )
    return 2148074244i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 58i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  if ( a3->cbBuffer == 12 )
    UserContext = SslFindUserContextEx((union _LARGE_INTEGER *)a3->pvBuffer);
  else
    UserContext = SslFindUserContext(a1);
  if ( UserContext )
  {
    v8 = SetMtuCallback(UserContext, a2, a3);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
    return v8;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
    return 2148074241i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

