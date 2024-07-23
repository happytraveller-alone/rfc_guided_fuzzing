//----- (000000018000F120) ----------------------------------------------------
__int64 __fastcall LookupChecksumAlg(wchar_t *a1)
{
  const wchar_t *v1; // rsi
  unsigned int v3; // ebx
  __int64 HashInfoFromAlgorithmName; // rax
  __int64 v5; // r9
  int v6; // eax
  int v7; // edx
  int HashDetailsFromHashInfo; // eax
  unsigned int v10; // [rsp+40h] [rbp+8h] BYREF

  v1 = a1 + 140;
  v3 = 0;
  v10 = 0;
  HashInfoFromAlgorithmName = I_GetHashInfoFromAlgorithmName(a1 + 140);
  if ( HashInfoFromAlgorithmName )
  {
    HashDetailsFromHashInfo = I_GetHashDetailsFromHashInfo(HashInfoFromAlgorithmName, 0i64, 0i64, v5, &v10, 0i64);
    v3 = v10;
    if ( !HashDetailsFromHashInfo )
      return v3;
  }
  v6 = *((_DWORD *)a1 + 2);
  if ( v6 == 49199 )
    return 32780;
  v7 = 4101;
  if ( (unsigned int)(v6 - 156) <= 0xC )
  {
    if ( _bittest(&v7, v6 - 156) )
      return 32780;
  }
  if ( v6 == 49200 || v6 == 49196 )
    return 32781;
  if ( v6 == 49195 || v6 == 4865 || v6 == 4867 )
    return 32780;
  if ( (unsigned int)(v6 - 157) <= 0xC && _bittest(&v7, v6 - 157) || v6 == 4866 )
    return 32781;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_S(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xEu, (__int64)&WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids, v1);
  return v3;
}
// 18000F1A5: variable 'v5' is possibly undefined

