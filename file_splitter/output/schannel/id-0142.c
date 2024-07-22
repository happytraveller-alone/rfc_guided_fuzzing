//----- (000000018000C2D0) ----------------------------------------------------
__int64 __fastcall SpUnsealMessage(__int64 a1, struct _SecBufferDesc *a2)
{
  struct CSslUserContext *UserContext; // rax
  unsigned int v5; // eax
  unsigned int v6; // ebx
  CCipherMill *v7; // r10
  unsigned int v9; // eax
  __int64 v10; // r10
  __int64 v11; // r10
  int v12; // [rsp+20h] [rbp-18h]

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  UserContext = SslFindUserContext(a1);
  if ( UserContext )
  {
    if ( *((_DWORD *)UserContext + 2) == 4 || *((_DWORD *)UserContext + 2) == 79 )
    {
      if ( (*((_DWORD *)UserContext + 4) & 0x1000i64) != 0 )
        v5 = SslUnsealMessageConnection(UserContext, a2);
      else
        v5 = SslUnsealMessageStream(UserContext, a2);
      v6 = v5;
      v7 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v9 = TranslateToSecurityStatus(v5);
        WPP_SF_D(*(_QWORD *)(v10 + 16), 25i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, v9);
        v7 = WPP_GLOBAL_Control;
      }
      if ( v6 == -2146893008 )
      {
        SslUnsealHideDecryptErrorDelay();
        v7 = WPP_GLOBAL_Control;
      }
      if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control
        && ((*((_BYTE *)v7 + 28) & 1) != 0 && (unsigned int)TranslateToSecurityStatus(v6)
         || (*((_BYTE *)v7 + 28) & 4) != 0) )
      {
        v12 = TranslateToSecurityStatus(v6);
        WPP_SF_DD(*(_QWORD *)(v11 + 16), 0x1Au, (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, v12, v12);
      }
      return TranslateToSecurityStatus(v6);
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
        WPP_SF_DD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x18u,
          (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids,
          -2146893033,
          -2146893033);
      return 2148074263i64;
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x17u,
        (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids,
        -2146893055,
        -2146893055);
    return 2148074241i64;
  }
}
// 180036574: variable 'v10' is possibly undefined
// 18000C373: variable 'v7' is possibly undefined
// 1800365BB: variable 'v11' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

