// File count: 154
// Total lines: 159
----------------------------------------
__int64 __fastcall ParseInputBufferDesc(
        struct _SecBufferDesc *a1,
        struct _SecBuffer **a2,
        struct SPBuffer *a3,
        struct _SecBuffer **a4,
        struct _SecBuffer **a5,
        struct _SecBuffer **a6,
        struct _SecBuffer **a7,
        struct _SecBuffer **a8,
        struct _SecBuffer **a9,
        struct _SecBuffer **a10,
        struct _SecBuffer **a11,
        struct _SecBuffer **a12,
        struct _SecBuffer **a13)
{
  unsigned int cBuffers; // r11d
  unsigned int cbBuffer; // r10d
  struct SPBuffer *v15; // rsi
  struct _SecBuffer *v16; // rbx
  struct _SecBuffer *v17; // rdi
  struct _SecBuffer *v18; // rbp
  struct _SecBuffer *v19; // r14
  struct _SecBuffer *v20; // r15
  struct _SecBuffer *v21; // r12
  struct _SecBuffer *v22; // r13
  unsigned int v23; // eax
  PSecBuffer pBuffers; // r9
  unsigned int *p_BufferType; // r8
  int v26; // ecx
  struct _SecBuffer *v28; // [rsp+20h] [rbp-68h]
  struct _SecBuffer *v29; // [rsp+28h] [rbp-60h]
  struct _SecBuffer *v30; // [rsp+30h] [rbp-58h]
  struct _SecBuffer *v31; // [rsp+38h] [rbp-50h]
  struct _SecBuffer *v32; // [rsp+90h] [rbp+8h]

  cBuffers = a1->cBuffers;
  cbBuffer = 0;
  v32 = 0i64;
  v15 = a3;
  v28 = 0i64;
  v16 = 0i64;
  v29 = 0i64;
  v17 = 0i64;
  v30 = 0i64;
  v18 = 0i64;
  v31 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v23 = 0;
  if ( !cBuffers )
    goto LABEL_22;
  pBuffers = a1->pBuffers;
  p_BufferType = &pBuffers->BufferType;
  do
  {
    v26 = *p_BufferType & 0xFFFFFFF;
    if ( v26 )
    {
      if ( v26 == 2 )
        goto LABEL_12;
      if ( v26 == 18 )
      {
        v19 = &pBuffers[v23];
      }
      else
      {
        switch ( v26 )
        {
          case 3:
            v32 = &pBuffers[v23];
            break;
          case 5:
            v18 = &pBuffers[v23];
            break;
          case 19:
            v20 = &pBuffers[v23];
            break;
          case 20:
            v21 = &pBuffers[v23];
            break;
          case 21:
            v28 = &pBuffers[v23];
            break;
          case 22:
            v22 = &pBuffers[v23];
            break;
          case 23:
            v29 = &pBuffers[v23];
            break;
          case 24:
            v30 = &pBuffers[v23];
            break;
          case 27:
            v31 = &pBuffers[v23];
            break;
          default:
            break;
        }
      }
    }
    else
    {
      if ( !v16 && !v32 && (*p_BufferType & 0x40000000) == 0 )
      {
LABEL_12:
        v16 = &pBuffers[v23];
        goto LABEL_13;
      }
      if ( !v17 )
        v17 = &pBuffers[v23];
    }
LABEL_13:
    ++v23;
    p_BufferType += 4;
  }
  while ( v23 < cBuffers );
  v15 = a3;
  cbBuffer = 0;
  if ( v16 )
    goto LABEL_15;
  if ( v32 )
  {
    v16 = v32;
LABEL_15:
    *((_QWORD *)a3 + 1) = v16->pvBuffer;
    *(_DWORD *)a3 = v16->cbBuffer;
    cbBuffer = v16->cbBuffer;
  }
  else
  {
LABEL_22:
    *((_QWORD *)v15 + 1) = 0i64;
    *(_DWORD *)v15 = 0;
  }
  *((_DWORD *)v15 + 1) = cbBuffer;
  if ( !v17
    && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
  }
  *a2 = v16;
  *a4 = v17;
  *a5 = v18;
  *a6 = v19;
  *a7 = v20;
  *a8 = v21;
  *a9 = v28;
  *a10 = v22;
  *a11 = v29;
  *a12 = v30;
  *a13 = v31;
  return 0i64;
}
// 18000D5F0: conditional instruction was optimized away because rbx.8==0
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
