//----- (0000000180056428) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::InitializeClientNameInfo(CCredentialGroup *this, __int64 a2)
{
  ULONG v4; // ebx
  DWORD LastError; // eax
  wchar_t *v6; // rax
  wchar_t *v7; // rdi
  __int64 v8; // rsi
  __int64 v9; // rax
  unsigned int v10; // r14d
  HLOCAL v11; // rax
  HLOCAL v12; // rax
  ULONG nSize; // [rsp+20h] [rbp-E0h] BYREF
  int v15[3]; // [rsp+24h] [rbp-DCh] BYREF
  wchar_t NameBuffer[520]; // [rsp+30h] [rbp-D0h] BYREF

  memset_0(NameBuffer, 0, 0x404ui64);
  nSize = 514;
  v15[0] = 0;
  v4 = SslImpersonateClient(a2, v15);
  if ( !v4 )
  {
    if ( GetUserNameExW(NameDnsDomain, NameBuffer, &nSize) )
    {
      v6 = wcsrchr(NameBuffer, 0x5Cu);
      v7 = v6;
      if ( v6 )
      {
        v8 = -1i64;
        *v6 = 0;
        v9 = -1i64;
        do
          ++v9;
        while ( v7[v9 + 1] );
        v10 = (unsigned __int16)v9 + 1;
        v11 = SPExternalAlloc(2 * v10);
        *((_QWORD *)this + 109) = v11;
        if ( !v11 )
          goto LABEL_12;
        memcpy_0(v11, v7 + 1, 2i64 * v10);
        do
          ++v8;
        while ( NameBuffer[v8] );
        nSize = (unsigned __int16)v8 + 1;
        v12 = SPExternalAlloc(2 * nSize);
        *((_QWORD *)this + 110) = v12;
        if ( v12 )
          memcpy_0(v12, NameBuffer, 2i64 * nSize);
        else
LABEL_12:
          v4 = 14;
      }
      else
      {
        v4 = 1359;
      }
    }
    else if ( GetLastError() != 1332
           && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
           && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    {
      LastError = GetLastError();
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_2ffbdd3159b83638eae39e16ce6a3c9c_Traceguids, LastError);
    }
  }
  if ( v15[0] )
    RevertToSelf();
  return v4;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180056428: using guessed type wchar_t NameBuffer[520];
// 180056428: using guessed type int var_44C[3];

