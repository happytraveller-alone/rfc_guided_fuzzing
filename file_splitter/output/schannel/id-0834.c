// File count: 834
// Total lines: 30
-----------------------------------------
char __fastcall SslFreeCustomBuffer(__int64 a1, unsigned __int64 *a2, __int64 a3, char a4)
{
  char v4; // di
  __int64 v8; // rcx

  v4 = 0;
  if ( a2 != g_dwPackageId && a2 != (unsigned __int64 *)qword_180092630 || !a1 )
    return 0;
  v8 = *(_QWORD *)(a1 + 24);
  if ( v8 )
  {
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v8 + 32i64))(v8, a3);
    v4 = 1;
    if ( a4 )
    {
      CSslContextManager::DeleteContextScratch(
        (__int64)&g_SslContextManager,
        *(_QWORD *)(a1 + 24),
        *(_BYTE *)(a1 + 32),
        *(_DWORD *)(*(_QWORD *)(a1 + 8) + 68i64));
      *(_QWORD *)(a1 + 24) = 0i64;
    }
  }
  return v4;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092628: using guessed type unsigned __int64 near *g_dwPackageId;
// 180092630: using guessed type __int64 qword_180092630;
// 180092DA0: using guessed type __int64 g_SslContextManager;
