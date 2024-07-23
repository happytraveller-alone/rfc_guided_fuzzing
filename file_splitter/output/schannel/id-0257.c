// File count: 257
// Total lines: 43
-----------------------------------------
__int64 __fastcall CSsl3TlsContext::ProcessHandshakeCommon(CSsl3TlsContext *this, unsigned __int8 *a2, unsigned int a3)
{
  unsigned int v6; // edi
  unsigned int v7; // eax
  int v9; // [rsp+40h] [rbp+8h] BYREF

  v9 = 0;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_DDD(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0x3Au,
      (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
      *((_DWORD *)this + 16),
      *a2,
      *((_DWORD *)this + 17));
  v6 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, unsigned __int8 *, _QWORD, int *))(*(_QWORD *)this + 416i64))(
         this,
         a2,
         a3,
         &v9);
  if ( (!v6 || v6 == 590624) && !v9 && !*((_DWORD *)this + 218) )
  {
    v7 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, unsigned __int8 *, _QWORD, _QWORD))(*(_QWORD *)this + 504i64))(
           this,
           a2,
           a3,
           0i64);
    if ( v7 )
      v6 = v7;
  }
  if ( *((_BYTE *)this + 923) )
  {
    v6 = 590610;
    *((_DWORD *)this + 18) = *((_DWORD *)this + 17);
    *((_DWORD *)this + 17) = 77;
  }
  else if ( v6 == 590624 )
  {
    *((_BYTE *)this + 924) = 1;
  }
  return v6;
}
