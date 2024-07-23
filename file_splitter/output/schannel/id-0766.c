// File count: 766
// Total lines: 15
-----------------------------------------
void *__fastcall operator new(size_t Size)
{
  size_t i; // rdi
  void *v2; // rbx

  for ( i = Size; ; Size = i )
  {
    v2 = o_malloc_0(Size);
    if ( v2 || !(unsigned int)o__callnewh_0(i) )
      break;
  }
  return v2;
}
// 180028C9E: using guessed type __int64 __fastcall o__callnewh_0(_QWORD);
