//----- (0000000180072F28) ----------------------------------------------------
struct DTlsMessage *__fastcall DTlsHandshakeQueue::GetNextReadyHandshakeMsg(DTlsMsgMgr **this, __int64 a2, __int64 a3)
{
  struct DTlsMessage *NextReadyMsg; // rdi
  CCipherMill *v5; // rcx
  __int64 v6; // rdx

  NextReadyMsg = DTlsMsgMgr::GetNextReadyMsg(*this, a2, a3);
  if ( NextReadyMsg )
  {
    *((_DWORD *)this + 8) = 1;
    return NextReadyMsg;
  }
  if ( *((_DWORD *)this + 8) == 1 || *((_DWORD *)this + 8) == 4 )
  {
    if ( *((_DWORD *)this + 2) )
    {
      if ( (*(unsigned __int8 (__fastcall **)(DTlsMsgMgr *))(*(_QWORD *)this[5] + 520i64))(this[5]) )
      {
        NextReadyMsg = this[2];
        this[2] = 0i64;
        *((_DWORD *)this + 2) = 0;
        *((_DWORD *)this + 8) = 2;
        v5 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          v6 = 44i64;
          goto LABEL_14;
        }
      }
    }
  }
  else if ( *((_DWORD *)this + 8) == 2 )
  {
    if ( *((_DWORD *)this + 3) )
    {
      NextReadyMsg = this[3];
      this[3] = 0i64;
      *((_DWORD *)this + 3) = 0;
      *((_DWORD *)this + 8) = 3;
      v5 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v6 = 45i64;
LABEL_14:
        WPP_SF_(*((_QWORD *)v5 + 2), v6, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
      }
    }
  }
  return NextReadyMsg;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
