//----- (000000018002A118) ----------------------------------------------------
void __fastcall Init_thread_header(_DWORD *a1)
{
  EnterCriticalSection(&CriticalSection);
  while ( 1 )
  {
    if ( !*a1 )
    {
      *a1 = -1;
      goto LABEL_7;
    }
    if ( *a1 != -1 )
      break;
    Init_thread_wait(0x64u);
  }
  *(_DWORD *)(*((_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + (unsigned int)tls_index) + 4i64) = Init_global_epoch;
LABEL_7:
  LeaveCriticalSection(&CriticalSection);
}
// 180091990: using guessed type int Init_global_epoch;
// 1800920C8: using guessed type int tls_index;

