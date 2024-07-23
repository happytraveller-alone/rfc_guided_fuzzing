//----- (0000000180017660) ----------------------------------------------------
__int64 __fastcall SpQueryCredentialsAttributes(struct CCredentialGroup *a1, int a2, _QWORD *a3)
{
  int v6; // r14d
  unsigned int v7; // ebx
  __int64 result; // rax
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // eax
  CCipherMill *v13; // rcx
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // edi
  unsigned int v19; // r15d
  int v20; // esi
  int v21; // edi
  HLOCAL v22; // rdi
  __int64 v23; // rax
  unsigned int v24; // r15d
  int v25; // esi
  int v26; // esi
  __int64 v27; // [rsp+30h] [rbp-58h] BYREF
  __int64 v28[2]; // [rsp+38h] [rbp-50h] BYREF
  __int64 v29; // [rsp+48h] [rbp-40h] BYREF
  int v30; // [rsp+50h] [rbp-38h]
  HLOCAL hMem; // [rsp+90h] [rbp+8h] BYREF
  unsigned int *v32; // [rsp+A8h] [rbp+20h] BYREF

  v32 = 0i64;
  LODWORD(hMem) = 0;
  v27 = 0i64;
  if ( !a1 )
    return 2148074241i64;
  if ( !(*(unsigned __int8 (__fastcall **)(__int64 *))(LsaTable + 192))(&v29) )
    return 2148074244i64;
  if ( (v30 & 0x10000) != 0 )
    return QueryCredAttributesRpc(a1, a2, a3);
  v6 = v30 & 0x40;
  switch ( a2 )
  {
    case 1:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 23i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      v7 = v6 != 0 ? 4 : 8;
      break;
    case 86:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 20i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      v7 = v6 != 0 ? 8 : 16;
      break;
    case 87:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 21i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      v7 = 8;
      break;
    case 88:
      v7 = 4;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 22i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      break;
    default:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x18u,
          (__int64)&WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids,
          a2);
      return 2148074242i64;
  }
  result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *, _QWORD *))(LsaTable + 80))(0i64, v7, v28, a3);
  if ( (int)result < 0 )
    return result;
  v9 = a2 - 1;
  if ( v9 )
  {
    v10 = v9 - 85;
    if ( !v10 )
    {
      v17 = BuildLegacySupportedAlgsList(a1, &v32, (unsigned int *)&hMem);
      result = TranslateToSecurityStatus(v17);
      if ( (_DWORD)result )
        return result;
      v18 = (int)hMem;
      v19 = 4 * (_DWORD)hMem;
      v20 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(
              0i64,
              (unsigned int)(4 * (_DWORD)hMem),
              &v27);
      if ( v20 < 0 )
      {
        SPExternalFree(v32);
        return (unsigned int)v20;
      }
      LODWORD(v28[0]) = v18;
      if ( v6 )
        HIDWORD(v28[0]) = v27;
      else
        v28[1] = v27;
      v21 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, unsigned int *))(LsaTable + 72))(0i64, v19, v27, v32);
      SPExternalFree(v32);
      if ( v21 < 0 )
      {
        (*(void (__fastcall **)(_QWORD, __int64))(LsaTable + 64))(0i64, v27);
        return (unsigned int)v21;
      }
      goto LABEL_17;
    }
    v11 = v10 - 1;
    if ( v11 )
    {
      if ( v11 != 1 )
        goto LABEL_17;
      v15 = *((_DWORD *)a1 + 38);
    }
    else
    {
      v12 = *((_DWORD *)a1 + 41);
      LODWORD(v28[0]) = v12;
      v13 = (CCipherMill *)*((unsigned int *)a1 + 42);
      HIDWORD(v28[0]) = (_DWORD)v13;
      if ( (_DWORD)v13 )
      {
        if ( v12 )
          goto LABEL_17;
      }
      else if ( !v12 )
      {
        goto LABEL_17;
      }
      CCipherMill::GetBaseCipherSizes(v13, v30 & 1, (unsigned int *)&v32, (unsigned int *)&hMem);
      v16 = HIDWORD(v28[0]);
      if ( !*((_DWORD *)a1 + 42) )
        v16 = (int)hMem;
      HIDWORD(v28[0]) = v16;
      if ( *((_DWORD *)a1 + 41) )
        goto LABEL_17;
      v15 = (int)v32;
    }
    LODWORD(v28[0]) = v15;
LABEL_17:
    v14 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD *, __int64 *))(LsaTable + 72))(0i64, v7, a3, v28);
    if ( v14 >= 0 )
      return 0i64;
    if ( v27 )
      (*(void (__fastcall **)(_QWORD))(LsaTable + 64))(0i64);
    return (unsigned int)v14;
  }
  hMem = 0i64;
  result = CCredentialGroup::GetNameFromFirstCred(a1, (unsigned __int16 **)&hMem);
  if ( (_DWORD)result )
    return result;
  v22 = hMem;
  v23 = -1i64;
  do
    ++v23;
  while ( *((_WORD *)hMem + v23) );
  v24 = 2 * v23 + 2;
  v25 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(0i64, v24, &v27);
  if ( v25 >= 0 )
  {
    if ( v6 )
      LODWORD(v28[0]) = v27;
    else
      v28[0] = v27;
    if ( !v27
      || (v26 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, HLOCAL))(LsaTable + 72))(0i64, v24, v27, v22),
          v26 >= 0) )
    {
      if ( v22 )
        LocalFree(v22);
      goto LABEL_17;
    }
    (*(void (__fastcall **)(_QWORD, __int64))(LsaTable + 64))(0i64, v27);
    if ( v22 )
      LocalFree(v22);
    return (unsigned int)v26;
  }
  else
  {
    if ( v22 )
      LocalFree(v22);
    return (unsigned int)v25;
  }
}
// 1800178F3: conditional instruction was optimized away because ecx.4!=0
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

