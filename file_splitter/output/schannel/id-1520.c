// File count: 1520
// Total lines: 57
----------------------------------------
__int64 __fastcall PAC_EncodeValidationInformation(
        struct _NETLOGON_VALIDATION_SAM_INFO3 *a1,
        unsigned __int8 **a2,
        unsigned int *a3)
{
  unsigned int v5; // edi
  unsigned __int8 *v6; // rbx
  unsigned int v7; // esi
  unsigned __int8 *v8; // rax
  RPC_STATUS v9; // eax
  __int128 v11; // [rsp+40h] [rbp-28h] BYREF
  struct _NETLOGON_VALIDATION_SAM_INFO3 *Operation; // [rsp+70h] [rbp+8h] BYREF
  handle_t Handle; // [rsp+88h] [rbp+20h] BYREF

  Operation = a1;
  v5 = 0;
  Handle = 0i64;
  v11 = 0i64;
  v6 = 0i64;
  if ( MesEncodeIncrementalHandleCreate(&v11, (MIDL_ES_ALLOC)PacReadFcn, PacWriteFcn, &Handle)
    || (v7 = NdrMesTypeAlignSize3(
               Handle,
               &pPicklingInfo,
               &pProxyInfo,
               (const unsigned int **)&ArrTypeOffset,
               1u,
               &Operation),
        v8 = (unsigned __int8 *)MIDL_user_allocate(v7),
        (v6 = v8) == 0i64) )
  {
    v5 = -1073741670;
  }
  else
  {
    DWORD2(v11) = v7;
    *(_QWORD *)&v11 = v8;
    v9 = MesIncrementalHandleReset(Handle, 0i64, 0i64, 0i64, 0i64, MES_ENCODE);
    if ( v9 )
    {
      v5 = I_RpcMapWin32Status(v9);
    }
    else
    {
      NdrMesTypeEncode3(Handle, &pPicklingInfo, &pProxyInfo, (const unsigned int **)&ArrTypeOffset, 1u, &Operation);
      *a2 = v6;
      *a3 = v7;
      v6 = 0i64;
    }
  }
  if ( v6 )
    (*(void (__fastcall **)(unsigned __int8 *))(LsaTable + 48))(v6);
  if ( Handle )
    MesHandleFree(Handle);
  return v5;
}
// 180092620: using guessed type __int64 LsaTable;
