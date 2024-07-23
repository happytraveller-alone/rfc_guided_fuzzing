//----- (00000001800248E0) ----------------------------------------------------
__int64 __fastcall AllocateCipherSuiteData(unsigned int a1, unsigned __int8 **a2, struct CCipherSuiteInfo **a3)
{
  unsigned __int8 *v5; // rax

  if ( a1 > 864 * a1 )
    return 14i64;
  v5 = (unsigned __int8 *)SPExternalAlloc(864 * a1 + 16);
  *a2 = v5;
  if ( !v5 )
    return 14i64;
  *a3 = (struct CCipherSuiteInfo *)(v5 + 16);
  return 0i64;
}

