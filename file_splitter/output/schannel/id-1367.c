// File count: 1367
// Total lines: 217
---------------------------------------
__int64 __fastcall CTls13ClientContext::GenerateHello(CTls13ClientContext *this, struct SPBuffer *a2)
{
  __int64 v4; // r15
  CCipherMill *v5; // rcx
  __int64 v6; // r10
  unsigned int OutputBuffer; // ebx
  __int16 *v8; // rsi
  __int64 v9; // rdx
  unsigned int v10; // r8d
  __int16 v11; // r14
  char v12; // al
  bool v13; // zf
  unsigned __int8 v14; // si
  unsigned int v15; // eax
  int v16; // r8d
  int v17; // edx
  CTls13ClientContext *v18; // rcx
  __int64 v19; // rax
  unsigned __int8 v20; // si
  unsigned __int16 *v21; // r13
  __int64 v22; // rcx
  unsigned int v23; // eax
  unsigned int v24; // edx
  HLOCAL Memory; // rax
  unsigned int ClientHello; // eax
  char v28[4]; // [rsp+50h] [rbp-B0h] BYREF
  unsigned int v29; // [rsp+54h] [rbp-ACh] BYREF
  unsigned int v30; // [rsp+58h] [rbp-A8h] BYREF
  unsigned __int16 *v31; // [rsp+60h] [rbp-A0h]
  unsigned __int64 AProvider; // [rsp+68h] [rbp-98h] BYREF
  __int16 v33[2]; // [rsp+70h] [rbp-90h] BYREF
  int v34; // [rsp+74h] [rbp-8Ch]
  int v35; // [rsp+78h] [rbp-88h]
  __int16 v36; // [rsp+7Ch] [rbp-84h]
  int v37; // [rsp+80h] [rbp-80h]
  int v38; // [rsp+84h] [rbp-7Ch]
  unsigned int v39[68]; // [rsp+90h] [rbp-70h] BYREF

  AProvider = CCipherMill::GetAProvider(this);
  v4 = AProvider;
  memset_0(v39, 0, sizeof(v39));
  v6 = *((_QWORD *)this + 10);
  v29 = 68;
  if ( !v6 )
  {
    OutputBuffer = 1359;
    goto LABEL_40;
  }
  OutputBuffer = CCipherMill::BuildCipherSuiteList(
                   (__int64)this + 912,
                   *(unsigned int **)(v6 + 184),
                   *(_DWORD *)(v6 + 176),
                   *(_DWORD *)(v6 + 192),
                   v6,
                   *((_DWORD *)this + 16),
                   (__int64)v39,
                   &v29,
                   (_QWORD *)this + 114,
                   (_WORD *)this + 460);
  if ( OutputBuffer )
    goto LABEL_40;
  v8 = (__int16 *)((char *)this + 474);
  CCipherMill::GetSignatureSuiteList(v5, (CTls13ClientContext *)((char *)this + 474));
  v9 = *((_QWORD *)this + 10);
  v10 = *(_DWORD *)(v9 + 196);
  if ( v10 )
  {
    OutputBuffer = CTlsSignatureSuiteList::Blacklist(
                     (CTls13ClientContext *)((char *)this + 474),
                     *(struct _TLS_PARAMETERS **)(v9 + 200),
                     v10);
    if ( OutputBuffer )
      goto LABEL_40;
    v11 = *v8;
    if ( !*v8 )
    {
      v5 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 26i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids);
      OutputBuffer = -2146893007;
      goto LABEL_40;
    }
  }
  else
  {
    v11 = *v8;
  }
  v31 = (unsigned __int16 *)((char *)this + 476);
  v12 = (*(__int64 (__fastcall **)(CTls13ClientContext *))(*(_QWORD *)this + 384i64))(this);
  v35 = 1;
  v38 = 1;
  v28[0] = 0;
  v13 = *((_DWORD *)this + 17) == 100;
  v14 = 0;
  *((_BYTE *)this + 1649) = v12 != 0 ? 0x20 : 0;
  v33[0] = 0;
  v34 = 22;
  v37 = 22;
  v36 = 0;
  if ( v13 )
  {
    v15 = CTls13Context::SetCcsRecordInfo(
            (CTls13ClientContext *)((char *)this + 1368),
            (struct CTlsRecord::CMessageInfo *)v33,
            v28);
    OutputBuffer = v15;
    if ( v15 )
    {
      v16 = v15;
LABEL_11:
      v17 = 50;
LABEL_12:
      v18 = this;
LABEL_13:
      CSslContext::SetError((__int64)v18, v17, v16);
      goto LABEL_40;
    }
    v14 = v28[0];
  }
  v19 = v14;
  v20 = v14 + 1;
  v21 = (unsigned __int16 *)&v33[6 * v19];
  OutputBuffer = CTls13ClientHandshake::ComputeClientHelloSize(
                   (CTls13ClientContext *)((char *)this + 1656),
                   v4,
                   v29,
                   v11,
                   v21);
  if ( OutputBuffer )
  {
    v16 = OutputBuffer;
    goto LABEL_11;
  }
  v22 = *((_QWORD *)this + 197);
  v30 = 0;
  v23 = (*(__int64 (__fastcall **)(__int64, _QWORD, __int16 *, unsigned int *))(*(_QWORD *)v22 + 16i64))(
          v22,
          v20,
          v33,
          &v30);
  OutputBuffer = v23;
  v18 = this;
  if ( v23 )
  {
    v16 = v23;
    v17 = 51;
    goto LABEL_13;
  }
  OutputBuffer = CSsl3TlsContext::AllocateOutputBuffer(this, a2, v30);
  if ( OutputBuffer )
    goto LABEL_20;
  OutputBuffer = (*(__int64 (__fastcall **)(_QWORD, struct SPBuffer *))(**((_QWORD **)this + 197) + 24i64))(
                   *((_QWORD *)this + 197),
                   a2);
  if ( OutputBuffer )
    goto LABEL_20;
  if ( *((_QWORD *)this + 110) )
  {
    (*(void (__fastcall **)(CTls13ClientContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 110) = 0i64;
  }
  v13 = *((_DWORD *)this + 17) == 40;
  *((_DWORD *)this + 218) = 0;
  if ( !v13 )
  {
    OutputBuffer = CTls13Context::GenerateCcsRecord((CTls13ClientContext *)((char *)this + 1368));
    if ( OutputBuffer )
      goto LABEL_20;
LABEL_32:
    if ( this == (CTls13ClientContext *)-272i64 )
    {
      OutputBuffer = 1359;
      goto LABEL_20;
    }
    ClientHello = CTls13ClientHandshake::GenerateClientHello(
                    (CTls13ClientContext *)((char *)this + 1656),
                    v29,
                    v39,
                    v11,
                    v31,
                    (PUCHAR)this + 272);
    OutputBuffer = ClientHello;
    if ( ClientHello )
    {
      v16 = ClientHello;
      goto LABEL_21;
    }
    goto LABEL_40;
  }
  v24 = *v21;
  *((_DWORD *)this + 218) = v24;
  Memory = CSslContext::GetMemory(this, v24);
  *((_QWORD *)this + 110) = Memory;
  if ( !Memory )
  {
    OutputBuffer = 14;
LABEL_20:
    v16 = OutputBuffer;
LABEL_21:
    v17 = 52;
    goto LABEL_12;
  }
  if ( !*((_BYTE *)this + 1649) )
    goto LABEL_32;
  OutputBuffer = GenerateRandomBits((PUCHAR)this + 1617, *((unsigned __int8 *)this + 1649));
  if ( !OutputBuffer )
    goto LABEL_32;
LABEL_40:
  if ( v4 )
    CCipherMill::DeferenceProvider(v5, &AProvider);
  return OutputBuffer;
}
// 18006C6B4: variable 'v5' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 18006C5E0: using guessed type char var_190[4];
