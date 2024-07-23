// File count: 1288
// Total lines: 141
---------------------------------------
int __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCertVerifyContentHash(
        __int64 a1,
        char a2,
        enum _eTlsHashAlgorithm a3,
        const wchar_t *a4,
        PUCHAR pbInput,
        ULONG cbOutput,
        ULONG *a7)
{
  unsigned __int8 v10; // al
  ULONG *v11; // rdi
  PUCHAR v12; // rsi
  ULONG v13; // r15d
  ULONG v14; // ecx
  __int64 v15; // rbx
  unsigned __int16 *v16; // rcx
  unsigned int v17; // ebx
  __int64 v18; // rax
  __int64 *v19; // rcx
  __int64 v20; // rcx
  int result; // eax
  ULONG v22; // r14d
  UCHAR *v23; // rax
  UCHAR *v24; // r15
  NTSTATUS v25; // ebx
  UCHAR *v26; // rdx
  ULONG cbInput; // [rsp+40h] [rbp-20h] BYREF
  ULONG pcbResult; // [rsp+44h] [rbp-1Ch] BYREF
  BCRYPT_HASH_HANDLE phHash; // [rsp+48h] [rbp-18h] BYREF
  BCRYPT_HANDLE hObject; // [rsp+50h] [rbp-10h] BYREF
  unsigned int pbOutput; // [rsp+B8h] [rbp+58h] BYREF

  if ( a4 )
  {
    v10 = wcsnlen(a4, 0x40ui64);
    if ( v10 >= 0x40u )
      return 87;
  }
  else
  {
    v10 = 0;
  }
  v11 = a7;
  if ( !a7 )
    return 87;
  if ( v10 )
    v10 = 2 * (v10 + 1);
  v12 = pbInput;
  v13 = v10;
  v14 = v10 + 64;
  *a7 = v14;
  if ( !v12 || cbOutput < v14 )
    return 122;
  *v11 = 0;
  if ( a4 )
  {
    v15 = v10;
    memcpy_0(v12, a4, v10);
    v12 += v15;
    *v11 = v13;
  }
  v16 = *(unsigned __int16 **)(a1 + 8);
  cbInput = 0;
  v17 = v16[17];
  v18 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD))(*(_QWORD *)v16 + 512i64))(v16, 0i64);
  v19 = *(__int64 **)(*(_QWORD *)(a1 + 8) + 8i64);
  if ( v19 )
    v20 = *v19;
  else
    v20 = 0i64;
  result = SslComputeSessionHash(v20, v18, v17, v12, 64, &cbInput, 0);
  if ( !result )
  {
    hObject = 0i64;
    result = TlsGetBCryptHashProvider(a3, &hObject, &cbOutput);
    if ( !result )
    {
      v22 = cbOutput;
      if ( cbOutput <= 0x40 )
      {
        pbOutput = 0;
        pcbResult = 0;
        result = BCryptGetProperty(hObject, L"ObjectLength", (PUCHAR)&pbOutput, 4u, &pcbResult, 0);
        if ( !result )
        {
          v23 = (UCHAR *)SPExternalAlloc(pbOutput);
          v24 = v23;
          if ( v23 )
          {
            phHash = 0i64;
            v25 = BCryptCreateHash(hObject, &phHash, v23, pbOutput, 0i64, 0, 0);
            if ( !v25 )
            {
              v25 = BCryptHashData(
                      phHash,
                      (PUCHAR)"                                                                TLS 1.3, ",
                      0x49u,
                      0);
              if ( !v25 )
              {
                v26 = (UCHAR *)"server";
                if ( !a2 )
                  v26 = (UCHAR *)"client";
                v25 = BCryptHashData(phHash, v26, 6u, 0);
                if ( !v25 )
                {
                  v25 = BCryptHashData(phHash, (PUCHAR)" CertificateVerify", 0x13u, 0);
                  if ( !v25 )
                  {
                    v25 = BCryptHashData(phHash, v12, cbInput, 0);
                    if ( !v25 )
                    {
                      v25 = BCryptFinishHash(phHash, v12, v22, 0);
                      if ( !v25 )
                        *v11 += v22;
                    }
                  }
                }
              }
            }
            if ( phHash )
              BCryptDestroyHash(phHash);
            SPExternalFree(v24);
            return v25;
          }
          else
          {
            return 14;
          }
        }
      }
      else
      {
        return 1359;
      }
    }
  }
  return result;
}
// 180098530: using guessed type __int64 __fastcall SslComputeSessionHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
