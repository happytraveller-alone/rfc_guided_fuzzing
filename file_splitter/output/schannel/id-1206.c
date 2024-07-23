// File count: 1206
// Total lines: 34
----------------------------------------
__int64 __fastcall CSslCredential::GetProviderSpecificMasterKey(
        CSslCredential *this,
        __int64 a2,
        struct CSslServerKey **a3)
{
  struct _RTL_RESOURCE *v3; // rsi
  unsigned int v7; // edi
  __int64 v8; // rax
  __int64 v9; // rcx

  v3 = (struct _RTL_RESOURCE *)((char *)this + 552);
  v7 = 1168;
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 552), 1u);
  v8 = 0i64;
  if ( *((_DWORD *)this + 24) )
  {
    while ( 1 )
    {
      v9 = *(_QWORD *)(*((_QWORD *)this + 11) + 8 * v8);
      if ( *(_QWORD *)(v9 + 16) == a2 )
        break;
      v8 = (unsigned int)(v8 + 1);
      if ( (unsigned int)v8 >= *((_DWORD *)this + 24) )
        goto LABEL_6;
    }
    _InterlockedIncrement((volatile signed __int32 *)(v9 + 24));
    v7 = 0;
    *a3 = *(struct CSslServerKey **)(*((_QWORD *)this + 11) + 8i64 * (unsigned int)v8);
  }
LABEL_6:
  RtlReleaseResource(v3);
  return v7;
}
