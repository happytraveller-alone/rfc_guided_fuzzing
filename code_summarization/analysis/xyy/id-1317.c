//----- (0000000180067888) ----------------------------------------------------
unsigned int __fastcall CTls13ServerHandshake::GenerateNewSessionTicket(CTls13ServerHandshake *this)
{
  unsigned int result; // eax
  __int64 v3; // rcx
  __int64 v4; // rcx
  __int64 v5; // rdi
  __int128 *v6; // rsi
  unsigned __int16 v7; // di
  __int64 v8; // rsi
  __int64 v9; // rcx
  void *v10; // rcx
  __int64 v11; // rcx
  char v12[4]; // [rsp+20h] [rbp-50h] BYREF
  __int16 v13; // [rsp+24h] [rbp-4Ch] BYREF
  __int16 v14[2]; // [rsp+28h] [rbp-48h] BYREF
  UCHAR pbBuffer[4]; // [rsp+2Ch] [rbp-44h] BYREF
  __int64 v16; // [rsp+30h] [rbp-40h] BYREF
  unsigned __int32 v17; // [rsp+38h] [rbp-38h] BYREF
  __int128 v18[2]; // [rsp+40h] [rbp-30h] BYREF

  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(
             (__int64)this,
             4,
             *((_WORD *)this + 86));
  if ( !result )
  {
    v3 = *((_QWORD *)this + 4);
    v17 = _byteswap_ulong(CSslGlobals::m_dwServerLifespan / 0x3E8);
    result = (*(__int64 (__fastcall **)(__int64, __int64, unsigned __int32 *))(*(_QWORD *)v3 + 32i64))(v3, 4i64, &v17);
    if ( !result )
    {
      *(_DWORD *)pbBuffer = 0;
      result = GenerateRandomBits(pbBuffer, 4u);
      if ( !result )
      {
        result = (*(__int64 (__fastcall **)(_QWORD, __int64, UCHAR *))(**((_QWORD **)this + 4) + 32i64))(
                   *((_QWORD *)this + 4),
                   4i64,
                   pbBuffer);
        if ( !result )
        {
          v4 = *((_QWORD *)this + 1);
          v16 = 0i64;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v4 + 232i64))(v4, &v16);
          if ( v16 )
          {
            RtlAcquireResourceShared((PRTL_RESOURCE)(v16 + 72), 1u);
            v5 = *(_QWORD *)(v16 + 200);
            v12[0] = *(_BYTE *)(v16 + 208);
            RtlReleaseResource((PRTL_RESOURCE)(v16 + 72));
            result = (*(__int64 (__fastcall **)(_QWORD, __int64, char *))(**((_QWORD **)this + 4) + 32i64))(
                       *((_QWORD *)this + 4),
                       1i64,
                       v12);
            if ( !result )
            {
              result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**((_QWORD **)this + 4) + 32i64))(
                         *((_QWORD *)this + 4),
                         (unsigned __int8)v12[0],
                         v5);
              if ( !result )
              {
                v6 = (__int128 *)*((_QWORD *)this + 24);
                v7 = *((_WORD *)this + 100);
                memset(v18, 0, sizeof(v18));
                if ( !v6 )
                {
                  v7 = 32;
                  RtlAcquireResourceShared((PRTL_RESOURCE)(v16 + 72), 1u);
                  v8 = v16;
                  if ( *(unsigned __int16 *)(v16 + 238) <= 0x20u )
                  {
                    v7 = *(_WORD *)(v16 + 238);
                    memcpy_0(v18, (const void *)(v16 + 240), v7);
                  }
                  RtlReleaseResource((PRTL_RESOURCE)(v8 + 72));
                  v6 = v18;
                }
                v9 = *((_QWORD *)this + 4);
                v13 = __ROR2__(v7, 8);
                result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v9 + 32i64))(
                           v9,
                           2i64,
                           &v13);
                if ( !result )
                {
                  result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int128 *))(**((_QWORD **)this + 4) + 32i64))(
                             *((_QWORD *)this + 4),
                             v7,
                             v6);
                  if ( !result )
                  {
                    v10 = (void *)*((_QWORD *)this + 24);
                    if ( v10 )
                    {
                      LocalFree(v10);
                      *((_QWORD *)this + 24) = 0i64;
                      *((_WORD *)this + 100) = 0;
                    }
                    v11 = *((_QWORD *)this + 4);
                    v14[0] = 0;
                    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v11 + 32i64))(
                               v11,
                               2i64,
                               v14);
                    if ( !result )
                      return (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 4) + 40i64))(*((_QWORD *)this + 4));
                  }
                }
              }
            }
          }
          else
          {
            return 1359;
          }
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180067888: using guessed type char var_50[4];
// 180067888: using guessed type __int16 var_48[2];

