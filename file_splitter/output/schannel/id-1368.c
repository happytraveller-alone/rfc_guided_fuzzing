//----- (000000018006C9C4) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::GenerateHelloRetryRequest(CTls13ServerContext *this, struct SPBuffer *a2)
{
  __int64 *v2; // rax
  __int64 v5; // rdx
  CTls13ServerHandshake *v6; // r15
  unsigned int OutputBuffer; // edi
  int v8; // edx
  CTls13ServerContext *v9; // rcx
  __int64 result; // rax
  __int64 v11; // rcx
  CTls13Context *v12; // rcx
  __int64 v13; // rax
  unsigned int v14; // r8d
  __int64 v15; // rdx
  char v16[4]; // [rsp+30h] [rbp-30h] BYREF
  unsigned int v17; // [rsp+34h] [rbp-2Ch] BYREF
  unsigned __int16 v18[2]; // [rsp+38h] [rbp-28h] BYREF
  int v19; // [rsp+3Ch] [rbp-24h]
  int v20; // [rsp+40h] [rbp-20h]
  __int16 v21; // [rsp+44h] [rbp-1Ch] BYREF
  int v22; // [rsp+48h] [rbp-18h]
  int v23; // [rsp+4Ch] [rbp-14h]

  v2 = (__int64 *)*((_QWORD *)this + 1);
  if ( v2 )
    v5 = *v2;
  else
    v5 = 0i64;
  v18[0] = 0;
  v6 = (CTls13ServerContext *)((char *)this + 1288);
  v19 = 22;
  v20 = 1;
  v21 = 0;
  v22 = 22;
  v23 = 1;
  v16[0] = 1;
  OutputBuffer = CTls13ServerHandshake::ComputeServerHelloOrHRRSize(
                   (CTls13ServerContext *)((char *)this + 1288),
                   v5,
                   0,
                   v18);
  if ( OutputBuffer
    || (OutputBuffer = CTls13Context::SetCcsRecordInfo(
                         (CTls13ServerContext *)((char *)this + 1000),
                         (struct CTlsRecord::CMessageInfo *)&v21,
                         v16)) != 0 )
  {
    v8 = 1256;
LABEL_6:
    v9 = this;
LABEL_7:
    CSslContext::SetError((__int64)v9, v8, OutputBuffer);
    return OutputBuffer;
  }
  v11 = *((_QWORD *)this + 151);
  v17 = 0;
  OutputBuffer = (*(__int64 (__fastcall **)(__int64, _QWORD, unsigned __int16 *, unsigned int *))(*(_QWORD *)v11 + 16i64))(
                   v11,
                   (unsigned __int8)v16[0],
                   v18,
                   &v17);
  v9 = this;
  if ( OutputBuffer )
  {
    v8 = 1257;
    goto LABEL_7;
  }
  OutputBuffer = CSsl3TlsContext::AllocateOutputBuffer(this, a2, v17);
  if ( OutputBuffer
    || (OutputBuffer = (*(__int64 (__fastcall **)(_QWORD, struct SPBuffer *))(**((_QWORD **)this + 151) + 24i64))(
                         *((_QWORD *)this + 151),
                         a2)) != 0 )
  {
LABEL_12:
    v8 = 1258;
    goto LABEL_6;
  }
  if ( (*((_BYTE *)this + 32) & 1) != 0 )
  {
    v13 = *((_QWORD *)this + 1);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 28);
LABEL_18:
      v15 = *(_QWORD *)v13;
      goto LABEL_20;
    }
  }
  v13 = *((_QWORD *)this + 1);
  v14 = 0;
  if ( v13 )
    goto LABEL_18;
  v15 = 0i64;
LABEL_20:
  OutputBuffer = CTls13Context::GenerateClientHelloHash(
                   v12,
                   v15,
                   v14,
                   *((unsigned __int8 **)this + 110),
                   (unsigned int *)this + 218);
  v9 = this;
  if ( OutputBuffer )
  {
    v8 = 1012;
    goto LABEL_7;
  }
  OutputBuffer = CSsl3TlsServerContext::InitUpdateClientHash(this);
  if ( OutputBuffer )
  {
    v8 = 1012;
    goto LABEL_6;
  }
  OutputBuffer = CTls13ServerHandshake::GenerateServerHelloOrHRR(v6, 0, 0i64);
  if ( OutputBuffer )
    goto LABEL_12;
  result = CTls13Context::GenerateCcsRecord((CTls13ServerContext *)((char *)this + 1000));
  OutputBuffer = result;
  if ( (_DWORD)result )
    goto LABEL_12;
  return result;
}
// 18006CB39: variable 'v12' is possibly undefined
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 18006C9C4: using guessed type char var_30[4];

