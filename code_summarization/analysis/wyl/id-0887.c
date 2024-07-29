//----- (00000001800494F8) ----------------------------------------------------
__int64 __fastcall SslMapCertAtDC(
        struct _UNICODE_STRING *a1,
        void *a2,
        unsigned int a3,
        int a4,
        int a5,
        unsigned __int8 **a6,
        unsigned int *a7,
        struct _MSV1_0_PASSTHROUGH_RESPONSE **a8)
{
  size_t v10; // r13
  int v12; // eax
  unsigned int v13; // ebx
  CCipherMill *v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // r9
  int v17; // r14d
  PVOID *p_ProtocolReturnBuffer; // rdi
  ULONG v19; // esi
  unsigned __int64 v20; // rcx
  unsigned __int64 v21; // rax
  void *v22; // rsp
  _DWORD *v23; // rax
  char *v24; // rbx
  void *v25; // rdx
  unsigned __int64 v26; // rcx
  int v27; // eax
  __int64 v28; // r14
  size_t v29; // rdi
  void *v30; // rax
  unsigned __int8 *v31; // rsi
  int v32; // eax
  void *v33; // rdi
  struct _MSV1_0_PASSTHROUGH_RESPONSE *v34; // rcx
  __int64 v35; // [rsp+0h] [rbp-40h] BYREF
  PVOID ProtocolReturnBuffer; // [rsp+40h] [rbp+0h] BYREF
  void *Src; // [rsp+48h] [rbp+8h] BYREF
  int v38; // [rsp+50h] [rbp+10h] BYREF
  int ProtocolStatus; // [rsp+54h] [rbp+14h] BYREF
  unsigned int v40; // [rsp+58h] [rbp+18h] BYREF
  void *v41; // [rsp+60h] [rbp+20h] BYREF
  ULONG ReturnBufferLength; // [rsp+68h] [rbp+28h] BYREF

