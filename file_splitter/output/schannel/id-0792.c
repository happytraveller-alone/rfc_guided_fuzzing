// File count: 792
// Total lines: 134
----------------------------------------
__int64 __fastcall RemotelyOpenClientKeyHandle(
        const unsigned __int16 *Src,
        const unsigned __int16 *a2,
        unsigned __int8 *a3,
        int a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int v8; // r14d
  unsigned int v9; // r15d
  char *v11; // rbx
  unsigned int v12; // esi
  size_t v13; // rdx
  char *v14; // rax
  char *v15; // rdi
  char *v16; // rdi
  CCipherMill *v17; // r10
  __int64 v18; // rax
  __int64 v19; // rdx
  size_t v20; // r8
  unsigned int v21; // ebx
  int v22; // eax
  int v23; // [rsp+20h] [rbp-40h]
  int v24; // [rsp+30h] [rbp-30h] BYREF
  size_t Size; // [rsp+38h] [rbp-28h] BYREF
  __int64 v26; // [rsp+40h] [rbp-20h] BYREF
  void *Srca[2]; // [rsp+48h] [rbp-18h] BYREF

  v24 = 0;
  Size = 0i64;
  v26 = 0i64;
  v8 = 0;
  v9 = 0;
  *(_OWORD *)Srca = 0i64;
  if ( !LsaTable )
    return 87i64;
  if ( (*(int (__fastcall **)(int *, __int64 *, size_t *, void **, _QWORD))(LsaTable + 488))(
         &v24,
         &v26,
         &Size,
         Srca,
         0i64) < 0 )
    return 1359i64;
  if ( Src )
    v8 = 2 * lstrlenW(Src) + 2;
  if ( a2 )
    v9 = 2 * lstrlenW(a2) + 2;
  v11 = (char *)Srca[1];
  v12 = v9 + v8 + 44;
  if ( Srca[1] )
  {
    v13 = Size;
    if ( LODWORD(Srca[0]) >= Size + v12 )
      goto LABEL_16;
    v14 = (char *)(*(__int64 (__fastcall **)(_QWORD))(LsaTable + 384))(4 * v12 + LODWORD(Srca[0]));
    v11 = v14;
    if ( v14 )
    {
      memcpy_0(v14, Srca[1], Size);
      (*(void (__fastcall **)(void *))(LsaTable + 392))(Srca[1]);
      LODWORD(Srca[0]) += 4 * v12;
      v13 = Size;
      Srca[1] = v11;
      goto LABEL_16;
    }
    return 14i64;
  }
  LODWORD(Srca[0]) = 4 * v12 + 8;
  Srca[1] = (void *)(*(__int64 (**)(void))(LsaTable + 384))();
  v11 = (char *)Srca[1];
  if ( !Srca[1] )
    return 14i64;
  v13 = Size + 8;
  Size += 8i64;
LABEL_16:
  v15 = &v11[v13];
  *(_DWORD *)v15 = v12 - 4;
  *(_OWORD *)(v15 + 4) = *(_OWORD *)a3;
  *((_DWORD *)v15 + 5) = *((_DWORD *)a3 + 4);
  *((_DWORD *)v15 + 6) = a5;
  *((_DWORD *)v15 + 7) = a6;
  *((_DWORD *)v15 + 8) = a4;
  *((_DWORD *)v15 + 9) = v8;
  *((_DWORD *)v15 + 10) = v9;
  v16 = &v11[v13 + 44];
  memcpy_0(v16, Src, v8);
  memcpy_0(&v16[v8], a2, v9);
  v17 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
    v17 = WPP_GLOBAL_Control;
  }
  v18 = LsaTable;
  v19 = v26 + 1;
  v20 = Size + v12;
  Size = v20;
  ++v26;
  if ( !LsaTable )
  {
    v21 = -2146893052;
LABEL_26:
    if ( Srca[1] )
    {
      (*(void (**)(void))(v18 + 392))();
      v17 = WPP_GLOBAL_Control;
    }
    if ( v17 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v17 + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)v17 + 2), 19i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v21);
    return v21;
  }
  LOBYTE(v23) = 1;
  v22 = (*(__int64 (__fastcall **)(__int64, __int64, size_t, void **, int))(LsaTable + 496))(4i64, v19, v20, Srca, v23);
  v21 = v22;
  if ( v22 < 0 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        10i64,
        &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
        (unsigned int)v22);
    CleanupAppModeInfo(0i64);
    v18 = LsaTable;
    v17 = WPP_GLOBAL_Control;
    goto LABEL_26;
  }
  return v21;
}
// 1800416DF: variable 'v23' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
