//----- (0000000180019060) ----------------------------------------------------
__int64 __fastcall CSsl3TlsServerContext::AllocateAndGenerateNstCcsAndFinish(
        CSsl3TlsServerContext *this,
        struct SPBuffer *a2)
{
  char v2; // r10
  unsigned int v5; // edi
  unsigned __int8 *v6; // rbp
  unsigned __int16 v7; // r12
  unsigned int v8; // r14d
  int v9; // r13d
  __int16 v10; // r9
  int v11; // r8d
  unsigned int v12; // ecx
  unsigned int v13; // r8d
  int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // r9d
  _BYTE *v18; // r15
  unsigned int v19; // eax
  unsigned int CcsAndFinishMessage; // edi
  int v22; // edi
  unsigned int v23; // edi
  bool v24; // zf
  unsigned int v25; // edi
  unsigned int v26; // ecx
  _BYTE *Memory; // rax
  unsigned int v28; // r12d
  __int16 v29; // cx
  unsigned __int16 v30; // [rsp+70h] [rbp+8h] BYREF
  unsigned int v31; // [rsp+80h] [rbp+18h] BYREF
  unsigned __int8 *v32; // [rsp+88h] [rbp+20h] BYREF

  v2 = *((_BYTE *)this + 233);
  v5 = 0;
  v6 = 0i64;
  v7 = 0;
  v31 = 0;
  v32 = 0i64;
  v30 = 0;
  if ( v2 )
  {
    v8 = 13;
    goto LABEL_3;
  }
  v8 = 5;
  if ( (*((_BYTE *)this + 32) & 4) == 0 )
  {
LABEL_3:
    v9 = 0;
    goto LABEL_4;
  }
  v9 = *((_DWORD *)this + 11);
LABEL_4:
  if ( (*((_DWORD *)this + 34) & 0x400000) != 0 )
  {
    CcsAndFinishMessage = CSsl3TlsServerContext::SerializeAndProtectSessionState(this, (HLOCAL *)&v32, &v30);
    if ( CcsAndFinishMessage )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          53i64,
          &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids,
          CcsAndFinishMessage);
      v6 = v32;
      goto LABEL_22;
    }
    v2 = *((_BYTE *)this + 233);
    v22 = 18;
    v7 = v30;
    if ( !v2 )
      v22 = 10;
    v23 = v30 + v22;
    v24 = (*((_BYTE *)this + 32) & 4) == 0;
    v31 = v23;
    if ( !v24 )
    {
      v25 = *((_DWORD *)this + 12) + v23;
      v26 = *((_DWORD *)this + 13);
      if ( v26 )
      {
        if ( (*((_BYTE *)this + 56) & 1) != 0 )
          v26 -= v25 % v26;
        v25 += v26;
      }
      v23 = *((_DWORD *)this + 11) + v25;
    }
    v5 = *((_DWORD *)this + 15) + v23;
    v6 = v32;
  }
  v10 = *((_WORD *)this + 16);
  v11 = 1;
  if ( (v10 & 4) != 0 )
  {
    v12 = *((_DWORD *)this + 13);
    v13 = *((_DWORD *)this + 12) + 1;
    if ( v12 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v12 -= v13 % v12;
      v13 += v12;
    }
    v11 = *((_DWORD *)this + 11) + v13;
  }
  if ( (*((_BYTE *)this + 64) & 0x30) != 0 )
  {
    v14 = 48;
    v15 = 40;
  }
  else
  {
    v14 = 24;
    v15 = 16;
  }
  if ( !v2 )
    v14 = v15;
  if ( (v10 & 1) != 0 )
  {
    v16 = *((_DWORD *)this + 12) + v14;
    v17 = *((_DWORD *)this + 13);
    if ( v17 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v17 -= v16 % v17;
      v16 += v17;
    }
    v14 = *((_DWORD *)this + 11) + v16;
  }
  v18 = (_BYTE *)*((_QWORD *)a2 + 1);
  v19 = v5 + v14 + v11 + 2 * *((_DWORD *)this + 15);
  if ( v18 )
  {
    if ( *(_DWORD *)a2 < v19 )
    {
      *((_DWORD *)a2 + 1) = v19;
      CcsAndFinishMessage = -2146893023;
      goto LABEL_22;
    }
  }
  else
  {
    *(_DWORD *)a2 = v19;
    Memory = CSslContext::GetMemory(this, v19);
    *((_QWORD *)a2 + 1) = Memory;
    v18 = Memory;
    if ( !Memory )
    {
      CcsAndFinishMessage = 14;
      goto LABEL_22;
    }
  }
  *((_DWORD *)a2 + 1) = 0;
  if ( (*((_DWORD *)this + 34) & 0x400000) == 0 )
  {
LABEL_21:
    CcsAndFinishMessage = CSsl3TlsContext::GenerateCcsAndFinishMessage(this, a2);
    goto LABEL_22;
  }
  CSsl3TlsServerContext::GenerateNewSessionTicket(this, v6, v7, &v18[v8 + v9], &v31);
  v28 = v31;
  CcsAndFinishMessage = CSsl3TlsServerContext::UpdateHashAndWrapMessage(
                          this,
                          (__int64)&v18[v8 + v9],
                          v31,
                          (__int64)a2,
                          1011,
                          964);
  if ( !CcsAndFinishMessage )
  {
    if ( *((_BYTE *)this + 233) )
    {
      *((_DWORD *)a2 + 1) += v8 + v28;
      v29 = *((_WORD *)this + 17);
      v18[12] = v28;
      v18[11] = BYTE1(v28);
      v18[1] = HIBYTE(v29);
      v18[2] = v29;
      *v18 = 22;
    }
    goto LABEL_21;
  }
LABEL_22:
  if ( v6 )
    LocalFree(v6);
  return CcsAndFinishMessage;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

