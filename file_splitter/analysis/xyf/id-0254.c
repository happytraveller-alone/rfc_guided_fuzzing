//----- (0000000180014990) ----------------------------------------------------
void __fastcall CSsl3TlsContext::GetUniqueBindings(CSsl3TlsContext *this, unsigned __int8 **a2, unsigned int *a3)
{
  *a2 = (unsigned __int8 *)this + 341;
  *a3 = (*((_DWORD *)this + 16) & 0x3FC0) != 0 ? 12 : 36;
}

