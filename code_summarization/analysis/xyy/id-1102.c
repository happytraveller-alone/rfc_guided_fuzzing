//----- (000000018005B060) ----------------------------------------------------
unsigned __int64 __fastcall CTls13ClientContext::GetHandshakeHash(
        CTls13ClientContext *this,
        enum _eTlsHashAlgorithm a2)
{
  if ( *((_BYTE *)this + 1601) )
    return *((_QWORD *)this + 201);
  else
    return *((_QWORD *)this + 74);
}
