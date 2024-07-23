//----- (0000000180016E98) ----------------------------------------------------
CCipherMill *__fastcall CCipherMill::CCipherMill(CCipherMill *this)
{
  dword_180092488 = 0;
  qword_180092490 = 0i64;
  qword_180092498 = 0;
  hProvider = 0i64;
  *(_OWORD *)&xmmword_1800925B0 = 0i64;
  qword_1800925C0 = 0i64;
  qword_1800925C8 = 0i64;
  word_1800925D0 = 0;
  xmmword_1800925EA = 0i64;
  xmmword_1800925FA = 0i64;
  word_1800925E8 = 0;
  word_18009260A = 0;
  RtlInitializeResource(&Resource);
  g_cCipherMill = 1;
  return (CCipherMill *)&g_cCipherMill;
}
// 180092488: using guessed type int dword_180092488;
// 180092490: using guessed type __int64 qword_180092490;
// 1800925C0: using guessed type __int64 qword_1800925C0;
// 1800925D0: using guessed type __int16 word_1800925D0;
// 1800925EA: using guessed type __int128 xmmword_1800925EA;
// 1800925FA: using guessed type __int128 xmmword_1800925FA;
// 18009260A: using guessed type __int16 word_18009260A;

