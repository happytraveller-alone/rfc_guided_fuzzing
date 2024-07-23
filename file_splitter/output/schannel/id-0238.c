// File count: 238
// Total lines: 54
-----------------------------------------
__int64 __fastcall CMasterEccCurveInfo::GetEccCurveType(CMasterEccCurveInfo *this, char *a2, unsigned int *a3)
{
  unsigned int v3; // r9d
  unsigned int v4; // r11d
  __int64 v7; // rbp
  unsigned int v8; // ecx
  __int64 v9; // rdx
  __int64 v10; // r14
  __int64 v11; // r8
  char *v12; // rsi
  int v13; // ebx
  int v14; // eax
  __int64 result; // rax

  *a3 = 0;
  v3 = 0;
  v4 = *((_DWORD *)this + 2);
  if ( !v4 )
    return 1168i64;
  v7 = *(_QWORD *)this;
  while ( 1 )
  {
    v8 = 0;
    v9 = 32i64 * v3;
    if ( *(_DWORD *)(v9 + v7 + 8) )
      break;
LABEL_12:
    if ( ++v3 >= v4 )
      return 1168i64;
  }
  v10 = *(_QWORD *)(v9 + v7);
  while ( 1 )
  {
    v11 = 780i64 * v8 + v10 + 510;
    v12 = &a2[-v11];
    do
    {
      v13 = (unsigned __int8)v12[v11];
      v14 = *(unsigned __int8 *)v11 - v13;
      if ( v14 )
        break;
      ++v11;
    }
    while ( v13 );
    if ( !v14 )
      break;
    if ( ++v8 >= *(_DWORD *)(v9 + v7 + 8) )
      goto LABEL_12;
  }
  result = 0i64;
  *a3 = *(_DWORD *)(780i64 * v8 + v10 + 772);
  return result;
}
