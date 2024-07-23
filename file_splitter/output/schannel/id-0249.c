// File count: 249
// Total lines: 86
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::SetPSKParameters(
        CSsl3TlsContext *this,
        struct _SecBuffer *const a2,
        struct _SecBuffer *const a3)
{
  unsigned __int16 *pvBuffer; // rbp
  size_t v7; // rsi
  CCipherMill *v8; // rcx
  __int64 v9; // rdx
  void *v10; // rax
  unsigned int cbBuffer; // ecx
  unsigned __int16 *v12; // rsi
  size_t v13; // rbx
  void *v14; // rax

  if ( a2 )
  {
    if ( a2->BufferType != 22 || a2->cbBuffer < 4 || (pvBuffer = (unsigned __int16 *)a2->pvBuffer) == 0i64 )
    {
      v8 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v9 = 93i64;
      goto LABEL_37;
    }
    v7 = (unsigned int)*pvBuffer + 2;
    if ( (unsigned int)v7 <= 4 )
    {
      v7 = 4i64;
    }
    else if ( a2->cbBuffer < (unsigned int)v7 )
    {
      v8 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v9 = 94i64;
      goto LABEL_37;
    }
    if ( *((_QWORD *)this + 106) )
      (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
    v10 = (void *)(*(__int64 (__fastcall **)(CSsl3TlsContext *, size_t))(*(_QWORD *)this + 8i64))(this, v7);
    *((_QWORD *)this + 106) = v10;
    if ( !v10 )
      return 14i64;
    memcpy_0(v10, pvBuffer, v7);
  }
  if ( !a3 )
    return 0i64;
  if ( a3->BufferType != 23
    || (cbBuffer = a3->cbBuffer, a3->cbBuffer < 4)
    || (v12 = (unsigned __int16 *)a3->pvBuffer) == 0i64 )
  {
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      return 2148074278i64;
    v9 = 95i64;
    goto LABEL_37;
  }
  v13 = (unsigned int)*v12 + 2;
  if ( (unsigned int)v13 <= 4 )
  {
    v13 = 4i64;
LABEL_29:
    if ( *((_QWORD *)this + 107) )
      (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
    v14 = (void *)(*(__int64 (__fastcall **)(CSsl3TlsContext *, size_t))(*(_QWORD *)this + 8i64))(this, v13);
    *((_QWORD *)this + 107) = v14;
    if ( v14 )
    {
      memcpy_0(v14, v12, v13);
      return 0i64;
    }
    return 14i64;
  }
  if ( cbBuffer >= (unsigned int)v13 )
    goto LABEL_29;
  v8 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
    return 2148074278i64;
  v9 = 96i64;
LABEL_37:
  WPP_SF_(*((_QWORD *)v8 + 2), v9, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
  return 2148074278i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
