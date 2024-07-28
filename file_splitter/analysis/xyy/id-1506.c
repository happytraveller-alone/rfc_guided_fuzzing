//----- (0000000180078D70) ----------------------------------------------------
char GetExternalCipherAlgorithms()
{
  NTSTATUS v0; // eax
  ULONG i; // edi
  unsigned __int64 v2; // r9
  wchar_t **Heap; // rax
  wchar_t **v4; // rbx
  wchar_t *v5; // rax
  PVOID ProcessHeap; // rcx
  wchar_t *v7; // rax
  wchar_t *v8; // r9
  int v9; // ecx
  UCHAR pbOutput[8]; // [rsp+38h] [rbp-D0h] BYREF
  HANDLE v12; // [rsp+40h] [rbp-C8h] BYREF
  BCRYPT_ALG_HANDLE phAlgorithm; // [rsp+48h] [rbp-C0h] BYREF
  ULONG pcbResult[2]; // [rsp+50h] [rbp-B8h] BYREF
  HANDLE KeyHandle; // [rsp+58h] [rbp-B0h] BYREF
  ULONG ResultLength; // [rsp+60h] [rbp-A8h] BYREF
  WCHAR pszAlgId[64]; // [rsp+68h] [rbp-A0h] BYREF
  wchar_t Source[64]; // [rsp+E8h] [rbp-20h] BYREF
  char KeyInformation[16]; // [rsp+168h] [rbp+60h] BYREF
  unsigned __int16 v20[264]; // [rsp+178h] [rbp+70h] BYREF
  WCHAR v21[64]; // [rsp+388h] [rbp+280h] BYREF

  KeyHandle = 0i64;
  v12 = 0i64;
  memset_0(v21, 0, sizeof(v21));
  *(_DWORD *)pbOutput = 0;
  phAlgorithm = 0i64;
  pcbResult[0] = 0;
  LOBYTE(v0) = FreeExternalCipherAlgorithms();
  if ( (unsigned int)g_dwCipherInfoTotalCount < 0x10 )
  {
    v0 = TlsOpenRegKey(
           L"\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\Cryptography\\Providers\\Microsoft SSL Protocol Provider\\Cipher",
           0i64,
           &KeyHandle);
    if ( v0 >= 0 )
    {
      for ( i = 0; (unsigned int)g_dwCipherInfoTotalCount < 0x10; ++i )
      {
        memset_0(KeyInformation, 0, 0x218ui64);
        if ( NtEnumerateKey(KeyHandle, i, KeyBasicInformation, KeyInformation, 0x218u, &ResultLength) < 0 )
          break;
        v2 = -1i64;
        do
          ++v2;
        while ( v20[v2] );
        if ( (int)RtlStringCchCopyNW((char *)v21, 64i64, (char *)v20, v2) >= 0
          && TlsOpenRegKey(
               L"\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\Cryptography\\Providers\\Microsoft SSL Protocol "
                "Provider\\Cipher",
               v21,
               &v12) >= 0 )
        {
          memset_0(pszAlgId, 0, 0x100ui64);
          if ( (int)GetCipherDetailsFromRegistry(v12, (char *)pszAlgId) >= 0 )
          {
            TlsCloseRegKey(&v12);
            if ( BCryptOpenAlgorithmProvider(&phAlgorithm, pszAlgId, 0i64, 0) >= 0 )
            {
              if ( BCryptGetProperty(phAlgorithm, L"BlockLength", pbOutput, 4u, pcbResult, 0) >= 0 )
              {
                BCryptCloseAlgorithmProvider(phAlgorithm, 0);
                Heap = (wchar_t **)RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x20ui64);
                v4 = Heap;
                if ( Heap )
                {
                  *(_OWORD *)Heap = 0i64;
                  *((_OWORD *)Heap + 1) = 0i64;
                  v5 = (wchar_t *)RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x80ui64);
                  *v4 = v5;
                  ProcessHeap = NtCurrentPeb()->ProcessHeap;
                  if ( v5 )
                  {
                    v7 = (wchar_t *)RtlAllocateHeap(ProcessHeap, 0, 0x80ui64);
                    v8 = *v4;
                    v4[3] = v7;
                    if ( v7 )
                    {
                      wcscpy_s(v8, 0x40ui64, pszAlgId);
                      wcscpy_s(v4[3], 0x40ui64, Source);
                      v9 = g_dwCipherInfoTotalCount++;
                      *((_DWORD *)v4 + 3) = v9 - 1073741830;
                      *((_DWORD *)v4 + 4) = v9 + 28665;
                      *((_DWORD *)v4 + 2) = *(_DWORD *)pbOutput;
                      g_pCipherInfo[v9] = v4;
                      continue;
                    }
                    RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v8);
                    ProcessHeap = NtCurrentPeb()->ProcessHeap;
                  }
                  RtlFreeHeap(ProcessHeap, 0, v4);
                }
              }
              else
              {
                BCryptCloseAlgorithmProvider(phAlgorithm, 0);
              }
            }
          }
          else
          {
            TlsCloseRegKey(&v12);
          }
        }
      }
      LOBYTE(v0) = TlsCloseRegKey(&KeyHandle);
    }
  }
  return v0;
}
// 1800922A0: using guessed type _QWORD g_pCipherInfo[16];
// 180092320: using guessed type int g_dwCipherInfoTotalCount;
// 180078D70: using guessed type wchar_t Source[64];
