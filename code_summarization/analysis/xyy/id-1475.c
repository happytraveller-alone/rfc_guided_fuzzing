//----- (0000000180076CA8) ----------------------------------------------------
__int64 __fastcall Ssl2UnpackClientHello(struct SPBuffer *a1, struct _Ssl2_Client_Hello **a2, __int64 a3, int *a4)
{
  unsigned __int8 *v4; // rdi
  unsigned __int64 v5; // r8
  unsigned int v10; // edx
  unsigned int v11; // r14d
  __int64 v12; // r15
  __int64 v13; // r13
  unsigned __int64 v14; // r9
  unsigned __int64 v15; // rsi
  _DWORD *v16; // rbx
  int v17; // ecx
  int v18; // eax
  unsigned __int8 *v19; // rdi
  int *v20; // rdx
  __int64 v21; // r8
  int v22; // eax
  int v23; // ecx
  int v24; // ecx
  unsigned __int8 *v25; // rdi

  v4 = (unsigned __int8 *)*((_QWORD *)a1 + 1);
  LODWORD(v5) = 0;
  if ( *((_DWORD *)a1 + 1) < 2u )
  {
    *((_DWORD *)a1 + 1) = 2;
    return 2148074264i64;
  }
  v10 = ((((char)*v4 >> 31) & 0x4000) + 0x3FFF) & (v4[1] | (*v4 << 8));
  v11 = v10 + 2;
  if ( v10 + 2 > *((_DWORD *)a1 + 1) )
  {
    *((_DWORD *)a1 + 1) = v11;
    return 2148074264i64;
  }
  if ( v10 >= 0xB && v4[2] == 1 && (v4[4] | (v4[3] << 8)) >= 2u )
  {
    *a2 = 0i64;
    v12 = v4[8] | (v4[7] << 8);
    v13 = v4[10] | (v4[9] << 8);
    v14 = v4[6] | ((unsigned __int64)v4[5] << 8);
    if ( v12 + v13 + v14 + 9 <= v10 )
    {
      v15 = v14 / 3;
      if ( (unsigned int)(v14 / 3) > 0x44 )
      {
        v5 = 4i64 * (unsigned int)(v15 - 68);
        if ( v5 > 0xFFFFFFFF )
          return 534i64;
      }
      v16 = SPExternalAlloc((int)v5 + 352);
      if ( !v16 )
        return 2148074244i64;
      v17 = v4[3];
      v18 = v4[4];
      v19 = v4 + 11;
      v16[1] = v15;
      *v16 = v18 | (v17 << 8);
      if ( (_DWORD)v15 )
      {
        v20 = v16 + 20;
        v21 = (unsigned int)v15;
        do
        {
          v22 = v19[2];
          v23 = (v19[1] | (*v19 << 8)) << 8;
          v19 += 3;
          v24 = v22 | v23;
          *v20 = v24;
          if ( v24 == 255 && a4 )
            *a4 = 1;
          ++v20;
          --v21;
        }
        while ( v21 );
      }
      if ( (unsigned int)v12 <= 0x10 )
      {
        memcpy_0(v16 + 4, v19, (unsigned int)v12);
        v16[2] = v12;
        v25 = &v19[(unsigned int)v12];
        if ( (unsigned int)(v13 - 1) <= 0x1F )
        {
          memcpy_0(v16 + 12, v25, (unsigned int)v13);
          v16[3] = v13;
          *((_DWORD *)a1 + 1) = v11;
          *a2 = (struct _Ssl2_Client_Hello *)v16;
          return 0i64;
        }
      }
      SPExternalFree(v16);
    }
  }
  return 2148074278i64;
}
