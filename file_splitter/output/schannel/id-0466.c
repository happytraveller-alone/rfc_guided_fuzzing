// File count: 466
// Total lines: 142
----------------------------------------
__int64 __fastcall CTls13Context::SetGenericExtensionBuffers(
        CTls13Context *this,
        struct _SecBufferDesc *const a2,
        struct _SecBuffer *const a3)
{
  void *v6; // rax
  PSecBuffer pBuffers; // rdx
  int v8; // eax
  unsigned int v9; // edx
  unsigned int v11; // ecx
  _DWORD *pvBuffer; // rdi
  int v13; // r8d
  __int64 v14; // r9
  unsigned __int64 cbBuffer; // rcx
  _DWORD *v16; // r8
  __int64 v17; // rdi
  unsigned __int64 v18; // r9
  __int16 *v19; // rdi
  unsigned __int64 v20; // r9

  *((_QWORD *)this + 18) = 0i64;
  *((_QWORD *)this + 16) = 0i64;
  memset((char *)this + 112, 0, 8ui64);
  *((_BYTE *)this + 120) = 0;
  v6 = (void *)*((_QWORD *)this + 20);
  if ( v6 )
  {
    v11 = *((_DWORD *)this + 38);
    if ( v11 )
    {
      if ( *((_BYTE *)this + 8) )
      {
        if ( a3 )
        {
          if ( a3->cbBuffer )
          {
            if ( a3->cbBuffer < v11 )
            {
              a3->cbBuffer = v11;
              v9 = -2146892950;
              goto LABEL_39;
            }
            memcpy_0(a3->pvBuffer, *((const void **)this + 20), *((unsigned int *)this + 38));
            SPExternalFree(*((void **)this + 20));
          }
          else
          {
            a3->pvBuffer = v6;
          }
          v9 = 590614;
          a3->cbBuffer = *((_DWORD *)this + 38);
          *((_QWORD *)this + 20) = 0i64;
          *((_DWORD *)this + 38) = 0;
          *((_BYTE *)this + 136) = 0;
LABEL_39:
          *((_QWORD *)this + 18) = 0i64;
          *((_QWORD *)this + 16) = 0i64;
          memset((char *)this + 112, 0, 8ui64);
          *((_BYTE *)this + 120) = 0;
          return v9;
        }
        SPExternalFree(*((void **)this + 20));
        *((_QWORD *)this + 20) = 0i64;
        *((_DWORD *)this + 38) = 0;
        *((_BYTE *)this + 136) = 0;
      }
    }
  }
  if ( a2 )
  {
    pBuffers = a2->pBuffers;
    if ( pBuffers < &pBuffers[a2->cBuffers] )
    {
      do
      {
        v8 = pBuffers->BufferType & 0xFFFFFFF;
        if ( v8 == 25 )
        {
          if ( *((_BYTE *)this + 120) )
            goto LABEL_38;
          if ( pBuffers->cbBuffer < 0xC )
            goto LABEL_38;
          pvBuffer = pBuffers->pvBuffer;
          v13 = *((unsigned __int16 *)pvBuffer + 4);
          if ( v13 + 10 > pBuffers->cbBuffer
            || (unsigned int)(v13 + 4) > 0xFFFF
            || pvBuffer[1]
            || !CTls13Context::IsValidGenericExtensionType(*(_WORD *)pvBuffer) )
          {
            goto LABEL_38;
          }
          *((_QWORD *)this + v14 + 14) = pvBuffer;
          ++*((_BYTE *)this + 120);
        }
        else if ( v8 == 26 )
        {
          cbBuffer = pBuffers->cbBuffer;
          if ( (unsigned int)cbBuffer < 0xC )
            goto LABEL_38;
          if ( *((_QWORD *)this + 16) )
            goto LABEL_38;
          v16 = pBuffers->pvBuffer;
          v17 = (unsigned int)v16[1];
          if ( (unsigned int)(v17 - 1) > 1 )
            goto LABEL_38;
          if ( *v16 )
            goto LABEL_38;
          v18 = 4 * v17 + 8;
          if ( v18 > cbBuffer )
            goto LABEL_38;
          v19 = (__int16 *)(v16 + 2);
          if ( v16 + 2 < (_DWORD *)((char *)v16 + v18) )
          {
            while ( CTls13Context::IsValidGenericExtensionType(*v19) )
            {
              v19 += 2;
              if ( (unsigned __int64)v19 >= v20 )
                goto LABEL_36;
            }
LABEL_38:
            v9 = -2146892963;
            goto LABEL_39;
          }
LABEL_36:
          *((_QWORD *)this + 16) = v16;
        }
        ++pBuffers;
      }
      while ( pBuffers < &a2->pBuffers[(unsigned __int64)a2->cBuffers] );
    }
    if ( *((_QWORD *)this + 16) && !a3 )
      goto LABEL_38;
    *((_QWORD *)this + 18) = a3;
    return 0;
  }
  return 0i64;
}
// 180022BB7: variable 'pBuffers' is possibly undefined
// 18003FDA2: variable 'v14' is possibly undefined
// 18003FE00: variable 'v20' is possibly undefined
// 18003FE02: variable 'v16' is possibly undefined
