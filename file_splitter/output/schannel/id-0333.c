//----- (0000000180017EE0) ----------------------------------------------------
__int64 __fastcall SpUniGetInfo(__int64 a1)
{
  __int64 result; // rax

  *(_DWORD *)(a1 + 4) = 917505;
  *(_QWORD *)(a1 + 16) = L"Microsoft Unified Security Protocol Provider";
  *(_QWORD *)(a1 + 24) = L"Schannel Security Package";
  result = 0i64;
  *(_DWORD *)a1 = 4261811;
  *(_DWORD *)(a1 + 8) = 24576;
  return result;
}

