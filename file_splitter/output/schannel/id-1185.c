// File count: 1185
// Total lines: 18
----------------------------------------
void __fastcall CSslScratchAllocator::Reset(CSslScratchAllocator *this)
{
  unsigned __int16 v1; // ax
  unsigned __int16 *v3; // rcx

  v1 = *((_WORD *)this + 10);
  if ( v1 > *((_WORD *)this + 9) )
    *((_WORD *)this + 9) = v1;
  *((_WORD *)this + 10) = 0;
  v3 = (unsigned __int16 *)*((_QWORD *)this + 1);
  if ( v3 )
  {
    memset_0(v3 + 2, 0, *v3);
    **((_WORD **)this + 1) = 0;
    *((_WORD *)this + 10) = *((_WORD *)this + 8) - *(_WORD *)(*((_QWORD *)this + 1) + 2i64) - 4;
  }
}
