// File count: 963
// Total lines: 36
-----------------------------------------
__int64 __fastcall ConvertCertificateAlgToTlsSignatureAlgorithm(unsigned int a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // ebx
  int SignatureDetailsFromAlgId; // eax
  unsigned int v7; // [rsp+40h] [rbp+8h] BYREF

  if ( a1 == 8704 )
  {
    return 2;
  }
  else
  {
    v4 = 3;
    if ( a1 != 8707 )
    {
      if ( a1 == 9216 || a1 == 41984 )
      {
        return 1;
      }
      else
      {
        SignatureDetailsFromAlgId = I_GetSignatureDetailsFromAlgId(a1, a2, a3, &v7, 0i64);
        v4 = v7;
        if ( (SignatureDetailsFromAlgId || !v7)
          && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 12i64, &WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids, a1);
        }
      }
    }
  }
  return v4;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
