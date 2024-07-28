//----- (0000000180043650) ----------------------------------------------------
__int64 __fastcall QueryCredAttributesRpc(struct CCredentialGroup *a1, int a2, _QWORD *a3)
{
  __int64 result; // rax
  int v7; // eax
  CCipherMill *v8; // rcx
  unsigned int v9; // eax
  int v10; // ebx
  size_t v11; // rsi
  void *v12; // rax
  HLOCAL v13; // rbx
  __int64 v14; // rax
  size_t v15; // rsi
  void *v16; // rax
  char v17[56]; // [rsp+20h] [rbp-38h] BYREF
  HLOCAL hMem; // [rsp+60h] [rbp+8h] BYREF
  void *Src; // [rsp+78h] [rbp+20h] BYREF

  Src = 0i64;
  LODWORD(hMem) = 0;
  if ( !a1 )
    return 2148074241i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v17) )
    return 2148074244i64;
  if ( !a3 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 14i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
    return 2148074333i64;
  }
  switch ( a2 )
  {
    case 1:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      hMem = 0i64;
      result = CCredentialGroup::GetNameFromFirstCred(a1, (unsigned __int16 **)&hMem);
      if ( !(_DWORD)result )
      {
        v13 = hMem;
        v14 = -1i64;
        do
          ++v14;
        while ( *((_WORD *)hMem + v14) );
        v15 = (unsigned int)(2 * v14 + 2);
        v16 = (void *)(*(__int64 (**)(void))(LsaTable + 384))();
        *a3 = v16;
        if ( v16 )
        {
          memcpy_0(v16, v13, v15);
          if ( v13 )
            LocalFree(v13);
          return 0i64;
        }
        if ( v13 )
          LocalFree(v13);
        return 2148074240i64;
      }
      break;
    case 86:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      v9 = BuildLegacySupportedAlgsList(a1, (unsigned int **)&Src, (unsigned int *)&hMem);
      result = TranslateToSecurityStatus(v9);
      if ( !(_DWORD)result )
      {
        v10 = (int)hMem;
        v11 = (unsigned int)(4 * (_DWORD)hMem);
        v12 = (void *)(*(__int64 (**)(void))(LsaTable + 384))();
        a3[1] = v12;
        if ( !v12 )
        {
          SPExternalFree(Src);
          return 2148074240i64;
        }
        memcpy_0(v12, Src, v11);
        *(_DWORD *)a3 = v10;
        SPExternalFree(Src);
        return 0i64;
      }
      break;
    case 87:
      v8 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      *(_DWORD *)a3 = *((_DWORD *)a1 + 41);
      *((_DWORD *)a3 + 1) = *((_DWORD *)a1 + 42);
      if ( *((_DWORD *)a1 + 42) )
      {
        if ( !*((_DWORD *)a1 + 41) )
          goto LABEL_29;
      }
      else if ( *((_DWORD *)a1 + 41) )
      {
LABEL_29:
        CCipherMill::GetBaseCipherSizes(v8, v17[8] & 1, (unsigned int *)&Src, (unsigned int *)&hMem);
        if ( !*((_DWORD *)a1 + 42) )
          *((_DWORD *)a3 + 1) = (_DWORD)hMem;
        if ( *((_DWORD *)a1 + 41) )
          return 0i64;
        v7 = (int)Src;
        goto LABEL_33;
      }
      return 0i64;
    case 88:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids);
      v7 = *((_DWORD *)a1 + 38);
LABEL_33:
      *(_DWORD *)a3 = v7;
      return 0i64;
    default:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x13u,
          (__int64)&WPP_d9c5339d4bdb3d03f2cfcf1c7d7ab7b7_Traceguids,
          a2);
      return 2148074242i64;
  }
  return result;
}
// 1800437D7: conditional instruction was optimized away because eax.4!=0
// 1800437F7: variable 'v8' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
