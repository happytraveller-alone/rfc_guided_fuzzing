// File count: 1259
// Total lines: 37
----------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateEntrySize(
        __int64 a1,
        __int64 a2,
        char a3,
        _WORD *a4)
{
  __int16 v4; // bx
  unsigned __int16 v7; // si
  __int64 result; // rax

  v4 = 0;
  if ( !a4 )
    return 87i64;
  v7 = 0;
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 16) > 0xFFFAu )
      return 87i64;
    v7 = *(_WORD *)(a2 + 16);
  }
  if ( !a3 )
  {
LABEL_9:
    *a4 = v7 + v4 + 5;
    return 0i64;
  }
  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateEntryExtensionsSize(a1);
  if ( (_DWORD)result )
    return result;
  if ( 65530 - v7 >= *(unsigned __int16 *)(a1 + 154) )
  {
    v4 = *(_WORD *)(a1 + 154);
    goto LABEL_9;
  }
  return 87i64;
}
