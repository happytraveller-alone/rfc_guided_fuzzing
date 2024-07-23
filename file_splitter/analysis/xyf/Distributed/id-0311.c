//----- (0000000180017090) ----------------------------------------------------
void __fastcall CSslGlobals::PeriodicCleanupHandler(void *a1, char a2)
{
  __int64 *v3; // rbx
  __int64 v4; // rdi
  unsigned int TickCount; // edi
  __int64 *v6; // rbx
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  _QWORD *v9; // r9
  __int64 v10; // r10
  __int64 v11; // rdx
  _QWORD *v12; // r8
  __int64 v13; // rdx
  _QWORD *v14; // rax

  if ( dword_180092D78 > *(_DWORD *)(*((_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + (unsigned int)tls_index)
                                   + 4i64) )
  {
    Init_thread_header(&dword_180092D78);
    if ( dword_180092D78 == -1 )
    {
      qword_1800921E8 = (__int64)CSessionCacheServerItem::m_pServerCacheLookaside;
      xmmword_1800921F0 = xmmword_180092DD0;
      qword_180092200 = (__int64)&g_SslContextManager;
      qword_180092208 = (__int64)CSessionCacheManager::m_pSessionCacheManager;
      qword_180092210 = (__int64)CSslCredManager::m_pCredManager;
      Init_thread_footer(&dword_180092D78);
    }
  }
  if ( a2 )
  {
    v3 = &qword_1800921E8;
    v4 = 6i64;
    do
    {
      if ( *v3 )
        (**(void (__fastcall ***)(__int64, _QWORD))*v3)(*v3, CSslGlobals::m_dwCleanupIntervalInSeconds);
      ++v3;
      --v4;
    }
    while ( v4 );
    if ( dword_180092704 && dword_180092778 )
    {
      TickCount = GetTickCount();
      RtlAcquireResourceExclusive(&stru_180092718, 1u);
      v6 = (__int64 *)qword_180092708;
      while ( v6 != &qword_180092708 )
      {
        v7 = *((_DWORD *)v6 - 10);
        v6 = (__int64 *)*v6;
        v8 = HasTimeElapsed(v7, TickCount, dword_1800926F8);
        if ( dword_180092704 > dword_180092700 || v8 )
        {
          v11 = *(_QWORD *)(v10 + 24);
          if ( *(_QWORD *)(v11 + 8) != v10 + 24
            || (v12 = *(_QWORD **)(v10 + 32), *v12 != v10 + 24)
            || (*v12 = v11, *(_QWORD *)(v11 + 8) = v12, v13 = *v9, *(_QWORD **)(*v9 + 8i64) != v9)
            || (v14 = (_QWORD *)v9[1], (_QWORD *)*v14 != v9) )
          {
            __fastfail(3u);
          }
          *v14 = v13;
          *(_QWORD *)(v13 + 8) = v14;
          --dword_180092704;
          SPDeleteIssuerEntry((struct ISSUER_CACHE_ENTRY *)v10);
        }
      }
      RtlReleaseResource(&stru_180092718);
    }
  }
  else
  {
    (**(void (__fastcall ***)(CSessionCacheManager *, _QWORD))CSessionCacheManager::m_pSessionCacheManager)(
      CSessionCacheManager::m_pSessionCacheManager,
      0i64);
  }
  ResetEvent(CSslGlobals::m_hCleanupEvent);
}
// 18003EC25: variable 'v10' is possibly undefined
// 18003EC42: variable 'v9' is possibly undefined
// 1800920C8: using guessed type int tls_index;
// 1800921E8: using guessed type __int64 qword_1800921E8;
// 1800921F0: using guessed type __int128 xmmword_1800921F0;
// 180092200: using guessed type __int64 qword_180092200;
// 180092208: using guessed type __int64 qword_180092208;
// 180092210: using guessed type __int64 qword_180092210;
// 180092704: using guessed type int dword_180092704;
// 180092708: using guessed type __int64 qword_180092708;
// 180092778: using guessed type int dword_180092778;
// 1800927F8: using guessed type struct IAllocate *CSessionCacheServerItem::m_pServerCacheLookaside;
// 180092D78: using guessed type int dword_180092D78;
// 180092DA0: using guessed type __int64 g_SslContextManager;
// 180092DD0: using guessed type __int128 xmmword_180092DD0;

