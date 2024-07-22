//----- (000000018005E0E0) ----------------------------------------------------
CSslLookasidePreallocate *__fastcall CSslLookasidePreallocate::`scalar deleting destructor'(
        CSslLookasidePreallocate *this,
        char a2)
{
  CSslLookasidePreallocate::~CSslLookasidePreallocate(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

