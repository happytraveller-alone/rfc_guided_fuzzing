//----- (0000000180012458) ----------------------------------------------------
void __fastcall CSchannelTelemetryContext::LogKeyExchange(CSchannelTelemetryContext *this, int a2, int a3)
{
  struct kexch *KeyExchangeInfo; // rax
  _DWORD *v4; // r9
  int v5; // r10d
  int v6; // r11d

  if ( this )
  {
    if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
    {
      *((_DWORD *)this + 12) = a3;
      if ( a2 == 43522 || a2 == 41984 )
      {
        KeyExchangeInfo = GetKeyExchangeInfo(a2);
        if ( KeyExchangeInfo )
        {
          v4[13] = *((_DWORD *)KeyExchangeInfo + 8);
          v4[14] = *((_DWORD *)KeyExchangeInfo + 10);
          if ( v5 == v6 )
            v4[15] = *((_DWORD *)KeyExchangeInfo + 12);
        }
      }
    }
  }
}
// 18003C168: variable 'v4' is possibly undefined
// 18003C176: variable 'v5' is possibly undefined
// 18003C176: variable 'v6' is possibly undefined
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

