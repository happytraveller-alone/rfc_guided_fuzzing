// File count: 1228
// Total lines: 41
----------------------------------------
__int64 __fastcall FilterFipsEccCurves(__int64 a1, unsigned int *a2)
{
  unsigned int v2; // r8d
  unsigned int v3; // r9d
  unsigned int i; // r10d
  unsigned int v5; // r11d
  int v6; // ebx
  _DWORD *v7; // rax
  __int64 v8; // rax

  v2 = 0;
  v3 = 0;
  if ( a1 && a2 )
  {
    for ( i = 0; i < *a2; ++i )
    {
      v5 = 0;
      v6 = *(_DWORD *)(a1 + 4i64 * i);
      v7 = &unk_180085820;
      while ( v6 != *v7 )
      {
        ++v5;
        ++v7;
        if ( v5 >= 3 )
          goto LABEL_9;
      }
      v8 = v3++;
      *(_DWORD *)(a1 + 4 * v8) = v6;
LABEL_9:
      if ( v3 == 3 )
        break;
    }
    *a2 = v3;
  }
  else
  {
    return (unsigned int)-1073741811;
  }
  return v2;
}
