// File count: 434
// Total lines: 235
----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::GenerateServerHello(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int *a3,
        struct CTlsExtServer *a4)
{
  int v8; // r15d
  unsigned int v9; // r10d
  char v10; // r8
  int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned __int8 *v15; // rbx
  int v16; // edx
  char v17; // al
  char v18; // cl
  unsigned int v19; // edi
  unsigned int v20; // r14d
  __int64 v21; // rdx
  char *v22; // rbx
  unsigned int v23; // edi
  char *v24; // rbx
  __int64 v25; // rax
  unsigned int v26; // edi
  unsigned int v27; // eax
  __int64 result; // rax
  __int16 v29; // r8
  unsigned int v30; // ecx
  unsigned int v31; // ecx
  bool v32; // zf
  unsigned int v33; // eax
  __int64 v34; // rcx
  __int64 v35; // rdx
  __int64 v36; // rax
  _DWORD *v37; // rcx
  __int64 v38; // rax
  __int64 v39; // rax
  int v40; // [rsp+20h] [rbp-38h]
  unsigned int v41; // [rsp+24h] [rbp-34h]
  unsigned int v42; // [rsp+68h] [rbp+10h] BYREF

  if ( !a2 || !a3 )
    return 87i64;
  LOWORD(v8) = 0;
  LOWORD(v9) = 0;
  if ( a4 )
  {
    v9 = *((_DWORD *)a4 + 5);
    if ( !v9 )
    {
      v34 = *((_QWORD *)a4 + 1);
      v35 = 0i64;
      if ( *(_BYTE *)(v34 + 922) )
      {
        v35 = 6i64;
        *((_BYTE *)a4 + 25) = 1;
        *((_DWORD *)a4 + 5) = 6;
      }
      if ( (*(_DWORD *)(v34 + 136) & 0x400000) != 0 )
        *((_DWORD *)a4 + 5) = v35 + 4;
      v36 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v34 + 88i64))(v34, v35);
      if ( v36 && *(_DWORD *)v36 == 1 && *(_DWORD *)(v36 + 4) == 2 )
        *((_DWORD *)a4 + 5) += *(unsigned __int8 *)(v36 + 8) + 7;
      v37 = (_DWORD *)*((_QWORD *)a4 + 1);
      if ( (v37[34] & 0x8000000) != 0 )
        *((_DWORD *)a4 + 5) += 4;
      v38 = (*(__int64 (__fastcall **)(_DWORD *))(*(_QWORD *)v37 + 96i64))(v37);
      if ( v38 )
        *((_DWORD *)a4 + 5) += *(unsigned __int8 *)(v38 + 2) + 9;
      v39 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)a4 + 1) + 104i64))(*((_QWORD *)a4 + 1));
      if ( v39 )
        *((_DWORD *)a4 + 5) += *(unsigned __int8 *)(v39 + 2) + 7;
      v9 = *((_DWORD *)a4 + 5);
      if ( (*(_DWORD *)(*((_QWORD *)a4 + 1) + 136i64) & 0x200000) != 0 )
      {
        v9 += 4;
        *((_DWORD *)a4 + 5) = v9;
      }
      if ( v9 )
      {
        v9 += 2;
        *((_DWORD *)a4 + 5) = v9;
      }
    }
    if ( v9 > 0xFFFF )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 50i64, &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids, 1359i64);
      return 1359i64;
    }
  }
  v10 = *((_BYTE *)this + 233);
  v11 = 4;
  v12 = 4;
  v40 = 4;
  if ( v10 )
    v12 = 12;
  v13 = (unsigned __int16)v9 + v12 + 70;
  v41 = v13;
  if ( *a3 < v13 )
  {
    *a3 = v13;
    return 234i64;
  }
  if ( v10 )
  {
    v11 = 12;
    v40 = 12;
  }
  v14 = v13 - v11;
  v15 = &a2[v11];
  v16 = *((_DWORD *)this + 16);
  if ( (v16 & 0x3FFC) != 0 && (v16 & 0xF0000) != 0 )
    goto LABEL_63;
  if ( (v16 & 0xC0000) != 0 )
  {
    v17 = -3;
    v18 = -2;
    goto LABEL_17;
  }
  if ( (v16 & 0x30000) != 0 )
  {
    v17 = -1;
    v18 = -2;
    goto LABEL_17;
  }
  if ( (v16 & 0x3000) != 0 )
  {
    v17 = 4;
LABEL_66:
    v18 = 3;
    goto LABEL_17;
  }
  if ( (v16 & 0xC00) == 0 )
  {
    if ( (v16 & 0x300) != 0 )
    {
      v17 = 2;
      goto LABEL_66;
    }
    if ( (v16 & 0xC0) != 0 )
    {
LABEL_65:
      v17 = 1;
      goto LABEL_66;
    }
    if ( (v16 & 0x30) != 0 )
    {
      v17 = 0;
      goto LABEL_66;
    }
    if ( (v16 & 0xC) != 0 )
    {
      v17 = 2;
      v18 = 0;
      goto LABEL_17;
    }
LABEL_63:
    if ( v10 )
    {
      v17 = -1;
      v18 = -2;
      goto LABEL_17;
    }
    goto LABEL_65;
  }
  v17 = 3;
  v18 = 3;
LABEL_17:
  *v15 = v18;
  v19 = v14 - 35;
  v15[1] = v17;
  v20 = v19;
  *(_OWORD *)(v15 + 2) = *((_OWORD *)this + 19);
  *(_OWORD *)(v15 + 18) = *((_OWORD *)this + 20);
  v21 = *((_QWORD *)this + 124);
  v22 = (char *)(v15 + 35);
  if ( v19 >= *(unsigned __int16 *)(v21 + 238) )
  {
    v20 = *(unsigned __int16 *)(v21 + 238);
    memcpy_0(v22, (const void *)(v21 + 240), *(unsigned __int16 *)(v21 + 238));
  }
  *(v22 - 1) = v20;
  v23 = v19 - v20;
  v24 = &v22[v20];
  if ( (*((_BYTE *)this + 32) & 1) != 0 )
  {
    v25 = *((_QWORD *)this + 1);
    if ( v25 )
      v8 = *(_DWORD *)(v25 + 28);
  }
  v26 = v23 - 3;
  *v24 = BYTE1(v8);
  v27 = v26;
  v24[1] = v8;
  v24[2] = 0;
  v42 = v26;
  if ( a4 && v26 )
  {
    result = CTlsExtServer::BuildServerHelloExtension(a4, v26, (unsigned __int8 *)v24 + 3, &v42);
    if ( (_DWORD)result )
      return result;
    v27 = v42;
  }
  v29 = *((_WORD *)this + 110);
  v30 = v27 - v26 + v41;
  *a3 = v30;
  v31 = v30 - v40;
  *((_WORD *)this + 110) = v29 + 1;
  v32 = *((_BYTE *)this + 233) == 0;
  *a2 = 2;
  if ( v32 )
  {
    v33 = HIWORD(v31);
  }
  else
  {
    a2[5] = v29;
    v33 = HIWORD(v31);
    a2[9] = BYTE2(v31);
    a2[4] = HIBYTE(v29);
    *(_WORD *)(a2 + 7) = 0;
    a2[6] = 0;
    a2[11] = v31;
    a2[10] = BYTE1(v31);
  }
  a2[1] = v33;
  result = 0i64;
  a2[3] = v31;
  a2[2] = BYTE1(v31);
  return result;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
