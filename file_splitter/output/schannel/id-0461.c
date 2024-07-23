// File count: 461
// Total lines: 356
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::ParseClientHello(
        CTls13ServerHandshake *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *const a4,
        unsigned int *a5,
        unsigned int **a6,
        unsigned int *a7)
{
  CTls13ServerHandshake *v7; // r11
  unsigned int v10; // r13d
  __int64 v12; // rcx
  bool v13; // r14
  const void **v14; // r10
  unsigned int *v15; // r8
  unsigned int v16; // edi
  unsigned int v17; // edi
  SIZE_T v18; // rsi
  unsigned __int8 *v19; // rbx
  unsigned int v20; // edi
  size_t v21; // r14
  unsigned __int16 *v22; // rbx
  unsigned int v23; // edi
  unsigned __int16 *v24; // r15
  unsigned __int16 v25; // bp
  unsigned __int8 *v26; // rbx
  unsigned int v27; // edi
  unsigned __int16 v28; // si
  unsigned int v29; // r12d
  _DWORD *v30; // r9
  _DWORD *v31; // rdx
  int v32; // eax
  int v33; // ecx
  unsigned int v34; // ebx
  __int64 v35; // rsi
  unsigned int v36; // edi
  char *v37; // rcx
  __int64 v38; // rdx
  unsigned int v39; // edi
  char *v40; // r9
  unsigned int v41; // edi
  unsigned int v42; // ebx
  __int64 v43; // r12
  char *v44; // rdi
  unsigned __int8 v45; // r14
  __int64 v46; // rax
  char v47; // r15
  CCipherMill *v48; // r10
  unsigned __int16 v49; // si
  unsigned int v50; // ebp
  unsigned int *v51; // rdi
  unsigned int v52; // ebx
  unsigned int v53; // eax
  unsigned __int8 v55; // r9
  int v56; // edx
  __int64 v57; // rax
  unsigned int v58; // edi
  unsigned int *Memory; // [rsp+30h] [rbp-48h]
  unsigned int v61; // [rsp+88h] [rbp+10h]

  v7 = this;
  v10 = 0;
  v12 = *((_QWORD *)this + 1);
  v13 = *(_DWORD *)(v12 + 68) == 71;
  if ( !a2 )
    return 87i64;
  if ( !a3 )
    return 87i64;
  if ( !a5 )
    return 87i64;
  v14 = (const void **)a6;
  if ( !a6 )
    return 87i64;
  v15 = a7;
  if ( !a7 )
    return 87i64;
  if ( a3 < 2 )
  {
    v10 = -2146893048;
    goto LABEL_66;
  }
  if ( (a2[1] | (*a2 << 8)) < 0x300u )
  {
    v55 = 70;
    v56 = 1201;
LABEL_64:
    CSslContext::SetErrorAndFatalAlert(v12, v56, -2146893048, v55);
    v10 = -2146893048;
    goto LABEL_65;
  }
  v16 = a3 - 2;
  if ( v16 < 0x20 )
    goto LABEL_62;
  if ( *(_DWORD *)(v12 + 68) == 71 )
  {
    if ( RtlCompareMemory(a2 + 2, (const void *)(v12 + 272), 0x20ui64) != 32 )
      goto LABEL_72;
    v7 = this;
    v15 = a7;
    v14 = (const void **)a6;
  }
  else
  {
    *(_OWORD *)(v12 + 272) = *(_OWORD *)(a2 + 2);
    *(_OWORD *)(v12 + 288) = *(_OWORD *)(a2 + 18);
  }
  v17 = v16 - 32;
  if ( !v17 || (v18 = a2[34], (unsigned __int8)v18 > 0x20u) || (v19 = a2 + 35, v20 = v17 - 1, v20 < (unsigned int)v18) )
  {
    v12 = *((_QWORD *)v7 + 1);
    goto LABEL_62;
  }
  if ( v13 )
  {
    v12 = *((_QWORD *)v7 + 1);
    if ( *(_BYTE *)(v12 + 1281) != (_BYTE)v18 )
    {
      v55 = 47;
      goto LABEL_63;
    }
  }
  if ( (_BYTE)v18 )
  {
    if ( !v13 )
    {
      v21 = v18;
LABEL_18:
      memcpy_0(a4, v19, v21);
      v7 = this;
      v15 = a7;
      v14 = (const void **)a6;
      goto LABEL_19;
    }
    if ( *((_QWORD *)v7 + 1) == -1249i64 )
    {
      v10 = -2146893052;
      goto LABEL_66;
    }
    v21 = v18;
    if ( RtlCompareMemory(v19, (const void *)(*((_QWORD *)v7 + 1) + 1249i64), v18) == v18 )
      goto LABEL_18;
LABEL_72:
    v55 = 47;
    v12 = *((_QWORD *)this + 1);
    goto LABEL_63;
  }
LABEL_19:
  *a5 = v18;
  v22 = (unsigned __int16 *)&v19[v18];
  v12 = *((_QWORD *)v7 + 1);
  v23 = v20 - v18;
  if ( *(_BYTE *)(v12 + 233) )
  {
    if ( !v23 )
      goto LABEL_62;
    v57 = *(unsigned __int8 *)v22;
    if ( (unsigned __int8)v57 > 0x20u )
      goto LABEL_62;
    v58 = v23 - 1;
    if ( v58 < (unsigned int)v57 )
      goto LABEL_62;
    v22 = (unsigned __int16 *)((char *)v22 + v57 + 1);
    v23 = v58 - v57;
  }
  v24 = v22;
  if ( v23 < 2
    || (v25 = _byteswap_ushort(*v22), v25 < 2u)
    || (v25 & 1) != 0
    || (v26 = (unsigned __int8 *)(v22 + 1), v27 = v23 - 2, v27 < v25) )
  {
LABEL_62:
    v55 = 50;
LABEL_63:
    v56 = 1200;
    goto LABEL_64;
  }
  v28 = v25 >> 1;
  v29 = v25 >> 1;
  v61 = v29;
  if ( v29 > *v15 )
  {
    Memory = (unsigned int *)CSslContext::GetMemory((CSslContext *)v12, 4 * (unsigned int)v28);
    v30 = Memory;
    if ( !Memory )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_d(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x1Fu,
          (__int64)WPP_922678f99ae534148d3bb024010f1556_Traceguids,
          4 * v29);
      v10 = 14;
      goto LABEL_65;
    }
    v7 = this;
    v14 = (const void **)a6;
  }
  else
  {
    v30 = *v14;
    Memory = (unsigned int *)*v14;
  }
  if ( v28 )
  {
    v31 = v30;
    v15 = (unsigned int *)(v25 >> 1);
    do
    {
      v32 = *v26;
      ++v31;
      v33 = v26[1];
      v26 += 2;
      *(v31 - 1) = (v32 << 8) | v33;
      v15 = (unsigned int *)((char *)v15 - 1);
    }
    while ( v15 );
  }
  v34 = v25 >> 1;
  v35 = *(_QWORD *)(*((_QWORD *)v7 + 1) + 120i64);
  if ( v35 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
  {
    *(_DWORD *)(v35 + 1580) = v29;
    if ( v29 > 0x64 )
      v34 = 100;
    memcpy_0((void *)(v35 + 1176), v30, 4i64 * v34);
    v7 = this;
    v14 = (const void **)a6;
    *(_WORD *)(v35 + 1576) = v34;
  }
  v36 = v27 - v25;
  v37 = (char *)v24 + v25;
  if ( !v36 )
    goto LABEL_83;
  v38 = (unsigned __int8)v37[2];
  if ( !(_BYTE)v38 )
  {
    v10 = -2146893048;
    goto LABEL_100;
  }
  v39 = v36 - 1;
  if ( v39 < (unsigned int)v38 )
    goto LABEL_83;
  v40 = v37 + 3;
  if ( v37[3] )
  {
    while ( v40 != &v37[v38 + 2] )
    {
      if ( !*++v40 )
        goto LABEL_38;
    }
LABEL_83:
    CSslContext::SetErrorAndFatalAlert(*((_QWORD *)v7 + 1), 1200, -2146893048, 0x32u);
    v10 = -2146893048;
    goto LABEL_99;
  }
LABEL_38:
  v41 = v39 - v38;
  if ( v41 < 2 )
    goto LABEL_54;
  v42 = (unsigned __int8)v37[v38 + 4] | ((unsigned __int8)v37[v38 + 3] << 8);
  if ( v41 < v42 )
    goto LABEL_54;
  v43 = *((_QWORD *)v7 + 2);
  v44 = &v37[v38 + 5];
  v45 = 0;
  v46 = *(_QWORD *)(v43 + 8);
  v47 = *(_BYTE *)(v46 + 64) & 0x30;
  *(_DWORD *)(v43 + 16) = 1;
  *(_BYTE *)(v46 + 922) = 0;
  *(_BYTE *)(v43 + 27) = 0;
  if ( !v42 )
  {
LABEL_52:
    (*(void (__fastcall **)(_QWORD, _QWORD, unsigned int *, char *))(**(_QWORD **)(v43 + 8) + 352i64))(
      *(_QWORD *)(v43 + 8),
      v45,
      v15,
      v40);
    v10 = 0;
LABEL_53:
    v29 = v61;
LABEL_54:
    v15 = a7;
    *a6 = Memory;
    goto LABEL_55;
  }
  v48 = WPP_GLOBAL_Control;
  while ( 1 )
  {
    if ( v42 < 4 )
      goto LABEL_96;
    v49 = _byteswap_ushort(*((_WORD *)v44 + 1));
    v50 = (unsigned __int8)v44[1] | ((unsigned __int8)*v44 << 8);
    if ( v48 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v48 + 28) & 4) != 0 )
    {
      WPP_SF_D(*((_QWORD *)v48 + 2), 73i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids, v50);
      v48 = WPP_GLOBAL_Control;
    }
    v51 = (unsigned int *)(v44 + 4);
    v52 = v42 - 4;
    if ( v52 < v49 )
    {
      if ( v48 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v48 + 28) & 2) != 0 )
        WPP_SF_(*((_QWORD *)v48 + 2), 74i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
LABEL_96:
      v10 = -2146893018;
LABEL_97:
      CSslContext::SetErrorAndFatalAlert(*((_QWORD *)this + 1), 1200, -2146893048, 0x32u);
      goto LABEL_98;
    }
    v15 = v51;
    v44 = (char *)v51 + v49;
    v42 = v52 - v49;
    if ( v47 && v50 != 65281 )
      goto LABEL_51;
    v53 = (*(__int64 (__fastcall **)(__int64, _QWORD, unsigned int *, _QWORD))(*(_QWORD *)v43 + 8i64))(
            v43,
            v50,
            v15,
            v49);
    v10 = v53;
    if ( v53 )
      break;
    v48 = WPP_GLOBAL_Control;
    if ( v50 == 65281 )
      v45 = 1;
LABEL_51:
    if ( !v42 )
      goto LABEL_52;
  }
  if ( v53 != -2146892986 && v53 != -2146892953 )
    goto LABEL_97;
LABEL_98:
  if ( !v10 )
    goto LABEL_53;
LABEL_99:
  v14 = (const void **)a6;
  v7 = this;
LABEL_100:
  if ( Memory && Memory != *v14 )
    (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v7 + 1) + 16i64))(*((_QWORD *)v7 + 1));
LABEL_65:
  v15 = a7;
LABEL_66:
  v29 = 0;
LABEL_55:
  *v15 = v29;
  return v10;
}
// 18002260E: variable 'v15' is possibly undefined
// 18002260E: variable 'v40' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
