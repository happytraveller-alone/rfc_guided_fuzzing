//----- (0000000180044054) ----------------------------------------------------
void __fastcall GenerateFatalAlertMessage(int a1, __int64 a2, __int16 a3, __int64 a4)
{
  __int64 v7; // rdx
  __int64 v8; // r8
  __int64 v9; // r9

  if ( *(_BYTE *)(a2 + 96) == 2 && IsFatalError(a1) && (*(_DWORD *)(v7 + 64) & 0x3FF0) != 0 )
  {
    LOBYTE(v9) = *(_BYTE *)(v7 + 97);
    if ( (*(unsigned int (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)v7 + 392i64))(a2, a4, v8, v9) )
    {
      if ( (a3 & 0x100) != 0 )
      {
        if ( *(_QWORD *)(a4 + 8) )
        {
          (*(void (__fastcall **)(__int64))(*(_QWORD *)a2 + 16i64))(a2);
          *(_QWORD *)(a4 + 8) = 0i64;
        }
      }
      *(_DWORD *)a4 = 0;
      *(_DWORD *)(a4 + 4) = 0;
    }
    else
    {
      *(_WORD *)(a2 + 96) = 0;
      if ( *(_DWORD *)(a2 + 68) == 96 )
        *(_DWORD *)(a2 + 68) = 3;
    }
  }
}
// 180044082: variable 'v7' is possibly undefined
// 1800440A9: variable 'v8' is possibly undefined
// 1800440A9: variable 'v9' is possibly undefined

