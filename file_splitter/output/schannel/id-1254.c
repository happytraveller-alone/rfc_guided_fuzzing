// File count: 1254
// Total lines: 23
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::ComputeALPNExtensionSize(CTls13ClientHandshake *this)
{
  __int64 v1; // rax
  __int64 v2; // rax
  unsigned __int16 v3; // dx

  v1 = *((_QWORD *)this + 1);
  *((_WORD *)this + 82) = 0;
  v2 = *(_QWORD *)(v1 + 784);
  if ( v2 )
  {
    v3 = *(_WORD *)(v2 + 4);
    if ( v3 > 0xFFFDu )
      return 87i64;
    if ( v2 != -6 )
    {
      if ( v3 )
        *((_WORD *)this + 82) = v3 + 2;
    }
  }
  return 0i64;
}
