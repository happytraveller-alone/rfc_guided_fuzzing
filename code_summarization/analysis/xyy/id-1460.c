//----- (0000000180074F68) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::DhGenerateServerMasterKey(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  unsigned __int64 *v3; // rbx
  unsigned __int64 v7; // rdi
  size_t v8; // r14
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  void *v11; // rsp
  _DWORD *v12; // rax
  unsigned int EccDhPskSessionKeysHelper; // edi
  unsigned int v14; // edx
  _QWORD *v15; // rcx
  unsigned int v16; // eax
  CSsl3TlsServerContext *v17; // rcx
  unsigned __int8 v18; // r9
  int v19; // r8d
  int v20; // edx
  __int64 v22; // [rsp+0h] [rbp-30h] BYREF
  unsigned __int64 v23; // [rsp+30h] [rbp+0h] BYREF
  __int64 v24[3]; // [rsp+38h] [rbp+8h] BYREF

  v23 = 0i64;
  v3 = 0i64;
  v7 = *(unsigned int *)(*((_QWORD *)this + 120) + 24i64);
  if ( !(_DWORD)v7 )
    goto LABEL_9;
  v8 = (unsigned int)v7;
  if ( v7 > g_ulMaxStackAllocSize )
    goto LABEL_9;
  v9 = v7 + g_ulAdditionalProbeSize + 8;
  if ( v9 < v7 || !(unsigned int)VerifyStackAvailable(v9) )
    goto LABEL_9;
  v10 = (unsigned int)(v7 + 8) + 15i64;
  if ( v10 <= (unsigned int)(v7 + 8) )
    v10 = 0xFFFFFFFFFFFFFF0i64;
  v11 = alloca(v10 & 0xFFFFFFFFFFFFFFF0ui64);
  v3 = &v23;
  if ( &v22 == (__int64 *)-48i64 || (LODWORD(v23) = 1801679955, (v3 = (unsigned __int64 *)v24) == 0i64) )
  {
LABEL_9:
    if ( (int)v7 + 8 >= (unsigned int)v7 )
    {
      v12 = (_DWORD *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)((unsigned int)(v7 + 8));
      if ( !v12 )
      {
LABEL_13:
        EccDhPskSessionKeysHelper = 14;
        goto LABEL_31;
      }
      *v12 = 1885431112;
      v3 = (unsigned __int64 *)(v12 + 2);
    }
    if ( !v3 )
      goto LABEL_13;
    v8 = v7;
  }
  memcpy_0(v3, *(const void **)(*((_QWORD *)this + 120) + 16i64), v8);
  if ( !a2 || a3 <= 2 || (v14 = a2[1] | (*a2 << 8), v14 + 2 != a3) || !v14 )
  {
    v19 = -2146893048;
    v17 = this;
    EccDhPskSessionKeysHelper = -2146893048;
    v20 = 704;
    v18 = 50;
    goto LABEL_27;
  }
  if ( (unsigned __int64)(3 * v14) + 8 <= v8 )
  {
    memcpy_0((char *)v3 + 2 * v14 + 8, a2 + 2, v14);
    v15 = (_QWORD *)*((_QWORD *)this + 1);
    if ( v15 )
      v15 = (_QWORD *)*v15;
    v16 = SslImportKey(v15, &v23, L"DHPUBLICBLOB", v3, v7, 0);
    EccDhPskSessionKeysHelper = v16;
    v17 = this;
    if ( !v16 )
    {
      EccDhPskSessionKeysHelper = MakeEccDhPskSessionKeysHelper(
                                    this,
                                    *(_QWORD *)(*((_QWORD *)this + 120) + 8i64),
                                    v23,
                                    1);
      goto LABEL_28;
    }
    v18 = 51;
    v19 = v16;
    v20 = 705;
LABEL_27:
    CSslContext::SetErrorAndFatalAlert((__int64)v17, v20, v19, v18);
    goto LABEL_28;
  }
  EccDhPskSessionKeysHelper = 1359;
LABEL_28:
  if ( v3 && *((_DWORD *)v3 - 2) == 1885431112 )
    ((void (*)(void))g_pfnFree)();
LABEL_31:
  if ( v23 )
    SslFreeObject(v23, 0i64);
  return EccDhPskSessionKeysHelper;
}
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);

