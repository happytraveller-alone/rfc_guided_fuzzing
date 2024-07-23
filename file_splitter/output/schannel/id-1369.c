// File count: 1369
// Total lines: 74
----------------------------------------
__int64 __fastcall CTls13ServerContext::GenerateNewSessionTicket(CTls13ServerContext *this, struct SPBuffer *a2)
{
  CTls13ServerHandshake *v2; // rbp
  unsigned int OutputBuffer; // edi
  int v6; // edx
  CTls13ServerContext *v7; // rcx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  __int64 v11; // rdx
  unsigned int v12; // [rsp+40h] [rbp-38h] BYREF
  unsigned __int16 v13[2]; // [rsp+48h] [rbp-30h] BYREF
  int v14; // [rsp+4Ch] [rbp-2Ch]
  int v15; // [rsp+50h] [rbp-28h]

  v2 = (CTls13ServerContext *)((char *)this + 1288);
  v13[0] = 0;
  v14 = 22;
  v15 = 2;
  OutputBuffer = CTls13ServerHandshake::ComputeNewSessionTicketSize((CTls13ServerContext *)((char *)this + 1288), v13);
  if ( OutputBuffer )
  {
    v6 = 1500;
LABEL_3:
    v7 = this;
LABEL_4:
    CSslContext::SetError((__int64)v7, v6, OutputBuffer);
    return OutputBuffer;
  }
  v9 = *((_QWORD *)this + 151);
  v12 = 0;
  OutputBuffer = (*(__int64 (__fastcall **)(__int64, __int64, unsigned __int16 *, unsigned int *))(*(_QWORD *)v9 + 16i64))(
                   v9,
                   1i64,
                   v13,
                   &v12);
  v7 = this;
  if ( OutputBuffer )
  {
    v6 = 1501;
    goto LABEL_4;
  }
  OutputBuffer = CSsl3TlsContext::AllocateOutputBuffer(this, a2, v12);
  if ( OutputBuffer
    || (OutputBuffer = (*(__int64 (__fastcall **)(_QWORD, struct SPBuffer *))(**((_QWORD **)this + 151) + 24i64))(
                         *((_QWORD *)this + 151),
                         a2)) != 0
    || (OutputBuffer = CTls13ServerHandshake::GenerateNewSessionTicket(v2)) != 0 )
  {
    v6 = 1502;
    goto LABEL_3;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(CTls13ServerContext *))(*(_QWORD *)this + 384i64))(this) )
  {
    v10 = (_QWORD *)*((_QWORD *)this + 1);
    v11 = v10 ? *v10 : 0i64;
    OutputBuffer = CTls13Context::PopulateSecTrafficSecret(
                     (__int64)this + 1000,
                     v11,
                     1,
                     3u,
                     (__int64)v10,
                     0,
                     *((_WORD *)a2 + 2));
    if ( OutputBuffer )
    {
      v6 = 612;
      goto LABEL_3;
    }
  }
  return 0i64;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 18006CBC0: using guessed type unsigned __int16 var_30[2];
