//----- (0000000180046990) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::QueryKeyingMaterial(CSsl3TlsContext *this, void *a2)
{
  __int64 v3; // rbx
  __int64 v4; // rcx
  __int64 v7; // rcx
  __int64 v8; // r8
  unsigned int v9; // ebx
  __int64 *v10; // rax
  unsigned int KeyingMaterialCommon; // eax

  v3 = 0i64;
  v4 = *((_QWORD *)this + 11);
  if ( !v4 )
    return 2148074241i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)(v4 + 72), 1u);
  v7 = *((_QWORD *)this + 11);
  v8 = *(_QWORD *)(v7 + 16);
  if ( v8 )
  {
    v10 = (__int64 *)*((_QWORD *)this + 1);
    if ( v10 )
      v3 = *v10;
    KeyingMaterialCommon = CSsl3TlsContext::QueryKeyingMaterialCommon(
                             this,
                             v3,
                             v8,
                             (unsigned __int8 *)this + 272,
                             0x40u,
                             a2);
    v7 = *((_QWORD *)this + 11);
    v9 = KeyingMaterialCommon;
  }
  else
  {
    v9 = -2146893055;
  }
  RtlReleaseResource((PRTL_RESOURCE)(v7 + 72));
  return v9;
}

