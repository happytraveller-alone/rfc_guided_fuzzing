// File count: 1373
// Total lines: 26
----------------------------------------
__int64 __fastcall CTls13ClientContext::GenerateTlsAlertMessage(
        CTls13ClientContext *this,
        struct SPBuffer *a2,
        char a3,
        char a4)
{
  bool v4; // al
  __int64 v5; // r10

  v4 = 0;
  if ( (*((_BYTE *)this + 32) & 4) != 0 )
  {
    v5 = *((_QWORD *)this + 1);
    if ( v5 )
      v4 = *(_DWORD *)(v5 + 28) != 0;
  }
  return CTls13Context::GenerateTlsAlertMessage(
           (CTls13ClientContext *)((char *)this + 1368),
           a3,
           a4,
           0,
           v4,
           (__int64 **)this,
           a2);
}
