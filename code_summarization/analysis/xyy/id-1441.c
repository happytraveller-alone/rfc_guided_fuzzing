//----- (0000000180073410) ----------------------------------------------------
__int64 __fastcall DTlsHandshakeQueue::SetFinish(
        DTlsHandshakeQueue *this,
        unsigned __int8 *a2,
        unsigned int a3,
        __int64 a4)
{
  size_t v5; // r15
  unsigned int v8; // edi
  CCipherMill *v9; // rcx
  DTlsMessage *v10; // rax
  DTlsMessage *v11; // rbx
  unsigned int inited; // ebp
  _BYTE *v13; // rdx
  __int16 v14; // ax
  unsigned __int64 v15; // rsi

  v5 = a3;
  v8 = 590610;
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Cu, (__int64)&WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
    v9 = WPP_GLOBAL_Control;
  }
  if ( *((_DWORD *)this + 3) )
  {
    if ( v9 == (CCipherMill *)&WPP_GLOBAL_Control )
      return v8;
    if ( (*((_BYTE *)v9 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v9 + 2), 29i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
      v9 = WPP_GLOBAL_Control;
    }
  }
  else
  {
    v10 = (DTlsMessage *)SPExternalAlloc(0x48u);
    v11 = v10;
    if ( v10 )
    {
      *((_DWORD *)v10 + 4) = 0;
      *((_DWORD *)v10 + 7) = 0;
      *((_DWORD *)v10 + 8) = 0;
      *((_QWORD *)v10 + 5) = 0i64;
      *((_QWORD *)v10 + 6) = 0i64;
      *((_QWORD *)v10 + 7) = 0i64;
      *((_DWORD *)v10 + 17) = 0;
      inited = DTlsMessage::initMsg(v10, 0, 22, v5, 0xDu);
      if ( inited )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
        v8 = inited;
        DTlsMessage::`scalar deleting destructor'(v11);
      }
      else
      {
        v13 = (_BYTE *)*((_QWORD *)v11 + 5);
        *v13 = 22;
        v14 = *(_WORD *)(*((_QWORD *)this + 5) + 34i64);
        v13[2] = v14;
        v13[1] = HIBYTE(v14);
        v13[4] = BYTE6(a4);
        v13[3] = HIBYTE(a4);
        v15 = a4 & 0xFFFFFFFFFFFFi64;
        v13[12] = v5;
        v13[10] = v15;
        v15 >>= 8;
        v13[9] = v15;
        v15 >>= 8;
        v13[8] = v15;
        v15 >>= 8;
        v13[7] = v15;
        v15 >>= 8;
        v13[6] = v15;
        v13[5] = BYTE1(v15);
        v13[11] = BYTE1(v5);
        memcpy_0(v13 + 13, a2, v5);
        *((_DWORD *)v11 + 17) = 1;
        *((_QWORD *)this + 3) = v11;
        *((_DWORD *)this + 3) = 1;
      }
      v9 = WPP_GLOBAL_Control;
    }
    else
    {
      v9 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
        v9 = WPP_GLOBAL_Control;
      }
      v8 = 14;
    }
  }
  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v9 + 2), 32i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids, v8);
  return v8;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
