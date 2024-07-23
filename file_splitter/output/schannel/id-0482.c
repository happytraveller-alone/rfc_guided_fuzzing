// File count: 482
// Total lines: 15
-----------------------------------------
void __fastcall FlushTimerCallbackUserMode(PTP_CALLBACK_INSTANCE Instance, __int64 Context, PTP_TIMER Timer)
{
  if ( *(_BYTE *)(Context + 356) )
  {
    *(_BYTE *)(Context + 356) = 0;
    LookUpTableFlushComplete(Context);
  }
  else
  {
    LookUpTableFlushPartial(Context);
  }
  if ( *(_DWORD *)(Context + 256) )
    EnableFlushTimer(*(struct _TP_TIMER **)(Context + 344), *(_DWORD *)(Context + 352));
}
