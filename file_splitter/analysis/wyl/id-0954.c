//----- (000000018004ED04) ----------------------------------------------------
__int64 __fastcall SslSealMessageConnection(struct CSslUserContext *a1, int a2, struct _SecBufferDesc *a3)
{
  struct _SecBuffer *v5; // rdi
  struct _SecBuffer *v6; // rsi
  CCipherMill *v7; // rcx
  unsigned int cBuffers; // r11d
  unsigned int v9; // edx
  PSecBuffer pBuffers; // r10
  unsigned int *p_BufferType; // r9
  char *pvBuffer; // rdx
  __int64 cbBuffer; // r8
  int v15; // eax
  unsigned __int8 *v16; // r12
  __int64 v17; // r15
  __int64 v18; // r14
  unsigned int v19; // eax
  unsigned int v20; // ebx
  int v21; // ebx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned __int16 v25; // dx
  __int64 v26; // [rsp+20h] [rbp-50h]
  int v27; // [rsp+50h] [rbp-20h] BYREF
  unsigned int v28; // [rsp+58h] [rbp-18h]
  unsigned int v29; // [rsp+5Ch] [rbp-14h] BYREF
  void *Src; // [rsp+60h] [rbp-10h]
  int v32; // [rsp+C0h] [rbp+50h]
  int v33; // [rsp+C8h] [rbp+58h]

  v32 = 0;
  v5 = 0i64;
  v6 = 0i64;
  v33 = 23;
  v27 = 23;
  v7 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 50i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    v7 = WPP_GLOBAL_Control;
  }
  cBuffers = a3->cBuffers;
  v9 = 0;
  if ( !cBuffers )
    goto LABEL_96;
  pBuffers = a3->pBuffers;
  p_BufferType = &pBuffers->BufferType;
  do
  {
    if ( *p_BufferType == 1 )
    {
      v5 = &pBuffers[v9];
    }
    else if ( *p_BufferType == 2 && !v6 )
    {
      v6 = &pBuffers[v9];
    }
    ++v9;
    p_BufferType += 4;
  }
  while ( v9 < cBuffers );
  if ( !v6 || !v5 )
  {
LABEL_96:
    if ( v7 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v7 + 28) & 5) == 0 )
      return 2148074248i64;
    v25 = 51;
    goto LABEL_98;
  }
  pvBuffer = (char *)v5->pvBuffer;
  if ( !pvBuffer || !v6->pvBuffer )
  {
    if ( v7 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v7 + 28) & 5) == 0 )
      return 2148074248i64;
    v25 = 52;
