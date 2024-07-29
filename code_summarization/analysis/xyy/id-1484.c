//----- (00000001800778D4) ----------------------------------------------------
__int64 __fastcall CTls13Record::WriteRecord(CTls13Record *this, unsigned __int16 a2, const unsigned __int8 *a3)
{
  __int64 v3; // r11
  __int64 v6; // r9
  unsigned __int16 *v7; // r10
  __int64 v8; // rdx
  unsigned __int64 v9; // rax
  __int64 v10; // rbp
  __int64 v11; // r8
  int v13; // edi
  __int64 v14; // rax

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
  if ( *((_QWORD *)this + 8) < v9 )
    return 87i64;
  v10 = (unsigned int)v3;
  v11 = *((_QWORD *)this + 8) - v9;
  if ( *((unsigned __int16 *)this + 45) + 5i64 < v11 + v3 || v11 < 5 )
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
  v13 = v3;
  if ( (int)v3 + *((_DWORD *)this + 18) > (unsigned int)*v7 || (unsigned int)(v3 + *(_DWORD *)(v8 + 4)) > *(_DWORD *)v8 )
    return 87i64;
  if ( (_WORD)v3 )
  {
    memcpy_0(*((void **)this + 8), a3, (unsigned int)v3);
    v14 = *((_QWORD *)this + 6);
    *((_QWORD *)this + 8) += v10;
    *((_DWORD *)this + 18) += v13;
    *(_DWORD *)(v14 + 4) += v13;
  }
  return 0i64;
}

