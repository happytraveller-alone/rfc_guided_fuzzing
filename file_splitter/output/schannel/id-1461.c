// File count: 1461
// Total lines: 179
---------------------------------------
__int64 __fastcall DhGetEphemKey(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        const unsigned __int8 *Src,
        unsigned int Size,
        const unsigned __int8 *a7,
        unsigned __int64 *a8,
        unsigned int *a9)
{
  struct kexch *KeyExchangeInfo; // rax
  unsigned int v11; // r9d
  const unsigned __int8 *v12; // rbx
  unsigned int v13; // r13d
  const unsigned __int8 *v14; // r15
  unsigned int v15; // esi
  unsigned int *v17; // rdi
  unsigned int v18; // r14d
  unsigned __int64 v19; // rdx
  unsigned __int64 v20; // rcx
  int v21; // edx
  unsigned __int64 v22; // rax
  void *v23; // rsp
  unsigned int v24; // eax
  _DWORD *v25; // rax
  unsigned int v26; // ebx
  char *v27; // r14
  __int64 v28; // [rsp+0h] [rbp-50h] BYREF
  unsigned int v29; // [rsp+50h] [rbp+0h] BYREF
  unsigned int v30; // [rsp+54h] [rbp+4h]
  unsigned int v31; // [rsp+58h] [rbp+8h] BYREF
  __int64 v32; // [rsp+60h] [rbp+10h]
  unsigned __int64 v33; // [rsp+68h] [rbp+18h] BYREF

  v32 = a1;
  v31 = a3;
  v30 = a2;
  KeyExchangeInfo = GetKeyExchangeInfo(43522);
  v12 = Src;
  v13 = Size;
  v14 = a7;
  if ( Src && a7 )
  {
    v15 = 8 * v11;
    if ( Size > v11 )
      return 87i64;
    if ( v15 < *((_DWORD *)KeyExchangeInfo + 8) || v15 > *((_DWORD *)KeyExchangeInfo + 10) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0xAu,
          (__int64)&WPP_83c3a6cdaad8366ccbbf1e25ed54fc6f_Traceguids,
          v15);
      return 87i64;
    }
  }
  else
  {
    v15 = *((_DWORD *)KeyExchangeInfo + 12);
  }
  v17 = 0i64;
  v18 = v15 >> 3;
  v19 = 2 * (v15 >> 3) + 12;
  v29 = 2 * (v15 >> 3) + 12;
  if ( v19 <= g_ulMaxStackAllocSize )
  {
    v20 = v19 + g_ulAdditionalProbeSize + 8;
    if ( v20 >= v19 )
    {
      if ( (unsigned int)VerifyStackAvailable(v20) )
      {
        v21 = 2 * v18 + 12;
        v22 = 2 * v18 + 20 + 15i64;
        if ( v22 <= 2 * v18 + 20 )
          v22 = 0xFFFFFFFFFFFFFF0i64;
        v23 = alloca(v22 & 0xFFFFFFFFFFFFFFF0ui64);
        v17 = &v29;
        if ( &v28 != (__int64 *)-80i64 )
        {
          v29 = 1801679955;
          v17 = &v31;
          if ( &v31 )
            goto LABEL_24;
        }
      }
    }
  }
  v24 = 2 * v18 + 20;
  if ( v24 < 2 * v18 + 12 )
  {
LABEL_21:
    if ( !v17 )
      return 14;
    v21 = 2 * v18 + 12;
LABEL_24:
    if ( !Src )
    {
      switch ( v15 )
      {
        case 0x400u:
          v12 = (const unsigned __int8 *)&unk_1800862E0;
          break;
        case 0x800u:
          v12 = (const unsigned __int8 *)&unk_180086160;
          break;
        case 0xC00u:
          v12 = (const unsigned __int8 *)&unk_180085EE0;
          break;
        default:
          v12 = (const unsigned __int8 *)&unk_180085B60;
          break;
      }
      a4 = v15 >> 3;
    }
    if ( !a7 )
    {
      switch ( v15 )
      {
        case 0x400u:
          v14 = (const unsigned __int8 *)&unk_180086260;
          break;
        case 0x800u:
          v14 = (const unsigned __int8 *)&unk_180086060;
          break;
        case 0xC00u:
          v14 = (const unsigned __int8 *)&unk_180085D60;
          break;
        default:
          v14 = (const unsigned __int8 *)&unk_180085960;
          break;
      }
      v13 = v15 >> 3;
    }
    *v17 = v21;
    v17[2] = a4;
    v17[1] = 1297107012;
    memcpy_0(v17 + 3, v12, a4);
    v27 = (char *)v17 + v17[2] + 12;
    if ( v13 < a4 )
    {
      memset_0(v27, 0, a4 - v13);
      v27 += a4 - v13;
    }
    memcpy_0(v27, v14, v13);
    v26 = SslCreateEphemeralKey(v32, &v33, v31, v30, 0, 8 * a4, v17, v29, 0);
    if ( v26 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_83c3a6cdaad8366ccbbf1e25ed54fc6f_Traceguids, v26);
    }
    else
    {
      *a8 = v33;
      if ( a9 )
        *a9 = v15;
    }
    if ( v17 && *(v17 - 2) == 1885431112 )
      ((void (*)(void))g_pfnFree)();
    return v26;
  }
  v25 = (_DWORD *)((__int64 (__fastcall *)(_QWORD))g_pfnAllocate)(v24);
  if ( v25 )
  {
    *v25 = 1885431112;
    v17 = v25 + 2;
    goto LABEL_21;
  }
  return 14;
}
// 18007521F: variable 'v11' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180098548: using guessed type __int64 __fastcall SslCreateEphemeralKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _DWORD, _DWORD);
