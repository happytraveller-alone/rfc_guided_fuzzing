//----- (00000001800289CC) ----------------------------------------------------
void __cdecl RTC_Initialize()
{
  void (**i)(void); // rbx

  for ( i = &_rtc_izz; i < &_rtc_izz; ++i )
  {
    if ( *i )
      (*i)();
  }
}
// 1800871A0: using guessed type void (*_rtc_izz)(void);

