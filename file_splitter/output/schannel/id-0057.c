// File count: 57
// Total lines: 13
------------------------------------------
__int64 __fastcall CCipherMill::GetCurveInfo(CCipherMill *this, int a2, struct CEccCurveInfo **a3)
{
  unsigned int CurveInfo; // ebx

  RtlAcquireResourceShared(&Resource, 1u);
  if ( a2 && a3 && qword_1800925C8 )
    CurveInfo = CMasterEccCurveInfo::GetCurveInfo(qword_1800925C8, a2, a3);
  else
    CurveInfo = 87;
  RtlReleaseResource(&Resource);
  return CurveInfo;
}
