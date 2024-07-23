// File count: 927
// Total lines: 49
-----------------------------------------
__int64 __fastcall ParseSniExtension(unsigned __int8 *a1, unsigned int a2, struct SPBuffer *a3)
{
  char v3; // r11
  unsigned __int8 *v4; // rcx
  unsigned int v5; // edx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  __int16 v8; // r9
  unsigned int v9; // edx
  __int16 v10; // ax
  unsigned __int8 *v11; // rcx
  unsigned __int16 v12; // r9

  v3 = 0;
  if ( a2 >= 2 && (a1[1] | (*a1 << 8)) >= 3u )
  {
    v4 = a1 + 2;
    v5 = a2 - 2;
    if ( !v5 )
      return 0i64;
    while ( 1 )
    {
      v6 = *v4;
      v7 = v5 - 1;
      if ( v7 < 2 )
        break;
      v8 = v4[1];
      v9 = v7 - 2;
      v10 = v4[2];
      v11 = v4 + 3;
      v12 = v10 | (v8 << 8);
      if ( v9 < v12 )
        break;
      if ( !v6 && !v3 )
      {
        *(_DWORD *)a3 = v12;
        v3 = 1;
        *((_DWORD *)a3 + 1) = v12;
        *((_QWORD *)a3 + 1) = v11;
      }
      v4 = &v11[v12];
      v5 = v9 - v12;
      if ( !v5 )
        return 0i64;
    }
  }
  return 2148074278i64;
}
