//----- (00000001800611F0) ----------------------------------------------------
bool __fastcall CSsl3TlsClientContext::IsWaitingForCCS(CSsl3TlsClientContext *this)
{
  int v1; // edx
  char v2; // cl

  v1 = *((_DWORD *)this + 17);
  v2 = 1;
  if ( (unsigned int)(v1 - 46) > 1 )
    return (unsigned int)(v1 - 50) <= 2;
  return v2;
}

