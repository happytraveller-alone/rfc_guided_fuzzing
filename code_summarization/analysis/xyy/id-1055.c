//----- (0000000180058E30) ----------------------------------------------------
__int64 __fastcall CSslCredManager::NotifyProviderChange(CSslCredManager *this)
{
  struct _RTL_CRITICAL_SECTION *v1; // rsi
  _QWORD **v2; // rdi
  _QWORD *i; // rbx

  v1 = (struct _RTL_CRITICAL_SECTION *)((char *)this + 8);
  v2 = (_QWORD **)((char *)this + 48);
  RtlEnterCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
  for ( i = *v2; i != v2; i = (_QWORD *)*i )
    CCredentialGroup::NotifyProviderChange((CCredentialGroup *)(i - 1));
  RtlLeaveCriticalSection(v1);
  return 0i64;
}
