//----- (00000001800489EC) ----------------------------------------------------
__int64 __fastcall SslGetNameFromCertificate(PCCERT_CONTEXT pCertContext, unsigned __int16 **a2, int *a3)
{
  PCERT_INFO pCertInfo; // rax
  unsigned __int16 *v4; // rbx
  unsigned int v5; // r12d
  PCERT_EXTENSION rgExtension; // rsi
  __int64 v9; // rdi
  _QWORD *v10; // rdi
  __int64 v11; // rsi
  __int64 v12; // rax
  __int64 v13; // r14
  unsigned __int16 *v14; // rax
  unsigned int v15; // r14d
  PCERT_EXTENSION v16; // rsi
  __int64 v17; // rdi
  void *v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // rsi
  __int64 v21; // rdi
  HLOCAL v22; // rcx
  SIZE_T v24; // r12
  unsigned __int16 *v25; // rax
  DWORD NameStringW; // eax
  DWORD cchNameString; // edi
  WCHAR *v28; // rax
  HLOCAL pvStructInfo[3]; // [rsp+40h] [rbp-18h] BYREF
  DWORD pcbStructInfo; // [rsp+A0h] [rbp+48h] BYREF
  unsigned __int16 **v31; // [rsp+A8h] [rbp+50h]
  _QWORD *v32; // [rsp+B0h] [rbp+58h] BYREF
  HLOCAL hMem; // [rsp+B8h] [rbp+60h] BYREF

  v31 = a2;
  pCertInfo = pCertContext->pCertInfo;
  v4 = 0i64;
  *a3 = 0;
  v5 = 0;
  if ( pCertInfo->cExtension )
  {
    while ( 1 )
    {
      rgExtension = pCertInfo->rgExtension;
      v9 = v5;
      if ( !strcmp_0(rgExtension[v9].pszObjId, "2.5.29.17") )
      {
        pcbStructInfo = 0;
        pvStructInfo[0] = 0i64;
        if ( CryptDecodeObjectEx(
               pCertContext->dwCertEncodingType,
               (LPCSTR)0xC,
               rgExtension[v9].Value.pbData,
               rgExtension[v9].Value.cbData,
               0x2008000u,
               0i64,
               pvStructInfo,
               &pcbStructInfo) )
        {
          v10 = pvStructInfo[0];
          v11 = 0i64;
          if ( *(_DWORD *)pvStructInfo[0] )
          {
            do
            {
              v12 = v10[1];
              if ( *(_DWORD *)(v12 + 24 * v11) == 1 )
              {
                v13 = *(_QWORD *)(v12 + 24 * v11 + 8);
                if ( v13 )
                {
                  if ( !strcmp_0("1.3.6.1.4.1.311.20.2.3", *(const char **)v13) )
                  {
                    LODWORD(v32) = 0;
                    hMem = 0i64;
                    if ( CryptDecodeObjectEx(
                           pCertContext->dwCertEncodingType,
                           (LPCSTR)0x18,
                           *(const BYTE **)(v13 + 16),
                           *(_DWORD *)(v13 + 8),
                           0x2008000u,
                           0i64,
                           &hMem,
                           (DWORD *)&v32) )
                    {
                      v14 = (unsigned __int16 *)LocalAlloc(0x40u, *((unsigned int *)hMem + 2) + 2i64);
                      v4 = v14;
                      if ( v14 )
                        memcpy_0(v14, *((const void **)hMem + 2), *((unsigned int *)hMem + 2));
                      LocalFree(hMem);
                      hMem = 0i64;
                      if ( !v4 )
                      {
                        v22 = pvStructInfo[0];
                        goto LABEL_26;
                      }
                    }
                    v10 = pvStructInfo[0];
                    if ( v4 )
                      break;
                  }
                }
              }
              v11 = (unsigned int)(v11 + 1);
            }
            while ( (unsigned int)v11 < *(_DWORD *)v10 );
          }
          LocalFree(v10);
          if ( v4 )
            break;
        }
      }
      pCertInfo = pCertContext->pCertInfo;
      if ( ++v5 >= pCertInfo->cExtension )
        goto LABEL_16;
    }
LABEL_37:
    *v31 = v4;
    return 0i64;
  }
LABEL_16:
  v15 = 0;
  if ( !pCertInfo->cExtension )
  {
LABEL_32:
    NameStringW = CertGetNameStringW(pCertContext, 3u, 0, "2.5.4.3", 0i64, 0);
    cchNameString = NameStringW;
    if ( !NameStringW )
      return 3221226021i64;
    v28 = (WCHAR *)LocalAlloc(0x40u, 2i64 * NameStringW);
    v4 = v28;
    if ( !v28 )
      return 3221225495i64;
    if ( !CertGetNameStringW(pCertContext, 3u, 0, "2.5.4.3", v28, cchNameString) )
    {
      LocalFree(v4);
      return 3221225524i64;
    }
    goto LABEL_37;
  }
  while ( 1 )
  {
    v16 = pCertInfo->rgExtension;
    v17 = v15;
    if ( !strcmp_0(v16[v17].pszObjId, "2.5.29.17") )
    {
      pcbStructInfo = 0;
      v32 = 0i64;
      if ( CryptDecodeObjectEx(
             pCertContext->dwCertEncodingType,
             (LPCSTR)0xC,
             v16[v17].Value.pbData,
             v16[v17].Value.cbData,
             0x2008000u,
             0i64,
             &v32,
             &pcbStructInfo) )
      {
        break;
      }
    }
LABEL_31:
    pCertInfo = pCertContext->pCertInfo;
    if ( ++v15 >= pCertInfo->cExtension )
      goto LABEL_32;
  }
  v18 = v32;
  v19 = 0i64;
  if ( !*(_DWORD *)v32 )
  {
LABEL_30:
    LocalFree(v18);
    if ( v4 )
      goto LABEL_37;
    goto LABEL_31;
  }
  v20 = v32[1];
  while ( 1 )
  {
    v21 = 3 * v19;
    if ( *(_DWORD *)(v20 + 24 * v19) == 3 )
    {
      if ( *(_QWORD *)(v20 + 24 * v19 + 8) )
        break;
    }
    v19 = (unsigned int)(v19 + 1);
    if ( (unsigned int)v19 >= *(_DWORD *)v32 )
      goto LABEL_30;
  }
  v24 = (unsigned int)(2 * lstrlenW(*(LPCWSTR *)(v20 + 24 * v19 + 8)) + 2);
  v25 = (unsigned __int16 *)LocalAlloc(0x40u, v24);
  v4 = v25;
  if ( v25 )
  {
    memcpy_0(v25, *(const void **)(v20 + 8 * v21 + 8), (unsigned int)v24);
    v18 = v32;
    *a3 = 1;
    goto LABEL_30;
  }
  v22 = v32;
LABEL_26:
  LocalFree(v22);
  return 3221225495i64;
}
// 180048BBD: conditional instruction was optimized away because rbx.8==0
// 180048D0F: conditional instruction was optimized away because rbx.8==0
// 1800489EC: using guessed type HLOCAL var_18[3];
