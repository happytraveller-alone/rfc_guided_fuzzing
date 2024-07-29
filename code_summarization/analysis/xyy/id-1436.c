//----- (0000000180072ADC) ----------------------------------------------------
__int64 __fastcall DTlsHandshakeQueue::DtlsReorderHandshake(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int64 a5)
{
  unsigned int v5; // ebp
  unsigned __int8 *v6; // rdi
  int v7; // r15d
  unsigned int v9; // ebx
  CCipherMill *v10; // r10
  CSsl3TlsContext *v11; // r8
  __int64 v12; // rax
  unsigned int v13; // r13d
  const unsigned __int16 *v14; // r12
  unsigned int v15; // eax
  CCipherMill *v16; // r11
  int v17; // r15d
  unsigned int v18; // r12d
  unsigned int v19; // esi
  CCipherMill *v20; // r10
  DTlsMsgMgr *v21; // r11
  struct DTlsMessage *Msg; // r13
  __int64 v23; // rdx
  unsigned int v24; // eax
  __int64 v25; // rdx
  unsigned __int16 *v27; // [rsp+70h] [rbp+8h]
  unsigned int v28; // [rsp+78h] [rbp+10h]
  int v29; // [rsp+90h] [rbp+28h]

  v5 = a4;
  v6 = (unsigned __int8 *)a3;
  v7 = a2;
  v9 = 590610;
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_DDi(*((_QWORD *)WPP_GLOBAL_Control + 2), a2, a3, a2, a4, a5);
    v10 = WPP_GLOBAL_Control;
  }
  v11 = *(CSsl3TlsContext **)(a1 + 40);
  v12 = *((_QWORD *)v11 + 10);
  if ( v12 )
  {
    v13 = *(_DWORD *)(v12 + 212);
    v14 = (const unsigned __int16 *)(v12 + 216);
  }
  else
  {
    v14 = &Class;
    v13 = 0;
  }
  v28 = v13;
  v27 = (unsigned __int16 *)v14;
  if ( v7 == 20 )
  {
    v15 = DTlsHandshakeQueue::SetCcs((DTlsHandshakeQueue *)a1, v6, v5, a5);
LABEL_9:
    v9 = v15;
    goto LABEL_55;
  }
  if ( v7 != 22 )
  {
    if ( v10 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v10 + 28) & 1) == 0 )
      goto LABEL_56;
    WPP_SF_(*((_QWORD *)v10 + 2), 34i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
LABEL_55:
    v10 = WPP_GLOBAL_Control;
    goto LABEL_56;
  }
  if ( *(_DWORD *)(a1 + 36) == -1 || *(_DWORD *)(a1 + 36) < HIWORD(a5) )
  {
    v15 = DTlsHandshakeQueue::SetFinish((DTlsHandshakeQueue *)a1, v6, v5, a5);
    goto LABEL_9;
  }
  if ( !CSsl3TlsContext::CheckRecordValidity(v11, a5) )
  {
    if ( WPP_GLOBAL_Control != v16 && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 35i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
    LogDtlsRecordOutOfRecvWindow(v13, v14);
    goto LABEL_55;
  }
  while ( 1 )
  {
    v10 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != v16 && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
      v10 = WPP_GLOBAL_Control;
      v16 = (CCipherMill *)&WPP_GLOBAL_Control;
    }
    if ( v5 < 0xC )
    {
      if ( v10 == v16 || (*((_BYTE *)v10 + 28) & 1) == 0 )
        goto LABEL_50;
      v25 = 37i64;
LABEL_48:
      WPP_SF_(*((_QWORD *)v10 + 2), v25, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
      goto LABEL_49;
    }
    v17 = v6[3] + ((v6[2] + (v6[1] << 8)) << 8);
    v29 = v6[8] + ((v6[7] + (v6[6] << 8)) << 8);
    v18 = v6[11] + ((v6[10] + (v6[9] << 8)) << 8);
    if ( (unsigned __int64)v18 + 12 > v5 )
    {
      if ( v10 == v16 || (*((_BYTE *)v10 + 28) & 1) == 0 )
        goto LABEL_50;
      v25 = 38i64;
      goto LABEL_48;
    }
    v19 = v6[5] + (v6[4] << 8);
    Msg = DTlsMsgMgr::FindMsg(*(DTlsMsgMgr **)a1, v19);
    if ( Msg )
      goto LABEL_33;
    if ( v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v20 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v20 + 2), 39i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
      v21 = *(DTlsMsgMgr **)a1;
    }
    Msg = DTlsMsgMgr::AddMsg(v21, 22i64, v19, v17);
    if ( Msg )
      break;
LABEL_37:
    v6 += v18 + 12;
    v5 += -12 - v18;
    if ( !v5 )
      goto LABEL_55;
    v16 = (CCipherMill *)&WPP_GLOBAL_Control;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
  v23 = *((_QWORD *)Msg + 5);
  *(_BYTE *)v23 = *v6;
  *(_BYTE *)(v23 + 5) = v19;
  *(_WORD *)(v23 + 7) = 0;
  *(_BYTE *)(v23 + 1) = BYTE2(v17);
  *(_BYTE *)(v23 + 9) = BYTE2(v17);
  *(_BYTE *)(v23 + 4) = BYTE1(v19);
  *(_BYTE *)(v23 + 3) = v17;
  *(_BYTE *)(v23 + 2) = BYTE1(v17);
  *(_BYTE *)(v23 + 11) = v17;
  *(_BYTE *)(v23 + 10) = BYTE1(v17);
  *(_BYTE *)(v23 + 6) = 0;
  v20 = WPP_GLOBAL_Control;
LABEL_33:
  if ( v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v20 + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)v20 + 2), 41i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
  v24 = DTlsMessage::addFragment(Msg, v28, v27, v6 + 12, v29, v18);
  v9 = v24;
  if ( !v24 )
    goto LABEL_37;
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 42i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids, v24);
LABEL_49:
    v10 = WPP_GLOBAL_Control;
  }
LABEL_50:
  v9 = -2146893018;
LABEL_56:
  if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v10 + 2), 43i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids, v9);
  return v9;
}
// 180072BD5: variable 'v16' is possibly undefined
// 180072CDC: variable 'v20' is possibly undefined
// 180072D0A: variable 'v21' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
