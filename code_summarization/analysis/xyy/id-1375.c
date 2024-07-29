//----- (000000018006D5A0) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::GenerateTlsAlertMessage(
        CTls13ServerContext *this,
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
           (CTls13ServerContext *)((char *)this + 1000),
           a3,
           a4,
           1,
           v4,
           (__int64 **)this,
           a2);
}