LABEL_98:
    WPP_SF_DD(
      *((_QWORD *)v7 + 2),
      v25,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      -2146893048,
      -2146893048);
    return 2148074248i64;
  }
  if ( (*((_DWORD *)a1 + 6) & 0xF0000) != 0 )
  {
    if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)v7 + 2),
        0x35u,
        (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
        -2146893054,
        -2146893054);
    return 2148074242i64;
  }
  cbBuffer = v5->cbBuffer;
  if ( v6->pvBuffer == &pvBuffer[cbBuffer] )
  {
    Src = v5->pvBuffer;
    v29 = 0;
    v15 = v5->cbBuffer + v6->cbBuffer;
    goto LABEL_29;
  }
  v32 = 1;
  Src = LocalAlloc(0x40u, (unsigned int)(cbBuffer + v6->cbBuffer));
  if ( Src )
  {
    v15 = v5->cbBuffer + v6->cbBuffer;
    v7 = WPP_GLOBAL_Control;
    v29 = 0;
LABEL_29:
    v28 = v15;
    v16 = (unsigned __int8 *)v5->pvBuffer;
    v17 = v5->cbBuffer;
    if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)v7 + 2), 57i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
        v7 = WPP_GLOBAL_Control;
      }
      if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)v7 + 2), 58i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, (unsigned int)v17);
          v7 = WPP_GLOBAL_Control;
        }
        if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)v7 + 2), 59i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, (unsigned int)v17);
            v7 = WPP_GLOBAL_Control;
          }
          if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
            {
              WPP_SF_D(*((_QWORD *)v7 + 2), 60i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v29);
              v7 = WPP_GLOBAL_Control;
            }
            if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 4) != 0 )
            {
              WPP_SF_D(*((_QWORD *)v7 + 2), 61i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v28);
              v7 = WPP_GLOBAL_Control;
            }
          }
        }
      }
    }
    v18 = (unsigned int)(*((_DWORD *)a1 + 16) + *((_DWORD *)a1 + 17));
    if ( a2 == 0x40000000 )
    {
      v19 = HandleSpecialMessage(a1, v16, v17, (enum eTlsRecordType *)&v27);
      v7 = WPP_GLOBAL_Control;
      v20 = v19;
      if ( v19 )
        goto LABEL_76;
      v33 = v27;
    }
    if ( !v32 )
    {
      memmove_s((char *)v5->pvBuffer + v18, v5->cbBuffer, v5->pvBuffer, v5->cbBuffer);
      v7 = WPP_GLOBAL_Control;
      v16 += (unsigned int)v18;
    }
    if ( (*((_DWORD *)a1 + 6) & 0x3000) != 0 )
    {
      v21 = 23;
      v16[v17] = v33;
      LODWORD(v17) = v17 + 1;
      v7 = WPP_GLOBAL_Control;
    }
    else
    {
      v21 = v33;
    }
    if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)v7 + 2), 62i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
        v7 = WPP_GLOBAL_Control;
      }
      if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)v7 + 2), 63i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, (unsigned int)v17);
          v7 = WPP_GLOBAL_Control;
        }
        if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
          {
            WPP_SF_q(
              *((_QWORD *)v7 + 2),
              0x40u,
              (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
              (char *)Src + (unsigned int)v18);
            v7 = WPP_GLOBAL_Control;
          }
          if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
          {
            if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)v7 + 2),
                65i64,
                &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
                v28 - (unsigned int)v18);
              v7 = WPP_GLOBAL_Control;
            }
            if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
              {
                WPP_SF_D(*((_QWORD *)v7 + 2), 66i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v29);
                v7 = WPP_GLOBAL_Control;
              }
              if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 4) != 0 )
                WPP_SF_D(
                  *((_QWORD *)v7 + 2),
                  67i64,
                  &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
                  *((unsigned int *)a1 + 26));
            }
          }
        }
      }
    }
    v22 = SslEncryptPacket(
            *((_QWORD *)a1 + 11),
            *((_QWORD *)a1 + 6),
            v16,
            (unsigned int)v17,
            Src,
            v28,
            &v29,
            *((_QWORD *)a1 + 13),
            v21,
            0);
    ++*((_QWORD *)a1 + 13);
    v20 = v22;
    if ( !v22 )
    {
      v23 = v29;
      if ( v29 >= v5->cbBuffer )
        v23 = v5->cbBuffer;
      v24 = v29 - v23;
      v5->cbBuffer = v23;
      if ( v24 >= v6->cbBuffer )
        v24 = v6->cbBuffer;
      v6->cbBuffer = v24;
      if ( !v32 )
        goto LABEL_85;
      memcpy_0(v5->pvBuffer, Src, v5->cbBuffer);
      memcpy_0(v6->pvBuffer, (char *)Src + v5->cbBuffer, v6->cbBuffer);
LABEL_84:
      LocalFree(Src);
LABEL_85:
      v7 = WPP_GLOBAL_Control;
LABEL_86:
      if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control
        && ((*((_BYTE *)v7 + 28) & 1) != 0 && v20 || (*((_BYTE *)v7 + 28) & 4) != 0) )
      {
        LODWORD(v26) = v20;
        WPP_SF_DD(*((_QWORD *)v7 + 2), 0x47u, (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v20, v26);
      }
      return v20;
    }
    v7 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 68i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v22);
      v7 = WPP_GLOBAL_Control;
    }
    v20 = -2146893015;
LABEL_76:
    if ( !v32 )
      goto LABEL_86;
    goto LABEL_84;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x38u,
      (__int64)&WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
      -2146893056,
      -2146893056);
  return 2148074240i64;
}
// 18004F255: variable 'v26' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098508: using guessed type __int64 __fastcall SslEncryptPacket(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _DWORD);
