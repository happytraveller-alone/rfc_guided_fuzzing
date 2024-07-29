//----- (000000018004E1C0) ----------------------------------------------------
__int64 __fastcall CSslUserContext::GetPeerCertValidationResults(CSslUserContext *this, int *a2, unsigned int *a3)
{
  if ( !a2 || !a3 )
    return 87i64;
  *a2 = *((_DWORD *)this + 94);
  *a3 = *((_DWORD *)this + 95);
  return 0i64;
}

