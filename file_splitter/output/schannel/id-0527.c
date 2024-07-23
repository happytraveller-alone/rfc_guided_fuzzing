// File count: 527
// Total lines: 16
-----------------------------------------
__int64 __fastcall LookupCertificateAlg(wchar_t *a1, __int64 a2)
{
  const wchar_t *v2; // rbx
  unsigned int v4; // [rsp+40h] [rbp+8h] BYREF

  v4 = 0;
  v2 = a1 + 274;
  if ( (unsigned int)I_GetSignatureDetailsFromAlgorithmName(a1 + 274, a2, &v4)
    && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    WPP_SF_S(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xBu, (__int64)&WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids, v2);
  }
  return v4;
}
