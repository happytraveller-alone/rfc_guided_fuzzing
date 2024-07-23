//----- (000000018000B810) ----------------------------------------------------
__int64 __fastcall SpInitLsaModeContext(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        struct _SecBufferDesc *a6,
        struct CSslParentContext **a7,
        struct _SecBufferDesc *a8,
        _DWORD *a9,
        union _LARGE_INTEGER *a10,
        unsigned __int8 *a11,
        struct _SecBuffer *a12)
{
  unsigned __int64 v15; // rsi
  struct CSslParentContext *v17; // r14
  unsigned __int64 v18; // r13
  CCipherMill *v19; // rcx
  unsigned int v20; // ebx
  __int64 v21; // rcx
  __int64 v22; // r8
  __int64 v23; // rax
  unsigned __int64 v24; // rax
  __int64 v25; // rdi
  __int64 v26; // r12
  struct _SecBuffer *v27; // rbx
  __int64 v28; // rdi
  __int64 v29; // rbx
  char v30; // al
  unsigned __int64 v31; // r9
  __int64 v32; // r8
  int v33; // ebx
  __int64 v34; // rax
  struct _SecBuffer *v35; // r14
  struct _SecBuffer *v36; // rdx
  const unsigned __int16 *v38; // rdx
  unsigned int v39; // eax
  __int64 v40; // rdi
  struct _SecBuffer *v41; // r15
  __int64 *pvBuffer; // rbx
  __int64 v43; // r9
  _QWORD *v44; // rax
  void *v45; // rcx
  __int64 v46; // rcx
  int v47; // ebx
  struct _SecBuffer **v48; // [rsp+28h] [rbp-E0h]
  struct CSslParentContext *v49; // [rsp+78h] [rbp-90h] BYREF
  char v50[4]; // [rsp+80h] [rbp-88h] BYREF
  unsigned int v51; // [rsp+84h] [rbp-84h]
  void *Src; // [rsp+88h] [rbp-80h]
  struct _SecBuffer *v53; // [rsp+90h] [rbp-78h] BYREF
  struct _SecBuffer *v54; // [rsp+98h] [rbp-70h] BYREF
  struct _SecBuffer *v55; // [rsp+A0h] [rbp-68h] BYREF
  struct _SecBuffer *v56; // [rsp+A8h] [rbp-60h] BYREF
  struct _SecBuffer *v57; // [rsp+B0h] [rbp-58h] BYREF
  struct _SecBuffer *v58; // [rsp+B8h] [rbp-50h] BYREF
  struct _SecBuffer *v59; // [rsp+C0h] [rbp-48h] BYREF
  struct _SecBuffer *v60; // [rsp+C8h] [rbp-40h] BYREF
  struct _SecBuffer *v61; // [rsp+D0h] [rbp-38h] BYREF
  struct _SecBuffer *v62; // [rsp+D8h] [rbp-30h] BYREF
  struct _SecBuffer *v63; // [rsp+E0h] [rbp-28h] BYREF
  struct _SecBuffer *v64; // [rsp+E8h] [rbp-20h] BYREF
  struct _SecBuffer *v65; // [rsp+F0h] [rbp-18h] BYREF
  unsigned __int64 *v66; // [rsp+F8h] [rbp-10h]
  __int128 v67; // [rsp+100h] [rbp-8h] BYREF
  struct _SecBuffer *v68; // [rsp+110h] [rbp+8h] BYREF
  struct _SecBuffer *v69; // [rsp+118h] [rbp+10h] BYREF
  char v70[16]; // [rsp+120h] [rbp+18h] BYREF
  struct _SecBuffer *v71; // [rsp+130h] [rbp+28h] BYREF
  int v74; // [rsp+190h] [rbp+88h]

