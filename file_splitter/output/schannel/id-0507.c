// File count: 507
// Total lines: 17
-----------------------------------------
void __fastcall SslWatchParamKey(char *a1)
{
  __int64 v1; // rbx
  LSTATUS v2; // eax
  int v3; // ecx

  v1 = *((_QWORD *)a1 + 2);
  v2 = WatchParamKeyHelper(a1);
  v3 = 0;
  if ( !v2 )
  {
    LOBYTE(v3) = v1 == 0;
    SslReadRegOptions(v3);
    NotifyWNFConfigChangeEvent(WNF_SCH_REGISTRY_RELOAD);
  }
}
