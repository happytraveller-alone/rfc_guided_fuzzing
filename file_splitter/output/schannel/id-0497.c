// File count: 497
// Total lines: 18
-----------------------------------------
CMasterCipherInfo *__fastcall CMasterCipherInfo::CMasterCipherInfo(
        CMasterCipherInfo *this,
        struct CCipherSuiteInfo *a2,
        int a3)
{
  unsigned int i; // edx
  __int64 v4; // rax

  *(_QWORD *)this = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = 1;
  _InterlockedIncrement(&CMasterCipherInfo::m_lMasterCiphersCount);
  for ( i = 0; i < *((_DWORD *)this + 2); *(_QWORD *)(864 * v4 + *(_QWORD *)this + 856) = this )
    v4 = i++;
  return this;
}
// 180092D90: using guessed type int CMasterCipherInfo::m_lMasterCiphersCount;
