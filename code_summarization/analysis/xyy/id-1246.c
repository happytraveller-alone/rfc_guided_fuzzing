//----- (00000001800635D4) ----------------------------------------------------
struct CTlsRecord *__fastcall CTlsRecord::MakeRecord(__int64 a1, unsigned __int8 *a2, struct CSsl3TlsContext *a3)
{
  if ( !a2 || !a3 )
    return 0i64;
  *((_QWORD *)a2 + 4) = 0i64;
  *((_DWORD *)a2 + 18) = 0;
  *((_QWORD *)a2 + 1) = a3;
  *((_WORD *)a2 + 8) = 0;
  *((_QWORD *)a2 + 3) = 0i64;
  *((_DWORD *)a2 + 10) = 0;
  *((_QWORD *)a2 + 6) = 0i64;
  *((_QWORD *)a2 + 7) = 0i64;
  *((_QWORD *)a2 + 8) = 0i64;
  if ( (a1 & 0x100000000i64) != 0 )
  {
    *(_QWORD *)a2 = &CNulRecord::`vftable';
  }
  else
  {
    *((_DWORD *)a2 + 21) = 20;
    *(_QWORD *)a2 = &CTls13Record::`vftable';
    *((_WORD *)a2 + 40) = 0x4000;
    *((_WORD *)a2 + 45) = 0x4000;
    a2[88] = 0;
  }
  return (struct CTlsRecord *)a2;
}
// 18007CF80: using guessed type void *CTls13Record::`vftable';
// 18007D590: using guessed type void *CNulRecord::`vftable';
