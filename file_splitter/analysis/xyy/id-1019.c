//----- (0000000180055288) ----------------------------------------------------
DWORD __fastcall CCredentialGroup::CheckCertStoreChangeNotification(CCredentialGroup *this, void *a2, void *a3)
{
  DWORD v5; // eax
  void *pvCtrlPara; // [rsp+40h] [rbp+18h] BYREF

  pvCtrlPara = a3;
  if ( !a2 || !a3 )
    return 87;
  v5 = WaitForSingleObjectEx(a3, 0, 0);
  if ( v5 != -1 && (v5 || (*((_DWORD *)this + 39) |= 0x10u, CertControlStore(a2, 0, 1u, &pvCtrlPara))) )
    return 0;
  else
    return GetLastError();
}
