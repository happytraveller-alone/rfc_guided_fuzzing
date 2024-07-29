//----- (00000001800634E0) ----------------------------------------------------
__int64 __fastcall CTlsRecord::HashPskBinderTranscript(CTlsRecord *this, __int64 a2)
{
  __int64 v4; // r9
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rdx
  unsigned __int16 v8; // cx
  _BYTE *v9; // rdx
  __int64 v10; // rax
  __int64 *v12; // rax
  __int64 v13; // r10

  if ( !a2 )
    return 87i64;
  if ( !*((_WORD *)this + 8) )
    return 87i64;
  v4 = *((_QWORD *)this + 3);
  if ( !v4 )
    return 87i64;
  v5 = *((_QWORD *)this + 4);
  if ( !v5 )
    return 87i64;
  if ( v5 >= v4 + 12 * (unsigned __int64)*((unsigned __int16 *)this + 8) )
    return 87i64;
  if ( (*(_BYTE *)(v5 + 8) & 1) == 0 )
    return 87i64;
  v6 = *((_QWORD *)this + 7);
  if ( !v6 )
    return 87i64;
  v7 = *((_QWORD *)this + 8);
  if ( v7 < v6 || !*((_DWORD *)this + 18) )
    return 87i64;
  v8 = (__int64)(v7 - v6) >= *((unsigned int *)this + 18) ? *((_WORD *)this + 36) : v7 - *((_WORD *)this + 28);
  v9 = (_BYTE *)(v7 - v8);
  if ( *v9 != 1 )
    return 87i64;
  v10 = *(_QWORD *)(*((_QWORD *)this + 1) + 88i64);
  if ( !v10 )
    return 2148074244i64;
  v12 = *(__int64 **)(v10 + 176);
  if ( v12 )
    v13 = *v12;
  else
    v13 = 0i64;
  return SslHashHandshake(v13, a2, v9, v8, 0);
}
// 180098420: using guessed type __int64 __fastcall SslHashHandshake(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);

