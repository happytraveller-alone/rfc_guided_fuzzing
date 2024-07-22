//----- (0000000180010674) ----------------------------------------------------
__int64 __fastcall CSslCredManager::CreateCredentialGroup(
        CSslCredManager *this,
        struct CCredentialGroup **a2,
        __int64 a3,
        struct _LUID *a4,
        void *a5,
        struct LSA_SCHANNEL_CRED *a6,
        unsigned __int16 *a7)
{
  unsigned int v9; // r13d
  CCredentialGroup *v11; // rax
  CCredentialGroup *v12; // rax
  struct CCredentialGroup *v13; // rdi
  unsigned int v14; // ebx
  CSslCredManager **v15; // rdx
  CSslCredManager *v16; // rax
  __int64 v18; // r8
  unsigned int v19; // ebp
  CCipherMill *v20; // rcx
  unsigned int v21; // edi
  __int64 v22; // rsi
  int v23; // r9d
  int v24; // r9d
  int v25; // r9d
  CCipherMill *v26; // rcx
  __int64 v27; // r9
  __int64 v28; // r9
  struct LSA_SCHANNEL_CRED *v29; // [rsp+20h] [rbp-38h]

  v9 = a3;
  if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
    goto LABEL_2;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 15i64, &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x10u,
        (__int64)&WPP_d7209deee65a328fe195e0fa91b71573_Traceguids,
        *(_DWORD *)a6);
  }
  DbgDumpSubCreds(*((struct LSA_SCHANNEL_SUB_CRED **)a6 + 1), *((_DWORD *)a6 + 1), a3);
  v19 = *((_DWORD *)a6 + 14);
  if ( v19 && *((_QWORD *)a6 + 8) )
  {
    v20 = WPP_GLOBAL_Control;
    v21 = 0;
    v22 = 0i64;
    do
    {
      if ( v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v20 + 28) & 4) != 0 )
      {
        LODWORD(v29) = *(_DWORD *)(v22 + *((_QWORD *)a6 + 8));
        WPP_SF_dD(*((_QWORD *)v20 + 2), 0x11u, v18, v21, v29);
        v20 = WPP_GLOBAL_Control;
      }
      ++v21;
      v22 += 4i64;
    }
    while ( v21 < v19 );
  }
  else
  {
    v20 = WPP_GLOBAL_Control;
  }
  if ( v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v20 + 28) & 4) != 0 )
  {
    WPP_SF_D(*((_QWORD *)v20 + 2), 18i64, &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids, *((unsigned int *)a6 + 18));
    v20 = WPP_GLOBAL_Control;
  }
  v23 = *((_DWORD *)a6 + 19);
  if ( v23 && v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v20 + 28) & 4) != 0 )
  {
    WPP_SF_d(*((_QWORD *)v20 + 2), 0x13u, (__int64)&WPP_d7209deee65a328fe195e0fa91b71573_Traceguids, v23);
    v20 = WPP_GLOBAL_Control;
  }
  v24 = *((_DWORD *)a6 + 20);
  if ( v24 && v20 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v20 + 28) & 4) != 0 )
    WPP_SF_d(*((_QWORD *)v20 + 2), 0x14u, (__int64)&WPP_d7209deee65a328fe195e0fa91b71573_Traceguids, v24);
  DbgDumpTlsParams(*((struct _TLS_PARAMETERS **)a6 + 13), *((unsigned int *)a6 + 24), v18);
  v25 = *((_DWORD *)a6 + 21);
  if ( v25 )
  {
    v26 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      goto LABEL_37;
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x15u, (__int64)&WPP_d7209deee65a328fe195e0fa91b71573_Traceguids, v25);
  }
  v26 = WPP_GLOBAL_Control;
LABEL_37:
  v27 = *((unsigned int *)a6 + 22);
  if ( (_DWORD)v27 && v26 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v26 + 28) & 4) != 0 )
  {
    WPP_SF_D(*((_QWORD *)v26 + 2), 22i64, &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids, v27);
    v26 = WPP_GLOBAL_Control;
  }
  v28 = *((unsigned int *)a6 + 23);
  if ( (_DWORD)v28 && v26 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v26 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v26 + 2), 23i64, &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids, v28);
LABEL_2:
  v11 = (CCredentialGroup *)SPExternalAlloc(0x388u);
  if ( v11 && (v12 = CCredentialGroup::CCredentialGroup(v11), (v13 = v12) != 0i64) )
  {
    v14 = CCredentialGroup::InitializeCredentialGroup(v12, v9, a4, (__int64)a5, a6, a7);
    if ( v14 )
    {
      (*(void (__fastcall **)(struct CCredentialGroup *, __int64))(*(_QWORD *)v13 + 8i64))(v13, 1i64);
    }
    else
    {
      RtlEnterCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
      v15 = (CSslCredManager **)*((_QWORD *)this + 7);
      v16 = (struct CCredentialGroup *)((char *)v13 + 8);
      if ( *v15 != (CSslCredManager *)((char *)this + 48) )
        __fastfail(3u);
      *(_QWORD *)v16 = (char *)this + 48;
      *((_QWORD *)v13 + 2) = v15;
      *v15 = v16;
      *((_QWORD *)this + 7) = v16;
      RtlLeaveCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
      _InterlockedIncrement((volatile signed __int32 *)v13 + 6);
      *a2 = v13;
    }
  }
  else
  {
    return 14;
  }
  return v14;
}
// 180039487: variable 'a3' is possibly undefined
// 1800394CE: variable 'v18' is possibly undefined
// 1800394CE: variable 'v29' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

