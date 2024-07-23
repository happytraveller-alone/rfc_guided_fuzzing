// File count: 82
// Total lines: 71
------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetTokenBindingEKM(CSsl3TlsContext *this)
{
  __int64 v3; // rcx
  __int64 v4; // rcx
  __int64 v5; // rdi
  void *v6; // rbp
  __int64 *v7; // rax
  __int64 v8; // rcx
  unsigned int v9; // esi
  __int64 v10; // rax
  void *v11; // rdi

  if ( !*((_QWORD *)this + 103) )
    return 6i64;
  v3 = *((_QWORD *)this + 11);
  if ( !v3 )
    return 1359i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)(v3 + 72), 1u);
  v4 = *((_QWORD *)this + 11);
  v5 = *(_QWORD *)(v4 + 16);
  if ( !v5 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(v4 + 72));
    return 6i64;
  }
  v6 = (void *)(*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(this, 32i64);
  if ( !v6 )
  {
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
    return 14i64;
  }
  v7 = (__int64 *)*((_QWORD *)this + 1);
  if ( v7 )
    v8 = *v7;
  else
    v8 = 0i64;
  v9 = SslExportKeyingMaterial(v8, v5, "EXPORTER-Token-Binding", (char *)this + 272, 64, 0i64, 0, v6, 32, 0);
  RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
  if ( v9 )
    goto LABEL_16;
  v10 = *((_QWORD *)this + 104);
  if ( v10 )
  {
    v11 = *(void **)(v10 + 8);
    if ( v11 )
    {
      memset(v11, 0, 0x20ui64);
      (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(
        this,
        *(_QWORD *)(*((_QWORD *)this + 104) + 8i64));
      v10 = *((_QWORD *)this + 104);
    }
    goto LABEL_20;
  }
  v10 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(this, 16i64);
  *((_QWORD *)this + 104) = v10;
  if ( v10 )
  {
LABEL_20:
    *(_DWORD *)v10 = 32;
    *(_QWORD *)(*((_QWORD *)this + 104) + 8i64) = v6;
    return v9;
  }
  v9 = 14;
LABEL_16:
  memset(v6, 0, 0x20ui64);
  (*(void (__fastcall **)(CSsl3TlsContext *, void *))(*(_QWORD *)this + 16i64))(this, v6);
  return v9;
}
// 180098560: using guessed type __int64 __fastcall SslExportKeyingMaterial(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD, _QWORD, _DWORD, _DWORD);
