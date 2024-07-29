//----- (00000001800570B0) ----------------------------------------------------
void __fastcall CCredentialGroup::UnsubscribeCertStoreChangeNotification(CCredentialGroup *this, void *a2, void **a3)
{
  if ( a2 && a3 )
  {
    if ( *a3 )
    {
      CertControlStore(a2, 0, 5u, a3);
      CloseHandle(*a3);
      *a3 = 0i64;
    }
  }
}

