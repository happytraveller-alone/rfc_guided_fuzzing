//----- (000000018005AA90) ----------------------------------------------------
CSslScratchAllocator *__fastcall CSslScratchAllocator::`vector deleting destructor'(
        CSslScratchAllocator *this,
        char a2)
{
  *(_QWORD *)this = &IAllocate::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
// 18007C298: using guessed type void *IAllocate::`vftable';

