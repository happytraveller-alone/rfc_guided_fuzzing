//----- (0000000180014734) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::GetTBParametersSize(struct _SEC_TOKEN_BINDING *const a1)
{
  __int64 KeyParametersSize; // rax
  unsigned int v2; // ecx
  unsigned __int64 v3; // rax

  if ( !a1 )
    return 0i64;
  KeyParametersSize = a1->KeyParametersSize;
  v2 = 6;
  v3 = KeyParametersSize + 4;
  if ( v3 > 6 )
    return (unsigned int)v3;
  return v2;
}

