// File count: 526
// Total lines: 54
-----------------------------------------
__int64 __fastcall GetKeyStorageProviderHandle(LPCWSTR pszFunction, unsigned __int8 *a2, unsigned __int64 *a3)
{
  NTSTATUS v5; // eax
  _QWORD *v6; // rcx
  unsigned int v7; // edi
  __int64 v8; // rbx
  SECURITY_STATUS v10; // eax
  PVOID pvBuffer; // [rsp+30h] [rbp-18h] BYREF
  ULONG v12; // [rsp+68h] [rbp+20h] BYREF

  v12 = 0;
  pvBuffer = 0i64;
  v5 = BCryptEnumContextFunctionProviders(
         1u,
         0i64,
         3u,
         pszFunction,
         &v12,
         (PCRYPT_CONTEXT_FUNCTION_PROVIDERS *)&pvBuffer);
  v6 = pvBuffer;
  v7 = v5;
  if ( v5 >= 0 )
  {
    v8 = 0i64;
    if ( *(_DWORD *)pvBuffer )
    {
      while ( 1 )
      {
        if ( !wcsicmp(*(const wchar_t **)(v6[1] + 8 * v8), L"Microsoft Primitive Provider") )
        {
          v7 = 0;
          v6 = pvBuffer;
          *a3 = hProvider;
          *a2 = 0;
          goto LABEL_5;
        }
        v10 = NCryptOpenStorageProvider(a3, *(LPCWSTR *)(*((_QWORD *)pvBuffer + 1) + 8 * v8), 0);
        v6 = pvBuffer;
        v7 = v10;
        if ( v10 >= 0 )
          break;
        v8 = (unsigned int)(v8 + 1);
        if ( (unsigned int)v8 >= *(_DWORD *)pvBuffer )
          goto LABEL_5;
      }
      *a2 = 1;
    }
  }
LABEL_5:
  if ( v6 )
    BCryptFreeBuffer(v6);
  return v7;
}
