// File count: 574
// Total lines: 28
-----------------------------------------
char __fastcall _scrt_initialize_onexit_tables(unsigned int a1)
{
  if ( !byte_180092000 )
  {
    if ( a1 > 1 )
    {
      _scrt_fastfail(5u);
      JUMPOUT(0x1800286F2i64);
    }
    if ( !_scrt_is_ucrt_dll_in_use() || a1 )
    {
      *(__m128i *)&Table._first = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
      Table._end = (_PVFV *)-1i64;
      *(_OWORD *)&stru_180091FE8._first = *(_OWORD *)&Table._first;
      stru_180091FE8._end = (_PVFV *)-1i64;
    }
    else if ( initialize_onexit_table(&Table) || initialize_onexit_table(&stru_180091FE8) )
    {
      return 0;
    }
    byte_180092000 = 1;
  }
  return 1;
}
// 1800286ED: control flows out of bounds to 1800286F2
// 180082770: using guessed type __int128 _xmm_ffffffffffffffffffffffffffffffff;
// 180092000: using guessed type char byte_180092000;
