//----- (0000000180060AAC) ----------------------------------------------------
__int64 __fastcall FormatIssuerList(unsigned __int8 *a1, unsigned int a2, unsigned __int8 *a3, unsigned int *a4)
{
  unsigned int v4; // ebp
  unsigned int v7; // r15d
  int v9; // esi
  unsigned int v10; // r15d
  int v11; // eax
  unsigned __int8 *v12; // r14
  unsigned int v13; // esi
  unsigned int v14; // ebp
  unsigned int v15; // eax

  v4 = 0;
  v7 = a2;
  if ( a2 )
  {
    while ( v7 >= 2 )
    {
      v9 = *a1;
      v10 = v7 - 2;
      v11 = a1[1];
      v12 = a1 + 2;
      v13 = v11 | (v9 << 8);
      if ( v10 < v13 )
        break;
      if ( a3 )
      {
        a3[1] = v13;
        *a3 = BYTE1(v13);
        a3 += 2;
      }
      v14 = v4 + 2;
      if ( *v12 != 48 )
      {
        v15 = CbLenOfEncode(v13, a3);
        if ( a3 )
          a3 += v15;
        v14 += v15;
      }
      if ( a3 )
      {
        memcpy_0(a3, v12, v13);
        a3 += v13;
      }
      v4 = v13 + v14;
      a1 = &v12[v13];
      v7 = v10 - v13;
      if ( !v7 )
        goto LABEL_13;
    }
    return 2148074278i64;
  }
  else
  {
LABEL_13:
    *a4 = v4;
    return 0i64;
  }
}

