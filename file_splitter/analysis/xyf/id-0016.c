//----- (0000000180001FC8) ----------------------------------------------------
bool __fastcall CSsl3TlsClientContext::IsFalseStartAllowed(CSsl3TlsClientContext *this)
{
  bool result; // al
  __int64 v2; // rax
  unsigned int v3; // ecx

  result = 0;
  if ( *((_BYTE *)this + 556) )
  {
    if ( *((_DWORD *)this + 16) == 2048 && !*((_BYTE *)this + 1315) && (*((_BYTE *)this + 32) & 8) != 0 )
    {
      v2 = *((_QWORD *)this + 1);
      if ( v2 )
      {
        v3 = *(_DWORD *)(v2 + 28);
        if ( v3 >= 0xC023
          && (v3 <= 0xC024 || v3 > 0xC026 && (v3 <= 0xC028 || v3 > 0xC02A && (v3 <= 0xC02C || v3 - 49199 <= 1))) )
        {
          return 1;
        }
      }
    }
  }
  return result;
}

