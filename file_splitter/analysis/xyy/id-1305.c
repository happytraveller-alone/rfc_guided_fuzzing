//----- (0000000180066FBC) ----------------------------------------------------
unsigned int __fastcall CTls13ServerHandshake::GenerateEncryptedExtensions(CTls13ServerHandshake *this)
{
  __int16 v1; // ax
  __int64 v3; // rcx
  unsigned int result; // eax
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  v1 = *((_WORD *)this + 82);
  v3 = *((_QWORD *)this + 4);
  v5 = __ROR2__(v1, 8);
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v5);
  if ( !result
    && ((*(_DWORD *)(*((_QWORD *)this + 1) + 136i64) & 0x200000) == 0
     || (result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(this, 0i64, 0i64)) == 0) )
  {
    result = CTls13ServerHandshake::GenerateSelectedALPNExtension(this);
    if ( !result )
      return CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateGenericExtensions(this, 8i64);
  }
  return result;
}
// 180067098: using guessed type __int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(_QWORD, _QWORD, _QWORD);
// 1800674C0: using guessed type __int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateGenericExtensions(_QWORD, _QWORD);
