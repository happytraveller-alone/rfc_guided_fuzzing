//----- (000000018006FF64) ----------------------------------------------------
void __fastcall CTlsMessageFragment::Initialize(CTlsMessageFragment *this, struct CSsl3TlsContext *a2)
{
  int v2; // eax
  int v3; // edx
  unsigned int v4; // edx
  unsigned int v5; // eax

  *(_QWORD *)this = a2;
  if ( (*((_DWORD *)a2 + 16) & 0x40051555) != 0 )
  {
    v2 = *((_DWORD *)a2 + 34);
    v3 = 256;
    if ( (v2 & 0x100) == 0 )
    {
      *((_DWORD *)this + 2) = CSslGlobals::m_dwTlsMessageLimitSrv;
      goto LABEL_9;
    }
    v4 = CSslGlobals::m_dwTlsMessageLimitSrvClientAuth;
    if ( CSslGlobals::m_dwTlsMessageLimitSrv > CSslGlobals::m_dwTlsMessageLimitSrvClientAuth )
      v4 = CSslGlobals::m_dwTlsMessageLimitSrv;
    *((_DWORD *)this + 2) = v4;
  }
  else
  {
    *((_DWORD *)this + 2) = CSslGlobals::m_dwTlsMessageLimitClient;
  }
  v3 = 1536;
LABEL_9:
  *((_DWORD *)this + 3) = v3;
  v5 = *((_DWORD *)this + 2);
  if ( v5 > 0xFFFFFF )
    v5 = 0xFFFFFF;
  *((_DWORD *)this + 2) = v5;
}

