//----- (000000018007AD88) ----------------------------------------------------
__int64 __fastcall PAC_UnmarshallValidationInfo(
        struct _NETLOGON_VALIDATION_SAM_INFO3 **a1,
        unsigned __int8 *a2,
        int a3)
{
  __int64 result; // rax
  int v5; // edi

  *a1 = 0i64;
  result = PAC_DecodeValidationInformation(a2, a3, a1);
  if ( (int)result >= 0 )
  {
    v5 = PacValidateInfo3(*a1);
    if ( v5 < 0 )
    {
      (*(void (__fastcall **)(_QWORD))(LsaTable + 48))(*a1);
      *a1 = 0i64;
    }
    return (unsigned int)v5;
  }
  return result;
}
// 180092620: using guessed type __int64 LsaTable;

