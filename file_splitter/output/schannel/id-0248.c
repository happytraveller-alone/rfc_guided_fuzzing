// File count: 248
// Total lines: 88
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::MakeRsaKeyXParameterList(
        __int64 a1,
        int a2,
        _DWORD *a3,
        __int64 a4,
        __int64 a5,
        int *a6)
{
  unsigned int v6; // eax
  __int64 v9; // rsi
  unsigned int v10; // ebp
  __int64 v11; // rdx
  unsigned int v12; // eax
  __int64 v13; // rdx
  int v14; // eax
  int v16; // r12d
  unsigned int v17; // r13d
  __int64 v18; // rax
  _QWORD *v19; // rcx
  int v20; // eax
  unsigned int v21; // r12d

  v6 = 0;
  if ( !a4 )
    return 87i64;
  v9 = *(_QWORD *)(a4 + 8);
  v10 = *(_DWORD *)(a4 + 4);
  if ( !a2 )
    goto LABEL_3;
  if ( a2 != 1 || !a3 || !v10 )
    return 87i64;
  *a3 = *(_DWORD *)(a1 + 36);
  v6 = 1;
  *(_DWORD *)(v9 + 4) = 22;
  *(_DWORD *)v9 = 4;
  *(_QWORD *)(v9 + 8) = a3;
  if ( (*(_DWORD *)(a1 + 136) & 0x8000000) == 0 )
  {
LABEL_3:
    if ( v10 >= v6 + 2 )
    {
      v11 = 2i64 * v6;
      v12 = v6 + 1;
      *(_QWORD *)(v9 + 8 * v11 + 8) = a1 + 272;
      *(_DWORD *)(v9 + 8 * v11 + 4) = 20;
      *(_DWORD *)(v9 + 8 * v11) = 32;
      v13 = 2i64 * v12;
      v14 = v12 + 1;
      *(_DWORD *)(v9 + 8 * v13 + 4) = 21;
      *(_DWORD *)(v9 + 8 * v13) = 32;
      *(_QWORD *)(v9 + 8 * v13 + 8) = a1 + 304;
LABEL_5:
      *(_DWORD *)(a4 + 4) = v14;
      return 0i64;
    }
    return 87i64;
  }
  if ( !a5 )
    return 87i64;
  if ( !a6 )
    return 87i64;
  v16 = *a6;
  if ( !*a6 )
    return 87i64;
  v17 = *(unsigned __int16 *)(a1 + 34);
  v18 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)a1 + 512i64))(a1, 0i64);
  v19 = *(_QWORD **)(a1 + 8);
  if ( v19 )
    v19 = (_QWORD *)*v19;
  v20 = SslComputeSessionHash(v19, v18, v17, a5, v16, a6, 0);
  v21 = v20;
  if ( !v20 )
  {
    if ( v10 >= 2 )
    {
      *(_DWORD *)(v9 + 20) = 25;
      *(_DWORD *)(v9 + 16) = *a6;
      v14 = 2;
      *(_QWORD *)(v9 + 24) = a5;
      goto LABEL_5;
    }
    return 87i64;
  }
  CSslContext::SetErrorAndFatalAlert(a1, 604, v20, 0x33u);
  return v21;
}
// 180098530: using guessed type __int64 __fastcall SslComputeSessionHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
