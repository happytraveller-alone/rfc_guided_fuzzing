//----- (000000018005A424) ----------------------------------------------------
CTls13Context *__fastcall CTls13Context::CTls13Context(CTls13Context *this, struct CTlsRecord *a2)
{
  CTls13Context *result; // rax

  *((_QWORD *)this + 3) = a2;
  *((_BYTE *)this + 8) = 0;
  *(_QWORD *)this = &CTls13Context::`vftable';
  *((_BYTE *)this + 32) = 0;
  *((_QWORD *)this + 2) = &CTls13ChangeCipherSpec::`vftable';
  *((_QWORD *)this + 5) = 0i64;
  *((_QWORD *)this + 6) = 0i64;
  *((_QWORD *)this + 7) = 0i64;
  *((_QWORD *)this + 8) = 0i64;
  *((_QWORD *)this + 9) = 0i64;
  *((_QWORD *)this + 10) = 0i64;
  *((_QWORD *)this + 11) = 0i64;
  *((_QWORD *)this + 12) = 0i64;
  *((_QWORD *)this + 13) = 0i64;
  *((_QWORD *)this + 14) = 0i64;
  result = this;
  *((_BYTE *)this + 120) = 0;
  *((_QWORD *)this + 16) = 0i64;
  *((_BYTE *)this + 136) = 0;
  *((_QWORD *)this + 18) = 0i64;
  *(_OWORD *)((char *)this + 152) = 0i64;
  *(_OWORD *)((char *)this + 168) = 0i64;
  *(_OWORD *)((char *)this + 184) = 0i64;
  *((_WORD *)this + 100) = 256;
  *((_QWORD *)this + 26) = a2;
  *((_BYTE *)this + 216) = 0;
  *((_QWORD *)this + 28) = 0i64;
  *((_WORD *)this + 116) = 0;
  *((_QWORD *)this + 30) = 0i64;
  *((_BYTE *)this + 248) = 0;
  *(_OWORD *)((char *)this + 249) = 0i64;
  *(_OWORD *)((char *)this + 265) = 0i64;
  *(_WORD *)((char *)this + 281) = 0;
  return result;
}
// 18007CB58: using guessed type void *CTls13ChangeCipherSpec::`vftable';
// 18007CB60: using guessed type void *CTls13Context::`vftable';

