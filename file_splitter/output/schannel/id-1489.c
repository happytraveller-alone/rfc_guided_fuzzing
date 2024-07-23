// File count: 1489
// Total lines: 19
----------------------------------------
__int64 __fastcall CNulRecord::WritePlaintext(void **this, unsigned __int16 a2, const unsigned __int8 *a3)
{
  __int64 v3; // rsi
  _DWORD *v6; // rax

  v3 = a2;
  if ( a2 )
  {
    if ( !a3 )
      return 87i64;
    memcpy_0(this[8], a3, a2);
    v6 = this[6];
    this[8] = (char *)this[8] + v3;
    *((_DWORD *)this + 18) += v3;
    v6[1] += v3;
  }
  return 0i64;
}
