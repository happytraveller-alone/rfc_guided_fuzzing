// File count: 1104
// Total lines: 10
----------------------------------------
unsigned __int16 __fastcall CSslScratchAllocator::GetLengthNeeded(CSslScratchAllocator *this)
{
  unsigned __int16 result; // ax

  result = *((_WORD *)this + 10);
  if ( result <= *((_WORD *)this + 9) )
    return *((_WORD *)this + 9);
  return result;
}
