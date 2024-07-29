//----- (000000018004D7A0) ----------------------------------------------------
__int64 __fastcall ParseClientHello(unsigned __int8 *a1, unsigned int a2, struct SPBuffer *a3)
{
  unsigned int v3; // r9d
  unsigned int v5; // r10d
  unsigned int v6; // edx
  unsigned int v7; // edx
  __int64 v8; // r8
  unsigned int v9; // edx
  unsigned int v10; // edx
  unsigned __int8 *v11; // r11
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned __int8 *v16; // r8
  __int64 v17; // rax
  unsigned int v18; // edx
  unsigned int v19; // edx
  unsigned int v20; // r9d
  __int64 result; // rax

  v3 = 0;
  if ( a2 < 2 )
    return 2148074278i64;
  v5 = a1[1] + (*a1 << 8);
  if ( v5 < 0x300 )
    return 2148074278i64;
  v6 = a2 - 2;
  if ( v6 < 0x20 )
    return 2148074278i64;
  v7 = v6 - 32;
  if ( !v7 )
    return 2148074278i64;
  v8 = a1[34];
  if ( (unsigned int)v8 > 0x20 )
    return 2148074278i64;
  v9 = v7 - 1;
  if ( v9 < (unsigned int)v8 )
    return 2148074278i64;
  v10 = v9 - v8;
  v11 = &a1[v8 + 35];
  if ( v10 < 2 )
    return 2148074278i64;
  v12 = v11[1];
  v13 = v12 + (*v11 << 8);
  if ( (v12 & 1) != 0 )
    return 2148074278i64;
  v14 = v10 - 2;
  if ( v14 < v13 )
    return 2148074278i64;
  v15 = v14 - v13;
  v16 = &v11[v13];
  if ( !v15 )
    return 2148074278i64;
  v17 = v16[2];
  if ( !v16[2] )
    return 2148074278i64;
  v18 = v15 - 1;
  if ( v18 < (unsigned int)v17 )
    return 2148074278i64;
  v19 = v18 - v17;
  if ( v5 < 0x301 )
    return v3;
  if ( v19 >= 2 )
  {
    v20 = v16[v17 + 4] | (v16[v17 + 3] << 8);
    if ( v19 - 2 >= v20 )
    {
      result = ParseTlsHelloExtensions(&v16[v16[2] + 5], v20, a3);
      v3 = result;
      if ( (_DWORD)result )
        return result;
      return v3;
    }
  }
  return 0i64;
}

