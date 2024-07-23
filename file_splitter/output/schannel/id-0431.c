// File count: 431
// Total lines: 88
-----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::GenerateResponse(CSsl3TlsServerContext *this, struct SPBuffer *a2)
{
  int v2; // eax
  unsigned int Restart; // esi
  __int64 v7; // rax
  __int64 *v8; // r14
  CSessionCacheManager *v9; // r15
  __int64 v10; // rbp
  __int64 v11; // r9
  unsigned int v12; // eax
  unsigned int v13; // r8d
  __int64 v14; // rax

  v2 = *((_DWORD *)this + 17);
  Restart = 0;
  switch ( v2 )
  {
    case 94:
      Restart = CSsl3TlsServerContext::GenerateRestart(this, a2);
      if ( !Restart )
        *((_DWORD *)this + 17) = 64;
      break;
    case 93:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      Restart = CSsl3TlsServerContext::GenerateClientHelloResponse(this, a2);
      if ( !Restart )
        *((_DWORD *)this + 17) = 70;
      break;
    case 4:
      if ( CSslGlobals::m_fDisableRenegoOnServer )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 26i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
        return (unsigned int)-2146893018;
      }
      else
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
        return (unsigned int)CSsl3TlsServerContext::GenerateHelloRequest(this, a2);
      }
    case 95:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 24i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
      Restart = CSsl3TlsServerContext::AllocateAndGenerateNstCcsAndFinish(this, a2);
      if ( !Restart )
      {
        (*(void (__fastcall **)(CSsl3TlsServerContext *))(*(_QWORD *)this + 448i64))(this);
        v7 = *((_QWORD *)this + 17);
        if ( (v7 & 0x400000) == 0 && (v7 & 0x8000000) != 0 )
        {
          v8 = (__int64 *)*((_QWORD *)this + 11);
          v9 = CSessionCacheManager::m_pSessionCacheManager;
          if ( v8 )
          {
            v10 = *((_QWORD *)this + 10);
            if ( v10 )
            {
              RtlAcquireResourceExclusive((PRTL_RESOURCE)(v8[28] + 48), 1u);
              RtlAcquireResourceExclusive((PRTL_RESOURCE)(v8 + 9), 1u);
              v12 = *(_DWORD *)(v10 + 208);
              v13 = *((_DWORD *)v8 + 70);
              *((_BYTE *)v8 + 236) = 1;
              if ( v12 < v13 )
                v13 = v12;
              v14 = *v8;
              *((_DWORD *)v8 + 70) = v13;
              LOBYTE(v11) = 1;
              (*(void (__fastcall **)(__int64 *, CSessionCacheManager *, CSsl3TlsServerContext *, __int64))(v14 + 64))(
                v8,
                v9,
                this,
                v11);
              RtlReleaseResource((PRTL_RESOURCE)(v8 + 9));
              RtlReleaseResource((PRTL_RESOURCE)(v8[28] + 48));
            }
          }
        }
      }
      break;
  }
  return Restart;
}
// 180019518: variable 'v11' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 1800927C0: using guessed type int CSslGlobals::m_fDisableRenegoOnServer;
