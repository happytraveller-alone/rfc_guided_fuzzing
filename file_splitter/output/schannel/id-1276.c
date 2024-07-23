// File count: 1276
// Total lines: 26
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::ComputeKeyShareExtensionSize(CTls13ClientHandshake *this)
{
  unsigned int v2; // ebx
  unsigned __int16 v4; // [rsp+38h] [rbp+10h] BYREF

  v4 = 0;
  v2 = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeKeyShareEntrySize((__int64)this, &v4);
  if ( v2 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 23i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids, v2);
    return v2;
  }
  else if ( v4 <= 0xFFFDu )
  {
    *((_WORD *)this + 26) = v4 + 2;
    return 0i64;
  }
  else
  {
    return 1359i64;
  }
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
