//----- (000000018007888C) ----------------------------------------------------
BOOLEAN FreeExternalSignatureAlgorithms()
{
  unsigned int i; // ebx
  PVOID *v1; // r8
  BOOLEAN result; // al

  for ( i = 7; i < g_dwSignatureInfoTotalCount; ++i )
  {
    v1 = (PVOID *)g_pSignatureInfo[i];
    if ( v1 && *v1 )
    {
      RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, *v1);
      v1 = (PVOID *)g_pSignatureInfo[i];
    }
    result = RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v1);
    g_pSignatureInfo[i] = 0i64;
  }
  g_dwSignatureInfoTotalCount = 7;
  return result;
}
// 180092218: using guessed type int g_dwSignatureInfoTotalCount;
// 180092220: using guessed type _QWORD g_pSignatureInfo[16];

