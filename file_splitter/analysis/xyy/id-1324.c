//----- (00000001800680E8) ----------------------------------------------------
unsigned int __fastcall CTls13ServerHandshake::GenerateServerHelloOrHRR(
        CTls13ServerHandshake *this,
        char a2,
        unsigned __int8 *a3)
{
  UCHAR *v3; // rsi
  unsigned int result; // eax
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rax
  int v10; // eax
  __int64 v11; // rcx
  __int64 v12; // rcx
  __int16 v13[2]; // [rsp+20h] [rbp-18h] BYREF
  __int16 v14[10]; // [rsp+24h] [rbp-14h] BYREF
  unsigned __int8 v15; // [rsp+50h] [rbp+18h] BYREF
  char v16; // [rsp+58h] [rbp+20h] BYREF

  v3 = a3;
  if ( !a3 && a2 )
    return 87;
  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader(
             (__int64)this,
             2,
             *((_WORD *)this + 80));
  if ( !result )
  {
    v7 = *((_QWORD *)this + 4);
    v13[0] = 771;
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v7 + 32i64))(v7, 2i64, v13);
    if ( !result && (!a2 || (result = GenerateRandomBits(v3, 0x20u)) == 0) )
    {
      if ( !a2 )
        v3 = (UCHAR *)&unk_1800858B0;
      result = (*(__int64 (__fastcall **)(_QWORD, __int64, UCHAR *))(**((_QWORD **)this + 4) + 32i64))(
                 *((_QWORD *)this + 4),
                 32i64,
                 v3);
      if ( !result )
      {
        v15 = *(_BYTE *)(*((_QWORD *)this + 1) + 1281i64);
        result = (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned __int8 *))(**((_QWORD **)this + 4) + 32i64))(
                   *((_QWORD *)this + 4),
                   1i64,
                   &v15);
        if ( !result
          && (!v15
           || (result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**((_QWORD **)this + 4) + 32i64))(
                          *((_QWORD *)this + 4),
                          v15,
                          *((_QWORD *)this + 1) + 1249i64)) == 0) )
        {
          v8 = *((_QWORD *)this + 1);
          if ( (*(_BYTE *)(v8 + 32) & 1) != 0 && (v9 = *(_QWORD *)(v8 + 8)) != 0 )
            v10 = *(_DWORD *)(v9 + 28);
          else
            LOWORD(v10) = 0;
          v11 = *((_QWORD *)this + 4);
          v14[0] = __ROR2__(v10, 8);
          result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v11 + 32i64))(v11, 2i64, v14);
          if ( !result )
          {
            v12 = *((_QWORD *)this + 4);
            v16 = 0;
            result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v12 + 32i64))(v12, 1i64, &v16);
            if ( !result )
            {
              if ( a2 )
                result = CTls13ServerHandshake::GenerateServerHelloExtensions(this);
              else
                result = CTls13ServerHandshake::GenerateHRRExtensions(this);
              if ( !result )
                return (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 4) + 40i64))(*((_QWORD *)this + 4));
            }
          }
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 1800680E8: using guessed type __int16 var_18[2];
// 1800680E8: using guessed type __int16 var_14[10];
