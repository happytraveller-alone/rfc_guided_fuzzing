// File count: 1267
// Total lines: 40
----------------------------------------
int __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateVerifySize(
        __int64 a1,
        _WORD *a2)
{
  int result; // eax
  __int64 v5; // rax
  unsigned int v6; // eax

  if ( !a2 )
    return 87;
  v5 = *(_QWORD *)(a1 + 72);
  if ( *(_BYTE *)(v5 + 78) && !*(_BYTE *)(v5 + 79)
    || (result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::DetermineCertVerifyCodePoint(a1)) == 0 )
  {
    if ( *(_DWORD *)(a1 + 104) && *(_WORD *)(a1 + 120) && *(_DWORD *)(a1 + 100) && *(_QWORD *)(a1 + 112) )
    {
      result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertVerifySignatureSize(a1);
      if ( !result )
      {
        v6 = *(unsigned __int16 *)(a1 + 142) + 8;
        if ( v6 <= 0xFFFF )
        {
          *(_WORD *)(a1 + 138) = v6;
          *a2 = v6;
          return 0;
        }
        else
        {
          return 1359;
        }
      }
    }
    else
    {
      return -2146893052;
    }
  }
  return result;
}
