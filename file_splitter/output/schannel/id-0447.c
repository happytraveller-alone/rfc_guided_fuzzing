// File count: 447
// Total lines: 910
----------------------------------------
__int64 __fastcall SpAcceptLsaModeContext(
        struct CCredentialGroup *a1,
        __int64 a2,
        struct _SecBufferDesc *a3,
        unsigned int a4,
        int a5,
        __int64 *a6,
        __int64 a7,
        _DWORD *a8,
        union _LARGE_INTEGER *a9,
        unsigned __int8 *a10,
        struct _SecBuffer *a11)
{
  unsigned int *v11; // r11
  __int64 v12; // rdi
  __int64 v13; // r12
  __int64 v15; // rax
  unsigned __int64 v16; // r14
  int v18; // r10d
  struct _SecBuffer *v19; // r15
  __int64 v20; // rsi
  unsigned int v21; // ecx
  unsigned int v22; // ebx
  unsigned int v23; // r8d
  __int64 v24; // r9
  _DWORD *v25; // rdx
  int v26; // eax
  _DWORD *v27; // r9
  _DWORD *v28; // rdx
  unsigned __int64 v29; // rcx
  void *pvBuffer; // rax
  __int64 v31; // r8
  __int64 v32; // rsi
  struct CCredentialGroup *v33; // rax
  __int64 v34; // rcx
  struct CCredentialGroup *v35; // rdx
  unsigned int v36; // eax
  __int64 (__fastcall *v37)(__int64, __int64, _QWORD, _QWORD); // rdi
  unsigned __int8 v38; // al
  int v39; // ebx
  __int64 v40; // rax
  __int64 v42; // rbx
  bool v43; // zf
  bool v44; // al
  int v45; // eax
  int v46; // eax
  struct CSslParentContext *v47; // r14
  __int64 v48; // rcx
  int v49; // edi
  int v50; // r13d
  int v51; // ebx
  __int64 v52; // r12
  char v53; // bl
  int v54; // eax
  __int64 v55; // rax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  __int64 v59; // rax
  __int64 *v60; // r9
  __int64 v61; // r9
  unsigned __int64 *v62; // rax
  __int64 v63; // rcx
  unsigned int v64; // ecx
  unsigned int v65; // eax
  void *v66; // rax
  __int64 v67; // rax
  void *v68; // rax
  __int64 v69; // rcx
  __int64 v70; // rax
  __int64 v71; // rdi
  void (__fastcall *v72)(__int64, __int64); // rbx
  __int64 v73; // rax
  void *v74; // rax
  int v75; // eax
  __int64 v76; // rdx
  __int64 v77; // rcx
  struct CSslParentContext *v78; // [rsp+70h] [rbp-90h] BYREF
  __int64 v79; // [rsp+78h] [rbp-88h]
  __int64 v80; // [rsp+80h] [rbp-80h] BYREF
  __int128 v81; // [rsp+90h] [rbp-70h] BYREF
  __int64 v82; // [rsp+A0h] [rbp-60h]
  __int64 v83; // [rsp+A8h] [rbp-58h]
  unsigned __int64 v84; // [rsp+B0h] [rbp-50h]
  struct _SecBuffer *v85; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v86[2]; // [rsp+C0h] [rbp-40h] BYREF
  __int128 v87; // [rsp+D0h] [rbp-30h] BYREF
  struct _SecBuffer *v88; // [rsp+E0h] [rbp-20h] BYREF
  struct _SecBuffer *v89; // [rsp+E8h] [rbp-18h] BYREF
  struct _SecBuffer *v90; // [rsp+F0h] [rbp-10h] BYREF
  struct _SecBuffer *v91; // [rsp+F8h] [rbp-8h] BYREF
  struct _SecBuffer *v92; // [rsp+100h] [rbp+0h] BYREF
  struct _SecBuffer *v93; // [rsp+108h] [rbp+8h] BYREF
  struct _SecBuffer *v94; // [rsp+110h] [rbp+10h] BYREF
  struct _SecBuffer *v95; // [rsp+118h] [rbp+18h] BYREF
  struct _SecBuffer *v96; // [rsp+120h] [rbp+20h] BYREF
  struct _SecBuffer *v97; // [rsp+128h] [rbp+28h] BYREF
  unsigned __int64 *v98; // [rsp+130h] [rbp+30h]
  unsigned int *v99; // [rsp+190h] [rbp+90h]
  __int64 v100; // [rsp+198h] [rbp+98h]
  int v102; // [rsp+1A8h] [rbp+A8h]

