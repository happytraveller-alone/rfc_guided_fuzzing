//----- (0000000180008600) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::InitHandshakeHash(CSsl3TlsContext *this, char a2)
{
  __int64 *v2; // rax
  __int64 v5; // r14
  unsigned int v6; // r15d
  unsigned int v7; // ebp
  unsigned int i; // edi
  __int64 result; // rax
  unsigned int v10; // edi
  unsigned int CipherSuitePRFHashAlgorithm; // r13d
  int v12; // r8d
  unsigned int v13; // esi
  char *v14; // r12
  __int64 v15; // rcx
  unsigned int v16[4]; // [rsp+30h] [rbp-148h] BYREF
  unsigned __int16 *v17[16]; // [rsp+40h] [rbp-138h] BYREF
  unsigned __int16 v18[64]; // [rsp+C0h] [rbp-B8h] BYREF

  v2 = (__int64 *)*((_QWORD *)this + 1);
  if ( v2 )
    v5 = *v2;
  else
    v5 = 0i64;
  v6 = *((unsigned __int16 *)this + 17);
  if ( (*((_BYTE *)this + 32) & 1) != 0 && v2 )
    v7 = *((_DWORD *)v2 + 7);
  else
    v7 = 0;
  for ( i = 0; i < *((_DWORD *)this + 137); ++i )
  {
    v14 = (char *)this + 8 * i;
    v15 = *((_QWORD *)v14 + 74);
    if ( v15 )
    {
      SslFreeObject(v15, 0i64);
      *((_QWORD *)v14 + 74) = 0i64;
    }
  }
  *((_DWORD *)this + 180) = 0;
  *((_DWORD *)this + 137) = 0;
  result = SslCreateHandshakeHash(v5, (char *)this + 592, v6, v7, 0);
  if ( !(_DWORD)result )
  {
    v10 = 1;
    *((_DWORD *)this + 137) = 1;
    if ( !a2 )
      return 0i64;
    v16[0] = 0;
    CipherSuitePRFHashAlgorithm = SslGetCipherSuitePRFHashAlgorithm(v5, v6, v7, 0i64, v18, 0);
    if ( !CipherSuitePRFHashAlgorithm )
    {
      v12 = *((_DWORD *)this + 16);
      v18[63] = 0;
      CipherSuitePRFHashAlgorithm = CTlsSignatureSuiteList::GetRunningHashList(
                                      (CSsl3TlsContext *)((char *)this + 474),
                                      v18,
                                      v12,
                                      (enum _eTlsHashAlgorithm *const)this + 180,
                                      v17,
                                      v16);
      if ( !CipherSuitePRFHashAlgorithm )
      {
        v13 = v16[0];
        if ( v16[0] <= 1 )
          return 0i64;
        while ( 1 )
        {
          CipherSuitePRFHashAlgorithm = SslCreateClientAuthHash(v5, (char *)this + 8 * v10 + 592, v6, v7, v17[v10], 0);
          if ( CipherSuitePRFHashAlgorithm )
            break;
          *((_DWORD *)this + 137) = ++v10;
          if ( v10 >= v13 )
            return 0i64;
        }
      }
    }
    CSsl3TlsContext::FreeHandshakeHash(this);
    return CipherSuitePRFHashAlgorithm;
  }
  return result;
}
// 180098430: using guessed type __int64 __fastcall SslCreateClientAuthHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098438: using guessed type __int64 __fastcall SslGetCipherSuitePRFHashAlgorithm(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098440: using guessed type __int64 __fastcall SslCreateHandshakeHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 180008600: using guessed type unsigned int var_148[4];

