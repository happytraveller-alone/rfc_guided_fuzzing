// File count: 1374
// Total lines: 88
----------------------------------------
__int64 __fastcall CTls13Context::GenerateTlsAlertMessage(
        CTls13Context *this,
        char a2,
        char a3,
        char a4,
        char a5,
        __int64 **a6,
        struct SPBuffer *a7)
{
  __int64 result; // rax
  __int64 *v10; // rax
  __int64 v11; // rdx
  int v12; // eax
  unsigned int v13; // edi
  char v14[8]; // [rsp+40h] [rbp-30h] BYREF
  char v15[8]; // [rsp+48h] [rbp-28h] BYREF
  unsigned int v16; // [rsp+50h] [rbp-20h] BYREF
  __int16 v17[2]; // [rsp+58h] [rbp-18h] BYREF
  int v18; // [rsp+5Ch] [rbp-14h]
  int v19; // [rsp+60h] [rbp-10h]

  v14[0] = a2;
  v15[0] = a3;
  if ( !a6 || !a7 )
    return 2148074333i64;
  v17[0] = 2;
  v18 = 21;
  v16 = 0;
  v19 = a5 != 0 ? 2 : 0;
  result = (*(__int64 (__fastcall **)(_QWORD, __int64, __int16 *, unsigned int *))(**((_QWORD **)this + 26) + 16i64))(
             *((_QWORD *)this + 26),
             1i64,
             v17,
             &v16);
  if ( !(_DWORD)result )
  {
    result = CSsl3TlsContext::AllocateOutputBuffer((CSsl3TlsContext *)a6, a7, v16);
    if ( !(_DWORD)result )
    {
      result = (*(__int64 (__fastcall **)(_QWORD, struct SPBuffer *))(**((_QWORD **)this + 26) + 24i64))(
                 *((_QWORD *)this + 26),
                 a7);
      if ( !(_DWORD)result )
      {
        result = (*(__int64 (__fastcall **)(_QWORD, __int64, char *))(**((_QWORD **)this + 26) + 32i64))(
                   *((_QWORD *)this + 26),
                   1i64,
                   v14);
        if ( !(_DWORD)result )
        {
          result = (*(__int64 (__fastcall **)(_QWORD, __int64, char *))(**((_QWORD **)this + 26) + 32i64))(
                     *((_QWORD *)this + 26),
                     1i64,
                     v15);
          if ( !(_DWORD)result )
          {
            if ( !*((_BYTE *)this + 201)
              && a5
              && ((v10 = a6[1]) == 0i64 ? (v11 = 0i64) : (v11 = *v10),
                  v12 = CTls13Context::PopulateSecTrafficSecret(
                          (__int64)this,
                          v11,
                          a4,
                          *((_BYTE *)this + 216),
                          (__int64)v10,
                          0,
                          *((_WORD *)a7 + 2)),
                  (v13 = v12) != 0) )
            {
              CSslContext::SetError((__int64)a6, 609, v12);
              return v13;
            }
            else
            {
              return (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 26) + 40i64))(*((_QWORD *)this + 26));
            }
          }
        }
      }
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 18006D3B0: using guessed type char var_30[8];
// 18006D3B0: using guessed type char var_28[8];
// 18006D3B0: using guessed type __int16 var_18[2];