  v100 = a2;
  v11 = 0i64;
  v12 = 0i64;
  v13 = 28i64;
  v15 = a2;
  v16 = a4;
  LODWORD(a2) = 0;
  v102 = 0;
  v78 = 0i64;
  v85 = 0i64;
  v97 = 0i64;
  v89 = 0i64;
  v90 = 0i64;
  v92 = 0i64;
  v91 = 0i64;
  v93 = 0i64;
  v95 = 0i64;
  v94 = 0i64;
  v96 = 0i64;
  v88 = 0i64;
  v87 = 0i64;
  v79 = 0i64;
  v81 = 0i64;
  v98 = 0i64;
  v84 = a4;
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
  {
    McTemplateU0pp_EtwEventWriteTransfer((__int64)a1, 0i64, a1, v15);
    v15 = v100;
    v11 = 0i64;
    LODWORD(a2) = 0;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
      v15 = v100;
      v11 = 0i64;
      LODWORD(a2) = 0;
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 41i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
        v15 = v100;
        v11 = 0i64;
        LODWORD(a2) = 0;
      }
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_q(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x2Au,
            (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
            a1);
          v15 = v100;
          v11 = 0i64;
          LODWORD(a2) = 0;
        }
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_q(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0x2Bu,
              (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
              v15);
            v11 = 0i64;
            LODWORD(a2) = 0;
          }
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 44i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids, a4);
            v11 = 0i64;
            LODWORD(a2) = 0;
          }
        }
      }
    }
  }
  if ( !a1 )
  {
    v22 = -2146893055;
    goto LABEL_157;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        45i64,
        &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
        *((unsigned int *)a1 + 53));
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_S(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x2Eu,
        (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
        (const wchar_t *)a1 + 108);
  }
  v18 = 0;
  v19 = 0i64;
  v99 = 0i64;
  v11 = 0i64;
  v80 = 0i64;
  v82 = 0i64;
  v20 = 0i64;
  v21 = 0;
  v22 = 14;
  v23 = *(_DWORD *)(a7 + 4);
  if ( !v23 )
  {
LABEL_34:
    v29 = v16 & 0x100;
    goto LABEL_35;
  }
  v24 = *(_QWORD *)(a7 + 8);
  v25 = (_DWORD *)(v24 + 4);
  do
  {
    v26 = *v25 & 0xFFFFFFF;
    if ( v26 )
    {
      if ( v26 == 2 )
        goto LABEL_111;
      v56 = v26 - 17;
      if ( v56 )
      {
        v57 = v56 - 6;
        if ( v57 )
        {
          v58 = v57 - 3;
          if ( v58 )
          {
            if ( v58 == 1 )
              v20 = v24 + 16i64 * v21;
          }
          else
          {
            v82 = v24 + 16i64 * v21;
          }
        }
        else
        {
          v80 = v24 + 16i64 * v21;
        }
      }
      else
      {
        v11 = (unsigned int *)(v24 + 16i64 * v21);
      }
    }
    else if ( !v19 && (v16 & 0x100) != 0 )
    {
LABEL_111:
      v19 = (struct _SecBuffer *)(v24 + 16i64 * v21);
    }
    ++v21;
    v25 += 4;
  }
  while ( v21 < v23 );
  v27 = (_DWORD *)v80;
  v99 = v11;
  if ( v80 )
  {
    if ( (v16 & 0x100) != 0 )
    {
      *(_QWORD *)(v80 + 8) = 0i64;
      *v27 = 0;
    }
    else if ( !*(_QWORD *)(v80 + 8) )
    {
      v18 = 14;
    }
  }
  v28 = (_DWORD *)v82;
  if ( v82 )
  {
    if ( (v16 & 0x100) != 0 )
    {
      *(_QWORD *)(v82 + 8) = 0i64;
      *v28 = 0;
    }
    else if ( !*(_QWORD *)(v82 + 8) )
    {
      v18 = 14;
    }
  }
  if ( v20 )
  {
    if ( (v16 & 0x100) != 0 )
    {
      *(_QWORD *)(v20 + 8) = 0i64;
      *(_DWORD *)v20 = 0;
    }
    else if ( *(_QWORD *)(v20 + 8) )
    {
      if ( *(_DWORD *)v20 < 8u )
      {
        *(_DWORD *)v20 = 8;
        v18 = -2146893023;
      }
    }
    else
    {
      v18 = 14;
    }
  }
  if ( !v11 )
    goto LABEL_34;
  v29 = v16 & 0x100;
  if ( (v16 & 0x100) != 0 )
  {
    *((_QWORD *)v11 + 1) = 0i64;
    *v11 = 0;
    goto LABEL_189;
  }
  v59 = *((_QWORD *)v11 + 1);
  if ( !v59 )
  {
    v18 = 14;
LABEL_189:
    v59 = 0i64;
  }
  *((_QWORD *)&v87 + 1) = v59;
  *(_QWORD *)&v87 = *v11;
