//----- (0000000180058A18) ----------------------------------------------------
unsigned __int8 __fastcall CSslCredManager::CheckForGpEventAndUpdateIssuersList(CSslCredManager *this)
{
  void *v2; // rcx
  _DWORD *i; // rax

  v2 = (void *)*((_QWORD *)this + 8);
  if ( !v2 || WaitForSingleObjectEx(v2, 0, 0) )
    return 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_d7209deee65a328fe195e0fa91b71573_Traceguids);
  RtlEnterCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
  for ( i = (_DWORD *)*((_QWORD *)this + 6); i != (_DWORD *)((char *)this + 48); i = *(_DWORD **)i )
    i[37] |= 0x10u;
  RtlLeaveCriticalSection((PRTL_CRITICAL_SECTION)((char *)this + 8));
  return 1;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

