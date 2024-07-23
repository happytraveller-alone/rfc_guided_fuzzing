// File count: 79
// Total lines: 77
------------------------------------------
__int64 __fastcall CTlsExt::ParseTlsExtensions(__int64 a1, unsigned __int8 *a2, unsigned int a3, int a4)
{
  __int64 v4; // rax
  char v5; // bp
  unsigned int v6; // ebx
  unsigned __int8 *v7; // rdi
  char v9; // r12
  CCipherMill *v10; // rcx
  unsigned __int16 v11; // r15
  unsigned int v12; // r14d
  unsigned __int8 *v13; // rdi
  unsigned int v14; // ebx
  unsigned __int8 *v15; // r8
  __int64 result; // rax

  v4 = *(_QWORD *)(a1 + 8);
  v5 = 0;
  v6 = a3;
  v7 = a2;
  v9 = *(_BYTE *)(v4 + 64) & 0x30;
  *(_DWORD *)(a1 + 16) = a4;
  *(_BYTE *)(v4 + 922) = 0;
  *(_BYTE *)(a1 + 27) = 0;
  if ( a3 )
  {
    v10 = WPP_GLOBAL_Control;
    while ( v6 >= 4 )
    {
      v11 = _byteswap_ushort(*((_WORD *)v7 + 1));
      v12 = v7[1] | (*v7 << 8);
      if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
      {
        WPP_SF_D(*((_QWORD *)v10 + 2), 73i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids, v12);
        v10 = WPP_GLOBAL_Control;
      }
      v13 = v7 + 4;
      a2 = (unsigned __int8 *)v11;
      v14 = v6 - 4;
      if ( v14 < v11 )
      {
        if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 2) != 0 )
          WPP_SF_(*((_QWORD *)v10 + 2), 74i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
        return 2148074278i64;
      }
      v15 = v13;
      v7 = &v13[v11];
      v6 = v14 - v11;
      if ( !v9 || v12 == 65281 )
      {
        result = (*(__int64 (__fastcall **)(__int64, _QWORD, unsigned __int8 *, _QWORD))(*(_QWORD *)a1 + 8i64))(
                   a1,
                   v12,
                   v15,
                   v11);
        if ( (_DWORD)result )
          return result;
        v10 = WPP_GLOBAL_Control;
        if ( v12 == 65281 )
          v5 = 1;
      }
      if ( !v6 )
        goto LABEL_13;
    }
    return 2148074278i64;
  }
  else
  {
LABEL_13:
    LOBYTE(a2) = v5;
    (*(void (__fastcall **)(_QWORD, unsigned __int8 *))(**(_QWORD **)(a1 + 8) + 352i64))(*(_QWORD *)(a1 + 8), a2);
    return 0i64;
  }
}
// 18000654D: variable 'a2' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
