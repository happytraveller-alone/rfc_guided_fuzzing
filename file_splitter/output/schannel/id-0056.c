// File count: 56
// Total lines: 88
------------------------------------------
__int64 __fastcall TlsGetBCryptHashProvider(enum _eTlsHashAlgorithm a1, void **a2, unsigned int *a3)
{
  unsigned int v3; // r10d
  int v6; // ebx
  char *v7; // r9
  BCRYPT_ALG_HANDLE v8; // rax
  __int64 v9; // rcx
  const WCHAR *v10; // rdx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  void *v14; // rbx
  unsigned int v15; // [rsp+48h] [rbp+10h]
  BCRYPT_ALG_HANDLE phAlgorithm; // [rsp+50h] [rbp+18h] BYREF
  const WCHAR *v17; // [rsp+58h] [rbp+20h]

  v3 = 0;
  v6 = g_dwHashInfoTotalCount;
  if ( g_dwHashInfoTotalCount )
  {
    v7 = (char *)g_pHashInfo;
    while ( !*(_QWORD *)v7 || *(_DWORD *)(*(_QWORD *)v7 + 20i64) != a1 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= g_dwHashInfoTotalCount )
        goto LABEL_8;
    }
    v6 = v3;
  }
LABEL_8:
  if ( v6 < 0 || v6 >= g_dwHashInfoTotalCount )
  {
    v6 = 0;
  }
  else
  {
    if ( v6 == 1 )
    {
      v8 = g_hMD5Provider;
      goto LABEL_13;
    }
    if ( v6 == 2 )
    {
      v8 = g_hSHAProvider;
      goto LABEL_13;
    }
  }
  v8 = (BCRYPT_ALG_HANDLE)qword_180092CF0[v6];
LABEL_13:
  phAlgorithm = v8;
  v15 = 0;
  if ( v6 >= (unsigned int)g_dwHashInfoTotalCount || (_mm_lfence(), (v9 = g_pHashInfo[v6]) == 0) )
  {
    v12 = 1168;
    goto LABEL_17;
  }
  v10 = *(const WCHAR **)v9;
  v11 = *(_DWORD *)(v9 + 8);
  v17 = *(const WCHAR **)v9;
  v15 = v11;
  if ( phAlgorithm )
    goto LABEL_16;
  if ( !v10 )
  {
    v12 = 1359;
    goto LABEL_17;
  }
  v12 = BCryptOpenAlgorithmProvider(&phAlgorithm, v10, 0i64, 0);
  if ( !v12 )
  {
    v14 = (void *)_InterlockedCompareExchange64(&qword_180092CF0[v6], (signed __int64)phAlgorithm, 0i64);
    if ( v14 )
    {
      BCryptCloseAlgorithmProvider(phAlgorithm, 0);
      phAlgorithm = v14;
    }
LABEL_16:
    v12 = 0;
  }
LABEL_17:
  *a2 = phAlgorithm;
  *a3 = v15;
  return v12;
}
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];
// 180092CF0: using guessed type signed __int64 qword_180092CF0[1];
