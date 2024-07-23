// File count: 1382
// Total lines: 99
----------------------------------------
__int64 __fastcall CTls13Context::PopulateSecTrafficSecret(
        __int64 a1,
        __int64 a2,
        char a3,
        unsigned __int8 a4,
        __int64 a5,
        __int16 a6,
        __int16 a7)
{
  char v7; // r12
  __int64 v11; // rax
  __int64 v12; // rbx
  void *v13; // rdi
  __int64 v14; // rsi
  HLOCAL v15; // rax
  unsigned int CipherSuitePRFHashAlgorithm; // edi
  void *v17; // rcx
  unsigned int v19; // [rsp+88h] [rbp+10h]

  v7 = 0;
  if ( !a2 )
    return (unsigned int)-2146892963;
  if ( !a4 )
    return (unsigned int)-2146892963;
  if ( !a5 )
    return (unsigned int)-2146892963;
  v11 = *(unsigned __int8 *)(a1 + 200);
  if ( (unsigned __int8)v11 >= 4u )
    return (unsigned int)-2146892963;
  v12 = *(_QWORD *)(a1 + 8 * v11 + 168);
  if ( !v12 )
    return (unsigned int)-2146893052;
  v13 = *(void **)(v12 + 8);
  if ( v13 )
  {
    if ( *(_DWORD *)v12 >= 0x1C0u )
    {
      memset(v13, 0, 0x1C0ui64);
      v14 = *(_QWORD *)(v12 + 8);
      goto LABEL_12;
    }
    return (unsigned int)-2146893052;
  }
  v7 = 1;
  v15 = SPExternalAlloc(0x1C0u);
  *(_QWORD *)(v12 + 8) = v15;
  v14 = (__int64)v15;
  if ( !v15 )
  {
    CipherSuitePRFHashAlgorithm = -2146893056;
LABEL_15:
    v17 = *(void **)(v12 + 8);
    if ( v17 )
    {
      SPExternalFree(v17);
      *(_QWORD *)(v12 + 8) = 0i64;
    }
    *(_DWORD *)v12 = 0;
    return CipherSuitePRFHashAlgorithm;
  }
  *(_DWORD *)v12 = 448;
LABEL_12:
  if ( (unsigned int)StringCchCopyW((char *)v14, 64i64, (char *)(a5 + 202))
    || (unsigned int)StringCchCopyW((char *)(v14 + 128), 64i64, (char *)(a5 + 714)) )
  {
    CipherSuitePRFHashAlgorithm = -2146893052;
  }
  else
  {
    v19 = *(_DWORD *)(a5 + 28);
    CipherSuitePRFHashAlgorithm = SslGetCipherSuitePRFHashAlgorithm(a2, 772i64, v19, 0i64, v14 + 256, 0);
    if ( !CipherSuitePRFHashAlgorithm )
    {
      *(_WORD *)(v14 + 384) = *(_DWORD *)(a5 + 20) >> 3;
      *(_WORD *)(v14 + 386) = 12;
      *(_WORD *)(v14 + 388) = a6;
      *(_WORD *)(v14 + 390) = a7;
      *(_DWORD *)(v14 + 392) = (a3 != 0) + 1;
      CipherSuitePRFHashAlgorithm = CTls13Context::ExportTrafficSecret(
                                      (_QWORD *)a1,
                                      a2,
                                      v19,
                                      a3,
                                      a4,
                                      v14,
                                      *(_DWORD *)v12 - 400);
      if ( !CipherSuitePRFHashAlgorithm )
      {
        ++*(_BYTE *)(a1 + 200);
        return CipherSuitePRFHashAlgorithm;
      }
    }
  }
  if ( v7 )
    goto LABEL_15;
  return CipherSuitePRFHashAlgorithm;
}
// 180098438: using guessed type __int64 __fastcall SslGetCipherSuitePRFHashAlgorithm(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
