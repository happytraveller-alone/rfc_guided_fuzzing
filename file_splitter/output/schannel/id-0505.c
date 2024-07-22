//----- (0000000180024FD0) ----------------------------------------------------
void __fastcall CCipherMill::DeleteProviderList(CCipherMill *this)
{
  __int64 i; // rdi

  for ( i = 0i64; (unsigned int)i < qword_180092498; i = (unsigned int)(i + 1) )
  {
    SslFreeObject(qword_1800924A0[i], 0i64);
    qword_1800924A0[i] = 0i64;
  }
  if ( qword_180092490 )
  {
    SslFreeBuffer();
    qword_180092490 = 0i64;
  }
  qword_180092498 = 0;
}
// 180092490: using guessed type __int64 qword_180092490;
// 1800924A0: using guessed type unsigned __int64 qword_1800924A0[32];
// 180098480: using guessed type __int64 SslFreeBuffer(void);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

