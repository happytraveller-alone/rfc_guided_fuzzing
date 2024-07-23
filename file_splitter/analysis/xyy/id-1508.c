//----- (000000018007916C) ----------------------------------------------------
BOOLEAN FreeExternalHashAlgorithms()
{
  unsigned int i; // ebx
  PVOID *v1; // r8
  BOOLEAN result; // al

  for ( i = 7; i < g_dwHashInfoTotalCount; ++i )
  {
    v1 = (PVOID *)g_pHashInfo[i];
    if ( v1 && *v1 )
    {
      RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, *v1);
      v1 = (PVOID *)g_pHashInfo[i];
    }
    result = RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v1);
    g_pHashInfo[i] = 0i64;
  }
  g_dwHashInfoTotalCount = 7;
  return result;
}
// 180092324: using guessed type int g_dwHashInfoTotalCount;
// 180092330: using guessed type _QWORD g_pHashInfo[16];

