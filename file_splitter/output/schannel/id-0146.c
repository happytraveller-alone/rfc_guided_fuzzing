//----- (000000018000C774) ----------------------------------------------------
struct CSslUserContext *__fastcall SslReferenceUserContext(__int64 a1, unsigned __int8 a2)
{
  int v2; // r14d
  _QWORD *v4; // rbx
  CCipherMill *v5; // r10
  unsigned int v6; // ebp
  __int64 v7; // rdi
  __int64 v8; // rdi
  struct _RTL_RESOURCE *v9; // rcx
  _QWORD **v10; // rdx
  _QWORD *v11; // rax
  CCipherMill *v12; // rcx
  __int64 v14; // rcx
  _QWORD *v15; // rdx
  __int64 v16; // [rsp+20h] [rbp-28h]

  v2 = a2;
  v4 = 0i64;
  v5 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_ba773d91511536867a821af0ee22c47a_Traceguids);
    v5 = WPP_GLOBAL_Control;
  }
  v6 = (dwSslContextListCount - 1) & (BYTE3(a1)
                                    + a1
                                    + WORD1(a1)
                                    + ((unsigned int)a1 >> 8)
                                    + ((BYTE3(a1) + (_DWORD)a1 + WORD1(a1) + ((unsigned int)a1 >> 8)) >> 4));
  v7 = v6 & (dwSslContextLockCount - 1);
  if ( v5 != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)v5 + 28) & 4) != 0 )
    {
      WPP_SF_qd(*((_QWORD *)v5 + 2), 0x11u, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, a1, v2);
      v5 = WPP_GLOBAL_Control;
    }
    if ( v5 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
    {
      LODWORD(v16) = v7;
      WPP_SF_dd(*((_QWORD *)v5 + 2), 0x12u, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, v6, v16);
    }
  }
  v8 = 96 * v7;
  v9 = (struct _RTL_RESOURCE *)((char *)SslContextLock + v8);
  if ( (_BYTE)v2 )
    RtlAcquireResourceExclusive(v9, 1u);
  else
    RtlAcquireResourceShared(v9, 1u);
  v10 = (_QWORD **)((char *)SslContextList + 16 * v6);
  v11 = *v10;
  while ( v11 != v10 )
  {
    v4 = v11 - 38;
    if ( *(v11 - 2) == a1 )
    {
      if ( (_BYTE)v2 )
      {
        v14 = *v11;
        if ( *(_QWORD **)(*v11 + 8i64) != v11 || (v15 = (_QWORD *)v11[1], (_QWORD *)*v15 != v11) )
          __fastfail(3u);
        *v15 = v14;
        *(_QWORD *)(v14 + 8) = v15;
      }
      break;
    }
    v11 = (_QWORD *)*v11;
    v4 = 0i64;
  }
  RtlReleaseResource((PRTL_RESOURCE)((char *)SslContextLock + v8));
  v12 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_q(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x13u,
        (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids,
        v4);
      v12 = WPP_GLOBAL_Control;
    }
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v12 + 28) & 4) != 0 )
      {
        WPP_SF_qq(*((_QWORD *)v12 + 2), 0x14u, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, a1, v4);
        v12 = WPP_GLOBAL_Control;
      }
      if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
        WPP_SF_q(*((_QWORD *)v12 + 2), 0x15u, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, v4);
    }
  }
  return (struct CSslUserContext *)v4;
}
// 1800369DF: variable 'v16' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800919E0: using guessed type unsigned int dwSslContextListCount;
// 1800919E4: using guessed type unsigned int dwSslContextLockCount;

