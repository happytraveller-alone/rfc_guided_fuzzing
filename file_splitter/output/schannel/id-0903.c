//----- (000000018004C488) ----------------------------------------------------
__int64 __fastcall SslSessionCacheInfo(
        void **a1,
        char *a2,
        unsigned __int64 a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  void **v7; // r15
  unsigned int *v8; // r12
  __int64 v10; // rax
  unsigned __int64 v12; // rsi
  int Info; // ebx
  int *v14; // rbx
  unsigned __int64 v15; // rcx
  __int64 v16; // rdx
  struct _SSL_SESSION_CACHE_INFO_RESPONSE *v18; // rax
  struct _SSL_SESSION_CACHE_INFO_RESPONSE *v19; // rdi
  char v20[24]; // [rsp+30h] [rbp-40h] BYREF
  int v21; // [rsp+48h] [rbp-28h] BYREF
  __int64 v22; // [rsp+4Ch] [rbp-24h]
  int v23; // [rsp+54h] [rbp-1Ch]
  __int16 v24; // [rsp+58h] [rbp-18h]
  __int16 v25; // [rsp+5Ah] [rbp-16h]
  int v26; // [rsp+5Ch] [rbp-14h]
  __int64 v27; // [rsp+60h] [rbp-10h]
  int v28; // [rsp+68h] [rbp-8h]
  int v29; // [rsp+6Ch] [rbp-4h]
  void **v30; // [rsp+A0h] [rbp+30h] BYREF

  v30 = a1;
  v7 = a5;
  v8 = a6;
  v10 = LsaTable;
  v12 = a4;
  *a5 = 0i64;
  *v8 = 0;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(v10 + 192))(v20) )
  {
    Info = -1073741595;
    goto LABEL_11;
  }
  if ( (v20[8] & 0x40) != 0 )
  {
    if ( (unsigned int)v12 >= 0x18 )
    {
      v14 = &v21;
      v21 = *(_DWORD *)a2;
      v22 = *(_QWORD *)(a2 + 4);
      v28 = *((_DWORD *)a2 + 5);
      v24 = *((_WORD *)a2 + 6);
      v25 = *((_WORD *)a2 + 7);
      v27 = *((unsigned int *)a2 + 4);
      v23 = 0;
      v26 = 0;
      v29 = 0;
      goto LABEL_8;
    }
LABEL_10:
    Info = -1073741811;
    goto LABEL_11;
  }
  if ( (unsigned int)v12 < 0x28 )
    goto LABEL_10;
  v14 = (int *)a2;
LABEL_8:
  v15 = *((_QWORD *)v14 + 3);
  v16 = *((unsigned __int16 *)v14 + 8);
  if ( v15 )
  {
    if ( (_WORD)v16 )
    {
      if ( v15 >= a3 )
        v15 -= a3;
      if ( !v15 )
        goto LABEL_10;
      if ( v15 > v12 )
        goto LABEL_10;
      if ( v15 + v16 > v12 )
        goto LABEL_10;
      if ( v15 < 0x28 )
        goto LABEL_10;
      if ( (v15 & 1) != 0 )
        goto LABEL_10;
      *((_WORD *)v14 + 9) = v16;
      *((_QWORD *)v14 + 3) = &a2[v15];
      if ( (v16 & 1) != 0 )
        goto LABEL_10;
    }
    else
    {
      *((_QWORD *)v14 + 3) = 0i64;
    }
  }
  else if ( (_WORD)v16 )
  {
    goto LABEL_10;
  }
  v18 = (struct _SSL_SESSION_CACHE_INFO_RESPONSE *)SPExternalAlloc(0x1Cu);
  v19 = v18;
  if ( v18 )
  {
    Info = CSessionCacheManager::CacheGetInfo(CSessionCacheManager::m_pSessionCacheManager, v14[8], v18);
    if ( Info >= 0 )
    {
      Info = (*(__int64 (__fastcall **)(_QWORD, __int64, void ***))(LsaTable + 56))(0i64, 28i64, &v30);
      if ( Info >= 0 )
      {
        Info = (*(__int64 (__fastcall **)(_QWORD, __int64, void **, struct _SSL_SESSION_CACHE_INFO_RESPONSE *))(LsaTable + 72))(
                 0i64,
                 28i64,
                 v30,
                 v19);
        if ( Info >= 0 )
        {
          *v7 = v30;
          *v8 = 28;
        }
        else
        {
          (*(void (__fastcall **)(_QWORD, void **))(LsaTable + 64))(0i64, v30);
        }
      }
    }
    SPExternalFree(v19);
  }
  else
  {
    Info = -1073741801;
  }
LABEL_11:
  *a7 = Info;
  return 0i64;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

