//----- (000000018000EB48) ----------------------------------------------------
ULONG __fastcall CSsl3TlsContext::TlsGenerateRandom(CSsl3TlsContext *this)
{
  unsigned __int64 v2; // rdx
  __time32_t Time; // [rsp+30h] [rbp+8h] BYREF

  time32_0(&Time);
  v2 = (-(__int64)((*((_DWORD *)this + 16) & 0xA2AA0) != 0) & 0xFFFFFFFFFFFFFFE0ui64) + 304;
  *(_DWORD *)((char *)this + v2) = _byteswap_ulong(Time);
  return GenerateRandomBits((PUCHAR)this + v2 + 4, 0x1Cu);
}

