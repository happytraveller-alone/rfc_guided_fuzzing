// File count: 155
// Total lines: 163
----------------------------------------
__int64 __fastcall ParseOutputBufferDesc(
        struct _SecBufferDesc *a1,
        __int16 a2,
        struct _SecBuffer **a3,
        struct SPBuffer *a4,
        struct _SecBuffer **a5,
        struct SPBuffer *a6,
        struct _SecBuffer **a7,
        struct _SecBuffer **a8,
        struct _SecBuffer **a9)
{
  unsigned int cBuffers; // r15d
  unsigned int v11; // ebx
  struct _SecBuffer *v12; // r10
  struct _SecBuffer *v13; // rdi
  struct _SecBuffer *v14; // rsi
  struct _SecBuffer *v15; // r14
  struct _SecBuffer *v16; // r11
  unsigned int v17; // ebp
  PSecBuffer pBuffers; // rcx
  unsigned int *p_BufferType; // r8
  __int64 v20; // rdx
  void *v21; // rax
  __int64 result; // rax
  void *pvBuffer; // rax

  cBuffers = a1->cBuffers;
  v11 = 0;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  v17 = 0;
  if ( !cBuffers )
    goto LABEL_8;
  pBuffers = a1->pBuffers;
  p_BufferType = &pBuffers->BufferType;
  do
  {
    if ( (*p_BufferType & 0xFFFFFFF) != 0 )
    {
      switch ( *p_BufferType & 0xFFFFFFF )
      {
        case 2u:
          goto LABEL_5;
        case 0x11u:
          v13 = &pBuffers[v17];
          break;
        case 0x17u:
          v14 = &pBuffers[v17];
          break;
        case 0x1Au:
          v15 = &pBuffers[v17];
          break;
        case 0x1Bu:
          v16 = &pBuffers[v17];
          break;
      }
    }
    else if ( !v12 && (a2 & 0x100) != 0 )
    {
LABEL_5:
      v12 = &pBuffers[v17];
    }
    ++v17;
    p_BufferType += 4;
  }
  while ( v17 < cBuffers );
  if ( v14 )
  {
    if ( (a2 & 0x100) != 0 )
    {
      v14->pvBuffer = 0i64;
      v14->cbBuffer = 0;
    }
    else if ( !v14->pvBuffer )
    {
      v11 = 14;
    }
  }
LABEL_8:
  *a7 = v14;
  if ( v15 )
  {
    if ( (a2 & 0x100) != 0 )
    {
      v15->pvBuffer = 0i64;
      v15->cbBuffer = 0;
    }
    else if ( !v15->pvBuffer )
    {
      v11 = 14;
    }
  }
  *a8 = v15;
  if ( v16 )
  {
    if ( (a2 & 0x100) != 0 )
    {
      v16->pvBuffer = 0i64;
      v16->cbBuffer = 0;
    }
    else if ( v16->pvBuffer )
    {
      if ( v16->cbBuffer < 8 )
      {
        v16->cbBuffer = 8;
        v11 = -2146893023;
      }
    }
    else
    {
      v11 = 14;
    }
  }
  v20 = a2 & 0x100;
  *a9 = v16;
  if ( v13 )
  {
    if ( v20 )
    {
      v13->pvBuffer = 0i64;
      v13->cbBuffer = 0;
    }
    else
    {
      pvBuffer = v13->pvBuffer;
      if ( pvBuffer )
      {
LABEL_49:
        *((_QWORD *)a6 + 1) = pvBuffer;
        *(_QWORD *)a6 = v13->cbBuffer;
        goto LABEL_11;
      }
      v11 = 14;
    }
    pvBuffer = 0i64;
    goto LABEL_49;
  }
LABEL_11:
  *a5 = v13;
  if ( !v12 )
    return 2148074248i64;
  v12->BufferType = 2;
  if ( v20 )
  {
    v12->pvBuffer = 0i64;
    v21 = 0i64;
    v12->cbBuffer = 0;
    goto LABEL_14;
  }
  v21 = v12->pvBuffer;
  if ( !v21 )
    return 14i64;
LABEL_14:
  *((_QWORD *)a4 + 1) = v21;
  result = v11;
  *(_QWORD *)a4 = v12->cbBuffer;
  *a3 = v12;
  return result;
}
