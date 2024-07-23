// File count: 471
// Total lines: 40
-----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::PreparseMessage(CSsl3TlsServerContext *this, struct SPBuffer *a2)
{
  int v2; // eax
  unsigned int v3; // ebx
  __int64 v7; // r8
  bool v8; // al
  int v9; // ecx

  v2 = *((_DWORD *)this + 17);
  v3 = 0;
  if ( v2 == 4 )
  {
    if ( *((_DWORD *)a2 + 1) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 28i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      *((_DWORD *)this + 17) = 76;
    }
    return v3;
  }
  if ( v2 != 20 )
    return v3;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
  v7 = *((unsigned int *)a2 + 1);
  if ( (unsigned int)v7 >= 3 )
  {
    v3 = CSsl3TlsServerContext::DigestUnifiedHello(this, *((unsigned __int8 **)a2 + 1), v7);
    v8 = IsFatalError(v3);
    v9 = 93;
    if ( v8 )
      v9 = 96;
    *((_DWORD *)this + 17) = v9;
    return v3;
  }
  *((_DWORD *)a2 + 1) = 3;
  return 2148074264i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
