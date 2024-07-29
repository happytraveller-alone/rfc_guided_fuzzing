//----- (000000018004312C) ----------------------------------------------------
__int64 __fastcall McGenEventWrite_EtwEventWriteTransfer(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 a5)
{
  unsigned __int16 *v5; // r8
  int v6; // eax
  int v7; // r8d

  v5 = (unsigned __int16 *)qword_180091388;
  v6 = 0;
  if ( qword_180091388 )
  {
    *(_QWORD *)a5 = qword_180091388;
    v6 = 2;
    v7 = *v5;
  }
  else
  {
    *(_QWORD *)a5 = 0i64;
    v7 = 0;
  }
  *(_DWORD *)(a5 + 8) = v7;
  *(_DWORD *)(a5 + 12) = v6;
  return EtwEventWriteTransfer(MS_Schannel_Provider_Context, a2, 0i64, 0i64, a4, a5);
}
// 180080F00: using guessed type __int64 __fastcall EtwEventWriteTransfer(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD);
// 180091388: using guessed type __int64 qword_180091388;

