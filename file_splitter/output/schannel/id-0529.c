// File count: 529
// Total lines: 18
-----------------------------------------
void __fastcall FreeCipherSuiteData(unsigned int a1, NCRYPT_HANDLE *a2, struct CMasterCipherInfo *a3)
{
  __int64 v5; // rdi

  if ( a1 )
  {
    v5 = a1;
    do
    {
      CCipherSuiteInfo::~CCipherSuiteInfo(a2);
      a2 += 108;
      --v5;
    }
    while ( v5 );
  }
  SPExternalFree(a3);
}
