// File count: 583
// Total lines: 12
-----------------------------------------
void __cdecl RTC_Terminate()
{
  void (**i)(void); // rbx

  for ( i = &_rtc_tzz; i < &_rtc_tzz; ++i )
  {
    if ( *i )
      (*i)();
  }
}
// 1800871B0: using guessed type void (*_rtc_tzz)(void);
