//----- (000000018005E280) ----------------------------------------------------
void __fastcall CSslScratchAllocator::Deallocate(CSslScratchAllocator *this, void *a2)
{
  unsigned __int64 v2; // r8

  v2 = *((_QWORD *)this + 1);
  if ( !v2 || (unsigned __int64)a2 < v2 || (unsigned __int64)a2 > v2 + *((unsigned __int16 *)this + 8) )
    SPExternalFree(a2);
}

