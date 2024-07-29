//----- (0000000180055ED0) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::GetKeyFilePath(CCredentialGroup *this, unsigned __int16 **a2)
{
  DWORD LastError; // ebx
  struct _RTL_RESOURCE *v5; // r15
  unsigned __int16 *v6; // rdi
  unsigned __int16 **v7; // r14
  SIZE_T v8; // rsi
  wchar_t *v9; // rax
  size_t *v10; // r8
  CCredentialGroup *v11; // rcx
  size_t v13; // [rsp+20h] [rbp-E0h]
  LPWSTR StringSid; // [rsp+30h] [rbp-D0h] BYREF
  size_t pcchLength; // [rsp+38h] [rbp-C8h] BYREF
  unsigned __int16 v16[8]; // [rsp+40h] [rbp-C0h] BYREF
  __int128 v17; // [rsp+50h] [rbp-B0h]
  __int64 v18; // [rsp+60h] [rbp-A0h]
  int v19; // [rsp+68h] [rbp-98h]
  wchar_t pszSrc[64]; // [rsp+70h] [rbp-90h] BYREF
  unsigned __int8 Sid[80]; // [rsp+F0h] [rbp-10h] BYREF

  LastError = 0;
  memset_0(Sid, 0, 0x44ui64);
  v5 = (struct _RTL_RESOURCE *)((char *)this + 48);
  StringSid = 0i64;
  v6 = 0i64;
  wcscpy(pszSrc, L"%ALLUSERSPROFILE%\\Microsoft\\Crypto\\TlsSessionTicketKeys\\");
  v19 = *(_DWORD *)L"y";
  *(_OWORD *)v16 = *(_OWORD *)L"\\SessionTicketKey.key";
  v18 = *(_QWORD *)L"y.key";
  v17 = *(_OWORD *)L"TicketKey.key";
  RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 48), 1u);
  v7 = (unsigned __int16 **)((char *)this + 888);
  if ( *((_QWORD *)this + 111) )
    goto LABEL_15;
  if ( !(unsigned int)GetTokenUserSid(*((void **)this + 94), Sid) || !ConvertSidToStringSidW(Sid, &StringSid) )
  {
    LastError = GetLastError();
    goto LABEL_16;
  }
  pcchLength = 0i64;
  if ( !StringSid || StringLengthWorkerW(StringSid, 0x7FFFFFFFui64, &pcchLength) < 0 )
    goto LABEL_14;
  v8 = (unsigned int)(2 * pcchLength + 156);
  v9 = (wchar_t *)LocalAlloc(0x40u, v8);
  v6 = v9;
  if ( !v9 )
  {
    LastError = 14;
    goto LABEL_16;
  }
  if ( v8 >> 1
    && StringCopyWorkerW(v9, v8 >> 1, v10, pszSrc, v13) >= 0
    && StringCbCatW(v6, v8, StringSid) >= 0
    && StringCbCatW(v6, v8, v16) >= 0
    && (int)CCredentialGroup::GetFileFullPath(v11, v6, v7) >= 0 )
  {
LABEL_15:
    *a2 = *v7;
  }
  else
  {
LABEL_14:
    LastError = 1359;
  }
LABEL_16:
  RtlReleaseResource(v5);
  if ( v6 )
    LocalFree(v6);
  if ( StringSid )
    LocalFree(StringSid);
  return LastError;
}
// 18005606C: variable 'v10' is possibly undefined
// 18005606C: variable 'v13' is possibly undefined
// 1800560A3: variable 'v11' is possibly undefined
// 180085560: using guessed type wchar_t aAllusersprofil[57];
// 1800855D8: using guessed type wchar_t aSessionticketk[22];

