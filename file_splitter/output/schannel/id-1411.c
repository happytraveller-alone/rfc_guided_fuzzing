// File count: 1411
// Total lines: 35
----------------------------------------
__int64 __fastcall CTlsMessageFragment::Reallocate(CTlsMessageFragment *this, unsigned int a2)
{
  unsigned int v2; // edi
  HLOCAL Memory; // rax
  HLOCAL v5; // rsi
  __int64 result; // rax

  v2 = a2;
  if ( a2 <= *((_DWORD *)this + 3) )
    v2 = *((_DWORD *)this + 3);
  Memory = CSslContext::GetMemory(*(CSslContext **)this, v2);
  v5 = Memory;
  if ( Memory )
  {
    if ( *((_DWORD *)this + 9) )
      memcpy_0(Memory, *((const void **)this + 3), *((unsigned int *)this + 9));
    if ( *((_QWORD *)this + 3) )
      (*(void (__fastcall **)(_QWORD))(**(_QWORD **)this + 16i64))(*(_QWORD *)this);
    *((_DWORD *)this + 4) = v2;
    result = 0i64;
    *((_QWORD *)this + 3) = v5;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_d(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x46u,
        (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
        v2);
    return 14i64;
  }
  return result;
}
