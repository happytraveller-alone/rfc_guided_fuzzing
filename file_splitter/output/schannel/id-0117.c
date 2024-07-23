// File count: 117
// Total lines: 340
----------------------------------------
__int64 __fastcall CopyTlsParameters(
        struct _TLS_PARAMETERS *a1,
        unsigned int a2,
        int a3,
        char a4,
        struct _TLS_PARAMETERS **a5,
        unsigned int *a6)
{
  struct _TLS_PARAMETERS **v6; // r14
  char v7; // bl
  unsigned int *v8; // rdi
  unsigned int v10; // r15d
  struct _TLS_PARAMETERS *v11; // rsi
  struct _TLS_PARAMETERS *v12; // rax
  __int64 v13; // rdx
  char *v14; // rdi
  signed __int64 v15; // rcx
  unsigned __int64 v16; // r9
  __int64 v17; // rdx
  unsigned int v18; // ebx
  int v19; // eax
  unsigned int v20; // r13d
  int v21; // eax
  HLOCAL v22; // rax
  __int64 v23; // rcx
  __int64 v24; // rsi
  char v25; // r9
  __int64 v26; // r14
  __int64 v27; // r9
  __int64 v28; // rdx
  unsigned int v29; // eax
  unsigned int v30; // ecx
  __int64 v31; // rbx
  unsigned int v32; // edx
  unsigned int v33; // r14d
  __int128 v35; // xmm1
  __int64 v36; // rax
  HLOCAL v37; // rax
  int v38; // eax
  unsigned int v39; // esi
  int v40; // r14d
  __int64 v41; // rcx
  unsigned int v42; // eax
  HLOCAL v43; // rax
  unsigned int v44; // eax
  int v45; // edx
  __int64 v46; // rcx
  struct _UNICODE_STRING *v47; // r8
  unsigned int v48; // eax
  int v50; // [rsp+34h] [rbp-A5h]
  unsigned int v51; // [rsp+38h] [rbp-A1h]
  int v52; // [rsp+3Ch] [rbp-9Dh]
  int v53; // [rsp+40h] [rbp-99h]
  __int64 v54; // [rsp+48h] [rbp-91h]
  signed __int64 v55; // [rsp+50h] [rbp-89h]
  struct _TLS_PARAMETERS *v56; // [rsp+58h] [rbp-81h]
  __int128 v58; // [rsp+78h] [rbp-61h] BYREF
  __int128 v59; // [rsp+88h] [rbp-51h]
  __int64 v60; // [rsp+98h] [rbp-41h]
  __int128 v61; // [rsp+A0h] [rbp-39h] BYREF
  __int128 v62; // [rsp+B0h] [rbp-29h]
  __int128 v63; // [rsp+C0h] [rbp-19h]

  v6 = a5;
  v7 = a4;
  v8 = a6;
  v10 = a2;
  v11 = a1;
  if ( !a2 )
    return 0i64;
  if ( a5 && a6 && (a1 || a3) && a2 <= 0x10 )
  {
    v12 = (struct _TLS_PARAMETERS *)SPExternalAlloc(40 * a2);
    v56 = v12;
    if ( v12 )
    {
      v13 = 0i64;
      v53 = 0;
      if ( !v10 )
      {
LABEL_45:
        v18 = 0;
        goto LABEL_46;
      }
      v14 = (char *)v12 + 24;
      v15 = v11 - v12;
      v55 = v11 - v12;
      while ( 1 )
      {
        v60 = 0i64;
        v58 = 0i64;
        v59 = 0i64;
        if ( v7 )
        {
          if ( a3 )
          {
            v16 = (unsigned int)(a3 + 24 * v13);
            v17 = 24i64;
          }
          else
          {
            v16 = (unsigned __int64)v11 + 40 * v13;
            v17 = 40i64;
          }
          v18 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, unsigned __int64))(LsaTable + 80))(
                  0i64,
                  v17,
                  &v58,
                  v16);
          if ( v18 )
            goto LABEL_71;
          v7 = a4;
        }
        else
        {
          v35 = *(_OWORD *)&v14[v15 - 8];
          v58 = *(_OWORD *)&v14[v15 - 24];
          v60 = *(_QWORD *)&v14[v15 + 8];
          v59 = v35;
        }
        if ( (_DWORD)v58 )
        {
          if ( (unsigned int)v58 > 0x10 )
            goto LABEL_70;
          v37 = SPExternalAlloc(16 * (int)v58);
          *((_QWORD *)v14 - 2) = v37;
          if ( !v37 )
            goto LABEL_82;
          v38 = v58;
          v39 = 0;
          *((_DWORD *)v14 - 6) = v58;
          if ( v38 )
          {
            v40 = 0;
            do
            {
              v41 = 16i64 * v39;
              v42 = a3
                  ? Wow64CopyUnicodeString(v40 + DWORD1(v58), (struct _UNICODE_STRING *)(v41 + *((_QWORD *)v14 - 2)))
                  : CopyUnicodeString(
                      v7,
                      (struct _UNICODE_STRING *)(v41 + *((_QWORD *)&v58 + 1)),
                      (struct _UNICODE_STRING *)(v41 + *((_QWORD *)v14 - 2)));
              v18 = v42;
              if ( v42 )
                goto LABEL_71;
              v7 = a4;
              ++v39;
              v40 += 8;
            }
            while ( v39 < (unsigned int)v58 );
          }
        }
        v19 = DWORD2(v58);
        v20 = HIDWORD(v58);
        if ( !a3 )
          v19 = v59;
        *((_DWORD *)v14 - 2) = v19;
        v21 = DWORD1(v59);
        if ( !a3 )
          v20 = DWORD1(v59);
        if ( v20 )
          break;
LABEL_41:
        if ( !a3 )
          v21 = v60;
        v13 = (unsigned int)(v53 + 1);
        *((_DWORD *)v14 + 2) = v21;
        v14 += 40;
        v53 = v13;
        if ( (unsigned int)v13 >= v10 )
        {
          v12 = v56;
          v8 = a6;
          v6 = a5;
          goto LABEL_45;
        }
        v15 = v55;
        v7 = a4;
        v11 = a1;
      }
      if ( v20 > 0x10 )
      {
LABEL_70:
        v18 = -2146892963;
        goto LABEL_71;
      }
      v22 = SPExternalAlloc(48 * v20);
      *(_QWORD *)v14 = v22;
      if ( v22 )
      {
        v23 = 0i64;
        *((_DWORD *)v14 - 1) = v20;
        v50 = 0;
        v24 = 0i64;
        while ( 1 )
        {
          v25 = a4;
          v26 = *(_QWORD *)v14;
          v54 = *(_QWORD *)v14;
          v61 = 0i64;
          v62 = 0i64;
          v63 = 0i64;
          if ( a4 )
          {
            if ( a3 )
            {
              v27 = (unsigned int)(v59 + 28 * v23);
              v28 = 28i64;
            }
            else
            {
              v27 = *((_QWORD *)&v59 + 1) + 48 * v23;
              v28 = 48i64;
            }
            v18 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, __int64))(LsaTable + 80))(
                    0i64,
                    v28,
                    &v61,
                    v27);
            if ( v18 )
              goto LABEL_71;
            LODWORD(v23) = v50;
            v25 = a4;
          }
          else
          {
            v36 = *(_QWORD *)&v14[v55];
            v61 = *(_OWORD *)(v36 + v24);
            v62 = *(_OWORD *)(v36 + v24 + 16);
            v63 = *(_OWORD *)(v36 + v24 + 32);
          }
          if ( a3 )
            v29 = Wow64CopyUnicodeString((int)v59 + 4 + 28 * (int)v23, (struct _UNICODE_STRING *)(v24 + v26 + 8));
          else
            v29 = CopyUnicodeString(
                    v25,
                    (struct _UNICODE_STRING *)(48i64 * (unsigned int)v23 + *((_QWORD *)&v59 + 1) + 8i64),
                    (struct _UNICODE_STRING *)(v24 + v26 + 8));
          v18 = v29;
          if ( v29 )
            goto LABEL_71;
          v30 = DWORD2(v62);
          v31 = v26;
          if ( !a3 )
            v30 = HIDWORD(v63);
          *(_DWORD *)(v24 + v26 + 44) = v30;
          v32 = DWORD1(v62);
          if ( !a3 )
            v32 = DWORD2(v63);
          *(_DWORD *)(v24 + v26 + 40) = v32;
          *(_DWORD *)(v24 + v26) = v61;
          if ( v30 )
          {
            if ( v32 > v30 )
              goto LABEL_70;
          }
          v33 = HIDWORD(v61);
          if ( !a3 )
            v33 = DWORD2(v62);
          if ( v33 )
          {
            if ( v33 > 0x10 )
              goto LABEL_70;
            v43 = SPExternalAlloc(16 * v33);
            *(_QWORD *)(v24 + v31 + 32) = v43;
            if ( v43 )
            {
              v44 = 0;
              *(_DWORD *)(v24 + v31 + 24) = v33;
              v45 = 0;
              v51 = 0;
              v52 = 0;
              while ( 1 )
              {
                v46 = 16i64 * v44;
                v47 = (struct _UNICODE_STRING *)(v46 + *(_QWORD *)(v24 + v31 + 32));
                v48 = a3
                    ? Wow64CopyUnicodeString(v45 + (int)v62, v47)
                    : CopyUnicodeString(a4, (struct _UNICODE_STRING *)(v46 + v63), v47);
                v18 = v48;
                if ( v48 )
                  goto LABEL_71;
                v44 = v51 + 1;
                v31 = v54;
                v45 = v52 + 8;
                v51 = v44;
                v52 += 8;
                if ( v44 >= v33 )
                  goto LABEL_39;
              }
            }
            break;
          }
LABEL_39:
          v24 += 48i64;
          v23 = (unsigned int)(v50 + 1);
          v50 = v23;
          if ( (unsigned int)v23 >= v20 )
          {
            v21 = DWORD1(v59);
            goto LABEL_41;
          }
        }
      }
LABEL_82:
      v18 = -2146893056;
LABEL_71:
      FreeTlsParameters(v56, v10);
      v8 = a6;
      v6 = a5;
    }
    else
    {
      v18 = -2146893056;
    }
  }
  else
  {
    v18 = -2146892963;
  }
  v10 = 0;
  v12 = 0i64;
LABEL_46:
  *v6 = v12;
  *v8 = v10;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && ((*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 && v18 || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) )
  {
    WPP_SF_DD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x44u,
      (__int64)&WPP_436d244ba9be3eb0a28121d2e8b5d9e1_Traceguids,
      v18,
      v18);
  }
  return v18;
}
// 180092620: using guessed type __int64 LsaTable;
