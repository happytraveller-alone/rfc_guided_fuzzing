//----- (0000000180003CE4) ----------------------------------------------------
__int64 __fastcall CMasterCipherInfo::Dereference(CMasterCipherInfo *this)
{
  unsigned __int32 v1; // ebx

  v1 = _InterlockedDecrement((volatile signed __int32 *)this + 3);
  if ( !v1 )
  {
    _InterlockedDecrement(&CMasterCipherInfo::m_lMasterCiphersCount);
    FreeCipherSuiteData(*((_DWORD *)this + 2), *(NCRYPT_HANDLE **)this, this);
  }
  return v1;
}
// 180092D90: using guessed type int CMasterCipherInfo::m_lMasterCiphersCount;