LABEL_35:
  if ( !v19 )
  {
    v22 = -2146893048;
    goto LABEL_192;
  }
  v19->BufferType = 2;
  if ( !v29 )
  {
    pvBuffer = v19->pvBuffer;
    if ( pvBuffer )
      goto LABEL_38;
LABEL_192:
    LODWORD(a2) = 0;
LABEL_157:
    v13 &= ~0x8000ui64;
    goto LABEL_90;
  }
  v19->pvBuffer = 0i64;
  pvBuffer = 0i64;
  v19->cbBuffer = 0;
LABEL_38:
  *((_QWORD *)&v81 + 1) = pvBuffer;
  v22 = v18;
  *(_QWORD *)&v81 = v19->cbBuffer;
  if ( v18 )
  {
    LODWORD(a2) = 0;
  }
  else
  {
    if ( (v16 & 2) != 0 )
    {
      v12 = 256i64;
      v79 = 256i64;
    }
    if ( CSslGlobals::m_dwEnableSessionTicket == 1 || CSslGlobals::m_dwEnableSessionTicket != 2 && (v16 & 0x40) != 0 )
    {
      v12 |= 0x800ui64;
      v79 = v12;
    }
    if ( (v16 & 0x1000000) != 0 )
    {
      v12 |= 0x10000ui64;
      v13 = 16777244i64;
      v79 = v12;
    }
    if ( v29 )
      v13 |= 0x100ui64;
    if ( (v16 & 0x8000) != 0 )
    {
      v13 |= 0x8000ui64;
      v12 |= 0x200ui64;
      v79 = v12;
    }
    if ( (v16 & 0x800) != 0 )
    {
      v13 |= 0x800ui64;
      v12 |= 0x1000ui64;
      v83 = v13;
      v79 = v12;
      if ( (v16 & 0x400) != 0
        && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 47i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
      }
    }
    else
    {
      v13 |= 0x10000ui64;
      v83 = v13;
    }
    if ( (*((_BYTE *)a1 + 156) & 1) != 0 )
    {
      v12 |= 0x10000ui64;
      v79 = v12;
    }
    v22 = ParseInputBufferDesc(
            a3,
            &v85,
            (struct SPBuffer *)v86,
            &v97,
            &v89,
            &v90,
            &v92,
            &v91,
            &v93,
            &v95,
            &v94,
            &v96,
            &v88);
    if ( v22 )
      goto LABEL_84;
    if ( !v88 )
      goto LABEL_56;
    v60 = (__int64 *)v88->pvBuffer;
    if ( v60 && v88->cbBuffer >= 8 )
    {
      v61 = *v60;
      if ( (v61 & 0xFFFFFFFEFFFFFFFFui64) != 0 )
      {
        v22 = -2146892963;
        goto LABEL_84;
      }
      if ( (v61 & 0x100000000i64) != 0 )
      {
        v13 |= 0x100000000ui64;
        v79 = v12 | 0x100000000i64;
        v83 = v13;
      }
      v16 |= v61;
      v84 = v16;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_i(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x30u, (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
      if ( v20 )
      {
        v62 = *(unsigned __int64 **)(v20 + 8);
        if ( !v62 )
        {
          v62 = (unsigned __int64 *)SPExternalAlloc(8u);
          *(_QWORD *)(v20 + 8) = v62;
          if ( !v62 )
          {
            v11 = v99;
            v22 = -2146893056;
            LODWORD(a2) = 0;
            goto LABEL_85;
          }
          *(_DWORD *)v20 = 8;
        }
        v98 = v62;
      }
LABEL_56:
      v31 = 0i64;
      if ( v85 && (v85->BufferType & 0xFFFFFFF) != 2 )
      {
        v86[1] = 0i64;
        v86[0] = 0i64;
      }
      if ( !v100 )
      {
        v22 = CSslContextManager::InstantiateServerContext(
                (CSslContextManager *)&g_SslContextManager,
                (struct SPBuffer *)v86,
                (struct SPBuffer *)&v81,
                v19,
                v89,
                a1,
                v16,
                &v78);
        if ( v22 )
          goto LABEL_84;
        v32 = *((_QWORD *)v78 + 1);
        v42 = *(_QWORD *)(v32 + 120);
        if ( v42 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        {
          *(_DWORD *)(v42 + 12) = 1;
          QueryPerformanceCounter((LARGE_INTEGER *)(v42 + 80));
          v43 = *(_DWORD *)(v42 + 12) == 1;
          *(_DWORD *)(v42 + 24) = 0;
          v44 = v43;
          v43 = !CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
          *(_BYTE *)(v42 + 28) = v44;
          *(_QWORD *)(v42 + 144) = v78;
          *(_QWORD *)(v42 + 120) = v16;
          *(_QWORD *)(v42 + 136) = a1;
          if ( !v43 )
            o_wcsncpy_s_0(v42 + 664, 256i64, (char *)a1 + 216, -1i64);
        }
        goto LABEL_64;
      }
      v32 = *(_QWORD *)(v100 + 8);
      a2 = 1i64;
      v102 = 1;
      v78 = (struct CSslParentContext *)v100;
      if ( _InterlockedIncrement((volatile signed __int32 *)v100) == 1 )
      {
        v33 = *(struct CCredentialGroup **)(v32 + 80);
        if ( v33 && v33 != a1 )
        {
          v22 = -2146893055;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            v11 = v99;
          }
          else
          {
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              50i64,
              &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
              2148074241i64);
            v11 = v99;
            LODWORD(a2) = 1;
          }
          goto LABEL_85;
        }
        *(_WORD *)(v100 + 34) = 0;
        *(_DWORD *)(v100 + 36) = 0;
LABEL_64:
        v34 = *((_QWORD *)v78 + 3);
        if ( v34 )
          (*(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v34 + 56i64))(v34, a2, v31);
        v35 = *(struct CCredentialGroup **)(v32 + 80);
        if ( v35 != a1 )
        {
          if ( v35 )
          {
            CSslCredManager::DereferenceCredentialGroup(CSslCredManager::m_pCredManager, v35);
            (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v32 + 256i64))(v32, 0i64);
          }
          _InterlockedIncrement((volatile signed __int32 *)a1 + 6);
          *(_QWORD *)(v32 + 80) = a1;
          v45 = *((_DWORD *)a1 + 39);
          if ( (v45 & 4) != 0 )
          {
            v63 = *(_QWORD *)(v32 + 136);
            if ( (v63 & 0x100) == 0 )
            {
              *(_QWORD *)(v32 + 136) = v63 | 0x4000;
              v45 = *((_DWORD *)a1 + 39);
            }
          }
          if ( (v45 & 0x4000) != 0 )
          {
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_c955f13c15ab3d9e41a0e2d56db0bfe4_Traceguids);
            }
            *(_QWORD *)(v32 + 136) |= 0x200000000ui64;
          }
          v46 = *(_DWORD *)(v32 + 68);
          if ( v46 == 91 || v46 == 101 )
          {
            if ( *(_BYTE *)(v32 + 266) )
            {
              *(_BYTE *)(v32 + 923) = 1;
              CSsl3TlsClientContext::SetDefCredSearched(v32, 0);
            }
            else
            {
              CSsl3TlsClientContext::CheckForClientCred((CSsl3TlsClientContext *)v32);
            }
          }
        }
        *(_QWORD *)(v32 + 136) |= v79;
        if ( (*(_DWORD *)(v32 + 68) & 0xFFFFFFFB) == 0 )
        {
          v22 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *, __int64))(*(_QWORD *)v32 + 296i64))(
                  v32,
                  v90,
                  v31);
          if ( v22 )
            goto LABEL_84;
          v22 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *, struct _SecBuffer *))(*(_QWORD *)v32 + 304i64))(
                  v32,
                  v92,
                  v91);
          if ( v22 )
            goto LABEL_84;
          v22 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v32 + 312i64))(v32, v93);
          if ( v22 )
            goto LABEL_84;
        }
        v22 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *, struct _SecBuffer *))(*(_QWORD *)v32 + 328i64))(
                v32,
                v95,
                v94);
        if ( v22 )
          goto LABEL_84;
        v22 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v32 + 344i64))(v32, v96);
        if ( v22 )
          goto LABEL_84;
        v36 = (*(__int64 (__fastcall **)(__int64, struct _SecBufferDesc *, __int64))(*(_QWORD *)v32 + 368i64))(
                v32,
                a3,
                v82);
        v22 = v36;
        if ( v36 )
        {
          if ( *(_DWORD *)(v32 + 68) == 4 && v36 == 590614 )
          {
            v39 = 0;
            goto LABEL_75;
          }
LABEL_84:
          v11 = v99;
          LODWORD(a2) = v102;
          goto LABEL_85;
        }
        v37 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD))(*(_QWORD *)v32 + 376i64);
        if ( (v16 & 0x100) != 0 )
          LOBYTE(v22) = 1;
        v38 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v32 + 384i64))(v32);
        v22 = v37(v32, a7, v38, (unsigned __int8)v22);
        if ( v22 )
          goto LABEL_84;
        v39 = (*(__int64 (__fastcall **)(__int64, __int64 *, __int128 *))(*(_QWORD *)v32 + 192i64))(v32, v86, &v81);
        if ( v39 != 1359 || (*(_DWORD *)(v32 + 136) & 0x40000) == 0 )
          goto LABEL_75;
        v47 = v78;
        if ( !v100 )
        {
          v32 = *((_QWORD *)v78 + 2);
          if ( v32 )
          {
            v78 = *(struct CSslParentContext **)(v32 + 128);
            if ( v78 )
            {
              v48 = *((_QWORD *)v47 + 1);
              *((_QWORD *)v47 + 2) = 0i64;
              v49 = *(_DWORD *)(v48 + 64);
              v50 = *(_DWORD *)(v48 + 68);
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_q(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  0x12u,
                  (__int64)&WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids,
                  v47);
                v48 = *((_QWORD *)v47 + 1);
              }
              if ( v48 )
              {
                v51 = *(_DWORD *)(v48 + 64);
                (**(void (__fastcall ***)(__int64, _QWORD))v48)(v48, 0i64);
                if ( (v51 & 0x800A2AAA) != 0 )
                  SPExternalFree(*((void **)v47 + 1));
                *((_QWORD *)v47 + 1) = 0i64;
              }
              if ( (v49 & 0x51550) != 0 )
              {
                v52 = *((_QWORD *)v47 + 3);
                v53 = *((_BYTE *)v47 + 32);
                if ( !v52 )
                  goto LABEL_145;
                if ( v50 == 4 )
                {
                  v64 = (*(unsigned __int16 (__fastcall **)(_QWORD))(*(_QWORD *)v52 + 64i64))(*((_QWORD *)v47 + 3));
                  v65 = qword_180092DB8;
                  if ( (unsigned int)qword_180092DB8 <= v64 )
                    v65 = v64;
                  LODWORD(qword_180092DB8) = v65;
                  if ( _InterlockedIncrement((_DWORD *)&qword_180092DB0 + 1) == 100 )
                  {
                    if ( *((_QWORD *)&xmmword_180092DD0 + 1) )
                    {
                      LODWORD(qword_180092DC0) = qword_180092DB8;
                      if ( dword_180092DE0 )
                      {
                        v66 = operator new(0x80ui64);
                        if ( v66 )
                        {
                          v67 = CSslLookasidePreallocate::CSslLookasidePreallocate(
                                  (__int64)v66,
                                  qword_180092DC0,
                                  dword_180092DE0);
                          goto LABEL_244;
                        }
                      }
                      else
                      {
                        v68 = operator new(0x50ui64);
                        if ( v68 )
                        {
                          v67 = CSslLookaside::CSslLookaside((__int64)v68, qword_180092DC0, 1);
LABEL_244:
                          v69 = v67;
                          v70 = *((_QWORD *)&xmmword_180092DD0 + 1);
                          if ( v69 )
                            v70 = v69;
                          *((_QWORD *)&xmmword_180092DD0 + 1) = v70;
                        }
                      }
                    }
                  }
                }
                if ( v53 )
                {
                  v74 = (void *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v52 + 40i64))(v52);
                  SPExternalFree(v74);
                }
                else
                {
                  v71 = *((_QWORD *)&xmmword_180092DD0 + 1);
                  v72 = *(void (__fastcall **)(__int64, __int64))(**((_QWORD **)&xmmword_180092DD0 + 1) + 32i64);
                  v73 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v52 + 40i64))(v52);
                  v72(v71, v73);
                }
