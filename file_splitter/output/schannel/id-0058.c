// File count: 58
// Total lines: 40
------------------------------------------
__int64 __fastcall CMasterEccCurveInfo::GetCurveInfo(CMasterEccCurveInfo *this, int a2, struct CEccCurveInfo **a3)
{
  unsigned int v3; // r10d
  unsigned int v4; // r9d
  __int64 v7; // rdi
  unsigned int v8; // edx
  __int64 v9; // rax
  unsigned int v10; // r8d
  __int64 v11; // rbx
  __int64 v12; // rax

  v3 = *((_DWORD *)this + 2);
  v4 = 0;
  if ( !v3 )
    return 1168i64;
  v7 = *(_QWORD *)this;
  while ( 1 )
  {
    v8 = 0;
    v9 = 32i64 * v4;
    v10 = *(_DWORD *)(v9 + v7 + 8);
    if ( v10 )
      break;
LABEL_10:
    if ( ++v4 >= v3 )
      return 1168i64;
  }
  v11 = *(_QWORD *)(v9 + v7);
  while ( 1 )
  {
    v12 = v11 + 780i64 * v8;
    if ( *(_DWORD *)(v12 + 772) == a2 )
      break;
    if ( ++v8 >= v10 )
      goto LABEL_10;
  }
  *a3 = (struct CEccCurveInfo *)v12;
  return 0i64;
}
