// File count: 204
// Total lines: 249
----------------------------------------
__int64 __fastcall ParseKeyBuffer(struct CSslContext *a1, __int64 a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v4; // esi
  char v7; // r14
  int v9; // ebp
  unsigned __int8 *v10; // rbx
  __int64 v11; // rax
  _QWORD *v12; // rbx
  _QWORD *v13; // r14
  _QWORD *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  CCipherMill *v17; // rcx
  _DWORD *v18; // rbx
  unsigned int v19; // r14d
  unsigned int *v20; // rax
  _BYTE *v21; // rbx
  __int64 v22; // r9
  __int64 v23; // r14
  __int64 v24; // r15
  unsigned int v25; // r12d
  _BYTE *v26; // rbx
  _BYTE *v27; // r8
  _BYTE *v28; // r13
  _BYTE *v29; // rbx
  _QWORD *v30; // rax
  __int64 v31; // rcx
  __int64 *v33; // rax
  __int64 v34; // rcx
  CCipherMill *v35; // rcx
  __int64 v36; // rdx
  __int64 *v37; // rax
  __int64 v38; // rdx
  CCipherMill *v39; // rcx
  const wchar_t *v40; // r9
  unsigned __int16 v41; // dx
  _QWORD *v42; // rax
  __int64 v43; // rdx
  __int64 v44; // [rsp+20h] [rbp-58h]
  int v45; // [rsp+80h] [rbp+8h]
  int v46; // [rsp+88h] [rbp+10h]

  v4 = 0;
  v45 = *((_DWORD *)a1 + 16) & 0x40051555;
  v7 = a2;
  if ( !a3 || a4 < 0x3D )
    return 87;
  v9 = a2 & 1;
  if ( (a2 & 1) != 0 )
  {
    *((_QWORD *)a1 + 22) = *(_QWORD *)a3;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Du, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
  }
  v46 = v7 & 2;
  if ( (v7 & 2) != 0 )
  {
    *((_QWORD *)a1 + 23) = *((_QWORD *)a3 + 1);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Eu, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
  }
  v10 = a3 + 16;
  if ( v9
    && (v11 = *(int *)v10, *((_DWORD *)a1 + 48) = v11, WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control)
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Fu, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v11);
    v12 = v10 + 4;
    v13 = v12;
  }
  else
  {
    v12 = v10 + 4;
    v13 = v12;
    if ( !v9 )
      goto LABEL_17;
  }
  *((_QWORD *)a1 + 25) = *v12;
  if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
  {
LABEL_17:
    v14 = v12 + 1;
    if ( !v9 )
      goto LABEL_21;
    goto LABEL_18;
  }
  WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x20u, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
  v14 = v13 + 1;
LABEL_18:
  *((_QWORD *)a1 + 26) = *v14;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x21u, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
LABEL_21:
  v15 = *((unsigned __int16 *)v14 + 4);
  *((_WORD *)a1 + 108) = v15;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 34i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v15);
  v16 = *((unsigned __int16 *)v14 + 5);
  *((_WORD *)a1 + 109) = v16;
  v17 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 35i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v16);
    v17 = WPP_GLOBAL_Control;
  }
  v18 = (_DWORD *)v14 + 3;
  if ( v9 )
  {
    v19 = *v18;
    if ( v17 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v17 + 28) & 4) != 0 )
      WPP_SF_D(*((_QWORD *)v17 + 2), 36i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v19);
    v20 = (unsigned int *)*((_QWORD *)a1 + 28);
    if ( v20 )
    {
      *v20 = v19;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          37i64,
          &WPP_66cada2652f531372f2ad4492a08a619_Traceguids,
          **((unsigned int **)a1 + 28));
    }
  }
  v21 = v18 + 1;
  LOBYTE(a2) = *v21;
  (*(void (__fastcall **)(struct CSslContext *, __int64))(*(_QWORD *)a1 + 408i64))(a1, a2);
  v22 = *(unsigned int *)++v21;
  v21 += 4;
  v23 = *(unsigned int *)v21;
  v21 += 4;
  v24 = *(unsigned int *)v21;
  v21 += 4;
  v25 = *(_DWORD *)v21;
  v26 = v21 + 4;
  if ( (unsigned int)v22 > 0x10000 || (unsigned int)v23 > 0x10000 || (unsigned int)v24 > 0x10000 || v25 > 0x10000 )
    return 87;
  if ( a4 - 61 != (_DWORD)v22 + (_DWORD)v23 + v25 + (_DWORD)v24 )
  {
    v4 = 1359;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 38i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
    return v4;
  }
  v27 = v26;
  v28 = &v26[v22];
  v29 = &v26[v22 + v23];
  if ( v9 )
  {
    if ( (_DWORD)v22 )
    {
      v33 = (__int64 *)*((_QWORD *)a1 + 1);
      if ( v33 )
        v34 = *v33;
      else
        v34 = 0i64;
      v4 = SslImportKey(v34, (char *)a1 + 144, L"OpaqueKeyBlob", v27, v22, 0);
      if ( v4 )
      {
        v35 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          return v4;
        v36 = 39i64;
LABEL_65:
        WPP_SF_D(*((_QWORD *)v35 + 2), v36, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v4);
        return v4;
      }
    }
    else
    {
      *((_QWORD *)a1 + 18) = 0i64;
    }
  }
  if ( v46 )
  {
    if ( !(_DWORD)v23 )
    {
      *((_QWORD *)a1 + 19) = 0i64;
      goto LABEL_45;
    }
    v30 = (_QWORD *)*((_QWORD *)a1 + 1);
    v31 = v30 ? *v30 : 0i64;
    v4 = SslImportKey(v31, (char *)a1 + 152, L"OpaqueKeyBlob", v28, v23, 0);
    if ( v4 )
    {
      v35 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return v4;
      v36 = 40i64;
      goto LABEL_65;
    }
  }
LABEL_45:
  if ( (_DWORD)v24
    && ((v37 = (__int64 *)*((_QWORD *)a1 + 1)) == 0i64 ? (v38 = 0i64) : (v38 = *v37),
        LOBYTE(v27) = 1,
        (v4 = (*(__int64 (__fastcall **)(struct CSslContext *, __int64, _BYTE *, _BYTE *, _DWORD))(*(_QWORD *)a1 + 400i64))(
                a1,
                v38,
                v27,
                v29,
                v24)) != 0) )
  {
    v39 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v40 = L"server";
      v41 = 41;
      if ( v45 )
        v40 = L"client";
      goto LABEL_81;
    }
  }
  else if ( v25 )
  {
    v42 = (_QWORD *)*((_QWORD *)a1 + 1);
    v43 = v42 ? *v42 : 0i64;
    v4 = (*(__int64 (__fastcall **)(struct CSslContext *, __int64, _QWORD, _BYTE *, unsigned int))(*(_QWORD *)a1 + 400i64))(
           a1,
           v43,
           0i64,
           &v29[v24],
           v25);
    if ( v4 )
    {
      v39 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        v40 = L"server";
        v41 = 42;
        if ( !v45 )
          v40 = L"client";
LABEL_81:
        LODWORD(v44) = v4;
        WPP_SF_SD(*((_QWORD *)v39 + 2), v41, (__int64)&WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v40, v44);
      }
    }
  }
  return v4;
}
// 180011622: variable 'a2' is possibly undefined
// 18003A9A2: variable 'v27' is possibly undefined
// 18003AA20: variable 'v44' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180084B40: using guessed type wchar_t aServer_1[7];
// 180084B50: using guessed type wchar_t aClient[7];
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
