//----- (00000001800122B0) ----------------------------------------------------
void __fastcall CSsl3TlsClientContext::SetStateConnected(CSchannelTelemetryContext **this)
{
  CSchannelTelemetryContext *v2; // rcx
  CSchannelTelemetryContext *v3; // rax
  char Src[8]; // [rsp+20h] [rbp-DE8h] BYREF
  int v5; // [rsp+28h] [rbp-DE0h]
  int v6; // [rsp+2Ch] [rbp-DDCh]
  int v7; // [rsp+30h] [rbp-DD8h]
  CSchannelTelemetryContext *v8; // [rsp+88h] [rbp-D80h]
  LARGE_INTEGER v9[223]; // [rsp+710h] [rbp-6F8h] BYREF

  CSsl3TlsContext::SetStateConnected((CSsl3TlsContext *)this);
  memset_0(Src, 0, 0x6E8ui64);
  v2 = this[1];
  if ( v2 )
    v5 = *((_DWORD *)v2 + 7);
  v6 = *((_DWORD *)this + 4);
  v7 = *((unsigned __int16 *)this + 17);
  v8 = this[17];
  if ( v2 )
  {
    v3 = this[11];
    if ( v3 )
      CSchannelTelemetryContext::LogKeyExchange(this[15], *((_DWORD *)v2 + 8), *((_DWORD *)v3 + 2));
  }
  memcpy_0(v9, Src, 0x6E8ui64);
  CSchannelTelemetryContext::LogHandshakeEnd((LARGE_INTEGER *)this[15], v9);
  CSchannelTelemetryContext::LogDebugTraceHandshakeInfo(this[15], L"Client");
}
// 1800122B0: using guessed type char Src[8];
// 1800122B0: using guessed type LARGE_INTEGER var_6F8[223];

