// File count: 1271
// Total lines: 38
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeEncryptedExtensionsSize(CTls13ServerHandshake *this)
{
  unsigned int *v2; // rcx
  unsigned __int64 v3; // rbx
  int v4; // ebx
  __int64 v5; // rax
  int v6; // eax
  __int64 result; // rax
  unsigned int v8; // ebx

  v2 = (unsigned int *)*((_QWORD *)this + 1);
  v3 = (unsigned __int64)v2[34] >> 19;
  *((_WORD *)this + 83) = 0;
  v4 = v3 & 4;
  v5 = (*(__int64 (__fastcall **)(unsigned int *))(*(_QWORD *)v2 + 88i64))(v2);
  if ( v5 && *(_DWORD *)v5 == 1 && *(_DWORD *)(v5 + 4) == 2 )
    *((_WORD *)this + 83) = *(unsigned __int8 *)(v5 + 8) + 3;
  v6 = *((unsigned __int16 *)this + 83);
  if ( (_WORD)v6 )
    v4 += v6 + 4;
  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeGenericExtensionsSize((__int64)this, 8);
  if ( !(_DWORD)result )
  {
    v8 = *((unsigned __int16 *)this + 61) + v4;
    if ( v8 <= 0xFFFF )
    {
      *((_WORD *)this + 82) = v8;
      return 0i64;
    }
    else
    {
      return 1359i64;
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
