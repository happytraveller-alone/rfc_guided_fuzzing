//----- (000000018000DDA0) ----------------------------------------------------
__int64 __fastcall CSslSerializeHelper::SerializeContextWorker(
        CSslSerializeHelper *this,
        void (__fastcall *a2)(__int64, __int64 *))
{
  __int64 result; // rax
  __int64 v5; // rax
  unsigned int v7; // edx
  unsigned int v8; // edi
  __int64 v9; // rdx
  __int64 v10; // rsi
  _DWORD *v11; // rdi
  int v12; // eax
  int v13; // edx
  __int64 v14; // rdx
  _DWORD *v15; // rdi
  int v16; // eax
  int v17; // edx
  __int64 v18; // rcx
  void *v19; // r9
  unsigned int v20; // edi
  void *v21; // r9
  unsigned int v22; // edi
  void *v23; // rdx
  size_t v24; // r8
  unsigned int v25; // edi
  void *v26; // r9
  unsigned int v27; // edi
  __int128 *v28; // rcx
  const void **v29; // rax
  const void **v30; // rdi
  const void **v31; // rax
  const void **v32; // rdi
  __int64 v33; // rax
  __int64 v34; // rax
  bool v35; // cf
  __int64 v36; // rax
  __int64 v37; // rsi
  _DWORD *v38; // rcx
  _DWORD *v39; // rcx
  size_t v40; // r8
  __int64 v41; // rax
  _DWORD *v42; // rcx
  size_t v43; // r8
  _DWORD *v44; // rcx
  size_t v45; // r8
  _DWORD *v46; // rcx
  _DWORD *v47; // rax
  _QWORD *v48; // rdx
  __int128 v49; // xmm0
  const void *v50; // r8
  __int64 v51; // [rsp+70h] [rbp-90h] BYREF
  size_t v52; // [rsp+78h] [rbp-88h] BYREF
  unsigned int v53; // [rsp+80h] [rbp-80h] BYREF
  size_t Size; // [rsp+84h] [rbp-7Ch] BYREF
  __int64 v55; // [rsp+90h] [rbp-70h] BYREF
  unsigned int v56; // [rsp+98h] [rbp-68h] BYREF
  unsigned int v57; // [rsp+9Ch] [rbp-64h] BYREF
  __int64 v58; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v59; // [rsp+A8h] [rbp-58h] BYREF
  const void *v60; // [rsp+B0h] [rbp-50h] BYREF
  const void *v61; // [rsp+B8h] [rbp-48h] BYREF
  const void *v62; // [rsp+C0h] [rbp-40h] BYREF
  void *v63; // [rsp+C8h] [rbp-38h] BYREF
  void *v64; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v65; // [rsp+D8h] [rbp-28h] BYREF
  __int64 v66; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v67; // [rsp+E8h] [rbp-18h] BYREF
  void *v68; // [rsp+F0h] [rbp-10h] BYREF
  void *v69; // [rsp+F8h] [rbp-8h] BYREF
  _WORD Src[256]; // [rsp+100h] [rbp+0h] BYREF

  v52 = 0i64;
  v60 = 0i64;
  v61 = 0i64;
  v62 = 0i64;
  v53 = 0;
  v63 = 0i64;
  Size = 0i64;
  v64 = 0i64;
  if ( *((_QWORD *)this + 1) )
  {
    v35 = *((_DWORD *)this + 7) < 0xD8u;
    v51 = 0i64;
    if ( v35 )
      return 2148074244i64;
    v36 = *((_QWORD *)this + 2);
    *(_DWORD *)v36 = 1;
    v37 = v36 + 16;
    *(_QWORD *)(v36 + 4) = 200i64;
    result = (*(__int64 (__fastcall **)(_QWORD, __int64))(**(_QWORD **)this + 24i64))(*(_QWORD *)this, v36 + 16);
    if ( (_DWORD)result )
      return result;
    (*(void (__fastcall **)(_QWORD, __int64 *, __int64))(**(_QWORD **)this + 72i64))(*(_QWORD *)this, &v65, v37 + 72);
    if ( v65 )
    {
      if ( a2 )
        a2(v65, &v51);
      *(_QWORD *)(v37 + 64) = v51;
    }
    *((_QWORD *)this + 2) += 216i64;
    *((_DWORD *)this + 7) -= 216;
  }
  else
  {
    *((_DWORD *)this + 6) += 216;
  }
  result = (*(__int64 (__fastcall **)(_QWORD, _WORD *, __int64 *))(**(_QWORD **)this + 32i64))(
             *(_QWORD *)this,
             Src,
             &v55);
  if ( (_DWORD)result )
    return result;
  v5 = -1i64;
  while ( Src[++v5] != 0 )
    ;
  v7 = 2 * v5 + 2;
  v8 = (2 * v5 + 25) & 0xFFFFFFF8;
  if ( *((_QWORD *)this + 1) )
  {
    if ( *((_DWORD *)this + 7) < v8 )
      return 1359i64;
    v38 = (_DWORD *)*((_QWORD *)this + 2);
    v38[2] = v7;
    *v38 = 9;
    v38[1] = v8 - 16;
    memcpy_0((void *)(*((_QWORD *)this + 2) + 16i64), Src, v7);
    *((_QWORD *)this + 2) += v8;
    *((_DWORD *)this + 7) -= v8;
  }
  else
  {
    *((_DWORD *)this + 6) += v8;
  }
  (*(void (__fastcall **)(_QWORD, __int64 *, __int64 *))(**(_QWORD **)this + 40i64))(*(_QWORD *)this, &v66, &v67);
  v9 = v66;
  v10 = 2i64;
  if ( v66 )
  {
    v11 = (_DWORD *)*((_QWORD *)this + 2);
    v12 = *((_DWORD *)this + 7);
    if ( *((_QWORD *)this + 1) )
    {
      v12 -= 16;
      *((_QWORD *)this + 2) = v11 + 4;
      *((_DWORD *)this + 7) = v12;
    }
    LODWORD(v51) = v12;
    result = SslExportKey(v55, v9, L"OpaqueKeyBlob");
    if ( (_DWORD)result && (_DWORD)result != -2146893784 )
      return result;
    v13 = (v51 + 23) & 0xFFFFFFF8;
    if ( *((_QWORD *)this + 1) )
    {
      *v11 = 2;
      v11[1] = v13 - 16;
      v11[2] = v51;
      *((_QWORD *)this + 2) += (unsigned int)(v13 - 16);
      *((_DWORD *)this + 7) += 16 - v13;
    }
    else
    {
      *((_DWORD *)this + 6) += v13;
    }
  }
  v14 = v67;
  if ( !v67 )
    goto LABEL_20;
  v15 = (_DWORD *)*((_QWORD *)this + 2);
  v16 = *((_DWORD *)this + 7);
  if ( *((_QWORD *)this + 1) )
  {
    v16 -= 16;
    *((_QWORD *)this + 2) = v15 + 4;
    *((_DWORD *)this + 7) = v16;
  }
  LODWORD(v51) = v16;
  result = SslExportKey(v55, v14, L"OpaqueKeyBlob");
  if ( !(_DWORD)result || (_DWORD)result == -2146893784 )
  {
    v17 = (v51 + 23) & 0xFFFFFFF8;
    if ( *((_QWORD *)this + 1) )
    {
      *v15 = 3;
      v15[1] = v17 - 16;
      v15[2] = v51;
      *((_QWORD *)this + 2) += (unsigned int)(v17 - 16);
      *((_DWORD *)this + 7) += 16 - v17;
    }
    else
    {
      *((_DWORD *)this + 6) += v17;
    }
LABEL_20:
    v18 = *(_QWORD *)this;
    v58 = 0i64;
    v59 = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *, __int64 *))(*(_QWORD *)v18 + 48i64))(v18, &v58, &v59);
    if ( v58 )
    {
      result = CSslSerializeHelper::SerializeEncryptionKey((__int64)this, 19, v55, v58);
      if ( (_DWORD)result )
        return result;
    }
    if ( v59 )
    {
      result = CSslSerializeHelper::SerializeEncryptionKey((__int64)this, 20, v55, v59);
      if ( (_DWORD)result )
        return result;
    }
    (*(void (__fastcall **)(_QWORD, const void **, unsigned int *, void **, size_t *, void **, char *, const void **, unsigned int *, const void **, unsigned int *, void **, size_t *))(**(_QWORD **)this + 56i64))(
      *(_QWORD *)this,
      &v60,
      &v56,
      &v68,
      &v52,
      &v69,
      (char *)&v52 + 4,
      &v61,
      &v57,
      &v62,
      &v53,
      &v63,
      &Size);
    if ( v60 )
    {
      result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 4, v60, v56);
      if ( (_DWORD)result )
        return result;
    }
    if ( (_DWORD)v52 )
    {
      v19 = v68;
      v20 = (v52 + 23) & 0xFFFFFFF8;
      if ( *((_QWORD *)this + 1) )
      {
        if ( *((_DWORD *)this + 7) < v20 )
          return 1359i64;
        v42 = (_DWORD *)*((_QWORD *)this + 2);
        v43 = (unsigned int)v52;
        v42[2] = v52;
        *v42 = 5;
        v42[1] = v20 - 16;
        memcpy_0((void *)(*((_QWORD *)this + 2) + 16i64), v19, v43);
        *((_QWORD *)this + 2) += v20;
        *((_DWORD *)this + 7) -= v20;
      }
      else
      {
        *((_DWORD *)this + 6) += v20;
      }
    }
    if ( HIDWORD(v52) )
    {
      v21 = v69;
      v22 = (HIDWORD(v52) + 23) & 0xFFFFFFF8;
      if ( *((_QWORD *)this + 1) )
      {
        if ( *((_DWORD *)this + 7) < v22 )
          return 1359i64;
        v44 = (_DWORD *)*((_QWORD *)this + 2);
        v45 = HIDWORD(v52);
        v44[2] = HIDWORD(v52);
        *v44 = 6;
        v44[1] = v22 - 16;
        memcpy_0((void *)(*((_QWORD *)this + 2) + 16i64), v21, v45);
        *((_QWORD *)this + 2) += v22;
        *((_DWORD *)this + 7) -= v22;
      }
      else
      {
        *((_DWORD *)this + 6) += v22;
      }
    }
    if ( v61 )
    {
      result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 7, v61, v57);
      if ( (_DWORD)result )
        return result;
    }
    if ( v62 )
    {
      if ( v53 )
      {
        result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 8, v62, v53);
        if ( (_DWORD)result )
          return result;
      }
    }
    v23 = v63;
    if ( v63 )
    {
      v24 = (unsigned int)Size;
      v25 = (Size + 23) & 0xFFFFFFF8;
      if ( *((_QWORD *)this + 1) )
      {
        if ( *((_DWORD *)this + 7) < v25 )
          return 1359i64;
        v46 = (_DWORD *)*((_QWORD *)this + 2);
        *v46 = 10;
        v46[1] = v25 - 16;
        v46[2] = v24;
        memcpy_0((void *)(*((_QWORD *)this + 2) + 16i64), v23, v24);
        *((_QWORD *)this + 2) += v25;
        *((_DWORD *)this + 7) -= v25;
      }
      else
      {
        *((_DWORD *)this + 6) += v25;
      }
    }
    (*(void (__fastcall **)(_QWORD, void **, char *))(**(_QWORD **)this + 80i64))(
      *(_QWORD *)this,
      &v64,
      (char *)&Size + 4);
    if ( HIDWORD(Size) )
    {
      v26 = v64;
      v27 = (HIDWORD(Size) + 23) & 0xFFFFFFF8;
      if ( *((_QWORD *)this + 1) )
      {
        if ( *((_DWORD *)this + 7) < v27 )
          return 1359i64;
        v39 = (_DWORD *)*((_QWORD *)this + 2);
        v40 = HIDWORD(Size);
        v39[2] = HIDWORD(Size);
        *v39 = 11;
        v39[1] = v27 - 16;
        memcpy_0((void *)(*((_QWORD *)this + 2) + 16i64), v26, v40);
        *((_QWORD *)this + 2) += v27;
        *((_DWORD *)this + 7) -= v27;
      }
      else
      {
        *((_DWORD *)this + 6) += v27;
      }
    }
    v28 = (__int128 *)(*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)this + 88i64))(*(_QWORD *)this);
    if ( v28 )
    {
      if ( *((_QWORD *)this + 1) )
      {
        if ( *((_DWORD *)this + 7) < 0x118u )
          return 1359i64;
        v47 = (_DWORD *)*((_QWORD *)this + 2);
        *v47 = 12;
        v47[1] = 264;
        v47[2] = 264;
        v48 = (_QWORD *)(*((_QWORD *)this + 2) + 16i64);
        do
        {
          v48 += 16;
          v49 = *v28;
          v28 += 8;
          *((_OWORD *)v48 - 8) = v49;
          *((_OWORD *)v48 - 7) = *(v28 - 7);
          *((_OWORD *)v48 - 6) = *(v28 - 6);
          *((_OWORD *)v48 - 5) = *(v28 - 5);
          *((_OWORD *)v48 - 4) = *(v28 - 4);
          *((_OWORD *)v48 - 3) = *(v28 - 3);
          *((_OWORD *)v48 - 2) = *(v28 - 2);
          *((_OWORD *)v48 - 1) = *(v28 - 1);
          --v10;
        }
        while ( v10 );
        *v48 = *(_QWORD *)v28;
        *((_QWORD *)this + 2) += 280i64;
        *((_DWORD *)this + 7) -= 280;
      }
      else
      {
        *((_DWORD *)this + 6) += 280;
      }
    }
    v29 = (const void **)(*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)this + 96i64))(*(_QWORD *)this);
    v30 = v29;
    if ( v29 )
    {
      result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 13, v29, 0x10u);
      if ( (_DWORD)result )
        return result;
      if ( *((_BYTE *)v30 + 2) )
      {
        result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 14, v30[1], *((unsigned __int8 *)v30 + 2));
        if ( (_DWORD)result )
          return result;
      }
    }
    v31 = (const void **)(*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)this + 104i64))(*(_QWORD *)this);
    v32 = v31;
    if ( v31 )
    {
      result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 15, v31, 0x10u);
      if ( (_DWORD)result )
        return result;
      if ( *((_WORD *)v32 + 1) )
      {
        result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 16, v32[1], *((unsigned __int16 *)v32 + 1));
        if ( (_DWORD)result )
          return result;
      }
    }
    v33 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)this + 112i64))(*(_QWORD *)this);
    if ( v33 )
    {
      v50 = *(const void **)(v33 + 8);
      if ( v50 )
      {
        result = CSslSerializeHelper::SerializeDataBlob((__int64)this, 17, v50, *(_DWORD *)v33);
        if ( (_DWORD)result )
          return result;
      }
    }
    v34 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)this + 120i64))(*(_QWORD *)this);
    if ( v34 )
    {
      result = CSslSerializeHelper::SerializeEncryptionKey((__int64)this, 18, v55, v34);
      if ( (_DWORD)result )
        return result;
    }
    if ( !*((_QWORD *)this + 1) )
    {
      *((_DWORD *)this + 6) += 16;
      return 0i64;
    }
    if ( *((_DWORD *)this + 7) >= 0x10u )
    {
      v41 = *((_QWORD *)this + 2);
      *(_QWORD *)v41 = 0i64;
      *(_DWORD *)(v41 + 8) = 0;
      *((_QWORD *)this + 2) += 16i64;
      *((_DWORD *)this + 7) -= 16;
      return 0i64;
    }
    return 1359i64;
  }
  return result;
}
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180098528: using guessed type __int64 __fastcall SslExportKey(_QWORD, _QWORD, _QWORD);
// 18000DDA0: using guessed type _WORD Src[256];

