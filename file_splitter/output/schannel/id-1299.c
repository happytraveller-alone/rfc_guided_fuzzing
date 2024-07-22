//----- (0000000180066854) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::GenerateCertificateRequest(CTls13ServerHandshake *this)
{
  __int64 result; // rax
  unsigned __int8 v3; // [rsp+30h] [rbp+8h] BYREF

  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(
             (__int64)this,
             13,
             *((_WORD *)this + 85));
  if ( !(_DWORD)result )
  {
    v3 = *(_BYTE *)(*((_QWORD *)this + 1) + 1232i64);
    result = (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned __int8 *))(**((_QWORD **)this + 4) + 32i64))(
               *((_QWORD *)this + 4),
               1i64,
               &v3);
    if ( !(_DWORD)result )
    {
      if ( !v3
        || (result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**((_QWORD **)this + 4) + 32i64))(
                       *((_QWORD *)this + 4),
                       v3,
                       *(_QWORD *)(*((_QWORD *)this + 1) + 1224i64)),
            !(_DWORD)result) )
      {
        result = CTls13ServerHandshake::GenerateCertificateRequestExtensions(this);
        if ( !(_DWORD)result )
          return (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 4) + 40i64))(*((_QWORD *)this + 4));
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

