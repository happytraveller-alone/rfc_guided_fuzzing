//----- (000000018006049C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::CheckForClientCred(CSsl3TlsClientContext *this)
{
  __int64 v1; // rax
  unsigned int v3; // esi
  unsigned int v4; // r15d
  int *v5; // r14
  CCipherMill *v7; // rcx
  __int64 v8; // rdx
  unsigned int v9; // esi
  CCipherMill *v10; // rcx
  __int64 v11; // rdx
  unsigned int v12; // r11d
  void *v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // r8
  int v16; // [rsp+20h] [rbp-20h]
  void *v17[2]; // [rsp+30h] [rbp-10h] BYREF
  struct CSslCredential *v18; // [rsp+80h] [rbp+40h] BYREF
  __int64 v19; // [rsp+88h] [rbp+48h] BYREF
  __int64 v20; // [rsp+90h] [rbp+50h] BYREF

  v1 = *((_QWORD *)this + 10);
  *((_BYTE *)this + 923) = 0;
  *((_BYTE *)this + 1314) = 0;
  if ( !*(_DWORD *)(v1 + 28) )
  {
    if ( (unsigned int)AcquireDefaultClientCredential(this, (*(_DWORD *)(v1 + 156) >> 3) & 1) || !*((_BYTE *)this + 266) )
      goto LABEL_8;
    *(_OWORD *)v17 = 0i64;
    LODWORD(v18) = 0;
    v19 = 0i64;
    v20 = 0i64;
    v9 = (*(__int64 (__fastcall **)(struct CSslCredential **, __int64 *, __int64 *, void **, _QWORD))(LsaTable + 488))(
           &v18,
           &v20,
           &v19,
           v17,
           0i64);
    if ( v9 )
    {
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return v9;
      v11 = 56i64;
    }
    else
    {
      v12 = (unsigned int)v18;
      if ( (_DWORD)v18 != 4 )
      {
        v7 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          v8 = 59i64;
LABEL_37:
          WPP_SF_(*((_QWORD *)v7 + 2), v8, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        }
        return 0i64;
      }
      if ( *((_DWORD *)this + 17) != 91 && *((_DWORD *)this + 17) != 101 )
      {
        CSsl3TlsClientContext::SetActiveClientCred(this, 0i64, 0);
        CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 0);
        v13 = v17[1];
        *((_BYTE *)this + 1314) = 1;
        CleanupAppModeInfo(v13);
        goto LABEL_8;
      }
      v14 = 1i64;
      *((_BYTE *)this + 923) = 1;
      v20 = 1i64;
      v15 = 0i64;
      v19 = 0i64;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 57i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
        v12 = (unsigned int)v18;
        v15 = v19;
        v14 = v20;
      }
      LOBYTE(v16) = 1;
      v9 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, void **, int))(LsaTable + 496))(v12, v14, v15, v17, v16);
      if ( !v9 )
        goto LABEL_8;
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return v9;
      v11 = 58i64;
    }
    WPP_SF_D(*((_QWORD *)v10 + 2), v11, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids, v9);
    return v9;
  }
  v3 = 0;
  if ( *((_WORD *)this + 673) )
  {
LABEL_3:
    v4 = 0;
    v5 = (int *)&unk_18007D758;
    while ( *((_DWORD *)this + v3 + 337) != v5[1]
         || (unsigned int)CCredentialGroup::PickClientCredential(
                            *((CCredentialGroup **)this + 10),
                            *v5,
                            *((_DWORD *)this + 16),
                            (struct CTlsSignatureSuiteList *)(((unsigned __int64)this + 510) & -(__int64)((*((_DWORD *)this + 16) & 0x82800) != 0)),
                            &v18) )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= 8 )
      {
        if ( ++v3 < *((unsigned __int16 *)this + 673) )
          goto LABEL_3;
        goto LABEL_8;
      }
    }
    CSsl3TlsClientContext::SetActiveClientCred(this, v18, 0);
    v7 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v8 = 55i64;
      goto LABEL_37;
    }
    return 0i64;
  }
LABEL_8:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
  return ~(*((_DWORD *)this + 34) << 21) & 0x80000000 | 0x90320;
}
// 180060744: variable 'v16' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
