// File count: 1302
// Total lines: 119
---------------------------------------
unsigned int __fastcall CTls13ClientHandshake::GenerateClientHello(
        CTls13ClientHandshake *this,
        int a2,
        unsigned int *a3,
        __int16 a4,
        const unsigned __int16 *a5,
        PUCHAR pbBuffer)
{
  UCHAR *v8; // rsi
  __int64 v9; // rax
  unsigned __int16 v10; // r8
  unsigned int result; // eax
  __int64 v12; // rcx
  __int64 v13; // rcx
  unsigned int *v14; // rsi
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // rcx
  char v18[4]; // [rsp+20h] [rbp-10h] BYREF
  __int16 v19; // [rsp+24h] [rbp-Ch] BYREF
  __int16 v20[2]; // [rsp+28h] [rbp-8h] BYREF
  __int16 v21; // [rsp+2Ch] [rbp-4h] BYREF
  char v22; // [rsp+50h] [rbp+20h] BYREF
  unsigned __int8 v23; // [rsp+58h] [rbp+28h] BYREF

  if ( a2 != *((unsigned __int16 *)this + 80) )
    return 87;
  if ( !a3 )
    return 87;
  if ( a4 != *((_WORD *)this + 63) )
    return 87;
  if ( !a5 )
    return 87;
  v8 = pbBuffer;
  if ( !pbBuffer )
    return 87;
  v9 = *((_QWORD *)this + 1);
  if ( !*(_WORD *)(v9 + 920) || !*(_QWORD *)(v9 + 912) )
    return 87;
  v10 = *((_WORD *)this + 84);
  *((_QWORD *)this + 16) = a5;
  result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::GenerateHandshakeHeader((__int64)this, 1, v10);
  if ( !result )
  {
    v12 = *((_QWORD *)this + 4);
    v19 = 771;
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v12 + 32i64))(v12, 2i64, &v19);
    if ( !result && (*(_DWORD *)(*((_QWORD *)this + 1) + 68i64) == 100 || (result = GenerateRandomBits(v8, 0x20u)) == 0) )
    {
      result = (*(__int64 (__fastcall **)(_QWORD, __int64, UCHAR *))(**((_QWORD **)this + 4) + 32i64))(
                 *((_QWORD *)this + 4),
                 32i64,
                 v8);
      if ( !result )
      {
        v23 = *(_BYTE *)(*((_QWORD *)this + 1) + 1649i64);
        result = (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned __int8 *))(**((_QWORD **)this + 4) + 32i64))(
                   *((_QWORD *)this + 4),
                   1i64,
                   &v23);
        if ( !result
          && (!v23
           || (result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**((_QWORD **)this + 4) + 32i64))(
                          *((_QWORD *)this + 4),
                          v23,
                          *((_QWORD *)this + 1) + 1617i64)) == 0) )
        {
          v13 = *((_QWORD *)this + 4);
          v20[0] = __ROR2__(2 * *((_WORD *)this + 80), 8);
          result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v13 + 32i64))(v13, 2i64, v20);
          if ( !result )
          {
            v14 = a3;
            if ( a3 >= &a3[*((unsigned __int16 *)this + 80)] )
            {
LABEL_20:
              v16 = *((_QWORD *)this + 4);
              v22 = 1;
              result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v16 + 32i64))(v16, 1i64, &v22);
              if ( !result )
              {
                v17 = *((_QWORD *)this + 4);
                v18[0] = 0;
                result = (*(__int64 (__fastcall **)(__int64, __int64, char *))(*(_QWORD *)v17 + 32i64))(v17, 1i64, v18);
                if ( !result )
                {
                  result = CTls13ClientHandshake::GenerateClientHelloExtensions(this);
                  if ( !result )
                    return (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 4) + 40i64))(*((_QWORD *)this + 4));
                }
              }
            }
            else
            {
              while ( 1 )
              {
                v15 = *((_QWORD *)this + 4);
                v21 = __ROR2__(*(_WORD *)v14, 8);
                result = (*(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v15 + 32i64))(
                           v15,
                           2i64,
                           &v21);
                if ( result )
                  break;
                if ( ++v14 >= &a3[*((unsigned __int16 *)this + 80)] )
                  goto LABEL_20;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180066AF0: using guessed type __int16 var_8[2];
// 180066AF0: using guessed type char var_10[4];