LABEL_145:
                *((_QWORD *)v47 + 3) = 0i64;
                (*(void (__fastcall **)(_QWORD, struct CSslParentContext *))(*(_QWORD *)xmmword_180092DD0 + 32i64))(
                  xmmword_180092DD0,
                  v47);
                v13 = v83;
              }
              else
              {
                SPExternalFree(v47);
              }
              v54 = (*(__int64 (__fastcall **)(__int64, __int64 *, __int128 *))(*(_QWORD *)v32 + 192i64))(
                      v32,
                      v86,
                      &v81);
              v16 = v84;
              v39 = v54;
LABEL_75:
              v40 = *(_QWORD *)(v32 + 136);
              if ( (v40 & 0x10000000) != 0 )
              {
                v13 |= 0x8000ui64;
                *(_QWORD *)(v32 + 136) = v40 & 0xFFFFFFFFEFFFFFFFui64;
              }
              if ( v39 && !*((_DWORD *)v78 + 9) )
                *((_DWORD *)v78 + 9) = v39;
              if ( v99 )
                GenerateFatalAlertMessage(v39, v32, v16, (__int64)&v87);
              if ( v39 == 590624 && v80 )
                GeneratePSKExchangeMessage(v32, v80);
              if ( v100
                || !v39
                || v39 == 590614
                || v39 == -2146892950
                || HIBYTE(*(_WORD *)(v32 + 34)) == 0xFE && v39 == 590692 )
              {
                *a6 = (__int64)v78;
              }
              else
              {
                if ( (v16 & 0x100) != 0 && *((_QWORD *)&v81 + 1) )
                {
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v32 + 16i64))(v32);
                  *((_QWORD *)&v81 + 1) = 0i64;
                }
                CSslContextManager::DeleteFullSslContext((CSslContextManager *)&g_SslContextManager, v78);
                v32 = 0i64;
              }
              v22 = AscIscPostProcessing(
                      v39,
                      (struct CSslContext *)v32,
                      v78,
                      a11,
                      v97,
                      v85,
                      (struct SPBuffer *)v86,
                      v19,
                      (struct SPBuffer *)&v81,
                      v16,
                      a10,
                      a9);
              if ( !v22 && v32 && *(_DWORD *)(v32 + 68) == 4 )
              {
                v55 = *(_QWORD *)v32;
                v80 = 0i64;
                (*(void (__fastcall **)(__int64, __int64 *))(v55 + 232))(v32, &v80);
                if ( *(_QWORD *)(v80 + 344) )
                  v13 |= 2ui64;
                v11 = v99;
                LODWORD(a2) = v102;
                if ( (*(_DWORD *)(v32 + 136) & 0x400000) != 0 )
                  v13 |= 0x40ui64;
                goto LABEL_85;
              }
              goto LABEL_84;
            }
          }
        }
        LOWORD(v16) = v84;
        v22 = 1359;
        v11 = v99;
        LODWORD(a2) = v102;
      }
      else
      {
        v11 = v99;
        v22 = 120;
      }
    }
    else
    {
      v11 = v99;
      v22 = 87;
      LODWORD(a2) = 0;
    }
  }
