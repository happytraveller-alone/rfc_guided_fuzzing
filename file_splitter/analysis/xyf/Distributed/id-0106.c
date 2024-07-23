//----- (0000000180008948) ----------------------------------------------------
__int64 __fastcall CSslContext::SetCipherState(CSslContext *this, struct CCipherSuiteInfo *a2)
{
  unsigned int v4; // ebp
  __int64 v5; // rax
  __int64 v6; // rsi
  CSslCredential *v7; // r14
  CSslServerKey *v8; // rcx
  int v9; // eax
  __int64 result; // rax
  __int64 v11; // rcx
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE Source1[20]; // [rsp+40h] [rbp-38h] BYREF

  v4 = 0;
  v5 = (*(__int64 (__fastcall **)(CSslContext *))(*(_QWORD *)this + 248i64))(this);
  v6 = *((_QWORD *)this + 1);
  v7 = (CSslCredential *)v5;
  if ( v6 )
  {
    v11 = *(_QWORD *)(v6 + 848);
    if ( v11 )
      CMasterEccCurveInfo::Dereference(*(CMasterEccCurveInfo **)(v11 + 16));
    CMasterCipherInfo::Dereference(*(CMasterCipherInfo **)(v6 + 856));
  }
  v8 = (CSslServerKey *)*((_QWORD *)this + 3);
  if ( v8 )
  {
    CSslServerKey::Dereference(v8);
    *((_QWORD *)this + 3) = 0i64;
  }
  if ( v7 )
    CSslCredential::GetProviderSpecificMasterKey(v7, *(_QWORD *)a2, (struct CSslServerKey **)this + 3);
  if ( (*((_DWORD *)this + 16) & 0xF3F00) != 0 )
  {
    v4 = SslLookupCipherLengths(
           *(_QWORD *)a2,
           *((unsigned __int16 *)this + 17),
           *((unsigned int *)a2 + 7),
           *((unsigned int *)this + 4),
           Source1,
           20,
           0);
    if ( v4 )
      goto LABEL_10;
  }
  else
  {
    *(_QWORD *)&Source1[12] = 0i64;
    v12 = *((_DWORD *)a2 + 3);
    v13 = *((_DWORD *)a2 + 4);
    *(_QWORD *)Source1 = 20i64;
    *(_DWORD *)&Source1[8] = v13;
    if ( v12 > 1 )
    {
      *(_DWORD *)&Source1[16] |= 1u;
      *(_DWORD *)&Source1[12] = v12;
    }
  }
  if ( (*((_BYTE *)this + 32) & 1) == 0 || RtlCompareMemory(Source1, (char *)this + 40, 0x14ui64) == 20 )
  {
    v9 = *(_DWORD *)&Source1[16];
    *(_OWORD *)((char *)this + 40) = *(_OWORD *)Source1;
    *((_DWORD *)this + 14) = v9;
  }
  else
  {
    v4 = -2146893007;
  }
LABEL_10:
  *((_WORD *)this + 16) |= 1u;
  result = v4;
  *((_QWORD *)this + 1) = a2;
  return result;
}
// 1800984F0: using guessed type __int64 __fastcall SslLookupCipherLengths(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);

