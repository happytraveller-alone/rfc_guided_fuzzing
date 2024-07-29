//----- (0000000180078C6C) ----------------------------------------------------
BOOLEAN FreeExternalCipherAlgorithms()
{
  unsigned int i; // ebx
  PVOID *v1; // r8
  BOOLEAN result; // al

  for ( i = 7; i < g_dwCipherInfoTotalCount; ++i )
  {
    v1 = (PVOID *)g_pCipherInfo[i];
    if ( v1 && *v1 )
    {
      RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, *v1);
      v1 = (PVOID *)g_pCipherInfo[i];
    }
    result = RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v1);
    g_pCipherInfo[i] = 0i64;
  }
  g_dwCipherInfoTotalCount = 7;
  return result;
}
// 1800922A0: using guessed type _QWORD g_pCipherInfo[16];
// 180092320: using guessed type int g_dwCipherInfoTotalCount;

