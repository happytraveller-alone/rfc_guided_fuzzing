//----- (000000018000BFE0) ----------------------------------------------------
__int64 __fastcall SpSealMessage(__int64 a1, int a2, struct _SecBufferDesc *a3)
{
  struct CSslUserContext *UserContext; // rax
  struct CSslUserContext *v7; // rcx
  int v9; // eax
  unsigned int v10; // eax
  int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // ebx
  CCipherMill *v14; // r10
  __int64 v15; // r10
  int v16; // [rsp+20h] [rbp-18h]

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  UserContext = SslFindUserContext(a1);
  v7 = UserContext;
  if ( UserContext )
  {
    v9 = *((_DWORD *)UserContext + 2);
    if ( v9 == 4 || (v10 = v9 - 51, v10 <= 0x1B) && (v11 = 167772161, _bittest(&v11, v10)) )
    {
      if ( (*((_DWORD *)v7 + 4) & 0x1000i64) != 0 )
        v12 = SslSealMessageConnection(v7, a2, a3);
      else
        v12 = SslSealMessageStream(v7, a2, a3);
      v13 = v12;
      v14 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && (unsigned int)TranslateToSecurityStatus(v12)
         || (*((_BYTE *)v14 + 28) & 4) != 0) )
      {
        v16 = TranslateToSecurityStatus(v13);
        WPP_SF_DD(*(_QWORD *)(v15 + 16), 0x15u, (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, v16, v16);
      }
      return TranslateToSecurityStatus(v13);
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
        WPP_SF_DD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x14u,
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
        0x13u,
        (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids,
        -2146893055,
        -2146893055);
    return 2148074241i64;
  }
}
// 18000C102: variable 'v14' is possibly undefined
// 18000C110: variable 'v15' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

