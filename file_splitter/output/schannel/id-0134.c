//----- (000000018000B0B0) ----------------------------------------------------
__int64 __fastcall SpInitUserModeContext(__int64 a1, struct _SecBuffer *a2)
{
  unsigned int v4; // ebx
  CCipherMill *v6; // rcx
  int v7; // [rsp+20h] [rbp-18h]
  unsigned int v8; // [rsp+20h] [rbp-18h]

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  if ( (unsigned int)SchannelInit(1) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_q(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x10u,
        (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids,
        a1);
    v4 = SslAddUserContext(a1, 0i64, a2, 0);
    if ( g_pFreeContextBuffer )
    {
      g_pFreeContextBuffer(a2->pvBuffer);
      a2->pvBuffer = 0i64;
      a2->cbBuffer = 0;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
      && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v4 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
    {
      v8 = v4;
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x11u,
        (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids,
        v4,
        v8);
    }
    return v4;
  }
  else
  {
    v6 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
        v6 = WPP_GLOBAL_Control;
      }
      if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
      {
        v7 = -2146893052;
        WPP_SF_DD(*((_QWORD *)v6 + 2), 0xFu, (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, -2146893052, v7);
      }
    }
    return 2148074244i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800921A0: using guessed type int (__stdcall *g_pFreeContextBuffer)(void *);

