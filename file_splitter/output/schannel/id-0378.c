// File count: 378
// Total lines: 5
------------------------------------------
void *__fastcall CSslScratchAllocator::GetScratchBuffer(CSslScratchAllocator *this)
{
  return (void *)*((_QWORD *)this + 1);
}
