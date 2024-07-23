// File count: 223
// Total lines: 77
-----------------------------------------
__int64 __fastcall PerformApplicationCallback(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        struct _SecBuffer *a4,
        struct _SecBuffer *a5,
        int a6,
        int a7,
        char a8)
{
  __int64 v8; // rax
  unsigned int v9; // ebx
  void *pvBuffer; // rcx

  v8 = LsaTable;
  if ( LsaTable )
  {
    if ( a7 )
    {
      v9 = (*(__int64 (__fastcall **)(__int64, __int64, __int64, struct _SecBuffer *, char))(LsaTable + 496))(
             a1,
             a2,
             a3,
             a4,
             a8);
      if ( (v9 & 0x80000000) != 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v9);
        CleanupAppModeInfo(0i64);
      }
      return v9;
    }
    if ( a5 )
    {
      a5->BufferType = 0;
      a5->pvBuffer = 0i64;
      a5->cbBuffer = 0;
      v9 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, struct _SecBuffer *, struct _SecBuffer *))(v8 + 280))(
             (unsigned int)a1,
             a2,
             a3,
             a4,
             a5);
      if ( (v9 & 0x80000000) != 0 )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids, v9);
        return v9;
      }
      pvBuffer = a5->pvBuffer;
      if ( pvBuffer && a5->cbBuffer )
      {
        if ( !a6 )
          v9 = -2146893052;
        if ( (v9 & 0x80000000) == 0 )
          return v9;
      }
      else
      {
        if ( !a6 )
          return v9;
        v9 = -2146893052;
      }
      if ( pvBuffer )
        SPExternalFree(pvBuffer);
      a5->BufferType = 0;
      a5->pvBuffer = 0i64;
      a5->cbBuffer = 0;
      return v9;
    }
  }
  return 2148074244i64;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
