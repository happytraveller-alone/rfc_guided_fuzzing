// File count: 1279
// Total lines: 50
----------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeServerHelloExtensionsSize(CTls13ServerHandshake *this)
{
  unsigned int v2; // ebx
  __int64 result; // rax
  int v4; // eax
  int v5; // ebx
  __int64 v6; // rcx
  unsigned __int16 v7; // r8
  unsigned int v8; // ebx
  unsigned __int16 v9; // [rsp+38h] [rbp+10h] BYREF

  v9 = 0;
  v2 = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeKeyShareEntrySize((__int64)this, &v9);
  if ( v2 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 32i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids, v2);
    return v2;
  }
  else
  {
    v4 = v9;
    *((_WORD *)this + 26) = v9;
    *((_BYTE *)this + 54) = 2;
    v5 = v4 + 10;
    v6 = *(_QWORD *)(*((_QWORD *)this + 1) + 136i64) & 0x8000i64;
    v7 = (*(_DWORD *)(*((_QWORD *)this + 1) + 136i64) & 0x8000) == 0i64 ? 2 : 0;
    *((_WORD *)this + 78) = v7;
    if ( !v6 )
      v5 = v7 + v4 + 14;
    result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeGenericExtensionsSize((__int64)this, 2);
    if ( !(_DWORD)result )
    {
      v8 = *((unsigned __int16 *)this + 61) + v5;
      if ( v8 <= 0xFFFF )
      {
        *((_WORD *)this + 20) = v8;
        return 0i64;
      }
      else
      {
        return 1359i64;
      }
    }
  }
  return result;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
