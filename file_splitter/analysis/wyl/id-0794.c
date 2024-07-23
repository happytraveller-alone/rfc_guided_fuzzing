//----- (0000000180041960) ----------------------------------------------------
__int64 __fastcall RemotelySignHash(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        LPCWSTR lpString,
        LPCWSTR a8,
        unsigned __int8 *Src,
        size_t Size)
{
  size_t v10; // rbx
  unsigned int v11; // r14d
  CCipherMill *v15; // rcx
  char *v16; // rdi
  char *v17; // rdi
  __int64 v18; // rax
  unsigned int v19; // ebx
  _BOOL8 v20; // r8
  int v21; // eax
  int v22[2]; // [rsp+30h] [rbp-38h] BYREF
  char *v23; // [rsp+38h] [rbp-30h]

  v10 = 0i64;
  v11 = 0;
  if ( !LsaTable )
    return 87i64;
  if ( lpString )
    v10 = (unsigned int)(2 * lstrlenW(lpString) + 2);
  if ( a8 )
    v11 = 2 * lstrlenW(a8) + 2;
  v22[1] = 1;
  v22[0] = v11 + v10 + Size + 36;
  v23 = (char *)(*(__int64 (**)(void))(LsaTable + 384))();
  if ( !v23 )
    return 14i64;
  v15 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xCu, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, a1);
      v15 = WPP_GLOBAL_Control;
    }
    if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v15 + 28) & 4) != 0 )
      {
        WPP_SF_q(*((_QWORD *)v15 + 2), 0xDu, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, a3);
        v15 = WPP_GLOBAL_Control;
      }
      if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v15 + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)v15 + 2), 14i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, a4);
          v15 = WPP_GLOBAL_Control;
        }
        if ( v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
        {
          WPP_SF_S(*((_QWORD *)v15 + 2), 0xFu, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, lpString);
          v15 = WPP_GLOBAL_Control;
        }
      }
    }
  }
  if ( a8 && v15 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v15 + 28) & 4) != 0 )
    WPP_SF_S(*((_QWORD *)v15 + 2), 0x10u, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, a8);
  v16 = v23;
  *((_DWORD *)v23 + 5) = 0;
  *(_DWORD *)v16 = a5;
  *((_DWORD *)v16 + 1) = a6;
  *(_QWORD *)(v16 + 12) = a2;
  *((_DWORD *)v16 + 2) = a4;
  *((_DWORD *)v16 + 6) = v10;
  *((_DWORD *)v16 + 7) = v11;
  *((_DWORD *)v16 + 8) = Size;
  v16 += 36;
  memcpy_0(v16, lpString, v10);
  v17 = &v16[v10];
  if ( v11 )
  {
    memcpy_0(v17, a8, v11);
    v17 += v11;
  }
  memcpy_0(v17, Src, (unsigned int)Size);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
  v18 = LsaTable;
  if ( LsaTable )
  {
    v20 = a3 != 0;
    if ( !a3 )
      a3 = a1;
    v21 = (*(__int64 (__fastcall **)(__int64, __int64, _BOOL8, int *, char))(LsaTable + 496))(1i64, a3, v20, v22, 1);
    v19 = v21;
    if ( v21 < 0 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          10i64,
          &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
          (unsigned int)v21);
      CleanupAppModeInfo(0i64);
    }
    if ( !v19 )
      return 590610i64;
    v18 = LsaTable;
  }
  else
  {
    v19 = -2146893052;
  }
  if ( v23 )
    (*(void (**)(void))(v18 + 392))();
  return v19;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;

