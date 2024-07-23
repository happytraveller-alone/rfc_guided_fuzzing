// File count: 1510
// Total lines: 23
----------------------------------------
BOOLEAN FreeExternalKeyExchangeAlgorithms()
{
  unsigned int i; // ebx
  PVOID *v1; // r8
  BOOLEAN result; // al

  for ( i = 7; i < g_dwKeyExchangeInfoTotalCount; ++i )
  {
    v1 = (PVOID *)g_pKeyExchangeInfo[i];
    if ( v1 && *v1 )
    {
      RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, *v1);
      v1 = (PVOID *)g_pKeyExchangeInfo[i];
    }
    result = RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v1);
    g_pKeyExchangeInfo[i] = 0i64;
  }
  g_dwKeyExchangeInfoTotalCount = 7;
  return result;
}
// 1800923B0: using guessed type int g_dwKeyExchangeInfoTotalCount;
// 1800923C0: using guessed type _QWORD g_pKeyExchangeInfo[12];
