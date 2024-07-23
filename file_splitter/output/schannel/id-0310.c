// File count: 310
// Total lines: 26
-----------------------------------------
__int64 InitializeClientSideSslProvCache(void)
{
  unsigned int v0; // ebx
  struct _RTL_RESOURCE *v1; // rax

  v0 = 0;
  v1 = (struct _RTL_RESOURCE *)LocalAlloc(0x40u, 0x60ui64);
  g_pSslProvCacheRWLock = v1;
  if ( v1 )
    RtlInitializeResource(v1);
  else
    v0 = -2146893056;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v0 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x13u,
      (__int64)&WPP_594269bf8ea736facf0022a8a380b3c5_Traceguids,
      v0,
      v0);
  }
  return v0;
}
// 18003EB64: conditional instruction was optimized away because rax.8==0
