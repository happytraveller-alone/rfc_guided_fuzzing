//----- (0000000180003D20) ----------------------------------------------------
__int64 __fastcall CMasterEccCurveInfo::Dereference(CMasterEccCurveInfo *this)
{
  unsigned __int32 v1; // ebx

  v1 = _InterlockedDecrement((volatile signed __int32 *)this + 3);
  if ( !v1 )
    SPExternalFree(this);
  return v1;
}

