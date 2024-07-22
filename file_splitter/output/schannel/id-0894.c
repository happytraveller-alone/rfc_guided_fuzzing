//----- (000000018004AE90) ----------------------------------------------------
__int64 __fastcall SslTryIssuer(
        unsigned __int8 *a1,
        unsigned int a2,
        unsigned __int8 **a3,
        unsigned int *a4,
        unsigned __int16 **a5)
{
  int v5; // r14d
  int v6; // r12d
  DWORD v11; // ebx
  struct _UNICODE_STRING *Buffer; // rdx
  USHORT MaximumLength; // r8
  unsigned __int64 v14; // rcx
  int v15; // eax
  unsigned __int64 v16; // rax
  void *v17; // rsp
  bool v18; // zf
  WCHAR *v19; // rax
  int v20; // eax
  __int64 v21; // rdx
  int v22; // ebx
  PWSTR v23; // rbx
  unsigned int *csz; // [rsp+20h] [rbp-20h]
  struct _UNICODE_STRING v25; // [rsp+40h] [rbp+0h] BYREF
  unsigned int v26; // [rsp+50h] [rbp+10h] BYREF
  unsigned int v27[4]; // [rsp+58h] [rbp+18h] BYREF
  struct _CRYPTOAPI_BLOB pName; // [rsp+68h] [rbp+28h] BYREF
  struct _UNICODE_STRING v29; // [rsp+78h] [rbp+38h] BYREF
  HLOCAL hMem[2]; // [rsp+88h] [rbp+48h] BYREF

  v5 = 0;
  v6 = (int)a4;
  *a5 = 0i64;
  *(_OWORD *)hMem = 0i64;
  v29 = 0i64;
  *(_OWORD *)v27 = 0i64;
  if ( (unsigned int)SPFindIssuerInCache(a1, a2) )
    return 3221226021i64;
  pName.pbData = a1;
  pName.cbData = a2;
  v11 = CertNameToStrW(1u, &pName, 0x28000003u, 0i64, 0);
  if ( v11 <= 0xFFFF && (unsigned __int16)v11 <= 0x7FFCu )
  {
    Buffer = 0i64;
    MaximumLength = 2 * (v11 + 3);
    v25.Buffer = 0i64;
    v25.MaximumLength = MaximumLength;
    if ( MaximumLength )
    {
      if ( MaximumLength <= (unsigned __int64)g_ulMaxStackAllocSize )
      {
        v14 = MaximumLength + g_ulAdditionalProbeSize + 8;
        if ( v14 >= MaximumLength )
        {
          v15 = VerifyStackAvailable(v14);
          MaximumLength = v25.MaximumLength;
          if ( v15 )
          {
            v16 = (unsigned int)v25.MaximumLength + 8 + 15i64;
            if ( v16 <= (unsigned int)v25.MaximumLength + 8 )
              v16 = 0xFFFFFFFFFFFFFF0i64;
            v17 = alloca(v16 & 0xFFFFFFFFFFFFFFF0ui64);
            Buffer = &v25;
            v25.Buffer = (PWSTR)&v25;
          }
          else
          {
            Buffer = (struct _UNICODE_STRING *)v25.Buffer;
          }
          if ( Buffer )
          {
            *(_DWORD *)&Buffer->Length = 1801679955;
            v18 = v25.Buffer == (PWSTR)-8i64;
            Buffer = (struct _UNICODE_STRING *)(v25.Buffer + 4);
            v25.Buffer += 4;
            if ( !v18 )
            {
LABEL_20:
              *(_QWORD *)&Buffer->Length = 0x3E0049003Ci64;
              CertNameToStrW(1u, &pName, 0x28000003u, v25.Buffer + 3, v11);
              ConvertNameString(&v25);
              LODWORD(csz) = v6;
              v20 = (*(__int64 (__fastcall **)(struct _UNICODE_STRING *, __int64, struct _UNICODE_STRING *, unsigned __int8 **))(LsaTable + 296))(
                      &v25,
                      1i64,
                      &SslNamePrefix,
                      a3);
              v22 = v20;
              if ( LOWORD(v27[0]) )
              {
                LOBYTE(v21) = v20 >= 0;
                csz = v27;
                (*(void (__fastcall **)(__int64, __int64, struct _UNICODE_STRING *, struct _UNICODE_STRING *))(LsaTable + 312))(
                  678i64,
                  v21,
                  &SslPackageName,
                  &v25);
                (*(void (__fastcall **)(_QWORD))(LsaTable + 48))(*(_QWORD *)&v27[2]);
              }
              if ( v22 == -1073741275 )
              {
                v22 = SslCrackSingleName(
                        0xFFFFFFF5,
                        v21,
                        &v25,
                        &SslNamePrefix,
                        (unsigned int)csz,
                        (struct _UNICODE_STRING *)hMem,
                        &v29,
                        &v26);
                if ( v22 < 0 )
                  goto LABEL_32;
                if ( v26 )
                {
                  v23 = v29.Buffer;
                }
                else
                {
                  v23 = 0i64;
                  *a5 = v29.Buffer;
                  v5 = 1;
                }
                if ( hMem[1] )
                  LocalFree(hMem[1]);
                if ( v23 )
                  LocalFree(v23);
                v22 = -1073741275;
                if ( !v5 )
LABEL_32:
                  SPAddIssuerToCache(a1, a2);
              }
              if ( v25.Buffer )
              {
                if ( *((_DWORD *)v25.Buffer - 2) == 1885431112 )
                  ((void (*)(void))g_pfnFree)();
              }
              return (unsigned int)v22;
            }
            MaximumLength = v25.MaximumLength;
          }
        }
      }
    }
    if ( (unsigned int)MaximumLength + 8 >= MaximumLength )
    {
      v19 = (WCHAR *)((__int64 (__fastcall *)(__int64))g_pfnAllocate)(MaximumLength + 8i64);
      v25.Buffer = v19;
      if ( !v19 )
        return (unsigned int)-1073741801;
      *(_DWORD *)v19 = 1885431112;
      Buffer = (struct _UNICODE_STRING *)(v25.Buffer + 4);
      v25.Buffer += 4;
    }
    if ( Buffer )
      goto LABEL_20;
    return (unsigned int)-1073741801;
  }
  return 3221225485i64;
}
// 18004B0F3: variable 'v21' is possibly undefined
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180092620: using guessed type __int64 LsaTable;

