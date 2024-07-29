//----- (0000000180043A7C) ----------------------------------------------------
__int64 __fastcall VerifyClientCertPolicyBuffer(char *a1, unsigned int a2)
{
  int v2; // r8d
  char *v3; // r9
  const unsigned __int16 *v4; // rcx
  const unsigned __int16 *v5; // r10
  __int64 result; // rax

  v2 = a2;
  v3 = a1;
  if ( a2 < 0x38 )
    return 2148074333i64;
  if ( &a1[a2] < a1 )
    return 2148074333i64;
  v4 = (const unsigned __int16 *)*((_QWORD *)a1 + 5);
  if ( ((unsigned __int8)v4 & 1) != 0 )
    return 2148074333i64;
  v5 = (const unsigned __int16 *)*((_QWORD *)v3 + 6);
  if ( ((unsigned __int8)v5 & 1) != 0 )
    return 2148074333i64;
  if ( !v4 || (result = VerifyUnicodeStringIsInBuffer(v4, v3, a2), !(_DWORD)result) )
  {
    if ( !v5 )
      return 0i64;
    result = VerifyUnicodeStringIsInBuffer(v5, v3, v2);
    if ( !(_DWORD)result )
      return 0i64;
  }
  return result;
}
// 180043ABB: variable 'v5' is possibly undefined
// 180043AC3: variable 'v3' is possibly undefined
// 180043AC3: variable 'v2' is possibly undefined

