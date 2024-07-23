// File count: 962
// Total lines: 50
-----------------------------------------
__int64 __fastcall SpImportSecurityContext(struct _SecBuffer *a1, void *a2, _QWORD *a3)
{
  CCipherMill *v6; // rcx
  __int64 result; // rax
  signed __int32 v8; // eax
  __int64 v9; // rbx
  int v10; // [rsp+20h] [rbp-18h]

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 37i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  if ( (unsigned int)SchannelInit(1) )
  {
    do
    {
      v8 = _InterlockedIncrement((volatile signed __int32 *)&ExportedContext);
      v9 = v8;
    }
    while ( (v8 & 7) == 0 );
    result = SslAddUserContext(v8, a2, a1, 1);
    if ( (int)result >= 0 )
      *a3 = v9;
  }
  else
  {
    v6 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 38i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
        v6 = WPP_GLOBAL_Control;
      }
      if ( v6 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v6 + 28) & 5) != 0 )
      {
        v10 = -2146893052;
        WPP_SF_DD(
          *((_QWORD *)v6 + 2),
          0x27u,
          (__int64)&WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids,
          -2146893052,
          v10);
      }
    }
    return 2148074244i64;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180092F50: using guessed type unsigned __int64 ExportedContext;
