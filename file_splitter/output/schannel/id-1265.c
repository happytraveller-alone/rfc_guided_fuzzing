// File count: 1265
// Total lines: 40
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeCertificateRequestExtensionsSize(CTls13ServerHandshake *this)
{
  __int16 v2; // cx
  unsigned __int16 v3; // cx
  unsigned int v4; // edi
  __int64 result; // rax
  int v6; // eax
  int v7; // ecx

  *((_WORD *)this + 84) = 0;
  v2 = *((_WORD *)this + 63);
  if ( (unsigned __int16)(v2 - 1) > 0xFu )
    return 1359i64;
  v3 = 2 * (v2 + 1);
  *((_WORD *)this + 62) = v3;
  v4 = v3 + 4;
  if ( !g_fSendIssuerList
    || !*((_QWORD *)this + 22)
    || !*((_WORD *)this + 92)
    || (result = CTls13ServerHandshake::ComputeCertificateAuthoritiesExtensionSize(this), !(_DWORD)result) )
  {
    v6 = *((unsigned __int16 *)this + 93);
    if ( (_WORD)v6 )
      v4 += v6 + 4;
    result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeGenericExtensionsSize((__int64)this, 13);
    if ( !(_DWORD)result )
    {
      v7 = *((unsigned __int16 *)this + 61);
      if ( 0xFFFF - v7 >= v4 )
      {
        *((_WORD *)this + 84) = v4 + v7;
        return 0i64;
      }
      return 1359i64;
    }
  }
  return result;
}
// 180092F08: using guessed type int g_fSendIssuerList;
