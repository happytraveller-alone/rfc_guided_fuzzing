// File count: 1487
// Total lines: 38
----------------------------------------
__int64 __fastcall CNulRecord::SetFlightInfo(
        CNulRecord *this,
        unsigned __int16 a2,
        struct CTlsRecord::CMessageInfo *a3,
        unsigned int *a4)
{
  unsigned int v4; // r10d
  __int64 v5; // rbx
  struct CTlsRecord::CMessageInfo *v7; // rdx
  struct CTlsRecord::CMessageInfo *v8; // rcx
  int v9; // eax
  __int64 result; // rax

  v4 = 0;
  v5 = a2;
  if ( *((_QWORD *)this + 6) || !a2 || !a3 || !a4 )
    return 87i64;
  v7 = a3;
  v8 = (struct CTlsRecord::CMessageInfo *)((char *)a3 + 12 * v5);
  if ( a3 < v8 )
  {
    do
    {
      v9 = *(unsigned __int16 *)v7;
      v7 = (struct CTlsRecord::CMessageInfo *)((char *)v7 + 12);
      v4 += v9;
    }
    while ( v7 < v8 );
  }
  *((_WORD *)this + 8) = v5;
  result = 0i64;
  *((_QWORD *)this + 3) = a3;
  *((_QWORD *)this + 4) = a3;
  *((_DWORD *)this + 10) = v4;
  *a4 = v4;
  return result;
}
