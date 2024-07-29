//----- (0000000180069B50) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::ParseNewSessionTicket(
        CTls13ClientHandshake *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  void *v4; // r14
  void *v5; // r15
  int v6; // edx
  __int64 v7; // rcx
  unsigned int v8; // ebx
  size_t v9; // r12
  unsigned __int8 *v10; // rsi
  unsigned int v11; // edi
  int v12; // ebx
  HLOCAL v13; // rax
  unsigned __int16 *v14; // rsi
  unsigned int v15; // edi
  unsigned int v16; // edi
  unsigned __int16 v17; // bx
  unsigned int v18; // r13d
  HLOCAL v19; // rax
  unsigned int v20; // edi
  unsigned int v21; // edi
  unsigned int v22; // eax
  _QWORD *v23; // rcx
  int v24; // r8d
  int v25; // edx
  __int64 v26; // rdi
  CSessionCacheClientItem *v28; // [rsp+50h] [rbp-48h] BYREF
  unsigned __int32 v29; // [rsp+A8h] [rbp+10h]
  unsigned int v30; // [rsp+B8h] [rbp+20h]

  v4 = 0i64;
  v5 = 0i64;
  if ( a2 && a3 )
  {
    if ( a3 < 4 )
    {
      v6 = 1400;
LABEL_5:
      v7 = *((_QWORD *)this + 1);
LABEL_6:
      v8 = -2146893048;
      CSslContext::SetErrorAndFatalAlert(v7, v6, -2146893048, 0x32u);
      return v8;
    }
    v29 = _byteswap_ulong(*(_DWORD *)a2);
    if ( v29 > 0x93A80 )
    {
      v6 = 1403;
      goto LABEL_5;
    }
    if ( a3 - 4 < 4
      || (v30 = *((_DWORD *)a2 + 1), a3 == 8)
      || (v9 = a2[8], v10 = a2 + 9, v11 = a3 - 9, v12 = a2[8], a3 - 9 < (unsigned int)v9) )
    {
      v7 = *((_QWORD *)this + 1);
      v6 = 1400;
      goto LABEL_6;
    }
    if ( (_BYTE)v9 )
    {
      v13 = SPExternalAlloc(a2[8]);
      v4 = v13;
      if ( !v13 )
        return 14;
      memcpy_0(v13, v10, v9);
    }
    v14 = (unsigned __int16 *)&v10[v9];
    v15 = v11 - v12;
    if ( v15 < 2 )
      goto LABEL_32;
    v16 = v15 - 2;
    v17 = _byteswap_ushort(*v14);
    if ( !v17 )
      goto LABEL_32;
    v18 = v17;
    if ( v16 < v17 )
      goto LABEL_32;
    v19 = SPExternalAlloc(v17);
    v5 = v19;
    if ( !v19 )
    {
      v8 = 14;
LABEL_34:
      if ( v4 )
        SPExternalFree(v4);
      if ( v5 )
        SPExternalFree(v5);
      return v8;
    }
    memcpy_0(v19, v14 + 1, v17);
    v20 = v16 - v17;
    if ( v20 >= 2
      && (v21 = v20 - 2, v21 == (*((unsigned __int8 *)v14 + v17 + 3) | (*((unsigned __int8 *)v14 + v17 + 2) << 8))) )
    {
      v22 = CTlsExt::ParseTlsExtensions(*((_QWORD *)this + 2), (unsigned __int8 *)v14 + v17 + 4, v21, 4);
      v23 = (_QWORD *)*((_QWORD *)this + 1);
      v8 = v22;
      if ( !v22 )
      {
        v26 = v23[10];
        if ( v26 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 30i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids, v18);
            v23 = (_QWORD *)*((_QWORD *)this + 1);
          }
          v28 = 0i64;
          (*(void (__fastcall **)(_QWORD *, CSessionCacheClientItem **))(*v23 + 224i64))(v23, &v28);
          RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)v28 + 72), 1u);
          CSessionCacheClientItem::SetSessionTicket(
            v28,
            (unsigned __int8 *)v5,
            v18,
            (unsigned __int8 *)v4,
            v9,
            v30,
            v29,
            *(_DWORD *)(v26 + 208),
            *(_DWORD *)(*((_QWORD *)this + 1) + 64i64));
          RtlReleaseResource((PRTL_RESOURCE)((char *)v28 + 72));
          return v8;
        }
        v8 = -2146893052;
        goto LABEL_34;
      }
      v24 = v22;
      v25 = 1403;
    }
    else
    {
LABEL_32:
      v23 = (_QWORD *)*((_QWORD *)this + 1);
      v8 = -2146893048;
      v24 = -2146893048;
      v25 = 1400;
    }
    CSslContext::SetErrorAndFatalAlert((__int64)v23, v25, v24, 0x32u);
    goto LABEL_34;
  }
  return 87i64;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
