// File count: 842
// Total lines: 21
-----------------------------------------
__int64 __fastcall LogCredAcquireContextFailedEvent(unsigned int a1, const WCHAR *a2, char a3, int a4, int a5)
{
  const WCHAR *v8; // rdx
  __int64 result; // rax
  int v10; // [rsp+28h] [rbp-40h]
  struct _UNICODE_STRING v12; // [rsp+40h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+50h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    v8 = (const WCHAR *)pszClientString;
    if ( a3 )
      v8 = pszServerString;
    RtlInitUnicodeString(&v12, v8);
    v10 = a4;
    return SchEventWrite(&SSLEVENT_CRED_ACQUIRE_CONTEXT_FAILED, L"duudd", a1, &DestinationString, &v12, v10, a5);
  }
  return result;
}
