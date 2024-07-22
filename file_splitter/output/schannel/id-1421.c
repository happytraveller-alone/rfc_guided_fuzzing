//----- (0000000180070EE8) ----------------------------------------------------
__int64 __fastcall GetRsaKeyModulus(__int64 a1, unsigned int *a2)
{
  __int64 result; // rax
  __int64 v4; // [rsp+50h] [rbp+18h] BYREF
  unsigned int *v5; // [rsp+58h] [rbp+20h] BYREF

  v5 = 0i64;
  result = SslGetKeyProperty(a1, L"Block Length", &v5, &v4, 0);
  if ( !(_DWORD)result )
  {
    *a2 = *v5;
    SslFreeBuffer();
    return 0i64;
  }
  return result;
}
// 1800858F8: using guessed type wchar_t aBlockLength[13];
// 180098480: using guessed type __int64 SslFreeBuffer(void);
// 180098550: using guessed type __int64 __fastcall SslGetKeyProperty(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);

