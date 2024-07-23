//----- (0000000180006034) ----------------------------------------------------
bool __fastcall CSessionCacheTable::LookupCacheByName(
        CSessionCacheTable *this,
        unsigned int a2,
        const unsigned __int16 *a3,
        struct CCredentialGroup *a4,
        struct CSessionCacheItem **a5)
{
  __int64 v6; // r13
  _QWORD *v8; // rdi
  int v9; // r15d
  __int64 v10; // r13
  _QWORD **v11; // rcx
  _QWORD *v12; // r14
  _QWORD *v14; // rsi
  struct CCredentialGroup *v15; // rbx
  CSessionCacheTable *v16; // rcx
  __int64 v17; // rcx
  _QWORD *v18; // rdx
  __int64 v19; // [rsp+30h] [rbp-58h] BYREF
  PRTL_RESOURCE Resource; // [rsp+38h] [rbp-50h]
  __int64 v21; // [rsp+90h] [rbp+8h] BYREF
  unsigned int TickCount; // [rsp+98h] [rbp+10h]
  const unsigned __int16 *v23; // [rsp+A0h] [rbp+18h]
  struct CCredentialGroup *v24; // [rsp+A8h] [rbp+20h]

  v24 = a4;
  v23 = a3;
  v6 = a2;
  v8 = 0i64;
  v9 = 0;
  TickCount = GetTickCount();
  v19 = *(_QWORD *)((char *)a4 + 740);
  Resource = (PRTL_RESOURCE)((char *)this + 48);
  RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
  v10 = 16 * v6;
  v11 = (_QWORD **)(v10 + *(_QWORD *)this);
  v12 = *v11;
  if ( *v11 == v11 )
    goto LABEL_2;
  do
  {
    v14 = v12 - 36;
    v12 = (_QWORD *)*v12;
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v14 + 9), 1u);
    if ( *((_BYTE *)v14 + 236) )
    {
      if ( !HasTimeElapsed(*((_DWORD *)v14 + 69), TickCount, *((_DWORD *)v14 + 70)) )
      {
        v15 = v24;
        v21 = *((_QWORD *)v24 + 95);
        if ( (*(unsigned __int8 (__fastcall **)(_QWORD *, __int64 *, const unsigned __int16 *, __int64 *, _DWORD))(*v14 + 80i64))(
               v14,
               &v19,
               v23,
               &v21,
               *((_DWORD *)v24 + 38)) )
        {
          if ( CSessionCacheItem::DoesAppAllowCipher((CSessionCacheItem *)v14, v15) )
          {
            if ( !v8 )
            {
              v9 = CSessionCacheTable::ReferenceCacheItemInternal(v16, (struct CSessionCacheItem *)v14);
LABEL_9:
              v8 = v14;
              goto LABEL_10;
            }
            if ( *((_DWORD *)v14 + 69) > *((_DWORD *)v8 + 69) )
            {
              v9 = CSessionCacheTable::ReferenceCacheItemInternal(v16, (struct CSessionCacheItem *)v14);
              RtlAcquireResourceExclusive((PRTL_RESOURCE)(v8 + 9), 1u);
              *((_BYTE *)v8 + 236) = 0;
              CSessionCacheTable::DereferenceCacheItemInternal(this, (struct CSessionCacheItem *)v8, 0, 0);
              RtlReleaseResource((PRTL_RESOURCE)(v8 + 9));
              goto LABEL_9;
            }
            *((_BYTE *)v14 + 236) = 0;
          }
        }
      }
    }
LABEL_10:
    RtlReleaseResource((PRTL_RESOURCE)(v14 + 9));
  }
  while ( v12 != (_QWORD *)(v10 + *(_QWORD *)this) );
  if ( v8 )
  {
    *a5 = (struct CSessionCacheItem *)v8;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xBu, (__int64)&WPP_54aae497645f38b3b161e68e12f6f932_Traceguids, v8);
    if ( v9 == 2 )
    {
      v17 = v8[40];
      if ( *(_QWORD **)(v17 + 8) != v8 + 40 || (v18 = (_QWORD *)v8[41], (_QWORD *)*v18 != v8 + 40) )
        __fastfail(3u);
      *v18 = v17;
      *(_QWORD *)(v17 + 8) = v18;
    }
    LsaIModifyPerformanceCounter(7i64);
  }
LABEL_2:
  RtlReleaseResource(Resource);
  return v8 != 0i64;
}
// 18000618D: variable 'v16' is possibly undefined
// 180098238: using guessed type __int64 __fastcall LsaIModifyPerformanceCounter(_QWORD);

