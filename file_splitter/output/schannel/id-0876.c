// File count: 876
// Total lines: 64
-----------------------------------------
__int64 __fastcall SpGetAppDataForSca(void *a1, unsigned int a2, unsigned __int8 **a3, unsigned int *a4)
{
  int v9; // ebx
  __int64 v10; // rdx
  NTSTATUS v11; // eax
  ULONG v12; // ebx
  bool v13; // zf
  __int64 v14; // rbx
  unsigned int v15; // edi
  unsigned __int8 *v16; // rsi
  NTSTATUS v17; // eax
  __int128 v18; // [rsp+30h] [rbp-38h] BYREF
  char v19[32]; // [rsp+40h] [rbp-28h] BYREF

  v18 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v19) )
    return 1359i64;
  v9 = v19[8] & 0x40;
  v10 = v9 != 0 ? 12 : 16;
  if ( a2 < (unsigned int)v10 )
    return 87;
  v11 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int128 *, void *))(LsaTable + 80))(0i64, v10, &v18, a1);
  if ( v11 >= 0 )
  {
    v13 = v9 == 0;
    v14 = *((_QWORD *)&v18 + 1);
    v15 = DWORD1(v18);
    if ( !v13 )
      v14 = DWORD2(v18);
    if ( DWORD1(v18) <= 0x10000 && DWORD1(v18) && v14 )
    {
      v16 = (unsigned __int8 *)SPExternalAlloc(DWORD1(v18));
      if ( v16 )
      {
        v17 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, unsigned __int8 *, __int64))(LsaTable + 80))(
                0i64,
                v15,
                v16,
                v14);
        v12 = v17;
        if ( v17 >= 0 )
        {
          *a3 = v16;
          *a4 = v15;
        }
        else
        {
          v12 = RtlNtStatusToDosError(v17);
        }
        if ( v12 )
          SPExternalFree(v16);
      }
      else
      {
        return 14;
      }
      return v12;
    }
    return 87;
  }
  return RtlNtStatusToDosError(v11);
}
// 180092620: using guessed type __int64 LsaTable;
