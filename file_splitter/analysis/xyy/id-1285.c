//----- (0000000180065360) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::DetermineCertVerifySignatureAlgorithm(
        __int64 a1,
        const struct _CERT_CONTEXT *a2)
{
  __int64 result; // rax
  int v4; // eax
  unsigned int v5; // [rsp+38h] [rbp+10h] BYREF

  if ( !a2 )
    return 87i64;
  v5 = 0;
  result = GetPublicKeyAlgIdFromCert(a2, &v5);
  if ( !(_DWORD)result )
  {
    if ( v5 == 8707 )
    {
      v4 = 3;
    }
    else
    {
      if ( v5 != 41984 )
        return 1359i64;
      v4 = 1;
    }
    *(_DWORD *)(a1 + 104) = v4;
    return 0i64;
  }
  return result;
}

