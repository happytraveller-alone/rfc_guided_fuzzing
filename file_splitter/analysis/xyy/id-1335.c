//----- (0000000180068EC4) ----------------------------------------------------
__int64 __fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ParseCertificateMsg(
        __int64 a1,
        unsigned __int8 *a2,
        int a3)
{
  __int64 v6; // r15
  void *v8; // rcx
  void *v9; // rcx
  const CERT_CONTEXT *v10; // rcx
  __int64 v11; // r12
  unsigned int v12; // esi
  int v13; // r8d
  unsigned __int8 v14; // r9
  int v15; // edx
  __int64 v16; // rcx
  unsigned __int8 *v17; // r14
  unsigned int v18; // ebp
  __int64 v19; // rax
  const void *v20; // rdx
  unsigned int v21; // ebp
  int v22; // ecx
  unsigned __int8 *v23; // r14
  __int64 v24; // rax
  int v25; // edx
  unsigned int v26; // r12d
  unsigned __int8 *v27; // rbx
  int v28; // r9d
  DWORD v29; // r12d
  DWORD v30; // r13d
  const BYTE *v31; // rbx
  unsigned int v32; // r12d
  const BYTE *v33; // rbx
  __int16 v34; // ax
  unsigned int v35; // r12d
  __int16 v36; // r13
  unsigned __int8 *v37; // rbx
  unsigned __int16 v38; // r13
  unsigned int v39; // eax
  __int64 v40; // r10
  unsigned int v41; // r9d
  __int64 v42; // r10
  _DWORD *v43; // rax
  _DWORD *v44; // r12
  unsigned int *i; // r13
  unsigned int v46; // edi
  char *v47; // r14
  char *v48; // r13
  unsigned __int16 *v49; // r14
  __int64 v50; // rax
  int v51; // [rsp+30h] [rbp-78h]
  int v52; // [rsp+34h] [rbp-74h]
  __int16 v53; // [rsp+40h] [rbp-68h] BYREF
  __int128 v54; // [rsp+42h] [rbp-66h]
  __int128 v55; // [rsp+52h] [rbp-56h]
  __int16 v56; // [rsp+62h] [rbp-46h]

  if ( a2 && a3 )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 88i64);
    if ( !v6 )
      return 1359i64;
    RtlAcquireResourceExclusive((PRTL_RESOURCE)(v6 + 72), 1u);
    v8 = *(void **)(v6 + 24);
    if ( v8 )
    {
      SPExternalFree(v8);
      *(_DWORD *)(v6 + 32) = 0;
      *(_QWORD *)(v6 + 24) = 0i64;
    }
    v9 = *(void **)(v6 + 40);
    if ( v9 )
    {
      SPExternalFree(v9);
      *(_QWORD *)(v6 + 40) = 0i64;
    }
    v10 = *(const CERT_CONTEXT **)(v6 + 48);
    if ( v10 )
    {
      CertFreeCertificateContext(v10);
      *(_QWORD *)(v6 + 48) = 0i64;
    }
    v11 = *a2;
    v53 = 0;
    v12 = 0;
    v56 = 0;
    v54 = 0i64;
    v55 = 0i64;
    if ( !a3 )
      goto LABEL_12;
    v17 = a2 + 1;
    v18 = a3 - 1;
    if ( (_BYTE)v11 )
    {
      v16 = *(_QWORD *)(a1 + 8);
      if ( v18 < (unsigned int)v11
        || (*(_DWORD *)(v16 + 64) & 0x40051555) == 0
        || *(_DWORD *)(v16 + 68) != 78
        || (v19 = *(unsigned __int8 *)(v16 + 1232), (_BYTE)v11 != (_BYTE)v19) )
      {
        v13 = -2146893048;
        v14 = 50;
        v12 = -2146893048;
        v15 = 250;
LABEL_14:
        CSslContext::SetErrorAndFatalAlert(v16, v15, v13, v14);
LABEL_55:
        RtlReleaseResource((PRTL_RESOURCE)(v6 + 72));
        return v12;
      }
      v20 = *(const void **)(v16 + 1224);
      if ( !v20 )
      {
        v12 = -2146893052;
        goto LABEL_55;
      }
      if ( RtlCompareMemory(v17, v20, *(unsigned __int8 *)(v16 + 1232)) != v19 )
      {
LABEL_12:
        v13 = -2146893048;
        v14 = 50;
        v12 = -2146893048;
        v15 = 250;
LABEL_13:
        v16 = *(_QWORD *)(a1 + 8);
        goto LABEL_14;
      }
      v17 += v11;
      v18 -= v11;
    }
    if ( v18 >= 3 )
    {
      v21 = v18 - 3;
      v22 = v17[2] + (*v17 << 16) + (v17[1] << 8);
      v23 = v17 + 3;
      if ( v21 == v22 )
      {
        if ( v22 )
        {
          v51 = 0;
          v25 = 0;
          v52 = 0;
          v26 = v21;
          v27 = v23;
          v28 = 0;
          if ( v21 )
          {
            while ( 1 )
            {
              if ( v26 < 3 )
                goto LABEL_12;
              v29 = v26 - 3;
              v30 = v27[2] + (*v27 << 16) + (v27[1] << 8);
              v31 = v27 + 3;
              if ( v29 < v30 || (unsigned int)~v28 < (unsigned __int64)v30 + 4 )
                goto LABEL_12;
              v12 = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ParseCertData(
                      a1,
                      v31,
                      v30,
                      v25,
                      (CTlsSignatureSuiteList *)&v53,
                      v6);
              if ( v12 )
                goto LABEL_55;
              ++v52;
              v32 = v29 - v30;
              v33 = &v31[v30];
              v51 += v30 + 4;
              if ( v32 < 2 )
                goto LABEL_12;
              v34 = v33[1];
              v35 = v32 - 2;
              v36 = *v33;
              v37 = (unsigned __int8 *)(v33 + 2);
              v38 = v34 | (v36 << 8);
              if ( v35 < v38 )
                break;
              v39 = CTlsExt::ParseTlsExtensions(*(_QWORD *)(a1 + 16), v37, v38, 11);
              v12 = v39;
              if ( v39 )
              {
                v14 = 110;
                v13 = v39;
LABEL_47:
                v15 = 253;
                goto LABEL_13;
              }
              v28 = v51;
              v25 = v52;
              v27 = &v37[v38];
              v26 = v35 - v38;
              if ( !v26 )
                goto LABEL_43;
            }
            v13 = -2146893048;
            v14 = 50;
            v12 = -2146893048;
            goto LABEL_47;
          }
LABEL_43:
          v40 = *(_QWORD *)(a1 + 8);
          if ( v40 == -474 )
          {
            v12 = 1359;
            goto LABEL_55;
          }
          if ( CTlsSignatureSuiteList::IsSupportedSignatureSuiteList(
                 (CTlsSignatureSuiteList *)(v40 + 474),
                 (struct CTlsSignatureSuiteList *)&v53) )
          {
            v43 = SPExternalAlloc(v41);
            v44 = v43;
            if ( v43 )
            {
              for ( i = v43; v21; v21 += -5 - v50 - v46 )
              {
                v46 = v23[2] + (*v23 << 16) + (v23[1] << 8);
                v47 = (char *)(v23 + 3);
                *i = v46;
                v48 = (char *)(i + 1);
                memcpy_0(v48, v47, v46);
                v49 = (unsigned __int16 *)&v47[v46];
                i = (unsigned int *)&v48[v46];
                v50 = _byteswap_ushort(*v49);
                v23 = (unsigned __int8 *)v49 + v50 + 2;
              }
              *(_DWORD *)(v6 + 32) = v51;
              *(_QWORD *)(v6 + 24) = v44;
            }
            else
            {
              v12 = 14;
            }
            goto LABEL_55;
          }
          v13 = -2146893048;
          v14 = 40;
          v12 = -2146893048;
          v15 = 252;
          v16 = v42;
        }
        else
        {
          v24 = *(_QWORD *)(a1 + 8);
          if ( (*(_DWORD *)(v24 + 64) & 0x800A2AAA) == 0 )
          {
            *(_BYTE *)(v24 + 552) = 1;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
            }
            v12 = 0;
            goto LABEL_55;
          }
          v13 = -2146893048;
          v14 = 42;
          v12 = -2146893048;
          v15 = 250;
          v16 = *(_QWORD *)(a1 + 8);
        }
        goto LABEL_14;
      }
    }
    goto LABEL_12;
  }
  return 87i64;
}
// 180069231: variable 'v42' is possibly undefined
// 18006923C: variable 'v41' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
