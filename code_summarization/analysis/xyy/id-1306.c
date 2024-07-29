//----- (0000000180067044) ----------------------------------------------------
unsigned int __fastcall CTls13ServerHandshake::GenerateEncryptedExtensionsMsg(CTls13ServerHandshake *this)
{
  unsigned int result; // eax

  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(
             (__int64)this,
             8,
             *((_WORD *)this + 81));
  if ( !result )
  {
    result = CTls13ServerHandshake::GenerateEncryptedExtensions(this);
    if ( !result )
      return (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 4) + 40i64))(*((_QWORD *)this + 4));
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

