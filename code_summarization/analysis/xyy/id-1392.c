//----- (000000018006EDF0) ----------------------------------------------------
__int64 __fastcall CTls13Context::SetPeerPublicKey(
        CTls13Context *this,
        unsigned __int16 a2,
        const unsigned __int8 *a3,
        unsigned __int16 a4,
        unsigned __int64 a5)
{
  int v5; // esi
  const unsigned __int8 *v6; // r15
  unsigned int EccCurveFlags; // eax
  unsigned int v8; // ebx
  CCipherMill *v10; // rcx
  __int64 v11; // rdx
  int v12; // r14d
  unsigned int *v13; // rbx
  unsigned __int64 v14; // r12
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  void *v17; // rsp
  _DWORD *v18; // rax
  unsigned int v19; // esi
  CTls13Context *v20; // rbx
  __int64 v21; // rcx
  __int64 v22; // [rsp+0h] [rbp-30h] BYREF
  unsigned int v23; // [rsp+30h] [rbp+0h] BYREF
  unsigned int v24; // [rsp+34h] [rbp+4h]
  __int64 v25; // [rsp+38h] [rbp+8h] BYREF
  CTls13Context *v26; // [rsp+40h] [rbp+10h]

  v5 = a4;
  v26 = this;
  v6 = a3;
  if ( !a3 || !a4 )
    return 2148074248i64;
  v23 = 0;
  v24 = a2;
  EccCurveFlags = CCipherMill::GetEccCurveFlags(this, a2, &v23);
  v8 = EccCurveFlags;
  if ( EccCurveFlags )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        10i64,
        &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
        EccCurveFlags);
    return v8;
  }
  if ( (v23 & 8) != 0 )
  {
    v12 = v5;
  }
  else
  {
    if ( *v6 != 4 )
    {
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074248i64;
      v11 = 11i64;
      goto LABEL_18;
    }
    ++v6;
    LOWORD(v5) = v5 - 1;
    if ( (v5 & 1) != 0 )
    {
      v10 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074248i64;
      v11 = 12i64;
LABEL_18:
      WPP_SF_(*((_QWORD *)v10 + 2), v11, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
      return 2148074248i64;
    }
    v12 = (unsigned __int16)v5 >> 1;
  }
  v13 = 0i64;
  v14 = (unsigned int)(2 * v12 + 8);
  if ( v14 > g_ulMaxStackAllocSize )
    goto LABEL_28;
  v15 = v14 + g_ulAdditionalProbeSize + 8;
  if ( v15 < v14 || !(unsigned int)VerifyStackAvailable(v15) )
    goto LABEL_28;
  v16 = (unsigned int)(2 * v12 + 16) + 15i64;
  if ( v16 <= (unsigned int)(2 * v12 + 16) )
    v16 = 0xFFFFFFFFFFFFFF0i64;
  v17 = alloca(v16 & 0xFFFFFFFFFFFFFFF0ui64);
  v13 = &v23;
  if ( &v22 == (__int64 *)-48i64 || (v23 = 1801679955, (v13 = (unsigned int *)&v25) == 0i64) )
  {
LABEL_28:
    if ( 2 * v12 + 16 >= (unsigned int)(2 * v12 + 8) )
    {
      v18 = (_DWORD *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)((unsigned int)(2 * v12 + 16));
      if ( !v18 )
        return 14i64;
      *v18 = 1885431112;
      v13 = v18 + 2;
    }
    if ( !v13 )
      return 14i64;
  }
  memset_0(v13, 0, (unsigned int)(2 * v12 + 8));
  *v13 = v24;
  v13[1] = v12;
  memcpy_0(v13 + 2, v6, (unsigned __int16)v5);
  v25 = 0i64;
  v19 = SslImportKey(a5, &v25, L"SSLECCPUBLICBLOB", v13, 2 * v12 + 8, 0);
  if ( *(v13 - 2) == 1885431112 )
    ((void (*)(void))g_pfnFree)();
  if ( v19 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids, v19);
    return v19;
  }
  else
  {
    v20 = v26;
    v21 = *((_QWORD *)v26 + 5);
    if ( v21 )
      SslFreeObject(v21, 0i64);
    *((_QWORD *)v20 + 5) = v25;
    return 0i64;
  }
}
// 18006EEA5: conditional instruction was optimized away because si.2!=0
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082258: using guessed type wchar_t aSsleccpublicbl[17];
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
