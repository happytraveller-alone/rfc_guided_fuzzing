// File count: 1372
// Total lines: 75
----------------------------------------
__int64 __fastcall CTls13ServerContext::GenerateResponse(CTls13ServerContext *this, struct SPBuffer *a2)
{
  unsigned int ClientHelloResponse; // edi
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  __int64 v9; // rcx

  ClientHelloResponse = 0;
  v5 = *((_DWORD *)this + 17) - 4;
  if ( v5 )
  {
    v6 = v5 - 89;
    if ( !v6 )
    {
LABEL_17:
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 60i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
      ClientHelloResponse = CTls13ServerContext::GenerateClientHelloResponse(this, a2);
      if ( !ClientHelloResponse )
        *((_DWORD *)this + 17) = 70;
      return ClientHelloResponse;
    }
    v7 = v6 - 5;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 == 3 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 62i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
          }
          ClientHelloResponse = CTls13ServerContext::GenerateNewSessionTicket(this, a2);
          if ( !ClientHelloResponse )
          {
            v9 = *(_QWORD *)this;
            *((_BYTE *)this + 1216) = 3;
            (*(void (__fastcall **)(CTls13ServerContext *))(v9 + 448))(this);
            if ( (*((_DWORD *)this + 34) & 0x400000) == 0 )
              CSessionCacheManager::FinishCacheAddItem(CSessionCacheManager::m_pSessionCacheManager, this);
          }
        }
        return ClientHelloResponse;
      }
      goto LABEL_17;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 61i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
    ClientHelloResponse = CTls13ServerContext::GenerateHelloRetryRequest(this, a2);
    if ( !ClientHelloResponse )
      *((_DWORD *)this + 17) = 71;
  }
  else if ( *((_BYTE *)this + 1506) && (*((_DWORD *)this + 34) & 0x100i64) != 0 )
  {
    if ( *((_BYTE *)this + 1233) && !*((_BYTE *)this + 1232) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 63i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
      return (unsigned int)CTls13ServerContext::GeneratePostHandshakeCertificateRequest(this, a2);
    }
  }
  else
  {
    return 590688;
  }
  return ClientHelloResponse;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
