//----- (0000000180041244) ----------------------------------------------------
__int64 __fastcall RemotelyGetAppDataStatus(struct CSsl3TlsContext *a1)
{
  int v1; // edi
  void *v4; // rax
  void **v5; // rcx
  int v6; // ebx
  struct _SecBuffer Size; // [rsp+40h] [rbp-40h] BYREF
  void *v8[2]; // [rsp+50h] [rbp-30h] BYREF
  char v9[32]; // [rsp+60h] [rbp-20h] BYREF

  v1 = *((unsigned __int8 *)a1 + 266);
  *(_OWORD *)v8 = 0i64;
  if ( !LsaTable )
    return 87i64;
  Size.pvBuffer = 0i64;
  *(_QWORD *)&Size.cbBuffer = 0x100000000i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v9) )
    return 1359i64;
  if ( (v9[8] & 0x40) != 0 )
  {
    Size.cbBuffer = 8;
    if ( (_BYTE)v1 )
    {
      v4 = (void *)(*(__int64 (__fastcall **)(__int64))(LsaTable + 384))(8i64);
      Size.pvBuffer = v4;
      if ( !v4 )
        return 14i64;
      memcpy_0(v4, (char *)a1 + 128, Size.cbBuffer);
    }
    else
    {
      Size.pvBuffer = (char *)a1 + 128;
    }
  }
  v5 = v8;
  if ( (_BYTE)v1 )
    v5 = 0i64;
  v6 = PerformApplicationCallback(
         9i64,
         *((_QWORD *)a1 + 16),
         -(__int64)((_BYTE)v1 != 0) & 8,
         &Size,
         (struct _SecBuffer *)v5,
         (_BYTE)v1 == 0,
         v1,
         1);
  if ( v6 >= 0 )
  {
    if ( (_BYTE)v1 )
    {
      v6 = 590610;
    }
    else if ( LODWORD(v8[0]) )
    {
      v6 = 0;
      *((_BYTE *)a1 + 472) = *(_BYTE *)v8[1];
    }
    else
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 45i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
      v6 = 87;
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        44i64,
        &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
        (unsigned int)v6);
    if ( (_BYTE)v1 && Size.pvBuffer )
      (*(void (**)(void))(LsaTable + 392))();
  }
  if ( v8[1] )
    SPExternalFree(v8[1]);
  return (unsigned int)v6;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
