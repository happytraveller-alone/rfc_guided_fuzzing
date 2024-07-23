// File count: 38
// Total lines: 20
------------------------------------------
void __fastcall CSslContext::FreeMemory(CSslContext *this, void *a2)
{
  __int64 v2; // rcx

  v2 = *(_QWORD *)(*((_QWORD *)this + 16) + 24i64);
  if ( v2 )
  {
    (*(void (__fastcall **)(__int64, void *))(*(_QWORD *)v2 + 32i64))(v2, a2);
  }
  else if ( LsaTable )
  {
    (*(void (__fastcall **)(void *))(LsaTable + 48))(a2);
  }
  else
  {
    LocalFree(a2);
  }
}
// 180092620: using guessed type __int64 LsaTable;
