//----- (0000000180075C88) ----------------------------------------------------
__int64 __fastcall SignEcdsaParams(
        struct CSsl3TlsServerContext *a1,
        unsigned __int8 *a2,
        ULONG a3,
        enum _eTlsHashAlgorithm a4,
        BYTE *pbEncoded,
        DWORD *pcbEncoded)
{
  enum _eTlsHashAlgorithm v8; // ecx
  int TlsHash; // eax
  unsigned int v10; // edi
  unsigned int *p_pvStructInfo; // rbx
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rax
  void *v15; // rsp
  _DWORD *v16; // rax
  __int64 v17; // rax
  DWORD v18; // edx
  __int64 v19; // r10
  __int64 *v20; // rax
  __int64 v21; // rcx
  int LastError; // eax
  int v23; // edx
  __int64 v24; // [rsp+0h] [rbp-40h] BYREF
  unsigned int *v25; // [rsp+28h] [rbp-18h]
  unsigned int v26; // [rsp+40h] [rbp+0h] BYREF
  unsigned int v27; // [rsp+44h] [rbp+4h] BYREF
  unsigned int pvStructInfo; // [rsp+48h] [rbp+8h] BYREF
  unsigned int *v29; // [rsp+50h] [rbp+10h]
  unsigned int v30; // [rsp+58h] [rbp+18h]
  __int64 v31; // [rsp+60h] [rbp+20h]
  unsigned __int8 v32[64]; // [rsp+70h] [rbp+30h] BYREF

  v27 = 0;
  if ( !*((_QWORD *)a1 + 3) )
    return 2148074253i64;
  v25 = &v27;
  v8 = TlsHashAlgorithm_Sha1;
  if ( a4 )
    v8 = a4;
  TlsHash = GenerateTlsHash(v8, (UCHAR *)a1, a2, a3, v32, v25);
  v10 = TlsHash;
  if ( !TlsHash )
  {
    p_pvStructInfo = 0i64;
    if ( !*pcbEncoded )
      goto LABEL_15;
    v12 = *pcbEncoded;
    if ( v12 > g_ulMaxStackAllocSize )
      goto LABEL_15;
    v13 = v12 + g_ulAdditionalProbeSize + 8;
    if ( v13 < v12 || !(unsigned int)VerifyStackAvailable(v13) )
      goto LABEL_15;
    v14 = *pcbEncoded + 8 + 15i64;
    if ( v14 <= *pcbEncoded + 8 )
      v14 = 0xFFFFFFFFFFFFFF0i64;
    v15 = alloca(v14 & 0xFFFFFFFFFFFFFFF0ui64);
    p_pvStructInfo = &v26;
    if ( &v24 == (__int64 *)-64i64 || (v26 = 1801679955, (p_pvStructInfo = &pvStructInfo) == 0i64) )
    {
LABEL_15:
      if ( *pcbEncoded + 8 >= *pcbEncoded )
      {
        v16 = (_DWORD *)((__int64 (*)(void))g_pfnAllocate)();
        if ( !v16 )
          return 14;
        *v16 = 1885431112;
        p_pvStructInfo = v16 + 2;
      }
      if ( !p_pvStructInfo )
        return 14;
    }
    v17 = *((_QWORD *)a1 + 3);
    v18 = *pcbEncoded;
    v26 = *pcbEncoded;
    v19 = *(_QWORD *)(v17 + 8);
    v20 = (__int64 *)*((_QWORD *)a1 + 1);
    if ( v20 )
      v21 = *v20;
    else
      v21 = 0i64;
    LastError = SslSignHash(v21, v19, v32, v27, p_pvStructInfo, v18, &v26, 0);
    v10 = LastError;
    if ( LastError )
    {
      v23 = 1103;
    }
    else
    {
      ReverseInPlace((unsigned __int8 *)p_pvStructInfo, v26 >> 1);
      ReverseInPlace((unsigned __int8 *)p_pvStructInfo + ((unsigned __int64)v26 >> 1), v26 >> 1);
      pvStructInfo = v26 >> 1;
      v30 = v26 >> 1;
      v31 = (__int64)p_pvStructInfo + ((unsigned __int64)v26 >> 1);
      v29 = p_pvStructInfo;
      if ( CryptEncodeObject(1u, (LPCSTR)0x2F, &pvStructInfo, pbEncoded, pcbEncoded) )
        goto LABEL_28;
      LastError = GetLastError();
      v10 = LastError;
      v23 = 1104;
    }
    CSslContext::SetErrorAndFatalAlert((__int64)a1, v23, LastError, 0x50u);
LABEL_28:
    if ( *(p_pvStructInfo - 2) == 1885431112 )
      ((void (*)(void))g_pfnFree)();
    return v10;
  }
  CSslContext::SetErrorAndFatalAlert((__int64)a1, 1102, TlsHash, 0x50u);
  return v10;
}
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180098540: using guessed type __int64 __fastcall SslSignHash(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);

