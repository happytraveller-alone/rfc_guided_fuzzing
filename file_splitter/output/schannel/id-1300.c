// File count: 1300
// Total lines: 32
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::GenerateCertificateRequestExtensions(CTls13ServerHandshake *this)
{
  __int16 v1; // ax
  __int64 v3; // rcx
  __int64 result; // rax
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  v1 = *((_WORD *)this + 84);
  v3 = *((_QWORD *)this + 4);
  v5 = __ROR2__(v1, 8);
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v5);
  if ( !(_DWORD)result )
  {
    result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateSignatureAlgorithmsExtension((__int64)this);
    if ( !(_DWORD)result )
    {
      if ( !g_fSendIssuerList )
        return CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateGenericExtensions((__int64)this, 13);
      if ( !*((_QWORD *)this + 22) )
        return CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateGenericExtensions((__int64)this, 13);
      if ( !*((_WORD *)this + 92) )
        return CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateGenericExtensions((__int64)this, 13);
      result = CTls13ServerHandshake::GenerateCertificateAuthoritiesExtension(this);
      if ( !(_DWORD)result )
        return CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateGenericExtensions((__int64)this, 13);
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092F08: using guessed type int g_fSendIssuerList;
