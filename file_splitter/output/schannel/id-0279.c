// File count: 279
// Total lines: 23
-----------------------------------------
__int64 __fastcall SpInstanceInit(__int64 a1, __int64 a2)
{
  unsigned int v3; // ebx
  unsigned int *v4; // rdi
  __int64 result; // rax

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x20) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_ce922361a63b3a68cf8f3b43d0a887f8_Traceguids);
  v3 = 0;
  v4 = (unsigned int *)&g_SchannelCallbacks;
  do
  {
    result = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(a2 + 16))(*v4, *((_QWORD *)v4 + 1));
    if ( (_DWORD)result )
      break;
    ++v3;
    v4 += 4;
  }
  while ( v3 < 0xA );
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
