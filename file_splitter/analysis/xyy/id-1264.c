//----- (00000001800640C4) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeCertificateMsgSize(
        __int64 a1,
        __int64 a2,
        char a3,
        _WORD *a4)
{
  int v4; // edi
  __int64 result; // rax
  __int64 v8; // rax
  unsigned int v9; // ecx

  v4 = 0;
  if ( (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 64i64) & 0x40051555) != 0 && !a2 || !a4 )
    return 87i64;
  *(_QWORD *)(a1 + 72) = a2;
  *(_BYTE *)(a1 + 80) = a3;
  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeCertificateListSize(a1);
  if ( !(_DWORD)result )
  {
    v8 = *(_QWORD *)(a1 + 8);
    if ( (*(_DWORD *)(v8 + 64) & 0x40051555) == 0 )
      v4 = *(unsigned __int8 *)(v8 + 1232);
    v9 = v4 + *(unsigned __int16 *)(a1 + 64) + 8;
    if ( v9 <= 0xFFFF )
    {
      *(_WORD *)(a1 + 136) = v9;
      result = 0i64;
      *a4 = v9;
    }
    else
    {
      return 1359i64;
    }
  }
  return result;
}
