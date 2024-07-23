//----- (000000018000CD3C) ----------------------------------------------------
__int64 __fastcall SslSealMessageStream(struct CSslUserContext *a1, int a2, struct _SecBufferDesc *a3)
{
  struct _SecBuffer *v3; // rdi
  struct _SecBuffer *v4; // rsi
  struct _SecBuffer *v5; // r15
  CCipherMill *v9; // r10
  unsigned int cBuffers; // r11d
  unsigned int v11; // edx
  PSecBuffer pBuffers; // r8
  unsigned int *p_BufferType; // r9
  unsigned __int8 *pvBuffer; // rbx
  __int64 cbBuffer; // rdx
  __int64 v16; // r8
  BOOL v17; // r9d
  unsigned int v18; // r12d
  unsigned int v19; // ecx
  unsigned int v20; // edx
  int v21; // r8d
  bool v22; // zf
  __int64 v23; // rdx
  unsigned __int8 *v24; // r13
  unsigned int v25; // ebx
  unsigned int KeyUpdateRecord; // ebx
  unsigned int v27; // ecx
  unsigned __int64 v28; // rdx
  unsigned int v29; // ecx
  unsigned int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // ecx
  CCipherMill *v34; // rcx
  unsigned __int16 v36; // dx
  unsigned int v37; // edx
  char *v38; // rax
  char *v39; // rcx
  __int64 v40; // rax
  size_t v41; // r8
  void *v42; // rdx
  __int64 v43; // rdx
  _BYTE *v44; // r13
  unsigned int v45; // ebx
  CCipherMill *v46; // rcx
  __int64 v47; // rbx
  unsigned int v48; // eax
  __int64 v49; // rdx
  __int64 v50; // r9
  __int64 v51; // rcx
  unsigned __int8 v52; // cl
  __int64 v53; // rax
  char v54; // r8
  unsigned int v55; // edx
  const wchar_t *v56; // r9
  char *v57; // r14
  __int64 v58; // [rsp+20h] [rbp-49h]
  BOOL v59; // [rsp+50h] [rbp-19h]
  __int64 v60; // [rsp+58h] [rbp-11h] BYREF
  unsigned __int8 *v61; // [rsp+60h] [rbp-9h]
  void *Src; // [rsp+68h] [rbp-1h]
  unsigned int v63; // [rsp+70h] [rbp+7h]
  unsigned int v64; // [rsp+74h] [rbp+Bh] BYREF
  char *v65; // [rsp+78h] [rbp+Fh]
  __int128 v66[4]; // [rsp+80h] [rbp+17h] BYREF
  unsigned int v67; // [rsp+E0h] [rbp+77h]
  int v68; // [rsp+E8h] [rbp+7Fh]

  v3 = 0i64;
  v4 = 0i64;
  Src = 0i64;
  v5 = 0i64;
  v63 = 0;
  v68 = 23;
  LODWORD(v60) = 23;
  v66[0] = 0i64;
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    v9 = WPP_GLOBAL_Control;
  }
  cBuffers = a3->cBuffers;
  v11 = 0;
  if ( !cBuffers )
    goto LABEL_181;
  pBuffers = a3->pBuffers;
  p_BufferType = &pBuffers->BufferType;
  do
  {
    switch ( *p_BufferType )
    {
      case 1u:
        v5 = &pBuffers[v11];
        if ( !v3 )
          v3 = &pBuffers[v11];
        break;
      case 2u:
        if ( !v3 )
          goto LABEL_9;
        if ( !v4 )
LABEL_76:
          v4 = &pBuffers[v11];
        break;
      case 6u:
        goto LABEL_76;
      case 7u:
LABEL_9:
        v3 = &pBuffers[v11];
        break;
    }
    ++v11;
    p_BufferType += 4;
  }
  while ( v11 < cBuffers );
  if ( !v3 || !v5 )
  {
LABEL_181:
    if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)v9 + 2),
        0xEu,
        (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
        -2146893048,
        -2146893048);
    return 2148074248i64;
  }
  pvBuffer = (unsigned __int8 *)v5->pvBuffer;
  cbBuffer = v3->cbBuffer;
  v16 = (__int64)v3->pvBuffer;
  v61 = pvBuffer;
  v17 = pvBuffer != (unsigned __int8 *)(v16 + cbBuffer);
  v59 = v17;
  if ( v4 )
  {
    if ( v4->pvBuffer != &pvBuffer[v5->cbBuffer] )
      v17 = 1;
    v59 = v17;
  }
  v18 = v5->cbBuffer;
  v19 = v5->cbBuffer + cbBuffer;
  if ( v19 < (unsigned int)cbBuffer )
  {
    if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 5) != 0 )
    {
      v36 = 18;
      goto LABEL_91;
    }
    return 2148074333i64;
  }
  if ( !v17 )
  {
    v64 = 0;
    v65 = (char *)v16;
    v20 = v3->cbBuffer + v5->cbBuffer;
    v67 = v18;
    v63 = v20;
    if ( !v4 )
      goto LABEL_22;
    if ( v20 + v4->cbBuffer >= v20 )
    {
      v63 = v20 + v4->cbBuffer;
      v67 = v18 + v4->cbBuffer;
      goto LABEL_22;
    }
    if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 5) != 0 )
    {
      v36 = 19;
      goto LABEL_91;
    }
    return 2148074333i64;
  }
  v63 = v5->cbBuffer + cbBuffer;
  if ( !v4 )
  {
LABEL_94:
    v38 = (char *)LocalAlloc(0x40u, v19);
    Src = v38;
    v39 = v38;
    if ( !v38 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
        WPP_SF_DD(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x15u,
          (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
          -2146893056,
          -2146893056);
      return 2148074240i64;
    }
    v64 = 0;
    v65 = v38;
    v40 = v3->cbBuffer;
    v41 = v5->cbBuffer;
    v42 = v5->pvBuffer;
    v18 = v5->cbBuffer;
    pvBuffer = (unsigned __int8 *)&v39[v40];
    v61 = (unsigned __int8 *)&v39[v40];
    v67 = v63 - v40;
    memcpy_0(&v39[v40], v42, v41);
    v9 = WPP_GLOBAL_Control;
LABEL_22:
    if ( a2 == 0x40000000 )
    {
      KeyUpdateRecord = HandleSpecialMessage(a1, pvBuffer, v18, (enum eTlsRecordType *)&v60);
      if ( KeyUpdateRecord )
      {
        v34 = WPP_GLOBAL_Control;
LABEL_167:
        if ( !v59 )
        {
LABEL_68:
          if ( v34 != (CCipherMill *)&WPP_GLOBAL_Control
            && ((*((_BYTE *)v34 + 28) & 1) != 0 && KeyUpdateRecord || (*((_BYTE *)v34 + 28) & 4) != 0) )
          {
            LODWORD(v58) = KeyUpdateRecord;
            WPP_SF_DD(
              *((_QWORD *)v34 + 2),
              0x31u,
              (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
              KeyUpdateRecord,
              v58);
          }
          return KeyUpdateRecord;
        }
        v57 = (char *)Src;
        goto LABEL_178;
      }
      v21 = v60;
      v9 = WPP_GLOBAL_Control;
      v68 = v60;
    }
    else
    {
      v21 = 23;
    }
    v22 = (*((_DWORD *)a1 + 6) & 0xF0000) == 0;
    v23 = *((_QWORD *)a1 + 13);
    v60 = v23;
    if ( !v22 )
      v60 = ((__int64)*((int *)a1 + 29) << 48) | v23;
    if ( (*((_BYTE *)a1 + 24) & 0x30) == 0 && (*((_BYTE *)a1 + 24) & 0xC0) == 0 )
      goto LABEL_28;
    v43 = *((unsigned int *)a1 + 17);
    if ( v3->cbBuffer <= (unsigned int)(v43 + *((_DWORD *)a1 + 16)) )
    {
      if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)v9 + 2), 31i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
        v9 = WPP_GLOBAL_Control;
LABEL_28:
        v24 = v61;
        v25 = v67;
        goto LABEL_29;
      }
      v25 = v67;
      v24 = v61;
    }
    else if ( v21 == 23 && v18 > 1 )
    {
      v44 = (char *)v3->pvBuffer + (unsigned int)v43;
      v45 = v3->cbBuffer - v43;
      *((_QWORD *)&v66[0] + 1) = v65;
      *(_QWORD *)&v66[0] = v63;
      *v44 = *(_BYTE *)v5->pvBuffer;
      v46 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
          v46 = WPP_GLOBAL_Control;
        }
        if ( v46 != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)v46 + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)v46 + 2), 23i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, 1i64);
            v46 = WPP_GLOBAL_Control;
          }
          if ( v46 != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_BYTE *)v46 + 28) & 4) != 0 )
            {
              WPP_SF_D(*((_QWORD *)v46 + 2), 24i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v45);
              v46 = WPP_GLOBAL_Control;
            }
            if ( v46 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v46 + 28) & 4) != 0 )
              {
                WPP_SF_q(*((_QWORD *)v46 + 2), 0x19u, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v44);
                v46 = WPP_GLOBAL_Control;
              }
              if ( v46 != (CCipherMill *)&WPP_GLOBAL_Control )
              {
                if ( (*((_BYTE *)v46 + 28) & 4) != 0 )
                {
                  WPP_SF_D(
                    *((_QWORD *)v46 + 2),
                    26i64,
                    &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
                    DWORD1(v66[0]));
                  v46 = WPP_GLOBAL_Control;
                }
                if ( v46 != (CCipherMill *)&WPP_GLOBAL_Control )
                {
                  if ( (*((_BYTE *)v46 + 28) & 4) != 0 )
                  {
                    WPP_SF_D(
                      *((_QWORD *)v46 + 2),
                      27i64,
                      &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
                      LODWORD(v66[0]));
                    v46 = WPP_GLOBAL_Control;
                  }
                  if ( v46 != (CCipherMill *)&WPP_GLOBAL_Control )
                  {
                    if ( (*((_BYTE *)v46 + 28) & 4) != 0 )
                    {
                      WPP_SF_q(
                        *((_QWORD *)v46 + 2),
                        0x1Cu,
                        (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
                        *((_QWORD *)&v66[0] + 1));
                      v46 = WPP_GLOBAL_Control;
                    }
                    if ( v46 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v46 + 28) & 4) != 0 )
                      WPP_SF_D(
                        *((_QWORD *)v46 + 2),
                        29i64,
                        &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
                        *((unsigned int *)a1 + 26));
                  }
                }
              }
            }
          }
        }
      }
      v47 = v60;
      v48 = SslEncryptPacket(
              *((_QWORD *)a1 + 11),
              *((_QWORD *)a1 + 6),
              v44,
              1i64,
              *((_QWORD *)&v66[0] + 1),
              v66[0],
              (char *)v66 + 4,
              v60,
              23,
              0);
      if ( v48 )
      {
        v34 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_166;
        v49 = 30i64;
        v50 = v48;
        goto LABEL_164;
      }
      v51 = DWORD1(v66[0]);
      ++*((_QWORD *)a1 + 13);
      v65 += v51;
      v24 = v61 + 1;
      v9 = WPP_GLOBAL_Control;
      --v18;
      v60 = v47 + 1;
      v25 = v67 - 1;
      v63 -= v51;
    }
    else
    {
      v24 = (unsigned __int8 *)v3->pvBuffer + v43;
      v25 = v63 - v43;
      if ( v18 )
      {
        memmove_0(v24, v5->pvBuffer, v18);
        v9 = WPP_GLOBAL_Control;
      }
    }
