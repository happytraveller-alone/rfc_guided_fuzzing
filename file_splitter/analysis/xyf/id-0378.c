//----- (0000000180018570) ----------------------------------------------------
void *__fastcall CSslScratchAllocator::GetScratchBuffer(CSslScratchAllocator *this)
{
  return (void *)*((_QWORD *)this + 1);
}

