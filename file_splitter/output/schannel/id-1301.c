// File count: 1301
// Total lines: 56
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateCertificateVerify(__int64 a1)
{
  unsigned int CertVerifySignature; // edi
  __int64 v3; // rcx
  void *v4; // rcx
  __int16 v6; // [rsp+30h] [rbp+8h] BYREF

  CertVerifySignature = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateCertVerifySignature(a1);
  if ( !CertVerifySignature )
  {
    CertVerifySignature = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(
                            a1,
                            15,
                            *(_WORD *)(a1 + 138));
    if ( !CertVerifySignature )
    {
      if ( *(_WORD *)(a1 + 120) )
      {
        CertVerifySignature = (*(__int64 (__fastcall **)(_QWORD, __int64))(**(_QWORD **)(a1 + 32) + 32i64))(
                                *(_QWORD *)(a1 + 32),
                                2i64);
        if ( !CertVerifySignature )
        {
          v3 = *(_QWORD *)(a1 + 32);
          v6 = __ROR2__(*(_WORD *)(a1 + 142), 8);
          CertVerifySignature = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(
                                  v3,
                                  2i64,
                                  &v6);
          if ( !CertVerifySignature )
          {
            CertVerifySignature = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(a1 + 32) + 32i64))(
                                    *(_QWORD *)(a1 + 32),
                                    *(unsigned __int16 *)(a1 + 142),
                                    *(_QWORD *)(a1 + 144));
            if ( !CertVerifySignature )
              CertVerifySignature = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(a1 + 32) + 40i64))(*(_QWORD *)(a1 + 32));
          }
        }
      }
      else
      {
        CertVerifySignature = 1359;
      }
    }
  }
  v4 = *(void **)(a1 + 144);
  if ( v4 )
  {
    SPExternalFree(v4);
    *(_QWORD *)(a1 + 144) = 0i64;
  }
  return CertVerifySignature;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
