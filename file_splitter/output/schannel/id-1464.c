// File count: 1464
// Total lines: 34
----------------------------------------
__int64 __fastcall GetServerEphemKey(struct CSsl3TlsServerContext *a1, struct CEphemKeyData **a2)
{
  unsigned int v2; // ebx
  struct CEphemKeyData **v5; // rax
  int v6; // edi
  unsigned int EccEphemeralKeyInfo; // ebx

  v2 = *((_DWORD *)a1 + 4);
  v5 = (struct CEphemKeyData **)(*(__int64 (__fastcall **)(struct CSsl3TlsServerContext *))(*(_QWORD *)a1 + 248i64))(a1);
  v6 = 0;
  if ( v2 )
  {
    EccEphemeralKeyInfo = CSslCredential::GetEccEphemeralKeyInfo((CSslCredential *)v5, v2, a2);
  }
  else
  {
    EccEphemeralKeyInfo = CSslCredential::GetEphemeralKeyInfo((CSslCredential *)v5, 0, v5 + 62, a2);
    if ( EccEphemeralKeyInfo == 87 )
    {
      v6 = 1;
      goto LABEL_4;
    }
  }
  if ( EccEphemeralKeyInfo )
  {
LABEL_4:
    CSslContext::SetErrorAndFatalAlert((__int64)a1, 603, EccEphemeralKeyInfo, v6 != 0 ? 40 : 80);
    return EccEphemeralKeyInfo;
  }
  *(_DWORD *)(*((_QWORD *)a1 + 11) + 8i64) = *((_DWORD *)*a2 + 10);
  return 0i64;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
