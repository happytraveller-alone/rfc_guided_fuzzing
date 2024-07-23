// File count: 864
// Total lines: 38
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::QueryEapKeyBlock(CSsl3TlsContext *this, void *a2)
{
  __int64 v4; // rcx
  __int64 v5; // rdx
  __int64 *v7; // rax
  __int64 v8; // rcx
  int v9; // ebx
  unsigned int v10[4]; // [rsp+40h] [rbp-E8h] BYREF
  char v11[192]; // [rsp+50h] [rbp-D8h] BYREF

  v10[0] = 192;
  RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
  v4 = *((_QWORD *)this + 11);
  v5 = *(_QWORD *)(v4 + 16);
  if ( v5 )
  {
    v7 = (__int64 *)*((_QWORD *)this + 1);
    if ( v7 )
      v8 = *v7;
    else
      v8 = 0i64;
    v9 = SslComputeEapKeyBlock(v8, v5, (char *)this + 272, 64i64, v11, v10[0], v10, *((_DWORD *)this + 84));
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
    if ( v9 )
      return 1359i64;
    else
      return (*(__int64 (__fastcall **)(_QWORD, _QWORD, void *, char *))(LsaTable + 72))(0i64, v10[0], a2, v11);
  }
  else
  {
    RtlReleaseResource((PRTL_RESOURCE)(v4 + 72));
    return 2148074241i64;
  }
}
// 180092620: using guessed type __int64 LsaTable;
// 180098568: using guessed type __int64 __fastcall SslComputeEapKeyBlock(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180046538: using guessed type unsigned int var_E8[4];
