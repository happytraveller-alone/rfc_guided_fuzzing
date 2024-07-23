// File count: 833
// Total lines: 100
----------------------------------------
__int64 __fastcall SpApplyControlToken(__int64 a1, __int64 a2)
{
  CCipherMill *v4; // rcx
  __int64 v5; // rbx
  __int64 v6; // rdi
  int v7; // esi
  unsigned int v8; // edx
  __int64 v9; // r10
  __int64 result; // rax
  _DWORD *v11; // r9
  int v12; // ecx
  __int64 v13; // rcx
  __int64 v14; // rdx
  char v15; // cl

  v4 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_qq(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x35u,
      (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
      a1,
      a2);
    v4 = WPP_GLOBAL_Control;
  }
  v5 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)(a2 + 4) != 1 )
    return 2148074248i64;
  v6 = *(_QWORD *)(a2 + 8);
  if ( !v6 )
    return 2148074248i64;
  v7 = 2;
  if ( (*(_DWORD *)(v6 + 4) & 0xFFFFFFF) != 2 )
    return 2148074248i64;
  v8 = *(_DWORD *)v6;
  if ( *(_DWORD *)v6 < 4u )
    return 2148074242i64;
  v9 = *(_QWORD *)(v5 + 88);
  if ( !v9 )
    return 2148074241i64;
  v11 = *(_DWORD **)(v6 + 8);
  if ( *v11 == 1 )
  {
    if ( v4 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v4 + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)v4 + 2), 54i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
    if ( *(_DWORD *)(v5 + 68) != 4 )
      v7 = 5;
    *(_DWORD *)(v5 + 68) = v7;
    return 0i64;
  }
  if ( *v11 == 2 )
  {
    if ( v4 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v4 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v4 + 2), 55i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
      v8 = *(_DWORD *)v6;
    }
    if ( v8 < 0xC )
      return 2148074248i64;
    v14 = *(_QWORD *)(v6 + 8);
    if ( (*(_DWORD *)(v5 + 64) & 0x3FF0) != 0 )
    {
      if ( (unsigned int)(*(_DWORD *)(v14 + 4) - 1) <= 1 && *(_DWORD *)(v14 + 8) < 0x100u )
      {
        v15 = *(_BYTE *)(v14 + 8);
        *(_BYTE *)(v5 + 96) = *(_BYTE *)(v14 + 4);
        *(_BYTE *)(v5 + 97) = v15;
        *(_DWORD *)(v5 + 68) = 96;
        return 0i64;
      }
      return 2148074248i64;
    }
    return 2148074242i64;
  }
  result = 2148074242i64;
  if ( *v11 != 3 )
    return result;
  if ( v8 < 8 )
    return 2148074248i64;
  v12 = v11[1];
  if ( (v12 & 2) != 0 )
  {
    *(_BYTE *)(v9 + 236) = 0;
    result = 0i64;
    v12 = v11[1];
  }
  if ( (v12 & 1) != 0 )
  {
    v13 = *(_QWORD *)(v5 + 88);
    if ( *(_BYTE *)(v13 + 237) )
    {
      *(_WORD *)(v13 + 236) = 1;
      return 0i64;
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
