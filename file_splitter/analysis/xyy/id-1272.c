//----- (00000001800648C8) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeFinishedSize(__int64 a1, __int64 a2)
{
  __int64 v3; // rcx
  struct hsel *HashInfo; // rax
  __int64 v5; // r8
  _WORD *v6; // r9
  __int16 v7; // ax

  if ( !a2 )
    return 87i64;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8i64);
  if ( !v3 )
    return 1359i64;
  HashInfo = GetHashInfo(*(_DWORD *)(v3 + 44));
  if ( !HashInfo || *((_DWORD *)HashInfo + 7) > 0x40u )
    return 1359i64;
  v7 = *((unsigned __int8 *)HashInfo + 28);
  *(_BYTE *)(v5 + 81) = v7;
  v7 += 4;
  *(_WORD *)(v5 + 82) = v7;
  *v6 = v7;
  return 0i64;
}
// 180064900: variable 'v5' is possibly undefined
// 18006490D: variable 'v6' is possibly undefined

