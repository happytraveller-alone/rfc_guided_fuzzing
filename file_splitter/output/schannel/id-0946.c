//----- (000000018004E470) ----------------------------------------------------
__int64 __fastcall SpQueryCertificateValidationResult(
        __int16 a1,
        unsigned int a2,
        unsigned int a3,
        struct _SecPkgContext_CertificateValidationResult *a4)
{
  __int64 result; // rax

  if ( !a4 )
    return 2148074333i64;
  if ( (a1 & 0x4000) != 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 114i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    return 2148074241i64;
  }
  else
  {
    result = 2148074254i64;
    if ( a3 != -2146893042 )
    {
      *(_QWORD *)a4 = __PAIR64__(a3, a2);
      return 0i64;
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

