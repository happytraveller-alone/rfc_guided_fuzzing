//----- (0000000180019B10) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::TlsParseClientHello(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned __int8 *const a4,
        unsigned int *a5,
        unsigned int **a6,
        unsigned int *a7)
{
  CSsl3TlsServerContext *v7; // r14
  unsigned int v8; // ecx
  __int64 v9; // rax
  bool v10; // r12
  __int64 v11; // rsi
  unsigned __int8 *v12; // rbx
  int v13; // edi
  unsigned __int8 *v14; // rbx
  unsigned int v15; // edi
  int v16; // eax
  unsigned int v17; // r15d
  unsigned __int8 *v18; // rbx
  unsigned int v19; // edi
  unsigned int v20; // ebp
  unsigned int **v21; // r11
  unsigned __int8 *v22; // r13
  unsigned int v23; // r10d
  unsigned int v24; // eax
  __int64 v25; // rsi
  unsigned int v26; // r14d
  unsigned int v27; // edi
  unsigned __int8 *v28; // rbx
  unsigned __int8 *v29; // rdx
  __int64 v30; // rcx
  _BYTE *v31; // rbx
  unsigned int v32; // edi
  unsigned int v33; // eax
  unsigned int v34; // edi
  int v35; // ebx
  unsigned int v36; // ebx
  char v37; // r12
  unsigned __int8 v38; // r15
  unsigned __int8 *v39; // rdi
  char v40; // r12
  CCipherMill *v41; // r10
  unsigned __int16 v42; // si
  unsigned int v43; // r14d
  unsigned __int8 *v44; // rdi
  unsigned int v45; // ebx
  unsigned int v46; // eax
  unsigned int v47; // esi
  __int64 result; // rax
  __int64 v49; // rcx
  unsigned int v50; // edi
  CCipherMill *v51; // rcx
  __int64 v52; // rdx
  unsigned int *Memory; // [rsp+30h] [rbp-68h]
  void **v54; // [rsp+38h] [rbp-60h] BYREF
  CSsl3TlsServerContext *v55; // [rsp+40h] [rbp-58h]
  int v56; // [rsp+48h] [rbp-50h]
  int v57; // [rsp+4Ch] [rbp-4Ch]
  __int16 v58; // [rsp+50h] [rbp-48h]
  char v59; // [rsp+52h] [rbp-46h]
  char v60; // [rsp+53h] [rbp-45h]
  CSsl3TlsServerContext *v61; // [rsp+58h] [rbp-40h]
  char v63; // [rsp+B0h] [rbp+18h]

  v63 = 0;
  *((_BYTE *)this + 554) = 0;
  v7 = this;
  if ( (unsigned int)a3 < 2 )
    goto LABEL_55;
  v8 = a2[1] + (*a2 << 8);
  if ( v8 < 0x300 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)v7, 1201, -2146893048, 0x46u);
    goto LABEL_55;
  }
  v9 = *((_QWORD *)v7 + 15);
  v10 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
  *((_DWORD *)v7 + 9) = v8;
  if ( v9 && v10 )
    *(_DWORD *)(v9 + 44) = v8;
  if ( (unsigned int)((_DWORD)a3 - 2) < 0x20 )
    goto LABEL_55;
  *((_OWORD *)v7 + 17) = *(_OWORD *)(a2 + 2);
  *((_OWORD *)v7 + 18) = *(_OWORD *)(a2 + 18);
  if ( (_DWORD)a3 == 34 )
    goto LABEL_55;
  v11 = a2[34];
  if ( (unsigned int)v11 > 0x20 )
    goto LABEL_55;
  v12 = a2 + 35;
  v13 = (_DWORD)a3 - 35;
  if ( (int)a3 - 35 < (unsigned int)v11 )
    goto LABEL_55;
  if ( a2[34] )
    memcpy_0(a4, v12, a2[34]);
  v14 = &v12[v11];
  v15 = v13 - v11;
  *a5 = v11;
  if ( *((_BYTE *)v7 + 233) )
  {
    if ( !v15 )
      goto LABEL_55;
    v49 = *v14;
    if ( (unsigned int)v49 > 0x20 )
      goto LABEL_55;
    v50 = v15 - 1;
    if ( v50 < (unsigned int)v49 )
      goto LABEL_55;
    v14 += v49 + 1;
    v15 = v50 - v49;
  }
  if ( v15 < 2 || (v16 = v14[1], v17 = v16 + (*v14 << 8), (v16 & 1) != 0) || (v18 = v14 + 2, v19 = v15 - 2, v19 < v17) )
  {
LABEL_55:
    v47 = -2146893048;
    v23 = 0;
    goto LABEL_51;
  }
  v20 = v17 >> 1;
  if ( v17 >> 1 > *a7 )
  {
    Memory = (unsigned int *)CSslContext::GetMemory(v7, 4 * v20);
    v22 = (unsigned __int8 *)Memory;
    if ( Memory )
    {
      v10 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
      v21 = a6;
      goto LABEL_18;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_d(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x36u,
        (__int64)&WPP_095c39149c3f336b5b94efe855075ae2_Traceguids,
        4 * v20);
      v23 = 0;
      v47 = -2146893048;
      goto LABEL_51;
    }
    goto LABEL_55;
  }
  v21 = a6;
  v22 = (unsigned __int8 *)*a6;
  Memory = *a6;
