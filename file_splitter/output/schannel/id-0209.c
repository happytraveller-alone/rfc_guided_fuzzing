// File count: 209
// Total lines: 155
----------------------------------------
__int64 __fastcall CSsl3TlsContext::UnwrapMessage(CSsl3TlsContext *this, struct SPBuffer *a2)
{
  __int16 v4; // r9
  int v5; // r8d
  int v6; // r10d
  _BYTE *v7; // rdx
  _BYTE *v8; // rbp
  int v9; // ecx
  int v10; // eax
  unsigned __int64 v11; // r14
  __int64 *v12; // rax
  __int64 v13; // rcx
  unsigned int v14; // eax
  int v15; // esi
  _BYTE *v16; // rcx
  __int64 v18; // rcx
  __int64 v19; // rax
  int UserKeys; // eax
  unsigned int v21; // r14d
  unsigned __int8 *v22; // rcx
  bool v23; // zf
  char v24; // cl
  __int16 v25; // [rsp+80h] [rbp+8h]

  v25 = 0;
  v4 = *((_WORD *)this + 16) & 2;
  if ( v4 )
  {
    v5 = *((_DWORD *)this + 11);
    v6 = *((_DWORD *)this + 12);
  }
  else
  {
    v5 = 0;
    v6 = 0;
  }
  v7 = (_BYTE *)*((_QWORD *)a2 + 1);
  v8 = &v7[*((unsigned int *)this + 15) + v5];
  if ( v7[1] == 0xFE && ((unsigned __int8)v7[2] | ((unsigned __int8)v7[1] << 8)) <= 0xFEFFu )
  {
    v9 = (unsigned __int8)v7[11];
    v10 = (unsigned __int8)v7[12];
  }
  else
  {
    v9 = (unsigned __int8)v7[3];
    v10 = (unsigned __int8)v7[4];
  }
  if ( (v10 | (unsigned int)(v9 << 8)) < v6 + v5 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 959, -2146893018, 0x32u);
    return 2148074278i64;
  }
  if ( !*((_QWORD *)this + 18) )
  {
    if ( v4 )
    {
      v19 = *((_QWORD *)this + 1);
      if ( v19 )
      {
        if ( *(_DWORD *)(v19 + 28) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids);
          }
          UserKeys = RemotelyGetUserKeys(this, 1u);
          v21 = UserKeys;
          if ( UserKeys )
          {
            CSslContext::SetErrorAndFatalAlert((__int64)this, 961, UserKeys, 0x50u);
            return v21;
          }
        }
      }
    }
  }
  if ( *((_BYTE *)this + 233) )
  {
    v22 = (unsigned __int8 *)*((_QWORD *)a2 + 1);
    v11 = v22[10] | ((v22[9] | ((v22[8] | ((v22[7] | ((v22[6] | ((v22[5] | ((v22[4] | ((unsigned __int64)v22[3] << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) << 8);
  }
  else
  {
    v11 = *((_QWORD *)this + 22);
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_Di(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x10u,
      (__int64)&WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids,
      *(_DWORD *)a2,
      v11);
  v12 = (__int64 *)*((_QWORD *)this + 1);
  if ( v12 )
    v13 = *v12;
  else
    v13 = 0i64;
  v14 = SslDecryptPacket(v13, *((_QWORD *)this + 18), *((_QWORD *)a2 + 1));
  v15 = v14;
  if ( v14 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids, v14);
    if ( *((_DWORD *)this + 9) >= 0x302u && (*((_DWORD *)this + 16) & 0x800A00AA) != 0 )
    {
      CSslContext::SetError((__int64)this, 962, v15);
      return 2148074278i64;
    }
    else
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 960, v15, 0x14u);
      return 2148074288i64;
    }
  }
  else
  {
    if ( (*((_DWORD *)this + 16) & 0x3000) != 0 )
    {
      LODWORD(v18) = 0;
      do
      {
        v23 = (_DWORD)v18 == 1;
        v18 = (unsigned int)(v18 - 1);
        v25 = v18;
      }
      while ( !v23 && !v8[v18] );
      v24 = v8[v18];
      if ( !v24 )
      {
        CSslContext::SetErrorAndFatalAlert((__int64)this, 960, -2146893048, 0xAu);
        return 2148074248i64;
      }
      **((_BYTE **)a2 + 1) = v24;
    }
    v16 = (_BYTE *)*((_QWORD *)a2 + 1);
    if ( *((_BYTE *)this + 233) )
    {
      v16[11] = HIBYTE(v25);
      v16[12] = v25;
    }
    else
    {
      v16[3] = HIBYTE(v25);
      v16[4] = v25;
      ++*((_QWORD *)this + 22);
    }
    return 0i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800984E0: using guessed type __int64 __fastcall SslDecryptPacket(_QWORD, _QWORD, _QWORD);
