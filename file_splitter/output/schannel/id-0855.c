// File count: 855
// Total lines: 503
----------------------------------------
__int64 SchEventWrite(const struct _EVENT_DESCRIPTOR *a1, unsigned __int16 *a2, __int64 a3, ...)
{
  const struct _EVENT_DESCRIPTOR *v3; // r15
  unsigned __int64 *v4; // r12
  unsigned int v5; // r8d
  unsigned __int64 *v6; // rdi
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rdx
  unsigned int v9; // ebx
  __int64 v10; // r8
  __int64 v11; // rax
  unsigned __int64 v12; // r14
  __int64 v13; // rax
  unsigned int v14; // ecx
  unsigned __int16 v15; // ax
  int v16; // eax
  size_t v17; // rbx
  __int64 v18; // rsi
  unsigned __int64 v19; // rcx
  __int64 v20; // rcx
  signed __int64 v21; // rcx
  void *v22; // rsp
  void *v23; // rsp
  _DWORD *v24; // rax
  unsigned __int64 v25; // rbx
  unsigned __int64 v26; // rcx
  __int64 v27; // rcx
  signed __int64 v28; // rcx
  void *v29; // rsp
  void *v30; // rsp
  _DWORD *v31; // rax
  unsigned int v32; // r13d
  __int64 v33; // rcx
  unsigned __int16 **v34; // r15
  unsigned __int64 *v35; // r14
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx
  int v39; // ecx
  int v40; // ecx
  char **v41; // r13
  __int64 v42; // rcx
  unsigned __int64 v43; // rcx
  unsigned __int64 v44; // rcx
  signed __int64 v45; // rcx
  void *v46; // rsp
  void *v47; // rsp
  _DWORD *v48; // rax
  unsigned __int64 v49; // rcx
  bool v50; // zf
  void *v51; // rcx
  _DWORD *v52; // rax
  unsigned __int64 v53; // rcx
  unsigned __int64 v54; // rax
  int v55; // ecx
  unsigned __int64 v56; // rax
  unsigned __int64 v57; // rbx
  DWORD LengthSid; // eax
  bool v59; // cf
  unsigned __int16 *v60; // rbx
  _DWORD *v61; // rax
  unsigned __int64 v62; // rax
  unsigned __int16 **v63; // rax
  _DWORD *v64; // rax
  unsigned __int64 v65; // rax
  int v66; // ebx
  _DWORD *v67; // rax
  unsigned __int64 v68; // rax
  _DWORD *v69; // rax
  _DWORD *v70; // rax
  unsigned __int64 v71; // rax
  int v72; // ebx
  _DWORD *v73; // rax
  unsigned __int64 v74; // rax
  _DWORD *v75; // rax
  _DWORD *v76; // rax
  unsigned __int64 v77; // rax
  unsigned __int64 v78; // rax
  int Id; // r9d
  __int64 v80; // rcx
  unsigned int v81; // r14d
  __int64 v82; // rax
  unsigned __int64 v83; // rcx
  _DWORD *v84; // rcx
  int v86[8]; // [rsp+0h] [rbp-30h] BYREF
  _QWORD v87[2]; // [rsp+20h] [rbp-10h] BYREF
  unsigned int v88; // [rsp+30h] [rbp+0h] BYREF
  unsigned int v89; // [rsp+34h] [rbp+4h]
  unsigned __int64 v90; // [rsp+38h] [rbp+8h] BYREF
  const struct _EVENT_DESCRIPTOR *v91; // [rsp+40h] [rbp+10h]
  unsigned __int16 *v92; // [rsp+A8h] [rbp+78h] BYREF

  v92 = a2;
  v91 = a1;
  v3 = a1;
  v4 = 0i64;
  v88 = 0;
  v5 = 0;
  v6 = 0i64;
  v7 = 0i64;
  if ( !g_RegistrationHandle )
  {
    v9 = SchInitializeEvents();
    if ( v9 )
      goto LABEL_104;
    a2 = v92;
    v5 = 0;
  }
  if ( !a2 )
    goto LABEL_100;
  v11 = -1i64;
  do
    ++v11;
  while ( a2[v11] );
  v12 = 127i64;
  v90 = 127i64;
  if ( (unsigned int)v11 > 0x7Fui64 || (v90 = (unsigned int)v11, v12 = (unsigned int)v11, (_DWORD)v11) )
  {
    v13 = 0i64;
    v14 = 0;
    do
    {
      v15 = a2[v13];
      if ( v15 == 98 )
      {
        v16 = 2;
      }
      else
      {
        if ( v15 != 100 && v15 != 112 && (v15 <= 0x72u || v15 > 0x75u) )
          return 87;
        v16 = 1;
      }
      ++v14;
      v5 += v16;
      v13 = v14;
    }
    while ( v14 < v12 );
    v88 = v5;
  }
  v4 = 0i64;
  v17 = 16i64 * v5;
  v18 = v5;
  if ( !v17 )
    goto LABEL_27;
  if ( v17 > g_ulMaxStackAllocSize )
    goto LABEL_27;
  v19 = v17 + g_ulAdditionalProbeSize + 8;
  if ( v19 < v17 || !(unsigned int)VerifyStackAvailable(v19) )
    goto LABEL_27;
  v20 = v17 + 23;
  if ( v17 + 23 <= v17 + 8 )
    v20 = 0xFFFFFFFFFFFFFF0i64;
  v21 = v20 & 0xFFFFFFFFFFFFFFF0ui64;
  v22 = alloca(v21);
  v23 = alloca(v21);
  v4 = (unsigned __int64 *)&v88;
  if ( v86 == (int *)-48i64 || (v88 = 1801679955, (v4 = &v90) == 0i64) )
  {
LABEL_27:
    if ( v17 + 8 >= v17 )
    {
      v24 = (_DWORD *)((__int64 (*)(void))g_pfnAllocate)();
      if ( !v24 )
        return 8;
      *v24 = 1885431112;
      v4 = (unsigned __int64 *)(v24 + 2);
    }
    if ( !v4 )
      return 8;
  }
  memset_0(v4, 0, v17);
  v25 = 8 * v18;
  v6 = 0i64;
  if ( 8 * v18 )
  {
    if ( v25 <= g_ulMaxStackAllocSize )
    {
      v26 = v25 + g_ulAdditionalProbeSize + 8;
      if ( v26 >= v25 )
      {
        if ( (unsigned int)VerifyStackAvailable(v26) )
        {
          v27 = v25 + 23;
          if ( v25 + 23 <= v25 + 8 )
            v27 = 0xFFFFFFFFFFFFFF0i64;
          v28 = v27 & 0xFFFFFFFFFFFFFFF0ui64;
          v29 = alloca(v28);
          v30 = alloca(v28);
          v6 = (unsigned __int64 *)&v88;
          if ( v86 != (int *)-48i64 )
          {
            v88 = 1801679955;
            v6 = &v90;
            if ( &v90 )
            {
LABEL_46:
              memset_0(v6, 0, 8 * v18);
              v89 = 0;
              v7 = 0i64;
              v32 = 0;
              if ( v12 )
              {
                v33 = 0i64;
                v34 = &v92;
                v35 = v4;
                while ( 1 )
                {
                  v36 = v92[v33] - 98;
                  if ( v36 )
                  {
                    v37 = v36 - 2;
                    if ( !v37 )
                    {
                      ++v34;
                      v59 = (unsigned __int64)g_ulMaxStackAllocSize < 4;
                      v66 = *(_DWORD *)v34;
                      v6[v7] = 0i64;
                      if ( v59 || (unsigned __int64)(g_ulAdditionalProbeSize + 12) < 4 )
                        goto LABEL_121;
                      if ( (unsigned int)VerifyStackAvailable(g_ulAdditionalProbeSize + 12) )
                        v6[v7] = (unsigned __int64)v87;
                      v67 = (_DWORD *)v6[v7];
                      if ( !v67
                        || (*v67 = 1801679955,
                            v68 = v6[v7],
                            v50 = v68 == -8i64,
                            v69 = (_DWORD *)(v68 + 8),
                            v6[v7] = (unsigned __int64)v69,
                            v50) )
                      {
LABEL_121:
                        v70 = (_DWORD *)((__int64 (__fastcall *)(__int64))g_pfnAllocate)(12i64);
                        v6[v7] = (unsigned __int64)v70;
                        if ( !v70 )
                          goto LABEL_117;
                        *v70 = 1885431112;
                        v71 = v6[v7];
                        v50 = v71 == -8i64;
                        v69 = (_DWORD *)(v71 + 8);
                        v6[v7] = (unsigned __int64)v69;
                        if ( v50 )
                          goto LABEL_117;
                      }
                      *v69 = v66;
                      v56 = v6[v7];
                      v35[1] = 4i64;
                      goto LABEL_87;
                    }
                    v38 = v37 - 12;
                    if ( !v38 )
                    {
                      ++v34;
                      v59 = (unsigned __int64)g_ulMaxStackAllocSize < 8;
                      v60 = *v34;
                      v6[v7] = 0i64;
                      if ( v59 || (unsigned __int64)(g_ulAdditionalProbeSize + 16) < 8 )
                        goto LABEL_122;
                      if ( (unsigned int)VerifyStackAvailable(g_ulAdditionalProbeSize + 16) )
                        v6[v7] = (unsigned __int64)v87;
                      v61 = (_DWORD *)v6[v7];
                      if ( !v61
                        || (*v61 = 1801679955,
                            v62 = v6[v7],
                            v50 = v62 == -8i64,
                            v63 = (unsigned __int16 **)(v62 + 8),
                            v6[v7] = (unsigned __int64)v63,
                            v50) )
                      {
LABEL_122:
                        v64 = (_DWORD *)((__int64 (__fastcall *)(__int64))g_pfnAllocate)(16i64);
                        v6[v7] = (unsigned __int64)v64;
                        if ( !v64 )
                          goto LABEL_117;
                        *v64 = 1885431112;
                        v65 = v6[v7];
                        v50 = v65 == -8i64;
                        v63 = (unsigned __int16 **)(v65 + 8);
                        v6[v7] = (unsigned __int64)v63;
                        if ( v50 )
                          goto LABEL_117;
                      }
                      *v63 = v60;
                      v56 = v6[v7];
                      v35[1] = 8i64;
LABEL_87:
                      *v35 = v56;
                      goto LABEL_88;
                    }
                    v39 = v38 - 3;
                    if ( !v39 )
                    {
                      v57 = (unsigned __int64)*++v34;
                      LengthSid = GetLengthSid(*v34);
                      *v35 = v57;
                      *((_DWORD *)v35 + 3) = 0;
                      *((_DWORD *)v35 + 2) = LengthSid;
LABEL_88:
                      ++v7;
                      v35 += 2;
                      goto LABEL_98;
                    }
                    v40 = v39 - 1;
                    if ( !v40 )
                    {
                      v56 = (unsigned __int64)*++v34;
                      v35[1] = 16i64;
                      goto LABEL_87;
                    }
                    if ( v40 != 1 )
                    {
                      v9 = 87;
                      goto LABEL_104;
                    }
                    v41 = (char **)*++v34;
                    v6[v7] = 0i64;
                    v42 = *(unsigned __int16 *)v41;
                    v8 = v42 + 2;
                    if ( v42 + 2 > (unsigned __int64)g_ulMaxStackAllocSize )
                      goto LABEL_123;
                    v43 = g_ulAdditionalProbeSize + 10 + v42;
                    if ( v43 < v8 )
                      goto LABEL_123;
                    if ( (unsigned int)VerifyStackAvailable(v43) )
                    {
                      v44 = *(unsigned __int16 *)v41 + 25i64;
                      if ( v44 <= (unsigned __int64)*(unsigned __int16 *)v41 + 10 )
                        v44 = 0xFFFFFFFFFFFFFF0i64;
                      v45 = v44 & 0xFFFFFFFFFFFFFFF0ui64;
                      v46 = alloca(v45);
                      v47 = alloca(v45);
                      v6[v7] = (unsigned __int64)&v88;
                    }
                    v48 = (_DWORD *)v6[v7];
                    if ( !v48
                      || (*v48 = 1801679955,
                          v49 = v6[v7],
                          v50 = v49 == -8i64,
                          v51 = (void *)(v49 + 8),
                          v6[v7] = (unsigned __int64)v51,
                          v50) )
                    {
LABEL_123:
                      if ( (unsigned __int64)*(unsigned __int16 *)v41 + 10 < (unsigned __int64)*(unsigned __int16 *)v41
                                                                           + 2 )
                        goto LABEL_117;
                      v52 = (_DWORD *)((__int64 (*)(void))g_pfnAllocate)();
                      v6[v7] = (unsigned __int64)v52;
                      if ( !v52 )
                        goto LABEL_117;
                      *v52 = 1885431112;
                      v53 = v6[v7];
                      v50 = v53 == -8i64;
                      v51 = (void *)(v53 + 8);
                      v6[v7] = (unsigned __int64)v51;
                      if ( v50 )
                        goto LABEL_117;
                    }
                    memset_0(v51, 0, *(unsigned __int16 *)v41 + 2i64);
                    v9 = RtlStringCchCopyNW(
                           (char *)v6[v7],
                           ((unsigned __int64)*(unsigned __int16 *)v41 >> 1) + 1,
                           v41[1],
                           (unsigned __int64)*(unsigned __int16 *)v41 >> 1);
                    if ( v9 )
                      goto LABEL_104;
                    v54 = v6[v7];
                    v55 = *(unsigned __int16 *)v41 + 2;
                    v32 = v89;
                    ++v7;
                    *((_DWORD *)v35 + 2) = v55;
                    *v35 = v54;
                    *((_DWORD *)v35 + 3) = 0;
                    v35 += 2;
                  }
                  else
                  {
                    v59 = (unsigned __int64)g_ulMaxStackAllocSize < 4;
                    v72 = *((_DWORD *)v34 + 2);
                    v6[v7] = 0i64;
                    if ( v59 || (unsigned __int64)(g_ulAdditionalProbeSize + 12) < 4 )
                      goto LABEL_124;
                    if ( (unsigned int)VerifyStackAvailable(g_ulAdditionalProbeSize + 12) )
                      v6[v7] = (unsigned __int64)v87;
                    v73 = (_DWORD *)v6[v7];
                    if ( !v73
                      || (*v73 = 1801679955,
                          v74 = v6[v7],
                          v50 = v74 == -8i64,
                          v75 = (_DWORD *)(v74 + 8),
                          v6[v7] = (unsigned __int64)v75,
                          v50) )
                    {
LABEL_124:
                      v76 = (_DWORD *)((__int64 (__fastcall *)(__int64))g_pfnAllocate)(12i64);
                      v6[v7] = (unsigned __int64)v76;
                      if ( !v76
                        || (*v76 = 1885431112,
                            v77 = v6[v7],
                            v50 = v77 == -8i64,
                            v75 = (_DWORD *)(v77 + 8),
                            v6[v7] = (unsigned __int64)v75,
                            v50) )
                      {
LABEL_117:
                        v9 = 8;
                        goto LABEL_104;
                      }
                    }
                    *v75 = v72;
                    v34 += 2;
                    v78 = v6[v7];
                    v7 += 2i64;
                    *v35 = v78;
                    v35[1] = 4i64;
                    v35[2] = (unsigned __int64)*v34;
                    *((_DWORD *)v35 + 6) = v72;
                    *((_DWORD *)v35 + 7) = 0;
                    v35 += 4;
                  }
LABEL_98:
                  v33 = ++v32;
                  v89 = v32;
                  if ( v32 >= v90 )
                  {
                    v3 = v91;
                    break;
                  }
                }
              }
LABEL_100:
              v9 = EtwEventWrite(g_RegistrationHandle, v3, v88, v4);
              if ( v9
                && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                Id = v3->Id;
                v80 = *((_QWORD *)WPP_GLOBAL_Control + 2);
                LODWORD(v87[0]) = v9;
                WPP_SF_DD(v80, 0xAu, (__int64)&WPP_9cc880ee923835bef0ce0974c4127801_Traceguids, Id, v87[0]);
              }
LABEL_104:
              v81 = 0;
              if ( v7 )
              {
                v82 = 0i64;
                do
                {
                  v83 = v6[v82];
                  if ( v83 )
                  {
                    v84 = (_DWORD *)(v83 - 8);
                    if ( *v84 == 1885431112 )
                      ((void (__fastcall *)(_DWORD *, unsigned __int64, __int64, _QWORD))g_pfnFree)(v84, v8, v10, 0i64);
                  }
                  v82 = ++v81;
                }
                while ( v81 < v7 );
              }
              if ( v6 && *((_DWORD *)v6 - 2) == 1885431112 )
                ((void (__fastcall *)(unsigned __int64 *, unsigned __int64, __int64, _QWORD))g_pfnFree)(
                  v6 - 1,
                  v8,
                  v10,
                  0i64);
              goto LABEL_113;
            }
          }
        }
      }
    }
  }
  if ( v25 + 8 < v25 )
  {
LABEL_44:
    if ( !v6 )
      goto LABEL_45;
    goto LABEL_46;
  }
  v31 = (_DWORD *)((__int64 (*)(void))g_pfnAllocate)();
  if ( v31 )
  {
    *v31 = 1885431112;
    v6 = (unsigned __int64 *)(v31 + 2);
    goto LABEL_44;
  }
LABEL_45:
  v9 = 8;
LABEL_113:
  if ( v4 && *((_DWORD *)v4 - 2) == 1885431112 )
    ((void (*)(void))g_pfnFree)();
  return v9;
}
// 180045B59: variable 'v8' is possibly undefined
// 180045B59: variable 'v10' is possibly undefined
// 180080E98: using guessed type __int64 __fastcall EtwEventWrite(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;
// 180092D80: using guessed type unsigned __int64 g_RegistrationHandle;
// 180045408: using guessed type _QWORD var_70[2];
