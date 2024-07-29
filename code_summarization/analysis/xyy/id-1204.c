//----- (000000018005F83C) ----------------------------------------------------
ULONG __fastcall CSslCredential::GetLocalServerKeyFromProvider(const struct _CERT_CONTEXT **this, __int64 a2)
{
  __int64 v3; // rsi
  ULONG result; // eax
  CCipherMill *v5; // rcx
  int PrivateKeyFromProvider; // edi
  unsigned int v7; // ebp
  const struct _CERT_CONTEXT *v8; // rax
  struct ProviderToPrivateKey *v9; // r14
  _QWORD *v10; // rax
  _QWORD *v11; // r9
  __int64 v12; // r8
  unsigned __int64 *v13; // rbx
  CCipherMill *v14; // rcx
  struct ProviderToPrivateKey *v15; // [rsp+20h] [rbp-28h] BYREF
  int v16; // [rsp+60h] [rbp+18h] BYREF
  unsigned int v17; // [rsp+68h] [rbp+20h] BYREF

  v16 = 0;
  v15 = 0i64;
  v17 = 0;
  v3 = 0i64;
  result = SslImpersonateClient(a2, &v16);
  if ( result )
    return result;
  PrivateKeyFromProvider = CCipherMill::GetPrivateKeyFromProvider(v5, this[4], &v15, &v17);
  if ( v16 )
    RevertToSelf();
  if ( PrivateKeyFromProvider )
  {
    *((_DWORD *)this + 18) = 10001;
    return -2146893043;
  }
  v7 = v17;
  v8 = (const struct _CERT_CONTEXT *)SPExternalAlloc(8 * v17);
  v9 = v15;
  this[11] = v8;
  if ( v8 )
  {
    if ( v7 )
    {
      while ( 1 )
      {
        v10 = SPExternalAlloc(0x20u);
        v11 = v10;
        if ( v10 )
        {
          v12 = *((_QWORD *)v9 + 2 * (unsigned int)v3);
          v10[1] = *((_QWORD *)v9 + 2 * (unsigned int)v3 + 1);
          v10[2] = v12;
          *v10 = &CSslServerKey::`vftable';
          *((_DWORD *)v10 + 6) = 1;
        }
        else
        {
          v11 = 0i64;
        }
        *((_QWORD *)&this[11]->dwCertEncodingType + v3) = v11;
        if ( !*((_QWORD *)&this[11]->dwCertEncodingType + v3) )
          break;
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= v7 )
          goto LABEL_16;
      }
      PrivateKeyFromProvider = 14;
    }
LABEL_16:
    *((_DWORD *)this + 24) = v3;
    if ( !PrivateKeyFromProvider )
      goto LABEL_20;
  }
  else
  {
    PrivateKeyFromProvider = 14;
  }
  while ( v7 > (unsigned int)v3 )
  {
    v13 = (unsigned __int64 *)((char *)v9 + 16 * --v7);
    SslFreeObject(v13[1], 0i64);
    CCipherMill::DeferenceProvider(v14, v13);
  }
LABEL_20:
  if ( v9 )
    SPExternalFree(v9);
  return PrivateKeyFromProvider;
}
// 18005F888: variable 'v5' is possibly undefined
// 18005F96C: variable 'v14' is possibly undefined
// 18007D568: using guessed type void *CSslServerKey::`vftable';
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

