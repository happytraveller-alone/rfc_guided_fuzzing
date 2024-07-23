// File count: 244
// Total lines: 13
-----------------------------------------
HLOCAL __fastcall CSslContext::GetMemory(CSslContext *this, __int64 a2)
{
  __int64 v2; // rcx

  v2 = *(_QWORD *)(*((_QWORD *)this + 16) + 24i64);
  if ( v2 )
    return (HLOCAL)(*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v2 + 48i64))(v2, a2, 0i64);
  if ( LsaTable )
    return (HLOCAL)(*(__int64 (__fastcall **)(_QWORD))(LsaTable + 40))((unsigned int)a2);
  return LocalAlloc(0x40u, (unsigned int)a2);
}
// 180092620: using guessed type __int64 LsaTable;
