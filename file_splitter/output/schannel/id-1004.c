// File count: 1004
// Total lines: 157
---------------------------------------
__int64 __fastcall ExtractIssuerNamesFromStore(void *a1, unsigned __int8 *a2, unsigned int *a3, unsigned __int8 *a4)
{
  unsigned int v4; // r12d
  unsigned int v6; // ebp
  unsigned __int8 *v7; // rsi
  char v8; // bl
  PCCERT_CONTEXT v11; // rdi
  __int128 *pCertInfo; // rcx
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __int128 v21; // xmm1
  __int128 v22; // xmm0
  __int128 v23; // xmm1
  __int128 v24; // xmm0
  size_t v25; // rbx
  BOOL v26; // eax
  DWORD LastError; // eax
  const void *v28; // rdx
  char *v29; // rsi
  int v31; // [rsp+20h] [rbp-118h] BYREF
  DWORD pcbData; // [rsp+24h] [rbp-114h] BYREF
  int pvData; // [rsp+28h] [rbp-110h] BYREF
  __int128 v34; // [rsp+30h] [rbp-108h]
  __int128 v35; // [rsp+40h] [rbp-F8h]
  __int128 v36; // [rsp+50h] [rbp-E8h]
  __int128 v37; // [rsp+60h] [rbp-D8h]
  __int128 v38; // [rsp+70h] [rbp-C8h]
  __int128 Size; // [rsp+80h] [rbp-B8h]
  __int128 v40; // [rsp+90h] [rbp-A8h]
  __int128 v41; // [rsp+A0h] [rbp-98h]
  __int128 v42; // [rsp+B0h] [rbp-88h]
  __int128 v43; // [rsp+C0h] [rbp-78h]
  __int128 v44; // [rsp+D0h] [rbp-68h]
  __int128 v45; // [rsp+E0h] [rbp-58h]
  __int128 v46; // [rsp+F0h] [rbp-48h]
  char v48; // [rsp+148h] [rbp+10h]
  char v49; // [rsp+150h] [rbp+18h]

  v4 = *a3;
  v6 = 0;
  v7 = a2;
  *a3 = 0;
  v8 = 0;
  v49 = 0;
  v48 = 0;
  v11 = CertEnumCertificatesInStore(a1, 0i64);
  if ( v11 )
  {
    while ( 1 )
    {
      pCertInfo = (__int128 *)v11->pCertInfo;
      if ( !pCertInfo )
      {
LABEL_27:
        v8 = v48;
        break;
      }
      v13 = pCertInfo[1];
      v34 = *pCertInfo;
      v14 = pCertInfo[2];
      v35 = v13;
      v15 = pCertInfo[3];
      v36 = v14;
      v16 = pCertInfo[4];
      v37 = v15;
      v17 = pCertInfo[5];
      v38 = v16;
      v18 = pCertInfo[6];
      Size = v17;
      v19 = pCertInfo[7];
      v40 = v18;
      v20 = pCertInfo[8];
      v41 = v19;
      v21 = pCertInfo[9];
      v42 = v20;
      v22 = pCertInfo[10];
      v43 = v21;
      v23 = pCertInfo[11];
      v44 = v22;
      v24 = pCertInfo[12];
      v45 = v23;
      v46 = v24;
      v25 = (unsigned int)Size;
      if ( (unsigned int)Size <= 0xFFFF )
      {
        if ( !(unsigned int)SPCheckKeyUsage(v11, (char *)&WPP_GLOBAL_Control, 0, &v31) && v31 )
        {
          v26 = IsCertSelfSigned(v11);
          if ( v26 )
            v49 = 1;
          else
            v48 = 1;
          if ( a2
            && v26
            && a4
            && *a4
            && (pvData = 0, pcbData = 4, !CertGetCertificateContextProperty(v11, 0x66u, &pvData, &pcbData)) )
          {
            LastError = GetLastError();
            if ( LastError != 1168
              && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                12i64,
                &WPP_145b996ecad4340088f3534b93eceddb_Traceguids,
                LastError);
            }
          }
          else
          {
            v6 += v25 + 2;
            if ( a2 )
            {
              if ( v6 > v4 || v4 < 2 || (unsigned int)v25 > v4 )
              {
                CertFreeCertificateContext(v11);
                return 1359i64;
              }
              v28 = (const void *)*((_QWORD *)&Size + 1);
              *v7 = BYTE1(v25);
              v7[1] = v25;
              v29 = (char *)(v7 + 2);
              memcpy_0(v29, v28, v25);
              v7 = (unsigned __int8 *)&v29[v25];
            }
          }
        }
      }
      else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
             && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids);
      }
      v11 = CertEnumCertificatesInStore(a1, v11);
      if ( !v11 )
        goto LABEL_27;
    }
  }
  if ( a4 && v49 )
  {
    if ( v8 )
      *a4 = 1;
  }
  *a3 = v6;
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
