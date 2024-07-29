//----- (000000018004F728) ----------------------------------------------------
__int64 __fastcall UpdateTrafficSecretAndDeriveNewKey(
        __int64 a1,
        unsigned __int64 *a2,
        unsigned __int64 *a3,
        unsigned __int64 *a4)
{
  unsigned int v8; // eax
  unsigned int v9; // ebx
  CCipherMill *v10; // rcx
  __int64 v11; // rdx
  unsigned __int64 v12; // rax
  unsigned __int64 v14[5]; // [rsp+30h] [rbp-28h] BYREF
  unsigned __int64 v15; // [rsp+60h] [rbp+8h] BYREF

  v15 = 0i64;
  v14[0] = 0i64;
  if ( a1 && a2 && a3 && a4 )
  {
    v8 = SslExpandNextGenTrafficKey(a1, *a2, &v15, 0i64, 0);
    v9 = v8;
    if ( v8 )
    {
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_21;
      v11 = 138i64;
    }
    else
    {
      v8 = SslExpandWriteKey(a1, v15, v14, 0i64, 0);
      v9 = v8;
      if ( !v8 )
      {
        if ( *a2 )
          SslFreeObject(*a2, 0i64);
        if ( *a3 )
          SslFreeObject(*a3, 0i64);
        v12 = v15;
        v15 = 0i64;
        *a2 = v12;
        *a3 = v14[0];
        *a4 = 0i64;
        v14[0] = 0i64;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          return v9;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 140i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
LABEL_21:
        if ( v15 )
          SslFreeObject(v15, 0i64);
        if ( v14[0] )
          SslFreeObject(v14[0], 0i64);
        return v9;
      }
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_21;
      v11 = 139i64;
    }
    WPP_SF_D(*((_QWORD *)v10 + 2), v11, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v8);
    goto LABEL_21;
  }
  return 2148074333i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098500: using guessed type __int64 __fastcall SslExpandNextGenTrafficKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098520: using guessed type __int64 __fastcall SslExpandWriteKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 18004F728: using guessed type unsigned __int64 var_28[5];