  v62 = 0i64;
  v53 = 0i64;
  v55 = 0i64;
  v15 = 28i64;
  v54 = 0i64;
  v56 = 0i64;
  v58 = 0i64;
  v17 = 0i64;
  v57 = 0i64;
  v65 = 0i64;
  v60 = 0i64;
  v59 = 0i64;
  v63 = 0i64;
  v64 = 0i64;
  v67 = 0i64;
  v49 = 0i64;
  v74 = 0;
  v66 = 0i64;
  v18 = a4;
  v19 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 23i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
      v19 = WPP_GLOBAL_Control;
    }
    if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)v19 + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)v19 + 2), 24i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
        v19 = WPP_GLOBAL_Control;
      }
      if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)v19 + 28) & 4) != 0 )
        {
          WPP_SF_q(*((_QWORD *)v19 + 2), 0x19u, (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids, a1);
          v19 = WPP_GLOBAL_Control;
        }
        if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control )
        {
          if ( (*((_BYTE *)v19 + 28) & 4) != 0 )
          {
            WPP_SF_q(*((_QWORD *)v19 + 2), 0x1Au, (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids, a2);
            v19 = WPP_GLOBAL_Control;
          }
          if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v19 + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)v19 + 2), 27i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids, a4);
            v19 = WPP_GLOBAL_Control;
          }
        }
      }
    }
  }
  if ( a3 && v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v19 + 28) & 4) != 0 )
  {
    WPP_SF_S(
      *((_QWORD *)v19 + 2),
      0x1Cu,
      (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
      *(const wchar_t **)(a3 + 8));
    v19 = WPP_GLOBAL_Control;
  }
  if ( !a1 )
  {
    v20 = -2146893055;
    goto LABEL_69;
  }
  if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)v19 + 28) & 4) != 0 )
    {
      WPP_SF_D(
        *((_QWORD *)v19 + 2),
        29i64,
        &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
        *(unsigned int *)(a1 + 212));
      v19 = WPP_GLOBAL_Control;
    }
    if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v19 + 28) & 4) != 0 )
      WPP_SF_S(
        *((_QWORD *)v19 + 2),
        0x1Eu,
        (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
        (const wchar_t *)(a1 + 216));
  }
  v20 = ParseOutputBufferDesc(a8, v18, &v61, (struct SPBuffer *)v50, &v62, (struct SPBuffer *)&v67, &v65, &v60, &v64);
  if ( v20 )
    goto LABEL_66;
  v21 = ((-(__int64)((v18 & 0x4000) != 0) & 0x4000) + 28) | 0x100;
  v22 = (v18 & 0x4000) != 0 ? 0x200 : 0;
  if ( (v18 & 0x100) == 0 )
    v21 = (-(__int64)((v18 & 0x4000) != 0) & 0x4000) + 28;
  if ( (v18 & 0x800) != 0 )
    v22 |= 0x1000ui64;
  v15 = v21 | ((-(__int64)((v18 & 0x800) != 0) & 0xFFFFFFFFFFFF8800ui64) + 0x8000);
  v23 = v18 & 0x80000;
  if ( (v18 & 2) != 0 )
  {
    v15 |= 2ui64;
    v22 |= 0x100ui64;
    if ( v23 )
    {
      v20 = 120;
      goto LABEL_66;
    }
  }
  else
  {
    if ( v23 )
    {
      v15 |= 0x80000ui64;
      v22 |= 0x4000ui64;
    }
    if ( g_fManualCredValidation )
      v22 |= 0x4000ui64;
  }
  v24 = v15;
  v15 |= 0x80ui64;
  if ( (v18 & 0x80) == 0 )
    v15 = v24;
  v25 = v22 | 0x400;
  if ( (v18 & 0x80) == 0 )
    v25 = v22;
  if ( (v18 & 0x400) != 0 )
  {
    v15 |= 0x400ui64;
    if ( (v18 & 0x800) != 0
      && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 31i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
    }
  }
  v20 = ParseInputBufferDesc(
          a6,
          &v68,
          (struct SPBuffer *)v70,
          &v69,
          &v71,
          &v53,
          &v55,
          &v54,
          &v56,
          &v58,
          &v57,
          &v59,
          &v63);
  if ( v20 )
    goto LABEL_66;
  v26 = v25;
  if ( v63 )
  {
    pvBuffer = (__int64 *)v63->pvBuffer;
    if ( !pvBuffer || v63->cbBuffer < 8 )
    {
      v20 = 87;
      goto LABEL_66;
    }
    v43 = *pvBuffer;
    v26 = v25;
    if ( (*pvBuffer & 0x100000000i64) != 0 )
    {
      v26 = v25 | 0x100000000i64;
      v15 |= 0x100000000ui64;
    }
    if ( (v43 & 0x200000000i64) != 0 )
    {
      v19 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
        v43 = *pvBuffer;
        v19 = WPP_GLOBAL_Control;
      }
      v26 |= 0x200000000ui64;
      v15 |= 0x200000000ui64;
    }
    else
    {
      v19 = WPP_GLOBAL_Control;
    }
    if ( (v43 & ~v26 & 0xFFFFFFFF00000000ui64) != 0 )
    {
      if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v19 + 28) & 4) != 0 )
      {
        WPP_SF_i(
          *((_QWORD *)v19 + 2),
          0x21u,
          (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
          v43 & ~v26 & 0xFFFFFFFF00000000ui64);
        v19 = WPP_GLOBAL_Control;
      }
      goto LABEL_121;
    }
    v18 |= v43;
    if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v19 + 28) & 4) != 0 )
      WPP_SF_i(*((_QWORD *)v19 + 2), 0x22u, (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
  }
  v27 = v64;
  if ( v64 )
  {
    v44 = v64->pvBuffer;
    if ( !v44 )
    {
      v44 = SPExternalAlloc(8u);
      v27->pvBuffer = v44;
      if ( !v44 )
      {
        v20 = -2146893056;
        goto LABEL_66;
      }
      v27->cbBuffer = 8;
    }
    v66 = v44;
  }
  if ( !a2 )
  {
    if ( a3 )
      v38 = *(const unsigned __int16 **)(a3 + 8);
    else
      v38 = &Class;
    v39 = CSslContextManager::InstantiateClientContext(v19, v38, (struct CCredentialGroup *)a1, &v49, v18);
    v17 = v49;
    v20 = v39;
    if ( v39 )
      goto LABEL_66;
    v40 = *((_QWORD *)v49 + 1);
    *(_QWORD *)(v40 + 136) |= v26;
    CSslContext::SetCredentialGroup((CSslContext *)v40, (struct CCredentialGroup *)a1);
    v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v40 + 296i64))(v40, v53);
    if ( v20 )
      goto LABEL_66;
    v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *, struct _SecBuffer *))(*(_QWORD *)v40 + 304i64))(
            v40,
            v55,
            v54);
    if ( v20 )
      goto LABEL_66;
    v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v40 + 312i64))(v40, v56);
    if ( v20 )
      goto LABEL_66;
    v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *, struct _SecBuffer *))(*(_QWORD *)v40 + 328i64))(
            v40,
            v58,
            v57);
    if ( v20 )
      goto LABEL_66;
    v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v40 + 344i64))(v40, v59);
    if ( v20 )
      goto LABEL_66;
    v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBufferDesc *, struct _SecBuffer *))(*(_QWORD *)v40 + 368i64))(
            v40,
            a6,
            v60);
    if ( v20 )
      goto LABEL_66;
    v20 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v40 + 216i64))(v40, v50);
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 36i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
    if ( v20 && (HIBYTE(*(_WORD *)(v40 + 34)) != 0xFE || v20 != 590692) )
    {
      if ( (v18 & 0x100) != 0 && Src )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v40 + 16i64))(v40);
