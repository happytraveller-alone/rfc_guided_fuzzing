//----- (0000000180046EB8) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::QuerySupportedSignatures(CSsl3TlsContext *this, void *a2)
{
  int v5; // ebx
  int v6; // edi
  NTSTATUS v7; // eax
  ULONG v8; // ebx
  __int64 *v9; // r9
  __int128 v10; // [rsp+30h] [rbp-30h] BYREF
  char v11[32]; // [rsp+40h] [rbp-20h] BYREF
  __int64 v12; // [rsp+A0h] [rbp+40h] BYREF
  __int64 v13; // [rsp+A8h] [rbp+48h] BYREF

  v13 = 0i64;
  v10 = 0i64;
  v12 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v11) )
    return 1359i64;
  v5 = v11[8] & 0x40;
  if ( (*((_DWORD *)this + 16) & 0x82800) == 0 )
    return 2148074242i64;
  v6 = *((unsigned __int16 *)this + 255);
  if ( (_WORD)v6 )
  {
    v7 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(LsaTable + 56))(0i64, (unsigned int)(2 * v6), &v12);
    if ( v7 < 0 )
      goto LABEL_7;
    v7 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, char *))(LsaTable + 72))(
           0i64,
           (unsigned int)(2 * v6),
           v12,
           (char *)this + 512);
    if ( v7 < 0 )
      goto LABEL_7;
  }
  if ( v5 )
  {
    HIDWORD(v13) = v12;
    LOWORD(v13) = v6;
  }
  else
  {
    *((_QWORD *)&v10 + 1) = v12;
    LOWORD(v10) = v6;
  }
  v9 = &v13;
  if ( !v5 )
    v9 = (__int64 *)&v10;
  v7 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, void *, __int64 *))(LsaTable + 72))(0i64, v5 != 0 ? 8 : 16, a2, v9);
  if ( v7 < 0 )
  {
LABEL_7:
    v8 = RtlNtStatusToDosError(v7);
  }
  else
  {
    v12 = 0i64;
    v8 = 0;
  }
  if ( v12 )
    (*(void (__fastcall **)(_QWORD))(LsaTable + 64))(0i64);
  return v8;
}
// 180092620: using guessed type __int64 LsaTable;

