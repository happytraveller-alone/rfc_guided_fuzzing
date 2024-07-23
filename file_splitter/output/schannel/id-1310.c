// File count: 1310
// Total lines: 50
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateGenericExtensions(__int64 a1, int a2)
{
  __int64 v2; // rax
  __int64 *v5; // rbx
  __int64 v6; // r8
  __int64 *v7; // rbp
  __int64 v8; // rdi
  __int64 result; // rax
  __int64 v10; // rdx

  v2 = *(_QWORD *)(a1 + 8);
  v5 = (__int64 *)(v2 + 1480);
  if ( v2 != -1480 )
  {
    v6 = *(unsigned __int8 *)(v2 + 1488);
    if ( (_BYTE)v6 )
    {
      v7 = &v5[v6];
      while ( v5 < v7 )
      {
        v8 = *v5;
        if ( !*v5 )
          return 2148074244i64;
        if ( *(unsigned __int16 *)(v8 + 2) == a2 )
        {
          result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
                     a1,
                     *(_WORD *)v8,
                     *(_WORD *)(v8 + 8));
          if ( (_DWORD)result )
            return result;
          v10 = *(unsigned __int16 *)(v8 + 8);
          if ( (_WORD)v10 )
          {
            result = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64))(**(_QWORD **)(a1 + 32) + 32i64))(
                       *(_QWORD *)(a1 + 32),
                       v10,
                       v8 + 10);
            if ( (_DWORD)result )
              return result;
          }
        }
        ++v5;
      }
    }
  }
  return 0i64;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
