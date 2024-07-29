//----- (0000000180026D60) ----------------------------------------------------
__int64 InitializeIssuerCache(void)
{
  unsigned int i; // ecx
  _QWORD *v1; // rax
  unsigned int v2; // ebx

  memset_0(&IssuerCache, 0, 0x90ui64);
  dword_1800926F8 = 600000;
  dword_1800926FC = 100;
  dword_180092700 = 100;
  qword_180092710 = (__int64)&qword_180092708;
  qword_180092708 = (__int64)&qword_180092708;
  RtlInitializeResource(&stru_180092718);
  dword_180092778 = 1;
  IssuerCache = SPExternalAlloc(16 * dword_1800926FC);
  if ( IssuerCache )
  {
    for ( i = 0; i < dword_1800926FC; ++i )
    {
      v1 = (char *)IssuerCache + 16 * i;
      v1[1] = v1;
      *v1 = v1;
    }
    return 0;
  }
  else
  {
    v2 = 14;
    ShutdownIssuerCache();
  }
  return v2;
}
// 1800926FC: using guessed type int dword_1800926FC;
// 180092708: using guessed type __int64 qword_180092708;
// 180092710: using guessed type __int64 qword_180092710;
// 180092778: using guessed type int dword_180092778;