LABEL_18:
  v23 = 0;
  v24 = 0;
  if ( v20 )
  {
    a4 = v22;
    do
    {
      a3 = (unsigned __int8 *)(v18[2 * v24 + 1] | (v18[2 * v24] << 8));
      *(_DWORD *)a4 = (_DWORD)a3;
      if ( (_DWORD)a3 == 255 )
      {
        if ( *((_DWORD *)v7 + 104) )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 55i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
          }
          CSslContext::SetErrorAndFatalAlert((__int64)v7, 1207, -2146892986, 0x28u);
          *((_DWORD *)v7 + 17) = 96;
          v47 = -2146892986;
          *((_WORD *)v7 + 48) = 10242;
          goto LABEL_82;
        }
        *((_BYTE *)v7 + 553) = 1;
        v63 = 1;
      }
      ++v24;
      a4 += 4;
    }
    while ( v24 < v20 );
  }
  v25 = *((_QWORD *)v7 + 15);
  v26 = v17 >> 1;
  if ( v25 && v10 )
  {
    *(_DWORD *)(v25 + 1580) = v20;
    if ( v20 > 0x64 )
      v26 = 100;
    memcpy_0((void *)(v25 + 1176), v22, 4i64 * v26);
    v21 = a6;
    v23 = 0;
    *(_WORD *)(v25 + 1576) = v26;
  }
  v27 = v19 - v17;
  v28 = &v18[v17];
  v29 = v28;
  if ( !v27 )
  {
    v7 = this;
    v47 = -2146893048;
    goto LABEL_83;
  }
  v30 = *v28;
  if ( !*v28 )
  {
    v7 = this;
    v47 = -2146893048;
    goto LABEL_83;
  }
  v31 = v28 + 1;
  v32 = v27 - 1;
  if ( v32 < (unsigned int)v30 )
  {
    v7 = this;
    v47 = -2146893048;
    goto LABEL_83;
  }
  v33 = 0;
  while ( *v31 )
  {
    ++v33;
    ++v31;
    if ( v33 >= (unsigned int)v30 )
    {
      if ( v33 == (_DWORD)v30 )
      {
        v7 = this;
        v47 = -2146893048;
        goto LABEL_83;
      }
      break;
    }
  }
  v34 = v32 - v30;
  if ( v34 < 2 )
    goto LABEL_47;
  v7 = this;
  v35 = v29[v30 + 1];
  v54 = &CTlsExtServer::`vftable';
  v36 = v29[v30 + 2] | (v35 << 8);
  v55 = this;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v61 = this;
  if ( v34 - 2 < v36 )
  {
LABEL_48:
    v47 = 0;
    goto LABEL_49;
  }
  v37 = *((_BYTE *)this + 64);
  v38 = 0;
  v56 = 1;
  v39 = &v29[v30 + 3];
  *((_BYTE *)this + 922) = 0;
  v40 = v37 & 0x30;
  v60 = 0;
  if ( !v36 )
  {
LABEL_46:
    (*(void (__fastcall **)(CSsl3TlsServerContext *, _QWORD, unsigned __int8 *, unsigned __int8 *const))(*(_QWORD *)v55 + 352i64))(
      v55,
      v38,
      a3,
      a4);
LABEL_47:
    v7 = this;
    goto LABEL_48;
  }
  v41 = WPP_GLOBAL_Control;
  while ( 1 )
  {
    if ( v36 < 4 )
      goto LABEL_89;
    v42 = _byteswap_ushort(*((_WORD *)v39 + 1));
    v43 = v39[1] | (*v39 << 8);
    if ( v41 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v41 + 28) & 4) != 0 )
    {
      WPP_SF_D(*((_QWORD *)v41 + 2), 73i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids, v43);
      v41 = WPP_GLOBAL_Control;
    }
    v44 = v39 + 4;
    v45 = v36 - 4;
    if ( v45 < v42 )
    {
      if ( v41 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v41 + 28) & 2) != 0 )
        WPP_SF_(*((_QWORD *)v41 + 2), 74i64, &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
LABEL_89:
      v47 = -2146893018;
      goto LABEL_90;
    }
    a3 = v44;
    v39 = &v44[v42];
    v36 = v45 - v42;
    if ( !v40 || v43 == 65281 )
      break;
LABEL_45:
    if ( !v36 )
      goto LABEL_46;
  }
  v46 = ((__int64 (__fastcall *)(void ***, _QWORD, unsigned __int8 *, _QWORD))v54[1])(&v54, v43, a3, v42);
  v47 = v46;
  if ( !v46 )
  {
    v41 = WPP_GLOBAL_Control;
    if ( v43 == 65281 )
      v38 = 1;
    goto LABEL_45;
  }
  if ( v46 == -2146892986 || v46 == -2146892953 )
  {
    v7 = this;
    goto LABEL_81;
  }
LABEL_90:
  v7 = this;
  CSslContext::SetErrorAndFatalAlert((__int64)this, 1202, -2146893048, 0xAu);
LABEL_81:
  if ( !v47 )
  {
LABEL_49:
    if ( !*((_BYTE *)v7 + 554) && !v63 )
    {
      if ( !g_fAllowInsecureRenegoClients )
      {
        v51 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_101;
        v52 = 56i64;
LABEL_100:
        WPP_SF_(*((_QWORD *)v51 + 2), v52, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
LABEL_101:
        CSslContext::SetErrorAndFatalAlert((__int64)v7, 1207, -2146892986, 0x28u);
        result = 2148074310i64;
        *((_DWORD *)v7 + 17) = 96;
        *((_WORD *)v7 + 48) = 10242;
        return result;
      }
      if ( *((_BYTE *)v7 + 553) )
      {
        v51 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_101;
        v52 = 57i64;
        goto LABEL_100;
      }
    }
    v23 = v20;
    *a6 = Memory;
    goto LABEL_51;
  }
LABEL_82:
  v21 = a6;
  v23 = 0;
  v22 = (unsigned __int8 *)Memory;
LABEL_83:
  if ( v22 && v22 != (unsigned __int8 *)*v21 )
  {
    (*(void (__fastcall **)(CSsl3TlsServerContext *, unsigned __int8 *, unsigned __int8 *, unsigned __int8 *const))(*(_QWORD *)v7 + 16i64))(
      v7,
      v22,
      a3,
      a4);
    v23 = 0;
  }
LABEL_51:
  result = v47;
  *a7 = v23;
  return result;
}
// 180019E70: variable 'a3' is possibly undefined
// 180019E70: variable 'a4' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 18007C320: using guessed type void *CTlsExtServer::`vftable';
// 1800919AC: using guessed type int g_fAllowInsecureRenegoClients;
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

