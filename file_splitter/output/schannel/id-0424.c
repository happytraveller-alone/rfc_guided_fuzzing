//----- (0000000180018EB4) ----------------------------------------------------
CEphemKeyData *__fastcall CEphemKeyData::CEphemKeyData(CEphemKeyData *this, unsigned int a2)
{
  __int64 v3; // rbx
  struct _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h] BYREF

  *((_DWORD *)this + 7) = 1;
  *(_QWORD *)this = &CEphemKeyData::`vftable';
  v3 = a2;
  *((_QWORD *)this + 1) = 0i64;
  *((_QWORD *)this + 2) = 0i64;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 10) = 0;
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  *((_QWORD *)this + 4) = v3 + *(_QWORD *)&SystemTimeAsFileTime;
  return this;
}
// 18007C270: using guessed type void *CEphemKeyData::`vftable';

