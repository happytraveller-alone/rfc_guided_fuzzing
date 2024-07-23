// File count: 1009
// Total lines: 93
----------------------------------------
__int64 __fastcall SPCheckKeyUsage(PCCERT_CONTEXT pCertContext, char *a2, int a3, int *a4)
{
  int v4; // edi
  DWORD v7; // esi
  DWORD v8; // edx
  struct _CTL_USAGE *p_pcbUsage; // rbx
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  void *v12; // rsp
  _DWORD *v13; // rax
  int v15; // esi
  LPSTR *rgpszUsageIdentifier; // r15
  __int64 v17; // [rsp+0h] [rbp-20h] BYREF
  DWORD pcbUsage; // [rsp+20h] [rbp+0h] BYREF
  __int64 v19[3]; // [rsp+28h] [rbp+8h] BYREF

  v4 = 0;
  pcbUsage = 0;
  v7 = a3 != 0 ? 2 : 0;
  if ( !CertGetEnhancedKeyUsage(pCertContext, v7, 0i64, &pcbUsage) )
    goto LABEL_19;
  v8 = pcbUsage;
  p_pcbUsage = 0i64;
  if ( !pcbUsage )
    goto LABEL_11;
  if ( pcbUsage > (unsigned __int64)g_ulMaxStackAllocSize )
    goto LABEL_11;
  v10 = pcbUsage + g_ulAdditionalProbeSize + 8;
  if ( v10 < pcbUsage )
    goto LABEL_11;
  if ( !(unsigned int)VerifyStackAvailable(v10) )
    goto LABEL_10;
  v8 = pcbUsage;
  v11 = pcbUsage + 8 + 15i64;
  if ( v11 <= pcbUsage + 8 )
    v11 = 0xFFFFFFFFFFFFFF0i64;
  v12 = alloca(v11 & 0xFFFFFFFFFFFFFFF0ui64);
  p_pcbUsage = (struct _CTL_USAGE *)&pcbUsage;
  if ( &v17 == (__int64 *)-32i64 )
    goto LABEL_11;
  pcbUsage = 1801679955;
  p_pcbUsage = (struct _CTL_USAGE *)v19;
  if ( !v19 )
  {
LABEL_10:
    v8 = pcbUsage;
LABEL_11:
    if ( v8 + 8 >= v8 )
    {
      v13 = (_DWORD *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)(v8 + 8);
      if ( !v13 )
      {
LABEL_15:
        *a4 = 0;
        return 2148074240i64;
      }
      *v13 = 1885431112;
      p_pcbUsage = (struct _CTL_USAGE *)(v13 + 2);
    }
    if ( !p_pcbUsage )
      goto LABEL_15;
  }
  if ( CertGetEnhancedKeyUsage(pCertContext, v7, p_pcbUsage, &pcbUsage)
    && (p_pcbUsage->cUsageIdentifier || GetLastError() != -2146885628) )
  {
    v15 = 0;
    if ( p_pcbUsage->cUsageIdentifier )
    {
      rgpszUsageIdentifier = p_pcbUsage->rgpszUsageIdentifier;
      while ( strcmp_0("1.3.6.1.5.5.7.3.2", rgpszUsageIdentifier[v15]) )
      {
        if ( ++v15 >= p_pcbUsage->cUsageIdentifier )
          goto LABEL_29;
      }
      v4 = 1;
    }
LABEL_29:
    if ( LODWORD(p_pcbUsage[-1].rgpszUsageIdentifier) == 1885431112 )
      ((void (*)(void))g_pfnFree)();
    *a4 = v4;
    return 0i64;
  }
  if ( LODWORD(p_pcbUsage[-1].rgpszUsageIdentifier) == 1885431112 )
    ((void (*)(void))g_pfnFree)();
LABEL_19:
  *a4 = 1;
  return 0i64;
}
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
