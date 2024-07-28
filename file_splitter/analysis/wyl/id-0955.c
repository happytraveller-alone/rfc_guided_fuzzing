//----- (000000018004F2BC) ----------------------------------------------------
__int64 __fastcall SslUnsealMessageConnection(struct CSslUserContext *a1, struct _SecBufferDesc *a2)
{
  struct _SecBuffer *v2; // rsi
  struct _SecBuffer *v3; // rdi
  __int64 v4; // r15
  int v5; // r12d
  CCipherMill *v8; // rcx
  unsigned int cBuffers; // r11d
  unsigned int v10; // r8d
  PSecBuffer pBuffers; // r10
  unsigned int *p_BufferType; // r9
  __int64 pvBuffer; // rdx
  unsigned int v15; // ebx
  __int64 cbBuffer; // rdx
  char *v17; // r8
  unsigned int v18; // r9d
  bool v19; // zf
  unsigned int v20; // ebx
  int v21; // r11d
  unsigned int v22; // r10d
  int v23; // edx
  int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned __int16 v27; // dx
  unsigned int v28; // [rsp+30h] [rbp-20h] BYREF
  unsigned int v29; // [rsp+34h] [rbp-1Ch]
  char *v30; // [rsp+38h] [rbp-18h]
  unsigned int v31; // [rsp+40h] [rbp-10h] BYREF
  unsigned int v32; // [rsp+44h] [rbp-Ch]
  __int64 v33; // [rsp+48h] [rbp-8h]
  unsigned __int8 v34; // [rsp+88h] [rbp+38h] BYREF

  v2 = 0i64;
  v3 = 0i64;
  v4 = 0i64;
  v34 = 0;
  v5 = 0;
  v8 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 83i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    v8 = WPP_GLOBAL_Control;
  }
  cBuffers = a2->cBuffers;
  v10 = 0;
  if ( !cBuffers )
    goto LABEL_86;
  pBuffers = a2->pBuffers;
  p_BufferType = &pBuffers->BufferType;
  do
  {
    switch ( *p_BufferType )
    {
      case 1u:
        v2 = &pBuffers[v10];
        break;
      case 2u:
        if ( !v3 )
          v3 = &pBuffers[v10];
        break;
      case 0x11u:
        v4 = (__int64)&pBuffers[v10];
        break;
    }
    ++v10;
    p_BufferType += 4;
  }
  while ( v10 < cBuffers );
  if ( !v3 || !v2 )
  {
LABEL_86:
    if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 5) == 0 )
      return 2148074248i64;
    v27 = 84;
    goto LABEL_88;
  }
  pvBuffer = (__int64)v2->pvBuffer;
  if ( !pvBuffer || !v3->pvBuffer )
  {
    if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 5) == 0 )
      return 2148074248i64;
    v27 = 85;
LABEL_88:
    WPP_SF_DD(
      *((_QWORD *)v8 + 2),
      v27,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      -2146893048,
      -2146893048);
    return 2148074248i64;
  }
  if ( v2->cbBuffer > ~v3->cbBuffer )
  {
    if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)v8 + 2),
        0x56u,
        (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
        -2146892963,
        -2146892963);
    return 2148074333i64;
  }
  v15 = *((_DWORD *)a1 + 6);
  if ( (v15 & 0xF0000) != 0 )
  {
    if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)v8 + 2),
        0x57u,
        (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
        -2146893054,
        -2146893054);
    return 2148074242i64;
  }
  v32 = 0;
  v33 = pvBuffer;
  cbBuffer = v2->cbBuffer;
  v17 = (char *)v2->pvBuffer;
  if ( &v17[cbBuffer] == v3->pvBuffer )
  {
    v30 = (char *)v2->pvBuffer;
    v18 = v2->cbBuffer + v3->cbBuffer;
    v29 = v18;
    v28 = v18;
    v31 = v18;
    goto LABEL_36;
  }
  v29 = cbBuffer + v3->cbBuffer;
  v30 = (char *)LocalAlloc(0x40u, v29);
  if ( v30 )
  {
    v28 = v29;
    memcpy_0(v30, v2->pvBuffer, v2->cbBuffer);
    memcpy_0(&v30[v2->cbBuffer], v3->pvBuffer, v3->cbBuffer);
    v5 = 1;
    v15 = *((_DWORD *)a1 + 6);
    v17 = v30;
    v18 = v29;
    v8 = WPP_GLOBAL_Control;
    v31 = v2->cbBuffer;
LABEL_36:
    if ( v15 > 0x800 )
    {
      if ( v15 == 4096 || v15 == 0x2000 || v15 == 0x10000 || v15 == 0x20000 || v15 == 0x40000 )
        goto LABEL_53;
      v19 = v15 == 0x80000;
    }
    else
    {
      if ( v15 == 2048 || v15 == 16 || v15 == 32 || v15 == 64 || v15 == 128 || v15 == 256 || v15 == 512 )
        goto LABEL_53;
      v19 = v15 == 1024;
    }
    if ( !v19 )
    {
      v20 = -2146893055;
      goto LABEL_72;
    }
LABEL_53:
    v21 = *((_DWORD *)a1 + 17);
    v22 = v21 + *((_DWORD *)a1 + 16);
    if ( v18 >= v22 )
    {
      if ( v17[1] == -2 && ((unsigned __int8)v17[2] | ((unsigned __int8)v17[1] << 8)) <= 0xFEFFu )
      {
        v23 = (unsigned __int8)v17[11];
        v24 = (unsigned __int8)v17[12];
      }
      else
      {
        v23 = (unsigned __int8)v17[3];
        v24 = (unsigned __int8)v17[4];
      }
      v25 = v21 + (v24 | (v23 << 8));
      if ( v25 < v22 )
      {
        v20 = -2146893048;
        v34 = 50;
        goto LABEL_72;
      }
      if ( v18 >= v25 )
      {
        if ( (v15 & 0x3000) != 0 )
          v26 = Tls13DecryptHandler(a1, (struct SPBuffer *)&v28, (struct SPBuffer *)&v31, &v34);
        else
          v26 = TlsDecryptHandler(a1, (struct SPBuffer *)&v28, (struct SPBuffer *)&v31, &v34);
        v20 = v26;
        if ( !v26 || v26 == 590625 )
        {
          v2->cbBuffer = v32;
          v3->cbBuffer = v29 - v32;
          if ( v26 == 590625 )
            *((_DWORD *)a1 + 2) = 76;
        }
        v8 = WPP_GLOBAL_Control;
        v17 = v30;
        goto LABEL_72;
      }
      v29 = v25;
    }
    else
    {
      v29 = v21 + *((_DWORD *)a1 + 16);
    }
    v20 = -2146893032;
LABEL_72:
    if ( v5 )
    {
      LocalFree(v17);
      v8 = WPP_GLOBAL_Control;
    }
    if ( v4 )
    {
      GenerateUserFatalAlertMessage(a1, v4, v34);
      v8 = WPP_GLOBAL_Control;
    }
    if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control
      && ((*((_BYTE *)v8 + 28) & 1) != 0 && v20 || (*((_BYTE *)v8 + 28) & 4) != 0) )
    {
      WPP_SF_DD(*((_QWORD *)v8 + 2), 0x5Du, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v20, v20);
    }
    return v20;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x5Au,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      -2146893056,
      -2146893056);
  return 2148074240i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
