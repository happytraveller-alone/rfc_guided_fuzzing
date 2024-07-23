//----- (000000018000657C) ----------------------------------------------------
__int64 __fastcall UpdateServerCertificateSerialChainProperty(struct CSsl3TlsClientContext *a1, unsigned int a2)
{
  __int64 v4; // rdx
  __int64 v6; // [rsp+30h] [rbp+8h] BYREF

  v6 = 0i64;
  (*(void (__fastcall **)(struct CSsl3TlsClientContext *, __int64 *))(*(_QWORD *)a1 + 224i64))(a1, &v6);
  v4 = *(unsigned int *)(v6 + 360);
  if ( (_DWORD)v4 )
    I_CertFinishSslHandshake(
      *(_QWORD *)(v6 + 352),
      v4,
      *((unsigned __int8 *)a1 + 307) | ((*((unsigned __int8 *)a1 + 306) | ((*((unsigned __int8 *)a1 + 305) | (*((unsigned __int8 *)a1 + 304) << 8)) << 8)) << 8),
      a2);
  return 0i64;
}
// 180098188: using guessed type __int64 __fastcall I_CertFinishSslHandshake(_QWORD, _QWORD, _QWORD, _QWORD);

