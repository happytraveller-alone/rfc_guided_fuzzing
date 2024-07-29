//----- (000000018006F0D8) ----------------------------------------------------
__int64 __fastcall CTls13Context::SetTrafficSecretsBuffers(
        CTls13Context *this,
        struct _SecBufferDesc *const a2,
        char a3,
        char a4)
{
  char *v7; // r8
  unsigned int v8; // edx
  unsigned __int8 v9; // di
  PSecBuffer pBuffers; // rcx
  __int64 v11; // rax

  if ( a3 )
    return 0i64;
  if ( !a2 )
    return 2148074333i64;
  v7 = (char *)this + 168;
  v8 = 0;
  memset((char *)this + 168, 0, 0x20ui64);
  *((_BYTE *)this + 200) = 0;
  v9 = 0;
  pBuffers = a2->pBuffers;
  if ( pBuffers >= &pBuffers[a2->cBuffers] )
  {
LABEL_18:
    v8 = -2146892949;
    goto LABEL_19;
  }
  while ( 1 )
  {
    if ( v9 >= 4u )
      goto LABEL_13;
    if ( (pBuffers->BufferType & 0xFFFFFFF) != 28 )
      goto LABEL_11;
    if ( a4 )
    {
      pBuffers->pvBuffer = 0i64;
      pBuffers->cbBuffer = 0;
      goto LABEL_10;
    }
    if ( !pBuffers->pvBuffer )
      break;
    if ( pBuffers->cbBuffer < 0x1C0 )
    {
      pBuffers->cbBuffer = 448;
      goto LABEL_11;
    }
LABEL_10:
    v11 = v9++;
    *((_QWORD *)this + v11 + 21) = pBuffers;
LABEL_11:
    if ( ++pBuffers >= &a2->pBuffers[(unsigned __int64)a2->cBuffers] )
    {
      if ( v9 < 4u )
        goto LABEL_18;
LABEL_13:
      *((_BYTE *)this + 201) = 0;
      return v8;
    }
  }
  v8 = 14;
LABEL_19:
  memset(v7, 0, 0x20ui64);
  *((_BYTE *)this + 200) = 0;
  return v8;
}

