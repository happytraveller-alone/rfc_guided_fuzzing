//----- (00000001800770E0) ----------------------------------------------------
__int64 __fastcall CTls13Record::EndOfMessage(CTls13Record *this)
{
  __int64 v2; // r8
  unsigned __int64 v3; // rdx
  unsigned __int64 v4; // r9
  __int64 v5; // rax
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rcx
  __int64 v8; // rcx
  __int64 result; // rax

  if ( !*((_WORD *)this + 8) )
    return 87i64;
  v2 = *((_QWORD *)this + 3);
  if ( !v2 )
    return 87i64;
  v3 = *((_QWORD *)this + 4);
  if ( !v3 )
    return 87i64;
  v4 = v2 + 12i64 * *((unsigned __int16 *)this + 8);
  if ( v3 >= v4 )
    return 87i64;
  v5 = *((_QWORD *)this + 6);
  if ( !v5 )
    return 87i64;
  if ( !*(_QWORD *)(v5 + 8) )
    return 87i64;
  v6 = *((_QWORD *)this + 7);
  if ( !v6 )
    return 87i64;
  v7 = *((_QWORD *)this + 8);
  if ( v7 < v6 )
    return 87i64;
  v8 = v7 - v6;
  if ( *((unsigned __int16 *)this + 45) + 5i64 < v8 || v8 <= 5 || !*((_DWORD *)this + 18) )
    return 87i64;
  if ( v3 >= v4 - 12 )
  {
    result = CTls13Record::FinalizeRecord(this);
    if ( (_DWORD)result )
      return result;
    *((_WORD *)this + 45) = *((_WORD *)this + 40);
    *((_WORD *)this + 8) = 0;
    *((_QWORD *)this + 3) = 0i64;
    *((_QWORD *)this + 4) = 0i64;
    *((_DWORD *)this + 10) = 0;
    *((_QWORD *)this + 6) = 0i64;
    *((_QWORD *)this + 7) = 0i64;
    *((_QWORD *)this + 8) = 0i64;
    *((_DWORD *)this + 21) = 20;
    *((_BYTE *)this + 88) = 0;
    goto LABEL_18;
  }
  if ( (*(_BYTE *)(v3 + 8) & 1) == 0
    || (result = (*(__int64 (__fastcall **)(CTls13Record *))(*(_QWORD *)this + 48i64))(this), !(_DWORD)result) )
  {
    *((_QWORD *)this + 4) += 12i64;
LABEL_18:
    *((_DWORD *)this + 18) = 0;
    return 0i64;
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

