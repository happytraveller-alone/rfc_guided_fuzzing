//----- (000000018007ACD0) ----------------------------------------------------
__int64 __fastcall PAC_UnMarshal(unsigned __int64 a1, unsigned int a2)
{
  unsigned int v2; // r8d
  char *v3; // r11
  unsigned int v4; // r9d
  unsigned int v5; // edi
  unsigned __int64 v6; // rax
  unsigned int v7; // ebx
  char *i; // rdx
  char *v9; // r10
  int v10; // esi
  __int64 v11; // rax

  v2 = 0;
  v3 = (char *)(a1 + a2);
  v4 = 0;
  if ( a2 >= 0x18 )
  {
    v5 = *(_DWORD *)a1;
    v6 = 16i64 * *(unsigned int *)a1;
    if ( v6 <= 0xFFFFFFFF && (int)v6 + 24 >= (unsigned int)v6 && (int)v6 + 24 <= a2 && !*(_DWORD *)(a1 + 4) )
    {
      v7 = 0;
      if ( !v5 )
        return v4;
      for ( i = (char *)(a1 + 12); ; i += 16 )
      {
        v9 = (char *)(a1 + *(_QWORD *)(i + 4));
        if ( v9 > v3 )
          break;
        if ( (unsigned __int64)v9 < a1 )
          break;
        v10 = *(_DWORD *)i;
        if ( *(_DWORD *)i > (unsigned int)((_DWORD)v3 - (_DWORD)v9) || v10 + v4 < v4 )
          break;
        ++v7;
        v4 += v10;
        if ( v7 >= v5 )
        {
          do
          {
            v11 = v2++;
            *(_QWORD *)(a1 + 16 * (v11 + 1)) += a1;
          }
          while ( v2 < *(_DWORD *)a1 );
          return v4;
        }
      }
    }
  }
  return 0i64;
}

