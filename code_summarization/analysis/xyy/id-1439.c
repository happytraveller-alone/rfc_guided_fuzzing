//----- (0000000180073028) ----------------------------------------------------
struct DTlsMessage *__fastcall DTlsMsgMgr::GetNextReadyMsg(DTlsMsgMgr *this, __int64 a2, __int64 a3)
{
  _QWORD *v3; // rsi
  __int64 v5; // rbp
  __int64 v6; // rdi
  CCipherMill *v7; // r10
  __int64 v8; // rdx
  int v9; // r9d
  struct DTlsMessage *Msg; // rax

  v3 = (_QWORD *)((char *)this + 24);
  v5 = *((_QWORD *)this + 3);
  v6 = 0i64;
  v7 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
    v7 = WPP_GLOBAL_Control;
  }
  if ( (_QWORD *)*v3 != v3 )
  {
    v9 = *(_DWORD *)(v5 + 24);
    if ( v9 != *(_DWORD *)this )
    {
      if ( v7 == (CCipherMill *)&WPP_GLOBAL_Control )
        return (struct DTlsMessage *)v6;
      if ( (*((_BYTE *)v7 + 28) & 4) == 0 )
        goto LABEL_23;
      WPP_SF_dd(
        *((_QWORD *)v7 + 2),
        0x12u,
        (__int64)&WPP_7c40084571853895c7781ddf48bb701c_Traceguids,
        v9,
        *(_DWORD *)this);
      goto LABEL_22;
    }
    if ( *(_DWORD *)(v5 + 28) )
    {
      Msg = DTlsMsgMgr::FindMsg(this, *(_DWORD *)this);
      if ( Msg )
      {
        **((_QWORD **)Msg + 1) = *(_QWORD *)Msg;
        *(_QWORD *)(*(_QWORD *)Msg + 8i64) = *((_QWORD *)Msg + 1);
        --*((_DWORD *)this + 1);
        ++*(_DWORD *)this;
        v6 = v5;
LABEL_22:
        v7 = WPP_GLOBAL_Control;
        goto LABEL_23;
      }
      if ( v7 == (CCipherMill *)&WPP_GLOBAL_Control )
        return (struct DTlsMessage *)v6;
      if ( (*((_BYTE *)v7 + 28) & 1) == 0 )
        goto LABEL_23;
      v8 = 20i64;
    }
    else
    {
      if ( v7 == (CCipherMill *)&WPP_GLOBAL_Control )
        return (struct DTlsMessage *)v6;
      if ( (*((_BYTE *)v7 + 28) & 4) == 0 )
        goto LABEL_23;
      v8 = 19i64;
    }
LABEL_21:
    WPP_SF_(*((_QWORD *)v7 + 2), v8, &WPP_7c40084571853895c7781ddf48bb701c_Traceguids);
    goto LABEL_22;
  }
  if ( v7 == (CCipherMill *)&WPP_GLOBAL_Control )
    return (struct DTlsMessage *)v6;
  if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
  {
    v8 = 17i64;
    goto LABEL_21;
  }
LABEL_23:
  if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 4) != 0 )
    WPP_SF_P(*((_QWORD *)v7 + 2), 0x15u, a3, v6);
  return (struct DTlsMessage *)v6;
}
// 18007312C: variable 'v7' is possibly undefined
// 180073165: variable 'a3' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
