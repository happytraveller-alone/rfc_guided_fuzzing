//----- (000000018005B0C0) ----------------------------------------------------
unsigned __int16 __fastcall CSslScratchAllocator::GetLengthNeeded(CSslScratchAllocator *this)
{
  unsigned __int16 result; // ax

  result = *((_WORD *)this + 10);
  if ( result <= *((_WORD *)this + 9) )
    return *((_WORD *)this + 9);
  return result;
}

