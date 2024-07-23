//----- (0000000180063B24) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeCertificateEntryExtensionsSize(
        __int64 a1)
{
  __int64 result; // rax
  __int64 v3; // rcx
  unsigned int v4; // edi
  int v5; // eax

  result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeGenericExtensionsSize(a1, 11);
  if ( !(_DWORD)result )
  {
    v4 = *(unsigned __int16 *)(v3 + 122);
    if ( (*(_DWORD *)(*(_QWORD *)(v3 + 8) + 64i64) & 0x40051555) != 0 )
    {
      result = (**(__int64 (__fastcall ***)(__int64))v3)(v3);
      if ( (_DWORD)result )
        return result;
      v5 = *(unsigned __int16 *)(a1 + 152);
      if ( (_WORD)v5 )
        v4 += v5 + 4;
    }
    if ( v4 <= 0xFFFF )
    {
      *(_WORD *)(a1 + 154) = v4;
      return 0i64;
    }
    else
    {
      return 1359i64;
    }
  }
  return result;
}
// 180063B48: variable 'v3' is possibly undefined
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

