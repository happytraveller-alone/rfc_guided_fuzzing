//----- (000000018004D100) ----------------------------------------------------
CSslBasicAllocator *__fastcall CSslBasicAllocator::`vector deleting destructor'(CSslBasicAllocator *this, char a2)
{
  *(_QWORD *)this = &IAllocate::`vftable';
  if ( (a2 & 1) != 0 )
  {
    if ( (a2 & 4) != 0 )
      __global_delete(this, 8ui64);
    else
      SPExternalFree(this);
  }
  return this;
}
// 18007C298: using guessed type void *IAllocate::`vftable';

