//----- (0000000180041794) ----------------------------------------------------
__int64 __fastcall RemotelySetMtu(struct CSslContext *a1)
{
  int v1; // edi
  unsigned int cbBuffer; // ecx
  _QWORD *v5; // rax
  _WORD *v6; // rcx
  struct _SecBuffer *v7; // r9
  __int64 v8; // rdx
  int v9; // ebx
  struct _SecBuffer v10; // [rsp+40h] [rbp-40h] BYREF
  int v11[2]; // [rsp+50h] [rbp-30h] BYREF
  __int64 v12; // [rsp+58h] [rbp-28h]
  char v13[8]; // [rsp+60h] [rbp-20h] BYREF
  char v14; // [rsp+68h] [rbp-18h]

  v1 = *((unsigned __int8 *)a1 + 266);
  if ( !LsaTable )
    return 87i64;
  v10.cbBuffer = 4;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v13) )
    return 1359i64;
  if ( (v14 & 0x40) != 0 )
  {
    cbBuffer = v10.cbBuffer + 8;
    v10.cbBuffer += 8;
  }
  else
  {
    cbBuffer = v10.cbBuffer;
  }
  v10.BufferType = 1;
  if ( (_BYTE)v1 )
    v5 = (_QWORD *)(*(__int64 (**)(void))(LsaTable + 384))();
  else
    v5 = SPExternalAlloc(cbBuffer);
  v10.pvBuffer = v5;
  v6 = v5;
  if ( !v5 )
    return 14i64;
  if ( (v14 & 0x40) != 0 )
  {
    *v5 = *((_QWORD *)a1 + 16);
    v6 = v5 + 1;
  }
  v7 = (struct _SecBuffer *)v11;
  *v6 = *((_WORD *)a1 + 108);
  v6[1] = *((_WORD *)a1 + 109);
  if ( (_BYTE)v1 )
    v7 = 0i64;
  v8 = *((_QWORD *)a1 + 16);
  v11[1] = 1;
  v11[0] = 0;
  v12 = 0i64;
  v9 = PerformApplicationCallback(8i64, v8, (_BYTE)v1 != 0 ? 8 : 0, &v10, v7, 0, v1, 0);
  if ( v9 < 0
    && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    WPP_SF_D(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      43i64,
      &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
      (unsigned int)v9);
  }
  if ( v10.pvBuffer )
  {
    if ( (_BYTE)v1 )
    {
      if ( v9 < 0 )
        (*(void (**)(void))(LsaTable + 392))();
    }
    else
    {
      SPExternalFree(v10.pvBuffer);
    }
  }
  return (unsigned int)v9;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
// 180041794: using guessed type char var_20[8];