LABEL_29:
    if ( (*((_DWORD *)a1 + 6) & 0x3000) != 0 )
    {
      v52 = v68;
      v53 = v18++;
      v68 = 23;
      v24[v53] = v52;
      v9 = WPP_GLOBAL_Control;
    }
    if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)v9 + 2), 32i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
        v9 = WPP_GLOBAL_Control;
      }
      if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)v9 + 2), 33i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v18);
          v9 = WPP_GLOBAL_Control;
        }
        if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)v9 + 2), 34i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v25);
            v9 = WPP_GLOBAL_Control;
          }
          if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
            {
              WPP_SF_q(*((_QWORD *)v9 + 2), 0x23u, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v24);
              v9 = WPP_GLOBAL_Control;
            }
            if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
              {
                WPP_SF_D(*((_QWORD *)v9 + 2), 36i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v64);
                v9 = WPP_GLOBAL_Control;
              }
              if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
              {
                if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
                {
                  WPP_SF_D(*((_QWORD *)v9 + 2), 37i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v63);
                  v9 = WPP_GLOBAL_Control;
                }
                if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control )
                {
                  if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
                  {
                    WPP_SF_q(*((_QWORD *)v9 + 2), 0x26u, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v65);
                    v9 = WPP_GLOBAL_Control;
                  }
                  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
                    WPP_SF_D(
                      *((_QWORD *)v9 + 2),
                      39i64,
                      &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
                      *((unsigned int *)a1 + 26));
                }
              }
            }
          }
        }
      }
    }
    KeyUpdateRecord = SslEncryptPacket(*((_QWORD *)a1 + 11), *((_QWORD *)a1 + 6), v24, v18, v65, v63, &v64, v60, v68, 0);
    if ( !KeyUpdateRecord )
    {
      v27 = v64;
      if ( (*((_DWORD *)a1 + 6) & 0xF0000) != 0 && v64 > *((unsigned __int16 *)a1 + 68) )
      {
        v34 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_166;
        v49 = 41i64;
        v50 = 0i64;
        goto LABEL_164;
      }
      v28 = *((_QWORD *)a1 + 13) + 1i64;
      v22 = (*((_DWORD *)a1 + 6) & 0x3000) == 0;
      *((_QWORD *)a1 + 13) = v28;
      if ( !v22 )
      {
        v54 = *((_BYTE *)a1 + 456);
        if ( v54 || v28 >= *((unsigned int *)a1 + 115) )
        {
          v55 = v63;
          if ( v63 < v27 )
          {
            v34 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
            {
              goto LABEL_166;
            }
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 42i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
LABEL_165:
            v34 = WPP_GLOBAL_Control;
LABEL_166:
            KeyUpdateRecord = -2146893015;
            goto LABEL_167;
          }
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            v56 = L"peer request";
            if ( !v54 )
              v56 = L"write counter";
            WPP_SF_S(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0x2Bu,
              (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
              v56);
            v27 = v64;
            v55 = v63;
          }
          *(_QWORD *)&v66[0] = v55 - v27;
          *((_QWORD *)&v66[0] + 1) = &v65[v27];
          KeyUpdateRecord = CSslUserContext::GenerateKeyUpdateRecord(a1, (struct SPBuffer *)v66);
          if ( KeyUpdateRecord )
          {
            v34 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
            {
              goto LABEL_166;
            }
            v49 = 44i64;
            goto LABEL_163;
          }
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 45i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
          }
          v27 = v64;
          *((_BYTE *)a1 + 456) = 0;
        }
      }
      v29 = DWORD1(v66[0]) + v27;
      v30 = v29;
      if ( v29 >= v3->cbBuffer )
        v30 = v3->cbBuffer;
      v31 = v29 - v30;
      v3->cbBuffer = v30;
      if ( v4 )
      {
        v32 = v31;
        if ( v31 >= v5->cbBuffer )
          v32 = v5->cbBuffer;
        v5->cbBuffer = v32;
        v33 = v31 - v32;
        if ( v33 >= v4->cbBuffer )
          v33 = v4->cbBuffer;
        v4->cbBuffer = v33;
      }
      else
      {
        if ( v31 >= v5->cbBuffer )
          v31 = v5->cbBuffer;
        v5->cbBuffer = v31;
      }
      if ( !v59 )
        goto LABEL_67;
      v57 = (char *)Src;
      memcpy_0(v3->pvBuffer, Src, v3->cbBuffer);
      memcpy_0(v5->pvBuffer, &v57[v3->cbBuffer], v5->cbBuffer);
      if ( v4 )
        memcpy_0(v4->pvBuffer, &v57[v5->cbBuffer + v3->cbBuffer], v4->cbBuffer);
LABEL_178:
      LocalFree(v57);
LABEL_67:
      v34 = WPP_GLOBAL_Control;
      goto LABEL_68;
    }
    v34 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
      goto LABEL_166;
    v49 = 40i64;
LABEL_163:
    v50 = KeyUpdateRecord;
LABEL_164:
    WPP_SF_D(*((_QWORD *)v34 + 2), v49, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v50);
    goto LABEL_165;
  }
  v37 = v19 + v4->cbBuffer;
  if ( v37 >= v19 )
  {
    v19 += v4->cbBuffer;
    v63 = v37;
    goto LABEL_94;
  }
  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 5) != 0 )
  {
    v36 = 20;
LABEL_91:
    WPP_SF_DD(
      *((_QWORD *)v9 + 2),
      v36,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      -2146892963,
      -2146892963);
  }
  return 2148074333i64;
}
// 180037C6F: variable 'v58' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180085398: using guessed type wchar_t aPeerRequest[13];
// 1800853B8: using guessed type wchar_t aWriteCounter[14];
// 180098508: using guessed type __int64 __fastcall SslEncryptPacket(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _DWORD);

