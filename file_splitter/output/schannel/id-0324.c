// File count: 324
// Total lines: 15
-----------------------------------------
void __fastcall CSslContextManager::~CSslContextManager(CSslContextManager *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx

  *(_QWORD *)this = &CSslContextManager::`vftable';
  v2 = *((_QWORD *)this + 6);
  if ( v2 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v2 + 8i64))(v2, 1i64);
  v3 = *((_QWORD *)this + 7);
  if ( v3 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v3 + 8i64))(v3, 1i64);
}
// 18007D3E8: using guessed type void *CSslContextManager::`vftable';