LABEL_140:
      CSslContextManager::DeleteFullSslContext((CSslContextManager *)&g_SslContextManager, v17);
      goto LABEL_66;
    }
    *a7 = v17;
    CSchannelTelemetryContext::LogHandshakeStart(*(_QWORD *)(v40 + 120), 0, v18, a1, (__int64)v17);
    v41 = v61;
    if ( (v18 & 0x100) != 0 )
    {
      v61->pvBuffer = Src;
    }
    else
    {
      v45 = v61->pvBuffer;
      if ( v45 != Src )
      {
        if ( v61->cbBuffer < v51 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            LODWORD(v48) = v51;
            WPP_SF_dd(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0x25u,
              (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids,
              v61->cbBuffer,
              v48);
          }
          v20 = -2146893023;
          goto LABEL_140;
        }
        memcpy_0(v45, Src, v51);
        (*(void (__fastcall **)(__int64, void *))(*(_QWORD *)v40 + 16i64))(v40, Src);
      }
    }
    v41->cbBuffer = v51;
    v19 = WPP_GLOBAL_Control;
    if ( v20 != 590692 )
      v20 = 590610;
    goto LABEL_67;
  }
  v28 = *(_QWORD *)(a2 + 8);
  v74 = 1;
  v49 = (struct CSslParentContext *)a2;
  if ( _InterlockedIncrement((volatile signed __int32 *)a2) != 1 )
  {
    v17 = v49;
    v20 = 120;
    goto LABEL_66;
  }
  *(_WORD *)(a2 + 34) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_QWORD *)(v28 + 136) |= v26;
  CSslContext::SetCredentialGroup((CSslContext *)v28, (struct CCredentialGroup *)a1);
  if ( (*(_QWORD *)(v28 + 136) & 0x200004000i64) != 0x200004000i64 )
  {
    if ( *(_DWORD *)(v28 + 68) != 4
      || (v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v28 + 296i64))(v28, v53)) == 0
      && (v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *, struct _SecBuffer *))(*(_QWORD *)v28 + 304i64))(
                  v28,
                  v55,
                  v54)) == 0
      && (v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v28 + 312i64))(v28, v56)) == 0 )
    {
      v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *, struct _SecBuffer *))(*(_QWORD *)v28 + 328i64))(
              v28,
              v58,
              v57);
      if ( !v20 )
      {
        v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBuffer *))(*(_QWORD *)v28 + 344i64))(v28, v59);
        if ( !v20 )
        {
          v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBufferDesc *, struct _SecBuffer *))(*(_QWORD *)v28
                                                                                                 + 368i64))(
                  v28,
                  a6,
                  v60);
          if ( !v20 )
          {
            v29 = *(_QWORD *)v28;
            v30 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v28 + 384i64))(v28);
            v31 = v18 >> 8;
            LOBYTE(v31) = BYTE1(v18) & 1;
            LOBYTE(v32) = v30;
            v20 = (*(__int64 (__fastcall **)(__int64, struct _SecBufferDesc *, __int64, unsigned __int64))(v29 + 376))(
                    v28,
                    a8,
                    v32,
                    v31);
            if ( !v20 )
            {
              v33 = (*(__int64 (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v28 + 192i64))(v28, v70, v50);
              if ( (*(_DWORD *)(v28 + 136) & 0x40000) == 0 )
              {
LABEL_54:
                v34 = *(_QWORD *)(v28 + 136);
                if ( (v34 & 0x10000000) != 0 )
                {
                  v15 |= 0x4000ui64;
                  *(_QWORD *)(v28 + 136) = v34 & 0xFFFFFFFFEFFFFFFFui64;
                }
                if ( v33 && !*(_DWORD *)(a2 + 36) )
                  *(_DWORD *)(a2 + 36) = v33;
                if ( v62 )
                  GenerateFatalAlertMessage(v33, v28, v18, (__int64)&v67);
                v35 = v61;
                if ( v33 == 590624 )
                {
                  if ( v65 )
                    GeneratePSKExchangeMessage(v28, (__int64)v65);
                }
                else if ( v33 == 590684 )
                {
                  v61->BufferType = 3;
                }
                if ( !IsFatalError(v33) )
                  *a7 = (struct CSslParentContext *)a2;
                v20 = AscIscPostProcessing(
                        v33,
                        (struct CSslContext *)v28,
                        (struct CSslParentContext *)a2,
                        a12,
                        v69,
                        v68,
                        (struct SPBuffer *)v70,
                        v35,
                        (struct SPBuffer *)v50,
                        v18,
                        a11,
                        a10);
                goto LABEL_65;
              }
              v46 = *(_QWORD *)(a2 + 8);
              v47 = *(_DWORD *)(v46 + 64);
              (**(void (__fastcall ***)(__int64, _QWORD))v46)(v46, 0i64);
              if ( (v47 & 0x800A2AAA) != 0 )
                SPExternalFree(*(void **)(a2 + 8));
              v28 = *(_QWORD *)(a2 + 16);
              *(_QWORD *)(a2 + 8) = v28;
              *(_QWORD *)(a2 + 16) = 0i64;
              if ( v28 )
              {
                v33 = (*(__int64 (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v28 + 192i64))(v28, v70, v50);
                goto LABEL_54;
              }
              v20 = 1359;
            }
          }
        }
      }
    }
