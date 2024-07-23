// File count: 1442
// Total lines: 59
----------------------------------------
__int64 __fastcall DTlsMessage::addFragment(
        DTlsMessage *this,
        unsigned int a2,
        const unsigned __int16 *a3,
        void *const a4,
        unsigned int a5,
        unsigned int Size)
{
  unsigned int v6; // ebx
  unsigned int v11; // esi
  __int64 v12; // r15
  char v13; // cl
  unsigned __int64 v14; // r9
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-28h] BYREF

  v6 = 0;
  if ( a4 && (v11 = a5, a5 + Size <= *((_DWORD *)this + 4)) )
  {
    if ( Size && !*((_DWORD *)this + 7) )
    {
      if ( DTlsMessage::checkOverlapp(this, a5, a5 + Size - 1) )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_DD(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0xAu,
            (__int64)&WPP_7c40084571853895c7781ddf48bb701c_Traceguids,
            a5,
            Size);
        if ( (g_dwEventLogging & 4) != 0 )
        {
          RtlInitUnicodeString(&DestinationString, a3);
          SchEventWrite(&SSLEVENT_DTLS_DUPLICATE_RECORD, L"du", a2, &DestinationString);
        }
      }
      else
      {
        v12 = Size;
        memcpy_0((void *)(*((_QWORD *)this + 6) + a5), a4, Size);
        do
        {
          v13 = v11 & 7;
          v14 = (unsigned __int64)v11++ >> 3;
          *(_BYTE *)(v14 + *((_QWORD *)this + 7)) |= 1 << (7 - v13);
          --v12;
        }
        while ( v12 );
        *((_DWORD *)this + 7) = DTlsMessage::checkComplete(this);
      }
    }
  }
  else
  {
    return 87;
  }
  return v6;
}
// 18007375B: conditional instruction was optimized away because ebp.4!=0
