//----- (0000000180066DB8) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::GenerateClientHelloExtensions(CTls13ClientHandshake *this)
{
  __int16 v1; // ax
  __int64 v3; // rcx
  __int64 result; // rax
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  v1 = *((_WORD *)this + 20);
  v3 = *((_QWORD *)this + 4);
  v5 = __ROR2__(v1, 8);
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 32i64))(v3, 2i64, &v5);
  if ( !(_DWORD)result )
  {
    result = CTls13ClientHandshake::GenerateServerNameExtension(this);
    if ( !(_DWORD)result )
    {
      result = (*(__int64 (__fastcall **)(CTls13ClientHandshake *))(*(_QWORD *)this + 8i64))(this);
      if ( !(_DWORD)result )
      {
        result = CTls13ClientHandshake::GenerateSupportedVersionsExtension(this);
        if ( !(_DWORD)result )
        {
          result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateSignatureAlgorithmsExtension((__int64)this);
          if ( !(_DWORD)result )
          {
            result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader((__int64)this, 35, 0);
            if ( !(_DWORD)result )
            {
              result = CTls13ClientHandshake::GenerateSupportedGroupsExtension(this);
              if ( !(_DWORD)result )
              {
                result = CTls13ClientHandshake::GenerateALPNExtension(this);
                if ( !(_DWORD)result )
                {
                  result = CTls13ClientHandshake::GenerateKeyShareExtension(this);
                  if ( !(_DWORD)result )
                  {
                    result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
                               (__int64)this,
                               49,
                               0);
                    if ( !(_DWORD)result )
                    {
                      if ( !*(_BYTE *)(*((_QWORD *)this + 1) + 1344i64)
                        || (result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader(
                                       (__int64)this,
                                       23,
                                       0),
                            !(_DWORD)result) )
                      {
                        result = CTls13ClientHandshake::GenerateRenegotiationInfoExtension(this);
                        if ( !(_DWORD)result )
                        {
                          result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateCookieExtension((__int64)this);
                          if ( !(_DWORD)result )
                          {
                            result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateGenericExtensions(
                                       (__int64)this,
                                       1);
                            if ( !(_DWORD)result )
                            {
                              result = CTls13ClientHandshake::GeneratePskKeyExchangeModesExtension(this);
                              if ( !(_DWORD)result )
                                return CTls13ClientHandshake::GeneratePskExtension(this);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

