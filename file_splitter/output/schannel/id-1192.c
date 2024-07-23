// File count: 1192
// Total lines: 27
----------------------------------------
void TlsCloseBCryptHashProviders(void)
{
  int v0; // eax
  int v1; // edi
  BCRYPT_ALG_HANDLE *v2; // rbx

  v0 = g_dwHashInfoTotalCount;
  v1 = 1;
  if ( g_dwHashInfoTotalCount > 1 )
  {
    v2 = (BCRYPT_ALG_HANDLE *)&unk_180092CF8;
    do
    {
      if ( *v2 )
      {
        BCryptCloseAlgorithmProvider(*v2, 0);
        *v2 = 0i64;
        v0 = g_dwHashInfoTotalCount;
      }
      ++v1;
      ++v2;
    }
    while ( v1 < v0 );
  }
}
// 180092324: using guessed type int g_dwHashInfoTotalCount;
