// File count: 784
// Total lines: 11
-----------------------------------------
__int64 __fastcall CCipherMill::GetProtocolsWithCipherSuitesEnabled(CCipherMill *this, char a2)
{
  __int64 result; // rax

  result = (unsigned int)qword_1800925C0;
  if ( a2 )
    return HIDWORD(qword_1800925C0);
  return result;
}
// 1800925C0: using guessed type __int64 qword_1800925C0;
