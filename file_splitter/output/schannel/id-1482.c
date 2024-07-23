// File count: 1482
// Total lines: 35
----------------------------------------
__int64 __fastcall CTls13Record::SetOutputBuffer(CTls13Record *this, struct SPBuffer *a2)
{
  _WORD *v2; // r9
  __int64 v3; // rax
  __int64 v4; // rax
  _WORD *v5; // rax

  if ( !*((_WORD *)this + 8) )
    return 87i64;
  v2 = (_WORD *)*((_QWORD *)this + 3);
  if ( !v2
    || *((_QWORD *)this + 6)
    || !a2
    || *(_DWORD *)a2 < *((_DWORD *)this + 10)
    || *((_DWORD *)a2 + 1)
    || !*((_QWORD *)a2 + 1) )
  {
    return 87i64;
  }
  *((_QWORD *)this + 6) = a2;
  v3 = *((_QWORD *)a2 + 1);
  *((_QWORD *)this + 7) = v3;
  *((_QWORD *)this + 8) = v3;
  v4 = *((unsigned __int16 *)this + 8);
  *((_DWORD *)this + 18) = 0;
  *((_QWORD *)this + 4) = v2;
  v5 = &v2[6 * v4];
  while ( v2 < v5 && !*v2 )
  {
    v2 += 6;
    *((_QWORD *)this + 4) = v2;
  }
  return CTls13Record::InitializeRecord(this);
}
