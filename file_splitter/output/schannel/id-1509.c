// File count: 1509
// Total lines: 110
---------------------------------------
char GetExternalHashAlgorithms()
{
  NTSTATUS v0; // eax
  ULONG v1; // edi
  unsigned __int64 v2; // r9
  _DWORD *Heap; // rbx
  wchar_t *v4; // rax
  __int64 v5; // rcx
  unsigned int v6; // ecx
  UCHAR pbOutput[8]; // [rsp+38h] [rbp-D0h] BYREF
  HANDLE v9; // [rsp+40h] [rbp-C8h] BYREF
  BCRYPT_ALG_HANDLE phAlgorithm; // [rsp+48h] [rbp-C0h] BYREF
  ULONG pcbResult[2]; // [rsp+50h] [rbp-B8h] BYREF
  HANDLE KeyHandle[2]; // [rsp+58h] [rbp-B0h] BYREF
  char KeyInformation[16]; // [rsp+68h] [rbp-A0h] BYREF
  unsigned __int16 v14[264]; // [rsp+78h] [rbp-90h] BYREF
  WCHAR pszAlgId[64]; // [rsp+288h] [rbp+180h] BYREF
  WCHAR v16[64]; // [rsp+308h] [rbp+200h] BYREF

  KeyHandle[0] = 0i64;
  v9 = 0i64;
  memset_0(v16, 0, sizeof(v16));
  memset_0(pszAlgId, 0, sizeof(pszAlgId));
  memset(pbOutput, 0, sizeof(pbOutput));
  phAlgorithm = 0i64;
  pcbResult[1] = 0;
  LOBYTE(v0) = FreeExternalHashAlgorithms();
  if ( (unsigned int)g_dwHashInfoTotalCount < 0x10 )
  {
    v0 = TlsOpenRegKey(
           L"\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\Cryptography\\Providers\\Microsoft SSL Protocol Provider\\Hash",
           0i64,
           KeyHandle);
    if ( v0 >= 0 )
    {
      v1 = 0;
      if ( (unsigned int)g_dwHashInfoTotalCount < 0x10 )
      {
        while ( 1 )
        {
          memset_0(KeyInformation, 0, 0x218ui64);
          pcbResult[0] = 0;
          if ( NtEnumerateKey(KeyHandle[0], v1, KeyBasicInformation, KeyInformation, 0x218u, pcbResult) < 0 )
            goto LABEL_21;
          v2 = -1i64;
          do
            ++v2;
          while ( v14[v2] );
          if ( (int)RtlStringCchCopyNW((char *)v16, 64i64, (char *)v14, v2) < 0
            || TlsOpenRegKey(
                 L"\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\Cryptography\\Providers\\Microsoft SSL Protoco"
                  "l Provider\\Hash",
                 v16,
                 &v9) < 0 )
          {
            goto LABEL_19;
          }
          if ( GetSslStringFromRegistry(v9, L"CngAlgorithm", (char *)pszAlgId) < 0
            || GetSslDWordFromRegistry(v9, L"TlsCodePoint", &pbOutput[4]) < 0 )
          {
            TlsCloseRegKey(&v9);
            goto LABEL_19;
          }
          TlsCloseRegKey(&v9);
          if ( BCryptOpenAlgorithmProvider(&phAlgorithm, pszAlgId, 0i64, 0) < 0 )
            goto LABEL_19;
          if ( BCryptGetProperty(phAlgorithm, L"HashDigestLength", pbOutput, 4u, &pcbResult[1], 0) < 0 )
            break;
          BCryptCloseAlgorithmProvider(phAlgorithm, 0);
          Heap = RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x18ui64);
          if ( !Heap )
            goto LABEL_19;
          *(_OWORD *)Heap = 0i64;
          *((_QWORD *)Heap + 2) = 0i64;
          v4 = (wchar_t *)RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x80ui64);
          *(_QWORD *)Heap = v4;
          if ( !v4 )
          {
            RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, Heap);
            goto LABEL_19;
          }
          wcscpy_s(v4, 0x40ui64, pszAlgId);
          v5 = (unsigned int)g_dwHashInfoTotalCount;
          Heap[2] = *(_DWORD *)pbOutput;
          g_pHashInfo[v5] = Heap;
          Heap[4] = v5 + 36857;
          Heap[3] = v5 - 268435462;
          v6 = v5 + 1;
          Heap[5] = *(_DWORD *)&pbOutput[4];
          g_dwHashInfoTotalCount = v6;
LABEL_20:
          ++v1;
          if ( v6 >= 0x10 )
            goto LABEL_21;
        }
        BCryptCloseAlgorithmProvider(phAlgorithm, 0);
LABEL_19:
        v6 = g_dwHashInfoTotalCount;
        goto LABEL_20;
      }
LABEL_21:
      LOBYTE(v0) = TlsCloseRegKey(KeyHandle);
    }
  }
  return v0;
}
// 1800864D8: using guessed type wchar_t aTlscodepoint[13];
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];
