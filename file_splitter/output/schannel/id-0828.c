//----- (0000000180044114) ----------------------------------------------------
__int64 __fastcall GeneratePSKExchangeMessage(__int64 a1, __int64 a2)
{
  unsigned __int16 *v4; // rax
  unsigned __int16 *v5; // rbx
  void *v6; // rcx
  __int64 v7; // rax
  unsigned int v9; // eax

  v4 = (unsigned __int16 *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 336i64))(a1);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = *(void **)(a2 + 8);
  if ( v6 )
  {
    v9 = *(_DWORD *)a2;
  }
  else
  {
    v7 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)a1 + 8i64))(a1, *v4);
    *(_QWORD *)(a2 + 8) = v7;
    v6 = (void *)v7;
    if ( !v7 )
      return 14i64;
    v9 = *v5;
    *(_DWORD *)a2 = v9;
  }
  if ( *v5 <= v9 )
  {
    memcpy_0(v6, v5 + 1, *v5);
    *(_DWORD *)a2 = *v5;
    return 0i64;
  }
  return 2148074273i64;
}

