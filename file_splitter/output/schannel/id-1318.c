// File count: 1318
// Total lines: 79
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::GeneratePskExtension(CTls13ClientHandshake *this)
{
  __int16 v1; // r8
  unsigned int ExtensionHeader; // ebx
  __int64 v5; // rcx
  int v6; // esi
  __int64 v7; // r14
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rbx
  int ElapsedTime; // eax
  __int64 v12; // rcx
  __int16 v13; // [rsp+50h] [rbp+30h] BYREF
  unsigned __int32 v14; // [rsp+58h] [rbp+38h] BYREF
  __int64 v15; // [rsp+60h] [rbp+40h] BYREF

  v1 = *((_WORD *)this + 78);
  if ( !v1 )
    return 0i64;
  v15 = 0i64;
  ExtensionHeader = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::GenerateExtensionHeader((__int64)this, 41, v1);
  if ( ExtensionHeader )
    goto LABEL_13;
  (*(void (__fastcall **)(_QWORD, __int64 *))(**((_QWORD **)this + 1) + 224i64))(*((_QWORD *)this + 1), &v15);
  if ( v15 )
  {
    RtlAcquireResourceShared((PRTL_RESOURCE)(v15 + 72), 1u);
    v5 = v15;
    v6 = *(_DWORD *)(v15 + 432);
    v7 = *(_QWORD *)(v15 + 424);
    if ( (unsigned int)(v6 - 1) > 0xFFF8 || !v7 )
    {
      ExtensionHeader = -2146893052;
LABEL_14:
      if ( v5 )
        RtlReleaseResource((PRTL_RESOURCE)(v5 + 72));
      return ExtensionHeader;
    }
    v8 = *((_QWORD *)this + 4);
    v13 = __ROR2__(v6 + 6, 8);
    ExtensionHeader = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v8 + 32i64))(v8, 2i64, &v13);
    if ( !ExtensionHeader )
    {
      v9 = *((_QWORD *)this + 4);
      v13 = __ROR2__(v6, 8);
      ExtensionHeader = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v9 + 32i64))(v9, 2i64, &v13);
      if ( !ExtensionHeader )
      {
        ExtensionHeader = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**((_QWORD **)this + 4) + 32i64))(
                            *((_QWORD *)this + 4),
                            (unsigned __int16)v6,
                            v7);
        if ( !ExtensionHeader )
        {
          v10 = v15;
          ElapsedTime = GetElapsedTime(*(_DWORD *)(v15 + 416));
          v12 = *((_QWORD *)this + 4);
          v14 = _byteswap_ulong(ElapsedTime + *(_DWORD *)(v10 + 212));
          ExtensionHeader = (*(__int64 (__fastcall **)(__int64, __int64, unsigned __int32 *))(*(_QWORD *)v12 + 32i64))(
                              v12,
                              4i64,
                              &v14);
          if ( !ExtensionHeader )
          {
            RtlReleaseResource((PRTL_RESOURCE)(v15 + 72));
            v15 = 0i64;
            ExtensionHeader = CTls13ClientHandshake::GenerateBinderEntry(this);
          }
        }
      }
    }
LABEL_13:
    v5 = v15;
    goto LABEL_14;
  }
  return (unsigned int)-2146893052;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
