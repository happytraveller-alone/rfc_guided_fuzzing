// File count: 422
// Total lines: 9
------------------------------------------
bool __fastcall CEphemKeyData::Reference(const FILETIME *this)
{
  struct _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  _InterlockedIncrement((volatile signed __int32 *)&this[3].dwHighDateTime);
  return CompareFileTime(&SystemTimeAsFileTime, this + 4) < 0;
}
