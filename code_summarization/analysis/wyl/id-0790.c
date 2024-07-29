//----- (0000000180040EA4) ----------------------------------------------------
__int64 __fastcall RemotelyCloseClientKeyHandle(__int64 a1, __int64 a2, int a3)
{
  int v6; // r14d
  CCipherMill *v7; // rcx
  unsigned __int64 v8; // rax
  unsigned int v9; // ebx
  _DWORD *v10; // rdx
  __int64 v11; // r8
  _DWORD *v12; // r9
  unsigned __int64 v13; // rcx
  __int64 v14; // rdx
  CCipherMill *v15; // rcx
  __int64 v16; // rax
  unsigned int v17; // ebx
  int v18; // eax
  __int64 v19; // [rsp+20h] [rbp-50h]
  __int64 v20; // [rsp+30h] [rbp-40h] BYREF
  __int128 v21; // [rsp+38h] [rbp-38h] BYREF
  int v22[2]; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v23; // [rsp+50h] [rbp-20h]
  char v24[24]; // [rsp+58h] [rbp-18h] BYREF
  int v25; // [rsp+B0h] [rbp+40h] BYREF
  int v26; // [rsp+B8h] [rbp+48h] BYREF

  v25 = a3;
  v26 = 0;
  v20 = 0i64;
  LOBYTE(v25) = 0;
  v21 = 0i64;
  if ( !LsaTable )
    return 87i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v24) )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x14u,
        (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
        -1073741595,
        -1073741595);
    return 3221225701i64;
  }
  v6 = v24[8] & 0x40;
  v7 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 21i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
      v7 = WPP_GLOBAL_Control;
    }
    if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)v7 + 2), 22i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
        v7 = WPP_GLOBAL_Control;
      }
      if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v7 + 28) & 4) != 0 )
        {
          WPP_SF_q(*((_QWORD *)v7 + 2), 0x17u, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, a1);
          v7 = WPP_GLOBAL_Control;
        }
        if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 4) != 0 )
          WPP_SF_q(*((_QWORD *)v7 + 2), 0x18u, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, a2);
      }
    }
  }
  if ( (*(int (__fastcall **)(int *, __int64 *, _QWORD, __int128 *, int *))(LsaTable + 488))(
         &v26,
         &v20,
         0i64,
         &v21,
         &v25) < 0 )
    return 1359i64;
  v22[1] = 1;
  v8 = (unsigned int)v21;
  v9 = v6 != 0 ? 8 : 16;
  if ( (_DWORD)v21 )
  {
    v10 = (_DWORD *)*((_QWORD *)&v21 + 1);
  }
  else
  {
    LODWORD(v21) = v6 != 0 ? 8 : 16;
    *((_QWORD *)&v21 + 1) = (*(__int64 (__fastcall **)(_QWORD))(LsaTable + 384))(v9);
    v10 = (_DWORD *)*((_QWORD *)&v21 + 1);
    if ( !*((_QWORD *)&v21 + 1) )
      return 14i64;
    v8 = (unsigned int)v21;
  }
  v11 = v20;
  v12 = v10;
  v23 = v10;
  v22[0] = v8;
  if ( v20 )
  {
    if ( v8 >= (unsigned __int64)v9 * (v20 + 1) )
    {
      v10 = (_DWORD *)((char *)v10 + v20 * v9);
      goto LABEL_29;
    }
    return 1359i64;
  }
LABEL_29:
  if ( v6 )
    *v10 = a1;
  else
    *(_QWORD *)v10 = a1;
  v13 = -(__int64)(v6 != 0) & 0xFFFFFFFFFFFFFFFCui64;
  if ( v6 )
    *(_DWORD *)((char *)v10 + v13 + 8) = a2;
  else
    *(_QWORD *)((char *)v10 + v13 + 8) = a2;
  v14 = ++v20;
  v15 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
    v14 = v20;
    v15 = WPP_GLOBAL_Control;
  }
  v16 = LsaTable;
  if ( !LsaTable )
  {
    v17 = -2146893052;
LABEL_45:
    if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 1) != 0 )
    {
      WPP_SF_D(*((_QWORD *)v15 + 2), 26i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v17);
      v16 = LsaTable;
    }
    (*(void (__fastcall **)(_DWORD *, __int64, __int64, _DWORD *))(v16 + 392))(v23, v14, v11, v12);
    goto LABEL_49;
  }
  LOBYTE(v19) = 0;
  v18 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, int *, _DWORD))(LsaTable + 496))(5i64, v14, 0i64, v22, v19);
  v17 = v18;
  if ( v18 < 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        10i64,
        &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
        (unsigned int)v18);
    CleanupAppModeInfo(0i64);
    v16 = LsaTable;
    v15 = WPP_GLOBAL_Control;
    goto LABEL_45;
  }
LABEL_49:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v17 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    LODWORD(v19) = v17;
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x1Bu,
      (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
      v17,
      v19);
  }
  return v17;
}
// 18004115D: variable 'v19' is possibly undefined
// 1800411DF: variable 'v14' is possibly undefined
// 1800411DF: variable 'v11' is possibly undefined
// 1800411DF: variable 'v12' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

