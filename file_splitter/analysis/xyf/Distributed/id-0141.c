//----- (000000018000C160) ----------------------------------------------------
__int64 __fastcall SpUserQueryContextAttributes(__int64 a1, unsigned int a2, struct _SecPkgContext_TokenBinding *a3)
{
  struct CSslUserContext *UserContext; // rax
  struct CSslUserContext *v6; // rcx
  struct CSslUserContext *v7; // rbx
  unsigned int v9; // ecx
  __int64 v11; // rax

  UserContext = SslFindUserContext(a1);
  v7 = UserContext;
  if ( !UserContext )
    return 2148074241i64;
  if ( a2 > 0x24 )
  {
    if ( a2 > 0x6C )
    {
      switch ( a2 )
      {
        case 'm':
          return (unsigned int)SpQueryTokenBinding(UserContext, a3);
        case 'n':
          return (unsigned int)SpQueryConnectionInfoEx(UserContext, (struct _SecPkgContext_ConnectionInfoEx *)a3);
        case 'o':
          return (unsigned int)SpQueryTokenBindingEKM(UserContext, (struct _SecPkgContext_KeyingMaterial *)a3);
        case 'p':
          return (unsigned int)SpQueryKeyingMaterial(UserContext, (struct _SecPkgContext_KeyingMaterial_Inproc *)a3);
        case 'r':
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 19i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
          }
          return (unsigned int)SpQueryCertificateValidationResult(
                                 *((_QWORD *)v7 + 2),
                                 *((_DWORD *)v7 + 95),
                                 *((_DWORD *)v7 + 94),
                                 (struct _SecPkgContext_CertificateValidationResult *)a3);
      }
    }
    else
    {
      switch ( a2 )
      {
        case 'l':
          return (unsigned int)SpQuerySrtpParameters(UserContext, (struct _SecPkgContext_SrtpParameters *)a3);
        case 'Z':
          return (unsigned int)GetOldConnectionInfo(UserContext, (struct _SecPkgContext_ConnectionInfo *)a3);
        case 'S':
          return SpQueryRemoteCertContext(UserContext, (const CERT_CONTEXT **)a3);
        case ']':
          return (unsigned int)SpQuerySessionInfo(UserContext, (struct _SecPkgContext_SessionInfo *)a3);
        case 'Q':
          return SpQueryRemoteCred(UserContext, a3);
        case 'd':
          return (unsigned int)GetCipherInfo(UserContext, (struct _SecPkgContext_CipherInfo *)a3);
      }
    }
  }
  else
  {
    if ( a2 == 36 )
      return (unsigned int)SpQueryNegotiatedTlsExtensions(
                             UserContext,
                             (struct _SecPkgContext_NegotiatedTlsExtensions *)a3);
    if ( a2 > 7 )
    {
      switch ( a2 )
      {
        case 0xAu:
          return (unsigned int)SpQueryPackageInfo(v6, a3);
        case 0x12u:
          v11 = *((_QWORD *)UserContext + 33);
          if ( v11 )
          {
            *(_QWORD *)&a3->MajorVersion = v11;
            return 0;
          }
          else
          {
            v9 = -2146893045;
            if ( *((_DWORD *)v7 + 68) )
              return *((unsigned int *)v7 + 68);
          }
          return v9;
        case 0x19u:
          return (unsigned int)SpQueryUniqueBindings(UserContext, (struct _SecPkgContext_Bindings *)a3);
        case 0x1Au:
          return (unsigned int)SpQueryEndpointBindings(UserContext, (struct _SecPkgContext_Bindings *)a3);
        case 0x23u:
          return (unsigned int)SpQueryApplicationProtocol(UserContext, (struct _SecPkgContext_ApplicationProtocol *)a3);
      }
    }
    else
    {
      switch ( a2 )
      {
        case 7u:
          return (unsigned int)SpQueryProtoInfo(UserContext, a3);
        case 0u:
          return (unsigned int)SpQuerySizes(UserContext, (struct _SecPkgContext_Sizes *)a3);
        case 1u:
          return SpQueryNames(UserContext, (struct _SecPkgContext_NamesW *)a3);
        case 2u:
          return (unsigned int)SpQueryLifespan(UserContext, (struct _SecPkgContext_Lifespan *)a3);
        case 4u:
          return (unsigned int)SpQueryStreamSizes(UserContext, (struct _SecPkgContext_StreamSizes *)a3);
        case 5u:
          return (unsigned int)SpQueryKeyInfo(UserContext, a3);
      }
    }
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x14u, (__int64)&WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids, a2);
  return 2148074242i64;
}
// 1800363C3: variable 'v6' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

