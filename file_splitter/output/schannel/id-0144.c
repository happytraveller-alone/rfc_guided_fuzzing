// File count: 144
// Total lines: 274
----------------------------------------
__int64 __fastcall SslUnsealMessageStream(struct CSslUserContext *a1, struct _SecBufferDesc *a2)
{
  struct _SecBuffer *v2; // rdi
  struct _SecBuffer *v3; // rsi
  struct _SecBuffer *v4; // r12
  struct _SecBuffer *v5; // r14
  CCipherMill *v8; // r10
  unsigned int cBuffers; // r11d
  unsigned int v10; // ecx
  PSecBuffer pBuffers; // rdx
  unsigned int *p_BufferType; // r9
  __int64 v13; // r8
  _BYTE *pvBuffer; // rdx
  unsigned int v15; // ecx
  unsigned int v16; // r11d
  int v17; // r9d
  unsigned int v18; // r15d
  int v19; // r8d
  int v20; // eax
  unsigned int v21; // r9d
  unsigned int v22; // eax
  unsigned int v23; // ebx
  unsigned int v25; // eax
  unsigned __int16 v26; // dx
  bool v27; // zf
  int v28; // ecx
  int v29; // eax
  unsigned int v30; // r11d
  __int64 v31; // [rsp+20h] [rbp-30h]
  unsigned int v32; // [rsp+30h] [rbp-20h] BYREF
  unsigned int cbBuffer; // [rsp+34h] [rbp-1Ch]
  unsigned __int8 *v34; // [rsp+38h] [rbp-18h]
  __int128 v35; // [rsp+40h] [rbp-10h] BYREF
  unsigned __int8 v36; // [rsp+98h] [rbp+48h] BYREF
  struct _SecBuffer *v37; // [rsp+A0h] [rbp+50h]

  v2 = 0i64;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  v37 = 0i64;
  v36 = 0;
  v35 = 0i64;
  v8 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 72i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    v8 = WPP_GLOBAL_Control;
  }
  cBuffers = a2->cBuffers;
  v10 = 0;
  if ( !cBuffers )
    goto LABEL_95;
  pBuffers = a2->pBuffers;
  p_BufferType = &pBuffers->BufferType;
  do
  {
    v13 = *p_BufferType;
    if ( (_DWORD)v13 )
    {
      v13 = (unsigned int)(v13 - 1);
      if ( (_DWORD)v13 )
      {
        if ( (_DWORD)v13 == 16 )
          v37 = &pBuffers[v10];
      }
      else
      {
        v2 = &pBuffers[v10];
      }
    }
    else if ( v3 )
    {
      if ( v4 )
      {
        if ( !v5 )
          v5 = &pBuffers[v10];
      }
      else
      {
        v4 = &pBuffers[v10];
      }
    }
    else
    {
      v3 = &pBuffers[v10];
    }
    ++v10;
    p_BufferType += 4;
  }
  while ( v10 < cBuffers );
  if ( !v2 || !v3 || !v4 || !v5 )
  {
LABEL_95:
    if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 5) == 0 )
      return 2148074248i64;
    v26 = 73;
    goto LABEL_97;
  }
  pvBuffer = v2->pvBuffer;
  if ( !pvBuffer )
  {
    if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 5) == 0 )
      return 2148074248i64;
    v26 = 74;
LABEL_97:
    WPP_SF_DD(
      *((_QWORD *)v8 + 2),
      v26,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      -2146893048,
      -2146893048);
    return 2148074248i64;
  }
  v15 = *((_DWORD *)a1 + 6);
  v34 = (unsigned __int8 *)v2->pvBuffer;
  cbBuffer = v2->cbBuffer;
  v16 = v2->cbBuffer;
  v32 = v2->cbBuffer;
  if ( v15 > 0x800 )
  {
    if ( v15 == 4096 || v15 == 0x2000 || v15 == 0x10000 || v15 == 0x20000 || v15 == 0x40000 )
      goto LABEL_20;
    v27 = v15 == 0x80000;
  }
  else
  {
    if ( v15 == 2048 || v15 == 16 || v15 == 32 || v15 == 64 || v15 == 128 || v15 == 256 || v15 == 512 )
      goto LABEL_20;
    v27 = v15 == 1024;
  }
  if ( !v27 )
  {
    v23 = -2146893055;
    goto LABEL_34;
  }
