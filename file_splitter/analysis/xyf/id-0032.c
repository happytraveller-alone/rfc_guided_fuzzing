//----- (00000001800030F0) ----------------------------------------------------
__int64 __fastcall SpFreeCredentialsHandle(struct CCredentialGroup *a1, __int64 a2, __int64 a3)
{
  int v4; // edi
  CCipherMill *v5; // rcx
  char v6; // al
  unsigned int v7; // eax
  __int64 v8; // rcx
  __int64 v9; // r8
  __int128 v11; // [rsp+30h] [rbp-48h] BYREF
  char v12[8]; // [rsp+40h] [rbp-38h] BYREF
  int v13; // [rsp+48h] [rbp-30h]
  char v14[16]; // [rsp+58h] [rbp-20h] BYREF

  v4 = 8;
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McTemplateU0p_EtwEventWriteTransfer((__int64)a1, a2, (__int64)a1);
  v5 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x43u, (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids, a1);
  if ( a1 )
  {
    CSessionCacheManager::PurgeCacheForCredentialGroup(CSessionCacheManager::m_pSessionCacheManager, a1);
    if ( (*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v12) )
    {
      v6 = v13;
      if ( (v13 & 0x20) != 0 )
      {
        CSessionCacheManager::PurgeCacheForProcessId(CSessionCacheManager::m_pSessionCacheManager, *((_DWORD *)a1 + 53));
        v6 = v13;
      }
      if ( (v6 & 0x40) != 0 )
        v4 = 4;
    }
    v7 = *((_DWORD *)a1 + 184);
    if ( v7 > 1 )
    {
      v11 = 2 * v4 * v7;
      *((_QWORD *)&v11 + 1) = (*(__int64 (**)(void))(LsaTable + 384))();
      if ( *((_QWORD *)&v11 + 1) )
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int128 *, _BYTE))(LsaTable + 496))(5i64, 0i64, 0i64, &v11, 0);
    }
    CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, a1);
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EtwEventWriteTransfer(v8, (__int64)&FchStop, v9, 1, (__int64)v14);
    return 0i64;
  }
  else
  {
    if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
      McGenEventWrite_EtwEventWriteTransfer((__int64)v5, (__int64)&FchStop, a3, 1, (__int64)v14);
    return 2148074241i64;
  }
}
// 180003262: variable 'v8' is possibly undefined
// 180003262: variable 'v9' is possibly undefined
// 18002CA46: variable 'v5' is possibly undefined
// 18002CA46: variable 'a3' is possibly undefined
// 180092620: using guessed type __int64 LsaTable;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
// 1800030F0: using guessed type char var_38[8];

