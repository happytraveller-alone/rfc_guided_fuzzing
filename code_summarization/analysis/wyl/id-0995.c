//----- (0000000180053448) ----------------------------------------------------
__int64 __fastcall SslGetClientProcess(unsigned int *a1)
{
  DWORD CurrentProcessId; // eax
  DWORD v4[10]; // [rsp+20h] [rbp-28h] BYREF

  if ( !LsaTable )
  {
    CurrentProcessId = GetCurrentProcessId();
LABEL_3:
    *a1 = CurrentProcessId;
    return 1i64;
  }
  if ( (*(unsigned __int8 (__fastcall **)(DWORD *))(LsaTable + 192))(v4) )
  {
    CurrentProcessId = v4[0];
    goto LABEL_3;
  }
  *a1 = -1;
  return 0i64;
}
// 180092620: using guessed type __int64 LsaTable;
// 180053448: using guessed type DWORD var_28[10];
