// File count: 901
// Total lines: 38
-----------------------------------------
__int64 __fastcall SslGetStreamSizes(void **a1, void *a2, void *a3, __int64 a4, void **a5, unsigned int *a6, int *a7)
{
  int v7; // ebx
  void *v9; // [rsp+30h] [rbp-28h] BYREF
  __int64 v10; // [rsp+38h] [rbp-20h] BYREF
  int v11; // [rsp+40h] [rbp-18h]
  int v12; // [rsp+44h] [rbp-14h]

  v9 = 0i64;
  v10 = 0i64;
  *a5 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_6672ee5dd6af34547aa752f96a369f0c_Traceguids);
  v11 = dword_1800925D4;
  v12 = dword_1800925D8;
  v7 = (*(__int64 (__fastcall **)(_QWORD, __int64, void **))(LsaTable + 56))(0i64, 16i64, &v9);
  if ( v7 >= 0 )
  {
    v7 = (*(__int64 (__fastcall **)(_QWORD, __int64, void *, __int64 *))(LsaTable + 72))(0i64, 16i64, v9, &v10);
    if ( v7 >= 0 )
    {
      *a5 = v9;
      *a6 = 16;
    }
    else
    {
      (*(void (__fastcall **)(_QWORD, void *))(LsaTable + 64))(0i64, v9);
    }
  }
  *a7 = v7;
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 1800925D4: using guessed type int dword_1800925D4;
// 1800925D8: using guessed type int dword_1800925D8;
// 180092620: using guessed type __int64 LsaTable;
