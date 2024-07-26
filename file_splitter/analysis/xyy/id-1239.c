//----- (0000000180062C20) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::SelectTBParameters(
        CSsl3TlsServerContext *this,
        char a2,
        char a3,
        unsigned __int8 *const a4,
        unsigned __int16 a5)
{
  unsigned __int8 *v8; // rbx
  unsigned __int8 *v9; // r10
  __int64 v10; // rdx
  _BYTE *v11; // rax
  unsigned __int64 v12; // rcx
  CCipherMill *v13; // rcx
  __int64 v14; // rdx
  unsigned __int8 *v15; // rsi
  unsigned int v17; // ebx

  v8 = a4;
  v9 = &a4[a5];
  if ( !a5 || !a4 )
    return 87i64;
  v10 = *((_QWORD *)this + 102);
  if ( !v10 || *(_BYTE *)v10 != a2 || *(_BYTE *)(v10 + 1) != a3 )
  {
    v13 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) == 0 )
      return 0i64;
    v14 = 63i64;
    goto LABEL_24;
  }
  v11 = (_BYTE *)(v10 + 4);
  v12 = v10 + 4 + *(unsigned __int16 *)(v10 + 2);
  while ( (unsigned __int64)v11 < v12 )
  {
    v8 = a4;
    if ( a4 < v9 )
    {
      while ( *v11 != *v8 )
      {
        if ( ++v8 >= v9 )
          goto LABEL_10;
      }
      break;
    }
LABEL_10:
    ++v11;
  }
  if ( v11 == (_BYTE *)v12 )
  {
    v13 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) == 0 )
      return 0i64;
    v14 = 64i64;
LABEL_24:
    WPP_SF_(*((_QWORD *)v13 + 2), v14, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
    return 0i64;
  }
  v15 = (unsigned __int8 *)(*(__int64 (__fastcall **)(CSsl3TlsServerContext *, __int64))(*(_QWORD *)this + 8i64))(
                             this,
                             1i64);
  if ( !v15 )
    return 14i64;
  *v15 = *v8;
  v17 = CSsl3TlsContext::SetSelectedTBParameters(this, a2, a3, v15, 1u);
  if ( v17 )
    (*(void (__fastcall **)(CSsl3TlsServerContext *, unsigned __int8 *))(*(_QWORD *)this + 16i64))(this, v15);
  return v17;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

