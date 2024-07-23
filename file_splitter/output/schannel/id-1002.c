// File count: 1002
// Total lines: 37
----------------------------------------
__int64 __fastcall ConstructIssuersListFromStore(void *a1, unsigned __int8 **a2, unsigned int *a3)
{
  __int64 result; // rax
  unsigned __int8 *v7; // rax
  unsigned int v8; // edi
  unsigned __int8 v9; // [rsp+30h] [rbp+8h] BYREF

  v9 = 0;
  if ( !a1 )
    return 87i64;
  result = ExtractIssuerNamesFromStore(a1, 0i64, a3, &v9);
  if ( !(_DWORD)result )
  {
    v7 = (unsigned __int8 *)SPExternalAlloc(*a3);
    *a2 = v7;
    if ( v7 )
    {
      v8 = ExtractIssuerNamesFromStore(a1, v7, a3, &v9);
      if ( v8 )
      {
        SPExternalFree(*a2);
        *a2 = 0i64;
        return v8;
      }
      else
      {
        return 0i64;
      }
    }
    else
    {
      return 14i64;
    }
  }
  return result;
}
