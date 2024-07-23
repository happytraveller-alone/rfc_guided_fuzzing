// File count: 960
// Total lines: 92
-----------------------------------------
__int64 __fastcall SpExportSecurityContext(__int64 a1, char a2, __int64 a3, void **a4)
{
  _QWORD *v8; // r14
  struct CSslUserContext *UserContext; // rax
  __int64 v10; // rdi
  int v12; // r15d
  unsigned int v13; // ebp
  CCipherMill *v14; // rcx
  void *v15; // rdx
  int v16; // ebx
  __int64 v17; // [rsp+20h] [rbp-58h]
  __int64 v18; // [rsp+40h] [rbp-38h] BYREF
  __int128 v19; // [rsp+48h] [rbp-30h]
  int v20; // [rsp+58h] [rbp-20h]
  int v21; // [rsp+5Ch] [rbp-1Ch]

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  if ( a4 )
    *a4 = 0i64;
  *(_DWORD *)a3 = 0;
  v8 = (_QWORD *)(a3 + 8);
  *(_QWORD *)(a3 + 8) = 0i64;
  *(_DWORD *)(a3 + 4) = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x21u, (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, a1);
  UserContext = SslFindUserContext(a1);
  v10 = (__int64)UserContext;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_q(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x22u,
      (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids,
      UserContext);
  if ( !v10 )
    return 2148074241i64;
  if ( *(_DWORD *)(v10 + 8) != 4 )
    return 2148074263i64;
  v20 = 0;
  v21 = 0;
  v12 = a2 & 2;
  v18 = v10;
  v19 = 0i64;
  v13 = CSslSerializeHelper::SerializeContext(
          (CSslSerializeHelper *)&v18,
          0i64,
          (unsigned __int8 **)(a3 + 8),
          (unsigned int *)a3);
  v14 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 35i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, v13);
    v14 = WPP_GLOBAL_Control;
  }
  if ( v13 )
    return 2148074281i64;
  if ( !a4 )
    goto LABEL_26;
  v15 = *(void **)(v10 + 264);
  if ( !v15 )
    goto LABEL_26;
  if ( v12 )
  {
    *a4 = v15;
    *(_QWORD *)(v10 + 264) = 0i64;
LABEL_25:
    v14 = WPP_GLOBAL_Control;
LABEL_26:
    v16 = 0;
    goto LABEL_27;
  }
  v16 = NtDuplicateObject((HANDLE)0xFFFFFFFFFFFFFFFFi64, v15, (HANDLE)0xFFFFFFFFFFFFFFFFi64, a4, 0, 0, 2u);
  if ( v16 >= 0 )
    goto LABEL_25;
  (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 16i64))(v10, *v8);
  *v8 = 0i64;
  *(_DWORD *)a3 = 0;
  v14 = WPP_GLOBAL_Control;
LABEL_27:
  if ( v14 != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)v14 + 28) & 1) != 0 && v16 || (*((_BYTE *)v14 + 28) & 4) != 0) )
  {
    LODWORD(v17) = v16;
    WPP_SF_DD(*((_QWORD *)v14 + 2), 0x24u, (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids, v16, v17);
  }
  return (unsigned int)v16;
}
// 18004FD7F: variable 'v17' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
