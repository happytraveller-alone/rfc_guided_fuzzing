//----- (0000000180077740) ----------------------------------------------------
__int64 __fastcall CTls13Record::WritePlaintext(CTls13Record *this, unsigned __int16 a2, const unsigned __int8 *a3)
{
  int v3; // edi
  __int64 v6; // rdx
  unsigned __int16 *v7; // r8
  __int64 v8; // rdx
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rcx
  __int64 v11; // rsi
  __int64 v12; // rcx
  __int64 result; // rax
  unsigned __int16 v14; // si
  int v15; // ecx
  const unsigned __int8 *v16; // r8
  CTls13Record *v17; // rcx

  v3 = a2;
  if ( !*((_WORD *)this + 8) )
    return 87i64;
  v6 = *((_QWORD *)this + 3);
  if ( !v6 )
    return 87i64;
  v7 = (unsigned __int16 *)*((_QWORD *)this + 4);
  if ( !v7 )
    return 87i64;
  if ( (unsigned __int64)v7 >= v6 + 12 * (unsigned __int64)*((unsigned __int16 *)this + 8) )
    return 87i64;
  v8 = *((_QWORD *)this + 6);
  if ( !v8 )
    return 87i64;
  if ( !*(_QWORD *)(v8 + 8) )
    return 87i64;
  v9 = *((_QWORD *)this + 7);
  if ( !v9 )
    return 87i64;
  v10 = *((_QWORD *)this + 8);
  if ( v10 < v9 )
    return 87i64;
  v11 = *((unsigned __int16 *)this + 45);
  v12 = v10 - v9;
  if ( v11 + 5 < v12 || v12 < 5 )
    return 87i64;
  if ( (_WORD)v3 )
  {
    if ( !a3 )
      return 87i64;
  }
  else if ( a3 )
  {
    return 87i64;
  }
  if ( v3 + *((_DWORD *)this + 18) > (unsigned int)*v7 || (unsigned int)(v3 + *(_DWORD *)(v8 + 4)) > *(_DWORD *)v8 )
    return 87i64;
  if ( !(_WORD)v3 )
    return 0i64;
  v14 = *((_WORD *)this + 28) + v11 - *((_WORD *)this + 32) + 5;
  v15 = *((_DWORD *)v7 + 1);
  if ( v15 != *((_DWORD *)this + 21)
    || v15 == 21 && v14 < (unsigned __int16)v3
    || ((*((_DWORD *)v7 + 2) & 2) != 0) != *((_BYTE *)this + 88) )
  {
    result = CTls13Record::FinalizeRecord(this);
    if ( (_DWORD)result )
      return result;
    result = CTls13Record::InitializeRecord(this);
    if ( (_DWORD)result )
      return result;
    v14 = *((_WORD *)this + 45);
  }
  v16 = a3;
  v17 = this;
  if ( (unsigned __int16)v3 < v14 )
    return CTls13Record::WriteRecord(this, v3, a3);
  while ( 1 )
  {
    result = CTls13Record::WriteRecord(v17, v14, v16);
    if ( (_DWORD)result )
      break;
    a3 += v14;
    LOWORD(v3) = v3 - v14;
    if ( !(_WORD)v3 )
      return 0i64;
    result = CTls13Record::FinalizeRecord(this);
    if ( (_DWORD)result )
      break;
    result = CTls13Record::InitializeRecord(this);
    if ( (_DWORD)result )
      break;
    v14 = *((_WORD *)this + 45);
    v16 = a3;
    v17 = this;
    if ( (unsigned __int16)v3 <= v14 )
      v14 = v3;
  }
  return result;
}

