//----- (0000000180004750) ----------------------------------------------------
__int64 __fastcall CreateServerCertificateSerialChainProperty(struct CSsl3TlsClientContext *a1)
{
  __int64 v1; // rcx
  __int64 v2; // rdx
  __int64 v3; // r10
  __int64 v4; // r9
  __int64 v5; // r8
  int v6; // eax
  __int64 v7; // rbx
  __int64 v8; // rdi
  int v9; // esi
  void *v10; // rcx
  int v12; // [rsp+50h] [rbp+20h] BYREF
  __int64 v13; // [rsp+58h] [rbp+28h] BYREF
  __int64 v14; // [rsp+60h] [rbp+30h] BYREF

  v13 = 0i64;
  v14 = 0i64;
  if ( !a1 )
    return 2148074244i64;
  (*(void (__fastcall **)(struct CSsl3TlsClientContext *, __int64 *))(*(_QWORD *)a1 + 224i64))(a1, &v13);
  if ( !v13 )
    return 2148074244i64;
  RtlAcquireResourceExclusive((PRTL_RESOURCE)(v13 + 72), 1u);
  v1 = v13;
  v2 = *(unsigned int *)(v13 + 32);
  v3 = *(_QWORD *)(v13 + 24);
  v4 = *(unsigned int *)(v13 + 344);
  v5 = *(_QWORD *)(v13 + 336);
  v6 = *(_DWORD *)(v13 + 360);
  v12 = v6;
  if ( (_DWORD)v2 && !v6 )
  {
    if ( (unsigned int)I_CertProcessSslHandshake(v3, v2, v5, v4, &v14, &v12) )
    {
      v7 = v13;
      v8 = v14;
      v9 = v12;
      v10 = *(void **)(v13 + 352);
      if ( v10 )
        CryptMemFree(v10);
      *(_DWORD *)(v7 + 360) = v9;
      *(_QWORD *)(v7 + 352) = v8;
    }
    v1 = v13;
  }
  RtlReleaseResource((PRTL_RESOURCE)(v1 + 72));
  return 0i64;
}
// 180098180: using guessed type __int64 __fastcall I_CertProcessSslHandshake(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD);

