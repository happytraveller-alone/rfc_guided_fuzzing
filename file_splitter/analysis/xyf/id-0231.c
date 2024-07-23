//----- (00000001800136A0) ----------------------------------------------------
__int64 __fastcall CreateNewEventEntry(
        __int128 *a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned __int8 a4,
        int a5,
        __int64 *a6)
{
  unsigned __int8 v6; // di
  __int64 v7; // rbp
  __int64 v9; // r8
  int v10; // r14d
  __int64 v11; // rdx
  unsigned __int8 v12; // r9
  unsigned int *v13; // r10
  __int64 v14; // rcx
  __int64 v15; // rax
  SIZE_T v16; // rsi
  HANDLE ProcessHeap; // rax
  __int64 NextOffset; // r12
  unsigned int v19; // edx
  void *v20; // rbx
  __int64 v21; // rdx
  __int64 v22; // rdi
  __int128 v23; // xmm0
  unsigned __int8 v24; // r14
  const void **v25; // rsi
  __int64 v26; // r12
  __int64 v27; // rbp
  unsigned int v28; // edx
  void *v29; // rbx
  char *v30; // rdx
  int v31; // eax
  __int64 v33[7]; // [rsp+20h] [rbp-38h] BYREF

  v6 = 0;
  v7 = a2;
  v33[0] = 0i64;
  v9 = 0i64;
  v10 = a4;
  v11 = 0i64;
  v12 = 0;
  *a6 = 0i64;
  if ( (_BYTE)v7 )
  {
    v13 = (unsigned int *)(a3 + 8);
    do
    {
      v14 = *v13;
      v13 += 4;
      if ( v12 >= 2u )
        v11 += v14;
      v15 = v14 + v9;
      if ( v12 >= 2u )
        v15 = v9;
      ++v12;
      v9 = v15;
    }
    while ( v12 < (unsigned __int8)v7 );
    if ( (unsigned __int64)(v11 + v15) > 0xFFFF )
      return 534i64;
  }
  v16 = v11 + 16 * v7 + 46;
  if ( !v16 )
    return 8i64;
  ProcessHeap = GetProcessHeap();
  v33[0] = (__int64)HeapAlloc(ProcessHeap, 8u, v16);
  if ( !v33[0] )
    return 8i64;
  v33[1] = v16;
  NextOffset = CBufferGetNextOffset(v33, 16 * v7);
  do
  {
    if ( v6 < 2u )
    {
      *(_OWORD *)(NextOffset + 16i64 * v6) = *(_OWORD *)(a3 + 16i64 * v6);
    }
    else
    {
      v20 = (void *)CBufferGetNextOffset(v33, *(unsigned int *)(a3 + 16i64 * v6 + 8));
      memcpy_0(v20, *(const void **)(a3 + 16i64 * v6), v19);
      *(_QWORD *)(NextOffset + 16i64 * v6) = v20;
      *(_DWORD *)(NextOffset + 16i64 * v6 + 12) = *(_DWORD *)(a3 + 16i64 * v6 + 12);
      *(_DWORD *)(NextOffset + 16i64 * v6 + 8) = *(_DWORD *)(a3 + 16i64 * v6 + 8);
    }
    ++v6;
  }
  while ( v6 < (unsigned int)(v10 + 2) );
  v22 = CBufferGetNextOffset(v33, 0x2Eui64);
  *(_QWORD *)(v22 + 16) = NextOffset;
  v23 = *a1;
  *(_BYTE *)(v22 + 45) = v10;
  v24 = v10 + 2;
  *(_BYTE *)(v22 + 44) = v7;
  *(_DWORD *)(v22 + 40) = a5;
  *(_OWORD *)v22 = v23;
  if ( v24 < (unsigned __int8)v7 )
  {
    v25 = (const void **)(16i64 * v24 + a3 + 8);
    v26 = v21 - 54 - a3;
    v27 = (unsigned __int8)(v7 - v24);
    do
    {
      v29 = (void *)CBufferGetNextOffset(v33, *(unsigned int *)v25);
      memcpy_0(v29, *(v25 - 1), v28);
      v30 = (char *)v25 + v26;
      *(_QWORD *)&v30[*(_QWORD *)(v22 + 16)] = v29;
      *(_DWORD *)&v30[*(_QWORD *)(v22 + 16) + 12] = *((_DWORD *)v25 + 1);
      v31 = *(_DWORD *)v25;
      v25 += 2;
      *(_DWORD *)&v30[*(_QWORD *)(v22 + 16) + 8] = v31;
      --v27;
    }
    while ( v27 );
  }
  *a6 = v22;
  return 0i64;
}
// 180013786: conditional instruction was optimized away because r14d.4<100u
// 1800137A8: variable 'v19' is possibly undefined
// 180013827: variable 'v21' is possibly undefined
// 180013844: variable 'v28' is possibly undefined

