// File count: 112
// Total lines: 284
----------------------------------------
__int64 __fastcall CSsl3TlsContext::GenerateCcsAndFinishMessage(CSsl3TlsContext *this, struct SPBuffer *a2)
{
  __int64 v2; // rdi
  __int64 v5; // r14
  unsigned int v6; // edx
  __int64 v7; // r8
  int v8; // eax
  unsigned int v9; // edi
  char v10; // cl
  _BYTE *v11; // r13
  int v12; // r15d
  unsigned int v13; // ebp
  _BYTE *v14; // r14
  __int64 *v15; // rax
  __int64 v16; // rcx
  unsigned int v17; // edi
  size_t v18; // r12
  __int64 v19; // r9
  __int16 v20; // cx
  _BYTE *v21; // rdi
  bool v22; // zf
  char v23; // cl
  __int64 v24; // rdx
  unsigned int v25; // eax
  int v26; // r14d
  int v27; // eax
  unsigned int v28; // edi
  __int64 result; // rax
  __int16 v30; // cx
  __int64 v31; // rcx
  __int64 v32; // rcx
  __int64 v33; // rdi
  void *v34; // r12
  __int64 *v35; // rax
  __int64 v36; // rcx
  int v37; // edi
  __int64 v38; // rax
  void *v39; // rdi
  __int16 v40; // cx
  __int64 v41; // [rsp+58h] [rbp-60h]
  __int64 v42; // [rsp+60h] [rbp-58h]
  int v43; // [rsp+C8h] [rbp+10h]
  unsigned int v44; // [rsp+D0h] [rbp+18h]
  unsigned int v45; // [rsp+D8h] [rbp+20h]

  v2 = *((_QWORD *)a2 + 1) + *((unsigned int *)a2 + 1);
  v42 = *((_DWORD *)this + 34) & 0x8000;
  if ( *((_BYTE *)this + 233) )
  {
    v45 = *((_DWORD *)this + 15);
    v5 = 12i64;
    goto LABEL_3;
  }
  v45 = *((_DWORD *)this + 15);
  v5 = 4i64;
  if ( (*((_BYTE *)this + 32) & 4) == 0 )
  {
LABEL_3:
    v6 = 0;
    goto LABEL_4;
  }
  v6 = *((_DWORD *)this + 11);
LABEL_4:
  v7 = v45;
  v44 = v6;
  v43 = v5;
  *(_BYTE *)(v45 + (unsigned __int64)v6 + v2) = 1;
  if ( *((_BYTE *)this + 233) )
  {
    v30 = *((_WORD *)this + 17);
    *(_BYTE *)(v2 + 2) = v30;
    *(_BYTE *)(v2 + 1) = HIBYTE(v30);
    *(_BYTE *)v2 = 20;
    *(_WORD *)(v2 + 11) = 256;
    *((_DWORD *)a2 + 1) += v6 + v45 + 1;
  }
  else
  {
    v8 = CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, 20, 1u);
    v9 = v8;
    if ( v8 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 950, v8, 0x50u);
      return v9;
    }
    *((_WORD *)this + 16) |= 0xCu;
    v10 = *((_BYTE *)this + 233);
    if ( !v10 && *((_QWORD *)this + 19) )
    {
      SslFreeObject(*((_QWORD *)this + 19), 0i64);
      v10 = *((_BYTE *)this + 233);
    }
    *((_QWORD *)this + 19) = *((_QWORD *)this + 21);
    *((_QWORD *)this + 21) = 0i64;
    if ( !v10 )
      *((_QWORD *)this + 23) = 0i64;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    v7 = v45;
    if ( (*((_BYTE *)this + 32) & 4) != 0 )
      v6 = *((_DWORD *)this + 11);
    else
      v6 = 0;
    v44 = v6;
  }
  v11 = (_BYTE *)(*((_QWORD *)a2 + 1) + *((unsigned int *)a2 + 1));
  v12 = *((_DWORD *)this + 16) & 0xA2AA0;
  if ( (*((_DWORD *)this + 16) & 0xF3FC0) != 0 )
    v13 = 12;
  else
    v13 = 36;
  v41 = v6;
  v14 = &v11[v7 + v6 + v5];
  RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
  v15 = (__int64 *)*((_QWORD *)this + 1);
  if ( v15 )
    v16 = *v15;
  else
    v16 = 0i64;
  v17 = SslComputeFinishedHash(
          v16,
          *(_QWORD *)(*((_QWORD *)this + 11) + 16i64),
          *((_QWORD *)this + 74),
          v14,
          v13,
          2 - (unsigned int)(v12 != 0));
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
  if ( v17 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 901, v17, 0x50u);
    return v17;
  }
  if ( !*((_BYTE *)this + 340) )
  {
    memcpy_0((char *)this + 341, v14, v13);
    *((_BYTE *)this + 340) = 1;
    if ( *((_QWORD *)this + 103) )
    {
      v31 = *((_QWORD *)this + 11);
      if ( v31 )
      {
        RtlAcquireResourceShared((PRTL_RESOURCE)(v31 + 72), 1u);
        v32 = *((_QWORD *)this + 11);
        v33 = *(_QWORD *)(v32 + 16);
        if ( !v33 )
        {
LABEL_58:
          RtlReleaseResource((PRTL_RESOURCE)(v32 + 72));
          goto LABEL_24;
        }
        v34 = (void *)(*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(this, 32i64);
        if ( !v34 )
        {
          v32 = *((_QWORD *)this + 11);
          goto LABEL_58;
        }
        v35 = (__int64 *)*((_QWORD *)this + 1);
        if ( v35 )
          v36 = *v35;
        else
          v36 = 0i64;
        v37 = SslExportKeyingMaterial(v36, v33, "EXPORTER-Token-Binding", (char *)this + 272, 64, 0i64, 0, v34, 32, 0);
        RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
        if ( v37 )
          goto LABEL_65;
        v38 = *((_QWORD *)this + 104);
        if ( v38 )
        {
          v39 = *(void **)(v38 + 8);
          if ( v39 )
          {
            memset(v39, 0, 0x20ui64);
            (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(
              this,
              *(_QWORD *)(*((_QWORD *)this + 104) + 8i64));
            v38 = *((_QWORD *)this + 104);
          }
        }
        else
        {
          v38 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(this, 16i64);
          *((_QWORD *)this + 104) = v38;
          if ( !v38 )
          {
LABEL_65:
            memset(v34, 0, 0x20ui64);
            (*(void (__fastcall **)(CSsl3TlsContext *, void *))(*(_QWORD *)this + 16i64))(this, v34);
            goto LABEL_24;
          }
        }
        *(_DWORD *)v38 = 32;
        *(_QWORD *)(*((_QWORD *)this + 104) + 8i64) = v34;
      }
    }
  }
LABEL_24:
  if ( v12 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 65i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    v18 = v13;
    memcpy_0((char *)this + 377, v14, v13);
    *((_DWORD *)this + 104) = v13;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 66i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    v18 = v13;
    memcpy_0((char *)this + 420, v14, v13);
    *((_DWORD *)this + 114) = v13;
  }
  v20 = *((_WORD *)this + 110);
  v21 = &v11[v41 + v45];
  v22 = *((_BYTE *)this + 233) == 0;
  *v21 = 20;
  if ( v22 )
  {
    v23 = v13;
    v24 = 4i64;
    v25 = HIWORD(v13);
  }
  else
  {
    v21[5] = v20;
    v24 = 12i64;
    v21[4] = HIBYTE(v20);
    v23 = v13;
    v25 = HIWORD(v13);
    v21[11] = v13;
    *(_WORD *)(v21 + 7) = 0;
    v21[6] = 0;
    *(_WORD *)(v21 + 9) = BYTE2(v13);
  }
  v21[1] = v25;
  v21[3] = v23;
  v21[2] = 0;
  if ( v14 )
    memcpy_0(&v21[v24], v14, v18);
  if ( *((_BYTE *)this + 233) )
    ++*((_WORD *)this + 110);
  if ( !v42 )
  {
    if ( !v12 )
      goto LABEL_37;
LABEL_41:
    v26 = v43;
    goto LABEL_38;
  }
  if ( !v12 )
    goto LABEL_41;
LABEL_37:
  v26 = v43;
  LOBYTE(v19) = 1;
  v27 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, _BYTE *, _QWORD, __int64))(*(_QWORD *)this + 504i64))(
          this,
          v21,
          v43 + v13,
          v19);
  v28 = v27;
  if ( v27 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 1000, v27, 0x50u);
    return v28;
  }
LABEL_38:
  if ( !*((_BYTE *)this + 233) )
    return CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, 22, v26 + v13);
  *((_DWORD *)a2 + 1) += v44 + v45 + v26 + v13;
  v40 = *((_WORD *)this + 17);
  v11[2] = v40;
  v11[1] = HIBYTE(v40);
  v11[12] = v26 + v13;
  v11[11] = (unsigned __int16)(v26 + v13) >> 8;
  result = 0i64;
  *v11 = 22;
  return result;
}
// 1800093BF: variable 'v19' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098538: using guessed type __int64 __fastcall SslComputeFinishedHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
// 180098560: using guessed type __int64 __fastcall SslExportKeyingMaterial(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD, _QWORD, _DWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);
