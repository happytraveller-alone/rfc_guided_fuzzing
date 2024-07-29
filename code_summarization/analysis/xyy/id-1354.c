//----- (000000018006AD5C) ----------------------------------------------------
__int64 __fastcall CTls13Context::ExportTrafficSecret(
        _QWORD *a1,
        __int64 a2,
        int a3,
        char a4,
        unsigned __int8 a5,
        __int64 a6,
        ULONG a7)
{
  __int64 v10; // rsi
  unsigned int Property; // ebx
  __int64 v12; // r8
  BCRYPT_HANDLE hObject; // [rsp+30h] [rbp-28h] BYREF
  ULONG pcbResult; // [rsp+68h] [rbp+10h] BYREF

  if ( !a2 )
    return 2148074333i64;
  if ( !a3 )
    return 2148074333i64;
  if ( !a7 )
    return 2148074333i64;
  if ( !a5 )
    return 2148074333i64;
  v10 = a6;
  if ( !a6 )
    return 2148074333i64;
  pcbResult = 0;
  hObject = 0i64;
  Property = BCryptOpenAlgorithmProvider(&hObject, (LPCWSTR)(a6 + 256), 0i64, 0);
  if ( !Property )
  {
    Property = BCryptGetProperty(hObject, L"HashDigestLength", (PUCHAR)&pcbResult, 4u, &pcbResult, 0);
    if ( !Property )
    {
      if ( pcbResult <= a7 )
      {
        v12 = 0i64;
        if ( a5 == 2 )
        {
          if ( a4 )
            v12 = a1[8];
          else
            v12 = a1[7];
        }
        else if ( a5 == 3 )
        {
          if ( a4 )
            v12 = a1[11];
          else
            v12 = a1[10];
        }
        Property = CTls13Context::ExportRawSecretBytes(
                     (CTls13Context *)((unsigned int)a5 - 2),
                     a2,
                     v12,
                     (unsigned __int8 *)(v10 + 398),
                     pcbResult);
        if ( !Property )
          *(_WORD *)(v10 + 396) = pcbResult;
      }
      else
      {
        Property = -2146893052;
      }
    }
  }
  if ( hObject )
    BCryptCloseAlgorithmProvider(hObject, 0);
  return Property;
}

