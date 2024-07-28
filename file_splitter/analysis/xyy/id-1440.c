//----- (0000000180073190) ----------------------------------------------------
__int64 __fastcall DTlsHandshakeQueue::SetCcs(
        DTlsHandshakeQueue *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int64 a4)
{
  size_t v5; // r15
  unsigned int v8; // edi
  CCipherMill *v9; // rcx
  __int64 v10; // rdx
  CCipherMill *v12; // r10
  DTlsMessage *v13; // rax
  DTlsMessage *v14; // rbx
  unsigned int inited; // r14d
  _BYTE *v16; // rdx
  __int16 v17; // ax
  unsigned __int64 v18; // rsi

  v5 = a3;
  v8 = 590610;
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x16u, (__int64)&WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
    v9 = WPP_GLOBAL_Control;
  }
  if ( *((_DWORD *)this + 2) )
  {
    if ( v9 == (CCipherMill *)&WPP_GLOBAL_Control )
      return v8;
    if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
    {
      v10 = 23i64;
LABEL_8:
      WPP_SF_(*((_QWORD *)v9 + 2), v10, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
LABEL_9:
      v9 = WPP_GLOBAL_Control;
    }
  }
  else
  {
    if ( CSsl3TlsContext::CheckRecordValidity(*((CSsl3TlsContext **)this + 5), a4) )
    {
      v13 = (DTlsMessage *)SPExternalAlloc(0x48u);
      v14 = v13;
      if ( !v13 )
      {
        v9 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
          v9 = WPP_GLOBAL_Control;
        }
        v8 = 14;
        goto LABEL_10;
      }
      *((_DWORD *)v13 + 4) = 0;
      *((_DWORD *)v13 + 7) = 0;
      *((_DWORD *)v13 + 8) = 0;
      *((_QWORD *)v13 + 5) = 0i64;
      *((_QWORD *)v13 + 6) = 0i64;
      *((_QWORD *)v13 + 7) = 0i64;
      *((_DWORD *)v13 + 17) = 0;
      inited = DTlsMessage::initMsg(v13, 0, 20, v5, 0xDu);
      if ( inited )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 26i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
        v8 = inited;
        DTlsMessage::`scalar deleting destructor'(v14);
        v9 = WPP_GLOBAL_Control;
        goto LABEL_10;
      }
      v16 = (_BYTE *)*((_QWORD *)v14 + 5);
      *v16 = 20;
      v17 = *(_WORD *)(*((_QWORD *)this + 5) + 34i64);
      v16[2] = v17;
      v16[1] = HIBYTE(v17);
      v16[4] = BYTE6(a4);
      v16[3] = HIBYTE(a4);
      v18 = a4 & 0xFFFFFFFFFFFFi64;
      v16[12] = v5;
      v16[10] = v18;
      v18 >>= 8;
      v16[9] = v18;
      v18 >>= 8;
      v16[8] = v18;
      v18 >>= 8;
      v16[7] = v18;
      v18 >>= 8;
      v16[6] = v18;
      v16[5] = BYTE1(v18);
      v16[11] = BYTE1(v5);
      memcpy_0(v16 + 13, a2, v5);
      *((_QWORD *)this + 2) = v14;
      *((_DWORD *)this + 2) = 1;
      goto LABEL_9;
    }
    v9 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != v12 && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v10 = 24i64;
      goto LABEL_8;
    }
  }
LABEL_10:
  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v9 + 2), 27i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids, v8);
  return v8;
}
// 18007328D: variable 'v12' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
