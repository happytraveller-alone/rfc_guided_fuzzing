// File count: 1403
// Total lines: 57
----------------------------------------
__int64 __fastcall CSsl3TlsContext::DtlsProcessRecord(__int64 a1, int a2, unsigned __int8 *a3, unsigned int a4)
{
  int v7; // edx
  unsigned int v8; // edi
  unsigned int v9; // r8d
  int v11; // eax
  unsigned __int8 v12; // [rsp+38h] [rbp+10h] BYREF

  v7 = a2 - 21;
  if ( v7 )
  {
    if ( v7 == 1 )
    {
      if ( a4 < 0xC )
        return 2148074248i64;
      v9 = a3[3] + (a3[1] << 16) + (a3[2] << 8);
      if ( (unsigned __int64)v9 + 12 > a4 )
        return 2148074248i64;
      return (unsigned int)CSsl3TlsContext::ProcessHandshakeCommon((CSsl3TlsContext *)a1, a3, v9 + 12);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 56i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    v11 = TlsParseAlertMessage(a3, a4, (unsigned __int8 *)(a1 + 473), &v12);
    v8 = v11;
    if ( v11 )
    {
      if ( *(_DWORD *)(a1 + 36) >= 0x302u && (*(_DWORD *)(a1 + 64) & 0x800A00AA) != 0 )
      {
        CSslContext::SetError(a1, 14, v11);
        return (unsigned int)-2146893018;
      }
      else if ( a4 == 2 )
      {
        LogReceiveAlertEvent(
          *(_DWORD *)(*(_QWORD *)(a1 + 80) + 212i64),
          (const unsigned __int16 *)(*(_QWORD *)(a1 + 80) + 216i64),
          *a3,
          a3[1]);
      }
    }
    else if ( v12 )
    {
      *(_BYTE *)(a1 + 552) = 1;
      *(_DWORD *)(a1 + 68) = 75;
    }
  }
  return v8;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
