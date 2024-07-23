// File count: 913
// Total lines: 16
-----------------------------------------
CSessionCacheManager *__fastcall CSessionCacheManager::`vector deleting destructor'(
        CSessionCacheManager *this,
        char a2)
{
  *(_QWORD *)this = &IAllocate::`vftable';
  if ( (a2 & 1) != 0 )
  {
    if ( (a2 & 4) != 0 )
      __global_delete(this, 0x68ui64);
    else
      SPExternalFree(this);
  }
  return this;
}
// 18007C298: using guessed type void *IAllocate::`vftable';
