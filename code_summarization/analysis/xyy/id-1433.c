//----- (00000001800727F8) ----------------------------------------------------
struct DTlsMessage *__fastcall DTlsMsgMgr::AddMsg(DTlsMsgMgr *this, __int64 a2, __int64 a3, int a4)
{
  unsigned int v5; // ebp
  int v6; // r15d
  DTlsMessage *v8; // rbx
  CCipherMill *v9; // r10
  char *v10; // rax
  __int64 v11; // r8
  DTlsMessage *v12; // rdi
  CCipherMill *v13; // rcx
  __int64 v14; // rcx
  const unsigned __int16 *v15; // rdx
  unsigned int v16; // ecx

  v5 = a3;
  v6 = a2;
  v8 = 0i64;
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_DDDD(*((_QWORD *)WPP_GLOBAL_Control + 2), a2, a3, a2, a3, a4);
    v9 = WPP_GLOBAL_Control;
  }
  if ( v5 < *(_DWORD *)this || v5 >= *((_DWORD *)this + 2) + *(_DWORD *)this )
  {
    if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
      WPP_SF_D(*((_QWORD *)v9 + 2), 12i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids, v5);
    v14 = *(_QWORD *)(*((_QWORD *)this + 11) + 80i64);
    if ( v14 )
    {
      v15 = (const unsigned __int16 *)(v14 + 216);
      v16 = *(_DWORD *)(v14 + 212);
    }
    else
    {
      v15 = &Class;
      v16 = 0;
    }
    LogDtlsRecordOutOfRecvWindow(v16, v15);
    goto LABEL_23;
  }
  v10 = (char *)SPExternalAlloc(0x48u);
  v12 = (DTlsMessage *)v10;
  if ( v10 )
  {
    *((_DWORD *)v10 + 4) = 0;
    *(_QWORD *)(v10 + 28) = 0i64;
    *((_QWORD *)v10 + 5) = 0i64;
    *((_QWORD *)v10 + 6) = 0i64;
    *((_QWORD *)v10 + 7) = 0i64;
    *((_DWORD *)v10 + 17) = 0;
    if ( (unsigned int)DTlsMessage::initMsg((DTlsMessage *)v10, v5, v6, a4, 0xCu) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
      DTlsMessage::`scalar deleting destructor'(v12);
    }
    else
    {
      DTlsMsgMgr::insertMsg(this, v12);
      ++*((_DWORD *)this + 1);
      v8 = v12;
    }
    goto LABEL_23;
  }
  v13 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control )
    return v8;
  if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
LABEL_23:
    v13 = WPP_GLOBAL_Control;
  }
  if ( v13 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v13 + 28) & 4) != 0 )
    WPP_SF_P(*((_QWORD *)v13 + 2), 0xFu, v11, v8);
  return v8;
}
// 180072991: variable 'v11' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