LABEL_65:
    v17 = v49;
LABEL_66:
    v19 = WPP_GLOBAL_Control;
    goto LABEL_67;
  }
  v19 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 38i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids);
    v19 = WPP_GLOBAL_Control;
  }
  v17 = v49;
LABEL_121:
  v20 = -2146892963;
LABEL_67:
  v36 = v62;
  if ( v62 )
  {
    v62->pvBuffer = (void *)*((_QWORD *)&v67 + 1);
    v36->cbBuffer = DWORD1(v67);
    v19 = WPP_GLOBAL_Control;
  }
LABEL_69:
  if ( a9 )
  {
    *a9 = v15;
    v19 = WPP_GLOBAL_Control;
  }
  if ( v66 )
  {
    *v66 = v15 & 0xFFFFFFFF00000000ui64;
    v19 = WPP_GLOBAL_Control;
  }
  if ( v74 && v17 )
  {
    _InterlockedDecrement((volatile signed __int32 *)v17);
    v19 = WPP_GLOBAL_Control;
  }
  if ( v19 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v19 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v19 + 2), 39i64, &WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids, v20);
  return TranslateToSecurityStatus(v20);
}
// 180036081: conditional instruction was optimized away because ecx.4 is in (FE00..FEFF)
// 18000BC28: variable 'v32' is possibly undefined
// 18000BDF0: variable 'v19' is possibly undefined
// 1800360CF: variable 'v48' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092DA0: using guessed type __int64 g_SslContextManager;
// 180092F04: using guessed type int g_fManualCredValidation;

