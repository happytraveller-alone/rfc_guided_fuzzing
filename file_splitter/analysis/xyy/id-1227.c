//----- (0000000180061E5C) ----------------------------------------------------
__int64 __fastcall CMasterEccCurveInfo::GetEccCurveFlags(CMasterEccCurveInfo *this, int a2, unsigned int *a3)
{
  unsigned __int64 v3; // r9
  unsigned __int64 v4; // r10
  unsigned __int64 i; // rcx

  v3 = *(_QWORD *)this;
  v4 = *(_QWORD *)this + 32i64 * *((unsigned int *)this + 2);
LABEL_7:
  if ( v3 >= v4 )
    return 1168i64;
  for ( i = *(_QWORD *)v3; ; i += 780i64 )
  {
    if ( i >= *(_QWORD *)v3 + 780 * (unsigned __int64)*(unsigned int *)(v3 + 8) )
    {
      v3 += 32i64;
      goto LABEL_7;
    }
    if ( *(_DWORD *)(i + 772) == a2 )
      break;
  }
  *a3 = *(_DWORD *)(i + 776);
  return 0i64;
}
