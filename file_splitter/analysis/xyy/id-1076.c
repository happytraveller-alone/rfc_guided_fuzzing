//----- (0000000180059ED0) ----------------------------------------------------
__int64 __fastcall CCipherMill::GetPrivateKeyFromProvider(
        CCipherMill *this,
        const struct _CERT_CONTEXT *a2,
        struct ProviderToPrivateKey **a3,
        unsigned int *a4)
{
  unsigned int *v5; // r13
  unsigned int v7; // ebp
  __int64 v8; // rsi
  CCipherMill *v9; // rcx
  struct ProviderToPrivateKey *v10; // r14
  __int64 v11; // r15
  unsigned __int64 *v12; // rbx
  __int64 v13; // rax
  __int64 v16[32]; // [rsp+30h] [rbp-148h] BYREF

  v5 = a4;
  v7 = 1168;
  RtlAcquireResourceShared(&Resource, 1u);
  v8 = 0i64;
  if ( qword_180092498 )
  {
    while ( 1 )
    {
      v7 = SslOpenPrivateKey(*(_QWORD *)&g_cCipherMill[8 * v8 + 128], &v16[v8], a2, 64i64);
      if ( v7 )
        break;
      v8 = (unsigned int)(v8 + 1);
      if ( (unsigned int)v8 >= qword_180092498 )
      {
        v10 = (struct ProviderToPrivateKey *)SPExternalAlloc(16 * qword_180092498);
        if ( v10 )
        {
          v11 = 0i64;
          if ( qword_180092498 )
          {
            do
            {
              v12 = (unsigned __int64 *)((char *)v10 + 16 * (unsigned int)v11);
              CCipherMill::ReferenceProvider(v9, *(_QWORD *)&g_cCipherMill[8 * v11 + 128], v12);
              v13 = v16[v11];
              v11 = (unsigned int)(v11 + 1);
              v12[1] = v13;
            }
            while ( (unsigned int)v11 < qword_180092498 );
            v5 = a4;
          }
          *a3 = v10;
          *v5 = qword_180092498;
        }
        else
        {
          v7 = 14;
        }
        break;
      }
    }
  }
  RtlReleaseResource(&Resource);
  if ( v7 )
  {
    while ( (_DWORD)v8 )
    {
      v8 = (unsigned int)(v8 - 1);
      SslFreeObject(v16[v8], 0i64);
    }
  }
  return v7;
}
// 180059FB9: variable 'v9' is possibly undefined
// 180098448: using guessed type __int64 __fastcall SslOpenPrivateKey(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 180059ED0: using guessed type __int64 var_148[32];

