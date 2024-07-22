//----- (000000018006F760) ----------------------------------------------------
bool __fastcall CSsl3TlsContext::CanParseInput(CSsl3TlsContext *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 17);
  return v1 != 2 && (v1 <= 3 || v1 > 5 && v1 != 91 && v1 != 93 && (v1 <= 94 || v1 > 96 && (v1 <= 97 || v1 > 102)));
}

