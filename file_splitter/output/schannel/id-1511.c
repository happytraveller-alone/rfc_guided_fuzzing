// File count: 1511
// Total lines: 109
---------------------------------------
char GetExternalKeyExchangeAlgorithms()
{
  NTSTATUS v0; // eax
  ULONG i; // edi
  unsigned __int64 v2; // r9
  _QWORD *Heap; // rbx
  wchar_t *v4; // rax
  int v5; // ecx
  __int64 v6; // rax
  HANDLE v8; // [rsp+38h] [rbp-D0h] BYREF
  ULONG ResultLength[2]; // [rsp+40h] [rbp-C8h] BYREF
  HANDLE KeyHandle[2]; // [rsp+48h] [rbp-C0h] BYREF
  char KeyInformation[16]; // [rsp+58h] [rbp-B0h] BYREF
  unsigned __int16 v12[264]; // [rsp+68h] [rbp-A0h] BYREF
  wchar_t String1[64]; // [rsp+278h] [rbp+170h] BYREF
  WCHAR v14[64]; // [rsp+2F8h] [rbp+1F0h] BYREF
  wchar_t Source[64]; // [rsp+378h] [rbp+270h] BYREF

  KeyHandle[0] = 0i64;
  v8 = 0i64;
  memset_0(v14, 0, sizeof(v14));
  memset_0(Source, 0, sizeof(Source));
  memset_0(String1, 0, sizeof(String1));
  LOBYTE(v0) = FreeExternalKeyExchangeAlgorithms();
  if ( (unsigned int)g_dwKeyExchangeInfoTotalCount < 0xC )
  {
    v0 = TlsOpenRegKey(
           L"\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\Cryptography\\Providers\\Microsoft SSL Protocol Prov"
            "ider\\KeyExchange",
           0i64,
           KeyHandle);
    if ( v0 >= 0 )
    {
      for ( i = 0; (unsigned int)g_dwKeyExchangeInfoTotalCount < 0xC; ++i )
      {
        memset_0(KeyInformation, 0, 0x218ui64);
        ResultLength[0] = 0;
        if ( NtEnumerateKey(KeyHandle[0], i, KeyBasicInformation, KeyInformation, 0x218u, ResultLength) < 0 )
          break;
        v2 = -1i64;
        do
          ++v2;
        while ( v12[v2] );
        if ( (int)RtlStringCchCopyNW((char *)v14, 64i64, (char *)v12, v2) < 0 )
          break;
        if ( TlsOpenRegKey(
               L"\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\Cryptography\\Providers\\Microsoft SSL Protocol "
                "Provider\\KeyExchange",
               v14,
               &v8) >= 0 )
        {
          if ( GetSslStringFromRegistry(v8, L"CngAlgorithm", (char *)Source) < 0
            || GetSslStringFromRegistry(v8, L"MessageFlow", (char *)String1) < 0 )
          {
            TlsCloseRegKey(&v8);
          }
          else
          {
            TlsCloseRegKey(&v8);
            Heap = RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x18ui64);
            if ( Heap )
            {
              *(_OWORD *)Heap = 0i64;
              Heap[2] = 0i64;
              v4 = (wchar_t *)RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x80ui64);
              *Heap = v4;
              if ( v4 )
              {
                wcscpy_s(v4, 0x40ui64, Source);
                v5 = g_dwKeyExchangeInfoTotalCount;
                *((_DWORD *)Heap + 3) = g_dwKeyExchangeInfoTotalCount + 45049;
                *((_DWORD *)Heap + 2) = v5 - 805306374;
                if ( wcsicmp(String1, L"RSA") )
                {
                  if ( wcsicmp(String1, L"DH") )
                  {
                    if ( wcsicmp(String1, L"ECDH") )
                      *((_DWORD *)Heap + 4) = wcsicmp(String1, L"PSK") == 0 ? 4 : 0;
                    else
                      *((_DWORD *)Heap + 4) = 3;
                  }
                  else
                  {
                    *((_DWORD *)Heap + 4) = 2;
                  }
                }
                else
                {
                  *((_DWORD *)Heap + 4) = 1;
                }
                v6 = (unsigned int)g_dwKeyExchangeInfoTotalCount++;
                g_pKeyExchangeInfo[v6] = Heap;
              }
              else
              {
                RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, Heap);
              }
            }
          }
        }
      }
      LOBYTE(v0) = TlsCloseRegKey(KeyHandle);
    }
  }
  return v0;
}
// 1800923B0: using guessed type int g_dwKeyExchangeInfoTotalCount;
// 1800923C0: using guessed type _QWORD g_pKeyExchangeInfo[12];
