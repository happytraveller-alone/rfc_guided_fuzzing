//----- (0000000180077204) ----------------------------------------------------
__int64 __fastcall CTls13Record::FinalizeRecord(CTls13Record *this)
{
  __int64 v2; // r8
  unsigned __int64 v3; // rdx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rcx
  __int64 v6; // rcx
  __int64 result; // rax
  _BYTE *v8; // rdx
  char v9; // cl
  __int16 v10; // cx

  if ( !*((_WORD *)this + 8) )
    return 87i64;
  v2 = *((_QWORD *)this + 3);
  if ( !v2 )
    return 87i64;
  v3 = *((_QWORD *)this + 4);
  if ( !v3 )
    return 87i64;
  if ( v3 >= v2 + 12 * (unsigned __int64)*((unsigned __int16 *)this + 8) )
    return 87i64;
  v4 = *((_QWORD *)this + 7);
  if ( !v4 )
    return 87i64;
  v5 = *((_QWORD *)this + 8);
  if ( v5 < v4 )
    return 87i64;
  v6 = v5 - v4;
  if ( *((unsigned __int16 *)this + 45) + 5i64 < v6 || v6 <= 5 )
    return 87i64;
  if ( !*((_DWORD *)this + 18)
    || (*(_BYTE *)(v3 + 8) & 1) == 0
    || (result = (*(__int64 (__fastcall **)(CTls13Record *))(*(_QWORD *)this + 48i64))(this), !(_DWORD)result) )
  {
    if ( *((_BYTE *)this + 88) )
    {
      return CTls13Record::EncryptRecord(this);
    }
    else
    {
      v8 = (_BYTE *)*((_QWORD *)this + 7);
      *v8 = *((_BYTE *)this + 84);
      v9 = 1;
      v8[1] = 3;
      if ( *(_DWORD *)(*((_QWORD *)this + 1) + 68i64) != 40 )
        v9 = 3;
      v8[2] = v9;
      v10 = *((_WORD *)this + 32) - *((_WORD *)this + 28) - 5;
      v8[4] = v10;
      v8[3] = HIBYTE(v10);
      *((_QWORD *)this + 7) = *((_QWORD *)this + 8);
      return 0i64;
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

