//----- (0000000180006B10) ----------------------------------------------------
CSchannelTelemetryContext *__fastcall CSchannelTelemetryContext::`vector deleting destructor'(
        CSchannelTelemetryContext *this,
        char a2)
{
  *(_QWORD *)this = &IAllocate::`vftable';
  if ( (a2 & 1) != 0 )
  {
    if ( LsaTable )
      (*(void (**)(void))(LsaTable + 48))();
    else
      LocalFree(this);
  }
  return this;
}
// 18007C298: using guessed type void *IAllocate::`vftable';
// 180092620: using guessed type __int64 LsaTable;

