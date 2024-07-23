// File count: 1041
// Total lines: 24
----------------------------------------
DWORD __fastcall CCredentialGroup::SubscribeCertStoreChangeNotification(CCredentialGroup *this, void *a2, void **a3)
{
  DWORD LastError; // ebx
  HANDLE pvCtrlPara; // [rsp+30h] [rbp+8h] BYREF

  pvCtrlPara = this;
  if ( !a2 || !a3 )
    return 87;
  pvCtrlPara = CreateEventA(0i64, 0, 0, 0i64);
  if ( !pvCtrlPara )
    return GetLastError();
  if ( CertControlStore(a2, 0, 2u, &pvCtrlPara) )
  {
    *a3 = pvCtrlPara;
    return 0;
  }
  else
  {
    LastError = GetLastError();
    CloseHandle(pvCtrlPara);
    return LastError;
  }
}
