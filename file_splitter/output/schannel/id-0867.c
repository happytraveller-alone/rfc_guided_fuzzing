// File count: 867
// Total lines: 107
----------------------------------------
__int64 __fastcall CSsl3TlsContext::QueryKeyingMaterialCommon(
        CSsl3TlsContext *this,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        unsigned int a5,
        void *a6)
{
  void *v6; // rsi
  unsigned int v9; // edi
  ULONG v10; // ebx
  int v11; // r15d
  __int64 v12; // rax
  HLOCAL v14; // rax
  NTSTATUS v15; // eax
  __int64 v16; // [rsp+50h] [rbp-30h] BYREF
  __int128 v17; // [rsp+58h] [rbp-28h] BYREF
  __int128 v18; // [rsp+68h] [rbp-18h] BYREF
  __int64 v19; // [rsp+78h] [rbp-8h]

  v6 = 0i64;
  v19 = 0i64;
  v16 = 0i64;
  v17 = 0i64;
  v9 = 0;
  v18 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(__int128 *))(LsaTable + 192))(&v18) )
  {
    v10 = 1359;
    goto LABEL_12;
  }
  v11 = BYTE8(v18) & 0x40;
  if ( !a6 )
  {
    v10 = 87;
    goto LABEL_12;
  }
  if ( !a2 )
    goto LABEL_11;
  v12 = *((_QWORD *)this + 105);
  if ( !v12 )
    goto LABEL_11;
  if ( !a3 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids);
LABEL_11:
    v10 = -2146893055;
    goto LABEL_12;
  }
  v9 = *(_DWORD *)(v12 + 32);
  v14 = SPExternalAlloc(v9);
  v6 = v14;
  if ( v14 )
  {
    v10 = SslExportKeyingMaterial(
            a2,
            a3,
            *(_QWORD *)(*((_QWORD *)this + 105) + 8i64),
            a4,
            a5,
            *(_QWORD *)(*((_QWORD *)this + 105) + 24i64),
            *(_WORD *)(*((_QWORD *)this + 105) + 16i64),
            v14,
            v9,
            0);
    if ( !v10 )
    {
      v15 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(0i64, v9, &v16);
      if ( v15 < 0
        || (v15 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, void *))(LsaTable + 72))(0i64, v9, v16, v6),
            v15 < 0)
        || ((LODWORD(v17) = v9, !v11) ? (*((_QWORD *)&v17 + 1) = v16) : (DWORD1(v17) = v16),
            v15 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, void *, __int128 *))(LsaTable + 72))(
                    0i64,
                    v11 != 0 ? 8 : 16,
                    a6,
                    &v17),
            v10 = v15,
            v15 < 0) )
      {
        v10 = RtlNtStatusToDosError(v15);
      }
      if ( !v10 )
        goto LABEL_15;
    }
  }
  else
  {
    v10 = 14;
  }
LABEL_12:
  if ( v16 )
    (*(void (__fastcall **)(_QWORD))(LsaTable + 64))(0i64);
  if ( v6 )
  {
LABEL_15:
    memset(v6, 0, v9);
    SPExternalFree(v6);
  }
  return v10;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
// 180098560: using guessed type __int64 __fastcall SslExportKeyingMaterial(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD, _QWORD, _DWORD, _DWORD);
