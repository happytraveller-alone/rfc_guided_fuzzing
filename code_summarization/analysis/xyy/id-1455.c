//----- (0000000180074430) ----------------------------------------------------
__int64 __fastcall SslMapCredential(
        struct CCredentialGroup *a1,
        void *a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        struct _CERT_CONTEXT *a6,
        const struct _CERT_CONTEXT *a7,
        unsigned __int16 *a8,
        unsigned __int16 *a9,
        unsigned __int64 *a10)
{
  int v10; // eax
  void *v12; // [rsp+30h] [rbp-28h]

  if ( fUseLocalMapping )
    v10 = SslLocalMapCredential(a1, 0i64, 1, a4, a5, a6, 0i64, a8, a9, a10);
  else
    v10 = SslRemoteMapCredential(a1, a2, 1, a4, a5, a6, v12, a8, a9, a10);
  return I_MapWinTrustErrorAndAlert(v10, -2146893045, 0, 0i64);
}
// 18007449F: variable 'v12' is possibly undefined
// 1800919A0: using guessed type int fUseLocalMapping;

