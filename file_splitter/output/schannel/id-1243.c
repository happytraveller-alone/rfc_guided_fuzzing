//----- (0000000180063404) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::UpdateHashAndWrapMessage(
        _BYTE *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6)
{
  __int64 v6; // rbp
  unsigned int v7; // esi
  int v9; // eax
  unsigned int v10; // ebx
  int v12; // r8d
  int v13; // eax

  v6 = a4;
  v7 = a3;
  LOBYTE(a4) = 1;
  v9 = (*(__int64 (__fastcall **)(_BYTE *, __int64, __int64, __int64))(*(_QWORD *)a1 + 504i64))(a1, a2, a3, a4);
  v10 = v9;
  if ( v9 )
  {
    v12 = v9;
LABEL_6:
    CSslContext::SetErrorAndFatalAlert((__int64)a1, a5, v12, 0x50u);
    return v10;
  }
  if ( !a1[233] )
  {
    v13 = CSsl3TlsContext::WrapMessage((__int64)a1, v6, 22, v7);
    v10 = v13;
    if ( v13 )
    {
      a5 = a6;
      v12 = v13;
      goto LABEL_6;
    }
  }
  return v10;
}

