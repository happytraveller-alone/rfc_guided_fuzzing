//----- (0000000180013248) ----------------------------------------------------
signed int __fastcall SslTransferCertChainToClientProcess(PCCERT_CONTEXT *a1, const struct _CERT_CONTEXT *a2)
{
  signed int result; // eax
  unsigned __int8 *v5; // rax
  int v6; // ebx
  __int64 v7; // rax
  NTSTATUS v8; // ebx
  PCCERT_CONTEXT v9; // rax
  unsigned int v10[2]; // [rsp+30h] [rbp-38h] BYREF
  unsigned __int8 *v11; // [rsp+38h] [rbp-30h]
  char v12[40]; // [rsp+40h] [rbp-28h] BYREF

  if ( !a2 )
    return -2146893042;
  if ( !a1 )
    return 87;
  if ( !LsaTable || !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v12) )
    return 1359;
  if ( (v12[8] & 0x10) != 0 )
  {
    v9 = CertDuplicateCertificateContext(a2);
    if ( v9 )
    {
      *a1 = v9;
      return 0;
    }
    return 1359;
  }
  result = SerializeCertContext(a2, 0i64, v10);
  if ( result < 0 )
    return result;
  v5 = (unsigned __int8 *)(*(__int64 (__fastcall **)(_QWORD))(LsaTable + 384))(v10[0]);
  v11 = v5;
  if ( !v5 )
    return 14;
  v6 = SerializeCertContext(a2, v5, v10);
  if ( v6 < 0 )
  {
    (*(void (__fastcall **)(unsigned __int8 *))(LsaTable + 392))(v11);
    return v6;
  }
  v7 = LsaTable;
  v10[1] = 1;
  if ( !LsaTable )
  {
    v8 = -2146893052;
LABEL_24:
    (*(void (__fastcall **)(unsigned __int8 *))(v7 + 392))(v11);
    return RtlNtStatusToDosError(v8);
  }
  v8 = (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, unsigned int *, _BYTE))(LsaTable + 496))(
         6i64,
         0i64,
         0i64,
         v10,
         0);
  if ( v8 < 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        10i64,
        &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
        (unsigned int)v8);
    CleanupAppModeInfo(0i64);
    v7 = LsaTable;
    goto LABEL_24;
  }
  return 0;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