  ProtocolReturnBuffer = 0i64;
  v41 = 0i64;
  v10 = a3;
  Src = a2;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 58i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
  if ( (unsigned int)v10 > 0x4000 )
    return 2148074278i64;
  if ( a4 && !a5 )
  {
    v38 = 1;
    v12 = LsaIIsDomainWithinForest(a1, &v38, 0i64, &v41, 0i64, 0i64, 0i64);
    v13 = v12;
    if ( v12 < 0 )
    {
      v14 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_56;
      v15 = 59i64;
      v16 = (unsigned int)v12;
      goto LABEL_12;
    }
    if ( !v38 )
    {
      v13 = -2146893039;
      v14 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        goto LABEL_56;
      v15 = 60i64;
      v16 = 2148074257i64;
      goto LABEL_12;
    }
  }
  v17 = (v10 + 3) & 0xFFFFFFFC;
  p_ProtocolReturnBuffer = 0i64;
  v19 = ((SslLegacyPackageName.Length + 3 + a1->Length) & 0xFFFFFFFC) + v17 + 64;
  if ( !v19 )
    goto LABEL_25;
  if ( v19 > (unsigned __int64)g_ulMaxStackAllocSize )
    goto LABEL_25;
  v20 = v19 + g_ulAdditionalProbeSize + 8;
  if ( v20 < v19 || !(unsigned int)VerifyStackAvailable(v20) )
    goto LABEL_25;
  v21 = v19 + 8 + 15i64;
  if ( v21 <= v19 + 8 )
    v21 = 0xFFFFFFFFFFFFFF0i64;
  v22 = alloca(v21 & 0xFFFFFFFFFFFFFFF0ui64);
  p_ProtocolReturnBuffer = &ProtocolReturnBuffer;
  if ( &v35 == (__int64 *)-64i64
    || (LODWORD(ProtocolReturnBuffer) = 1801679955, (p_ProtocolReturnBuffer = &Src) == 0i64) )
  {
LABEL_25:
    if ( v19 + 8 >= v19 )
    {
      v23 = (_DWORD *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)(v19 + 8);
      if ( !v23 )
      {
LABEL_29:
        v13 = -2146893056;
        goto LABEL_56;
      }
      *v23 = 1885431112;
      p_ProtocolReturnBuffer = (PVOID *)(v23 + 2);
    }
    if ( !p_ProtocolReturnBuffer )
      goto LABEL_29;
  }
  *(_DWORD *)p_ProtocolReturnBuffer = 7;
  *(struct _UNICODE_STRING *)(p_ProtocolReturnBuffer + 1) = *a1;
  p_ProtocolReturnBuffer[2] = p_ProtocolReturnBuffer + 8;
  memcpy_0(p_ProtocolReturnBuffer + 8, a1->Buffer, a1->Length);
  v24 = (char *)p_ProtocolReturnBuffer + a1->Length + 64;
  *(struct _UNICODE_STRING *)(p_ProtocolReturnBuffer + 3) = SslLegacyPackageName;
  p_ProtocolReturnBuffer[4] = v24;
  memcpy_0(v24, SslLegacyPackageName.Buffer, SslLegacyPackageName.Length);
  v25 = Src;
  v26 = (unsigned __int64)&v24[SslLegacyPackageName.Length + 3];
  *((_DWORD *)p_ProtocolReturnBuffer + 10) = v17;
  v26 &= 0xFFFFFFFFFFFFFFFCui64;
  p_ProtocolReturnBuffer[6] = (PVOID)v26;
  memcpy_0((void *)v26, v25, v10);
  v13 = LsaCallAuthenticationPackage(
          SslLogonHandle,
          SslMsvPackageId,
          p_ProtocolReturnBuffer,
          v19,
          &ProtocolReturnBuffer,
          &ReturnBufferLength,
          &ProtocolStatus);
  if ( *((_DWORD *)p_ProtocolReturnBuffer - 2) == 1885431112 )
    ((void (*)(void))g_pfnFree)();
  if ( (v13 & 0x80000000) == 0 )
  {
    v27 = ProtocolStatus;
    if ( ProtocolStatus < 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      {
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          62i64,
          &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
          (unsigned int)ProtocolStatus);
        v27 = ProtocolStatus;
      }
      v13 = v27;
      goto LABEL_56;
    }
    v28 = *((_QWORD *)ProtocolReturnBuffer + 2);
    v40 = *(_DWORD *)(v28 + 12);
    v29 = v40;
    v30 = MIDL_user_allocate(v40);
    Src = v30;
    v31 = (unsigned __int8 *)v30;
    if ( !v30 )
    {
      v13 = -1073741801;
      goto LABEL_56;
    }
    memcpy_0(v30, (const void *)(v28 + *(unsigned int *)(v28 + 8)), v29);
    if ( !a5 )
    {
      v32 = SslCheckPacForSidFiltering(v41, (unsigned __int8 **)&Src, &v40);
      v13 = v32;
      if ( v32 < 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
          && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            63i64,
            &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids,
            (unsigned int)v32);
        }
        v33 = Src;
LABEL_54:
        if ( v33 )
          (*(void (__fastcall **)(void *))(LsaTable + 48))(v33);
        goto LABEL_56;
      }
      v31 = (unsigned __int8 *)Src;
      LODWORD(v29) = v40;
    }
    v34 = (struct _MSV1_0_PASSTHROUGH_RESPONSE *)ProtocolReturnBuffer;
    *a6 = v31;
    *a7 = v29;
    v33 = 0i64;
    ProtocolReturnBuffer = 0i64;
    *a8 = v34;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 64i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v13);
    v13 = 0;
    goto LABEL_54;
  }
  ProtocolReturnBuffer = 0i64;
  v14 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) == 0 )
    goto LABEL_56;
  v15 = 61i64;
  v16 = v13;
LABEL_12:
  WPP_SF_D(*((_QWORD *)v14 + 2), v15, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v16);
LABEL_56:
  if ( v41 )
    (*(void (**)(void))(LsaTable + 48))();
  if ( ProtocolReturnBuffer )
    (*(void (**)(void))(LsaTable + 184))();
  return v13;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180092620: using guessed type __int64 LsaTable;
// 180098240: using guessed type __int64 __fastcall LsaIIsDomainWithinForest(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD);
