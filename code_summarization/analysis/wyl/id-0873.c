//----- (000000018004718C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetKeyingMaterialInfo(CSsl3TlsContext *this, void *a2, unsigned int a3)
{
  struct _SecPkgContext_KeyingMaterialInfo *v6; // rax
  struct _SecPkgContext_KeyingMaterialInfo *v7; // rdi
  unsigned int KeyingMaterialInfoForSca; // esi
  void **v9; // rcx

  v6 = (struct _SecPkgContext_KeyingMaterialInfo *)SPExternalAlloc(0x28u);
  v7 = v6;
  if ( v6 )
  {
    KeyingMaterialInfoForSca = SpGetKeyingMaterialInfoForSca(a2, a3, v6);
    if ( KeyingMaterialInfoForSca )
    {
      SPExternalFree(v7);
    }
    else
    {
      v9 = (void **)*((_QWORD *)this + 105);
      if ( v9 )
      {
        if ( v9[1] )
        {
          SPExternalFree(v9[1]);
          v9 = (void **)*((_QWORD *)this + 105);
        }
        if ( v9[3] )
        {
          SPExternalFree(v9[3]);
          v9 = (void **)*((_QWORD *)this + 105);
        }
        SPExternalFree(v9);
      }
      *((_QWORD *)this + 105) = v7;
    }
  }
  else
  {
    return 14;
  }
  return KeyingMaterialInfoForSca;
}

