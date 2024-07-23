// File count: 322
// Total lines: 23
-----------------------------------------
__int64 WppCleanupUm()
{
  CCipherMill *v0; // rbx
  __int64 result; // rax

  v0 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    while ( v0 )
    {
      if ( *((_QWORD *)v0 + 1) )
      {
        result = EtwUnregisterTraceGuids();
        *((_QWORD *)v0 + 1) = 0i64;
      }
      v0 = *(CCipherMill **)v0;
    }
    WPP_GLOBAL_Control = (CCipherMill *)&WPP_GLOBAL_Control;
  }
  return result;
}
// 180080E08: using guessed type __int64 EtwUnregisterTraceGuids(void);
