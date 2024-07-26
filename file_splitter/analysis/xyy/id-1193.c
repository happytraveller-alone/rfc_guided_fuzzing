//----- (000000018005E6D0) ----------------------------------------------------
CSslCredential *__fastcall CSslCredential::CSslCredential(CSslCredential *this)
{
  char v2; // r9
  char v3; // r8
  char v4; // dl

  CSslBasicAllocator::CSslBasicAllocator(this);
  *(_QWORD *)this = &CSslCredential::`vftable';
  *((_BYTE *)this + 77) = v2;
  *((_BYTE *)this + 78) = v3;
  *((_BYTE *)this + 79) = v4;
  *((_BYTE *)this + 80) = 0;
  *((_DWORD *)this + 31) = 1;
  *((_DWORD *)this + 32) = 1;
  *(_OWORD *)((char *)this + 514) = 0i64;
  *(_OWORD *)((char *)this + 530) = 0i64;
  *((_WORD *)this + 256) = 0;
  *((_WORD *)this + 273) = 0;
  *(_QWORD *)((char *)this + 652) = 0i64;
  memset_0((char *)this + 660, 0, 0x204ui64);
  RtlInitializeResource((PRTL_RESOURCE)((char *)this + 552));
  *((_BYTE *)this + 648) = 1;
  *((_QWORD *)this + 61) = (char *)this + 480;
  *((_QWORD *)this + 60) = (char *)this + 480;
  return this;
}
// 18005E6EC: variable 'v2' is possibly undefined
// 18005E6F0: variable 'v3' is possibly undefined
// 18005E6F4: variable 'v4' is possibly undefined
// 18007FD20: using guessed type void *CSslCredential::`vftable';