LABEL_85:
  if ( !v19->cbBuffer || DWORD1(v81) > (unsigned int)v81 || v22 == -2146892949 )
    goto LABEL_157;
  if ( (v16 & 0x8000) != 0 )
    v13 |= 0x8000ui64;
LABEL_90:
  if ( v11 )
  {
    *((_QWORD *)v11 + 1) = *((_QWORD *)&v87 + 1);
    *v11 = DWORD1(v87);
  }
  if ( a8 )
    *a8 = v13;
  if ( v98 )
    *v98 = v13 & 0xFFFFFFFF00000000ui64;
  if ( (_DWORD)a2 && v78 )
    _InterlockedDecrement((volatile signed __int32 *)v78);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 51i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids, v22);
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
  {
    v75 = TranslateToSecurityStatus(v22);
    McTemplateU0pd_EtwEventWriteTransfer(v77, v76, *a6, v75);
  }
  if ( (v22 & 0x1FFF0000) == 589824 )
  {
    if ( v22 + 2146893823 > 0x2E )
    {
      if ( v22 + 2146889727 > 0x100E && v22 + 2146885612 > 0xFEC && v22 != -2146885615 )
        return v22;
LABEL_263:
      if ( v22 > 0x80092004 )
      {
        switch ( v22 )
        {
          case 0x800B0101:
          case 0x800B0102:
            return (unsigned int)-2146893016;
          case 0x800B0109:
            return (unsigned int)-2146893019;
          case 0x800B010C:
            return (unsigned int)-2146885616;
          case 0x800B010F:
            return (unsigned int)-2146893022;
        }
      }
      else
      {
        switch ( v22 )
        {
          case 0x80092004:
            return (unsigned int)-2146893043;
          case 0xEu:
            return (unsigned int)-2146893056;
          case 0x57u:
            return (unsigned int)-2146892963;
          case 0x78u:
            return (unsigned int)-2146893054;
          case 0x7Au:
            return (unsigned int)-2146893023;
        }
      }
    }
    return (unsigned int)-2146893052;
  }
  if ( v22 )
    goto LABEL_263;
  return 0i64;
}
// 180032A0E: conditional instruction was optimized away because ecx.4 is in (FE00..FEFF)
// 18003270F: variable 'a2' is possibly undefined
// 18003270F: variable 'v31' is possibly undefined
// 180032AD5: variable 'v77' is possibly undefined
// 180032AD5: variable 'v76' is possibly undefined
// 180028D84: using guessed type __int64 __fastcall o_wcsncpy_s_0(_QWORD, _QWORD, _QWORD, _QWORD);
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 1800927B0: using guessed type unsigned int CSslGlobals::m_dwEnableSessionTicket;
// 180092DA0: using guessed type __int64 g_SslContextManager;
// 180092DB0: using guessed type __int64 qword_180092DB0;
// 180092DB8: using guessed type __int64 qword_180092DB8;
// 180092DC0: using guessed type __int64 qword_180092DC0;
// 180092DD0: using guessed type __int128 xmmword_180092DD0;
// 180092DE0: using guessed type int dword_180092DE0;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;
