// File count: 476
// Total lines: 73
-----------------------------------------
__int64 __fastcall CTls13ServerContext::SetTrafficSecretsBuffers(
        CTls13ServerContext *this,
        struct _SecBufferDesc *const a2,
        char a3,
        char a4)
{
  unsigned int v4; // r10d
  char *v8; // r8
  unsigned int v9; // edx
  unsigned __int8 v10; // di
  PSecBuffer pBuffers; // rcx
  __int64 v12; // rax

  v4 = 0;
  if ( a3 )
    return v4;
  if ( !a2 )
    return (unsigned int)-2146892963;
  v8 = (char *)this + 1168;
  v9 = 0;
  memset((char *)this + 1168, 0, 0x20ui64);
  *((_BYTE *)this + 1200) = 0;
  v10 = 0;
  pBuffers = a2->pBuffers;
  if ( pBuffers < &pBuffers[a2->cBuffers] )
  {
    while ( 1 )
    {
      if ( v10 >= 4u )
      {
LABEL_20:
        *((_BYTE *)this + 1201) = 0;
        return v9;
      }
      if ( (pBuffers->BufferType & 0xFFFFFFF) == 28 )
      {
        if ( a4 )
        {
          pBuffers->pvBuffer = 0i64;
          pBuffers->cbBuffer = 0;
        }
        else
        {
          if ( !pBuffers->pvBuffer )
          {
            v9 = 14;
            goto LABEL_14;
          }
          if ( pBuffers->cbBuffer < 0x1C0 )
          {
            pBuffers->cbBuffer = 448;
            goto LABEL_11;
          }
        }
        v12 = v10++;
        *((_QWORD *)this + v12 + 146) = pBuffers;
      }
LABEL_11:
      if ( ++pBuffers >= &a2->pBuffers[(unsigned __int64)a2->cBuffers] )
      {
        if ( v10 < 4u )
          break;
        goto LABEL_20;
      }
    }
  }
  v9 = -2146892949;
LABEL_14:
  memset(v8, 0, 0x20ui64);
  *((_BYTE *)this + 1200) = 0;
  return v9;
}
