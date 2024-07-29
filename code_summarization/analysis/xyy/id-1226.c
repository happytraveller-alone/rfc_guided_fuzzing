//----- (0000000180061DDC) ----------------------------------------------------
__int64 __fastcall CCipherMill::GetEccCurveFlags(CCipherMill *this, int a2, unsigned int *a3)
{
  unsigned int EccCurveFlags; // ebx

  if ( !a2 || !a3 )
    return 87i64;
  if ( !qword_1800925C8 )
    return 1359i64;
  RtlAcquireResourceShared(&Resource, 1u);
  EccCurveFlags = CMasterEccCurveInfo::GetEccCurveFlags(qword_1800925C8, a2, a3);
  RtlReleaseResource(&Resource);
  return EccCurveFlags;
}

