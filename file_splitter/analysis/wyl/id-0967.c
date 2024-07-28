//----- (0000000180050800) ----------------------------------------------------
struct CSslUserContext *__fastcall SslFindUserContextEx(union _LARGE_INTEGER *a1)
{
  CCipherMill *v2; // rcx
  unsigned int v3; // edi
  __int64 v4; // rsi
  _QWORD **v5; // rdx
  _QWORD *v6; // rax
  _QWORD *v7; // rbx

  v2 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, &WPP_ba773d91511536867a821af0ee22c47a_Traceguids);
      v2 = WPP_GLOBAL_Control;
    }
    if ( v2 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v2 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v2 + 2), 25i64, &WPP_ba773d91511536867a821af0ee22c47a_Traceguids);
      v2 = WPP_GLOBAL_Control;
    }
  }
  v3 = 0;
  if ( dwSslContextListCount )
  {
    while ( 1 )
    {
      v4 = 96i64 * (v3 & (dwSslContextLockCount - 1));
      RtlAcquireResourceShared((PRTL_RESOURCE)((char *)SslContextLock + v4), 1u);
      v5 = (_QWORD **)((char *)SslContextList + 16 * v3);
      v6 = *v5;
      if ( *v5 != v5 )
        break;
LABEL_11:
      RtlReleaseResource((PRTL_RESOURCE)((char *)SslContextLock + v4));
      if ( ++v3 >= dwSslContextListCount )
      {
        v2 = WPP_GLOBAL_Control;
        goto LABEL_13;
      }
    }
    while ( 1 )
    {
      v7 = v6 - 38;
      if ( a1->QuadPart == *(v6 - 1) )
        break;
      v6 = (_QWORD *)*v6;
      if ( v6 == v5 )
        goto LABEL_11;
    }
    RtlReleaseResource((PRTL_RESOURCE)((char *)SslContextLock + v4));
    v2 = WPP_GLOBAL_Control;
  }
  else
  {
LABEL_13:
    v7 = 0i64;
  }
  if ( v2 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v2 + 28) & 4) != 0 )
    WPP_SF_q(*((_QWORD *)v2 + 2), 0x1Au, (__int64)&WPP_ba773d91511536867a821af0ee22c47a_Traceguids, v7);
  return (struct CSslUserContext *)v7;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800919E0: using guessed type unsigned int dwSslContextListCount;
// 1800919E4: using guessed type unsigned int dwSslContextLockCount;
