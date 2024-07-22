//----- (0000000180027890) ----------------------------------------------------
unsigned __int8 __fastcall CSslCredManager::InitCredentialManager(CSslCredManager *this)
{
  HANDLE EventA; // rax
  HCERTSTORE v3; // rax
  HANDLE v4; // rax

  if ( RtlInitializeCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8)) < 0 )
    return 0;
  *((_QWORD *)this + 7) = (char *)this + 48;
  *((_QWORD *)this + 6) = (char *)this + 48;
  EventA = CreateEventA(0i64, 0, 0, 0i64);
  *((_QWORD *)this + 8) = EventA;
  if ( EventA )
    RegisterGPNotification(EventA, 1);
  v3 = CertOpenStore((LPCSTR)0xA, 1u, 0i64, 0x20020000u, L"MY");
  *((_QWORD *)this + 9) = v3;
  if ( v3 )
  {
    v4 = CreateEventA(0i64, 0, 0, 0i64);
    *((_QWORD *)this + 10) = v4;
    if ( v4 )
      CertControlStore(*((HCERTSTORE *)this + 9), 0, 2u, (char *)this + 80);
  }
  return 1;
}
// 18008275C: using guessed type wchar_t aMy[3];

