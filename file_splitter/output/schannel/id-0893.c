//----- (000000018004AA94) ----------------------------------------------------
__int64 __fastcall SslTryCompoundName(
        const struct _CERT_CONTEXT *a1,
        unsigned __int8 **a2,
        unsigned int *a3,
        unsigned __int16 **a4)
{
  PCERT_INFO pCertInfo; // rdx
  int v7; // r12d
  DWORD dwCertEncodingType; // ecx
  unsigned int v10; // edi
  DWORD v11; // eax
  DWORD v12; // esi
  unsigned int v13; // ecx
  __int16 v14; // r8
  struct _UNICODE_STRING *Buffer; // rdx
  bool v16; // zf
  USHORT MaximumLength; // r8
  unsigned __int64 v18; // rcx
  int v19; // eax
  unsigned __int64 v20; // rax
  void *v21; // rsp
  WCHAR *v22; // rax
  PWSTR v23; // rbx
  __int64 v24; // rcx
  int v25; // eax
  __int64 v26; // rdx
  int v27; // ebx
  PWSTR v28; // rbx
  unsigned int *csz; // [rsp+20h] [rbp-20h]
  struct _UNICODE_STRING v31; // [rsp+40h] [rbp+0h] BYREF
  unsigned int v32; // [rsp+50h] [rbp+10h] BYREF
  unsigned int v33[4]; // [rsp+58h] [rbp+18h] BYREF
  struct _UNICODE_STRING v34; // [rsp+68h] [rbp+28h] BYREF
  struct _UNICODE_STRING v35; // [rsp+78h] [rbp+38h] BYREF

  pCertInfo = a1->pCertInfo;
  *a4 = 0i64;
  v7 = (int)a3;
  dwCertEncodingType = a1->dwCertEncodingType;
  v35 = 0i64;
  v34 = 0i64;
  *(_OWORD *)v33 = 0i64;
  v10 = CertNameToStrW(dwCertEncodingType, &pCertInfo->Issuer, 0x28000003u, 0i64, 0);
  v11 = CertNameToStrW(a1->dwCertEncodingType, &a1->pCertInfo->Subject, 0x28000003u, 0i64, 0);
  v12 = v11;
  if ( v10 )
  {
    if ( v11 )
    {
      v13 = v11 + v10;
      if ( v11 + v10 >= v10 && v13 <= 0xFFFF && (unsigned __int16)v13 <= 0x7FF9u )
      {
        v31.Buffer = 0i64;
        v14 = v11 + v10 + 6;
        Buffer = 0i64;
        v16 = 2 * v14 == 0;
        MaximumLength = 2 * v14;
        v31.MaximumLength = MaximumLength;
        if ( !v16 && MaximumLength <= (unsigned __int64)g_ulMaxStackAllocSize )
        {
          v18 = MaximumLength + g_ulAdditionalProbeSize + 8;
          if ( v18 >= MaximumLength )
          {
            v19 = VerifyStackAvailable(v18);
            MaximumLength = v31.MaximumLength;
            if ( v19 )
            {
              v20 = (unsigned int)v31.MaximumLength + 8 + 15i64;
              if ( v20 <= (unsigned int)v31.MaximumLength + 8 )
                v20 = 0xFFFFFFFFFFFFFF0i64;
              v21 = alloca(v20 & 0xFFFFFFFFFFFFFFF0ui64);
              Buffer = &v31;
              v31.Buffer = (PWSTR)&v31;
            }
            else
            {
              Buffer = (struct _UNICODE_STRING *)v31.Buffer;
            }
            if ( Buffer )
            {
              *(_DWORD *)&Buffer->Length = 1801679955;
              v16 = v31.Buffer == (PWSTR)-8i64;
              Buffer = (struct _UNICODE_STRING *)(v31.Buffer + 4);
              v31.Buffer += 4;
              if ( !v16 )
              {
LABEL_21:
                *(_QWORD *)&Buffer->Length = 0x3E0049003Ci64;
                v23 = v31.Buffer;
                v24 = CertNameToStrW(a1->dwCertEncodingType, &a1->pCertInfo->Issuer, 0x28000003u, v31.Buffer + 3, v10)
                    - 1;
                *(_QWORD *)&v23[v24 + 3] = 0x3E0053003Ci64;
                CertNameToStrW(a1->dwCertEncodingType, &a1->pCertInfo->Subject, 0x28000003u, &v23[v24 + 6], v12);
                ConvertNameString(&v31);
                LODWORD(csz) = v7;
                v25 = (*(__int64 (__fastcall **)(struct _UNICODE_STRING *, __int64, struct _UNICODE_STRING *, unsigned __int8 **))(LsaTable + 296))(
                        &v31,
                        1i64,
                        &SslNamePrefix,
                        a2);
                v27 = v25;
                if ( LOWORD(v33[0]) )
                {
                  LOBYTE(v26) = v25 >= 0;
                  csz = v33;
                  (*(void (__fastcall **)(__int64, __int64, struct _UNICODE_STRING *, struct _UNICODE_STRING *))(LsaTable + 312))(
                    678i64,
                    v26,
                    &SslPackageName,
                    &v31);
                  (*(void (__fastcall **)(_QWORD))(LsaTable + 48))(*(_QWORD *)&v33[2]);
                }
                if ( v27 == -1073741275 )
                {
                  v27 = SslCrackSingleName(0xFFFFFFF5, v26, &v31, &SslNamePrefix, (unsigned int)csz, &v35, &v34, &v32);
                  if ( v27 >= 0 )
                  {
                    if ( v32 )
                    {
                      v28 = v34.Buffer;
                    }
                    else
                    {
                      v28 = 0i64;
                      *a4 = v34.Buffer;
                    }
                    if ( v35.Buffer )
                      (*(void (**)(void))(LsaTable + 48))();
                    if ( v28 )
                      (*(void (__fastcall **)(PWSTR))(LsaTable + 48))(v28);
                    v27 = -1073741275;
                  }
                }
                if ( v31.Buffer )
                {
                  if ( *((_DWORD *)v31.Buffer - 2) == 1885431112 )
                    ((void (*)(void))g_pfnFree)();
                }
                return (unsigned int)v27;
              }
              MaximumLength = v31.MaximumLength;
            }
          }
        }
        if ( (unsigned int)MaximumLength + 8 >= MaximumLength )
        {
          v22 = (WCHAR *)((__int64 (__fastcall *)(__int64, struct _UNICODE_STRING *))g_pfnAllocate)(
                           MaximumLength + 8i64,
                           Buffer);
          v31.Buffer = v22;
          if ( !v22 )
            return (unsigned int)-1073741801;
          *(_DWORD *)v22 = 1885431112;
          Buffer = (struct _UNICODE_STRING *)(v31.Buffer + 4);
          v31.Buffer += 4;
        }
        if ( Buffer )
          goto LABEL_21;
        return (unsigned int)-1073741801;
      }
    }
  }
  return 3221225495i64;
}
// 18004AD56: variable 'v26' is possibly undefined
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180092620: using guessed type __int64 LsaTable;

