// File count: 868
// Total lines: 68
-----------------------------------------
ULONG __fastcall CSslContext::QueryLocalCred(CSslContext *this, void *a2)
{
  __int64 v2; // rax
  __int64 v4; // rax
  __int64 v5; // rdx
  __int64 v6; // rcx
  DWORD PublicKeyLength; // eax
  int v8; // eax
  NTSTATUS v9; // ecx
  int v11; // ebx
  __int128 v12; // [rsp+30h] [rbp-20h] BYREF
  __int128 v13; // [rsp+40h] [rbp-10h]
  __int64 v14; // [rsp+60h] [rbp+10h] BYREF

  v14 = 0i64;
  v2 = *(_QWORD *)this;
  v12 = 0i64;
  v13 = 0i64;
  v4 = (*(__int64 (__fastcall **)(CSslContext *))(v2 + 248))(this);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 32);
    v6 = *(_QWORD *)(v4 + 432);
    if ( v5 )
    {
      *(_QWORD *)((char *)&v13 + 4) = DWORD1(v13) | 1i64;
      *((_QWORD *)&v12 + 1) = *(_QWORD *)(v5 + 8);
      LODWORD(v12) = *(_DWORD *)(v5 + 16);
      LODWORD(v13) = 1;
      if ( v6 )
      {
        if ( *(_QWORD *)v6 == -8i64 )
          PublicKeyLength = CertGetPublicKeyLength(1u, (PCERT_PUBLIC_KEY_INFO)(*(_QWORD *)(v5 + 24) + 96i64));
        else
          PublicKeyLength = *(_DWORD *)(*(_QWORD *)v6 + 12i64);
        DWORD2(v13) = PublicKeyLength;
      }
    }
  }
  if ( *((_QWORD *)&v12 + 1) )
  {
    v8 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(0i64, (unsigned int)v12, &v14);
    if ( v8 < 0 )
    {
      v9 = v8;
      return RtlNtStatusToDosError(v9);
    }
    v11 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD))(LsaTable + 72))(
            0i64,
            (unsigned int)v12,
            v14,
            *((_QWORD *)&v12 + 1));
    if ( v11 < 0 )
    {
LABEL_13:
      (*(void (__fastcall **)(_QWORD, __int64))(LsaTable + 64))(0i64, v14);
      v9 = v11;
      return RtlNtStatusToDosError(v9);
    }
    *((_QWORD *)&v12 + 1) = v14;
  }
  v11 = (*(__int64 (__fastcall **)(_QWORD, __int64, void *, __int128 *))(LsaTable + 72))(0i64, 32i64, a2, &v12);
  if ( v11 < 0 )
    goto LABEL_13;
  return 0;
}
// 180092620: using guessed type __int64 LsaTable;
