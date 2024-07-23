// File count: 1180
// Total lines: 10
----------------------------------------
CSslLookasidePreallocate *__fastcall CSslLookasidePreallocate::`scalar deleting destructor'(
        CSslLookasidePreallocate *this,
        char a2)
{
  CSslLookasidePreallocate::~CSslLookasidePreallocate(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