LABEL_20:
  v17 = *((_DWORD *)a1 + 17);
  v18 = v17 + *((_DWORD *)a1 + 16);
  if ( v16 < v18 )
  {
    if ( (v15 & 0x50000) != 0 && !*((_BYTE *)a1 + 140) )
    {
      if ( pvBuffer[1] == 0xFE && ((unsigned __int8)pvBuffer[2] | ((unsigned __int8)pvBuffer[1] << 8)) <= 0xFEFFu )
      {
        v28 = (unsigned __int8)pvBuffer[11];
        v29 = (unsigned __int8)pvBuffer[12];
      }
      else
      {
        v28 = (unsigned __int8)pvBuffer[3];
        v29 = (unsigned __int8)pvBuffer[4];
      }
      if ( v17 + (v29 | (unsigned int)(v28 << 8)) < v18
        && *pvBuffer == 20
        && ((unsigned __int8)pvBuffer[4] | ((unsigned __int8)pvBuffer[3] << 8)) < *((_DWORD *)a1 + 29) )
      {
        v23 = -2146893005;
        goto LABEL_34;
      }
    }
    cbBuffer = v17 + *((_DWORD *)a1 + 16);
    goto LABEL_44;
  }
  if ( pvBuffer[1] == 0xFE && ((unsigned __int8)pvBuffer[2] | ((unsigned __int8)pvBuffer[1] << 8)) <= 0xFEFFu )
  {
    v19 = (unsigned __int8)pvBuffer[11];
    v20 = (unsigned __int8)pvBuffer[12];
  }
  else
  {
    v19 = (unsigned __int8)pvBuffer[3];
    v20 = (unsigned __int8)pvBuffer[4];
  }
  v13 = v20 | (unsigned int)(v19 << 8);
  v21 = v13 + v17;
  if ( v21 < v18 )
  {
    v23 = -2146893048;
    v36 = 50;
    goto LABEL_34;
  }
  LODWORD(v35) = v16;
  *((_QWORD *)&v35 + 1) = &pvBuffer[v18];
  DWORD1(v35) = v21 - v18;
  if ( v16 < v21 )
  {
    cbBuffer = v21;
LABEL_44:
    v23 = -2146893032;
    goto LABEL_45;
  }
  if ( (v15 & 0x3000) != 0 )
    v22 = Tls13DecryptHandler(a1, (struct SPBuffer *)&v32, (struct SPBuffer *)&v35, &v36);
  else
    v22 = TlsDecryptHandler(a1, (struct SPBuffer *)&v32, (struct SPBuffer *)&v35, &v36);
  v23 = v22;
  if ( (*((_DWORD *)a1 + 6) & 0xF0000) != 0 )
  {
    if ( !v22 )
    {
      if ( !CSslUserContext::DTLSCheckRecordValidity(
              a1,
              v34[10] | ((v34[9] | ((v34[8] | ((v34[7] | ((v34[6] | ((v34[5] | ((v34[4] | ((unsigned __int64)v34[3] << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) )
      {
        v8 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 76i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v30);
          v8 = WPP_GLOBAL_Control;
        }
        v23 = -2146893040;
        goto LABEL_34;
      }
      goto LABEL_30;
    }
  }
  else if ( !v22 )
  {
LABEL_30:
    if ( cbBuffer < v2->cbBuffer )
    {
      v5->BufferType = 5;
      v5->cbBuffer = v2->cbBuffer - cbBuffer;
      v5->pvBuffer = (char *)v2->pvBuffer + cbBuffer;
    }
    v2->BufferType = 7;
    v2->cbBuffer = v18;
    v3->BufferType = 1;
    v3->pvBuffer = (void *)*((_QWORD *)&v35 + 1);
    v3->cbBuffer = DWORD1(v35);
    v4->BufferType = 6;
    v4->pvBuffer = (char *)v3->pvBuffer + DWORD1(v35);
    v4->cbBuffer = v32 - DWORD1(v35) - v18;
    goto LABEL_33;
  }
  if ( v22 == 590625 )
    goto LABEL_30;
  if ( v22 == -2146893032 )
  {
LABEL_45:
    v3->BufferType = 4;
    v25 = cbBuffer - v2->cbBuffer;
    v3->cbBuffer = v25;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_ddd(*((_QWORD *)WPP_GLOBAL_Control + 2), (__int64)pvBuffer, v13, v2->cbBuffer, cbBuffer, v25);
    v2->BufferType = 4;
    v2->cbBuffer = cbBuffer - v2->cbBuffer;
    v8 = WPP_GLOBAL_Control;
    goto LABEL_34;
  }
LABEL_33:
  v8 = WPP_GLOBAL_Control;
LABEL_34:
  if ( v37 )
  {
    GenerateUserFatalAlertMessage(a1, (__int64)v37, v36);
    v8 = WPP_GLOBAL_Control;
  }
  if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)v8 + 28) & 1) != 0 && v23 || (*((_BYTE *)v8 + 28) & 4) != 0) )
  {
    LODWORD(v31) = v23;
    WPP_SF_DD(*((_QWORD *)v8 + 2), 0x52u, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v23, v31);
  }
  return v23;
}
// 1800368C6: variable 'pvBuffer' is possibly undefined
// 1800368C6: variable 'v13' is possibly undefined
// 180036894: variable 'v30' is possibly undefined
// 180036908: variable 'v31' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
