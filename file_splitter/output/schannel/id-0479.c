//----- (00000001800230B0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::Initialize(CSsl3TlsServerContext *this)
{
  int v2; // edi
  char *v4; // rax
  char *v5; // rdx
  _QWORD *v6; // rcx
  _QWORD *v7; // rax
  _DWORD *v8; // rax
  __int64 v9; // rcx
  DTlsMsgMgr *v10; // rcx

  v2 = g_fEnableHelloVerifyRequest;
  if ( !*((_BYTE *)this + 233) )
    return 0i64;
  *((_QWORD *)this + 23) = g_fEnableHelloVerifyRequest != 0;
  v4 = (char *)operator new(0x60ui64);
  v5 = v4;
  if ( v4 )
  {
    *((_DWORD *)v4 + 2) = 10;
    *((_QWORD *)v4 + 11) = this;
    *((_DWORD *)v4 + 1) = 0;
    *(_DWORD *)v4 = v2 != 0;
    *((_QWORD *)v4 + 4) = v4 + 24;
    *((_QWORD *)v4 + 3) = v4 + 24;
    v6 = v4 + 40;
    v7 = v4 + 56;
    v6[1] = v6;
    *v6 = v6;
    v7[1] = v7;
    *v7 = v7;
    *((_QWORD *)v5 + 10) = v5 + 72;
    *((_QWORD *)v5 + 9) = v5 + 72;
  }
  else
  {
    v5 = 0i64;
  }
  *((_QWORD *)this + 72) = v5;
  if ( v5 )
  {
    v8 = operator new(0x30ui64);
    if ( v8 )
    {
      v9 = *((_QWORD *)this + 72);
      v8[2] = 0;
      v8[3] = 0;
      *((_QWORD *)v8 + 2) = 0i64;
      *((_QWORD *)v8 + 3) = 0i64;
      v8[8] = 0;
      *(_QWORD *)v8 = v9;
      *((_QWORD *)v8 + 5) = this;
      v8[9] = *((__int16 *)this + 96);
    }
    v10 = (DTlsMsgMgr *)*((_QWORD *)this + 72);
    *((_QWORD *)this + 73) = v8;
    if ( v8 )
    {
      *((_QWORD *)this + 28) = v10;
      if ( v2 )
        ++*((_WORD *)this + 110);
      return 0i64;
    }
    if ( v10 )
      DTlsMsgMgr::`scalar deleting destructor'(v10);
  }
  return 14i64;
}
// 1800919A4: using guessed type int g_fEnableHelloVerifyRequest;

