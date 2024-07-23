// File count: 78
// Total lines: 96
------------------------------------------
__int64 __fastcall CSessionCacheManager::ComputeClientCacheIndex(
        CSessionCacheManager *this,
        const unsigned __int16 *a2)
{
  unsigned int v4; // edx
  __int64 v5; // rax
  __int64 v6; // r10
  __int64 v7; // r8
  unsigned __int64 v8; // r11
  __int64 v9; // rcx
  __int64 v10; // rax
  int v12; // r10d
  int v13; // r10d
  int v14; // r10d
  int v15; // r10d
  int v16; // r10d
  int v17; // r10d

  v4 = 0;
  if ( a2 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( a2[v5] );
    v6 = (unsigned int)(2 * v5);
    v7 = 314159i64;
    if ( (unsigned __int64)v6 >= 8 )
    {
      v8 = (unsigned __int64)(unsigned int)v6 >> 3;
      v6 -= 8 * v8;
      do
      {
        v9 = *((unsigned __int8 *)a2 + 6)
           + 37
           * (*((unsigned __int8 *)a2 + 5)
            + 37
            * (*((unsigned __int8 *)a2 + 4)
             + 37
             * (*((unsigned __int8 *)a2 + 3)
              + 37
              * (*((unsigned __int8 *)a2 + 2)
               + 37 * (*((unsigned __int8 *)a2 + 1) + 37 * (*(unsigned __int8 *)a2 + 37 * v7))))));
        v10 = *((unsigned __int8 *)a2 + 7);
        a2 += 4;
        v7 = v10 + 37 * v9;
        --v8;
      }
      while ( v8 );
    }
    if ( v6 < 1 || v6 > 7 )
      return (unsigned int)v7 % *((_DWORD *)this + 4);
    v12 = v6 - 1;
    if ( v12 )
    {
      v13 = v12 - 1;
      if ( v13 )
      {
        v14 = v13 - 1;
        if ( v14 )
        {
          v15 = v14 - 1;
          if ( v15 )
          {
            v16 = v15 - 1;
            if ( v16 )
            {
              v17 = v16 - 1;
              if ( v17 )
              {
                if ( v17 != 1 )
                  return (unsigned int)v7 % *((_DWORD *)this + 4);
                LODWORD(v7) = *(unsigned __int8 *)a2 + 37 * v7;
                a2 = (const unsigned __int16 *)((char *)a2 + 1);
              }
              LODWORD(v7) = *(unsigned __int8 *)a2 + 37 * v7;
              a2 = (const unsigned __int16 *)((char *)a2 + 1);
            }
            LODWORD(v7) = *(unsigned __int8 *)a2 + 37 * v7;
            a2 = (const unsigned __int16 *)((char *)a2 + 1);
          }
          LODWORD(v7) = *(unsigned __int8 *)a2 + 37 * v7;
          a2 = (const unsigned __int16 *)((char *)a2 + 1);
        }
        LODWORD(v7) = *(unsigned __int8 *)a2 + 37 * v7;
        a2 = (const unsigned __int16 *)((char *)a2 + 1);
      }
      LODWORD(v7) = *(unsigned __int8 *)a2 + 37 * v7;
      a2 = (const unsigned __int16 *)((char *)a2 + 1);
    }
    LODWORD(v7) = *(unsigned __int8 *)a2 + 37 * v7;
    return (unsigned int)v7 % *((_DWORD *)this + 4);
  }
  return v4;
}
