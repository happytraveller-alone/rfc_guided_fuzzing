// File count: 414
// Total lines: 13
-----------------------------------------
__int64 __fastcall CSsl3TlsServerContext::GetClientAuthResults(
        CSsl3TlsServerContext *this,
        unsigned __int64 *a2,
        int *a3)
{
  __int64 result; // rax

  *a2 = *(_QWORD *)(*((_QWORD *)this + 124) + 344i64);
  result = 0i64;
  *a3 = *(_DWORD *)(*((_QWORD *)this + 124) + 352i64);
  return result;
}
