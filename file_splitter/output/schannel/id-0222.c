//----- (0000000180012E50) ----------------------------------------------------
__int64 __fastcall RemotelyGetUserKeys(struct CSslContext *a1, unsigned int a2)
{
  int v2; // edi
  unsigned int v3; // esi
  unsigned __int8 **v5; // rax
  int v6; // eax
  unsigned int v7; // ebx
  void *v9; // rax
  struct _SecBuffer Size; // [rsp+40h] [rbp-40h] BYREF
  unsigned __int8 *v11[2]; // [rsp+50h] [rbp-30h] BYREF
  char v12[32]; // [rsp+60h] [rbp-20h] BYREF

  v2 = *((unsigned __int8 *)a1 + 266);
  v3 = a2 | 8;
  *(_OWORD *)v11 = 0i64;
  if ( !(_BYTE)v2 )
    v3 = a2;
  if ( !LsaTable )
    return 87i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v12) )
    return 1359i64;
  Size.BufferType = 1;
  if ( (v12[8] & 0x40) != 0 )
  {
    Size.cbBuffer = 8;
    if ( (_BYTE)v2 )
    {
      v9 = (void *)(*(__int64 (__fastcall **)(__int64))(LsaTable + 384))(8i64);
      Size.pvBuffer = v9;
      if ( !v9 )
        return 14i64;
      memcpy_0(v9, (char *)a1 + 128, Size.cbBuffer);
    }
    else
    {
      Size.pvBuffer = (char *)a1 + 128;
    }
  }
  else
  {
    Size.cbBuffer = 0;
    Size.pvBuffer = 0i64;
  }
  v5 = v11;
  if ( (_BYTE)v2 )
    v5 = 0i64;
  v6 = PerformApplicationCallback(7i64, *((_QWORD *)a1 + 16), v3, &Size, (struct _SecBuffer *)v5, (_BYTE)v2 == 0, v2, 1);
  if ( v6 < 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        28i64,
        &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
        (unsigned int)v6);
    v7 = -2146893052;
    if ( (_BYTE)v2 && Size.pvBuffer )
      (*(void (**)(void))(LsaTable + 392))();
  }
  else if ( (_BYTE)v2 )
  {
    v7 = 590610;
  }
  else
  {
    v7 = ParseKeyBuffer(a1, v3, v11[1], (unsigned int)v11[0]);
  }
  if ( v11[1] )
    SPExternalFree(v11[1]);
  return v7;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

