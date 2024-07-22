//----- (000000018007A678) ----------------------------------------------------
__int64 __fastcall PAC_DecodeValidationInformation(
        unsigned __int8 *a1,
        int a2,
        struct _NETLOGON_VALIDATION_SAM_INFO3 **a3)
{
  unsigned int v6; // ebx
  __int128 v8; // [rsp+30h] [rbp-18h] BYREF
  handle_t Handle; // [rsp+68h] [rbp+20h] BYREF

  v6 = 0;
  Handle = 0i64;
  v8 = 0i64;
  if ( MesDecodeIncrementalHandleCreate(&v8, (MIDL_ES_READ)PacReadFcn, &Handle) )
  {
    v6 = -1073741670;
  }
  else
  {
    DWORD2(v8) = a2;
    *(_QWORD *)&v8 = a1;
    NdrMesTypeDecode3(Handle, &pPicklingInfo, &pProxyInfo, (const unsigned int **)&ArrTypeOffset, 1u, a3);
  }
  if ( Handle )
    MesHandleFree(Handle);
  return v6;
}

