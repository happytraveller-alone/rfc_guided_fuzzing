// File count: 1232
// Total lines: 112
---------------------------------------
__int64 __fastcall CSsl3TlsServerContext::DigestUnifiedHello(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        __int64 a3)
{
  ULONG RandomBits; // ebx
  int v5; // eax
  unsigned int *v6; // rsi
  unsigned __int8 v7; // r9
  int v8; // edx
  unsigned int v9; // edx
  HLOCAL Memory; // rax
  __int64 v11; // rcx
  int NewServerItem; // ebx
  __int64 v13; // rcx
  int v15; // [rsp+30h] [rbp-50h] BYREF
  struct _Ssl2_Client_Hello *v16; // [rsp+38h] [rbp-48h] BYREF
  int v17; // [rsp+40h] [rbp-40h] BYREF
  int v18; // [rsp+44h] [rbp-3Ch]
  unsigned __int8 *v19; // [rsp+48h] [rbp-38h]
  UCHAR pbBuffer[16]; // [rsp+50h] [rbp-30h] BYREF
  __int128 v21; // [rsp+60h] [rbp-20h]

  v16 = 0i64;
  v15 = 0;
  *(_OWORD *)pbBuffer = 0i64;
  v21 = 0i64;
  if ( (unsigned int)a3 < 2 )
  {
    RandomBits = -2146893018;
    CSslContext::SetErrorAndFatalAlert((__int64)this, 1203, -2146893018, 0x32u);
    return RandomBits;
  }
  v19 = a2;
  v18 = a3;
  v17 = a3;
  v5 = Ssl2UnpackClientHello((struct SPBuffer *)&v17, &v16, a3, &v15);
  v6 = (unsigned int *)v16;
  RandomBits = v5;
  if ( v5 )
  {
    v7 = 10;
    v8 = 1203;
    goto LABEL_20;
  }
  if ( v15 )
  {
    *((_BYTE *)this + 553) = 1;
    goto LABEL_7;
  }
  if ( g_fAllowInsecureRenegoClients )
  {
LABEL_7:
    if ( *((_QWORD *)this + 110) )
    {
      (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 16i64))(this);
      *((_QWORD *)this + 110) = 0i64;
    }
    v9 = v18 - 2;
    *((_DWORD *)this + 218) = v18 - 2;
    Memory = CSslContext::GetMemory(this, v9);
    *((_QWORD *)this + 110) = Memory;
    if ( !Memory )
      goto LABEL_10;
    memcpy_0(Memory, v19 + 2, *((unsigned int *)this + 218));
    memset_0((char *)this + 272, 0, 32 - v6[3]);
    memcpy_0((char *)this - v6[3] + 304, v6 + 12, v6[3]);
    RandomBits = GenerateRandomBits(pbBuffer, 0x20u);
    if ( RandomBits )
      goto LABEL_21;
    CSessionCacheManager::AcquireCacheTableLock(v11, 0i64, pbBuffer);
    NewServerItem = CSessionCacheManager::CacheRetrieveNewServerItem(
                      CSessionCacheManager::m_pSessionCacheManager,
                      *((_DWORD *)this + 16),
                      pbBuffer,
                      (struct CSessionCacheServerItem **)this + 124);
    CSessionCacheManager::ReleaseCacheTableLock(v13, 0i64, pbBuffer);
    if ( NewServerItem )
    {
LABEL_10:
      RandomBits = -2146893056;
      goto LABEL_21;
    }
    *((_QWORD *)this + 11) = *((_QWORD *)this + 124);
    v5 = CCipherMill::ChooseServerCipher((CCipherMill *)g_cCipherMill, this, v6 + 20, v6[1], *((_DWORD *)this + 16), 0);
    RandomBits = v5;
    if ( !v5 )
    {
LABEL_21:
      if ( v6 )
        SPExternalFree(v6);
      return RandomBits;
    }
    v7 = 40;
    v8 = 1204;
LABEL_20:
    CSslContext::SetErrorAndFatalAlert((__int64)this, v8, v5, v7);
    goto LABEL_21;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 49i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
  RandomBits = -2146892986;
  CSslContext::SetErrorAndFatalAlert((__int64)this, 1207, -2146892986, 0x28u);
  *((_DWORD *)this + 17) = 96;
  *((_WORD *)this + 48) = 10242;
  return RandomBits;
}
// 1800625E7: variable 'v11' is possibly undefined
// 180062611: variable 'v13' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800919AC: using guessed type int g_fAllowInsecureRenegoClients;
