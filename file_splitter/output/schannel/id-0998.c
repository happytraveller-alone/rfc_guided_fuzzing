//----- (0000000180053588) ----------------------------------------------------
__int64 __fastcall IsThreadLocalSystemOrNetworkService(unsigned __int8 *a1)
{
  DWORD LastError; // ebx
  HANDLE CurrentThread; // rax
  CCipherMill *v4; // rcx
  __int64 v5; // rdx
  DWORD cbSid; // [rsp+20h] [rbp-69h] BYREF
  void *TokenHandle; // [rsp+28h] [rbp-61h] BYREF
  char pSid[80]; // [rsp+30h] [rbp-59h] BYREF
  unsigned __int8 pSid2[80]; // [rsp+80h] [rbp-9h] BYREF

  TokenHandle = 0i64;
  LastError = 0;
  *a1 = 0;
  cbSid = 68;
  CurrentThread = GetCurrentThread();
  if ( !OpenThreadToken(CurrentThread, 8u, 1, &TokenHandle)
    || !(unsigned int)GetTokenUserSid(TokenHandle, pSid2)
    || !CreateWellKnownSid(WinLocalSystemSid, 0i64, pSid, &cbSid) )
  {
    goto LABEL_2;
  }
  if ( EqualSid(pSid, pSid2) )
  {
    v4 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      goto LABEL_15;
    v5 = 10i64;
    goto LABEL_14;
  }
  cbSid = 68;
  if ( !CreateWellKnownSid(WinNetworkServiceSid, 0i64, pSid, &cbSid) )
  {
LABEL_2:
    LastError = GetLastError();
    goto LABEL_16;
  }
  if ( !EqualSid(pSid, pSid2) )
    goto LABEL_16;
  v4 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v5 = 11i64;
LABEL_14:
    WPP_SF_(*((_QWORD *)v4 + 2), v5, &WPP_515891eeb9b1375e41800a5e1897fca1_Traceguids);
  }
LABEL_15:
  *a1 = 1;
LABEL_16:
  if ( TokenHandle )
    CloseHandle(TokenHandle);
  return LastError;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

