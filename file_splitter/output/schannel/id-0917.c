// File count: 917
// Total lines: 9
------------------------------------------
IAllocate *__fastcall IAllocate::`vector deleting destructor'(IAllocate *this, char a2)
{
  *(_QWORD *)this = &IAllocate::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this, 8ui64);
  return this;
}
// 18007C298: using guessed type void *IAllocate::`vftable';
