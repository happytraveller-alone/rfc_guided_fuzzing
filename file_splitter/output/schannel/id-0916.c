// File count: 916
// Total lines: 14
-----------------------------------------
CSslCredManager *__fastcall CSslCredManager::`vector deleting destructor'(CSslCredManager *this, char a2)
{
  *(_QWORD *)this = &IAllocate::`vftable';
  if ( (a2 & 1) != 0 )
  {
    if ( (a2 & 4) != 0 )
      __global_delete(this, 0x60ui64);
    else
      SPExternalFree(this);
  }
  return this;
}
// 18007C298: using guessed type void *IAllocate::`vftable';
