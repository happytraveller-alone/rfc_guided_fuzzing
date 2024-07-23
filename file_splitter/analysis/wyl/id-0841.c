//----- (0000000180044C38) ----------------------------------------------------
__int64 __fastcall LogCreateCredFailedEvent(unsigned int a1, const WCHAR *a2, char a3, int a4)
{
  const WCHAR *v7; // rdx
  __int64 result; // rax
  int v9; // [rsp+28h] [rbp-30h]
  struct _UNICODE_STRING v10; // [rsp+30h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-18h] BYREF

  if ( (g_dwEventLogging & 1) != 0 )
  {
    RtlInitUnicodeString(&DestinationString, a2);
    v7 = (const WCHAR *)pszClientString;
    if ( a3 )
      v7 = pszServerString;
    RtlInitUnicodeString(&v10, v7);
    v9 = a4;
    return SchEventWrite(&SSLEVENT_CREATE_CRED_FAILED, L"duud", a1, &DestinationString, &v10, v9);
  }
  return result;
}

