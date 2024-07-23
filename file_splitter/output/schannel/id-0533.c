// File count: 533
// Total lines: 39
-----------------------------------------
__int64 __fastcall TraceLoggingRegisterEx_EventRegister_EventSetInformation(
        ULONGLONG *CallbackContext,
        ULONGLONG a2,
        ULONGLONG a3)
{
  ULONGLONG *v3; // rsi
  bool v4; // zf
  signed int v6; // eax
  unsigned int v7; // ebx
  GUID ProviderId; // [rsp+20h] [rbp-28h] BYREF

  v3 = CallbackContext + 4;
  v4 = CallbackContext[4] == 0;
  ProviderId = *(GUID *)(CallbackContext[1] - 16);
  if ( !v4 )
    __fastfail(5u);
  CallbackContext[5] = a2;
  CallbackContext[6] = a3;
  v6 = EventRegister(&ProviderId, (PENABLECALLBACK)tlgEnableCallback, CallbackContext, v3);
  v7 = v6;
  if ( v6 )
  {
    if ( v6 > 0 )
      return (unsigned __int16)v6 | 0x80070000;
  }
  else
  {
    EventSetInformation(
      *v3,
      2i64,
      CallbackContext[1],
      *(unsigned __int16 *)CallbackContext[1],
      *(_QWORD *)&ProviderId.Data1,
      *(_QWORD *)ProviderId.Data4);
  }
  return v7;
}
// 180080D68: using guessed type __int64 __fastcall EventSetInformation(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD);
