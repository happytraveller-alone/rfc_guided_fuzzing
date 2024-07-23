// File count: 66
// Total lines: 39
------------------------------------------
__int64 __fastcall CMasterEccCurveInfo::GetPublicKeyLength(CMasterEccCurveInfo *this, int a2, unsigned int *a3)
{
  unsigned int v3; // r9d
  unsigned int v4; // r11d
  __int64 v6; // rdi
  unsigned int v7; // ecx
  __int64 v8; // rax
  unsigned int v9; // ebx
  __int64 v10; // r8
  __int64 result; // rax

  *a3 = 0;
  v3 = 0;
  v4 = *((_DWORD *)this + 2);
  if ( !v4 )
    return 1168i64;
  v6 = *(_QWORD *)this;
  while ( 1 )
  {
    v7 = 0;
    v8 = 32i64 * v3;
    v9 = *(_DWORD *)(v8 + v6 + 8);
    if ( v9 )
      break;
LABEL_10:
    if ( ++v3 >= v4 )
      return 1168i64;
  }
  v10 = *(_QWORD *)(v8 + v6);
  while ( *(_DWORD *)(780i64 * v7 + v10 + 772) != a2 )
  {
    if ( ++v7 >= v9 )
      goto LABEL_10;
  }
  result = 0i64;
  *a3 = *(_DWORD *)(780i64 * v7 + v10 + 768);
  return result;
}
