//----- (00000001800615C8) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::SetNegotiatedTBParameters(
        CSsl3TlsClientContext *this,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 *const a4,
        unsigned __int16 a5)
{
  unsigned __int8 *v5; // rdi
  __int16 v6; // r15
  unsigned __int8 *v9; // r10
  unsigned __int16 *v10; // r8
  CCipherMill *v11; // rcx
  __int64 v12; // rdx
  unsigned __int16 v13; // cx
  unsigned __int16 v14; // dx
  unsigned __int64 v16; // rcx
  unsigned __int16 *v17; // r8
  unsigned __int16 *v18; // rax
  unsigned __int8 *v19; // rax
  unsigned __int8 *v20; // rsi
  unsigned int v21; // edi

  v5 = a4;
  v6 = a3;
  v9 = &a4[a5];
  if ( !a5 || !a4 )
    return 87i64;
  v10 = (unsigned __int16 *)*((_QWORD *)this + 102);
  if ( !v10 )
  {
    v11 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v12 = 73i64;
      goto LABEL_28;
    }
    return 2148074278i64;
  }
  v13 = _byteswap_ushort(*v10);
  v14 = v6 | (a2 << 8);
  if ( v14 > v13 )
  {
    v11 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v12 = 74i64;
      goto LABEL_28;
    }
    return 2148074278i64;
  }
  if ( v14 < v13 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 75i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
    return 0i64;
  }
  v16 = (unsigned __int64)v10 + v10[1] + 4;
  if ( a4 >= v9 )
  {
LABEL_23:
    v19 = (unsigned __int8 *)(*(__int64 (__fastcall **)(CSsl3TlsClientContext *, _QWORD))(*(_QWORD *)this + 8i64))(
                               this,
                               a5);
    v20 = v19;
    if ( !v19 )
      return 14i64;
    memcpy_0(v19, v5, a5);
    v21 = CSsl3TlsContext::SetSelectedTBParameters(this, a2, v6, v20, a5);
    if ( v21 )
      (*(void (__fastcall **)(CSsl3TlsClientContext *, unsigned __int8 *))(*(_QWORD *)this + 16i64))(this, v20);
    return v21;
  }
  v17 = v10 + 2;
  while ( 1 )
  {
    v18 = v17;
    if ( (unsigned __int64)v17 < v16 )
    {
      while ( *a4 != *(_BYTE *)v18 )
      {
        v18 = (unsigned __int16 *)((char *)v18 + 1);
        if ( (unsigned __int64)v18 >= v16 )
          goto LABEL_21;
      }
      goto LABEL_22;
    }
LABEL_21:
    if ( v18 == (unsigned __int16 *)v16 )
      break;
LABEL_22:
    if ( ++a4 >= v9 )
      goto LABEL_23;
  }
  v11 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    v12 = 76i64;
LABEL_28:
    WPP_SF_(*((_QWORD *)v11 + 2), v12, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
  }
  return 2148074278i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
