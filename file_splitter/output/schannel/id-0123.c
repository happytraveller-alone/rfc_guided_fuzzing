// File count: 123
// Total lines: 101
----------------------------------------
NTSTATUS __fastcall GenerateHash(
        BCRYPT_ALG_HANDLE hAlgorithm,
        UCHAR *a2,
        unsigned __int8 *a3,
        ULONG a4,
        unsigned __int8 *a5,
        ULONG cbOutput)
{
  NTSTATUS result; // eax
  __int64 v11; // rdx
  ULONG v12; // r9d
  UCHAR *p_phHash; // rbx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rax
  void *v16; // rsp
  NTSTATUS v17; // edi
  _DWORD *v18; // rax
  __int64 v19; // [rsp+0h] [rbp-40h] BYREF
  UCHAR pbOutput[4]; // [rsp+40h] [rbp+0h] BYREF
  BCRYPT_HASH_HANDLE phHash; // [rsp+48h] [rbp+8h] BYREF
  ULONG pcbResult; // [rsp+50h] [rbp+10h] BYREF

  phHash = 0i64;
  result = BCryptGetProperty(hAlgorithm, L"ObjectLength", pbOutput, 4u, &pcbResult, 0);
  if ( result )
    return result;
  v12 = *(_DWORD *)pbOutput;
  p_phHash = 0i64;
  if ( *(_DWORD *)pbOutput )
  {
    v11 = *(unsigned int *)pbOutput;
    if ( *(unsigned int *)pbOutput <= (unsigned __int64)g_ulMaxStackAllocSize )
    {
      v14 = *(unsigned int *)pbOutput + g_ulAdditionalProbeSize + 8;
      if ( v14 >= *(unsigned int *)pbOutput )
      {
        if ( !(unsigned int)VerifyStackAvailable(v14) )
        {
LABEL_22:
          v12 = *(_DWORD *)pbOutput;
          goto LABEL_23;
        }
        v12 = *(_DWORD *)pbOutput;
        v15 = (unsigned int)(*(_DWORD *)pbOutput + 8) + 15i64;
        if ( v15 <= (unsigned int)(*(_DWORD *)pbOutput + 8) )
          v15 = 0xFFFFFFFFFFFFFF0i64;
        v16 = alloca(v15 & 0xFFFFFFFFFFFFFFF0ui64);
        p_phHash = pbOutput;
        if ( &v19 != (__int64 *)-64i64 )
        {
          *(_DWORD *)pbOutput = 1801679955;
          p_phHash = (UCHAR *)&phHash;
          if ( &phHash )
          {
            v12 = *(_DWORD *)pbOutput;
            goto LABEL_11;
          }
          goto LABEL_22;
        }
      }
    }
  }
LABEL_23:
  if ( v12 + 8 >= v12 )
  {
    v18 = (_DWORD *)((__int64 (__fastcall *)(_QWORD, __int64))g_pfnAllocate)(v12 + 8, v11);
    if ( !v18 )
      return 14;
    *v18 = 1885431112;
    p_phHash = (UCHAR *)(v18 + 2);
    v12 = *(_DWORD *)pbOutput;
  }
  if ( !p_phHash )
    return 14;
LABEL_11:
  v17 = BCryptCreateHash(hAlgorithm, &phHash, p_phHash, v12, 0i64, 0, 0);
  if ( !v17 )
  {
    v17 = BCryptHashData(phHash, a2 + 272, 0x40u, 0);
    if ( !v17 )
    {
      v17 = BCryptHashData(phHash, a3, a4, 0);
      if ( !v17 )
        v17 = BCryptFinishHash(phHash, a5, cbOutput, 0);
    }
  }
  if ( phHash )
    BCryptDestroyHash(phHash);
  if ( p_phHash )
  {
    if ( *((_DWORD *)p_phHash - 2) == 1885431112 )
      ((void (__fastcall *)(UCHAR *))g_pfnFree)(p_phHash - 8);
  }
  return v17;
}
// 180034FB4: variable 'v11' is possibly undefined
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
