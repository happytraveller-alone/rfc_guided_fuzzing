//----- (0000000180004850) ----------------------------------------------------
__int64 __fastcall AutoVerifyServerCertificate(struct CSsl3TlsContext *a1)
{
  __int64 v3; // rax
  int v4; // r10d
  int v5; // edx
  int v6; // ecx
  int v7; // r9d
  int v8; // r8d
  unsigned int v9; // edx

  if ( !a1 )
    return 2148074244i64;
  if ( (*((_DWORD *)a1 + 34) & 0x4000i64) != 0 )
    return 0i64;
  v3 = *((_QWORD *)a1 + 10);
  if ( !v3 )
    return 2148074244i64;
  v4 = *(_DWORD *)(v3 + 160);
  v5 = ((v4 & 0x100) << 20) | 0x20000000;
  if ( (v4 & 0x200) == 0 )
    v5 = (v4 & 0x100) << 20;
  v6 = v5 | 0x40000000;
  if ( (v4 & 0x400) == 0 )
    v6 = v5;
  v7 = v6 | 4;
  if ( (v4 & 0x2000) == 0 )
    v7 = v6;
  v8 = v4 & 0x800 | 0x1000;
  if ( (v4 & 0x1000) == 0 )
    v8 = v4 & 0x800;
  v9 = v7 | 0x80000000;
  if ( (v4 & 0x4000) == 0 )
    v9 = v7;
  return VerifyServerCertificate(a1, v9, v8);
}

