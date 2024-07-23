// File count: 971
// Total lines: 35
-----------------------------------------
__int64 __fastcall GetAppAppDataStatusCallback(__int64 a1, char a2, __int64 a3, struct _SecBuffer *a4)
{
  union _LARGE_INTEGER *v8; // rcx
  struct CSslUserContext *UserContext; // rax
  void *(__stdcall *v10)(unsigned int); // rdx
  void (__stdcall *v11)(void *); // r8
  unsigned int AppDataStatusCallback; // ebx

  if ( !(unsigned int)SchannelInit(1) || !a3 || !a4 )
    return 2148074244i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 61i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
  v8 = *(union _LARGE_INTEGER **)(a3 + 8);
  if ( v8 && *(_DWORD *)a3 == 8 )
    UserContext = SslFindUserContextEx(v8);
  else
    UserContext = SslFindUserContext(a1);
  if ( UserContext )
  {
    AppDataStatusCallback = GetAppDataStatusCallback(UserContext, v10, v11, a2, a4);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 63i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
    return AppDataStatusCallback;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 62i64, &WPP_e7a188b1921532aa285b79366435dd9d_Traceguids);
    return 2148074241i64;
  }
}
// 180050C80: variable 'v10' is possibly undefined
// 180050C80: variable 'v11' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
