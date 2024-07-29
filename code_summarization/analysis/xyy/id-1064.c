//----- (000000018005933C) ----------------------------------------------------
bool __fastcall CSessionCacheTable::LookupCacheBySessionId(
        CSessionCacheTable *this,
        unsigned int a2,
        struct CSslContext *a3,
        unsigned __int8 *a4,
        size_t Size,
        struct CSessionCacheItem **a6)
{
  __int64 v6; // r14
  int v8; // edi
  __int64 v9; // r14
  _QWORD **v10; // rcx
  _QWORD *v11; // rsi
  unsigned int v12; // r12d
  _QWORD *v13; // rbx
  CSessionCacheTable *v14; // rcx
  _QWORD *v15; // rbx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  __int64 v19[11]; // [rsp+30h] [rbp-58h] BYREF
  DWORD TickCount; // [rsp+90h] [rbp+8h]
  unsigned int v21; // [rsp+98h] [rbp+10h] BYREF
  struct CSslContext *v22; // [rsp+A0h] [rbp+18h]
  void *Buf1; // [rsp+A8h] [rbp+20h]

  Buf1 = a4;
  v22 = a3;
  v6 = a2;
  v8 = 0;
  TickCount = GetTickCount();
  SslGetClientProcess(&v21);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
  v9 = 16 * v6;
  v10 = (_QWORD **)(v9 + *(_QWORD *)this);
  v11 = *v10;
  if ( *v10 != v10 )
  {
    v12 = v21;
    while ( 1 )
    {
      v13 = v11 - 36;
      v11 = (_QWORD *)*v11;
      RtlAcquireResourceShared((PRTL_RESOURCE)(v13 + 9), 1u);
      if ( *((_BYTE *)v13 + 236) )
      {
        if ( !HasTimeElapsed(*((_DWORD *)v13 + 69), TickCount, *((_DWORD *)v13 + 70))
          && (_DWORD)Size == *((unsigned __int16 *)v13 + 119)
          && !memcmp_0(Buf1, v13 + 30, (unsigned int)Size)
          && *((_DWORD *)v13 + 68) == v12 )
        {
          v19[0] = *(_QWORD *)(*((_QWORD *)v22 + 10) + 760i64);
          if ( (*(unsigned __int8 (__fastcall **)(_QWORD *, _QWORD, _QWORD, __int64 *, _DWORD))(*v13 + 80i64))(
                 v13,
                 0i64,
                 0i64,
                 v19,
                 *((_DWORD *)v22 + 16)) )
          {
            break;
          }
        }
      }
      RtlReleaseResource((PRTL_RESOURCE)(v13 + 9));
      if ( v11 == (_QWORD *)(v9 + *(_QWORD *)this) )
        goto LABEL_20;
    }
    v8 = CSessionCacheTable::ReferenceCacheItemInternal(v14, (struct CSessionCacheItem *)v13);
    RtlReleaseResource((PRTL_RESOURCE)(v13 + 9));
    if ( v8 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_q(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xAu,
          (__int64)&WPP_54aae497645f38b3b161e68e12f6f932_Traceguids,
          v13);
      *a6 = (struct CSessionCacheItem *)v13;
      if ( v8 == 2 )
      {
        v15 = v13 + 40;
        v16 = *v15;
        if ( *(_QWORD **)(*v15 + 8i64) != v15 || (v17 = (_QWORD *)v15[1], (_QWORD *)*v17 != v15) )
          __fastfail(3u);
        *v17 = v16;
        *(_QWORD *)(v16 + 8) = v17;
      }
      LsaIModifyPerformanceCounter(9i64);
    }
  }
LABEL_20:
  RtlReleaseResource((PRTL_RESOURCE)((char *)this + 48));
  return v8 > 0;
}
// 1800594A4: variable 'v14' is possibly undefined
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);
// 18005933C: using guessed type __int64 var_58[11];
