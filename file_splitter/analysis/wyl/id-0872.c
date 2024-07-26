//----- (0000000180047118) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetEapPrfType(CSsl3TlsContext *this, void *a2, unsigned int a3)
{
  unsigned int AppDataForSca; // eax
  void *v5; // rdx
  unsigned int v6; // ebx
  void *v8; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v9; // [rsp+58h] [rbp+20h] BYREF

  v8 = 0i64;
  v9 = 0;
  AppDataForSca = SpGetAppDataForSca(a2, a3, (unsigned __int8 **)&v8, &v9);
  v5 = v8;
  v6 = AppDataForSca;
  if ( !AppDataForSca )
  {
    if ( v9 == 4 )
      *((_DWORD *)this + 84) = *(_DWORD *)v8;
    else
      v6 = 87;
  }
  if ( v5 )
    SPExternalFree(v5);
  return v6;
}

