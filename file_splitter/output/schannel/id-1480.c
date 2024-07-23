// File count: 1480
// Total lines: 33
----------------------------------------
__int64 __fastcall CTls13Record::InitializeRecord(CTls13Record *this)
{
  __int64 v2; // rcx
  unsigned __int64 v3; // rdx
  __int64 v4; // rcx
  int v5; // edx
  __int16 v6; // ax

  if ( !*((_QWORD *)this + 4) )
    return 87i64;
  if ( *((_QWORD *)this + 4) >= *((_QWORD *)this + 3) + 12 * (unsigned __int64)*((unsigned __int16 *)this + 8) )
    return 87i64;
  v2 = *((_QWORD *)this + 6);
  if ( !v2 )
    return 87i64;
  if ( !*(_QWORD *)(v2 + 8) )
    return 87i64;
  v3 = *((_QWORD *)this + 7);
  if ( !v3 || *((_QWORD *)this + 8) < v3 || (unsigned int)(*(_DWORD *)(v2 + 4) + 5) >= *(_DWORD *)v2 )
    return 87i64;
  *((_QWORD *)this + 8) = v3 + 5;
  *(_DWORD *)(v2 + 4) += 5;
  v4 = *((_QWORD *)this + 4);
  *((_DWORD *)this + 21) = *(_DWORD *)(v4 + 4);
  v5 = *(_DWORD *)(v4 + 8) & 2;
  *((_BYTE *)this + 88) = v5 != 0;
  v6 = *((_WORD *)this + 40) - 1;
  if ( !v5 )
    v6 = *((_WORD *)this + 40);
  *((_WORD *)this + 45) = v6;
  return 0i64;
}
