// File count: 1178
// Total lines: 12
----------------------------------------
void __fastcall CSslLookasidePreallocate::~CSslLookasidePreallocate(CSslLookasidePreallocate *this)
{
  void *v2; // rcx

  *(_QWORD *)this = &CSslLookasidePreallocate::`vftable';
  v2 = (void *)*((_QWORD *)this + 12);
  if ( v2 )
    VirtualFree(v2, 0i64, 0x8000u);
  CSslLookaside::~CSslLookaside(this);
}
// 18007FCF8: using guessed type void *CSslLookasidePreallocate::`vftable';
