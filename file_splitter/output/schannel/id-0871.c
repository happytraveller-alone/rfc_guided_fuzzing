// File count: 871
// Total lines: 36
-----------------------------------------
__int64 __fastcall CSslContext::SetApplicationData(CSslContext *this, void *a2, unsigned int a3)
{
  unsigned int AppDataForSca; // edi
  __int64 v6; // rdi
  void *v7; // rcx
  unsigned __int8 *v8; // rcx
  unsigned int v9; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int8 *v10; // [rsp+48h] [rbp+20h] BYREF

  v10 = 0i64;
  v9 = 0;
  if ( !*((_QWORD *)this + 11) )
    return 2148074241i64;
  AppDataForSca = SpGetAppDataForSca(a2, a3, &v10, &v9);
  if ( AppDataForSca )
  {
    v8 = v10;
  }
  else
  {
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
    v6 = *((_QWORD *)this + 11);
    v7 = *(void **)(v6 + 56);
    if ( v7 )
      SPExternalFree(v7);
    *(_QWORD *)(v6 + 56) = v10;
    *(_DWORD *)(v6 + 64) = v9;
    AppDataForSca = 0;
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
    v8 = 0i64;
  }
  if ( v8 )
    SPExternalFree(v8);
  return AppDataForSca;
}
