//----- (000000018006CD58) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::GeneratePostHandshakeCertificateRequest(
        CTls13ServerContext *this,
        struct SPBuffer *a2)
{
  unsigned int CertificateRequestContext; // edi
  int v5; // edx
  CTls13ServerContext *v6; // rcx
  __int64 result; // rax
  __int64 v8; // rcx
  unsigned int v9; // [rsp+30h] [rbp-38h] BYREF
  unsigned __int16 v10[2]; // [rsp+38h] [rbp-30h] BYREF
  int v11; // [rsp+3Ch] [rbp-2Ch]
  int v12; // [rsp+40h] [rbp-28h]

  v11 = 22;
  v10[0] = 0;
  v12 = 3;
  if ( !*((_BYTE *)this + 1506)
    || !*((_BYTE *)this + 1233)
    || *(_DWORD *)(*((_QWORD *)this + 1) + 48i64) == 4
    || (*((_DWORD *)this + 34) & 0x100i64) == 0 )
  {
    return 2148074333i64;
  }
  CertificateRequestContext = CTls13ServerContext::GenerateCertificateRequestContext(this);
  if ( CertificateRequestContext )
  {
    v5 = 1259;
LABEL_7:
    v6 = this;
LABEL_8:
    CSslContext::SetError((__int64)v6, v5, CertificateRequestContext);
    return CertificateRequestContext;
  }
  CertificateRequestContext = CTls13ServerHandshake::ComputeCertificateRequestSize(
                                (CTls13ServerContext *)((char *)this + 1288),
                                v10);
  if ( CertificateRequestContext )
  {
    v5 = 1260;
    goto LABEL_7;
  }
  v8 = *((_QWORD *)this + 151);
  v9 = 0;
  CertificateRequestContext = (*(__int64 (__fastcall **)(__int64, __int64, unsigned __int16 *, unsigned int *))(*(_QWORD *)v8 + 16i64))(
                                v8,
                                1i64,
                                v10,
                                &v9);
  v6 = this;
  if ( CertificateRequestContext )
  {
    v5 = 1261;
    goto LABEL_8;
  }
  CertificateRequestContext = CSsl3TlsContext::AllocateOutputBuffer(this, a2, v9);
  if ( CertificateRequestContext
    || (CertificateRequestContext = (*(__int64 (__fastcall **)(_QWORD, struct SPBuffer *))(**((_QWORD **)this + 151)
                                                                                         + 24i64))(
                                      *((_QWORD *)this + 151),
                                      a2)) != 0
    || (result = CTls13ServerHandshake::GenerateCertificateRequest((CTls13ServerContext *)((char *)this + 1288)),
        (CertificateRequestContext = result) != 0) )
  {
    v5 = 1262;
    goto LABEL_7;
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
