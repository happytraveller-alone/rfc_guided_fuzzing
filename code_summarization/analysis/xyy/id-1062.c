//----- (00000001800591E4) ----------------------------------------------------
__int64 __fastcall CSessionCacheTable::CacheGetInfo(
        CSessionCacheTable *this,
        char a2,
        struct _SSL_SESSION_CACHE_INFO_RESPONSE *a3)
{
  struct _RTL_RESOURCE *v6; // rbp
  unsigned int TickCount; // r12d
  char *v8; // r14
  char *v9; // rsi
  unsigned int *v10; // rbx
  int v11; // eax
  bool v12; // zf

  v6 = (struct _RTL_RESOURCE *)((char *)this + 48);
  TickCount = GetTickCount();
  RtlAcquireResourceExclusive(v6, 1u);
  v8 = (char *)this + 16;
  v9 = (char *)*((_QWORD *)this + 2);
  while ( v9 != v8 )
  {
    v10 = (unsigned int *)(v9 - 304);
    v9 = *(char **)v9;
    v11 = (*(__int64 (__fastcall **)(unsigned int *))(*(_QWORD *)v10 + 88i64))(v10);
    if ( v11 == 1 )
    {
      v12 = (a2 & 1) == 0;
LABEL_6:
      if ( !v12 )
      {
        ++*((_DWORD *)a3 + 1);
        if ( v10[58] == 1 )
        {
          ++*((_DWORD *)a3 + 3);
          if ( HasTimeElapsed(v10[69], TickCount, v10[70]) )
            ++*((_DWORD *)a3 + 4);
          if ( !*((_BYTE *)v10 + 236) )
            ++*((_DWORD *)a3 + 5);
        }
        else
        {
          ++*((_DWORD *)a3 + 2);
        }
      }
    }
    else if ( v11 == 2 )
    {
      v12 = (a2 & 2) == 0;
      goto LABEL_6;
    }
  }
  RtlReleaseResource(v6);
  return 0i64;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

