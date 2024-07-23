// File count: 1241
// Total lines: 46
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::SetServerNameIndication(
        CSsl3TlsServerContext *this,
        const unsigned __int8 *Src,
        unsigned __int16 a3)
{
  size_t v3; // rbx
  const void *v6; // rcx
  HLOCAL Memory; // rax

  v3 = a3;
  if ( !Src || !a3 )
    return 87i64;
  v6 = (const void *)*((_QWORD *)this + 118);
  if ( v6 )
  {
    if ( *((_WORD *)this + 476) != a3 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_dd(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x3Au,
          (__int64)&WPP_095c39149c3f336b5b94efe855075ae2_Traceguids,
          a3,
          *((unsigned __int16 *)this + 476));
      return 2148074278i64;
    }
    if ( RtlCompareMemory(v6, Src, a3) != a3 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      return 2148074278i64;
    }
  }
  else
  {
    Memory = CSslContext::GetMemory(this, a3);
    *((_QWORD *)this + 118) = Memory;
    if ( !Memory )
      return 2148074240i64;
    memcpy_0(Memory, Src, v3);
    *((_WORD *)this + 476) = v3;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
