//----- (000000018005B090) ----------------------------------------------------
unsigned __int64 __fastcall CTls13ServerContext::GetHandshakeHash(
        CTls13ServerContext *this,
        enum _eTlsHashAlgorithm a2)
{
  if ( *((_BYTE *)this + 1233) )
    return *((_QWORD *)this + 155);
  else
    return *((_QWORD *)this + 74);
}
