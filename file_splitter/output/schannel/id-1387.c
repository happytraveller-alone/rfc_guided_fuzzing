// File count: 1387
// Total lines: 99
----------------------------------------
__int64 __fastcall CTls13Context::RetrieveGenericExtension(
        __int64 a1,
        __int16 a2,
        int a3,
        __int64 a4,
        unsigned __int16 a5)
{
  __int64 v5; // r10
  unsigned int v6; // ebp
  _WORD *v10; // rcx
  unsigned __int64 v11; // rdx
  char *v12; // rsi
  unsigned __int16 v13; // r14
  const void *v14; // r12
  char *v15; // rax
  __m128i v16; // xmm0
  unsigned int v17; // r15d
  unsigned int v18; // ebx
  char *v19; // rax
  __int128 Src; // [rsp+20h] [rbp-28h]

  v5 = *(_QWORD *)(a1 + 128);
  v6 = 0;
  Src = 0i64;
  if ( !v5 )
    goto LABEL_25;
  if ( *(_BYTE *)(a1 + 136) == 2 )
    goto LABEL_25;
  v10 = (_WORD *)(v5 + 8);
  v11 = v5 + 4 * (*(unsigned int *)(v5 + 4) + 2i64);
  if ( v5 + 8 >= v11 )
    goto LABEL_25;
  while ( (unsigned __int16)v10[1] != a3 || *v10 != a2 )
  {
    v10 += 2;
    if ( (unsigned __int64)v10 >= v11 )
      goto LABEL_25;
  }
  if ( 0xFFFF - a5 < 4 )
  {
    v12 = *(char **)(a1 + 160);
LABEL_21:
    v6 = -2146893052;
    goto LABEL_22;
  }
  v13 = a5 + 4;
  v14 = (const void *)(a4 - 4);
  if ( (unsigned __int16)(a5 + 4) > (unsigned int)~*(_DWORD *)(a1 + 152) )
    goto LABEL_25;
  if ( !*(_QWORD *)(a1 + 160) )
  {
    v15 = (char *)SPExternalAlloc(v13);
    *(_QWORD *)(a1 + 160) = v15;
    v12 = v15;
    if ( !v15 )
      goto LABEL_13;
    *(_DWORD *)(a1 + 152) = v13;
LABEL_19:
    memcpy_0(v12, v14, v13);
    ++*(_BYTE *)(a1 + 136);
    *(_BYTE *)(a1 + 8) = 0;
    goto LABEL_25;
  }
  v16 = *(__m128i *)(a1 + 152);
  *(_QWORD *)(a1 + 160) = 0i64;
  *(_DWORD *)(a1 + 152) = 0;
  v17 = _mm_cvtsi128_si32(v16);
  *((_QWORD *)&Src + 1) = v16.m128i_i64[1];
  if ( !v17 || !v16.m128i_i64[1] )
  {
    v12 = 0i64;
    goto LABEL_21;
  }
  v18 = v17 + v13;
  v19 = (char *)SPExternalAlloc(v18);
  *(_QWORD *)(a1 + 160) = v19;
  v12 = v19;
  if ( v19 )
  {
    *(_DWORD *)(a1 + 152) = v18;
    memcpy_0(v19, (const void *)v16.m128i_i64[1], v17);
    v12 += v17;
    goto LABEL_19;
  }
LABEL_13:
  v6 = -2146893056;
LABEL_22:
  if ( v12 )
  {
    SPExternalFree(v12);
    *(_QWORD *)(a1 + 160) = 0i64;
  }
  *(_DWORD *)(a1 + 152) = 0;
LABEL_25:
  if ( *((_QWORD *)&Src + 1) )
    SPExternalFree(*((void **)&Src + 1));
  return v6;
}
