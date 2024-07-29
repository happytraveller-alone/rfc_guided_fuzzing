//----- (0000000180062A60) ----------------------------------------------------
bool __fastcall CSsl3TlsServerContext::IsWaitingForCCS(CSsl3TlsServerContext *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 17);
  if ( v1 == 61 )
    return (*((_DWORD *)this + 34) & 0x100i64) == 0 || *((_BYTE *)this + 552) != 0;
  else
    return ((v1 - 62) & 0xFFFFFFFD) == 0;
}

